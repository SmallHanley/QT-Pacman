#include "pacman.h"
#include "mainwindow.h"

pacman::pacman(){
    pics[0].push_back(QPixmap(":/img/img/pacmanu1"));
    pics[0].push_back(QPixmap(":/img/img/pacmanu2"));
    pics[1].push_back(QPixmap(":/img/img/pacmand1"));
    pics[1].push_back(QPixmap(":/img/img/pacmand2"));
    pics[2].push_back(QPixmap(":/img/img/pacmanl1"));
    pics[2].push_back(QPixmap(":/img/img/pacmanl2"));
    pics[3].push_back(QPixmap(":/img/img/pacmanr1"));
    pics[3].push_back(QPixmap(":/img/img/pacmanr2"));
    setPixmap(pics[3][0].scaled(50, 50, Qt::KeepAspectRatio));
    direction = 3;
    keyDirection = 3;
    picsArg = 0;
}

void pacman::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up){
        keyDirection = 0;
        if(direction == 1){
            direction = 0;
        }
    }
    if(event->key() == Qt::Key_Down){
        keyDirection = 1;
        if(direction == 0){
            direction = 1;
        }
    }
    if(event->key() == Qt::Key_Left){
        keyDirection = 2;
        if(direction == 3){
            direction = 2;
        }
    }
    if(event->key() == Qt::Key_Right){
        keyDirection = 3;
        if(direction == 2){
            direction = 3;
        }
    }
}

void pacman::move(){
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
    if(canChange() && direction != keyDirection){
        direction = keyDirection;
        setPixmap(pics[direction][picsArg].scaled(50, 50, Qt::KeepAspectRatio));
    }
    if(isWall()){
        direction = 4;
        keyDirection = 4;
    }
    if(x() > 792){
        setPos(-40, 342);
    }
    if(x() < -40){
        setPos(792, 342);
    }
}

void pacman::changePics(){
    picsArg = picsArg * -1 + 1;
    if(direction < 4)
    setPixmap(pics[direction][picsArg].scaled(50, 50, Qt::KeepAspectRatio));
}

bool pacman::canChange(){
    if(keyDirection == 4)   return true;
    int i = 0, j = 0;
    bool checkX = false, checkY = false;
    if(x() == 10.0){
        i = 0;
        checkX = true;
    }
    if(x() == 74.0){
        i = 1;
        checkX = true;
    }
    if(x() == 170.0){
        i = 2;
        checkX = true;
    }
    if(x() == 252.0){
        i = 3;
        checkX = true;
    }
    if(x() == 334.0){
        i = 4;
        checkX = true;
    }
    if(x() == 418.0){
        i = 5;
        checkX = true;
    }
    if(x() == 500.0){
        i = 6;
        checkX = true;
    }
    if(x() == 584.0){
        i = 7;
        checkX = true;
    }
    if(x() == 678.0){
        i = 8;
        checkX = true;
    }
    if(x() == 740.0){
        i = 9;
        checkX = true;
    }
    if(y() == 8.0){
        j = 0;
        checkY = true;
    }
    if(y() == 110.0){
        j = 1;
        checkY = true;
    }
    if(y() == 194.0){
        j = 2;
        checkY = true;
    }
    if(y() == 272.0){
        j = 3;
        checkY = true;
    }
    if(y() == 342.0){
        j = 4;
        checkY = true;
    }
    if(y() == 416.0){
        j = 5;
        checkY = true;
    }
    if(y() == 492.0){
        j = 6;
        checkY = true;
    }
    if(y() == 576.0){
        j = 7;
        checkY = true;
    }
    if(y() == 660.0){
        j = 8;
        checkY = true;
    }
    if(y() == 742.0){
        j = 9;
        checkY = true;
    }
    if(checkX && checkY && mapDirection[i][j][keyDirection]){
        return true;
    }
    else{
        return false;
    }
}

bool pacman::isWall(){
    if(direction == 4)   return true;
    int i = 0, j = 0;
    bool checkX = false, checkY = false;
    if(x() == 10.0){
        i = 0;
        checkX = true;
    }
    if(x() == 74.0){
        i = 1;
        checkX = true;
    }
    if(x() == 170.0){
        i = 2;
        checkX = true;
    }
    if(x() == 252.0){
        i = 3;
        checkX = true;
    }
    if(x() == 334.0){
        i = 4;
        checkX = true;
    }
    if(x() == 418.0){
        i = 5;
        checkX = true;
    }
    if(x() == 500.0){
        i = 6;
        checkX = true;
    }
    if(x() == 584.0){
        i = 7;
        checkX = true;
    }
    if(x() == 678.0){
        i = 8;
        checkX = true;
    }
    if(x() == 740.0){
        i = 9;
        checkX = true;
    }
    if(y() == 8.0){
        j = 0;
        checkY = true;
    }
    if(y() == 110.0){
        j = 1;
        checkY = true;
    }
    if(y() == 194.0){
        j = 2;
        checkY = true;
    }
    if(y() == 272.0){
        j = 3;
        checkY = true;
    }
    if(y() == 342.0){
        j = 4;
        checkY = true;
    }
    if(y() == 416.0){
        j = 5;
        checkY = true;
    }
    if(y() == 492.0){
        j = 6;
        checkY = true;
    }
    if(y() == 576.0){
        j = 7;
        checkY = true;
    }
    if(y() == 660.0){
        j = 8;
        checkY = true;
    }
    if(y() == 742.0){
        j = 9;
        checkY = true;
    }
    if(checkX && checkY && !mapDirection[i][j][direction]){
        return true;
    }
    else{
        return false;
    }
}
