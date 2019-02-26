# Tile Game for HaikuOS

This is a simple tile game for HaikuOS.  I'm mainly doing it to learn C++ and the HaikuOS/BeOS API so don't expect it to follow best practices.

To compile:

c++ TileGame*.cpp -o TileGame -lbe -ltranslation
rc -o resources.rsrc resources.rdef
xres -o TileGame resources.rsrc
