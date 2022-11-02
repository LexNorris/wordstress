makefile: 
all: testing

clean:
	-rm test

testing:
	gcc filereader.c -o stress
