#include<TowerPosition.h>
#include<QPainter>
#include<QPoint>
#include<QPixmap>
using namespace std;


const QSize TowerPosition::_size(50,50);//宽50，高50

TowerPosition::TowerPosition(QPoint beginpoint)
    :_beginpoint(beginpoint),
      _haslowtower(false),
      _hasmiddletower(false),
      _hashightower(false)
{
}

QPoint TowerPosition::beginPoint(){
    return _beginpoint;
}

QPoint TowerPosition::centralPoint(){
    QPoint centralpoint(_size.width()/2,_size.height()/2);//中心点的位置
    return _beginpoint+centralpoint;//QPoint可以重载“+”，这里相当于centralpoint的坐标
}

bool TowerPosition::includePoint(QPoint &point){
    //判断点是否落在塔的位置里面
    bool x = false,y = false;
    if(_beginpoint.x()<point.x()&&point.x()<_size.width())x=true;
    if(_beginpoint.y()<point.y()&&point.y()<_size.height())y=true;
    return (x&&y);
}

bool TowerPosition::haslowTower()const{
    return _haslowtower;
}

bool TowerPosition::hasmiddleTower()const{
    return _hasmiddletower;
}

bool TowerPosition::hashighTower()const{
    return _hashightower;
}

void TowerPosition::setState1(bool hastower/* =true */){
    _haslowtower = hastower;
}
void TowerPosition::setState2(bool hastower/* =true */){
    _hasmiddletower = hastower;
}
void TowerPosition::setState3(bool hastower/* =true */){
    _hasmiddletower = hastower;
}


