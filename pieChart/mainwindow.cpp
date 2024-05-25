#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPieSeries *series = new QPieSeries();
    series->append("English", 40);
    series->append("Maths", 40);
    series->append("Science", 20);
    series->append("Geograpgy", 50);
    series->append("Physics", 40);


     QPieSlice *slice_1 = series->slices().at(0);
     slice_1->setExploded(true);
     slice_1->setLabelVisible(true);
     slice_1->setPen(QPen(Qt::red, 1));
     slice_1->setBrush(Qt::red);

     QPieSlice *slice_2 = series->slices().at(1);
     slice_2->setExploded(true);
     slice_2->setLabelVisible(true);
     slice_2->setPen(QPen(Qt::blue, 1));
     slice_2->setBrush(Qt::blue);

     QPieSlice *slice_3 = series->slices().at(2);
     slice_3->setExploded(true);
     slice_3->setLabelVisible(true);
     slice_3->setPen(QPen(Qt::green, 1));
     slice_3->setBrush(Qt::green);

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Student Marks");
    chart->setVisible(true);


    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);

    setCentralWidget(chartView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

