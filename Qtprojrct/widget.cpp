#include "widget.h"
#include "ui_widget.h"
#include <qDebug>
#include <QRegularExpressionValidator>
#include "Circuit.h"
#include "../src/include/Utils.hpp"
#include "../src/include/CircuitSimulator.hpp"
#include "../src/include/floyd.hpp"

Graphl my_circuit;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->Delete_txt->setPlaceholderText(tr("例：3"));  //设置输入框提示语

    //限制输入的数据类型
    QRegularExpression rx("-?\\d{1,3}");  //节点编号仅为整数
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->Delete_txt->setValidator(validator);
    ui->Bus_txt1->setValidator(validator);
    ui->Bus_txt2->setValidator(validator);

    QRegularExpression rx1("^(-?\\d+)(\\.\\d+)?$");  //阻抗可以为负数或小数
    QValidator *validator1 = new QRegularExpressionValidator(rx1, this);
    ui->Resistance_txt->setValidator(validator1);
    ui->Reactance_txt->setValidator(validator1);

    //初始化矩阵
    // importFromCSV(my_circuit,"example2");
    importFromCSV(my_circuit,"example2");
    cout << "print Adjust" << endl;
    my_circuit.printAdjList();
    ui->graphWidget->update();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Add_Button_clicked()  //当点击了添加节点按钮
{
    //尝试调用函数
    my_circuit.addVertex();
    cout << "Bus added! Print AdjustList" << endl;
    my_circuit.printAdjList();
    ui->graphWidget->showVoltageResults(false);
    ui->graphWidget->showCurrentPowerResults(false);
    ui->graphWidget->update();
}


void Widget::on_Delete_Button_clicked()  //当点击了删除节点按钮
{
    //尝试获取txt中的信息
    //QString Deletebus = ui->Delete_txt->text();  //得到输入内容
    int Deletebus = ui->Delete_txt->text().toInt();

    if (my_circuit.delVertex(Deletebus))  {
        ui->Delete_txt->setPlaceholderText(tr("例：3"));  //设置输入框提示语
        qDebug() << Deletebus << " " << Qt::endl;
    }
    else{
        ui->Delete_txt->setPlaceholderText(tr("节点不存在"));  //提示错误
        qDebug() << "节点不存在，重新输入" << " " << Qt::endl;
    }

    cout << "Bus delete! Print AdjustList" << endl;
    my_circuit.printAdjList();

    ui->Delete_txt->clear();  //清空输入框
    ui->graphWidget->showVoltageResults(false);
    ui->graphWidget->showCurrentPowerResults(false);
    ui->graphWidget->update();
}


// 删除阻抗
void Widget::on_Delete_impedance_clicked()
{
    int bus1 = ui->Bus_txt1->text().toInt();
    int bus2 = ui->Bus_txt2->text().toInt();
    if(my_circuit.isEdge(bus1,bus2)){
        my_circuit.delEdge(bus1,bus2);
        ui->Bus_txt1->setPlaceholderText(tr("3"));  //设置输入框提示语
        ui->Bus_txt2->setPlaceholderText(tr("4"));  //设置输入框提示语
    }
    else{
        ui->Bus_txt1->setPlaceholderText(tr("错误"));  //设置输入框提示语
        ui->Bus_txt2->setPlaceholderText(tr("错误"));  //设置输入框提示语
    }

    ui->Bus_txt1->clear();  //清空输入框
    ui->Bus_txt2->clear();  //清空输入框

    cout << "Impedance delete! Print AdjustList" << endl;
    my_circuit.printAdjList();
    ui->graphWidget->showVoltageResults(false);
    ui->graphWidget->showCurrentPowerResults(false);
    ui->graphWidget->update();

}


