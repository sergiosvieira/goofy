#ifndef SPRITE_H
#define SPRITE_H

#include "Structs.h"

class QPixmap;

class Sprite
{
public:
    Sprite(Position a_position, Size a_size, const char * a_filename);
    Sprite(const char * a_filename);
    ~Sprite();
    Position &position();
    Size &size();
    QPixmap &pixmap();
protected:
    Position m_position;
    Size m_size;
    QPixmap * m_pixmap;
};

#endif // SPRITE_H
