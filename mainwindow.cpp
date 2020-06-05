#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QPixmap>
#include<QPaintEvent>
#include<qevent.h>
#include<Tower.h>
#include<TowerPosition.h>
#include<QMouseEvent>
#include<QPainter>
#include<iostream>
using namespace std;

static const int lowTowerCost = 300;
static const int middleTowerCost = 200;//相当于500， = 300+200
static const int highTowerCost = 200;//相当于700， = 300+200+200


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,_Gold(1000)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap map("pictures/map1.png");

    QPainter anotherPainter(&map);


    painter.drawPixmap(0,0,this ->width(),this ->height(),map);

}

void MainWindow::loadTowerPosition(){
    QPoint towerpoint[]={
        QPoint(1688,910),
        QPoint(1459,914),
        QPoint(1536,682),
        QPoint(1305,685),
        QPoint(1533,529),
        QPoint(1308,300),
        QPoint(1305,453),
        QPoint(1070,453),
        QPoint(1075,762)
    };

    int length = sizeof(towerpoint)/sizeof(towerpoint[0]);

    for(int i=0; i<length; i++){
        _TowerPositionList.push_back(towerpoint[i]);
    }

}

void MainWindow::mousePressEvent(QMouseEvent *event){
    QPoint presspoint = event -> pos();//pos()，相对于窗口，以窗口左上角为原点（去除边框）
    int x = event -> globalX();
    int y = event -> globalY();
    cout<<x<<" "<<y<<endl;
    auto p = _TowerPositionList.begin();
    while(p != _TowerPositionList.end()){
        if(enoughGold()&& p-> includePoint(presspoint)&& !p ->haslowTower()){
            p->setState1();
            lowTower *tower = new lowTower(p ->beginPoint(),p ->centralPoint(),this);
            _TowerList.push_back(tower);
            update();
            break;
        }
        else if(enoughGold()&& p-> includePoint(presspoint)&& !p ->hasmiddleTower()){
            p->setState2();
            middleTower *tower = new middleTower(p ->beginPoint(),p ->centralPoint(),this);
            _TowerList.push_back(tower);
            update();
            break;
        }
        else if(enoughGold()&& p-> includePoint(presspoint)&& !p ->hashighTower()){
            p->setState3();
            highTower *tower = new highTower(p ->beginPoint(),p ->centralPoint(),this);
            _TowerList.push_back(tower);
            update();
            break;
        }

        p++;
    }
}

bool MainWindow::enoughGold() const
{
    auto p =_TowerPositionList.begin();
    while(p != _TowerPositionList.end()){
        if(_Gold >= lowTowerCost&& ! p->haslowTower())
            return true;
        if(_Gold >= middleTowerCost&& !p ->hasmiddleTower()&&p ->haslowTower())
            return true;
        if(_Gold >= highTowerCost&& !p ->hashighTower()&&p->haslowTower()&&p->hasmiddleTower())
            return true;
    }

    return false;
}
