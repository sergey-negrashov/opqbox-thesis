#ifndef PLOTTER_H
#define PLOTTER_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QMap>
#include <qwt_plot_curve.h>
#include <qwt_plot.h>
#include <qwt_symbol.h>
#include <qwt_plot_marker.h>

namespace Ui {
class Plotter;
}

struct Reading
{
    float voltage;
    float frequency;
    qlonglong timestamp;
    bool operator<(const Reading &other) const
    {
        return (timestamp < other.timestamp);
    }
    QString toString()
    {
        return QString::number(timestamp) + "," + QString::number(frequency) + "," + QString::number(voltage);
    }
};

class Plotter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Plotter(QString file,QWidget *parent = 0);

    ~Plotter();

private slots:
    void updatedSlider(int);
    void updatePlot();
    void toCSV();
    void vboxClicked(bool);
    void fboxClicked(bool);
private:
    Ui::Plotter *ui;
    QFile *file_;
    QVector< struct Reading> readingVector_;
    QwtPlot* plot;
    QwtPlotCurve *curveV;
    QwtPlotCurve *curveF;
};

#endif // PLOTTER_H
