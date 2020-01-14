//
// Created by yaodi on 2020/1/8.
//

class Painter{
private:
    Turtle *turtle;
public:
    Painter(Turtle *turtle) {
        this->turtle = turtle;
    };

    int DrawCircle(int val1, int val2, int val3){
        turtle->PenDown();
        return 1;
    }
};