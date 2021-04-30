#ifndef __MOTION_H_
#define __MOTION_H_

class Motion
{
public:
    Motion(){}
    virtual ~Motion(){}

private:
    bool Forward = false;
    bool Backward = false;
    bool Left = false;
    bool Right = false;
    bool Accelerator = false;

public:
    void setMotionForward(bool val) { Forward = val; };
    bool getMotionForward() { return Forward; };

    void setMotionBackward(bool val) { Backward = val; };
    bool getMotionBackward() { return Backward; };

    void setMotionLeft(bool val) { Left = val; };
    bool getMotionLeft() { return Left; };

    void setMotionRight(bool val) { Right = val; };
    bool getMotionRight() { return Right; };

    void setMotionAccelerator(bool val) { Accelerator = val; };
    bool getMotionAccelerator() { return Accelerator; };
};


#endif