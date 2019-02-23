/*
 * Copyright 2018, Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#ifndef TILEGAMEAPP_H
#define TILEGAMEAPP_H

#include <SupportDefs.h>
#include <Application.h>

#define APP_SIG "application/x-vnd.tilegame"

class TileGameApp
	:
	public BApplication
{
	public:
		TileGameApp();
		virtual void ReadyToRun();
};

#endif
