#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QList>
#include<QPaintEvent>
#include<TowerPosition.h>
#include<Tower.h>
#include<QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);


private:
    int _Gold;
private:
    void loadTowerPosition();
    bool enoughGold()const;

private:
    Ui::MainWindow *ui;
    //设置List数组以便后续直接引用
    QList<TowerPosition> _TowerPositionList;
    QList<Tower *> _TowerList;
};
#endif // MAINWINDOW_H
