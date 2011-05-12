/* bzflag
 * Copyright (c) 1993 - 2002 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named LICENSE that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <math.h>
#include "daylight.h"

static const double		radPerDeg = M_PI / 180.0;
static const double		radPerHour = M_PI / 12.0;
static const double		siderealHoursPerHour = 1.002737908;
static const double		epoch = 2415020.0;

static double			getGreenwichSideral(double julianDay)
{
	// true position requires sidereal time of midnight at prime meridian.
	// get midnight of given julian day (midnight has decimal of .5)
	double jdMidnight = floor(julianDay);
	if (julianDay - jdMidnight >= 0.5) jdMidnight += 0.5;
	else jdMidnight -= 0.5;

	// get fraction of a day
	double dayFraction = (julianDay - jdMidnight) * 24.0;

	// get Greenwich midnight sidereal time (in hours)
	double T = (jdMidnight - epoch) / 36525.0;
	const double greenwichMidnight =
				fmod((0.00002581 * T + 2400.051262) * T + 6.6460656, 24.0);

	// return Greenwich sidereal time
	return radPerHour * (greenwichMidnight + dayFraction * siderealHoursPerHour);
}

static void				gettruePosition(double julianDay,
										float latitude, float longitude,
										double sx, double sy, double sz,
										float pos[3])
{
	// get local sidereal time
	const float localSidereal = (float)getGreenwichSideral(julianDay) -
												longitude * M_PI / 180.0f;

	// rotate around polar axis (y-axis) by local sidereal time
	float tx = float(sx * cosf(localSidereal) - sz * sinf(localSidereal));
	float ty = float(sy);
	float tz = float(sz * cosf(localSidereal) + sx * sinf(localSidereal));

	// rotate by latitude to local position
	pos[0] = tx;
	pos[1] = ty * cosf(latitude*M_PI/180.0f) - tz * sinf(latitude*M_PI/180.0f);
	pos[2] = tz * cosf(latitude*M_PI/180.0f) + ty * sinf(latitude*M_PI/180.0f);
}

void					getCelestialTransform(double julianDay,
										float latitude, float longitude,
										float xform[4][4])
{
	// get local sidereal time
	const float localSidereal = (float)getGreenwichSideral(julianDay) -
												longitude * M_PI / 180.0f;

	// localSidereal is the amount the celestial sphere should be
	// rotated from the vernal equinox about the celestial axis.
	// construct the matrix that transforms points in the celestial
	// coordinate system (x points to vernal equinox, z points to
	// celestial north pole) to the local coordinate system on earth
	// where z is up and y points in the horizontal plane towards
	// north.
	const float cls = cosf(localSidereal);
	const float sls = sinf(localSidereal);
	const float cla = cosf(latitude * M_PI / 180.0f);
	const float sla = sinf(latitude * M_PI / 180.0f);

	// constant stuff
	xform[0][3] = xform[1][3] = xform[2][3] = 0.0f;
	xform[3][0] = xform[3][1] = xform[3][2] = 0.0f;
	xform[3][3] = 1.0f;

	// fill in rotation
	xform[0][0] = -sls;
	xform[1][0] = cls;
	xform[2][0] = 0.0f;
	xform[0][1] = -cls * sla;
	xform[1][1] = -sls * sla;
	xform[2][1] = cla;
	xform[0][2] = cls * cla;
	xform[1][2] = sls * cla;
	xform[2][2] = sla;
}

void					getSunPosition(double julianDay, float latitude,
										float longitude, float pos[3])
{
	double T = (julianDay - epoch) / 36525.0;
	double geometricMeanLongitude = radPerDeg *
				((0.0003025 * T + 36000.76892) * T + 279.69668);
	geometricMeanLongitude = fmod(geometricMeanLongitude, 2.0 * M_PI);

	double meanAnomaly = radPerDeg * (358.47583 +
				((0.0000033 * T + 0.000150) * T + 35999.04975) * T);
	meanAnomaly = fmod(meanAnomaly, 2.0 * M_PI);

//  double eccentricity = 0.01675104 +
//				T * (-0.000000126 * T - 0.0000418);

	double C = radPerDeg *
				(sin(meanAnomaly) * (1.919460 - (0.004789 + 0.000014 * T) * T) +
				sin(2.0 * meanAnomaly) * (0.020094 - 0.0001 * T) +
				sin(3.0 * meanAnomaly) * 0.000293);
	C = fmod(C, 2.0 * M_PI);

	double trueLongitude = geometricMeanLongitude + C;
	trueLongitude = fmod(trueLongitude, 2.0 * M_PI);

	// get obliquity (earth's tilt)
	double obliquity = radPerDeg *
				(23.452294 + (-0.0130125 + (-0.00000164 +
												0.000000503 * T) * T) * T);
	obliquity = fmod(obliquity, 2.0 * M_PI);

	// position of sun if earth didn't rotate:
	double sx, sy, sz;
	sx = sin(trueLongitude) * cos(obliquity);
	sy = sin(trueLongitude) * sin(obliquity);
	sz = cos(trueLongitude);

	// get true position
	gettruePosition(julianDay, latitude, longitude, sx, sy, sz, pos);
}

void					getMoonPosition(double julianDay, float latitude,
										float longitude, float pos[3])
{
	double T = (julianDay - epoch) / 36525.0;
	double e = 1.0 + (-0.002495 - 0.00000752 * T) * T;
	double meanLongitude = radPerDeg *
				(270.434164 + (481267.8831 + (-0.001133 + 0.0000019 * T)*T)*T);
	meanLongitude = fmod(meanLongitude, 2.0 * M_PI);

	double meanAnomaly = radPerDeg *
				(296.104608 + (477198.8491 + (0.009192 + 0.0000144 * T)*T)*T);
	meanAnomaly = fmod(meanAnomaly, 2.0 * M_PI);

	double meanElongation = radPerDeg *
				(350.737486 + (445267.1142 + (-0.001436 + 0.0000019 * T)*T)*T);
	meanElongation = fmod(meanElongation, 2.0 * M_PI);
	double meanElongation2 = 2.0 * meanElongation;

	double distFromAscendingNode = radPerDeg *
				(11.250889 + (483202.0251 + (-0.003211 - 0.0000003 * T)*T)*T);
	distFromAscendingNode = fmod(distFromAscendingNode, 2.0 * M_PI);

	// get sun's meanAnomaly
	double solMeanAnomaly = radPerDeg * (358.47583 +
				((0.0000033 * T + 0.000150) * T + 35999.04975) * T);
	solMeanAnomaly = fmod(solMeanAnomaly, 2.0 * M_PI);

	// get moon's geocentric latitude and longitude
	double geocentricLongitude = meanLongitude + radPerDeg *
				(6.288750 * sin(meanAnomaly) +
				 1.274018 * sin(meanElongation2 - meanAnomaly) +
				 0.658309 * sin(meanElongation2) +
				 0.213616 * sin(2.0 * meanAnomaly) +
				-0.185596 * sin(solMeanAnomaly) * e +
				-0.114336 * sin(2.0 * distFromAscendingNode));
	double geocentricLatitude = radPerDeg *
				(5.128189 * sin(distFromAscendingNode) +
				 0.280606 * sin(meanAnomaly + distFromAscendingNode) +
				 0.277693 * sin(meanAnomaly - distFromAscendingNode) +
				 0.173238 * sin(meanElongation2 - distFromAscendingNode) +
				 0.055413 * sin(meanElongation2 + distFromAscendingNode - meanAnomaly) +
				 0.046272 * sin(meanElongation2 - distFromAscendingNode - meanAnomaly) +
				 0.032573 * sin(meanElongation2 + distFromAscendingNode) +
				 0.017198 * sin(2.0 * meanAnomaly + distFromAscendingNode));
	geocentricLongitude = fmod(geocentricLongitude, 2.0 * M_PI);
	geocentricLatitude = fmod(geocentricLatitude, 2.0 * M_PI);

	// get obliquity (earth's tilt)
	double obliquity = radPerDeg *
				(23.452294 + (-0.0130125 + (-0.00000164 +
												0.000000503 * T) * T) * T);
	obliquity = fmod(obliquity, 2.0 * M_PI);

	// position of moon if earth didn't rotate:
	double sx, sy, sz;
	sx = cos(geocentricLatitude) * sin(geocentricLongitude) * cos(obliquity) -
		sin(geocentricLatitude) * sin(obliquity);
	sy = sin(geocentricLatitude) * cos(obliquity) +
		cos(geocentricLatitude) * sin(geocentricLongitude) * sin(obliquity);
	sz = cos(geocentricLatitude) * cos(geocentricLongitude);

	// get true position
	gettruePosition(julianDay, latitude, longitude, sx, sy, sz, pos);
}

/* FIXME -- remove this
bool					areShadowsCast(const float sunDir[3])
{
	return sunDir[2] > 0.087f; // sin(5)
}
*/
// ex: shiftwidth=4 tabstop=4