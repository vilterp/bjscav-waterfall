import Image, ImageFont, ImageDraw
import numpy
import time
import serial

arial = ImageFont.truetype('/Library/Fonts/Arial.ttf', 50)

def letter_to_array(letter):
	assert len(letter) == 1
	letter = letter.capitalize()
	# draw letter to image
	orig_width = 35
	orig_height = 70
	image = Image.new('1', (orig_width, orig_height))
	draw = ImageDraw.Draw(image)
	draw.text((1,0), letter, font=arial, fill=255)
	# convert to array
	a = numpy.asarray(image)
	return a

def to_bool_array(image):
	rows, cols = image.shape
	image_rows = []
	for row in range(rows):
		this_row = []
		for col in range(cols):
			pixel = image[row,col]
			if pixel:
				this_row.append(1)
			else:
				this_row.append(0)
		image_rows.append(this_row)
	return image_rows

START = 10
STOP = 11

LINE_INTERVAL = .01 # TODO: test

def main():
	# conn = serial.Serial('/dev/tty.usbmodemfd121', 9600)
	print 'sleeping...'
	time.sleep(2)
	while True:
		text = raw_input('message> ')
		letter_arrays = map(lambda l: to_bool_array(letter_to_array(l)), text)
		# stream letters
		# each letter...
		for i in range(len(text)):
			print 'streaming %s' % text[i]
			letter = letter_arrays[i]
			# conn.write(chr(START))
			for row in letter:
				# print 'START'
				for col in row:
					# conn.write(chr(col))
					# print col
					pass
				# conn.write(chr(STOP))
				# print 'STOP'
				print 'line'
				time.sleep(LINE_INTERVAL)

if __name__ == '__main__':
	main()
