#ifndef RED_H
#define RED_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <ghost.h>

class red : public ghost
{
public:
    red();
    virtual void move();

};
#endif // RED_H
