#include "frame.h"


Coordinates Frame::current()
{
    int sx = (m_current % m_cols) * m_width;
    int sy = (m_current / m_cols) * m_height;
    Coordinates result = {sx, sy};

    return result;
}

Frame::Frame(int a_first, int a_last, int a_current, int a_width, int a_height, int a_cols)
{
    m_first = a_first;
    m_last = a_last;
    m_current = a_current;
    m_width = a_width;
    m_height = a_height;
    m_cols = a_cols;
}

void Frame::reset()
{
    m_current = m_first;
}

void Frame::next()
{
    m_current = m_current + 1 > m_last ? m_first : m_current + 1;
}

void Frame::previous()
{
    m_current = m_current - 1 < m_first ? m_last : m_current - 1;
}

void Frame::updateFrame(int a_first, int a_last, int a_current)
{
    m_first = a_first;
    m_last = a_last;
    m_current = a_current;
}
