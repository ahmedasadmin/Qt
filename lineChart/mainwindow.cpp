#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLineSeries *series = new QLineSeries();
    series->append(0,3);
    series->append(1,5);
    series->append(2,6);
    series->append(3,20);
    series->append(4,22);
    series->append(5,5);
    series->append(6,11);
    series->append(7,9);
    series->append(8,2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 25);
    chart->axes(Qt::Horizontal).first()->setRange(0, 12);
    chart->setVisible(true);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHints(QPainter::Antialiasing);
    chartView->setVisible(true);

    setCentralWidget(chartView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

