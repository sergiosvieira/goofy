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

static const int KEY_UP = 16777235;
static const int KEY_DOWN = 16777237;
static const int KEY_LEFT = 16777234;
static const int KEY_RIGHT = 16777236;

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
    Size size = {48., 64.};

    m_goofy = new Goofy(position, size, ":sprites.png");
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
    Direction dir = RIGHT;

    switch (tolower(event->key()))
    {
        case KEY_UP:
            dir = UP;
            break;
        case KEY_DOWN:
            dir = DOWN;
            break;
        case KEY_LEFT:
            dir = LEFT;
            break;
        case KEY_RIGHT:
            dir = RIGHT;
            break;
    }

    m_goofy->moveFrame(dir);
    m_goofy->move(dir);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    m_goofy->stand();
}

void MainWindow::update()
{
    repaint();
}
