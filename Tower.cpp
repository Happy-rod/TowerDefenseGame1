#include "Tower.h"
#include "mainwindow.h"
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QVector2D>
#include <QtMath>
#include<QDebug>
const QSize Tower::fixedSize(50, 50);


Tower::Tower(QPoint centralpoint, MainWindow *ingame,  QPixmap tower,int range,int hurt,int attackfrequency)
            :_centralpoint(centralpoint),
              _ingame(ingame),
              _tower(tower),
              _target(false),
              _range(range),
              _hurt(hurt),
              _attackfrequency(attackfrequency),
              _rotation(0.0),
              _targetEnemy(NULL){

}

Tower::~Tower(){

}

void Tower::draw(QPainter *painter) const{
    painter -> save();//保存坐标系现在的状态
    painter->setPen(Qt::white);//定义白色来描绘线
    painter->drawEllipse(_centralpoint,_range,_range);//画出攻击范围（圆）

    //偏移点,保证偏移点+塔的圆心=初始点
    static const QPoint offsetPoint(-fixedSize.width()/2,-fixedSize.height()/2);
    painter ->translate(_centralpoint);//塔的圆心作为中心
    painter ->drawPixmap(offsetPoint,_tower);
    painter ->restore();//恢复以前坐标系的状态
}

void Tower::checkEnemy(){

}

lowTower::lowTower(QPoint beginpoint,QPoint centralpoint, MainWindow *ingame,  QPixmap tower,int range,int hurt,int attackfrequency)
    :Tower(centralpoint,ingame,tower,range,hurt,attackfrequency),
      TowerPosition(beginpoint),
      _beginpoint(beginpoint),
      _centralpoint(centralpoint),
      _ingame(ingame),
      _tower(tower),
      _target(false),
      _range(range),
      _hurt(hurt),
      _attackfrequency(attackfrequency),
      _rotation(0.0),
      _targetEnemy(NULL){

}


lowTower::~lowTower(){

}


middleTower::middleTower(QPoint beginpoint,QPoint centralpoint, MainWindow *ingame,  QPixmap tower,int range,int hurt,int attackfrequency)
    :Tower(centralpoint,ingame,tower,range,hurt,attackfrequency),
     TowerPosition(beginpoint),
     _beginpoint(beginpoint),
     _centralpoint(centralpoint),
     _ingame(ingame),
     _tower(tower),
     _target(false),
     _range(range),
     _hurt(hurt),
     _attackfrequency(attackfrequency),
     _rotation(0.0),
     _targetEnemy(NULL){}

middleTower::~middleTower(){

}

highTower::highTower(QPoint beginpoint,QPoint centralpoint, MainWindow *ingame,  QPixmap tower,int range,int hurt,int attackfrequency)
    :Tower(centralpoint,ingame,tower,range,hurt,attackfrequency),
    TowerPosition(beginpoint),
    _beginpoint(beginpoint),
    _centralpoint(centralpoint),
    _ingame(ingame),
    _tower(tower),
    _target(false),
    _range(range),
    _hurt(hurt),
    _attackfrequency(attackfrequency),
    _rotation(0.0),
    _targetEnemy(NULL){}


highTower::~highTower(){

}
