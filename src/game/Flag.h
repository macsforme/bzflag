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

/*
 * flag enums and class
 */

#ifndef BZF_FLAG_H
#define BZF_FLAG_H

#include "common.h"
#include "global.h"
#include "Address.h"

enum FlagDropReason {
						DropReasonTimeout = 0,
						DropReasonScore,
						DropReasonCaptured,
						DropReasonDropped,
						DropReasonKilled,
						DropReasonForced
};

enum FlagStatus {
						FlagNoExist = 0,
						FlagOnGround,
						FlagOnTank,
						FlagInAir,
						FlagComing,
						FlagGoing
};
enum FlagType {
						FlagNormal = 0,			// permanent flag
						FlagUnstable = 1,		// disappears after use
						FlagSticky = 2			// can't be dropped normally
};

const int				FlagPLen = 6 + PlayerIdPLen + 48;

class Flag {
public:
	void*				pack(void*) const;
	void*				unpack(void*);

	static const char*	getName(FlagId);
	static const char*	getAbbreviation(FlagId);
	static const char*	getHelp(FlagId);
	static FlagType		getType(FlagId);
	static const float*	getColor(FlagId);
	static FlagId		getIDFromName(const char*);
	static FlagId		getIDFromAbbreviation(const char*);

    class FlagTable {
	  public:
	    FlagTable(char* _name = 0, char* _abbv = 0, 
				  FlagType _type = FlagUnstable, char* _help = 0):
	      name(_name),
	      abbv(_abbv),
	      type(_type),
		  help(_help) { }
	    FlagTable(const FlagTable& _ft) :
	      name(_ft.name),
	      abbv(_ft.abbv),
	      type(_ft.type),
		  help(_ft.help) { }
	    inline const char* getname() const { return name; }
	    inline const char* getabbv() const { return abbv; }
	    inline const FlagType gettype() const { return type; }
		inline const char* gethelp() const { return help; }
	  private:
		char* name;
		char* abbv;
		FlagType type;
		char* help;
	};

public:
	FlagId				id;
	FlagStatus			status;
	FlagType			type;
	PlayerId			owner;					// who has flag
	float				position[3];			// position on ground
	float				launchPosition[3];		// position flag launched from
	float				landingPosition[3];		// position flag will land
	float				flightTime;				// flight time so far
	float				flightEnd;				// total duration of flight
	float				initialVelocity;		// initial launch velocity

private:
	static const FlagTable flagTable[];
};

#endif // BZF_FLAG_H
// ex: shiftwidth=4 tabstop=4