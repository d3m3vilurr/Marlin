buildi: clean
	ino build -m mega2560

upload:
	ino upload -m mega2560

serial:
	ino serial -b 115200

clean:
	ino clean

