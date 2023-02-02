///*
//
//CSE4208: Computer Graphics Laboratory
//Project: Central Library
//
//Author: Faiyaj Bin Amin
//Roll: 1707062
//
//*/
//
//
//
//
//#include<GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <windows.h>
//#include<math.h>
//#include<bits/stdc++.h>
//
//#include "BmpLoader.h"
//
//#include<stdio.h>
//BmpLoader::BmpLoader(const char* filename)
//{
//    FILE *file=0;
//    file=fopen(filename, "rb");
//    if(!file)
//        std::cout<<"File not found"<<std::endl;
//    fread(&bfh, sizeof(BITMAPFILEHEADER),1,file);
//    if(bfh.bfType != 0x4D42)
//        std::cout<<"Not a valid bitmap"<<std::endl;
//    fread(&bih, sizeof(BITMAPINFOHEADER),1,file);
//    if(bih.biSizeImage==0)
//        bih.biSizeImage=bih.biHeight*bih.biWidth*3;
//    textureData = new unsigned char[bih.biSizeImage];
//    fseek(file, bfh.bfOffBits, SEEK_SET);
//    fread(textureData, 1, bih.biSizeImage, file);
//    unsigned char temp;
//    for(int i=0; i<bih.biSizeImage; i+=3)
//    {
//        temp = textureData[i];
//        textureData[i] = textureData[i+2];
//        textureData[i+2] = temp;
//
//    }
//
//    iWidth = bih.biWidth;
//    iHeight = bih.biHeight;
//    fclose(file);
//}
//
//BmpLoader::~BmpLoader()
//{
//    delete [] textureData;
//}
//
//
//double Txval=0,Tyval=0,Tzval=0;
//double windowHeight=1000, windowWidth=1000;
//double gammaa = 0;
//GLfloat alpha = 0.0, falpha=360, theta = 0.0, axis_x=0.0, axis_y=0.0, Calpha= 360.0, C_hr_alpha=360.0;
//GLfloat eye_x = 25.0, eye_y = 15.0, eye_z = 270.0;
//GLfloat lookat_x = 25.0, lookat_y = 15.0, lookat_z = 150.0;
//GLdouble up_x = 0.0;
//GLdouble up_y = 1.0;
//GLdouble up_z = 0.0;
//GLdouble sx=1.0,sy=1.0,sz=1.0;
//
//double anglePitch=0,angleYaw=90,angleRoll = 0;
//int pilotPitch=0,pilotYaw=0,pilotRoll=0; ///
//GLboolean bRotate = false, uRotate = false, cRotate= true, fRotate=false, light0 = false,light1=false,light2=false,zRotate = false;
//
//unsigned int ID,ID1;
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
//static GLfloat v_pyramid[8][3] =
//{
//    {0.0, 0.0, 0.0}, //0
//    {1.0, 0.0, 0.0}, //1
//    {1.0, 1.0, 0.0}, //2
//    {0.0, 1.0, 0.0}, //3
//
//    {0.0, 0.0, 1.0}, //4
//    {1.0, 0.0, 1.0}, //5
//    {1.0, 1.0, 1.0}, //6
//    {0.0, 1.0, 1.0}, //7
//
//};
//
//static GLfloat v_pyramid2[8][3] =
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
//static GLubyte quadIndices[6][4] =
//{
//
//    {0,1,2,3},
//    {1,5,6,2},
//    {5,4,7,6},
//    {4,0,3,7},
//    {3,2,6,7},
//    {4,5,1,0}
//};
//
//
//static GLubyte quadIndices2[6][4] =
//{
//    {0,1,2,3},
//    {7,6,5,4},
//    {2,6,7,3},
//
//    {0,4,5,1},
//    {2,1,5,6},
//    {7,4,0,3},
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
//void drawcube3(GLfloat r,GLfloat g,GLfloat b)
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
//        glVertex3fv(&v_pyramid2[quadIndices2[i][0]][0]);
//        glTexCoord2f(1,1);
//        glVertex3fv(&v_pyramid2[quadIndices2[i][1]][0]);
//        glTexCoord2f(1,0);
//        glVertex3fv(&v_pyramid2[quadIndices2[i][2]][0]);
//        glTexCoord2f(0,0);
//        glVertex3fv(&v_pyramid2[quadIndices2[i][3]][0]);
//        glTexCoord2f(0,1);
//        glEnd();
//
//    }
//}
//
//
//
//
//
//void drawcube(GLfloat ar,GLfloat ag,GLfloat ab, GLfloat dr,GLfloat dg,GLfloat db, GLfloat sr,GLfloat sg,GLfloat sb, GLfloat s)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { ar, ag, ab, 1.0 };
//    GLfloat mat_diffuse[] = { dr, dg, db, 1.0 };
//    GLfloat mat_specular[] = { sr, sg, sb, 1.0 };
//    GLfloat mat_shininess[] = {s};
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
//        glBegin(GL_QUADS);
//        glVertex3fv(&v_pyramid[quadIndices[i][0]][0]);
//        glVertex3fv(&v_pyramid[quadIndices[i][1]][0]);
//        glVertex3fv(&v_pyramid[quadIndices[i][2]][0]);
//        glVertex3fv(&v_pyramid[quadIndices[i][3]][0]);
//        glEnd();
//
//    }
//}
//
//void drawcube2(GLfloat ar,GLfloat ag,GLfloat ab, GLfloat dr,GLfloat dg,GLfloat db, GLfloat sr,GLfloat sg,GLfloat sb, GLfloat s)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { ar, ag, ab, 1.0 };
//    GLfloat mat_diffuse[] = { dr, dg, db, 1.0 };
//    GLfloat mat_specular[] = { sr, sg, sb, 1.0 };
//    GLfloat mat_shininess[] = {s};
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
//        glBegin(GL_QUADS);
//        glVertex3fv(&v_pyramid[quadIndices[i][1]][1]);
//        glTexCoord2f(1,1);
//        glVertex3fv(&v_pyramid[quadIndices[i][1]][0]);
//        glTexCoord2f(1,0);
//        glVertex3fv(&v_pyramid[quadIndices[i][0]][0]);
//        glTexCoord2f(0,0);
//        glVertex3fv(&v_pyramid[quadIndices[i][0]][1]);
//        glTexCoord2f(0,1);
//        glEnd();
//
//    }
//}
//
//
//void ceilingLight(GLfloat ar,GLfloat ag,GLfloat ab, GLfloat dr,GLfloat dg,GLfloat db, GLfloat sr,GLfloat sg,GLfloat sb, GLfloat s)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { ar, ag, ab, 1.0 };
//    GLfloat mat_diffuse[] = { dr, dg, db, 1.0 };
//    GLfloat mat_specular[] = { sr, sg, sb, 1.0 };
//    GLfloat mat_shininess[] = {s};
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glPushMatrix();
//    glTranslatef(40,32,60);
//    glutSolidSphere(2.0,16,20);
//    glPopMatrix();
//}
//
//void ceilingLightHolder(GLfloat ar,GLfloat ag,GLfloat ab, GLfloat dr,GLfloat dg,GLfloat db, GLfloat sr,GLfloat sg,GLfloat sb, GLfloat s)
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { ar, ag, ab, 1.0 };
//    GLfloat mat_diffuse[] = { dr, dg, db, 1.0 };
//    GLfloat mat_specular[] = { sr, sg, sb, 1.0 };
//    GLfloat mat_shininess[] = {s};
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glPushMatrix();
//    glTranslatef(40,32,60);
//    glRotatef(-90,1,0,0);
//    glutSolidCone(3.0,8.0,16,20);
//    glPopMatrix();
//}
//
//
//void drawClock(GLfloat ar,GLfloat ag,GLfloat ab, GLfloat dr,GLfloat dg,GLfloat db, GLfloat sr,GLfloat sg,GLfloat sb, GLfloat s)
//{
//    glPushMatrix();
//    glTranslatef(41.5,30,1.5);
//
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { ar, ag, ab, 1.0 };
//    GLfloat mat_diffuse[] = { dr, dg, db, 1.0 };
//    GLfloat mat_specular[] = { sr, sg, sb, 1.0 };
//    GLfloat mat_shininess[] = {s};
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glPushMatrix();
//    gluDisk(gluNewQuadric(),0,5,32,32);
//    glPopMatrix();
//
//    glPushMatrix(); //clk_leg1
//    glScalef(2,.4,1);
//    drawcube(0,0,0, 0,0,0, 1,1,1,60);
//    glPopMatrix();
//
//    glPushMatrix(); //clk_leg3
//    glRotatef( C_hr_alpha,0, 0, 1);
//    glScalef(3,.3,1);
//    drawcube(0,0,0, 0,0,0, 1,1,1,60);
//    glPopMatrix();
//
//
//    glPushMatrix(); //clk_leg3
//    glRotatef( Calpha,0, 0, 1);
//    glScalef(4,.2,1);
//    drawcube(0,0,0, 0,0,0, 1,1,1,60);
//    glPopMatrix();
//
//    glPopMatrix();
//
//}
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
//        else //tube
//        {
//            glLightfv( Lights, GL_AMBIENT, light_ambient);
//            glLightfv( Lights, GL_DIFFUSE, light_diffuse);
//            glLightfv( Lights, GL_SPECULAR, light_specular);
//            glLightfv( Lights, GL_POSITION, light_position);
//        }
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
//    //position of strip light
//    glPushMatrix();
//    glTranslatef(-15,4,28);
//    glutSolidCube(2);
//    glPopMatrix();
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
//void drawTable()
//{
//
//    //Table upper partition
//    glPushMatrix();
//    glTranslatef(0,4,5);
//    glScalef(5,3,0.5);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//
//    //Table Base
//    glPushMatrix();
//    glTranslatef(0,4,0);
//    glScalef(5,0.5,10);
//    drawcube(0.722, 0.525, 0.043, 0.722, 0.525, 0.043, 1,1,1,60);
//    glPopMatrix();
//
//
//    //Table  Leg left-back
//    glPushMatrix();
//    glTranslatef(0,0,0);
//    glScalef(0.75,4,0.75);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//    //Table  Leg Right-back
//    glPushMatrix();
//    glTranslatef(4.25,0,0);
//    glScalef(0.75,4,0.75);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//    //Table Leg left-front
//    glPushMatrix();
//    glTranslatef(0,0,9.25);
//    glScalef(0.75,4,0.75);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//    //Table Leg Right-front
//    glPushMatrix();
//    glTranslatef(4.25,0,9.25);
//    glScalef(0.75,4,0.75);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//}
//
//void drawDoubleTable()
//{
//
//    //Table Base
//    glPushMatrix();
//    glTranslatef(0,4,0);
//    glScalef(5,0.5,10);
//    drawcube(0.722, 0.525, 0.043, 0.722, 0.525, 0.043, 1,1,1,60);
//    glPopMatrix();
//
//
//    //Table  Leg left-back
//    glPushMatrix();
//    glTranslatef(0,0,0);
//    glScalef(0.75,4,0.75);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//    //Table  Leg Right-back
//    glPushMatrix();
//    glTranslatef(4.25,0,0);
//    glScalef(0.75,4,0.75);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//    //Table Leg left-front
//    glPushMatrix();
//    glTranslatef(0,0,9.25);
//    glScalef(0.75,4,0.75);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//    //Table Leg Right-front
//    glPushMatrix();
//    glTranslatef(4.25,0,9.25);
//    glScalef(0.75,4,0.75);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//}
//
//
//void drawChair()
//{
//    glPushMatrix();
//
//    //Chair Back
//    glPushMatrix();
//    glTranslatef(0,3.5,0);
//    glScalef(2.5,2.75,0.5);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//
//    //Chair Base
//    glPushMatrix();
//    glTranslatef(0,3,0);
//    glScalef(2.5,0.5,2.5);
//    drawcube(0.722, 0.525, 0.043, 0.722, 0.525, 0.043, 1,1,1,60);
//    glPopMatrix();
//
//
//    //Chair Leg left-back
//    glPushMatrix();
//    glTranslatef(0,0,0);
//    glScalef(0.5,3,0.5);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//    //Chair Leg Right-back
//    glPushMatrix();
//    glTranslatef(2,0,0);
//    glScalef(0.5,3,0.5);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//    //Chair Leg left-front
//    glPushMatrix();
//    glTranslatef(0,0,2);
//    glScalef(0.5,3,0.5);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//    //Chair Leg Right-front
//    glPushMatrix();
//    glTranslatef(2,0,2);
//    glScalef(0.5,3,0.5);
//    drawcube(0.627, 0.322, 0.176, 0.627, 0.322, 0.176, 1,1,1,60);
//    glPopMatrix();
//
//    glPopMatrix();
//
//}
//
//
//void singleTableChairSet()
//{
//    //Back chair
//    glPushMatrix();
//    glTranslatef(1.5,0,0);
//    drawChair();
//    glPopMatrix();
//
//    //Front chair
//    glPushMatrix();
//    glTranslatef(3.5,0, 16);
//    glRotatef(180, 0, 1, 0);
//    drawChair();
//    glPopMatrix();
//
//    //Table
//    glPushMatrix();
//    glTranslatef(0,0,3);
//    drawTable();
//    glPopMatrix();
//}
//
//
//void doubleTableChairSet()
//{
//    //Back chair
//    glPushMatrix();
//    glTranslatef(1.5,0,0);
//    drawChair();
//    glPopMatrix();
//
//    //Back chair
//    glPushMatrix();
//    glTranslatef(6.5,0,0);
//    drawChair();
//    glPopMatrix();
//
//    //Front chair
//    glPushMatrix();
//    glTranslatef(3.5,0, 16);
//    glRotatef(180, 0, 1, 0);
//    drawChair();
//    glPopMatrix();
//
//    //Front chair 2
//    glPushMatrix();
//    glTranslatef(8.5,0, 16);
//    glRotatef(180, 0, 1, 0);
//    drawChair();
//    glPopMatrix();
//
//
//    //Table
//    glPushMatrix();
//    glTranslatef(0,0,3);
//    glScalef(2,1,1);
//    drawDoubleTable(); //double table used
//    glPopMatrix();
//}
//
//
//void threeSingleTableChairSet()
//{
//    glPushMatrix();
//    glTranslatef(5,0,80);
//    singleTableChairSet();
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslatef(5,0,60);
//    singleTableChairSet();
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslatef(5,0,40);
//    singleTableChairSet();
//    glPopMatrix();
//}
//
//void threeDoubleTableChairSet()
//{
//    glPushMatrix();
//    glTranslatef(5,0,80);
//    doubleTableChairSet();
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslatef(5,0,60);
//    doubleTableChairSet();
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslatef(5,0,40);
//    doubleTableChairSet();
//    glPopMatrix();
//}
//
//
//void drawTwothreeSingleTableChairSet()
//{
//    glPushMatrix();
//    glTranslatef(0,0,40);
//    threeSingleTableChairSet();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(65,0,40);
//    threeSingleTableChairSet();
//    glPopMatrix();
//}
//
//
//void drawThreeRowsOfthreeDoubleTableChairSet()
//{
//    glPushMatrix();
//    glTranslatef(10,0,40);
//    threeDoubleTableChairSet();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(30,0,40);
//    threeDoubleTableChairSet();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(50,0,40);
//    threeDoubleTableChairSet();
//    glPopMatrix();
//}
//
//void drawLibraryRoom()
//{
//    //Left Side Wall
//    glPushMatrix();
//    glScalef(0.1,40,140);
//    drawcube(0.94,0.94,0.86, 0.96,0.96,0.86, 1,1,1,60);
//    glPopMatrix();
//
//    //Right Side Wall
//    glPushMatrix();
//    glTranslatef(80,0,0);
//    glScalef(0.1,40,140);
//    drawcube(0.94,0.94,0.86, 0.96,0.96,0.86, 1,1,1,60);
//    glPopMatrix();
//
//    //Roof
//    glPushMatrix();
//    glTranslatef(0,40,0);
//    glScalef(80,0.1,140);
//    drawcube(0.94,0.94,0.86, 0.96,0.96,0.86, 1,1,1,60);
//    glPopMatrix();
//
//    //Back Wall
//    glPushMatrix();
//    glScalef(80,40,0.1);
//    drawcube(0.94,0.94,0.86, 0.96,0.96,0.86, 1,1,1,60);
//    glPopMatrix();
//
//
//    //Floor
//    glPushMatrix();
//    glScalef(80,0.1,140);
//    drawcube(0.40,0.40,0.40, 0.40,0.40,0.40, 1,1,1,60);
//    glPopMatrix();
//
//    //Front Wall
//    glPushMatrix();
//    glScalef(80,40,140.1);
//    drawcube(0.94,0.94,0.86, 0.96,0.96,0.86, 1,1,1,60);
//    glPopMatrix();
//
//
//}
//
//
//void drawUpperSideWindow()
//{
//    //sky blue window left
//    glPushMatrix();
//    glTranslatef(0.11, 32, 5);
//    glScalef(0.1,5,130);
//    drawcube(0.79, 0.87, 0.92, 0.79, 0.87, 0.92, 1,1,1,60);
//    glPopMatrix();
//
//    //sky blue window right
//    glPushMatrix();
//    glTranslatef(79.9, 32, 5);
//    glScalef(0.1,5,130);
//    drawcube(0.79, 0.87, 0.92, 0.79, 0.87, 0.92, 1,1,1,60);
//    glPopMatrix();
//
//    //left window bar 1
//    glPushMatrix();
//    glTranslatef(0.21, 33.7, 5);
//    glScalef(0.1,0.1,130);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //right window bar 1
//    glPushMatrix();
//    glTranslatef(79.79, 33.7, 5);
//    glScalef(0.1,0.1,130);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //left window bar 2
//    glPushMatrix();
//    glTranslatef(0.21, 35.4, 5);
//    glScalef(0.1,0.1,130);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //right window bar 2
//    glPushMatrix();
//    glTranslatef(79.79, 35.4, 5);
//    glScalef(0.1,0.1,130);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //left window vertical bar 1
//    glPushMatrix();
//    glTranslatef(0.21, 32, 46);
//    glScalef(0.1,5,0.1);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //right window vertical bar 1
//    glPushMatrix();
//    glTranslatef(79.79, 32, 46);
//    glScalef(0.1,5,0.1);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //left window vertical bar 2
//    glPushMatrix();
//    glTranslatef(0.21, 32, 65);
//    glScalef(0.1,5,0.1);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //left window vertical bar 3
//    glPushMatrix();
//    glTranslatef(0.21, 32, 92);
//    glScalef(0.1,5,0.1);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //left window vertical bar 4
//    glPushMatrix();
//    glTranslatef(0.21, 32, 120);
//    glScalef(0.1,5,0.1);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //right window vertical bar 2
//    glPushMatrix();
//    glTranslatef(79.79, 32, 65);
//    glScalef(0.1,5,0.1);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //right window vertical bar 3
//    glPushMatrix();
//    glTranslatef(79.79, 32, 92);
//    glScalef(0.1,5,0.1);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//    //right window vertical bar 4
//    glPushMatrix();
//    glTranslatef(79.79, 32, 120);
//    glScalef(0.1,5,0.1);
//    drawcube(0.5,0.5,0.5, 0.5,0.5,0.5, 1,1,1,60);
//    glPopMatrix();
//
//}
//
//
//void bookRows()
//{
//    //red book
//    glPushMatrix();
//    glTranslatef(0.21,0,0);
//    glScalef(0.8,2.5,2.3);
//    drawcube(0.7,0,0,0.7,0.0,0.0, 1,1,1,60);
//    glPopMatrix();
//
//    //green book
//    glPushMatrix();
//    glTranslatef(0.3,0,0);
//    glScalef(1.8,2.7,2.3);
//    drawcube(0,0.7,0,0,0.7,0, 1,1,1,60);
//    glPopMatrix();
//
//    //blue book
//    glPushMatrix();
//    glTranslatef(2.1,0,0);
//    glScalef(1.3,1.5,2.3);
//    drawcube(0,0,0.7,0,0,0.7, 1,1,1,60);
//    glPopMatrix();
//
//    //orange book
//    glPushMatrix();
//    glTranslatef(3.4,0,0);
//    glScalef(1.3,2.5,2.3);
//    drawcube(0.84,0.41,0.08, 0.84,0.41,0.08, 1,1,1,60);
//    glPopMatrix();
//
//    //purple book
//    glPushMatrix();
//    glTranslatef(4.7,0,0);
//    glScalef(1.5,3,2.3);
//    drawcube(0.7,0.11,0.74,0,0,0.7, 1,1,1,60);
//    glPopMatrix();
//
//    //yellow book
//    glPushMatrix();
//    glTranslatef(6.2,0,0);
//    glScalef(1.1,2.5,2.3);
//    drawcube(0.84,0.82,0.18, 0.84,0.82,0.18, 1,1,1,60);
//    glPopMatrix();
//
//
//}
//
//void bookshelfBase()
//{
//    //Bookshelf base
//    glPushMatrix();
//    glScalef(15,0.2,2.5);
//    drawcube(0.753,0.753,0.753,0.753,0.753,0.753, 1,1,1,60);
//    glPopMatrix();
//
//}
//
//void bookshelfVerticalSide()
//{
//    //Bookshelf base
//    glPushMatrix();
//    glScalef(0.2,16,2.5);
//    drawcube(0.753,0.753,0.753,0.753,0.753,0.753, 1,1,1,60);
//    glPopMatrix();
//
//}
//
//void bookshelfSetUp()
//{
//    //base
//    glPushMatrix();
//    bookRows();
//    glPushMatrix();
//    glTranslatef(7.3, 0, 0);
//    bookRows();
//    glPopMatrix();
//    bookshelfBase();
//    glPopMatrix();
//
//
//    //upper bases
//    glPushMatrix();
//    glTranslatef(0, 4, 0);
//    bookRows();
//    glPushMatrix();
//    glTranslatef(7.3, 0, 0);
//    bookRows();
//    glPopMatrix();
//    bookshelfBase();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0, 8, 0);
//    bookRows();
//    glPushMatrix();
//    glTranslatef(7.3, 0, 0);
//    bookRows();
//    glPopMatrix();
//    bookshelfBase();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0, 12, 0);
//    bookRows();
//    glPushMatrix();
//    glTranslatef(7.3, 0, 0);
//    bookRows();
//    glPopMatrix();
//    bookshelfBase();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0, 16, 0);
//    bookshelfBase();
//    glPopMatrix();
//
//    //left side
//    glPushMatrix();
//    bookshelfVerticalSide();
//    glPopMatrix();
//
//    //right side
//    glPushMatrix();
//    glTranslatef(14.8, 0, 0);
//    bookshelfVerticalSide();
//    glPopMatrix();
//
//}
//
//void drawBookshelf()
//{
//    //leftmos back bookshelf
//    glPushMatrix();
//    glTranslatef(2, 0, 3);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //left back bookshelf
//    glPushMatrix();
//    glTranslatef(20, 0, 3);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //right back bookshelf
//    glPushMatrix();
//    glTranslatef(46, 0, 3);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //rightmost back bookshelf
//    glPushMatrix();
//    glTranslatef(63, 0, 3);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v11 bookshelf
//    glPushMatrix();
//    glTranslatef(2, 0, 28);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v12 bookshelf
//    glPushMatrix();
//    glTranslatef(17, 0, 28);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v13 bookshelf
//    glPushMatrix();
//    glTranslatef(32, 0, 28);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v14 bookshelf
//    glPushMatrix();
//    glTranslatef(46, 0, 28);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v15 bookshelf
//    glPushMatrix();
//    glTranslatef(60.5, 0, 28);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v16 bookshelf
//    glPushMatrix();
//    glTranslatef(75, 0, 28);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//    ////////////////////
//
//    //v21 bookshelf
//    glPushMatrix();
//    glTranslatef(2, 0, 50);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v22 bookshelf
//    glPushMatrix();
//    glTranslatef(17, 0, 50);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v23 bookshelf
//    glPushMatrix();
//    glTranslatef(32, 0, 50);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v24 bookshelf
//    glPushMatrix();
//    glTranslatef(46, 0, 50);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v25 bookshelf
//    glPushMatrix();
//    glTranslatef(60.5, 0, 50);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//    //v26 bookshelf
//    glPushMatrix();
//    glTranslatef(75, 0, 50);
//    glRotatef(90,0,1,0);
//    bookshelfSetUp();
//    glPopMatrix();
//
//
//}
//
//void drawCeilingSpotLight()
//{
//
//    //holder tube
//    glPushMatrix();
//    glTranslatef(39,38,60);
//    glScalef(2,2,2);
//    drawcube(0.4,.4,.4,.4,.4,.4,1,1,1,60);
//    glPopMatrix();
//
//
//    ceilingLightHolder(0.3,0.3,0.4,0.3,0.3,0.4, 1,1,1,60);
//    ceilingLight(.85,.85,.85, .85,.85,.85, 1,1,1,60);
//}
//
//void drawFanConnectorsandBlade()
//{
//    glPushMatrix();
//    glRotatef(90,1, 0, 0);
//    glScalef(.4,.4,.4);
//
//    //cone1
//
//    glPushMatrix();
//    glTranslatef(0,0,-3);
//    gluCylinder(gluNewQuadric(),1,4,3,32,32);
//    glPopMatrix();
//
//
//    //rod
//    glPushMatrix();
//    glTranslatef(0,0,-12);
//    gluCylinder(gluNewQuadric(),1,1,10,32,32);
//    glPopMatrix();
//
//
//    //cone2
//    glPushMatrix();
//    glTranslatef(0,0,-15);
//    gluCylinder(gluNewQuadric(),2.5,1,3,32,32);
//    glPopMatrix();
//
//    glPushMatrix();
//    //glRotatef( C_hr_alpha,0, 0, 1);
//    glRotatef( falpha,0, 0, 1);
//
//    //connector1
//    glPushMatrix();
//    glRotatef(5,0,1,0);
//    glTranslatef(-1,5,0.5);
//    glScalef(2,4,.7);
//    drawcube(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    //connector2
//    glPushMatrix();
//    glRotatef(5,0,1,0);
//    glTranslatef(5,-5,0.5);
//    glRotatef(45,0,0,1);
//
//    glScalef(2,4,.7);
//    drawcube(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    //connector3
//    glPushMatrix();
//    glRotatef(5,0,1,0);
//    glTranslatef(-6,-4,0.5);
//    glRotatef(-45,0,0,1);
//
//    glScalef(2,4,.7);
//    drawcube(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    //blade 1
//
//    glPushMatrix();
//    glRotatef(5,0,1,0);
//    glTranslatef(-1.8,6,0.5);
//    glScalef(3.5,25,.5);
//    drawcube(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    //blade2
//    glPushMatrix();
//    glRotatef(5,0,1,0);
//    glTranslatef(20,-21,0.5);
//    glRotatef(45,0,0,1);
//    glScalef(3.5,25,.5);
//    drawcube(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    //blade3
//    glPushMatrix();
//    glRotatef(5,0,1,0);
//    glTranslatef(-23,-20,0.5);
//    glRotatef(-45,0,0,1);
//    glScalef(3.5,25,.5);
//    drawcube(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    glPopMatrix();
//    glPopMatrix();
//}
//
//void buildFan(GLfloat ar,GLfloat ag,GLfloat ab, GLfloat dr,GLfloat dg,GLfloat db, GLfloat sr,GLfloat sg,GLfloat sb, GLfloat s)
//{
//    glPushMatrix();
//    glScalef(.4,.4,.4);
//    //glTranslatef(41.5,30,30);
//
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { ar, ag, ab, 1.0 };
//    GLfloat mat_diffuse[] = { dr, dg, db, 1.0 };
//    GLfloat mat_specular[] = { sr, sg, sb, 1.0 };
//    GLfloat mat_shininess[] = {s};
//    GLfloat mat_em[] = {1.0,1.0,1.0,1.0};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glPushMatrix();
//    glRotatef(90,1,0,0);
//    //fan base
//    glPushMatrix();
//    //glScalef(3,3,1);
//    gluCylinder(gluNewQuadric(), 4.5, 4.5, 2,100, 100);
//    glPopMatrix();
//
//    //back
//    glPushMatrix();
//    gluDisk(gluNewQuadric(),.5,4.5,32,32);
//    glPopMatrix();
//
//    //front
//    glTranslatef(0,0,2);
//    gluDisk(gluNewQuadric(),0,4.5,32,32);
//    glPopMatrix();
//    glPopMatrix();
//
//    drawFanConnectorsandBlade();
//
//    glPopMatrix();
//
//}
//
//void drawFans()
//{
//    //first row
//    glPushMatrix();
//    glTranslatef(15,34,5);
//    buildFan(.72,.67,.27,.72,.67,.27,1,1,1,30);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(41,34,5);
//    buildFan(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(65,34,5);
//    buildFan(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    //second row
//    glPushMatrix();
//    glTranslatef(15,34,30);
//    buildFan(.72,.67,.27,.72,.67,.27,1,1,1,30);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(41,34,30);
//    buildFan(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(65,34,30);
//    buildFan(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    //third row
//    glPushMatrix();
//    glTranslatef(15,34,110);
//    buildFan(.72,.67,.27,.72,.67,.27,1,1,1,30);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(41,34,110);
//    buildFan(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(65,34, 110);
//    buildFan(.72,.67,.27,.72,.67,.27,1,1,1,60);
//    glPopMatrix();
//}
//
//
//
//void drawSkyAndGrass()
//{
//
//    //sky
//    glPushMatrix();
//    glTranslatef(-200,-200,-10);
//    glScalef(500,500,1);
//    drawcube(0.54,.78,.86,0.54,.78,.86,1,1,1,60);
//    glPopMatrix();
//
//    //sky
//    glPushMatrix();
//    glRotatef(90, 0,1,0);
//    glTranslatef(-200,-200,-10);
//    glScalef(500,500,1);
//    drawcube(0.54,.78,.86,0.54,.78,.86,1,1,1,60);
//    glPopMatrix();
//
//    //sky
//    glPushMatrix();
//    glTranslatef(110,-200,-10);
//    glScalef(1,500,200);
//    drawcube(0.54,.78,.86,0.54,.78,.86,1,1,1,60);
//    glPopMatrix();
//
//    //floor
//    glPushMatrix();
//    glTranslatef(-200,-1.5,-10);
//    glScalef(500,1,500);
//    drawcube(0.4,.44,.22,0.4,.44,.22,1,1,1,60);
//    glPopMatrix();
//
//}
//
//
////
////void drawCar()
////{
//////    //Upper
//////        glEnable(GL_TEXTURE_2D);
//////    glPushMatrix();
//////    glTranslatef(30,0,100);
//////    drawBox();
//////    LoadTexture1("C:\\Users\\NLP Lab\\Desktop\\Lab_3\\Texture\\table.bmp");
//////    glPopMatrix();
//////    glDisable(GL_TEXTURE_2D);
////
////    glEnable(GL_TEXTURE_2D);
////    glPushMatrix();
////    glTranslatef(20, 10, 110);
////    glScalef(20,5,13);
//////    drawcube2(1,1,1,1,1,1, 1,1,1,60);
////    drawcube3(1,1,1);
////    LoadTexture1("F:\\CSE Works & Studies\\CLASSDATA\\4-2 2022\\CSE 4207 - Computer Graphics\\My projects\\assignment3\\table.bmp");
////    glPopMatrix();
////    glDisable(GL_TEXTURE_2D);
////
////    //Lower
////    glEnable(GL_TEXTURE_2D);
////    glPushMatrix();
////    glTranslatef(15, 3, 100);
////    glScalef(30,7,25);
////    drawcube2(1,1,1,1,1,1, 1,1,1,60);
////    LoadTexture("F:\\CSE Works & Studies\\CLASSDATA\\4-2 2022\\CSE 4207 - Computer Graphics\\My projects\\assignment3\\floor.bmp");
////    glPopMatrix();
////    glDisable(GL_TEXTURE_2D);
////
////}
//
//
//void drawStairs()
//{
//
//    glPushMatrix();
//    glTranslatef(50,1,65);
//
//    //stair base 1
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glScalef(5,1,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//
//    //stairs
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(5,1,0);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(6.5,2.5,0);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(7,4,0);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(8.5,5.5,0);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(10,6,0);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(11.5,7.5,0);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(13,9,0);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(14.5,10.5,0);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    //stair base 2
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(20,13,3);
//    glScalef(5,1,13);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(15,15,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(13.5,17,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(12,19,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(10.5,22,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(9,24,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(7.5,26,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(5,28,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(3.5,30,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(2,32,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(0,34,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-1.5,36,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(-3,38,10);
//    glScalef(1.5,1.5,5);
//    glBindTexture(GL_TEXTURE_2D,1);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//
//    glPopMatrix();
//}
//
//
//GLdouble dx=0;
//
//void drawDoor()
//{
//
//    glPushMatrix();
//    glTranslatef(40,10,140.1);
//    glScalef(7,10,.1);
//    drawcube3(0,0,0);
//    glPopMatrix();
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(dx,0,0);
//    glTranslatef(40,10,140.2);
//    glScalef(7,10,.5);
//    glBindTexture(GL_TEXTURE_2D, 4);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//}
//
//void window()
//{
//    glPushMatrix();
//    glTranslatef(1.5,22,123);
//    glScalef(1,1,9);
//    drawcube3(.46,.33,.25);
//    glPopMatrix();
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(1.5,15,125);
//    glScalef(0.1,7,5);
//    glBindTexture(GL_TEXTURE_2D, 2);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(1.5,12,131);
//    glScalef(0.1,10,2);
//    glBindTexture(GL_TEXTURE_2D, 3);
//    drawcube3(1,1,1);
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//}
//
//void drawWindows()
//{
//    glPushMatrix();
//    //glTranslatef(1.5,22,123);
//    window();
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslatef(0,0,-30);
//    window();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0,0,-60);
//    window();
//    glPopMatrix();
//}
//
//
//void display()
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
//    cameraRoll();
//    gluLookAt(eye_x,eye_y,eye_z, lookat_x,lookat_y,lookat_z, up_x,up_y,up_z);
//    glViewport(0, 0, windowHeight, windowWidth);
//
//    glRotatef( alpha,axis_x, axis_y, 0.0 );
//    glRotatef( theta, axis_x, axis_y, 0.0 );
//    glScaled(sx,sy,sz);
//
//
//    drawSkyAndGrass();
//    drawLibraryRoom();
//    drawCeilingSpotLight();
//    drawClock(1,.77,.36,1,.77,.36,1,1,1,60);
//    drawFans();
//
//    glPushMatrix();
//    glTranslatef(0,0.1,0); // to raise everything above floor
//    drawTwothreeSingleTableChairSet();
//    drawThreeRowsOfthreeDoubleTableChairSet();
//    drawUpperSideWindow();
//    drawBookshelf();
////    drawCar();
//    glPopMatrix();
//
//    glPushMatrix();
////    glRotatef(90,0,1,0);
//    drawStairs();
//    drawWindows();
//    glPopMatrix();
//
//    drawDoor();
//
//    light(25.0,15.0,-1,light0,GL_LIGHT0,false,false); //tube
//    light(40,32,60,light1,GL_LIGHT1,true,false); //spot
//    light(-55,4,28,light2,GL_LIGHT2,false,true); //strip
//    glFlush();
//    glutSwapBuffers();
//
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
//        }
//        glutPostRedisplay();
//        break;
//    case 'j':
//        if(angleRoll>=-180)
//        {
//            angleRoll--;
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
//    case 'u':
//        if(dx<=10)
//        {
//            dx +=1;
//        }
//        glutPostRedisplay();
//        break;
//
//    //fanswitch
//    case 'f':
//    case 'F':
//        fRotate = !fRotate;
//        axis_x=0.0;
//        axis_y=1.0;
//        break;
//
//    //switch for light0 tube
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
//        zRotate = !zRotate;
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
//        alpha += 0.2;
//        if(alpha > 360.0)
//            alpha -= 360.0*floor(alpha/360.0);
//    }
//    if (zRotate == true)
//    {
//        gammaa += 0.5;
//        if(gammaa > 360.0)
//            gammaa -= 360.0*floor(gammaa/360.0);
//    }
//
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
//    if (fRotate == true)  //for fan
//    {
//        falpha += 3;
//        if(falpha > 360.0)
//            falpha -= 360.0*floor(falpha/360.0);
//    }
////
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
//    glutCreateWindow("Central Library");
//    ///glutReshapeFunc(resize);
//
//    glShadeModel( GL_SMOOTH );
//    glEnable( GL_DEPTH_TEST );
//    glEnable(GL_NORMALIZE);
//    glEnable(GL_LIGHTING);
//
//    LoadTexture("F:\\CSE Works & Studies\\CLASSDATA\\4-2 2022\\CSE 4207 - Computer Graphics\\My projects\\central_library_final1\\stair.bmp"); //1
//    LoadTexture("F:\\CSE Works & Studies\\CLASSDATA\\4-2 2022\\CSE 4207 - Computer Graphics\\My projects\\central_library_final1\\sunset3.bmp"); //2
//    LoadTexture("F:\\CSE Works & Studies\\CLASSDATA\\4-2 2022\\CSE 4207 - Computer Graphics\\My projects\\central_library_final1\\curtain.bmp"); //3
//    LoadTexture("F:\\CSE Works & Studies\\CLASSDATA\\4-2 2022\\CSE 4207 - Computer Graphics\\My projects\\central_library_final1\\door.bmp"); //4
//
//
//    glutKeyboardFunc(myKeyboardFunc);
//    glutDisplayFunc(display);
//    glutIdleFunc(animate);
//
////    printf("Press '1' to on/off light  from the front side.\n");
////    printf("Press '2' to on/off light  from the right side.\n");
////    printf("Press '3' to on/off spot light from the left side.\n");
//
//
//    glutMainLoop();
//    return 0;
//}
//
