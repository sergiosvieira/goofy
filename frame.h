#ifndef FRAME_H
#define FRAME_H

#include "Structs.h"

class Frame
{
public:
    Frame(int a_first, int a_last, int a_current, int a_width, int a_height, int a_cols);
    Coordinates current();
    void reset();
    void next();
    void previous();
    void updateFrame(int a_first, int a_last, int a_current);
private:
    int m_first, m_last, m_current, m_width, m_height, m_cols;
};

#endif // FRAME_H
