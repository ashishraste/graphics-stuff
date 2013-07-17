LIB=glut 

opengl_starter: opengl_starter.c
	gcc -o opengl_starter opengl_starter.c -l ${LIB}

clean:	
	rm opengl_starter	
