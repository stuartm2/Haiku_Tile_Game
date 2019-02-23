/*
 * Copyright 2018, Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#ifndef TILEGAMEVIEW_H
#define TILEGAMEVIEW_H

#include <Point.h>
#include <Rect.h>
#include <SupportDefs.h>
#include <View.h>

class TileGameView
	:
	public BView
{
	public:
		TileGameView(BRect frame);
		virtual void Draw(BRect updateRect);
		virtual void MouseDown(BPoint where);
	private:
		char tiles[16];
	protected:
		int blankAt();
		void shiftTiles(int clickedIndex);
		void shuffle();
		bool isSolved();
};

#endif
