#ifndef BIGPOINT_H
#define BIGPOINT_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>

class bigpoint : public QGraphicsPixmapItem
{
public:
    bigpoint();
    void collide();
    void changePics();

private:
    bool isEaten;
    QList<QPixmap> pics;
    int picsArg;
};
#endif // BIGPOINT_H
