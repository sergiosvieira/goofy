#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
#include "drawer.h"
#include "goofy.h"
#include "sprite.h"
#include "frame.h"

static const int KEY_UP = 16777235;
static const int KEY_DOWN = 16777237;
static const int KEY_LEFT = 16777234;
static const int KEY_RIGHT = 16777236;
const int TICKS_PER_SECOND = 50;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 10;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_tickTime = new QTime();
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
    m_timer->start(0);
    ui->setupUi(this);

    /** initializing game objects **/
    m_painter = new QPainter(this);

    Position position = {0., 0.};
    Size size = {48., 64.};

    m_goofy = new Goofy(position, size, ":sprites.png");
    m_tickTime->start();
    m_nextGameTick = m_tickTime->elapsed();
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
    static int loops = 0;

    while( m_tickTime->elapsed() > m_nextGameTick && loops < MAX_FRAMESKIP)
    {
        m_goofy->moveFrame();
        m_goofy->move();
        m_nextGameTick += SKIP_TICKS;
        loops++;
    }

    loops = 0;

    QPainter painter(this);

    //m_goofy->stand();

    Drawer::draw(&painter, m_goofy, m_goofy->frame());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
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

    m_goofy->setDirection(dir);
    repaint();
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    m_goofy->stand();
}

void MainWindow::update()
{
    repaint();
}
