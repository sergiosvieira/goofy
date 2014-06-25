#ifndef DRAWER_H
#define DRAWER_H

class Sprite;
class Frame;
class QPainter;

class Drawer
{
public:
    static void draw(QPainter * a_painter, Sprite * a_sprite, Frame * a_frame);
};

#endif // DRAWER_H
