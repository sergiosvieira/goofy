#include "goofy.h"
#include <QPixmap>

#include "frame.h"
#include "Structs.h"

static const Coordinates kAnimationFrames[] = {
    {1, 6}, /** up **/
    {8, 14}, /** down **/
    {16, 21}, /** right **/
    {23, 28} /** left **/
};

Goofy::Goofy(Position a_position, Size a_size, const char *a_filename) :
    Sprite(a_position, a_size, a_filename)
{
    int first = kAnimationFrames[LEFT].x;
    int last = kAnimationFrames[LEFT].y;

    m_frame = new Frame(first, last, first, m_size.width, m_size.height);
    m_lastDirection = RIGHT;
    m_moving = false;
}

Goofy::~Goofy()
{
    delete m_frame;
}

void Goofy::move(Direction a_direction)
{
    m_moving = true;
    float speed = 5.;
    m_position.x += a_direction == RIGHT ? speed : (a_direction == LEFT ? -speed : 0);
    m_position.y += a_direction == DOWN ? speed : (a_direction == UP ? -speed : 0);
}

void Goofy::moveFrame(Direction a_direction)
{
    int first = kAnimationFrames[a_direction].x;
    int last = kAnimationFrames[a_direction].y;

    m_frame->updateFrame(first, last, first);
    m_moving = true;
    m_lastDirection = a_direction;
}

void Goofy::stand()
{
    m_moving = false;
    int first = kAnimationFrames[m_lastDirection].x - 1;
    m_frame->updateFrame(first, first, first);
}

bool Goofy::isMoving()
{
    return m_moving;
}

Frame *Goofy::frame()
{
    return m_frame;
}
