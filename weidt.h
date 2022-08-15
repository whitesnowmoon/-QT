#ifndef WEIDT_H
#define WEIDT_H

#include <QObject>
#include <QTextEdit>
#include "Disk.h"
#include "FileM.h"
#include "Filemanage.h"
#include "Profiles.h"
#include "wigdetdisk.h"
#include "FPage.h"
#include <QMessageBox>
class weidt :public QTextEdit
{
    Q_OBJECT
public:
    bool open=0;
    static int opennum;
    string* rw;
    OFTLE* file;
    void setOFTLE(int index);
    void init();
    weidt();

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // WEIDT_H
