#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::printDocument( QPrinter *printer )
{
    ui->graphicsView->render( printer );


//    QPainter painter;

//    painter.begin(printer);
//    painter.save();

//    int w = printer->pageRect().width();
//    int h = printer->pageRect().height();

//    painter.drawLine( 0, 0, w, h );

//    painter.restore();
//    painter.end();



    // 显示比例不对，修改如下
//    QPainter painter(printer);

//    QPixmap image;
//    image=image.grabWidget(AllView,0,0,400, 300);
//    QRect rect = painter.viewport();
//    QSize size = image.size();
//    size.scale(rect.size(), Qt::KeepAspectRatio);     //此处保证图片显示完整
//    painter.setViewport(rect.x(), rect.y(),size.width(), size.height());
//    painter.setWindow(image.rect());
//    painter.drawPixmap(0,0,image);

}

void MainWindow::on_pushButton_clicked()
{
//    QPrinter printer;

//    QPrintDialog printDialog( &printer, this);
//    if (printDialog.exec())
//    {
//        ui->graphicsView->render( &printer );
//    }


    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, this);

    connect(&preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT( printDocument( QPrinter* ) ) );

    preview.exec();

}
