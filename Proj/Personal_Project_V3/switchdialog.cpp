#include "switchdialog.h"
#include <QDebug>

SwitchDialog::SwitchDialog(QWidget *parent)
{
    // INIT vars
    isClicked = false;

    label = new QLabel(tr("Change/flip object? "));
    btn_yes = new QPushButton(tr("Yes"));
    //btn_yes->setDefault(true);
    btn_no = new QPushButton(tr("No"));
    btn_no->setDefault(true);

    // If clicked connections
    connect(btn_yes, SIGNAL(clicked()), this, SLOT(yesClicked()));
    connect(btn_no,  SIGNAL(clicked()), this, SLOT(close()));

    // Layout
    layout_text = new QHBoxLayout();
    layout_text->addWidget(label);

    layout_btn = new QVBoxLayout();
    layout_btn->addWidget(btn_yes);
    layout_btn->addWidget(btn_no);
    layout_btn->addStretch();

    layout_main = new QHBoxLayout();
    layout_main->addLayout(layout_text);
    layout_main->addLayout(layout_btn);

    setLayout(layout_main);

    setWindowTitle("Change?");
    setFixedHeight(sizeHint().height());
}

void SwitchDialog::yesClicked()
{
    qDebug() << "CLICKED YES";

    setYesClicked(true);
    close();
}

void SwitchDialog::setYesClicked(bool c)
{
    isClicked = c;
}

bool SwitchDialog::getYesClicked() const
{
    return isClicked;
}

