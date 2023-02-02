//#include <windows.h>
//#include <mmsystem.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <iostream>
//#include<math.h>
//#include<bits/stdc++.h>
//#include "BmpLoader.h"
//
//
//
//using namespace std;
//
//double Txval=0,Tyval=0,Tzval=0;
//double windowHeight=1200, windowWidth=1400;
//double gammaa = 0;
//GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
//GLfloat eye_x = 0.0, eye_y = 0.0, eye_z = 50.0;
//GLfloat lookat_x = 0.0, lookat_y = 0.0, lookat_z = 0.0;
//GLdouble up_x = 0.0;
//GLdouble up_y = 1.0;
//GLdouble up_z = 0.0;
//GLdouble sx=1.0,sy=1.0,sz=1.0;
//GLdouble tx,ty,tz=0;
//GLdouble dx=0,dz=4.8;
//
//double anglePitch=0,angleYaw=90,angleRoll = 0;
//GLboolean bRotate = false, uRotate = false, light0 = false,light1=false,light2=false,zRotate = false;
//int pilotPitch=0,pilotYaw=0,pilotRoll=0;
//unsigned int ID,ID1;
//
//
////static GLfloat v_box[8][3] =
////{
////    {-2.0, 0.0, 0.0},
////    {2.0, 0.0, 0.0},
////    {-2.0, 0.0, 2.0},
////    {2.0, 0.0, 2.0},
////
////    {-2.0, 2.0, 0.0},
////    {2.0, 2.0, 0.0},
////    {-2.0, 2.0, 2.0},
////    {2.0, 2.0, 2.0}
////};
////
////static GLubyte quadIndices[6][4] =
////{
////    {0,2,3,1},
////    {0,2,6,4},
////    {2,3,7,6},
////    {1,3,7,5},
////    {1,5,4,0},
////    {6,7,5,4}
////};
//
//static GLfloat v_pyramid[8][3] =
//{
//    {-1.0, -1.0, 1.0},
//    {1.0, -1.0, 1.0},
//    {1.0, 1.0, 1.0},
//    {-1.0, 1.0, 1.0},
//
//
//    {-1.0, -1.0, -1.0},
//    {1.0, -1.0, -1.0},
//    {1.0, 1.0, -1.0},
//    {-1.0, 1.0, -1.0},
//
//
//};
//
//
//static GLubyte quadIndices[6][4] =
//{
//    //{4,5,6,7},
//    {0,1,2,3},
//    {7,6,5,4},
//    {2,6,7,3},
//
//    {0,4,5,1},
//    {2,1,5,6},
//    {7,4,0,3},
//};
//
//
//static GLfloat colors[8][3] =
//{
//    //polygon colors
//    {1.0, 1.0, 1.0},
//    {0.5, 0.5, 0.5},
//    //quad er shuru ekhan theke
//    {0.8,0.5,0.3}, //right surface
//    {0.8,0.5,0.5}, //shamner tol
//    {0.6,0.4,0.2}, //left surface
//    {0.6,0.4,0.2}, //pisertol
//    {0.8,0.5,0.3}, //upper surface
//    {1.0, 0.5, 0.0} //bottom surface
//};
//
//static void getNormal3p
//(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
//{
//    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;
//
//    Ux = x2-x1;
//    Uy = y2-y1;
//    Uz = z2-z1;
//
//    Vx = x3-x1;
//    Vy = y3-y1;
//    Vz = z3-z1;
//
//    Nx = Uy*Vz - Uz*Vy;
//    Ny = Uz*Vx - Ux*Vz;
//    Nz = Ux*Vy - Uy*Vx;
//
//    glNormal3f(Nx,Ny,Nz);
//}
//
//void drawcube(GLfloat r,GLfloat g,GLfloat b)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { r, g, b, 1.0 };
//    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = {60};
//
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//
//    for (GLint i = 0; i <6; i++)
//    {
//
//        glBegin(GL_QUADS);
//        glVertex3fv(&v_pyramid[quadIndices[i][0]][0]);
//        glTexCoord2f(1,1);
//        glVertex3fv(&v_pyramid[quadIndices[i][1]][0]);
//        glTexCoord2f(1,0);
//        glVertex3fv(&v_pyramid[quadIndices[i][2]][0]);
//        glTexCoord2f(0,0);
//        glVertex3fv(&v_pyramid[quadIndices[i][3]][0]);
//        glTexCoord2f(0,1);
//        glEnd();
//
//    }
//}
//
//
//
//
//void teapot(GLfloat r,GLfloat g,GLfloat b)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { r, g, b, 1.0 };
//    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = {60};
//
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glTexCoord2f(1,1);
//    glutSolidTeapot(1.4);
//
//}
//
//void knob(GLfloat r,GLfloat g,GLfloat b)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { r, g, b, 1.0 };
//    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = {60};
//
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//
//
//    glutSolidCube(2);
//
//}
//
//void ceiling_light_holder(GLfloat r,GLfloat g,GLfloat b)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { r, g, b, 1.0 };
//    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = {60};
//
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glPushMatrix();
//    glTranslatef(12,12,8);
//    glRotatef(-90,1,0,0);
//    glutSolidCone(2.0,3.0,16,20);
//    glPopMatrix();
//}
//
//void ceiling_light(GLfloat r,GLfloat g,GLfloat b)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { r, g, b, 1.0 };
//    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = {60};
//
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glPushMatrix();
//    glTranslatef(12,12,8);
//    glutSolidSphere(1.0,16,20);
//    glPopMatrix();
//}
//
//void venti_fan(GLfloat r,GLfloat g,GLfloat b)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { r, g, b, 1.0 };
//    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = {60};
//
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glPushMatrix();
//    glTranslatef(0,1,0);
//    glScalef(0.3,1.3,0.2);
//    glutSolidCube(2);
//    glPopMatrix();
//}
//
//
//void chair()
//{
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-3,1.6,-7);
//    glScalef(1.2,0.1,1.2);
//    glBindTexture(GL_TEXTURE_2D,14);
//    drawcube(1,1,1);
//
//    //chair shamner left leg
//    glTranslatef(-0.8,-6,0.8);
//    glScalef(0.15,6.5,0.1);
//    drawcube(0,0,0);
//
//    //shamner right leg
//    glTranslatef(10,0,0);
//    drawcube(0,0,0);
//
//    //piser right leg
//    glTranslatef(0,0,-16.8);
//    drawcube(0,0,0);
//
//    //piser left leg
//    glTranslatef(-10,0,0);
//    drawcube(0,0,0);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(-1.8,2.5,-7);
//    glScalef(0.15,1, 1.2);
//    glBindTexture(GL_TEXTURE_2D,14);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//}
//void disk(GLfloat r,
//          GLfloat g,
//          GLfloat b,
//          GLboolean emission = false )
//{
//
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { r, g, b, 1.0 };
//    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = {60};
//
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    if(emission) glMaterialfv( GL_FRONT, GL_EMISSION, mat_em);
//    else glMaterialfv( GL_FRONT, GL_EMISSION, no_mat);
//
//    GLUquadric* qobj;
//    qobj = gluNewQuadric();
//    gluDisk(qobj,0,5,20,10);
//}
//
//void cyl(GLfloat r,
//         GLfloat g,
//         GLfloat b,
//         GLboolean emission = false )
//{
//
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { r, g, b, 1.0 };
//    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = {60};
//
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    if(emission) glMaterialfv( GL_FRONT, GL_EMISSION, mat_em);
//    else glMaterialfv( GL_FRONT, GL_EMISSION, no_mat);
//
//    GLUquadric* qobj;
//    qobj = gluNewQuadric();
//    gluCylinder(qobj,1.5,1.5,2,16,16);
//}
//
//
//void atm()
//{
//    //atm
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-11.2, -11.4, -14.85);
//    glScalef(2.3,1.5,1.7);
//    glBindTexture(GL_TEXTURE_2D,5);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-11.2, -8.2,-15.9);
//    glScalef(2.3,1.7,0.6);
//    glBindTexture(GL_TEXTURE_2D,5);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//
//    //atm shade
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-11.2, -6.1,-14.6);
//    glRotatef(-25,1,0,0);
//    glScalef(2.3,0.5,1.8);
//    glBindTexture(GL_TEXTURE_2D,5);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //atm card port
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-9.6, -8.6, -15.2);
//    glScalef(0.1,0.1,0.1);
//    glBindTexture(GL_TEXTURE_2D,7);
//    disk( 1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //atm card
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-9.6, -8.6, -14.8);
//    glScalef(0.2,0.02,0.35);
//    glBindTexture(GL_TEXTURE_2D,6);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //atm screen
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-11.8, -8.4,-15.5);
//    glScalef(1.5,1.4,0.3);
//    glBindTexture(GL_TEXTURE_2D,4);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //atm keyboard
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-11.8,-10.18, -14.6);
//    glRotatef(90,1,0,0);
//    glScalef(1.5,1.4,0.3);
//    glBindTexture(GL_TEXTURE_2D,3);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //atm divider
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-5, -9.2, -13.8);
//    glRotatef(90,0,1,0);
//    glScalef(3,3.6,0.3);
//    glBindTexture(GL_TEXTURE_2D,2);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //cashport
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-11.2, -10.8, -13.6);
//    glScalef(1.5,0.2,0.5);
//    glBindTexture(GL_TEXTURE_2D,7);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //cash
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-11.2, -10.7, -12.9);
//    glScalef(0.22,0.02,0.35);
//    glBindTexture(GL_TEXTURE_2D,9);
//    drawcube(1,1,1);
//    glTranslatef(0,-3,0.1);
//    glBindTexture(GL_TEXTURE_2D,9);
//    drawcube(1,1,1);
//    glTranslatef(0,-3,0.1);
//    glBindTexture(GL_TEXTURE_2D,9);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//}
//
//
//
//void light(double x,double y,double z,bool lighton,GLenum Lights,bool spot,bool strip)
//{
//    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
//    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat strip_light_diffuse[]  = { 1.0, 1.0, 0.8, 1.0 };
//    GLfloat strip_light_specular[] = { 1.0, 1.0, 0.8, 1.0 };
//    GLfloat light_position[] = { x, y, z, 1.0 };
//
//    glEnable(Lights);
//    if(lighton)
//    {
//        if(strip)
//        {
//            glLightfv( Lights, GL_AMBIENT, light_ambient);
//            glLightfv( Lights, GL_DIFFUSE, strip_light_diffuse);
//            glLightfv( Lights, GL_SPECULAR, strip_light_specular);
//            glLightfv( Lights, GL_POSITION, light_position);
//        }
//        else
//        {
//            glLightfv( Lights, GL_AMBIENT, light_ambient);
//            glLightfv( Lights, GL_DIFFUSE, light_diffuse);
//            glLightfv( Lights, GL_SPECULAR, light_specular);
//            glLightfv( Lights, GL_POSITION, light_position);
//        }
//
//
//    }
//    else
//    {
//        glLightfv( Lights, GL_AMBIENT, no_light);
//        glLightfv( Lights, GL_DIFFUSE, no_light);
//        glLightfv( Lights, GL_SPECULAR, no_light);
//        glLightfv( Lights, GL_POSITION, no_light);
//    }
//
//
//
//    //to know the position of strip light
//    /*glPushMatrix();
//    glTranslatef(-15,4,28);
//    glutSolidCube(2);
//    glPopMatrix();*/
//
//
//    if(spot)
//    {
//        GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
//        glLightfv(Lights, GL_SPOT_DIRECTION, spot_direction);
//        glLightf(Lights, GL_SPOT_CUTOFF, 55.0);
//    }
//
//
//}
//
//void cameraPitch()
//{
//    lookat_x = 30*(cos(anglePitch*3.1416/180.0))*(cos(angleYaw*3.1416/180.0));
//    lookat_y = 30*(sin(anglePitch*3.1416/180.0));
//    lookat_z = 30*(cos(anglePitch*3.1416/180.0))*(sin(angleYaw*3.1416/180.0));
//}
//
//void cameraYaw()
//{
//    lookat_x = 30*(cos(anglePitch*3.1416/180.0))*(cos(angleYaw*3.1416/180.0));
//    lookat_z = 30*(cos(anglePitch*3.1416/180.0))*(sin(angleYaw*3.1416/180.0));
//}
//
//void cameraRoll()
//{
//    up_x = 1.0*(sin(angleRoll*3.1416/180.0));
//    up_y = 1.0*(cos(angleRoll*3.1416/180.0));
//}
//
//
////void light()
////{
////    //GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
////    GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
////    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
////    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
////    GLfloat light_position[] = { 0.0, 10.0, 50.0, 1.0 };
////
////    glEnable( GL_LIGHT0);
////
////    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
////    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
////    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
////    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
////
////    /*GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
////    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
////    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0);*/
////}
//
//void LoadTexture(const char*filename)
//{
//    glGenTextures(1, &ID);
//    glBindTexture(GL_TEXTURE_2D, ID);
//    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    BmpLoader bl(filename);
//    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
//}
//
//int i = 1;
//GLuint ID_[100];
//
//void LoadTexture1(const char*filename)
//{
//    glGenTextures(1, &ID_[i]);
//    glBindTexture(GL_TEXTURE_2D, ID_[i]);
//    glPixelStorei(GL_UNPACK_ALIGNMENT, ID_[i++]);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    BmpLoader bl(filename);
//    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
//}
//
//
//void display(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//
//    glMatrixMode( GL_PROJECTION );
//    glLoadIdentity();
//    //glFrustum(-5, 5, -5, 5, 4, 100);
//    gluPerspective(60,1,4,200);
//    glMatrixMode( GL_MODELVIEW );
//    glLoadIdentity();
//
//    gluLookAt(eye_x,eye_y,eye_z, lookat_x,lookat_y,lookat_z, up_x,up_y,up_z);
//    glViewport(0, 0, windowHeight, windowWidth);
//
//    glRotatef( alpha,axis_x, axis_y, 0.0 );
//    glRotatef( theta, axis_x, axis_y, 0.0 );
//    glScaled(sx,sy,sz);
//
//
//    glTranslated(0,-7,0);
////    glPushMatrix();
////    glTranslatef(tx,ty,tz);
////    glScalef(2,2,2);
////    drawcube(1,1,1);
////    glPopMatrix();
//
//    //floor
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glScalef(17,0.1,15);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube(0.5,0.5,0.5);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//
//    //table
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-6,2,8);
//    glScalef(1.5,0.1,3);
//    glBindTexture(GL_TEXTURE_2D,14);
//    drawcube(1,1,1);
//    glDisable(GL_TEXTURE_2D);
//
//    // shamner left leg
//    glTranslatef(-0.8,-9,0.8);
//    glScalef(0.15,10,0.1);
//    drawcube(0,0,0);
//
//    // shamner right leg
//    glTranslatef(10,0,0);
//    drawcube(0,0,0);
//
//    // back right leg
//    glTranslatef(0,0,-16);
//    drawcube(0,0,0);
//
//    // back left leg
//    glTranslatef(-10,0,0);
//    drawcube(0,0,0);
//    glPopMatrix();
//
//    //GM wall partition
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(0,4.9,10.8);
//    glScalef(0.15,4.8,4);
//    glBindTexture(GL_TEXTURE_2D,21);
//    drawcube(0.4,0.4,0.4);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(0,4.9,1.4);
//    glScalef(0.15,4.8,1.5);
//    glBindTexture(GL_TEXTURE_2D,21);
//    drawcube(0.4,0.4,0.4);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    //dorja
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(dx, 3.7, dz);
//    glScalef(0.15,3.6,2);
//    glBindTexture(GL_TEXTURE_2D,12);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //dorjar uporer jinish
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef( 0, 8.5, 4.8);
//    glScalef(0.15,1.2,2);
//    glBindTexture(GL_TEXTURE_2D,21);
//    drawcube(0.4,0.4,0.4);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //chair
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-7.5,1.4,8);
//    glScalef(1.2,0.1,1.2);
//    glBindTexture(GL_TEXTURE_2D,14);
//    drawcube(1,1,1);
//    glDisable(GL_TEXTURE_2D);
//
//    //chair shamner left leg
//    glTranslatef(-0.8,-6,0.8);
//    glScalef(0.15,6.5,0.1);
//    drawcube(0,0,0);
//
//    //shamner right leg
//    glTranslatef(10,0,0);
//    drawcube(0,0,0);
//
//    //piser right leg
//    glTranslatef(0,0,-16.8);
//    drawcube(0,0,0);
//
//    //piser left leg
//    glTranslatef(-10,0,0);
//    drawcube(0,0,0);
//    glPopMatrix();
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-8.55,2.5,8);
//    glScalef(0.15,1, 1.2);
//    glBindTexture(GL_TEXTURE_2D,14);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //arekwall partition
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-8.5,4.9,0);
//
//    glScalef(8.6,4.8,0.15);
//    glBindTexture(GL_TEXTURE_2D,21);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //shelf
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-9,0.1,2);
//    glRotatef(90,0,1,0);
//    glScalef(1.5,0.2,5.5);
//    glBindTexture(GL_TEXTURE_2D,2);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//
//    glPushMatrix();
//    glTranslatef(-9,3.3,2);
//    glRotatef(90,0,1,0);
//    glScalef(1.2,3,5.5);
//    glBindTexture(GL_TEXTURE_2D,13);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-9,6.3,2);
//    glRotatef(90,0,1,0);
//    glScalef(1.5,0.2,5.5);
//    glBindTexture(GL_TEXTURE_2D,2);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    //laptop
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-6,2.15,8);
//    glScalef(1,0.03,1.2);
//    drawcube(0,0,0);
//
//
//    glTranslatef(0,0.5,0);
//    glBindTexture(GL_TEXTURE_2D,15);//===================================================
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-4.8,3,8);
//    glRotatef(-10,0,0,1);
//    glScalef(0.05,0.85,1.2);
//    drawcube(0,0,0);
//
//    glTranslatef(-0.03,0,0);
//    glBindTexture(GL_TEXTURE_2D,16);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    //cash counter shelf
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(7.5,1.6,-7);
//    glScalef(7.5,1.5,1);
//    glBindTexture(GL_TEXTURE_2D,17);
//    drawcube(1,1,1);
//
//
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslatef(7.5,3,-6.6);
//    glScalef(7.5,0.2,1.4);
//    glBindTexture(GL_TEXTURE_2D,18);
//    drawcube(1,1,1);
//
//
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    //counter er aynar frame
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(7.5,4.2,-6.6);
//    glScalef(0.2,1.2,1.4);
//    glBindTexture(GL_TEXTURE_2D,2);
//    drawcube(1,1,0);
//
//    glTranslatef(35,0,0);
//    glBindTexture(GL_TEXTURE_2D,2);
//    drawcube(1,1,0);
//
//
//    glTranslatef(-70,0,0);
//    glBindTexture(GL_TEXTURE_2D,2);
//    drawcube(1,1,0);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    //counter ayna
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(11.2,4.7,-5.3);
//    glScalef(3.5,0.7,0.2);
//    glBindTexture(GL_TEXTURE_2D,19);
//    drawcube(1,1,1);
//
//    glTranslatef(-2.1,0,0);
//    glBindTexture(GL_TEXTURE_2D,19);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //sofa
//    glPushMatrix();
//    glTranslatef(1,0,2.2);
//    glScalef(0.9,0.9,0.9);
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(10,1,13);
//    glScalef(3.5,1,1.3);
//    glBindTexture(GL_TEXTURE_2D,20);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(10,2.5,14);
//    glScalef(3.5,2,0.3);
//    glBindTexture(GL_TEXTURE_2D,20);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(6.5,1.3,12.5);
//    glScalef(0.8,1.4,1.3);
//    glBindTexture(GL_TEXTURE_2D,20);
//    drawcube(1,1,1);
//
//
//
//    glTranslatef(9,0,0);
//    glBindTexture(GL_TEXTURE_2D,20);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//    glPopMatrix();
//
//
//
//    //lobbyroom table
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(10,2,8.5);
//    glRotatef(90,0,1,0);
//    glScalef(1.5,0.1,3);
//    glBindTexture(GL_TEXTURE_2D,14);
//    drawcube(1,1,1);
//
//
//    glTranslatef(-0.8,-9,0.8);
//    glScalef(0.15,10,0.1);
//    drawcube(0,0,0);
//
//    glTranslatef(0,0,-16);
//    drawcube(0,0,0);
//
//    glTranslatef(10,0,0);
//    drawcube(0,0,0);
//
//    glTranslatef(0,0,16);
//    drawcube(0,0,0);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(10,2.05,8.5);
//    glRotatef(25,0,1,0);
//    glScalef(0.8,0.1,1);
//    drawcube(0,0,1);
//
//
//    glTranslatef(0,0.7,0);
//    glRotatef(10,0,1,0);
//    drawcube(0,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    //employee table
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glScalef(0.9,0.9,0.9);
//    glTranslatef(-9,1.6,-4.5);
//    glScalef(1,1.3,4);
//    glBindTexture(GL_TEXTURE_2D,17);
//    drawcube(1,1,1);
//
//    glTranslatef(0,1,0);
//    glScalef(1.5,0.2,1);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glScalef(0.9,0.9,0.9);
//    glTranslatef(-9,1.6,-13.2);
//    glScalef(1,1.3,1.7);
//    glBindTexture(GL_TEXTURE_2D,17);
//    drawcube(1,1,1);
//
//    glTranslatef(0,1,0);
//    glScalef(1.5,0.2,1);
//    drawcube(1,1,1);
//
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glScalef(0.9,0.9,0.9);
//    glTranslatef(-9, 2.9, -10);
//    glScalef(1.6,0.2,1.4);
//    glBindTexture(GL_TEXTURE_2D,2);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //chair
//    glPushMatrix();
//    glTranslatef(-2,0,4);
//    chair();
//
//    glTranslatef(0,0,-3.8);
//    chair();
//
//    glTranslatef(0,0,-6.2);
//    chair();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(-16,0,-10);
//    glRotatef(180,0,1,0);
//    chair();
//
//    glTranslatef(0,0,3.8);
//    chair();
//
//    glTranslatef(0,0,6);
//    chair();
//    glPopMatrix();
//
//
//    //employee laptop
//    glPushMatrix();
//
//    glTranslatef(-2,0.7,-1);
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-6,2.15,-2);
//    glScalef(1,0.03,1.2);
//    drawcube(0,0,0);
//    glTranslatef(0,0.5,0);
//    glBindTexture(GL_TEXTURE_2D,15);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-4.8,3,-2);
//    glRotatef(-10,0,0,1);
//    glScalef(0.05,0.85,1.2);
//    drawcube(0,0,0);
//    glTranslatef(-0.03,0,0);
//    glBindTexture(GL_TEXTURE_2D,16);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glPopMatrix();
//
//
//    //laptop2
//
//    glPushMatrix();
//
//    glTranslatef(-2,0.7,-4);
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-6,2.15,-2);
//    glScalef(1,0.03,1.2);
//    drawcube(0,0,0);
//    glTranslatef(0,0.5,0);
//    glBindTexture(GL_TEXTURE_2D,15);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-4.8,3,-2);
//    glRotatef(-10,0,0,1);
//    glScalef(0.05,0.85,1.2);
//    drawcube(0,0,0);
//    glTranslatef(-0.03,0,0);
//    glBindTexture(GL_TEXTURE_2D,16);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glPopMatrix();
//
//
//
//    //laptop
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//
//    glTranslatef(-2,0.7,-10);
//    glPushMatrix();
//    glTranslatef(-6,2.15,-2);
//    glScalef(1,0.03,1.2);
//    drawcube(0,0,0);
//    glTranslatef(0,0.5,0);
//    glBindTexture(GL_TEXTURE_2D,15);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-4.8,3,-2);
//    glRotatef(-10,0,0,1);
//    glScalef(0.05,0.85,1.2);
//    drawcube(0,0,0);
//    glTranslatef(-0.03,0,0);
//    glBindTexture(GL_TEXTURE_2D,16);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glPopMatrix();
//
//    //stair base 1
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(21,0,0);
//    glScalef(4,0.3,4);
//    glBindTexture(GL_TEXTURE_2D,11);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//
//    //stairs
//    glEnable(GL_TEXTURE_2D);
//
//    glPushMatrix();
//    glTranslatef(21,-1,4.8);
//    glScalef(4,1.2,1);
//    glBindTexture(GL_TEXTURE_2D,11);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(21, -2.5, 6.6);
//    glScalef(4,1.2,1);
//    glBindTexture(GL_TEXTURE_2D,11);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//
//    glPushMatrix();
//    glTranslatef( 21, -3.5,8.2);
//    glScalef(4,1.2,1);
//    glBindTexture(GL_TEXTURE_2D,11);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef( 21,-4.5,9.8);
//    glScalef(4,1.2,1);
//    glBindTexture(GL_TEXTURE_2D,11);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //stair base 2
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(16.9, -5.5, 13);
//    glScalef(8,0.3,4);
//    glBindTexture(GL_TEXTURE_2D,11);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //stairs2
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(12.8, -7,8.2);
//    glScalef(4,1.2,1);
//    glBindTexture(GL_TEXTURE_2D,11);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(12.8, -8.6, 6.6);
//    glScalef(4,1.2,1);
//    glBindTexture(GL_TEXTURE_2D,11);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(12.8, -10.2, 5);
//    glScalef(4,1.2,1);
//    glBindTexture(GL_TEXTURE_2D,11);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(12.8, -11.8, 3.4);
//    glScalef(4,1.2,1);
//    glBindTexture(GL_TEXTURE_2D,11);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //nicher floor
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(3.8, -13, 0.2);
//    glScalef(21,0.1,17);
//    glBindTexture(GL_TEXTURE_2D, 1);
//    drawcube(0.5,0.5,0.5);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    //atm stuffs
//    glPushMatrix();
//    atm();
//    glTranslatef(12,0,0);
//    atm();
//    glPopMatrix();
//
//    //bathroom
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-14.8, -12.8, 10.6);
//    glScalef(2.2,0.2,2.2);
//    glBindTexture(GL_TEXTURE_2D,10);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //bathroom wall
//    glPushMatrix();
//    glTranslatef( -7.2, -7, 17);
//    glScalef(10,6,0.2);
//    drawcube(1,1,1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef( -7.2, -7, 5.2);
//    glScalef(10,6,0.2);
//    drawcube(1,1,1);
//    glPopMatrix();
//
//    //tissue roll
//    glPushMatrix();
//    glTranslatef(-9.6, -9.8, 15.6);
//    glRotatef(90,0,1,0);
//    glScalef(0.2,0.2,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glTranslatef(0,0,0.2);
//    glutSolidTorus(1,2,20,20);
//    glPopMatrix();
//
//    //tissue holder
//    glPushMatrix();
//    glTranslatef(-10.4, -9.8, 16.1);
//    glScalef(0.15,0.15,0.6);
//    drawcube(0,0,0);
//
//    glTranslatef(14,0,0);
//    drawcube(0,0,0);
//
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslatef(-9.4, -9.8, 15.6);
//    glRotatef(90,0,1,0);
//    glScalef(0.15,0.15,1);
//    drawcube(0,0,0);
//    glPopMatrix();
//
//    //basin
//    glPushMatrix();
//    glTranslatef(-2.2, -8.4, 15.8);
//    glScalef(2.3,0.3,1.2);
//    drawcube(1,1,1);
//
//    glTranslatef( 0, 0.6, 0.2);
//    glScalef(0.6,0.6,0.8);
//    drawcube(0,0,0);
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslatef(-2.2, -10.8, 16);
//    glScalef(0.7,2.2,0.7);
//    drawcube(0,0,1);
//    glPopMatrix();
//
//
//    //tap
//    glPushMatrix();
//    glTranslatef( -2.2, -6.6, 16);
//    glScalef(0.2,0.16,0.8);
//    drawcube(0,1,0);
//    glPopMatrix();
//
//    //tap er mukkha
//    glPushMatrix();
//    glTranslatef(  -2.2, -6.8, 15.4);
//    glScalef(0.2,0.16,0.2);
//    drawcube(0,1,1);
//    glPopMatrix();
//
//
//    //soapcase
//    glPushMatrix();
//    glTranslatef( -7, -8.2, 16.4);
//    glScalef(0.15,0.15,0.6);
//    drawcube(1,0,0);
//
//    glTranslatef(10,0,0);
//    drawcube(1,0,0);
//
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslatef(-6.25, -8.4, 16.3);
//    glRotatef(90,0,1,0);
//    glScalef(0.5,0.15,0.9);
//    drawcube(0,0,0);
//    glPopMatrix();
//
//
//    //soap
//    glPushMatrix();
//    glTranslatef(-6.25, -8.1, 16.32);
//    glRotatef(90,0,1,0);
//    glScalef(0.35,0.15,0.6);
//    drawcube(1,1,1);
//    glPopMatrix();
//
//    //mirror
//    glPushMatrix();
//    glTranslatef( -2.2, -4, 16.8);
//    glScalef(1.3,1.7,0.2);
//    drawcube(0,0,0.7);
//    glPopMatrix();
//
//    //dotaalar wall left side
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-16.9, 4.9, 0.1);
//    glScalef(0.15,4.8,15);
//    glBindTexture(GL_TEXTURE_2D,21);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //dotaalar wall backside
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(0, 4.9, -14.8);
//    glRotatef(90,0,1,0);
//    glScalef(0.15,4.8,17);
//    glBindTexture(GL_TEXTURE_2D,21);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //nichtala left side
//     glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-17.1, -8.1, 0);
//    glScalef(0.15,4.8,16.8);
//    glBindTexture(GL_TEXTURE_2D,21);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    //nichtala backside
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-0.1, -8.1, -16.7);
//    glRotatef(90,0,1,0);
//    glScalef(0.15,4.8,17);
//    glBindTexture(GL_TEXTURE_2D,21);
//    drawcube(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//    light(-5.0,15.0,-7,light0,GL_LIGHT0,false,false);
//    light(-5,13.85,0,light1,GL_LIGHT1,true,false);
//    light(-55,30,28,light2,GL_LIGHT2,false,true);
//    glFlush();
//    glutSwapBuffers();
//}
//
//void myKeyboardFunc( unsigned char key, int x, int y )
//{
//    switch ( key )
//    {
//    case 't':
//    case 'T':
//        bRotate = !bRotate;
//        uRotate = false;
//        axis_x=0.0;
//        axis_y=1.0;
//        break;
//
//    case 'r':
//    case 'R':
//        uRotate = !uRotate;
//        bRotate = false;
//        axis_x=1.0;
//        axis_y=0.0;
//        break;
//    case 'w':
//        eye_y++;
//        lookat_y++;
//        glutPostRedisplay();
//        break;
//    case 's':
//        eye_y--;
//        lookat_y--;
//        glutPostRedisplay();
//        break;
//    case 'd':
//        eye_x++;
//        lookat_x++;
//        glutPostRedisplay();
//        break;
//    case 'a':
//        eye_x--;
//        lookat_x--;
//        glutPostRedisplay();
//        break;
//
//    case '+':
//        eye_z--;
//        if(pilotRoll)
//        {
//            angleRoll++;
//        }
//        else
//        {
//            lookat_z--;
//        }
//        glutPostRedisplay();
//        break;
//    case '-':
//        eye_z++;
//        if(pilotRoll)
//        {
//            angleRoll--;
//        }
//        else
//        {
//            lookat_z;
//        }
//        glutPostRedisplay();
//        break;
//    case '*':
//        sx+=0.1;
//        sy+=0.1;
//        sz+=0.1;
//        glutPostRedisplay();
//        break;
//    case '/':
//        sx-=0.1;
//        sy-=0.1;
//        sz-=0.1;
//        glutPostRedisplay();
//        break;
//    //for pitch-yaw-roll
//    case 'i':
//        if(angleRoll<=180)
//        {
//            angleRoll++;
//            cameraRoll();
//        }
//        glutPostRedisplay();
//        break;
//    case 'j':
//        if(angleRoll>=-180)
//        {
//            angleRoll--;
//            cameraRoll();
//        }
//        glutPostRedisplay();
//        break;
//    case 'o':
//        if(angleYaw<180)
//        {
//            angleYaw++;
//            cameraYaw();
//
//        }
//        glutPostRedisplay();
//        break;
//    case 'p':
//        if(angleYaw>0)
//        {
//            angleYaw--;
//            cameraYaw();
//        }
//        glutPostRedisplay();
//        break;
//    case 'k':
//        if(anglePitch<90)
//        {
//            anglePitch++;
//            cameraPitch();
//
//        }
//        glutPostRedisplay();
//        break;
//    case 'l':
//        if(anglePitch>-90)
//        {
//            anglePitch--;
//            cameraPitch();
//        }
//        glutPostRedisplay();
//        break;
//
//    //switch for light0
//    case '1':
//        light0 = !light0;
//        glutPostRedisplay();
//        break;
//    case '2':
//        light1 = !light1;
//        glutPostRedisplay();
//        break;
//    case '3':
//        light2 = !light2;
//        glutPostRedisplay();
//        break;
//
//    //for fan
//    case '4':
//        gammaa += 0.5;
//        glutPostRedisplay();
//        break;
//
//    //for pilotview
//    case '7':
//        pilotPitch = !pilotPitch;
//        glutPostRedisplay();
//        break;
//    case '8':
//        pilotYaw = !pilotYaw;
//        glutPostRedisplay();
//        break;
//    case '9':
//        pilotRoll = !pilotRoll;
//        glutPostRedisplay();
//        break;
//    case '5':
//        ty -= 0.1;
//        break;
//    case '6':
//        ty += 0.1;
//        break;
//    case 'u':
//        if(dx<=0.5)
//        {
//            dx +=0.05;
//        }
//        else
//        {
//            if(dz<=9.8)
//            {
//                dz +=0.05;
//            }
//
//        }
//        glutPostRedisplay();
//        break;
//    case 'U':
//        if(dz>4.8)
//        {
//            dz -=0.05;
//        }
//        else
//        {
//            if(dz==4.8 && dx>=0)
//            {
//                dx-=0.05;
//            }
//
//
//        }
//        glutPostRedisplay();
//        break;
//
//
//
//    case 27:  // Escape key
//        exit(1);
//    }
//
//
//}
//
//
//void SpecialInput(int key, int x, int y)
//{
//    switch(key)
//    {
//    case GLUT_KEY_UP:
//        tz -= 0.1;
//        break;
//    case GLUT_KEY_DOWN:
////do something here
//        tz += 0.1;
//        break;
//    case GLUT_KEY_LEFT:
////do something here
//        tx -= 0.1;
//        break;
//    case GLUT_KEY_RIGHT:
////do something here
//        tx += 0.1;
//        break;
//    }
//    cout<<"Starting Point "<<tx<<", "<<ty<<", "<<tz<<" \n";
//
//    glutPostRedisplay();
//}
//
//
//
//void animate()
//{
//    if (bRotate == true)
//    {
//        theta += 0.1;
//        if(theta > 360.0)
//            theta -= 360.0*floor(theta/360.0);
//    }
//
//    if (uRotate == true)
//    {
//        alpha += 0.1;
//        if(alpha > 360.0)
//            alpha -= 360.0*floor(alpha/360.0);
//    }
//    if (zRotate == true)
//    {
//        gammaa += 0.5;
//        if(gammaa > 90.0)
//            gammaa -= 90.0*floor(gammaa/90.0);
//    }
//
//
//    glutPostRedisplay();
//
//}
//
//
//
//int main (int argc, char **argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowPosition(0,0);
//    glutInitWindowSize(windowHeight, windowWidth);
//    glutCreateWindow("Janata Bank, Kuet");
//    glShadeModel( GL_SMOOTH );
//    glEnable( GL_DEPTH_TEST );
//    glEnable(GL_NORMALIZE);
//    glEnable(GL_LIGHTING);
//
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\bfloor.bmp"); //1
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\atmdiv.bmp"); //2
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\numpad.bmp"); //3
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\atmscreen.bmp"); //4
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\atmtext.bmp"); //5
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\atmcard.bmp"); //6
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\atmport.bmp"); //7
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\cashport.bmp"); //8
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\taka.bmp"); //9
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\toilet.bmp"); //10
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\stair.bmp"); //11
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\gmdoor.bmp"); //12
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\shelf.bmp"); //13
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\gmtable.bmp"); //14
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\keyboard.bmp"); //15
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\lscreen.bmp"); //16
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\wood.bmp"); //17
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\cshelf.bmp"); //18
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\cglass.bmp"); //19
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\sofaseat.bmp"); //20
//    LoadTexture("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\wall.bmp"); //21
//    LoadTexture1("C:\\Users\\nafir\\OneDrive\\Desktop\\Janata Bank\\cglass.bmp"); //22
//
//
//
//
//    glutKeyboardFunc(myKeyboardFunc);
//    glutSpecialFunc(SpecialInput);
//    //sndPlaySound("woo.wav",SND_ASYNC);
//    glutDisplayFunc(display);
//    glutIdleFunc(animate);
//    //PlaySound(TEXT("woo.wav"),NULL, SND_SYNC);
//    glutMainLoop();
//
//
//    return 0;
//}
//
//
