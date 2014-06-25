#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QTimer>
#include "drawer.h"
#include "goofy.h"
#include "sprite.h"
#include "frame.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
    m_timer->start(0);
    ui->setupUi(this);

    /** initializing game objects **/
    m_painter = new QPainter(this);

    Position position = {0., 0.};
    Size size = {38., 38.};

    m_goofy = new Goofy(position, size, ":goofy.png");
}

MainWindow::~MainWindow()
{
    delete m_painter;
    delete m_goofy;
    delete m_timer;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    Drawer::draw(&painter, m_goofy, m_goofy->frame());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << tolower(event->key());
    switch (tolower(event->key()))
    {
        case 16777235:
            m_goofy->moveFrame(UP);
            m_goofy->move(UP);
            break;
        case 16777237:
            m_goofy->moveFrame(DOWN);
            m_goofy->move(DOWN);
            break;
        case 16777234:
            m_goofy->moveFrame(LEFT);
            m_goofy->move(LEFT);
            break;
        case 16777236:
            m_goofy->moveFrame(RIGHT);
            m_goofy->move(RIGHT);
            break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    m_goofy->stand();
}

void MainWindow::update()
{
    if (m_goofy->isMoving() == true)
    {
        m_goofy->frame()->next();
    }

    repaint();
}
