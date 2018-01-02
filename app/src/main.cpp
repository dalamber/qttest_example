#include <QApplication>

#include "main_widget.h"

int main(int argc, char *argv[1])
{
    QApplication app(argc, argv);

    ui::MainWidget w;
    w.show();

    return app.exec();
}