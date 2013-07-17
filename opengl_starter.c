#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

static void display(void)
{
/*  clear all pixels  */    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
 
    glPushMatrix();
        glTranslated(-1, 0, -7);
        glutWireSphere(2, 25, 25);
    glPopMatrix();
 
    glutSwapBuffers();

    glFlush ();
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
 
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void init (void) 
{
/*  select clearing (background) color       */
    glClearColor(1, 1, 1, 1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
 
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); 
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480); 
    glutInitWindowPosition(100, 100);

    glutCreateWindow ("Solid and Wired spheres");    

    init();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);     


    glutMainLoop();
    return 0;   
}