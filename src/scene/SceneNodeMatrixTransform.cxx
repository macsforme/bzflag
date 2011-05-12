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

#include "SceneNodeMatrixTransform.h"
#include "SceneVisitor.h"
#include "math3D.h"

//
// SceneNodeMatrixTransform
//

SceneNodeMatrixTransform::SceneNodeMatrixTransform() :
								matrix("matrix", 0, 16, 16)
{
	matrix.resize(16);
	matrix.set(0,  1.0f);
	matrix.set(5,  1.0f);
	matrix.set(10, 1.0f);
	matrix.set(15, 1.0f);
}

SceneNodeMatrixTransform::~SceneNodeMatrixTransform()
{
	// do nothing
}

void					SceneNodeMatrixTransform::get(
								Matrix& m,
								const SceneVisitorParams&)
{
	if (matrix.isDirty()) {
		matrix.clearDirty();
		xform = FloatMatrix(matrix.get());
	}

	// apply transform
	m *= xform;
}

bool					SceneNodeMatrixTransform::visit(SceneVisitor* visitor)
{
	return visitor->visit(this);
}
// ex: shiftwidth=4 tabstop=4