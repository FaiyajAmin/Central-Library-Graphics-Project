/*

CSE4208: Computer Graphics Laboratory
Project: Central Library

Author: Faiyaj Bin Amin
Roll: 1707062

*/




#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>



double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1200, windowWidth=1200;
double gammaa = 0;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, Calpha= 360.0, C_hr_alpha=360.0;
GLfloat eye_x = 25.0, eye_y = 15.0, eye_z = 270.0;
GLfloat lookat_x = 25.0, lookat_y = 15.0, lookat_z = 150.0;
GLdouble up_x = 0.0;
GLdouble up_y = 1.0;
GLdouble up_z = 0.0;
GLdouble sx=1.0,sy=1.0,sz=1.0;

double anglePitch=0,angleYaw=90,angleRoll = 0;
int pilotPitch=0,pilotYaw=0,pilotRoll=0; ///
GLboolean bRotate = false, uRotate = false, cRotate= true, light0 = false,light1=false,light2=false,zRotate = false;



static GLfloat v_pyramid[8][3] =
{
    {0.0, 0.0, 0.0}, //0
    {1.0, 0.0, 0.0}, //1
    {1.0, 1.0, 0.0}, //2
    {0.0, 1.0, 0.0}, //3

    {0.0, 0.0, 1.0}, //4
    {1.0, 0.0, 1.0}, //5
    {1.0, 1.0, 1.0}, //6
    {0.0, 1.0, 1.0}, //7

};


static GLubyte quadIndices[6][4] =
{

    {0,1,2,3},
    {1,5,6,2},
    {5,4,7,6},
    {4,0,3,7},
    {3,2,6,7},
    {4,5,1,0}
};

void drawcube(GLfloat ar,GLfloat ag,GLfloat ab, GLfloat dr,GLfloat dg,GLfloat db, GLfloat sr,GLfloat sg,GLfloat sb, GLfloat s)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ar, ag, ab, 1.0 };
    GLfloat mat_diffuse[] = { dr, dg, db, 1.0 };
    GLfloat mat_specular[] = { sr, sg, sb, 1.0 };
    GLfloat mat_shininess[] = {s};
    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);


    for (GLint i = 0; i <6; i++)
    {
        glBegin(GL_QUADS);
        glVertex3fv(&v_pyramid[quadIndices[i][0]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][1]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][2]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][3]][0]);
        glEnd();

    }
}

void ceilingLight(GLfloat ar,GLfloat ag,GLfloat ab, GLfloat dr,GLfloat dg,GLfloat db, GLfloat sr,GLfloat sg,GLfloat sb, GLfloat s)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ar, ag, ab, 1.0 };
    GLfloat mat_diffuse[] = { dr, dg, db, 1.0 };
    GLfloat mat_specular[] = { sr, sg, sb, 1.0 };
    GLfloat mat_shininess[] = {s};
    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glPushMatrix();
    glTranslatef(40,32,60);
    glutSolidSphere(2.0,16,20);
    glPopMatrix();
}

void ceilingLightHolder(GLfloat ar,GLfloat ag,GLfloat ab, GLfloat dr,GLfloat dg,GLfloat db, GLfloat sr,GLfloat sg,GLfloat sb, GLfloat s)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { ar, ag, ab, 1.0 };
    GLfloat mat_diffuse[] = { dr, dg, db, 1.0 };
    GLfloat mat_specular[] = { sr, sg, sb, 1.0 };
    GLfloat mat_shininess[] = {s};
    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glPushMatrix();
    glTranslatef(40,32,60);
    glRotatef(-90,1,0,0);
    glutSolidCone(3.0,8.0,16,20);
    glPopMatrix();
}




