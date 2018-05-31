#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <string>
using namespace std;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QString s;
    QString first;
    QString second;
    QString all;
    QString value1;
    QString value2;
    int mark;

private slots:
    void on_button0_clicked();

    void on_button1_clicked();

    void on_button2_2_clicked();

    void on_button3_2_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button7_clicked();

    void on_button8_clicked();

    void on_button9_clicked();

    void on_mutiplicationButton_clicked();

    void on_clearButton_clicked();

    void on_equalButton_clicked();
    string BigMutiple(string num1, string num2);
    bool isZeroFirst();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
