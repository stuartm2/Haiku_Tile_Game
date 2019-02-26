# Tile Game for HaikuOS

This is a simple tile game for HaikuOS.  I'm mainly doing it to learn C++ and the HaikuOS/BeOS API so don't expect it to follow best practices.

I've included a small python script to convert an image file to a hex(ascii) array and add it to resources.rdef so the image can be changed easily.  To use this:

python img2res.py {image_file}

To compile:

c++ TileGame*.cpp -o TileGame -lbe -ltranslation
rc -o resources.rsrc resources.rdef
xres -o TileGame resources.rsrc
