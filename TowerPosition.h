#ifndef TOWERPOSITION_H
#define TOWERPOSITION_H
#include<QPoint>
#include<QPainter>
#include<QPixmap>
#include<vector>

class TowerPosition{
public:
    TowerPosition(QPoint beginpoint);
    QPoint centralPoint();//通过起点和中心点来确定位置
    QPoint beginPoint();
    bool includePoint(QPoint & point);//判断点击的位置是不是放置塔的位置
    bool haslowTower()const;//判断有没有塔
    bool hasmiddleTower()const;
    bool hashighTower()const;
    void setState1(bool hastower = true);//设置塔的状态
    void setState2(bool hastower = true);
    void setState3(bool hastower = true);

private:
    QPoint _beginpoint;//左上角起点
    bool _haslowtower;//判断位置是否有塔了
    bool _hasmiddletower;
    bool _hashightower;
    static const QSize _size;//塔位置大小

};


#endif // TOWERPOSITION_H
