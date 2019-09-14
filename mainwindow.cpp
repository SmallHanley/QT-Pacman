#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Win->setVisible(false);
    ui->Lose->setVisible(false);
    scene = new QGraphicsScene(0, 0, ui->graphicsView->width() - 2, ui->graphicsView->height() - 2);
    scene->addPixmap(QPixmap(":/img/img/background"));
    ui->graphicsView->setScene(scene);
    for(int i = 0; i < 29; i++){
        for(int j = 0; j < 26; j++){
            Smallpoint[i][j] = new smallpoint(18 + j * 28.5, 8 + i * 26.1, i, j);
            scene->addItem(Smallpoint[i][j]);
        }
    }
    smallpointNum = 0;
    Bigpoint[0] = new bigpoint();
    Bigpoint[0]->setPos(18, 60.2);
    scene->addItem(Bigpoint[0]);
    Bigpoint[1] = new bigpoint();
    Bigpoint[1]->setPos(730.5, 60.2);
    scene->addItem(Bigpoint[1]);
    Bigpoint[2] = new bigpoint();
    Bigpoint[2]->setPos(18, 582.2);
    scene->addItem(Bigpoint[2]);
    Bigpoint[3] = new bigpoint();
    Bigpoint[3]->setPos(730.5, 582.2);
    scene->addItem(Bigpoint[3]);
    bigpointNum = 0;
    Pacman = new pacman();
    Pacman->setPos(376, 576);
    Pacman->setFlag(QGraphicsItem::ItemIsFocusable);
    Pacman->setFocus();
    scene->addItem(Pacman);
    ghost1 = new red();
    scene->addItem(ghost1);
    ghost2 = new pink();
    scene->addItem(ghost2);
    ghost3 = new cyan();
    scene->addItem(ghost3);
    ghost4 = new orange();
    scene->addItem(ghost4);
    point = new QLabel(this);
    point->setGeometry(0, 0, 49, 17);
    point->setFont(QFont("Ubuntu Regular", 14));
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::darkGreen);
    point->setPalette(pa);
    point->setVisible(false);
    Cherry = new cherry();
    scene->addItem(Cherry);
    srandom(time(NULL));
    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(allMove()));
    timer1->start(13);
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(allChangePics()));
    timer2->start(100);
    timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), this, SLOT(bigpointChangePics()));
    timer3->start(200);
    modeRed = modePink = modeCyan = modeOrange = 0;
    addpoint = 200;
    pause = false;
    isBonus2 = false;
    timer8 = new QTimer(this);
    timer8->setSingleShot(true);
    connect(timer8, SIGNAL(timeout()), this, SLOT(pauseTime()));
    timer8->start(2000);
    timer9 = new QTimer(this);
    connect(timer9, SIGNAL(timeout()), this, SLOT(slowMove()));
    timer9->start(26);
    timer10 = new QTimer(this);
    timer10->setSingleShot(true);
    connect(timer10, SIGNAL(timeout()), this, SLOT(cyanStartSlot()));
    timer10->start(7000);
    timer11 = new QTimer(this);
    timer11->setSingleShot(true);
    connect(timer11, SIGNAL(timeout()), this, SLOT(orangeStartSlot()));
    timer11->start(17000);
    timer12 = new QTimer(this);
    connect(timer12, SIGNAL(timeout()), this, SLOT(cherrySetVisibleTrue()));
    timer12->start(60000);
    pause = true;
    slowRed = false;
    slowPink = slowCyan = slowOrange = true;
}

