#include "DrawBoard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDrawBoard w;
   w.show();
    return a.exec();
}
