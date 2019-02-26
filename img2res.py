import os
import sys

if len(sys.argv)  != 2:
	print "Usage: python img2res.py {image_file}\nThis operation will overwrite resources.rdef if it exists"
	sys.exit(1)

infile_name = sys.argv[1]
outfile_name = 'resources.rdef'

if not os.path.exists(infile_name):
	print "File: %s does not exist" % infile_name
	exit(1)

with open(infile_name, 'rb') as infile:
	with open(outfile_name, 'w') as outfile:
		byte = infile.read(1)
		i = 0

		outfile.write('\nresource(1, "%s") #\'PNG \' array {\n\t$"' % infile_name)

		while byte:
			outfile.write(str.upper('%02x' % ord(byte)))

			if i == 32:
				outfile.write('"\n\t$"')
				i = 0
			else:
				i += 1

			byte = infile.read(1)

		outfile.write('"\n};\n')