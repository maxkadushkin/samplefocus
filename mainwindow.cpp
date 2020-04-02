#include "mainwindow.h"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget * widget_ = new QWidget;
    QVBoxLayout * layout_ = new QVBoxLayout(this);
    widget_->setLayout(layout_);

    QLineEdit *
    edit_ = new QLineEdit;
    layout_->addWidget(edit_);

    edit_ = new QLineEdit;
    layout_->addWidget(edit_);

    QLineEdit *
    edit_3 = new QLineEdit;
    layout_->addWidget(edit_3);

    QLineEdit *
    edit_4 = new QLineEdit;
    layout_->addWidget(edit_4);

    setCentralWidget(widget_);

    QPushButton * button_ = new QPushButton("open window");
    layout_->addWidget(button_);

    connect(button_, &QPushButton::clicked, [=]{
        QMainWindow * window_ = new QMainWindow;
        connect(qApp, &QApplication::aboutToQuit, window_, &QMainWindow::deleteLater);

        QWidget * widget_ = new QWidget;
        widget_->setLayout(new QVBoxLayout);

        QPushButton * button_ = new QPushButton("set focus");
        widget_->layout()->addWidget(button_);

        window_->setCentralWidget(widget_);
        window_->show();

        QTimer::singleShot(2000, [=]{
            edit_4->setFocus();
        });

        connect(button_, &QPushButton::clicked, [=]{
            edit_3->setFocus();
        });
    });
}

MainWindow::~MainWindow()
{

}
