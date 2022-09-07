#ifndef WIGDETDISK_H
#define WIGDETDISK_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include "Disk.h"
#include "Profiles.h"

class wigdetdisk :public QLabel
{
    Q_OBJECT
public:
    static wigdetdisk* wdisk;
    int fillPiece[DiskPieceNum];
    QColor fillcolors[DiskPieceNum];
    QPainter painter;
    wigdetdisk(QWidget *parent=nullptr);
protected:
    void paintEvent(QPaintEvent *event);
    int isindex(int i);
    void fillfile(int index);
};

#endif // WIGDETDISK_H
