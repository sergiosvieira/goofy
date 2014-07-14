#include "goofy.h"
#include <QPixmap>

#include "frame.h"
#include "Structs.h"

static const Coordinates kAnimationFrames[] = {
    {36, 38}, /** up **/
    {0, 2}, /** down **/
    {24, 26}, /** right **/
    {12, 14} /** left **/
};

Goofy::Goofy(Position a_position, Size a_size, const char *a_filename) :
    Sprite(a_position, a_size, a_filename)
{
    Direction dir = RIGHT;
    int first = kAnimationFrames[dir].x;
    int last = kAnimationFrames[dir].y;

    m_frame = new Frame(first, last, first + 1, m_size.width, m_size.height, 12);
    m_lastDirection = dir;
    m_moving = false;
}

Goofy::~Goofy()
{
    delete m_frame;
}

void Goofy::move(Direction a_direction)
{
    float speed = 5.;

    m_position.x += a_direction == RIGHT ? speed : (a_direction == LEFT ? -speed : 0);
    m_position.y += a_direction == DOWN ? speed : (a_direction == UP ? -speed : 0);
    m_moving = true;
}

void Goofy::move()
{
    if (m_moving)
    {
        float speed = 3.5;

        m_position.x += m_direction == RIGHT ? speed : (m_direction == LEFT ? -speed : 0);
        m_position.y += m_direction == DOWN ? speed : (m_direction == UP ? -speed : 0);
    }
}

void Goofy::moveFrame(Direction a_direction)
{
    if (a_direction != m_lastDirection)
    {
        int first = kAnimationFrames[a_direction].x;
        int last = kAnimationFrames[a_direction].y;

        m_frame->updateFrame(first, last, first);
        m_lastDirection = a_direction;
    }

    this->frame()->next();
}

void Goofy::moveFrame()
{
    if (m_moving)
    {
        if (m_direction != m_lastDirection)
        {
            int first = kAnimationFrames[m_direction].x;
            int last = kAnimationFrames[m_direction].y;

            m_frame->updateFrame(first, last, first);
            m_lastDirection = m_direction;
        }

        this->frame()->next();
    }
}

void Goofy::stand()
{
    m_moving = false;

    int first = kAnimationFrames[m_lastDirection].x;
    int last = kAnimationFrames[m_lastDirection].y;

    m_frame->updateFrame(first, last, first + 1);
}

bool Goofy::isMoving()
{
    return m_moving;
}
Direction Goofy::direction() const
{
    return m_direction;
}

void Goofy::setDirection(const Direction &direction)
{
    m_moving = true;
    m_direction = direction;
}


Frame *Goofy::frame()
{
    return m_frame;
}
