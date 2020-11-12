/*************************************/
/* A Hex program using openGL & C++  */
/*************************************/

// this code just creates a window and draws three rectangles in it

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <memory>
#include <GL/freeglut.h>



using namespace std;

int x, y;
bool check;
int turn = 1;

/*
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
}*/


/*
    Utility function to draw the circle
*/
void DrawCircle1(float cx, float cy, float r, int num_segments) 
{   
    glColor3f(0.0, 1.0, 0.0);
    turn = 2;
   
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)   
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 
        float x = r * cosf(theta);//calculate the x component 
        float y = r * sinf(theta);//calculate the y component 
        glVertex2f(x + cx, y + cy);//output vertex 
    }
    glEnd();
}

void DrawCircle2(float cx, float cy, float r, int num_segments) 
{   
   
    
    glColor3f(0.0, 0.0, 1.0);
    turn = 1;
    
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)   
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 
        float x = r * cosf(theta);//calculate the x component 
        float y = r * sinf(theta);//calculate the y component 
        glVertex2f(x + cx, y + cy);//output vertex 
    }
    glEnd();
}

// display content (called automatically in main loop)
void display(){
    //glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1.0, 1.0, 1.0);
    //glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT);       // clear color buffer
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 0.0, 0.0);


    double start_x = 0.0;
    double start_y = 0.0;
    for(int i=10; i>0; i--){
        if(i==10){ start_x = 20.0; start_y = 185.0;}
        if(i==9) { start_x = 40.0; start_y = 205;}
        if(i==8 ){ start_x = 60.0; start_y = 225;}
        if(i==7 ){ start_x = 80.0; start_y = 245;}
        if(i==6 ){ start_x = 100.0; start_y = 265;}
        if(i==5 ){ start_x = 120.0; start_y = 285;}
        if(i==4 ){ start_x = 140.0; start_y = 305;}
        if(i==3 ){ start_x = 160.0; start_y = 325;}
        if(i==2 ){ start_x = 180.0; start_y = 345;}
        if(i==1 ){ start_x = 200.0; start_y = 365;}

        double increment_x = 0;
        double increment_y = 0;
        for(int j=0; j<i; j++){
            glBegin(GL_POLYGON); 
            glVertex3f(start_x-0+increment_x, start_y, 0.0);
            glVertex3f(start_x-20+increment_x, start_y+10, 0.0);
            glVertex3f(start_x-20+increment_x, start_y+20, 0.0);
            glVertex3f(start_x+increment_x, start_y+30, 0.0);
            glVertex3f(start_x+20+increment_x, start_y+20, 0.0);
            glVertex3f(start_x+20+increment_x, start_y+10, 0.0);
            increment_x += 40;
            
            glEnd();
        }
    } 

    // draw top half of the board
    for(int i=9; i>0; i--){
        if(i==9) { start_x = 40.0; start_y = 165;}
        if(i==8 ){ start_x = 60.0; start_y = 145;}
        if(i==7 ){ start_x = 80.0; start_y = 125;}
        if(i==6 ){ start_x = 100.0; start_y = 105;}
        if(i==5 ){ start_x = 120.0; start_y = 85;}
        if(i==4 ){ start_x = 140.0; start_y = 65;}
        if(i==3 ){ start_x = 160.0; start_y = 45;}
        if(i==2 ){ start_x = 180.0; start_y = 25;}
        if(i==1 ){ start_x = 200.0; start_y = 05;}

        double increment_x = 0;
        double increment_y = 0;
        for(int j=0; j<i; j++){
            glBegin(GL_POLYGON); 
            glVertex3f(start_x-0+increment_x, start_y, 0.0);
            glVertex3f(start_x-20+increment_x, start_y+10, 0.0);
            glVertex3f(start_x-20+increment_x, start_y+20, 0.0);
            glVertex3f(start_x+increment_x, start_y+30, 0.0);
            glVertex3f(start_x+20+increment_x, start_y+20, 0.0);
            glVertex3f(start_x+20+increment_x, start_y+10, 0.0);
            increment_x += 40;
            
            glEnd();
        }
    } 


    if(check){
        if(turn == 1){
            DrawCircle1(x, y, 10, 15);
        }
        else if (turn == 2){
            DrawCircle2(x,y, 10, 15);
        }
    }
    glFlush();
    glutSwapBuffers();             // bring draw buffer to front
}

// Mouse click
void onMouse(int button, int state, int mousex, int mousey){
    
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        check = true;
        x = mousex;
        y = mousey;
        cout << "left clicked down\n";
        
    }
    glutPostRedisplay();
}


/*
    Function to reshape
*/
void Reshape(int x, int y)
{
    glViewport(0, 0, x, y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, x, y, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
}


int main (int argc, char **argv){
    //LoadMap("map.bmp");
    // setup window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // double buffering, rbg mode
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hex Board");
    glutMouseFunc(onMouse);
    //init();

    // register call-back function
    glutReshapeFunc(Reshape);
    glutDisplayFunc(display);

    // glut takes over - calling display() repeatedly
    glutMainLoop();
    return 0;
}