//void clock()
//{
//    glPushMatrix();
//
//    glPushMatrix(); //clk_leg1
//
//    glScalef(1.5,1,1);
//    glTranslatef(-.5,0.2,0);
//    glScalef(0.8,0.01,0.1);
//    glTranslatef(-1,-1,-1);
//    cube(0,0,0);
//    glPopMatrix();
//
//    glPushMatrix(); //clk_leg2
//    glRotatef( C_hr_alpha,0, 1, 0.0 );
//    glScalef(1.5,1,1);
//    glTranslatef(0.8,0.2,0);
//    glScalef(0.8,0.01,0.1);
//    glTranslatef(-1,-1,-1);
//    cube(0,0,0);
//    glPopMatrix();
//
//    glPushMatrix(); //clk_leg3
//    glRotatef( Calpha,0, 1, 0.0 );
//    glRotatef(90,0,1,0);
//    glScalef(1.5,1,1);
//    glTranslatef(0.8,0.2,0);
//    glScalef(0.8,0.01,0.1);
//    glTranslatef(-1,-1,-1);
//    cube(0,0,0);
//    glPopMatrix();
//
//
//
//    glScalef(4,0.2,3.5);
//    glTranslatef(-1,-1,-1);
//    cube(0.000, 0.000, 0.804);
//
//    glPopMatrix();
//
//}


//void my_clock()
//{
//     glPushMatrix();
//    glPushMatrix(); //clk_leg1
//    glScalef(1.5,1,1);
//    glTranslatef(-.5,0.2,0);
//    glScalef(0.8,0.01,0.1);
//    glTranslatef(-1,-1,-1);
//    drawcube(.5,.5,.5,.5,.5,.5,1,1,1,10);
//    //cube(0,0,0);
//    glPopMatrix();
//
//    glPushMatrix(); //clk_leg2
//    glRotatef( C_hr_alpha,0, 1, 0.0 );
//    glScalef(1.5,1,1);
//    glTranslatef(0.8,0.2,0);
//    glScalef(0.8,0.01,0.1);
//    glTranslatef(-1,-1,-1);
//    drawcube(0,0,0,0,0,0,1,1,1,10);
//    //cube(0,0,0);
//    glPopMatrix();
//
//    glPushMatrix(); //clk_leg3
//    glRotatef( Calpha,0, 1, 0.0 );
//    glRotatef(90,0,1,0);
//    glScalef(1.5,1,1);
//    glTranslatef(0.8,0.2,0);
//    glScalef(0.8,0.01,0.1);
//    glTranslatef(-1,-1,-1);
//    drawcube(0,0,0,0,0,0,1,1,1,10);
//    //cube(0,0,0);
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glScalef(4,0.2,3.5);
//    glTranslatef(-1,-1,-1);
//    drawcube(0,0,0.27,0,0,.8,1,1,1,60);
//    //cube(0,0,0);
//    glPopMatrix();
//    glPopMatrix();
//
//}

void light(double x,double y,double z,bool lighton,GLenum Lights,bool spot,bool strip)
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat strip_light_diffuse[]  = { 1.0, 1.0, 0.8, 1.0 };
    GLfloat strip_light_specular[] = { 1.0, 1.0, 0.8, 1.0 };
    GLfloat light_position[] = { x, y, z, 1.0 };

    glEnable(Lights);
    if(lighton)
    {
        if(strip)
        {
            glLightfv( Lights, GL_AMBIENT, light_ambient);
            glLightfv( Lights, GL_DIFFUSE, strip_light_diffuse);
            glLightfv( Lights, GL_SPECULAR, strip_light_specular);
            glLightfv( Lights, GL_POSITION, light_position);
        }
        else //tube
        {
            glLightfv( Lights, GL_AMBIENT, light_ambient);
            glLightfv( Lights, GL_DIFFUSE, light_diffuse);
            glLightfv( Lights, GL_SPECULAR, light_specular);
            glLightfv( Lights, GL_POSITION, light_position);
        }

    }
    else
    {
        glLightfv( Lights, GL_AMBIENT, no_light);
        glLightfv( Lights, GL_DIFFUSE, no_light);
        glLightfv( Lights, GL_SPECULAR, no_light);
        glLightfv( Lights, GL_POSITION, no_light);
    }



    //position of strip light
    glPushMatrix();
    glTranslatef(-15,4,28);
    glutSolidCube(2);
    glPopMatrix();


    if(spot)
    {
        GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
        glLightfv(Lights, GL_SPOT_DIRECTION, spot_direction);
        glLightf(Lights, GL_SPOT_CUTOFF, 55.0);
    }


}

