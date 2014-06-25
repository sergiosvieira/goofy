#ifndef GOOFY_H
#define GOOFY_H

#include "sprite.h"
#include "Structs.h"

class QPixmap;
class Frame;

class Goofy : public Sprite
{
public:
    Goofy(Position a_position, Size a_size, const char *a_filename);
    ~Goofy();
    void move(Direction a_direction);
    Frame *frame();
    void moveFrame(Direction a_direction);
    void stand();
    bool isMoving();
private:
    Frame *m_frame;
    Direction m_lastDirection;
    bool m_moving;
};

#endif // GOOFY_H
