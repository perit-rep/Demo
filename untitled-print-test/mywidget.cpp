#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter( this );

    painter.drawText( 100, 100, "asdfsaf" );

    painter.drawLine( 100, 100, 200, 200 );

    QWidget::paintEvent(event);


}