void cameraPitch()
{
    lookat_x = 30*(cos(anglePitch*3.1416/180.0))*(cos(angleYaw*3.1416/180.0));
    lookat_y = 30*(sin(anglePitch*3.1416/180.0));
    lookat_z = 30*(cos(anglePitch*3.1416/180.0))*(sin(angleYaw*3.1416/180.0));
}

void cameraYaw()
{
    lookat_x = 30*(cos(anglePitch*3.1416/180.0))*(cos(angleYaw*3.1416/180.0));
    lookat_z = 30*(cos(anglePitch*3.1416/180.0))*(sin(angleYaw*3.1416/180.0));
}

void cameraRoll()
{
    up_x = 1.0*(sin(angleRoll*3.1416/180.0));
    up_y = 1.0*(cos(angleRoll*3.1416/180.0));
}


void drawTable()
{

    //Table upper partition
    glPushMatrix();
    glTranslatef(0,4,5);
    glScalef(5,3,0.5);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();


    //Table Base
    glPushMatrix();
    glTranslatef(0,4,0);
    glScalef(5,0.5,10);
    drawcube(0.722, 0.525, 0.043, 0.722, 0.525, 0.043, 1,1,1,60);
    glPopMatrix();


    //Table  Leg left-back
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(0.75,4,0.75);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

    //Table  Leg Right-back
    glPushMatrix();
    glTranslatef(4.25,0,0);
    glScalef(0.75,4,0.75);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

    //Table Leg left-front
    glPushMatrix();
    glTranslatef(0,0,9.25);
    glScalef(0.75,4,0.75);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

    //Table Leg Right-front
    glPushMatrix();
    glTranslatef(4.25,0,9.25);
    glScalef(0.75,4,0.75);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

}

void drawDoubleTable()
{

    //Table Base
    glPushMatrix();
    glTranslatef(0,4,0);
    glScalef(5,0.5,10);
    drawcube(0.722, 0.525, 0.043, 0.722, 0.525, 0.043, 1,1,1,60);
    glPopMatrix();


    //Table  Leg left-back
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(0.75,4,0.75);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

    //Table  Leg Right-back
    glPushMatrix();
    glTranslatef(4.25,0,0);
    glScalef(0.75,4,0.75);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

    //Table Leg left-front
    glPushMatrix();
    glTranslatef(0,0,9.25);
    glScalef(0.75,4,0.75);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

    //Table Leg Right-front
    glPushMatrix();
    glTranslatef(4.25,0,9.25);
    glScalef(0.75,4,0.75);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

}


void drawChair()
{
    glPushMatrix();

    //Chair Back
    glPushMatrix();
    glTranslatef(0,3.5,0);
    glScalef(2.5,2.75,0.5);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();


    //Chair Base
    glPushMatrix();
    glTranslatef(0,3,0);
    glScalef(2.5,0.5,2.5);
    drawcube(0.722, 0.525, 0.043, 0.722, 0.525, 0.043, 1,1,1,60);
    glPopMatrix();


    //Chair Leg left-back
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(0.5,3,0.5);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

    //Chair Leg Right-back
    glPushMatrix();
    glTranslatef(2,0,0);
    glScalef(0.5,3,0.5);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

    //Chair Leg left-front
    glPushMatrix();
    glTranslatef(0,0,2);
    glScalef(0.5,3,0.5);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

    //Chair Leg Right-front
    glPushMatrix();
    glTranslatef(2,0,2);
    glScalef(0.5,3,0.5);
    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
    glPopMatrix();

    glPopMatrix();

}


void singleTableChairSet()
{
    //Back chair
    glPushMatrix();
    glTranslatef(1.5,0,0);
    drawChair();
    glPopMatrix();

    //Front chair
    glPushMatrix();
    glTranslatef(3.5,0, 16);
    glRotatef(180, 0, 1, 0);
    drawChair();
    glPopMatrix();

    //Table
    glPushMatrix();
    glTranslatef(0,0,3);
    drawTable();
    glPopMatrix();
}


