#ifndef HEX_H
#define HEX_H

enum Color {Blue, Red, Black};

struct Hexagon{
    // constructor
    Hexagon(double x_, double y_, int turn_){
        x = x_;
        y = y_;
        turn = turn_;
    }
    double x,y;
    int turn;
    bool left_clicked;
    Color color;
};

class Grid{
public:


private:
    int width = 400;
    int height = 400;
};

#endif