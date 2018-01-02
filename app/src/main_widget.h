#ifndef TESTER_MAINWIDGET_H
#define TESTER_MAINWIDGET_H

#include <QWidget>

namespace ui
{
    class MainWidget : public QWidget
    {
    public:
        explicit MainWidget(QWidget *parent = nullptr);
        ~MainWidget() override = default;
    };
}


#endif //TESTER_MAINWIDGET_H