void Widget::on_Change_impedance_clicked()
{
    int bus1 = ui->Bus_txt1->text().toInt();
    int bus2 = ui->Bus_txt2->text().toInt();
    float resistance = ui->Resistance_txt->text().toFloat();
    float racetance = ui->Reactance_txt->text().toFloat();
    complex<double> mycomplex(resistance, racetance);

    if(bus2>bus1){
        if(resistance>=0){
            my_circuit.setEdge(bus1,bus2, mycomplex);
            ui->Bus_txt1->setPlaceholderText(tr("3"));  //设置输入框提示语
            ui->Bus_txt2->setPlaceholderText(tr("4"));  //设置输入框提示语
        }
        else{
            ui->Resistance_txt->setPlaceholderText(tr("电阻>0"));
        }
    }
    else{
        ui->Bus_txt1->setPlaceholderText(tr("小节点前"));  //设置输入框提示语
        ui->Bus_txt2->setPlaceholderText(tr("小节点前"));  //设置输入框提示语
    }

    ui->Bus_txt1->clear();  //清空输入框
    ui->Bus_txt2->clear();  //清空输入框
    ui->Reactance_txt->clear();  //清空输入框
    ui->Resistance_txt->clear();

    cout << "Impedance change! Print AdjustList" << endl;
    my_circuit.printAdjList();
    ui->graphWidget->showVoltageResults(false);
    ui->graphWidget->showCurrentPowerResults(false);
    ui->graphWidget->update();
}


void Widget::on_analyseButton_clicked()
{

    CircuitSimulator simulator(my_circuit);
    simulator.setVoltageSource(0, Complex(220, 0));
    simulator.setReferenceNode();
    simulator.analyze();

    ui->graphWidget->setAnalysisData(
        simulator.getNodeVoltages(),
        simulator.getBranchCurrents(),
        simulator.getBranchPowers()
        );
    ui->graphWidget->showVoltageResults(true);       // 只显示电压
    ui->graphWidget->showCurrentPowerResults(false); // 不显示电流和功率

    cout << "Circuit analysing! Print parameters:" << endl;

    // 看能否打印电流电压矩阵
    // 获取节点电压
    cout << "Node Voltage: " << endl;
    const auto &voltages = simulator.getNodeVoltages();
    for (int i = 0; i < voltages.size(); i++)
    {
        double magnitude = abs(voltages[i]);          // 模
        double phase = arg(voltages[i]) * 180 / M_PI; // 幅角，转换为度
        cout << fixed << setprecision(4);
        cout << "V" << (i + 1) << " = ";
        // api dosomthing()
        cout << magnitude << " |_" << phase << " V" << endl;
    }

    // 节点连线上的电流
    cout << "\nBranch current: " << endl;
    const auto &currents = simulator.getBranchCurrents();
    int branchIndex = 0;
    for (int i = 0; i < my_circuit.n(); i++)
    {
        for (int j = i + 1; j < my_circuit.n(); j++)
        {
            if (my_circuit.getAdjMatrix()[i][j] != Complex(0, 0))
            {
                double magnitude = abs(currents[branchIndex]);          // 模
                double phase = arg(currents[branchIndex]) * 180 / M_PI; // 幅角
                cout << "I" << (i + 1) << "-" << (j + 1) << " = ";
                // api dosomthing()
                cout << magnitude << " |_" << phase << " A" << endl;
                branchIndex++;
            }
        }
    }

    // 节点连线上的损耗功率
    cout << "\nBranch power" << endl;
    const auto &powers = simulator.getBranchPowers();
    branchIndex = 0;
    for (int i = 0; i < my_circuit.n(); i++)
    {
        for (int j = i + 1; j < my_circuit.n(); j++)
        {
            if (my_circuit.getAdjMatrix()[i][j] != Complex(0, 0))
            {
                double active = real(powers[branchIndex]);   // 有功
                double reactive = imag(powers[branchIndex]); // 无功
                // api dosomthing()
                cout << "S" << (i + 1) << "-" << (j + 1) << " = ";
                // printComplex(powers[branchIndex]);
                cout << active << (reactive >= 0 ? "+" : "") << reactive << "j";
                cout << " VA" << endl;
                branchIndex++;
            }
        }
    }
}


void Widget::on_pushButton_2_clicked()
{
    ui->graphWidget->showVoltageResults(false);
    ui->graphWidget->showCurrentPowerResults(false);
}


void Widget::on_analyseButton_2_clicked()
{
    ui->graphWidget->showCurrentPowerResults(true); // 显示电流和功率
    cout << "Showing current and power result on the plot" << endl;
}


void Widget::on_importButton_clicked()
{
    importFromCSV(my_circuit, "config");  // QString 转 std::string
    cout << "Import new file, print Adjust" << endl;
    my_circuit.printAdjList();
    ui->graphWidget->update();
}


void Widget::on_pushButton_clicked()   //转出为csv
{
    cout << "Output as csv" << endl;
    exportToCSV(my_circuit,"export");

}


void Widget::on_floydButton_clicked()
{
    cout << "Floyd analysis" << endl;
    Floyd(&my_circuit);
}

