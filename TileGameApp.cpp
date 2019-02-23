/*
 * Copyright 2018, Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#include <Point.h>
#include <Rect.h>
#include <Size.h>
#include <Window.h>

#include "TileGameApp.h"
#include "TileGameView.h"

TileGameApp::TileGameApp()
	:
	BApplication(APP_SIG)
{
}

void
TileGameApp::ReadyToRun()
{
	BRect winFrame = BRect(BPoint(200.0, 200.0), BSize(400, 400));
	BRect viewFrame = BRect(BPoint(0.0, 0.0), BSize(400, 400));
	BWindow* win = new BWindow(winFrame, "Tile Game", B_TITLED_WINDOW,
				B_QUIT_ON_WINDOW_CLOSE | B_NOT_RESIZABLE);
	TileGameView* view = new TileGameView(viewFrame);
	win->AddChild(view);
	win->Show();
}

int main(void) {
	TileGameApp* app = new TileGameApp();
	app->Run();
	delete app;
	return 0;
}
