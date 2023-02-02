///*
//
// Texturing
//Author: Faiyaj Bin Amin
//Roll: 1707062
//
//*/
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
//#include "BmpLoader.h"
//
//using namespace std;
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
////#include<GL/gl.h>
////#include <GL/glu.h>
////#include <GL/glut.h>
////#include <stdlib.h>
////#include <stdio.h>
////#include <windows.h>
////#include<math.h>
////#include<bits/stdc++.h>
////#include "BmpLoader.h"
////
////using namespace std;
////
////double Txval=0,Tyval=0,Tzval=0;
////double windowHeight=1000, windowWidth=1000;
////GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
////GLboolean bRotate = false, uRotate = false;
////unsigned int ID, ID2; // take id array for project
////
////
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
////
////static void getNormal3p
////(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
////{
////    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;
////
////    Ux = x2-x1;
////    Uy = y2-y1;
////    Uz = z2-z1;
////
////    Vx = x3-x1;
////    Vy = y3-y1;
////    Vz = z3-z1;
////
////    Nx = Uy*Vz - Uz*Vy;
////    Ny = Uz*Vx - Ux*Vz;
////    Nz = Ux*Vy - Uy*Vx;
////
////    glNormal3f(Nx,Ny,Nz);
////}
////
////void drawBox()
////{
////  //  glColor3f(1,1,1);
////    //GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
////    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
////    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
////    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
////    GLfloat mat_shininess[] = {60};
////
////    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
////    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
////    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
////    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
////
////    glBegin(GL_QUADS);
////    for (GLint i = 0; i <6; i++)
////    {
////        //glColor3f(colors[4][0],colors[4][1],colors[4][2]);
////        getNormal3p(v_box[quadIndices[i][0]][0], v_box[quadIndices[i][0]][1], v_box[quadIndices[i][0]][2],
////                    v_box[quadIndices[i][1]][0], v_box[quadIndices[i][1]][1], v_box[quadIndices[i][1]][2],
////                    v_box[quadIndices[i][2]][0], v_box[quadIndices[i][2]][1], v_box[quadIndices[i][2]][2]);
//////
//////        glVertex3fv(&v_box[quadIndices[i][0]][0]);glTexCoord2f(1,1);
//////        glVertex3fv(&v_box[quadIndices[i][1]][0]);glTexCoord2f(1,0);
//////        glVertex3fv(&v_box[quadIndices[i][2]][0]);glTexCoord2f(0,0);
//////        glVertex3fv(&v_box[quadIndices[i][3]][0]);glTexCoord2f(0,1);
////
////        glVertex3fv(&v_box[quadIndices[i][0]][0]);glTexCoord2f(0,1);
////        glVertex3fv(&v_box[quadIndices[i][1]][0]);glTexCoord2f(1,1);
////        glVertex3fv(&v_box[quadIndices[i][2]][0]);glTexCoord2f(1,0);
////        glVertex3fv(&v_box[quadIndices[i][3]][0]);glTexCoord2f(0,0);
////    }
////    glEnd();
////    //glutSolidSphere (3.0, 20, 16);
////
////}
////
////void drawPlane()
////{
////  //  glColor3f(1,1,1);
////    //GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
////    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
////    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
////    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
////    GLfloat mat_shininess[] = {60};
////
////    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
////    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
////    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
////    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
////
////    glBegin(GL_QUADS);
////    for (GLint i = 0; i <1; i++)
////    {
////        //glColor3f(colors[4][0],colors[4][1],colors[4][2]);
////        getNormal3p(v_box[quadIndices[i][0]][0], v_box[quadIndices[i][0]][1], v_box[quadIndices[i][0]][2],
////                    v_box[quadIndices[i][1]][0], v_box[quadIndices[i][1]][1], v_box[quadIndices[i][1]][2],
////                    v_box[quadIndices[i][2]][0], v_box[quadIndices[i][2]][1], v_box[quadIndices[i][2]][2]);
//////
//////        glVertex3fv(&v_box[quadIndices[i][0]][0]);glTexCoord2f(1,1);
//////        glVertex3fv(&v_box[quadIndices[i][1]][0]);glTexCoord2f(1,0);
//////        glVertex3fv(&v_box[quadIndices[i][2]][0]);glTexCoord2f(0,0);
//////        glVertex3fv(&v_box[quadIndices[i][3]][0]);glTexCoord2f(0,1);
////
////        glVertex3fv(&v_box[quadIndices[i][0]][0]);glTexCoord2f(0,1);
////        glVertex3fv(&v_box[quadIndices[i][1]][0]);glTexCoord2f(1,1);
////        glVertex3fv(&v_box[quadIndices[i][2]][0]);glTexCoord2f(1,0);
////        glVertex3fv(&v_box[quadIndices[i][3]][0]);glTexCoord2f(0,0);
////    }
////    glEnd();
////    //glutSolidSphere (3.0, 20, 16);
////
////}
////
////
////
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
////
//////void drawPlane()
//////{
//////
//////}
////
////void display(void)
////{
////    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
////
////    glMatrixMode( GL_PROJECTION );
////    glLoadIdentity();
////    glFrustum(-5,5,-5,5, 4,50);
////    //gluPerspective(60,1,5,100);
////    //glOrtho(-5,5,-5,5, 4, 50);
////
////    glMatrixMode( GL_MODELVIEW );
////    glLoadIdentity();
////    gluLookAt(0,0,10, 0,0,0, 0,1,0);
////
////    glViewport(0, 0, windowHeight, windowWidth);
////
////    glEnable(GL_TEXTURE_2D);
////
////    glPushMatrix();
////    glTranslatef(0,0,Tzval);
////    glRotatef( alpha,axis_x, axis_y, 0.0 );
////    glRotatef( theta, axis_x, axis_y, 0.0 );
////    drawBox();
////    glPopMatrix();
////
//////    glDisable(GL_TEXTURE_2D);
//////
//////
//////    glEnable(GL_TEXTURE_2D);
////
////    glPushMatrix();
////    glTranslatef(0,0,Tzval);
////    glScaled(5,5,0);
////    glRotatef( alpha,axis_x, axis_y, 0.0 );
////    glRotatef( theta, axis_x, axis_y, 0.0 );
////    drawPlane();
////    glPopMatrix();
////
////    glDisable(GL_TEXTURE_2D);
////
////    glFlush();
////    glutSwapBuffers();
////
////}
////
////void myKeyboardFunc( unsigned char key, int x, int y )
////{
////    switch ( key )
////    {
////    case 's':
////    case 'S':
////        bRotate = !bRotate;
////        uRotate = false;
////        axis_x=0.0;
////        axis_y=1.0;
////        break;
////
////    case 'r':
////    case 'R':
////        uRotate = !uRotate;
////        bRotate = false;
////        axis_x=1.0;
////        axis_y=0.0;
////        break;
////    case '+':
////        Tzval+=0.2;
////        break;
////
////    case '-':
////        Tzval-=0.2;
////        break;
////
////    case 27:	// Escape key
////        exit(1);
////    }
////}
////
////
////void animate()
////{
////    if (bRotate == true)
////    {
////        theta += 0.2;
////        if(theta > 360.0)
////            theta -= 360.0*floor(theta/360.0);
////    }
////
////    if (uRotate == true)
////    {
////        alpha += 0.2;
////        if(alpha > 360.0)
////            alpha -= 360.0*floor(alpha/360.0);
////    }
////    glutPostRedisplay();
////
////}
////
////void LoadTexture(const char*filename)
////{
////    glGenTextures(1, &ID);
////    glBindTexture(GL_TEXTURE_2D, ID);
////    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
////    BmpLoader bl(filename); //constructor
////    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
//////
////
////}
////
////
////void LoadTexture2(const char*filename)
////{
////    glGenTextures(2, &ID2);
////    glBindTexture(GL_TEXTURE_2D, ID2);
////    glPixelStorei(GL_UNPACK_ALIGNMENT, ID2);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
////    BmpLoader bl2(filename); //constructor
////    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl2.iWidth, bl2.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl2.textureData );
//////
////
////}
////
////
////int main (int argc, char **argv)
////{
////    glutInit(&argc, argv);
////    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
////
////    glutInitWindowPosition(100,100);
////    glutInitWindowSize(windowHeight, windowWidth);
////    glutCreateWindow("Texture-Demo");
////
//////    LoadTexture("H:\\CLass Content\\Even Semester\\LAB CSE 4208\\Lab4\\Texture\\brick.bmp");
////    LoadTexture("C:\\Users\\NLP Lab\\Desktop\\Lab_3 B1 ori\\Texture\\brick.bmp");
////    LoadTexture2("C:\\Users\\NLP Lab\\Desktop\\Lab_3 B1 ori\\Texture\\table.bmp");
////
////
////    glutKeyboardFunc(myKeyboardFunc);
////    glutDisplayFunc(display);
////    glutIdleFunc(animate);
////
////    //glClearColor(0,0,0,1);
////
////
////    glShadeModel( GL_SMOOTH );
////    glEnable( GL_DEPTH_TEST );
////    glEnable(GL_NORMALIZE);
////    glEnable(GL_LIGHTING);
////
////    light();
////
////
////    glutMainLoop();
////
////    return 0;
////}
////
//
//
//double Txval=0,Tyval=0,Tzval=0;
//double windowHeight=1200, windowWidth=1200;
//double gammaa = 0;
//GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, Calpha= 360.0, C_hr_alpha=360.0;
//GLfloat eye_x = 25.0, eye_y = 15.0, eye_z = 270.0;
//GLfloat lookat_x = 25.0, lookat_y = 15.0, lookat_z = 150.0;
//GLdouble up_x = 0.0;
//GLdouble up_y = 1.0;
//GLdouble up_z = 0.0;
//GLdouble sx=1.0,sy=1.0,sz=1.0;
//
//double anglePitch=0,angleYaw=90,angleRoll = 0;
//int pilotPitch=0,pilotYaw=0,pilotRoll=0; ///
//GLboolean bRotate = false, uRotate = false, cRotate= true, light0 = false,light1=false,light2=false,zRotate = false;
//
//unsigned int ID,ID1;
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
////
//static GLfloat v_box[8][3] =
//{
//    {-2.0, 0.0, 0.0},
//    {2.0, 0.0, 0.0},
//    {-2.0, 0.0, 2.0},
//    {2.0, 0.0, 2.0},
//
//    {-2.0, 2.0, 0.0},
//    {2.0, 2.0, 0.0},
//    {-2.0, 2.0, 2.0},
//    {2.0, 2.0, 2.0}
//};
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
//
//void drawBox()
//{
//  //  glColor3f(1,1,1);
//    //GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = {60};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glBegin(GL_QUADS);
//    for (GLint i = 0; i <6; i++)
//    {
//        //glColor3f(colors[4][0],colors[4][1],colors[4][2]);
//        getNormal3p(v_box[quadIndices[i][0]][0], v_box[quadIndices[i][0]][1], v_box[quadIndices[i][0]][2],
//                    v_box[quadIndices[i][1]][0], v_box[quadIndices[i][1]][1], v_box[quadIndices[i][1]][2],
//                    v_box[quadIndices[i][2]][0], v_box[quadIndices[i][2]][1], v_box[quadIndices[i][2]][2]);
//
//        glVertex3fv(&v_box[quadIndices[i][0]][0]);glTexCoord2f(0,1);
//        glVertex3fv(&v_box[quadIndices[i][1]][0]);glTexCoord2f(1,1);
//        glVertex3fv(&v_box[quadIndices[i][2]][0]);glTexCoord2f(1,0);
//        glVertex3fv(&v_box[quadIndices[i][3]][0]);glTexCoord2f(0,0);
//    }
//    glEnd();
//    //glutSolidSphere (3.0, 20, 16);
//
//}
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
//        glVertex3fv(&v_pyramid[quadIndices[i][0]][0]);glTexCoord2f(0,1);
//        glVertex3fv(&v_pyramid[quadIndices[i][1]][0]);glTexCoord2f(1,1);
//        glVertex3fv(&v_pyramid[quadIndices[i][2]][0]);glTexCoord2f(1,0);
//        glVertex3fv(&v_pyramid[quadIndices[i][3]][0]);glTexCoord2f(0,0);
//        glEnd();
//
//    }
//}
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
//void LoadTexture(const char*filename)
//{
//    glGenTextures(1, &ID);
//    glBindTexture(GL_TEXTURE_2D, ID);
//    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_CLAMP );
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP );
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
//    BmpLoader bl(filename);
//    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
//}
//void LoadTexture1(const char*filename)
//{
//    glGenTextures(1, &ID1);
//    glBindTexture(GL_TEXTURE_2D, ID1);
//    glPixelStorei(GL_UNPACK_ALIGNMENT, ID1);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_CLAMP );
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP );
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
//    BmpLoader bl(filename);
//    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
//}
//
//
//void drawPurpleHouse()
//{
//    //House Cube
//    glPushMatrix();
//    glTranslatef(40, 0.1, 60);
//    glScalef(25,25,20);
//    drawcube(0.50,0.18,0.84, 0.50,0.18,0.84, 1,1,1,60);
//    glPopMatrix();
//
//    //Door
//    glPushMatrix();
//    glTranslatef(50, 0.1, 80);
//    glScalef(5,11,0.11);
//    drawcube(0.84,0.82,0.18, 0.84,0.82,0.18, 1,1,1,60);
//    glPopMatrix();
//
//    //Windows
//    glPushMatrix();
//    glTranslatef(55, 13, 80);
//    glScalef(4,4,0.11);
//    drawcube(0.84,0.82,0.18, 0.84,0.82,0.18, 1,1,1,60);
//    glPopMatrix();
//
//    //Windows
//    glPushMatrix();
//    glTranslatef(60, 13, 80);
//    glScalef(4,4,0.11);
//    drawcube(0.84,0.82,0.18, 0.84,0.82,0.18, 1,1,1,60);
//    glPopMatrix();
//
//    //Windows
//    glPushMatrix();
//    glTranslatef(55, 18, 80);
//    glScalef(4,4,0.11);
//    drawcube(0.84,0.82,0.18, 0.84,0.82,0.18, 1,1,1,60);
//    glPopMatrix();
//
//    //Windows
//    glPushMatrix();
//    glTranslatef(60, 18, 80);
//    glScalef(4,4,0.11);
//    drawcube(0.84,0.82,0.18, 0.84,0.82,0.18, 1,1,1,60);
//    glPopMatrix();
//
//
//}
////
////void drawFence()
////{
////    //House Cube
////    glPushMatrix();
////    glTranslatef(40, 0.1, 60);
////    glScalef(25,25,20);
////    drawcube(0.50,0.18,0.84, 0.50,0.18,0.84, 1,1,1,60);
////    glPopMatrix();
////}
////
//
//void drawCar()
//{
////    //Upper
////        glEnable(GL_TEXTURE_2D);
////    glPushMatrix();
////    glTranslatef(30,0,100);
////    drawBox();
////    LoadTexture1("C:\\Users\\NLP Lab\\Desktop\\Lab_3\\Texture\\table.bmp");
////    glPopMatrix();
////    glDisable(GL_TEXTURE_2D);
//
//     glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(20, 10, 110);
//    glScalef(20,5,13);
//    drawcube2(1,1,1,1,1,1, 1,1,1,60);
//    LoadTexture1("F:\\CSE Works & Studies\\CLASSDATA\\4-2 2022\\CSE 4207 - Computer Graphics\\My projects\\assignment3\\table.bmp");
//    glPopMatrix();
//     glDisable(GL_TEXTURE_2D);
//
//    //Lower
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslatef(15, 3, 100);
//    glScalef(30,7,25);
//    drawcube2(1,1,1,1,1,1, 1,1,1,60);
//    LoadTexture("F:\\CSE Works & Studies\\CLASSDATA\\4-2 2022\\CSE 4207 - Computer Graphics\\My projects\\assignment3\\floor.bmp");
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//
//}
//
//void drawTorus(GLfloat ar,GLfloat ag,GLfloat ab, GLfloat dr,GLfloat dg,GLfloat db, GLfloat sr,GLfloat sg,GLfloat sb, GLfloat s)
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
//    glTranslatef(21,4,125.1);
//    glutSolidTorus(1.0, 3, 16,20);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(39,4,125.1);
//    glutSolidTorus(1.0, 3, 16,20);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(21,4,99.5);
//    glutSolidTorus(1.0, 3, 16,20);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(39,4,99.5);
//    glutSolidTorus(1.0, 3, 16,20);
//    glPopMatrix();
//
//}
//
//void drawGreenFloor()
//{
//    //Floor
//    glPushMatrix();
//    glScalef(80,0.1,140);
//    drawcube(0.0,0.50,0.0, 0.0,0.50,0.0, 1,1,1,60);
//    glPopMatrix();
//
//}
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
//    ///glPushMatrix();
//    ///glTranslatef(0,0,-18);
//
////    drawLibraryRoom();
////    drawCeilingSpotLight();
////
////    glPushMatrix();
////    glTranslatef(0,0.1,0); // to raise everything above floor
////    drawTwothreeSingleTableChairSet();
////    drawThreeRowsOfthreeDoubleTableChairSet();
////    drawUpperSideWindow();
////    drawBookshelf();
////    glPopMatrix();
//
////    glPushMatrix();
////    glTranslatef(30, 0.11, 70);
////    bookshelfSetUp();
////    glPopMatrix();
//
////    //Clock
////    glPushMatrix();
////    glTranslatef(3,10,0);
////    clock();
////    glPopMatrix();
//
//    drawGreenFloor();
//    drawPurpleHouse();
//
//    glPushMatrix();
//    glScalef(0.5, 0.5, 0.5);
//    glTranslatef(0,0,10);
//    drawCar();
//    //LoadTexture1("C:\\Users\\NLP Lab\\Desktop\\Lab_3\\Texture\\table.bmp");
//    drawTorus(.4,.4,.4, .4,.4,.4, 1,1,1,60);
//    glPopMatrix();
//
////    glEnable(GL_TEXTURE_2D);
////    glPushMatrix();
////    glTranslatef(30,0,100);
////    drawBox();
////    LoadTexture1("C:\\Users\\NLP Lab\\Desktop\\Lab_3\\Texture\\table.bmp");
////    glPopMatrix();
////    glDisable(GL_TEXTURE_2D);
//
//
//
////    glPushMatrix();
////    glTranslatef(0,0,Tzval);
////    glRotatef( alpha,axis_x, axis_y, 0.0 );
////    glRotatef( theta, axis_x, axis_y, 0.0 );
////    drawSurface();
////    LoadTexture1("C:\\Users\\NLP Lab\\Desktop\\Lab_3\\Texture\\table.bmp");
////    glPushMatrix();
////    drawBox();
////    LoadTexture("C:\\Users\\NLP Lab\\Desktop\\Lab_3\\Texture\\floor.bmp");
////    glPopMatrix();
////    glPopMatrix();
////    glDisable(GL_TEXTURE_2D);
//
//
//    light(25.0,15.0,-1,light0,GL_LIGHT0,false,false); //tube
//    light(40,32,60,light1,GL_LIGHT1,true,false); //spot
//    light(-55,4,28,light2,GL_LIGHT2,false,true); //strip
//    glFlush();
//    glutSwapBuffers();
//
//}
//
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
//    glutKeyboardFunc(myKeyboardFunc);
//    glutDisplayFunc(display);
//    glutIdleFunc(animate);
//
/////    printf("Press '1' to on/off light  from the front side.\n");
//    printf("Press '2' to on/off light  from the right side.\n");
//    printf("Press '3' to on/off spot light from the left side.\n");
//
//    printf("Press 'a' to on/off the light ambient property for all lights.\n");
//    printf("Press 'd' to on/off the light diffuse property for all lights.\n");
//    printf("Press 's' to on/off the light Specular property for all lights.\n");
//
//    printf("Press 'r' to rotate the scene. \n");
//    printf("Press 'f' to on/off the fan.\n");
//
//    printf("Press '+' to zoom in and '-' to zoom out.\n");
//    printf("Press '*' to look up, '/' to look down, 'z' to look right, and 'x' to look left.\n");
//
//
//
//    glutMainLoop();
//    return 0;
//}
