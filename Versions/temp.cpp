#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include <iostream>

using namespace std;

double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1200, windowWidth=1200;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = false, uRotate = false;

GLfloat eye_x = 0.0, eye_y = 10.0, eye_z = 150.0;
GLfloat lookat_x = 0.0, lookat_y = 5.0, lookat_z = 0.0;
GLdouble up_x = 0.0;
GLdouble up_y = 1.0;
GLdouble up_z = 0.0;



GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 1.0, 1.0},
    {0.0, 1.0, 1.0},


    {0.0, 0.0, 0.0},
    {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0},
    {0.0, 1.0, 0.0},

};

GLubyte quadIndices[6][4] =
{
    {0,1,2,3},
    {7,6,5,4},
    {2,6,7,3},

    {0,4,5,1},
    {2,1,5,6},
    {7,4,0,3},
};


void drawcube(float r, float g, float b)
{
    glColor3ub(r,g,b);

    for (GLint i = 0; i <6; i++)
    {

        glBegin(GL_QUADS);
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
        glEnd();

    }
}

void I()
{
    glPushMatrix();
    glScalef(3, 20, 3);
    drawcube(255, 255, 255);
    glPopMatrix();
}

void M()
{
    glPushMatrix();
    glScalef(3, 20, 3);
    drawcube(255, 255, 255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9,10,0);
    glRotatef(45,0,0,1);
    glScalef(2, 12, 3);
    drawcube(255, 255, 255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9,10,0);
    glRotatef(-45,0,0,1);
    glScalef(2, 12, 3);
    drawcube(255, 255, 255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(17, 0, 0);
    glScalef(3, 20, 3);
    drawcube(255, 255, 255);
    glPopMatrix();

}

void N()
{
    glPushMatrix();
    glScalef(3,20,3);
    drawcube(255,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18.2, 0.3, 0.2);
    glRotatef(45,0,0,1);
    glScalef(3,25,3);
    drawcube(255,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18.6,0,0);
    glScalef(3,20,3);
    drawcube(255,255,255);
    glPopMatrix();
}


void A()
{
    glPushMatrix();
    glRotatef(-30,0,0,1);
    glScalef(3,22,3);
    drawcube(255,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(21.2, -1.5,0);
    glRotatef(30,0,0,1);
    glScalef(3,22,3);
    drawcube(255,255,255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 19.3, 4.7,0);
    glRotatef(90,0,0,1);
    glScalef(3,15,3);
    drawcube(255,255,255);
    glPopMatrix();
}

static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
//    glFrustum(-5, 5, -5, 5, 4, 100);
    gluPerspective(60,1,4,200);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    gluLookAt(eye_x,eye_y,eye_z, lookat_x,lookat_y,lookat_z, up_x,up_y,up_z);
//    gluLookAt(2,3,10, 2,0,0, 0,1,0);
    glViewport(0, 0, windowHeight, windowWidth);

    glPushMatrix();
    glTranslatef(0,40,0);
    glRotatef( alpha,axis_x, axis_y, 0.0 );
    glRotatef( theta, axis_x, axis_y, 0.0 );


    glPushMatrix();
    glTranslatef(0,0,0);
    A();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -30, 0);
    N();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(Txval, -60, 0);
    I();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -90, 0);
    M();
    glPopMatrix();


    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 's':
    case 'S':
        bRotate = !bRotate;
        uRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    case 'r':
    case 'R':
        uRotate = !uRotate;
        bRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;
    case '1':
        Txval+=0.2;
        break;

    case '2':
        Txval-=0.2;
        break;

    case 27:  // Escape key
        exit(1);
    }
}


void animate()
{
    if (bRotate == true)
    {
        theta += 0.5;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        alpha += 0.5;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
    }

//    if (cRotate == true)  //for clock
//    {
//        Calpha -= 0.075;
//        C_hr_alpha -=0.009;
//        if(Calpha < 1.0)
//            Calpha = 360.0;
//        if(C_hr_alpha < 1.0)
//            C_hr_alpha = 360.0;
//    }
//
    glutPostRedisplay();

}



int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("One");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();


    return 0;
}
