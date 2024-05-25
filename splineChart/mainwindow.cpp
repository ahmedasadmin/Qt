#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSplineSeries* series = new QSplineSeries();
    series->append(0, 10);
    series->append(1, 4);
    series->append(2, 11);
    series->append(3, 13);
    series->append(4, 7);
    series->append(5, 3);
    series->append(6, 9);
    series->append(7, 1);
    series->append(8, 2);
    series->append(9, 10);
    series->append(10, 5);
    series->append(11, 12);
    series->append(12, 7);

    QChart* chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0,15);
    chart->axes(Qt::Horizontal).first()->setRange(0,12);
    chart->setVisible(true);

    QChartView *chartView= new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    setCentralWidget(chartView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

