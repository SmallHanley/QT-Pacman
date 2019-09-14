#include "ghost.h"
#include "mainwindow.h"


ghost::ghost(){
    cyanStart = false;
    orangeStart = false;
}

void ghost::move(){

}

int ghost::changeDirection(){
    int i = 0, j = 0, tempDirect;
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
    if(x() == 376.0 && y() == 272.0){
        tempDirect = random() % 2 + 2;
        return tempDirect;
    }
    if(x() == 322.0 && y() == 330.0){
        return 1;
    }
    if(x() == 322.0 && y() == 354.0){
        return 0;
    }
    if(x() == 430.0 && y() == 330.0){
        return 1;
    }
    if(x() == 430.0 && y() == 354.0){
        return 0;
    }
    if(x() == 322.0 && y() == 342.0 && cyanStart){
        return 3;
    }
    if(x() == 430.0 && y() == 342.0 && orangeStart){
        return 2;
    }
    if(x() == 376.0 && y() == 342.0){
        return 0;
    }
    if(checkX && checkY){
        tempDirect = random() % 4;
        if(mapDirection[i][j][tempDirect] && intersection[i][j]){
            return tempDirect;
        }
        else if(!mapDirection[i][j][tempDirect] && intersection[i][j]){
            return 4;
        }
        else{
            return direction;
        }
    }
    else{
        return direction;
    }
}

void ghost::changePics(){
    picsArg = picsArg * -1 + 1;
    if(direction < 4 )
    setPixmap(pics[direction][picsArg].scaled(50, 50, Qt::KeepAspectRatio));
}

void ghost::changePics2(){
    picsArg = picsArg * -1 + 1;
    setPixmap(pics[4][picsArg].scaled(50, 50, Qt::KeepAspectRatio));
}

void ghost::changePics3(){
    picsArg = picsArg * -1 + 1;
    setPixmap(pics[5][picsArg].scaled(50, 50, Qt::KeepAspectRatio));
}

void ghost::setDirection(int d){
    direction = d;
}

void ghost::setCyanStart(){
    cyanStart = true;
}

void ghost::setOrangeStart(){
    orangeStart = true;
}
