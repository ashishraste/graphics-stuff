LIB=glut 

all: opengl_starter.o spinning_square.o
	gcc -o opengl_starter opengl_starter.o -l ${LIB}
	gcc -o spinning_square spinning_square.o -l ${LIB}

opengl_starter.o: opengl_starter.c
	gcc -c opengl_starter.c

spinning_square.o: spinning_square.c
	gcc -c spinning_square.c

clean:	
	rm opengl_starter spinning_square opengl_starter.o spinning_square.o
