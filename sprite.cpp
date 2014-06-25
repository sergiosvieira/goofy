#include "sprite.h"

#include <QPixmap>

Sprite::Sprite(Position a_position, Size a_size, const char *a_filename)
{
    /** set size and position **/
    m_position = a_position;
    m_size = a_size;

    /** load pixmap **/
    m_pixmap = new QPixmap(a_filename);
}

Sprite::Sprite(const char * a_filename)
{
    /** load pixmap **/
    m_pixmap = new QPixmap(a_filename);

    /** set size and position **/
    Size size = {
        m_pixmap->size().width(),
        m_pixmap->size().height()
    };
    Position position = {
      0,
      0
    };
    m_position = position;
    m_size = size;
}

Sprite::~Sprite()
{
    delete m_pixmap;
}

Position &Sprite::position()
{
    return m_position;
}

Size &Sprite::size()
{
    return m_size;
}

QPixmap &Sprite::pixmap()
{
    return *m_pixmap;
}
