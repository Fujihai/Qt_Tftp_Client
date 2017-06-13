#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*2.Add Headers*/
#include <QMainWindow>
#include <QDebug>
#include <QUdpSocket>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QIODevice>
#include <QtEndian>
#include <QString>
#include <QProgressBar>
#include <QStyleFactory>
#include "tftp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QUdpSocket *udpSocketClient;
    QFile *rFile;
    QFile *sFile;
    QFileDialog *dialog;

    char recvData[RECV_BUFFER_SIZE];

    void sendReadReqMsg(char *pFilename);
    void sendDataAckMsg(struct TFTPData *pData, QHostAddress sender, quint16 senderPort);
    void sendWriteReqMsg(char *pFilename);
    void sendDataMsg(short blockno, QHostAddress sender, quint16 senderPort);

private:
    Ui::MainWindow *ui;

private slots:
    void readPendingDatagrams();
    void on_pushButton_Start_clicked();
    void on_pushButton_browse_clicked();
    void on_pushButton_select_clicked();
    void on_radioButton_get_clicked();
    void on_radioButton_put_clicked();
};

#endif // MAINWINDOW_H
