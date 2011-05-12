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

#include "BzfWindow.h"
#include "ErrorHandler.h"

BzfWindow::BzfWindow(const BzfDisplay* _display) : display(_display)
{
	// do nothing
}

BzfWindow::~BzfWindow()
{
	// do nothing
}

void					BzfWindow::initJoystick(const char* joystickName)
{
	printError("joystick '%s' not supported...", joystickName);
}
// ex: shiftwidth=4 tabstop=4