void MainWindow::allMove(){
    if(!pause){
        Pacman->move();
        if(modeRed == 0 && !slowRed)
            ghost1->move();
        if(modePink == 0 && !slowPink)
            ghost2->move();
        if(modeCyan == 0 && !slowCyan)
            ghost3->move();
        if(modeOrange == 0 && !slowOrange)
            ghost4->move();
        for(int i = 0; i < 29; i++){
            for(int j = 0; j < 26; j++){
                bool isCollided = Pacman->collidesWithItem(Smallpoint[i][j]);
                if(isCollided){
                    Smallpoint[i][j]->collide();
                    ui->lcdNumber->display(ui->lcdNumber->value() + 10);
                    smallpointNum++;
                }
            }
        }
        for(int i = 0; i < 4; i++){
            bool isCollided = Pacman->collidesWithItem(Bigpoint[i]);
            if(isCollided){
                if(!q.empty()){
                    int temp = q.front();
                    q.pop_front();
                    delete timer4[temp];
                    delete timer5[temp];
                    delete timer6[temp];
                    delete timer7[temp];
                    addpoint = 200;
                    isBonus2 = false;
                }
                Bigpoint[i]->collide();
                ui->lcdNumber->display(ui->lcdNumber->value() + 50);
                modeRed = modePink = modeCyan = modeOrange = 1;
                timer4[i] = new QTimer(this);
                timer4[i]->setSingleShot(true);
                connect(timer4[i], SIGNAL(timeout()), this, SLOT(bonusTime()));
                timer5[i] = new QTimer(this);
                timer5[i]->setSingleShot(true);
                connect(timer5[i], SIGNAL(timeout()), this, SLOT(bonusTime2()));
                timer6[i] = new QTimer(this);
                connect(timer6[i], SIGNAL(timeout()), this, SLOT(flicker()));
                timer7[i] = new QTimer(this);
                connect(timer7[i], SIGNAL(timeout()), this, SLOT(ghostmove2()));
                timer4[i]->start(9000);
                timer5[i]->start(6500);
                timer6[i]->start(200);
                timer7[i]->start(20);
                q.push_back(i);
                bigpointNum++;
            }
        }
        bool isCollided1 = Pacman->collidesWithItem(ghost1);
        bool isCollided2 = Pacman->collidesWithItem(ghost2);
        bool isCollided3 = Pacman->collidesWithItem(ghost3);
        bool isCollided4 = Pacman->collidesWithItem(ghost4);
        if((isCollided1 && !modeRed) || (isCollided2 && !modePink) || (isCollided3 && !modeCyan) || (isCollided4 && !modeOrange)){
            pause = true;
            ui->Lose->setVisible(true);
        }
        if(isCollided1 && modeRed){
            modeRed = 0;
            point->setText(QString::number(addpoint));
            point->setGeometry(ghost1->x(), ghost1->y() + 30, 49, 17);
            point->setVisible(true);
            ui->lcdNumber->display(ui->lcdNumber->value() + addpoint);
            pause = true;
            timer8 = new QTimer(this);
            timer8->setSingleShot(true);
            connect(timer8, SIGNAL(timeout()), this, SLOT(getPointTime()));
            timer8->start(1000);
            ghost1->setPos(376, 342);
            ghost1->setDirection(0);
            slowRed = true;
            addpoint *= 2;
        }
        if(isCollided2 && modePink){
            modePink = 0;
            point->setText(QString::number(addpoint));
            point->setGeometry(ghost2->x(), ghost2->y() + 30, 49, 17);
            point->setVisible(true);
            ui->lcdNumber->display(ui->lcdNumber->value() + addpoint);
            pause = true;
            timer8 = new QTimer(this);
            timer8->setSingleShot(true);
            connect(timer8, SIGNAL(timeout()), this, SLOT(getPointTime()));
            timer8->start(1000);
            ghost2->setPos(376, 342);
            ghost2->setDirection(0);
            slowPink = true;
            addpoint *= 2;
        }
        if(isCollided3 && modeCyan){
            modeCyan = 0;
            point->setText(QString::number(addpoint));
            point->setGeometry(ghost3->x(), ghost3->y() + 30, 49, 17);
            point->setVisible(true);
            ui->lcdNumber->display(ui->lcdNumber->value() + addpoint);
            pause = true;
            timer8 = new QTimer(this);
            timer8->setSingleShot(true);
            connect(timer8, SIGNAL(timeout()), this, SLOT(getPointTime()));
            timer8->start(1000);
            ghost3->setPos(376, 342);
            ghost3->setDirection(0);
            slowCyan = true;
            addpoint *= 2;
        }
        if(isCollided4 && modeOrange){
            modeOrange = 0;
            point->setText(QString::number(addpoint));
            point->setGeometry(ghost4->x(), ghost4->y() + 30, 49, 17);
            point->setVisible(true);
            ui->lcdNumber->display(ui->lcdNumber->value() + addpoint);
            pause = true;
            timer8 = new QTimer(this);
            timer8->setSingleShot(true);
            connect(timer8, SIGNAL(timeout()), this, SLOT(getPointTime()));
            timer8->start(1000);
            ghost4->setPos(376, 342);
            ghost4->setDirection(0);
            slowOrange = true;
            addpoint *= 2;
        }
        bool isCollided = Pacman->collidesWithItem(Cherry);
        if(isCollided){
            Cherry->changePics(1);
            ui->lcdNumber->display(ui->lcdNumber->value() + 100);
        }
        if(smallpointNum == 242 && bigpointNum == 4){
            pause = true;
            ui->Win->setVisible(true);
        }
    }
}

