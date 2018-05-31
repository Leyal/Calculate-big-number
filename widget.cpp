#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <string>
#include <QMessageBox>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->s = "";
    this->first = "";
    this->second = "";
    this->all = "";
    this->mark = 0;
    this->setWindowTitle("大数计算器");
    ui->textEdit1->setPlaceholderText("0");
    ui->textEdit1->setText(s);
    ui->textEdit2->setText(all);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_button0_clicked()
{
    s+= "0";
    ui->textEdit1->setText(s);
    all+="0";
    ui->textEdit2->setText(all);
    repaint();
}

void Widget::on_button1_clicked()
{
    if(s[0] != '0')
    {
        s+="1";
        ui->textEdit1->setText(s);
        all+="1";
        ui->textEdit2->setText(all);
        repaint();
    }
    else {
        QMessageBox::information(this,"erro","公式格式错误");
    }

}

void Widget::on_button2_2_clicked()
{
    if(s[0] != '0')
    {
        s+="2";
        ui->textEdit1->setText(s);
        all+="2";
        ui->textEdit2->setText(all);
        repaint();
    }else{
        QMessageBox::information(this,"erro","公式格式错误");
    }
}

void Widget::on_button3_2_clicked()
{
    if(s[0] != '0')
    {
        s+="3";
        ui->textEdit1->setText(s);
        all+="3";
        ui->textEdit2->setText(all);
        repaint();
    }else {
        QMessageBox::information(this,"erro","公式格式错误");
    }
}

void Widget::on_button4_clicked()
{
    if(s[0] != '0')
    {
        s+="4";
        ui->textEdit1->setText(s);
        all+="4";
        ui->textEdit2->setText(all);
        repaint();
    }else {
        QMessageBox::information(this,"erro","公式格式错误");
    }
}

void Widget::on_button5_clicked()
{
    if(s[0] != '0')
    {
        s+="5";
        ui->textEdit1->setText(s);
        all+="5";
        ui->textEdit2->setText(all);
        repaint();
    }
    else {
        QMessageBox::information(this,"erro","公式格式错误");
    }
}

void Widget::on_button6_clicked()
{
    if(s[0] != '0')
    {
        s+="6";
        ui->textEdit1->setText(s);
        all+="6";
        ui->textEdit2->setText(all);
        repaint();
    }else {
        QMessageBox::information(this,"erro","公式格式错误");
    }
}

void Widget::on_button7_clicked()
{
    if(s[0] != '0')
    {
        s+="7";
        ui->textEdit1->setText(s);
        all+="7";
        ui->textEdit2->setText(all);
        repaint();
    }else {
        QMessageBox::information(this,"erro","公式格式错误");
    }
}

void Widget::on_button8_clicked()
{
    if(s[0] != '0')
    {
        s+="8";
        ui->textEdit1->setText(s);
        all+="8";
        ui->textEdit2->setText(all);
        repaint();
    }
    else {
        QMessageBox::information(this,"erro","公式格式错误");
    }
}

void Widget::on_button9_clicked()
{
    if(s[0] != '0')
    {
        s+="9";
        ui->textEdit1->setText(s);
        all+="9";
        ui->textEdit2->setText(all);
        repaint();
    }
    else {
        QMessageBox::information(this,"erro","公式格式错误");
    }
}

void Widget::on_mutiplicationButton_clicked()
{
    if(s != NULL)
    {
        value1 = s;
        s = "";
        ui->textEdit1->setText(s);
        all+="*";
        ui->textEdit2->setText(all);
        mark = 1;
        repaint();
    }
    else {
        QMessageBox::information(this,"erro","公式格式错误");
    }

}

void Widget::on_clearButton_clicked()
{
    s = "";
    value1 = "";
    value2 = "";
    all="";
    ui->textEdit1->setText(s);
    ui->textEdit2->setText("");
    ui->textEdit3->setText("");
    repaint();
}

void Widget::on_equalButton_clicked()
{
    value2 = s;
   if(value1!= NULL&&value2 != NULL)
   {
       string v1 = value1.toStdString();
       string v2 = value2.toStdString();
       string result = BigMutiple(v1,v2);
       QString all_result = QString::fromStdString(result);
       ui->textEdit3->setText(all_result);
       repaint();
   }
   else {
       QMessageBox::information(this,"error","格式错误");
   }
}

string Widget::BigMutiple(string num1, string num2)
{

        string res="";
        int m = num1.size(), n = num2.size();
        vector<long long> tmp(m + n - 1);
        for (int i = 0; i < m; i++){
            int a = num1[i] - '0';
            for (int j = 0; j < n; j++){
                int b = num2[j] - '0';
                tmp[i + j] += a*b;
            }
        }
        int carry = 0;
        for (int i = tmp.size() - 1; i >= 0; i--){
            int t = tmp[i] + carry;
            tmp[i] = t % 10;
            carry = t / 10;
        }
        while (carry != 0){
            int t = carry % 10;
            carry /= 10;
            tmp.insert(tmp.begin(), t);
        }
        for (auto a : tmp){
            res = res + to_string(a);
        }
        if(res.size()>0&&res[0]=='0')return "0";
        return res;
}

bool Widget::isZeroFirst()
{
    if(s[0] == '0')
    {
       QMessageBox::information(this,"erro","乘数不符合标准");
       return true;
    }
    return false;
}
