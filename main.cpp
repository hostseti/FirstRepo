#include "serverchat.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ServerChat w;
    w.setFixedSize(QSize(303, 92));
    w.show();

    return a.exec();
}
