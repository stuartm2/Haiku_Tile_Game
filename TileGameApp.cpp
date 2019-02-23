/*
 * Copyright 2018, Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#include <Rect.h>
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
	BRect winFrame = (200, 200, 400, 400);
	BRect viewFrame = (0, 0, 400, 400);
	BWindow* win = new BWindow(winFrame, "Tile Game", B_TITLED_WINDOW,
				B_QUIT_ON_WINDOW_CLOSE | B_NOT_H_RESIZABLE);
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
