#include "./ui_MainWidget.h"
#include "MainWidget.hpp"
#include <QWidget>

MainWidget::MainWidget(QWidget *parent) 
    : QWidget(parent), ui(new Ui::MainWidget) {

    ui->setupUi(this);

}

MainWidget::~MainWidget() {
    delete ui;
}
