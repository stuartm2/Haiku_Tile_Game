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
		char tiles[16] = {
			 0,  1,  2,  3,
			 4,  5,  6,  7,
			 8,  9, 10, 11,
			12, 13, 14, 15
		};
	protected:
		int blankAt();
		void shiftTiles(int clickedIndex);
};

#endif
