#ifndef SWITCHDIALOG_H
#define SWITCHDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class SwitchDialog : public QDialog
{
    Q_OBJECT
public:
    SwitchDialog(QWidget *parent=0);

    void setYesClicked(bool c);
    bool getYesClicked() const;

private:
    bool isClicked;

    QLabel *label;

    QPushButton *btn_yes;
    QPushButton *btn_no;

    QHBoxLayout *layout_text;
    QVBoxLayout *layout_btn;
    QHBoxLayout *layout_main;
private slots:
    void yesClicked();
};

#endif // SWITCHDIALOG_H
