#include "cherry.h"
#include "mainwindow.h"

cherry::cherry()
{
    pics.push_back(QPixmap(":/img/img/cherry"));
    pics.push_back(QPixmap(":/img/img/transparent"));
    setPixmap(pics[1].scaled(50, 50, Qt::KeepAspectRatio));
    setPos(376, 416);
}

void cherry::changePics(int i){
    setPixmap(pics[i].scaled(50, 50, Qt::KeepAspectRatio));
}
