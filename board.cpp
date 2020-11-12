/*************************************/
/* A Simple OpenGL Example           */
/*************************************/

// this code just creates a window and draws three rectangles in it

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstdlib>

#include <fstream>
#include <memory>
#include <GL/freeglut.h>



using namespace std;

// set up projection
void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0); // clear -> black R,G,B,A = 0 (A=alpha channel)
    glMatrixMode(GL_PROJECTION);      // applies subsequent matrix ops to
                                    // projection matrix
    glLoadIdentity();
    //gluOrtho2D(0.0, 800.0, 0.0, 800.0); // view box
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    // all matrix operations that follow apply to modelview matrix
}

// display content (called automatically in main loop)
void display(){
    //glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1.0, 1.0, 1.0);
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);       // clear color buffer
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.0, 0.0, 0.0);

    // draw the bottom half of the board
    double startx = 0.0;
    double starty = 0.0;
    for(int i=10; i>0; i--){
        if(i==10){ startx = -45.0; starty = 5.0;}
        else if(i==9){ startx = -40.0; starty = 0.0;}
        else if(i==8){ startx = -35.0; starty = -5.0;}
        else if(i==7){ startx = -30.0; starty = -10.0;}
        else if(i==6){ startx = -25.0; starty = -15.0;}
        else if(i==5){ startx = -20.0; starty = -20.0;}
        else if(i==4){ startx = -15.0; starty = -25.0;}
        else if(i==3){ startx = -10.0; starty = -30.0;}
        else if(i==2){ startx = -5.0; starty = -35.0;}
        else if(i==1){ startx =  0.0; starty = -40.0;}

        int count = 0;
        for(int j=0; j<i; j++){
            glBegin(GL_POLYGON); 
            glVertex3f(startx+count, starty, 0.0);
            glVertex3f(startx-5.0+count, starty-2.5, 0.0);
            glVertex3f(startx-5.0+count, starty-5.0, 0.0);
            glVertex3f(startx+0.0+count, starty-7.5, 0.0);
            glVertex3f(startx+5.0+count, starty-5.0, 0.0);
            glVertex3f(startx+5.0+count, starty-2.5, 0.0);
            glEnd(); 
            count+=10;
        }
    }

    // draw the upper half
    for(int i=9; i>0; i--){
        if(i==9){ startx = -40.0; starty = 10.0;}
        else if(i==8){ startx = -35.0; starty = 15.0;}
        else if(i==7){ startx = -30.0; starty = 20.0;}
        else if(i==6){ startx = -25.0; starty = 25.0;}
        else if(i==5){ startx = -20.0; starty = 30.0;}
        else if(i==4){ startx = -15.0; starty = 35.0;}
        else if(i==3){ startx = -10.0; starty = 40.0;}
        else if(i==2){ startx = -5.0; starty = 45.0;}
        else if(i==1){ startx =  0.0; starty = 50.0;}

        int count = 0;
        for(int j=0; j<i; j++){
            glBegin(GL_POLYGON); 
            glVertex3f(startx+count, starty, 0.0);
            glVertex3f(startx-5.0+count, starty-2.5, 0.0);
            glVertex3f(startx-5.0+count, starty-5.0, 0.0);
            glVertex3f(startx+0.0+count, starty-7.5, 0.0);
            glVertex3f(startx+5.0+count, starty-5.0, 0.0);
            glVertex3f(startx+5.0+count, starty-2.5, 0.0);
            glEnd(); 
            count+=10;
        }
    }

    /*
    // the blue line
    //glClear(GL_COLOR_BUFFER_BIT);       // clear color buffer
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.0, 1.0, 0.0);
    startx = -10;
    starty = 50;
    double county=0;
    double countx = 0;
    for(int i=0; i<10; i++){
        glVertex3f(startx, starty, 0.0);
        glVertex3f(startx-countx, starty-county, 0.0);
        countx -=10;
        county -=2.5;
        startx += countx;
        starty += county;
    }
    */
    glFlush();
    glutSwapBuffers();             // bring draw buffer to front
}


int main (int argc, char **argv)
{
    //LoadMap("map.bmp");
  // setup window
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // double buffering, rbg mode
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Hex Board");
  init();

  // register call-back function
  glutDisplayFunc(display);

  // glut takes over - calling display() repeatedly
  glutMainLoop();
  return 0;
}