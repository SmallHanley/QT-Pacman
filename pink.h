#ifndef PINK_H
#define PINK_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <ghost.h>

class pink : public ghost
{
public:
    pink();
    virtual void move();

};
#endif // PINK_H
