#include "cyan.h"
#include "mainwindow.h"

cyan::cyan(){
    pics[0].push_back(QPixmap(":/img/img/cyanu1"));
    pics[0].push_back(QPixmap(":/img/img/cyanu2"));
    pics[1].push_back(QPixmap(":/img/img/cyand1"));
    pics[1].push_back(QPixmap(":/img/img/cyand2"));
    pics[2].push_back(QPixmap(":/img/img/cyanl1"));
    pics[2].push_back(QPixmap(":/img/img/cyanl2"));
    pics[3].push_back(QPixmap(":/img/img/cyanr1"));
    pics[3].push_back(QPixmap(":/img/img/cyanr2"));
    pics[4].push_back(QPixmap(":/img/img/blue1"));
    pics[4].push_back(QPixmap(":/img/img/blue2"));
    pics[5].push_back(QPixmap(":/img/img/white1"));
    pics[5].push_back(QPixmap(":/img/img/white2"));
    setPixmap(pics[0][0].scaled(50, 50, Qt::KeepAspectRatio));
    setPos(322, 342);
    direction = 0;
    picsArg = 0;
}

void cyan::move(){
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
