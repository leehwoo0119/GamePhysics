#ifndef MOTION
#define MOTION

class Motion
{
private:
    bool Forward = false;
    bool Backward = false;
    bool Left = false;
    bool Right = false;
public:
    void setMotionForward(bool val) { Forward = val; };
    bool getMotionForward() { return Forward; };
    void setMotionBackward(bool val) { Backward = val; };
    bool getMotionBackward() { return Backward; };
    void setMotionLeft(bool val) { Left = val; };
    bool getMotionLeft() { return Left; };
    void setMotionRight(bool val) { Right = val; };
    bool getMotionRight() { return Right; };
};


#endif