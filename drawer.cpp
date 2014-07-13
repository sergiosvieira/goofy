#include "drawer.h"

#include <QPainter>
#include "sprite.h"
#include "frame.h"
#include "Structs.h"

void Drawer::draw(QPainter *a_painter, Sprite *a_sprite, Frame *a_frame)
{
    Position position = a_sprite->position();
    Size size = a_sprite->size();
    Coordinates coordinates= a_frame->current();

    a_painter->drawPixmap(position.x, position.y, a_sprite->pixmap(), coordinates.x, coordinates.y, size.width, size.height);
}
