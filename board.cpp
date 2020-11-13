/*************************************/
/* A Simple Hex Board Game           */
/*************************************/

/* 
 *
 * this code just creates a window,
 * draws a hex board and allows
 * two players red and blue
 * to place stones on the board
 *
*/
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

#include "Hex.h"
#include <vector>

using namespace std;

int turn = 1;
std::vector<Hexagon*>board;     //holds a hundred hexagons

void initializeBoard(){
    double xstart = 200;
    double ystart = 20;
    for(int i=0; i<10; i++){
        double pos_y = ystart+(20*i);
        double pos_x = xstart-(20*i);
        for(int j=0; j<i+1; j++){
            board.push_back(new Hexagon(pos_x, pos_y, 0));
            pos_x += 40;
        }
    }

    // second half of the board
    int nth = 0;
    xstart = 40;
    ystart = 220;
    for(int i=9; i>0; i--){
        double pos_y = ystart+(20*nth);
        double pos_x = xstart+(20*nth);
        for(int j=0; j<i; j++){
            board.push_back(new Hexagon(pos_x, pos_y, 0));
            pos_x += 40;
        }
        nth++;
    }
}


/*
 * Draw the blue circle
*/
void DrawCircle1(float cx, float cy, float r, int num_segments) {   
    glColor3f(0.0, 0.0, 1.0);   
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

/*
 * Draws red stone
*/
void DrawCircle2(float cx, float cy, float r, int num_segments) {   
    glColor3f(1.0, 0.0, 0.0);    
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

/*
 * Fills the position with the 
 * respective stone blue/red
*/
void Draw(){
    for(int i=0; i<100; i++){
        if(board[i]->turn == 1){
            DrawCircle1(board[i]->x, board[i]->y, 10, 15);
        }
        else if(board[i]->turn == 2){
            DrawCircle2(board[i]->x, board[i]->y, 10, 15);
        }
    }
}

// display content (called automatically in main loop)
void display(){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    glColor3f(0.0, 0.0, 0.0);
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
    // fill board with a stones if theres a click
    Draw();
    
    glFlush();
    glutSwapBuffers();             // bring draw buffer to front
}

// Mouse click
void onMouse(int button, int state, int mousex, int mousey){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        for(int i=0; i<100; i++){
            if(fabs(board[i]->x - mousex)<=20 && fabs(board[i]->y - mousey) <=15){
                if(board[i]->turn == 0){
                    board[i]->turn = turn;
                    if(turn == 1){
                        turn = 2;
                    }
                    else if(turn ==2){
                        turn =1;
                    }
                }
                break;
            }
        }
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
    // setup window
    initializeBoard();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // double buffering, rbg mode
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("10X10 Hex Board Game");
    glClearColor(0.6f, 0.8f, 0.7f, 0.7f);
    glClear(GL_COLOR_BUFFER_BIT);       // clear color buffer
    glutMouseFunc(onMouse);

    // register call-back function
    glutReshapeFunc(Reshape);
    glutDisplayFunc(display);

    // glut takes over - calling display() repeatedly
    glutMainLoop();
    return 0;
}