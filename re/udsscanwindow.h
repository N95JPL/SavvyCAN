#ifndef UDSSCANWINDOW_H
#define UDSSCANWINDOW_H

#include "can_structs.h"
#include "connections/canconnection.h"

#include <QDialog>

namespace Ui {
class UDSScanWindow;
}

struct UDS_TESTS
{
    int ID;
    int bus;
    int service;
    int subFunc;
};

class UDSScanWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UDSScanWindow(const QVector<CANFrame> *frames, QWidget *parent = 0);
    ~UDSScanWindow();

private slots:
    void updatedFrames(int numFrames);
    void rapidFrames(const CANConnection* conn, const QVector<CANFrame>& pFrames);
    void scanUDS();
    void saveResults();
    void timeOut();

private:
    Ui::UDSScanWindow *ui;
    const QVector<CANFrame> *modelFrames;
    QTimer *waitTimer;
    QList<UDS_TESTS> sendingFrames;
    int currIdx = 0;
    bool currentlyRunning;

    void sendNextMsg();
    void sendOnBuses(UDS_TESTS frame, int buses);
};

#endif // UDSSCANWINDOW_H