void doubleTableChairSet()
{
    //Back chair
    glPushMatrix();
    glTranslatef(1.5,0,0);
    drawChair();
    glPopMatrix();

    //Back chair
    glPushMatrix();
    glTranslatef(6.5,0,0);
    drawChair();
    glPopMatrix();

    //Front chair
    glPushMatrix();
    glTranslatef(3.5,0, 16);
    glRotatef(180, 0, 1, 0);
    drawChair();
    glPopMatrix();

    //Front chair 2
    glPushMatrix();
    glTranslatef(8.5,0, 16);
    glRotatef(180, 0, 1, 0);
    drawChair();
    glPopMatrix();


    //Table
    glPushMatrix();
    glTranslatef(0,0,3);
    glScalef(2,1,1);
    drawDoubleTable(); //double table used
    glPopMatrix();
}


void threeSingleTableChairSet()
{
    glPushMatrix();
    glTranslatef(5,0,80);
    singleTableChairSet();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(5,0,60);
    singleTableChairSet();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(5,0,40);
    singleTableChairSet();
    glPopMatrix();
}

void threeDoubleTableChairSet()
{
    glPushMatrix();
    glTranslatef(5,0,80);
    doubleTableChairSet();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(5,0,60);
    doubleTableChairSet();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(5,0,40);
    doubleTableChairSet();
    glPopMatrix();
}


void drawTwothreeSingleTableChairSet()
{
    glPushMatrix();
    glTranslatef(0,0,40);
    threeSingleTableChairSet();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(65,0,40);
    threeSingleTableChairSet();
    glPopMatrix();
}


void drawThreeRowsOfthreeDoubleTableChairSet()
{
    glPushMatrix();
    glTranslatef(10,0,40);
    threeDoubleTableChairSet();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,0,40);
    threeDoubleTableChairSet();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50,0,40);
    threeDoubleTableChairSet();
    glPopMatrix();
}

void drawLibraryRoom()
{
    //Left Side Wall
    glPushMatrix();
    glScalef(0.1,40,140);
    drawcube(0.94,0.94,0.86, 0.96,0.96,0.86, 1,1,1,60);
    glPopMatrix();

    //Right Side Wall
    glPushMatrix();
    glTranslatef(80,0,0);
    glScalef(0.1,40,140);
    drawcube(0.94,0.94,0.86, 0.96,0.96,0.86, 1,1,1,60);
    glPopMatrix();

    //Roof
    glPushMatrix();
    glTranslatef(0,40,0);
    glScalef(80,0.1,140);
    drawcube(0.94,0.94,0.86, 0.96,0.96,0.86, 1,1,1,60);
    glPopMatrix();

    //Back Wall
    glPushMatrix();
    glScalef(80,40,0.1);
    drawcube(0.94,0.94,0.86, 0.96,0.96,0.86, 1,1,1,60);
    glPopMatrix();

    //Floor
    glPushMatrix();
    glScalef(80,0.1,140);
    drawcube(0.40,0.40,0.40, 0.40,0.40,0.40, 1,1,1,60);
    glPopMatrix();

}


