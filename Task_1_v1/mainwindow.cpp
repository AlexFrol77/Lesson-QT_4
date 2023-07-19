#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(300, 200, 450, 300);
    this->setMaximumSize(550, 350);
    this->setMinimumSize(450, 300);
    this->setStyleSheet("background-color: #aaa;");
    this->setWindowTitle("LessonQT_4");

    setToolProgBar();
    setToolPushButton();
    setToolRadioButton();
    setToolGroupBoxRb();
    setToolComboBox();
    setToolLabel();

    connect(ui->pb_userProgress, SIGNAL(clicked()), this, SLOT(incrProgBar()));
    connect(ui->pb_userProgress, SIGNAL(clicked()), this, SLOT(setColorProgBar()));
    connect(ui->pb_userProgress, SIGNAL(clicked()), this, SLOT(setColorTextProgBar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setToolProgBar()
{
    ui->pB_userProgress->setMinimum(0);
    ui->pB_userProgress->setMaximum(10);
    ui->pB_userProgress->setRange(0, 10);
    ui->pB_userProgress->setValue(0);
    ui->pB_userProgress->setAlignment(Qt::AlignCenter);
    ui->pB_userProgress->setFormat("%p%");

}

void MainWindow::incrProgBar()
{
    ui->pB_userProgress->setValue(step++);
    if (ui->pB_userProgress->value() == ui->pB_userProgress->maximum()) {
        step = 0;
    }
    ui->lb_userProgress->setText("Value Progress Bar: " + QString::number(ui->pB_userProgress->value() * 10) + "%");
}

void MainWindow::setToolPushButton()
{
    ui->pb_userProgress->setText("Increase Progress Bar");
}

void MainWindow::setToolRadioButton()
{
    ui->rb_red->setChecked(true);
    ui->rb_red->setText("Color changes Progress Bar to red");
    ui->rb_green->setText("Color changes Progress Bar to green");
    ui->rb_blue->setText("Color changes Progress Bar to blue");
}

void MainWindow::setToolGroupBoxRb()
{
    ui->gb_userTools->setTitle("Changed color Progress Bar");
    ui->gb_userTools->setStyleSheet("background-color: #9f9;");
}

void MainWindow::setToolComboBox()
{
    ui->cb_listChangesColorTextPb->addItem("Changes to red");
    ui->cb_listChangesColorTextPb->addItem("Changes to green");
    ui->cb_listChangesColorTextPb->addItem("Changes to blue");
    ui->statusbar->showMessage("Color selection : " + ui->cb_listChangesColorTextPb->currentText());
}

void MainWindow::setToolLabel()
{
    ui->lb_userProgress->setText("Value Progress Bar: 0 %");
    ui->lb_userTasks->setText("Color selection text progress");
}

void MainWindow::setColorProgBar()
{
    if (ui->rb_red->isChecked()) {
        ui->pB_userProgress->setStyleSheet("QProgressBar::chunk {"
                                           "background-color: #f00;"
                                           "width: 20px;"
                                           "}");
    }
    else if (ui->rb_green->isChecked()) {
        ui->pB_userProgress->setStyleSheet("QProgressBar::chunk {"
                                           "background-color: #0f0;"
                                           "width: 20px;"
                                           "}");
    }
    else if (ui->rb_blue->isChecked()) {
        ui->pB_userProgress->setStyleSheet("QProgressBar::chunk {"
                                           "background-color: #00f;"
                                           "width: 20px;"
                                           "}");
    }
}

void MainWindow::setColorTextProgBar()
{
    if (ui->cb_listChangesColorTextPb->currentText() == "Changes to red") {
        ui->lb_userProgress->setStyleSheet("color: red;");
    }
    else if (ui->cb_listChangesColorTextPb->currentText() == "Changes to green") {
        ui->lb_userProgress->setStyleSheet("color: green;");
    }
    else if (ui->cb_listChangesColorTextPb->currentText() == "Changes to blue") {
        ui->lb_userProgress->setStyleSheet("color: blue;");
    }
    ui->statusbar->showMessage("Color selection : " + ui->cb_listChangesColorTextPb->currentText());
}

