#include "orange.h"
#include "mainwindow.h"

orange::orange(){
    pics[0].push_back(QPixmap(":/img/img/orangeu1"));
    pics[0].push_back(QPixmap(":/img/img/orangeu2"));
    pics[1].push_back(QPixmap(":/img/img/oranged1"));
    pics[1].push_back(QPixmap(":/img/img/oranged2"));
    pics[2].push_back(QPixmap(":/img/img/orangel1"));
    pics[2].push_back(QPixmap(":/img/img/orangel2"));
    pics[3].push_back(QPixmap(":/img/img/oranger1"));
    pics[3].push_back(QPixmap(":/img/img/oranger2"));
    pics[4].push_back(QPixmap(":/img/img/blue1"));
    pics[4].push_back(QPixmap(":/img/img/blue2"));
    pics[5].push_back(QPixmap(":/img/img/white1"));
    pics[5].push_back(QPixmap(":/img/img/white2"));
    setPixmap(pics[0][0].scaled(50, 50, Qt::KeepAspectRatio));
    setPos(430, 342);
    direction = 0;
    picsArg = 0;
}

void orange::move(){
    direction = changeDirection();
    if(direction == 0){
        setPos(x(), y() - 2);
    }
    if(direction == 1){
        setPos(x(), y() + 2);
    }
    if(direction == 2){
        setPos(x() - 2, y());
    }
    if(direction == 3){
        setPos(x() + 2, y());
    }
    if(x() > 792){
        setPos(-40, 342);
    }
    if(x() < -40){
        setPos(792, 342);
    }
}