void drawUpperSideWindow()
{
    //sky blue window left
    glPushMatrix();
    glTranslatef(0.11, 32, 5);
    glScalef(0.1,5,130);
    drawcube(0.79, 0.87, 0.92, 0.79, 0.87, 0.92, 1,1,1,60);
    glPopMatrix();

    //sky blue window right
    glPushMatrix();
    glTranslatef(79.9, 32, 5);
    glScalef(0.1,5,130);
    drawcube(0.79, 0.87, 0.92, 0.79, 0.87, 0.92, 1,1,1,60);
    glPopMatrix();

    //left window bar 1
    glPushMatrix();
    glTranslatef(0.21, 33.7, 5);
    glScalef(0.1,0.1,130);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //right window bar 1
    glPushMatrix();
    glTranslatef(79.79, 33.7, 5);
    glScalef(0.1,0.1,130);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //left window bar 2
    glPushMatrix();
    glTranslatef(0.21, 35.4, 5);
    glScalef(0.1,0.1,130);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //right window bar 2
    glPushMatrix();
    glTranslatef(79.79, 35.4, 5);
    glScalef(0.1,0.1,130);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //left window vertical bar 1
    glPushMatrix();
    glTranslatef(0.21, 32, 46);
    glScalef(0.1,5,0.1);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //right window vertical bar 1
    glPushMatrix();
    glTranslatef(79.79, 32, 46);
    glScalef(0.1,5,0.1);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //left window vertical bar 2
    glPushMatrix();
    glTranslatef(0.21, 32, 65);
    glScalef(0.1,5,0.1);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //left window vertical bar 3
    glPushMatrix();
    glTranslatef(0.21, 32, 92);
    glScalef(0.1,5,0.1);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //left window vertical bar 4
    glPushMatrix();
    glTranslatef(0.21, 32, 120);
    glScalef(0.1,5,0.1);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //right window vertical bar 2
    glPushMatrix();
    glTranslatef(79.79, 32, 65);
    glScalef(0.1,5,0.1);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //right window vertical bar 3
    glPushMatrix();
    glTranslatef(79.79, 32, 92);
    glScalef(0.1,5,0.1);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

    //right window vertical bar 4
    glPushMatrix();
    glTranslatef(79.79, 32, 120);
    glScalef(0.1,5,0.1);
    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
    glPopMatrix();

}


void bookRows()
{
    //red book
    glPushMatrix();
    glTranslatef(0.21,0,0);
    glScalef(0.8,2.5,2.3);
    drawcube(0.7,0,0,0.7,0.0,0.0, 1,1,1,60);
    glPopMatrix();

    //green book
    glPushMatrix();
    glTranslatef(0.3,0,0);
    glScalef(1.8,2.7,2.3);
    drawcube(0,0.7,0,0,0.7,0, 1,1,1,60);
    glPopMatrix();

    //blue book
    glPushMatrix();
    glTranslatef(2.1,0,0);
    glScalef(1.3,1.5,2.3);
    drawcube(0,0,0.7,0,0,0.7, 1,1,1,60);
    glPopMatrix();

    //orange book
    glPushMatrix();
    glTranslatef(3.4,0,0);
    glScalef(1.3,2.5,2.3);
    drawcube(0.84,0.41,0.08, 0.84,0.41,0.08, 1,1,1,60);
    glPopMatrix();

    //purple book
    glPushMatrix();
    glTranslatef(4.7,0,0);
    glScalef(1.5,3,2.3);
    drawcube(0.7,0.11,0.74,0,0,0.7, 1,1,1,60);
    glPopMatrix();

    //yellow book
    glPushMatrix();
    glTranslatef(6.2,0,0);
    glScalef(1.1,2.5,2.3);
    drawcube(0.84,0.82,0.18, 0.84,0.82,0.18, 1,1,1,60);
    glPopMatrix();


}

void bookshelfBase()
{
    //Bookshelf base
    glPushMatrix();
    glScalef(15,0.2,2.5);
    drawcube(0.753,0.753,0.753,0.753,0.753,0.753, 1,1,1,60);
    glPopMatrix();

}

void bookshelfVerticalSide()
{
    //Bookshelf base
    glPushMatrix();
    glScalef(0.2,16,2.5);
    drawcube(0.753,0.753,0.753,0.753,0.753,0.753, 1,1,1,60);
    glPopMatrix();

}

void bookshelfSetUp()
{
    //base
    glPushMatrix();
    bookRows();
    glPushMatrix();
    glTranslatef(7.3, 0, 0);
    bookRows();
    glPopMatrix();
    bookshelfBase();
    glPopMatrix();


    //upper bases
    glPushMatrix();
    glTranslatef(0, 4, 0);
    bookRows();
    glPushMatrix();
    glTranslatef(7.3, 0, 0);
    bookRows();
    glPopMatrix();
    bookshelfBase();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 8, 0);
    bookRows();
    glPushMatrix();
    glTranslatef(7.3, 0, 0);
    bookRows();
    glPopMatrix();
    bookshelfBase();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 12, 0);
    bookRows();
    glPushMatrix();
    glTranslatef(7.3, 0, 0);
    bookRows();
    glPopMatrix();
    bookshelfBase();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 16, 0);
    bookshelfBase();
    glPopMatrix();

    //left side
    glPushMatrix();
    bookshelfVerticalSide();
    glPopMatrix();

    //right side
    glPushMatrix();
    glTranslatef(14.8, 0, 0);
    bookshelfVerticalSide();
    glPopMatrix();

}

