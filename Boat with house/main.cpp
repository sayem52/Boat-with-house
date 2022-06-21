#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
static float shift = 0;

void boatMove()
{
    shift += 0.01;
    //if(shift > 200)
       // shift = 0;
    shift = (shift > 200) ? 0:shift;
    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);



    glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.5f,1.0f);

        glVertex3d(100.0,70.0,0.0);
        glVertex3d(85.0,90.0,0.0);
        glVertex3d(70.0,70.0,0.0);

    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3d(100.0,30.0,0.0);
        glVertex3d(100.0,70.0,0.0);
        glVertex3d(70.0,70.0,0.0);
        glVertex3d(70.0,30.0,0.0);
        //door
        glColor3f(1.0f,10.5f,0.0f);
        glVertex3d(88.0,30.0,0.0);
        glVertex3d(88.0,50.0,0.0);
        glVertex3d(82.0,50.0,0.0);
        glVertex3d(82.0,30.0,0.0);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex3d(77.0,45.0,0.0);
        glVertex3d(77.0,55.0,0.0);
        glVertex3d(73.0,55.0,0.0);
        glVertex3d(73.0,45.0,0.0);









    glEnd();



	glColor3f(0.3, 0.3, 1);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 18);
	glVertex2f(150, 18);
	glVertex2f(150, 0);

	glEnd();

    glPushMatrix();
    // we want to draw moving boat

    boatMove();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(45 + shift, 20);
	glVertex2f(5 + shift, 20);
	glVertex2f(15 + shift, 10);
	glVertex2f(35 + shift, 10);

	glEnd();



	glColor3f(0.160, 0.658, 0.203);
	glBegin(GL_POLYGON);
	glVertex2f(25 + shift, 30);
	glVertex2f(25 + shift, 25);
	glVertex2f(17.943 + shift, 25.019);

	glEnd();


	// fourth regular shape is octagon
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(25 + shift, 25.0);
	glVertex2f(25 + shift, 20);
	glVertex2f(23 + shift, 20);
	glVertex2f(23 + shift, 25);

	glEnd();

    glPopMatrix();



    glFlush();
}


void init(void)
{
    glClearColor(0.10, 1.0, 0.0, 0.0);
    glOrtho(0, 100.0, 0, 100.0, 0, 100.0);
}

int main()
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Transformation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
