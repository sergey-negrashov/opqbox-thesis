#include "plotter.h"
#include "ui_plotter.h"
#include <qdebug.h>
#include <QtAlgorithms>
#include <QDateTime>
#include <QFileDialog>
Plotter::Plotter(QString file, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Plotter)
{
    ui->setupUi(this);
    setWindowTitle(file);
    plot = new QwtPlot();
    ui->horizontalLayout->addWidget(plot);
    curveV = new QwtPlotCurve("Voltage");
    curveF = new QwtPlotCurve("Frequency");
    curveV->attach(plot);
    curveF->attach(plot);
    file_ = new QFile(file);
    file_->open(QIODevice::ReadOnly);
    QString line;
    while((line = QString(file_->readLine())) != "")
    {
        QStringList chunks = line.split(',');
        Reading r;
        r.timestamp = chunks.at(0).toLongLong();
        r.frequency = chunks.at(1).toFloat();
        r.voltage = chunks.at(2).toFloat();
        if(r.frequency > 59 && r.voltage > 80 && r.frequency < 61 && r.voltage < 140)
            readingVector_.push_back(r);
    }
    qSort(readingVector_);
    ui->rangeMax->setMinimum(0);
    ui->rangeMax->setMaximum(readingVector_.size() - 1);
    ui->rangeMax->setValue(readingVector_.size() -1 );

    ui->rangeMin->setMinimum(0);
    ui->rangeMin->setMaximum(readingVector_.size() -1);

    QDateTime timestamp;
    timestamp.setTime_t(readingVector_.at(0).timestamp/1000);
    ui->min_label->setText("Min " + timestamp.toString(Qt::SystemLocaleShortDate));

    timestamp.setTime_t(readingVector_.at(readingVector_.size() - 1 ).timestamp/1000);
    ui->max_label->setText("Max " + timestamp.toString(Qt::SystemLocaleShortDate));
    connect(ui->rangeMin, SIGNAL(sliderMoved(int)), this, SLOT(updatedSlider(int)));
    connect(ui->rangeMax, SIGNAL(sliderMoved(int)), this, SLOT(updatedSlider(int)));
    connect(ui->rangeMin, SIGNAL(sliderReleased()), this, SLOT(updatePlot()));
    connect(ui->rangeMax, SIGNAL(sliderReleased()), this, SLOT(updatePlot()));
    connect(ui->toCSVBtn, SIGNAL(clicked()), this, SLOT(toCSV()));
    connect(ui->vbox, SIGNAL(toggled(bool)), this, SLOT(vboxClicked(bool)));
    connect(ui->fbox, SIGNAL(toggled(bool)), this, SLOT(fboxClicked(bool)));
    updatePlot();
}

Plotter::~Plotter()
{
    delete ui;
}

void Plotter::updatedSlider(int)
{
    int minIndex = ui->rangeMin->value();
    int maxIndex = ui->rangeMax->value();
    QDateTime timestamp;
    timestamp.setTime_t(readingVector_.at(minIndex).timestamp/1000);
    ui->min_label->setText("Min " + timestamp.toString(Qt::SystemLocaleShortDate));

    timestamp.setTime_t(readingVector_.at(maxIndex).timestamp/1000);
    ui->max_label->setText("Max " + timestamp.toString(Qt::SystemLocaleShortDate));
}

void Plotter::updatePlot()
{
    int minIndex = ui->rangeMin->value();
    int maxIndex = ui->rangeMax->value();
    QVector<double> T;
    QVector<double> V;
    QVector<double> F;
    for(int i = minIndex; i<= maxIndex; i++)
    {
        T.push_back(readingVector_[i].timestamp);
        V.push_back(readingVector_[i].voltage);
        F.push_back(readingVector_[i].frequency);
    }
    curveV->setSamples(T,V);
    curveF->setSamples(T,F);
    plot->replot();
}

void Plotter::toCSV()
{
    QString fileName = QFileDialog::getSaveFileName(NULL,"Save File");
    if(fileName == "")
        return;
    QFile out(fileName);
    out.open(QIODevice::WriteOnly);
    int minIndex = ui->rangeMin->value();
    int maxIndex = ui->rangeMax->value();
    for(int i = minIndex; i<= maxIndex; i++)
    {
        out.write((readingVector_[i].toString() + "\n").toAscii());
    }

}

void Plotter::vboxClicked(bool c)
{
    if(c)
        curveV->attach(plot);
    else
        curveV->detach();
    plot->replot();
}

void Plotter::fboxClicked(bool c)
{
    if(c)
        curveF->attach(plot);
    else
        curveF->detach();
    plot->replot();
}
