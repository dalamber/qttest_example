#include "main_widget.h"

#include "lib/src/random.h"

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

ui::MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    auto numberTitleLabel = new QLabel("Random number:\t", this);
    auto uuidTitleLabel = new QLabel("Random UUID:\t", this);

    auto numberEdit = new QLineEdit(this);
    auto uuidEdit = new QLineEdit(this);

    auto refreshButton = new QPushButton("Refresh", this);
    auto exitButton = new QPushButton("Exit", this);
    refreshButton->setFixedWidth(100);
    exitButton->setFixedWidth(100);

    auto numLayout = new QHBoxLayout();
    numLayout->addWidget(numberTitleLabel);
    numLayout->addWidget(numberEdit);

    auto uuidLayout = new QHBoxLayout();
    uuidLayout->addWidget(uuidTitleLabel);
    uuidLayout->addWidget(uuidEdit);

    auto mainLayout = new QVBoxLayout();
    mainLayout->addLayout(numLayout);
    mainLayout->addLayout(uuidLayout);
    mainLayout->addWidget(refreshButton);
    mainLayout->addWidget(exitButton);

    setLayout(mainLayout);

    setMinimumWidth(460);
    setFixedHeight(140);

    auto updateEdits = [=]
    {
        numberEdit->setText(QString::number(tester_lib::randomNumber()));
        uuidEdit->setText(tester_lib::randomUuid());
    };

    connect(refreshButton, &QPushButton::clicked, updateEdits);
    connect(exitButton, &QPushButton::clicked, qApp, &QCoreApplication::quit);

    updateEdits();
}
