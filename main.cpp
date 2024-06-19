#include <QCoreApplication>
#include "mainclass.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainClass mainClass;

    return a.exec();
}
