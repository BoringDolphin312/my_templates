#include <iostream>
#include <QApplication>

#include "MainWidget.hpp"

int main(int argc, char **argv){
    QApplication a(argc, argv);
    MainWidget w;

    w.show();

    return QApplication::exec();
}
