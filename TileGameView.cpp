/*
 * Copyright 2018, Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#include <stdio.h>
#include <time.h>
#include <Alert.h>
#include <Point.h>
#include <Rect.h>
#include <Size.h>

#include "TileGameView.h"

#define SHUFFLE_SIZE 100

TileGameView::TileGameView(BRect frame)
	: BView(frame, "view", B_FOLLOW_ALL_SIDES,
			B_FULL_UPDATE_ON_RESIZE | B_WILL_DRAW)
{
	SetViewColor(0, 0, 0);
	shuffle();
}

void
TileGameView::Draw(BRect updateRect)
{
	BSize size = BSize(98.0, 98.0);
	BRect rect;

	for (int i=0; i<16; i++) {
		int x = (i % 4) * 100,
			y = (i / 4) * 100;

		rect = BRect(BPoint(x + 1, y + 1), size);

		if (tiles[i] == 15) { // Blank tile
			FillRect(rect, B_SOLID_HIGH);
		} else {
			FillRect(rect, B_SOLID_LOW);
			DrawChar(tiles[i] + 65, BPoint(x + 50, y + 50));
		}
	}
}

void
TileGameView::MouseDown(BPoint where)
{
	int xTile = where.x / (400/4);
	int yTile = where.y / (400/4);
	int iTile = 4 * yTile + xTile;
	shiftTiles(iTile);

	if (isSolved()) {
		BAlert* alert = new BAlert("Solved!",
			"Congratulations, you\'ve solved the puzzle!", "Play again");
		alert->Go();
		Window()->Activate();
		shuffle();
	}
}

int
TileGameView::blankAt()
{
	for (int i=0; i<16; i++) {
		if (tiles[i] == 15) {
			return i;
		}
	}

	return 0;
}

void TileGameView::shiftTiles(int clickedIndex)
{
	int blankIndex = blankAt();

	// Clicking a tile in the same row moves horizontally
	if (clickedIndex != blankIndex &&
		clickedIndex / 4 == blankIndex / 4)
	{
		int diff = clickedIndex - blankIndex,
			dir = diff / abs(diff);

		for (int i=0; i<abs(diff); i++) {
			tiles[blankIndex+(i*dir)] = tiles[blankIndex+((i+1)*dir)];
		}

		tiles[clickedIndex] = 15;
	}

	// Clicking a tile in the same column moves vertically
	else if (clickedIndex != blankIndex &&
		clickedIndex % 4 == blankIndex % 4)
	{
		int diff = (clickedIndex - blankIndex) / 4,
			dir = 4 * (diff / abs(diff));

		for (int i=0; i<abs(diff); i++) {
			tiles[blankIndex+(i*dir)] = tiles[blankIndex+((i+1)*dir)];
		}

		tiles[clickedIndex] = 15;
	}

	// Otherwise, do nothing
	else
	{
		return;
	}

	// If tiles have shifted, tell the view to redraw
	Invalidate();
}

void
TileGameView::shuffle()
{
	int i, swapA, swapB, tmp;
	int neighbours[4];

	for (i=0; i<16; i++) {
		tiles[i] = i;
	}

	srand(time(NULL));

	for (i=0; i<SHUFFLE_SIZE; i++) {
		swapA = blankAt();
		neighbours[0] = swapA-1;
		neighbours[1] = swapA-4;
		neighbours[2] = swapA+1;
		neighbours[3] = swapA+4;

		do {
			swapB = neighbours[rand()%4];
		} while (swapB<0 or swapB>15 or
			(swapA%4 != swapB%4 and swapA/4 != swapB/4));

		tmp = tiles[swapA];
		tiles[swapA] = tiles[swapB];
		tiles[swapB] = tmp;
	}

	Invalidate();
}

bool
TileGameView::isSolved()
{
	for (int i=0; i<16; i++) {
		if (i != tiles[i]) {
			return false;
		}
	}

	return true;
}