void drawBookshelf()
{
    //leftmos back bookshelf
    glPushMatrix();
    glTranslatef(2, 0, 3);
    bookshelfSetUp();
    glPopMatrix();

    //left back bookshelf
    glPushMatrix();
    glTranslatef(20, 0, 3);
    bookshelfSetUp();
    glPopMatrix();

    //right back bookshelf
    glPushMatrix();
    glTranslatef(46, 0, 3);
    bookshelfSetUp();
    glPopMatrix();

    //rightmost back bookshelf
    glPushMatrix();
    glTranslatef(63, 0, 3);
    bookshelfSetUp();
    glPopMatrix();

    //v11 bookshelf
    glPushMatrix();
    glTranslatef(2, 0, 28);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();

    //v12 bookshelf
    glPushMatrix();
    glTranslatef(17, 0, 28);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();

    //v13 bookshelf
    glPushMatrix();
    glTranslatef(32, 0, 28);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();

    //v14 bookshelf
    glPushMatrix();
    glTranslatef(46, 0, 28);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();

    //v15 bookshelf
    glPushMatrix();
    glTranslatef(60.5, 0, 28);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();

    //v16 bookshelf
    glPushMatrix();
    glTranslatef(75, 0, 28);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();
    ////////////////////

    //v21 bookshelf
    glPushMatrix();
    glTranslatef(2, 0, 50);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();

    //v22 bookshelf
    glPushMatrix();
    glTranslatef(17, 0, 50);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();

    //v23 bookshelf
    glPushMatrix();
    glTranslatef(32, 0, 50);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();

    //v24 bookshelf
    glPushMatrix();
    glTranslatef(46, 0, 50);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();

    //v25 bookshelf
    glPushMatrix();
    glTranslatef(60.5, 0, 50);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();

    //v26 bookshelf
    glPushMatrix();
    glTranslatef(75, 0, 50);
    glRotatef(90,0,1,0);
    bookshelfSetUp();
    glPopMatrix();


}

