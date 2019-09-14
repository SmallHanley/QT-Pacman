#ifndef CHERRY_H
#define CHERRY_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <cstdlib>

class cherry : public QGraphicsPixmapItem
{
public:
    cherry();
    void changePics(int i);

private:
    QList<QPixmap> pics;

};

#endif // CHERRY_H