void MainWindow::allChangePics(){
    if(!pause){
        Pacman->changePics();
        if(modeRed == 0){
            ghost1->changePics();
        }
        else if(modeRed == 1){
            ghost1->changePics2();
        }
        else if(modeRed == 2){
            ghost1->changePics3();
        }
        if(modePink == 0){
            ghost2->changePics();
        }
        else if(modePink == 1){
            ghost2->changePics2();
        }
        else if(modePink == 2){
            ghost2->changePics3();
        }
        if(modeCyan == 0){
            ghost3->changePics();
        }
        else if(modeCyan == 1){
            ghost3->changePics2();
        }
        else if(modeCyan == 2){
            ghost3->changePics3();
        }
        if(modeOrange == 0){
            ghost4->changePics();
        }
        else if(modeOrange == 1){
            ghost4->changePics2();
        }
        else if(modeOrange == 2){
            ghost4->changePics3();
        }
    }
}

void MainWindow::bigpointChangePics(){
    if(!pause){
        Bigpoint[0]->changePics();
        Bigpoint[1]->changePics();
        Bigpoint[2]->changePics();
        Bigpoint[3]->changePics();
    }
}

void MainWindow::bonusTime(){
    int i = q.front();
    q.pop_front();
    modeRed = modePink = modeCyan = modeOrange = 0;
    isBonus2 = false;
    addpoint = 200;
    delete timer4[i];
    delete timer5[i];
    delete timer6[i];
    delete timer7[i];
}

void MainWindow::bonusTime2(){
    isBonus2 = true;
}

void MainWindow::flicker(){
    if(!pause){
        if(isBonus2){
            if(modeRed == 1){
                modeRed = 2;
            }
            else if(modeRed == 2){
                modeRed = 1;
            }
            if(modePink == 1){
                modePink = 2;
            }
            else if(modePink == 2){
                modePink = 1;
            }
            if(modeCyan == 1){
                modeCyan = 2;
            }
            else if(modeCyan == 2){
                modeCyan = 1;
            }
            if(modeOrange == 1){
                modeOrange = 2;
            }
            else if(modeOrange == 2){
                modeOrange = 1;
            }
        }
    }
}

void MainWindow::ghostmove2(){
    if(!pause){
        if((modeRed == 1 || modeRed == 2) && !slowRed)
            ghost1->move();
        if((modePink == 1 || modePink == 2) && !slowPink)
            ghost2->move();
        if((modeCyan == 1 || modeCyan == 2) && !slowCyan)
            ghost3->move();
        if((modeOrange == 1 || modeOrange == 2) && !slowOrange)
            ghost4->move();
    }
}

void MainWindow::getPointTime(){
    delete timer8;
    point->setVisible(false);
    pause = false;
}

void MainWindow::pauseTime(){
    delete timer8;
    ui->ready->setVisible(false);
    pause = false;
}

void MainWindow::slowMove(){
    if(!pause){
        if(slowRed)
            ghost1->move();
        if(slowPink)
            ghost2->move();
        if(slowCyan)
            ghost3->move();
        if(slowOrange)
            ghost4->move();
    }
    if(ghost1->x() == 376.0 && ghost1->y() == 272.0){
        slowRed = false;
    }
    if(ghost2->x() == 376.0 && ghost2->y() == 272.0){
        slowPink = false;
    }
    if(ghost3->x() == 376.0 && ghost3->y() == 272.0){
        slowCyan = false;
    }
    if(ghost4->x() == 376.0 && ghost4->y() == 272.0){
        slowOrange = false;
    }
}

void MainWindow::cyanStartSlot(){
    delete timer10;
    ghost3->setCyanStart();
}

void MainWindow::orangeStartSlot(){
    delete timer11;
    ghost4->setOrangeStart();
}

void MainWindow::cherrySetVisibleTrue(){
    Cherry->changePics(0);
    timer13 = new QTimer(this);
    timer13->setSingleShot(true);
    connect(timer13, SIGNAL(timeout()), this, SLOT(cherrySetVisibleFalse()));
    timer13->start(10000);
}

void MainWindow::cherrySetVisibleFalse(){
    Cherry->changePics(1);
    delete timer13;
}

MainWindow::~MainWindow()
{
    delete ui;
}