void drawCeilingSpotLight()
{

    //holder tube
    glPushMatrix();
    glTranslatef(39,38,60);
    glScalef(2,2,2);
    drawcube(0.4,.4,.4,.4,.4,.4,1,1,1,60);
    glPopMatrix();


    ceilingLightHolder(0.3,0.3,0.4,0.3,0.3,0.4, 1,1,1,60);
    ceilingLight(.85,.85,.85, .85,.85,.85, 1,1,1,60);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    //glFrustum(-5, 5, -5, 5, 4, 100);
    gluPerspective(60,1,4,200);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    cameraRoll();
    gluLookAt(eye_x,eye_y,eye_z, lookat_x,lookat_y,lookat_z, up_x,up_y,up_z);
    glViewport(0, 0, windowHeight, windowWidth);

    glRotatef( alpha,axis_x, axis_y, 0.0 );
    glRotatef( theta, axis_x, axis_y, 0.0 );
    glScaled(sx,sy,sz);

    ///glPushMatrix();
    ///glTranslatef(0,0,-18);

    drawLibraryRoom();
    drawCeilingSpotLight();

    glPushMatrix();
    glTranslatef(0,0.1,0); // to raise everything above floor
    drawTwothreeSingleTableChairSet();
    drawThreeRowsOfthreeDoubleTableChairSet();
    drawUpperSideWindow();
    drawBookshelf();
    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(30, 0.11, 70);
//    bookshelfSetUp();
//    glPopMatrix();

//    //Clock
//    glPushMatrix();
//    glTranslatef(3,10,0);
//    clock();
//    glPopMatrix();


    light(25.0,15.0,-1,light0,GL_LIGHT0,false,false); //tube
    light(40,32,60,light1,GL_LIGHT1,true,false); //spot
    light(-55,4,28,light2,GL_LIGHT2,false,true); //strip
    glFlush();
    glutSwapBuffers();

}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 't':
    case 'T':
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
    case 'w':
        eye_y++;
        lookat_y++;
        glutPostRedisplay();
        break;
    case 's':
        eye_y--;
        lookat_y--;
        glutPostRedisplay();
        break;
    case 'd':
        eye_x++;
        lookat_x++;
        glutPostRedisplay();
        break;
    case 'a':
        eye_x--;
        lookat_x--;
        glutPostRedisplay();
        break;

    case '+':
        eye_z--;
        if(pilotRoll)
        {
            angleRoll++;
        }
        else
        {
            lookat_z--;
        }
        glutPostRedisplay();
        break;
    case '-':
        eye_z++;
        if(pilotRoll)
        {
            angleRoll--;
        }
        else
        {
            lookat_z;
        }
        glutPostRedisplay();
        break;
    case '*':
        sx+=0.1;
        sy+=0.1;
        sz+=0.1;
        glutPostRedisplay();
        break;
    case '/':
        sx-=0.1;
        sy-=0.1;
        sz-=0.1;
        glutPostRedisplay();
        break;
    //for pitch-yaw-roll
    case 'i':
        if(angleRoll<=180)
        {
            angleRoll++;
        }
        glutPostRedisplay();
        break;
    case 'j':
        if(angleRoll>=-180)
        {
            angleRoll--;
        }
        glutPostRedisplay();
        break;
    case 'o':
        if(angleYaw<180)
        {
            angleYaw++;
            cameraYaw();

        }
        glutPostRedisplay();
        break;
    case 'p':
        if(angleYaw>0)
        {
            angleYaw--;
            cameraYaw();
        }
        glutPostRedisplay();
        break;
    case 'k':
        if(anglePitch<90)
        {
            anglePitch++;
            cameraPitch();

        }
        glutPostRedisplay();
        break;
    case 'l':
        if(anglePitch>-90)
        {
            anglePitch--;
            cameraPitch();
        }
        glutPostRedisplay();
        break;

    //switch for light0 tube
    case '1':
        light0 = !light0;
        glutPostRedisplay();
        break;
    case '2':
        light1 = !light1;
        glutPostRedisplay();
        break;
    case '3':
        light2 = !light2;
        glutPostRedisplay();
        break;

    //for fan
    case '4':
        zRotate = !zRotate;
        glutPostRedisplay();
        break;

    //for pilotview
    case '7':
        pilotPitch = !pilotPitch;
        glutPostRedisplay();
        break;
    case '8':
        pilotYaw = !pilotYaw;
        glutPostRedisplay();
        break;
    case '9':
        pilotRoll = !pilotRoll;
        glutPostRedisplay();
        break;



    case 27:  // Escape key
        exit(1);
    }


}

void animate()
{
    if (bRotate == true)
    {
        theta += 0.1;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        alpha += 0.2;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
    }
    if (zRotate == true)
    {
        gammaa += 0.5;
        if(gammaa > 360.0)
            gammaa -= 360.0*floor(gammaa/360.0);
    }

    if (cRotate == true)  //for clock
    {
        Calpha -= 0.075;
        C_hr_alpha -=0.009;
        if(Calpha < 1.0)
            Calpha = 360.0;
        if(C_hr_alpha < 1.0)
            C_hr_alpha = 360.0;
    }


    glutPostRedisplay();

}



int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Central Library");
    ///glutReshapeFunc(resize);

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);

///    printf("Press '1' to on/off light  from the front side.\n");
    printf("Press '2' to on/off light  from the right side.\n");
    printf("Press '3' to on/off spot light from the left side.\n");

    printf("Press 'a' to on/off the light ambient property for all lights.\n");
    printf("Press 'd' to on/off the light diffuse property for all lights.\n");
    printf("Press 's' to on/off the light Specular property for all lights.\n");

    printf("Press 'r' to rotate the scene. \n");
    printf("Press 'f' to on/off the fan.\n");

    printf("Press '+' to zoom in and '-' to zoom out.\n");
    printf("Press '*' to look up, '/' to look down, 'z' to look right, and 'x' to look left.\n");



    glutMainLoop();
    return 0;
}
