#ifndef TOWER_H
#define TOWER_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
#include<TowerPosition.h>

class QPainter;
class Enemy;
class MainWindow;
class QTimer;

class Tower : QObject
{
    Q_OBJECT
public:
    Tower(QPoint centralpoint, MainWindow *ingame,  QPixmap tower,int range=50,int hurt=10,int attackfrequency=1000);
    ~Tower();

    void draw(QPainter *painter) const;
    void checkEnemy();//判断敌人是否在攻击范围内
    void targetEnemytoattack(Enemy *enemy);//选择敌人去攻击
    void attackEnemy();//攻击敌人
    void hurtEnemy();//当敌人受到伤害的时候
    void Enemydie();//当敌人死的时候
    void Enemyoutofrange();//敌人离开攻击范围
    void removeBullet();



private:
    const QPoint	_centralpoint;//塔的圆心
    MainWindow *	_ingame;//窗口
    const QPixmap	_tower;
    bool			_target;//判断敌人是否被选中
    int				_range;	// 攻击范围
    int				_hurt;//攻击敌人时造成的伤害
    int				_attackfrequency;// 攻击频率
    qreal			_rotation;

    Enemy *         _targetEnemy;//被选中的敌人

    QTimer *		_attackrateTimer;//计时器

    static const QSize fixedSize;
};

class lowTower:public Tower,public TowerPosition{
public:
    lowTower(QPoint beginpoint,QPoint centralpoint, MainWindow *ingame,  QPixmap tower = QPixmap(":pictures/tower.png/"),int range=50,int hurt=10,int attackfrequency=1000);
    ~lowTower();

private:
    QPoint          _beginpoint;
    const QPoint	_centralpoint;//塔的圆心
    MainWindow *	_ingame;//窗口
    const QPixmap	_tower;
    bool			_target;//判断敌人是否被选中
    int				_range;	// 攻击范围
    int				_hurt;//攻击敌人时造成的伤害
    int				_attackfrequency;// 攻击频率
    qreal			_rotation;

    Enemy *         _targetEnemy;//被选中的敌人

    QTimer *		_attackrateTimer;//计时器

};

class  middleTower:public Tower,public TowerPosition{
public:
    middleTower(QPoint beginpoint,QPoint centralpoint, MainWindow *ingame,  QPixmap tower = QPixmap(":pictures/tower.png/"),int range=80,int hurt=30,int attackfrequency=800);
    ~middleTower();

private:
    QPoint          _beginpoint;
    const QPoint	_centralpoint;//塔的圆心
    MainWindow *	_ingame;//窗口
    const QPixmap	_tower;
    bool			_target;//判断敌人是否被选中
    int				_range;	// 攻击范围
    int				_hurt;//攻击敌人时造成的伤害
    int				_attackfrequency;// 攻击频率
    qreal			_rotation;

    Enemy *         _targetEnemy;//被选中的敌人

    QTimer *		_attackrateTimer;//计时器
};

class highTower:public Tower,public TowerPosition{
public:
    highTower(QPoint beginpoint,QPoint centralpoint, MainWindow *ingame,  QPixmap tower = QPixmap(":pictures/tower.png/"),int range=100,int hurt=50,int attackfrequency=600);
    ~highTower();

private:
    QPoint          _beginpoint;
    const QPoint	_centralpoint;//塔的圆心
    MainWindow *	_ingame;//窗口
    const QPixmap	_tower;
    bool			_target;//判断敌人是否被选中
    int				_range;	// 攻击范围
    int				_hurt;//攻击敌人时造成的伤害
    int				_attackfrequency;// 攻击频率
    qreal			_rotation;

    Enemy *         _targetEnemy;//被选中的敌人

    QTimer *		_attackrateTimer;//计时器
};

#endif // TOWER_H
