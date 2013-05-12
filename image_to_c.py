from pylab import imread, imshow

def main():
	import sys
	infile = sys.argv[1]
	image = imread(infile)
	print >> sys.stderr, image.shape
	rows, cols, _ = image.shape
	image_rows = []
	for row in range(rows):
		this_row = []
		for col in range(cols):
			pixel = image[row,col]
			r, g, b = pixel[0], pixel[1], pixel[2]
			if (r+g+b) < 1.5:
				this_row.append(1)
			else:
				this_row.append(0)
		image_rows.append(this_row)
	print '{'
	for row in image_rows:
		print '{%s},' % ','.join(map(str, row))
	print '}'

if __name__ == '__main__':
	main()