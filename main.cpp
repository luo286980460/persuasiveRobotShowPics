#include <QCoreApplication>
#include "mainclass.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //qDebug() <<
    MainClass mainClass;

    return a.exec();
}
