#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
protected:
    double m_X;
    double m_Y;
public:
    Shape();
    virtual void print() = 0;
};

#endif // SHAPE_H
