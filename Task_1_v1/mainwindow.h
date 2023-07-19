#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setToolProgBar();
    void setToolPushButton();
    void setToolRadioButton();
    void setToolGroupBoxRb();
    void setToolComboBox();
    void setToolLabel();

private slots:

    void incrProgBar();
    void setColorProgBar();
    void setColorTextProgBar();

private:
    Ui::MainWindow *ui;
    int step = 1;
};
#endif // MAINWINDOW_H
