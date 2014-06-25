#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTimer;
class QPainter;
class Goofy;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    QPainter * m_painter;
    QTimer * m_timer;
    Goofy * m_goofy;
private slots:
    void update();
};

#endif // MAINWINDOW_H
