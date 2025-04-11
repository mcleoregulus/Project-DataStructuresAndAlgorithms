#include "paintwidget.h"
#include "Circuit.h"
#include <cmath>
#include <iomanip>
#include <sstream>

paintwidget::paintwidget(QWidget *parent)
    : QWidget{parent}
{
    this->setAttribute(Qt::WA_StyledBackground, true);
    gridSize = 50;
}

QString paintwidget::formatComplex(const std::complex<double>& c) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2)
        << c.real() << (c.imag() >= 0 ? "+" : "") << c.imag() << "j";
    return QString::fromStdString(oss.str());
}

void paintwidget::setAnalysisData(const std::vector<std::complex<double>>& voltages,
                                  const std::vector<std::complex<double>>& currents,
                                  const std::vector<std::complex<double>>& powers) {
    nodeVoltages = voltages;
    branchCurrents = currents;
    branchPowers = powers;
    update();
}

// 替换原有的 showAnalysisResults 方法
void paintwidget::showVoltageResults(bool show) {
    showVoltage = show;
    update();
}

void paintwidget::showCurrentPowerResults(bool show) {
    showCurrentPower = show;
    update();
}

QPoint paintwidget::calculateNodePosition(int nodeIndex, int totalNodes) {
    int n = std::ceil(std::sqrt(totalNodes));
    int row = nodeIndex / n;
    int col = nodeIndex % n;
    int margin = 40; //20->40
    int x = margin + col * (width() - 2 * margin) / (n - 1);
    int y = margin + row * (height() - 2 * margin) / (n - 1);
    return QPoint(x, y);
}

void paintwidget::drawAdjacencyMatrix(QPainter &painter) {
    // 1. 计算节点位置
    int nodeCount = my_circuit.n();
    nodePositions.clear();

    for (int i = 0; i < nodeCount; ++i) {
        nodePositions.push_back(calculateNodePosition(i, nodeCount));
    }

    // 2. 绘制连接线
    QPen linePen(Qt::blue);
    linePen.setWidth(2);
    painter.setPen(linePen);

    int branchIndex = 0;
    for (int i = 0; i < nodeCount; ++i) {
        my_circuit.getAdjList()->moveToPos(i);
        LList<Edge>* edges = my_circuit.getAdjList()->getValue();

        edges->moveToStart();
        while (edges->currPos() < edges->length()) {
            Edge e = edges->getValue();
            int j = e.vertex();

            if (i < j) {
                // 绘制从i到j的线
                painter.drawLine(nodePositions[i], nodePositions[j]);

                // 在连线中间显示阻抗（保持蓝色）
                QPoint midPoint = (nodePositions[i] + nodePositions[j]) / 2;
                QString impedanceText = QString("Z=%1").arg(formatComplex(e.weight()));
                painter.drawText(midPoint, impedanceText);

                // 如果显示分析结果，绘制电流和功率（红色）
                if (showCurrentPower && branchIndex < int(branchCurrents.size())) { // toInt
                    // 保存当前画笔设置
                    QPen oldPen = painter.pen();

                    // 设置红色文本
                    QPen redPen(Qt::red);
                    painter.setPen(redPen);

                    QPoint currentPos = midPoint + QPoint(0, 15);
                    QString currentText = QString("I=%1").arg(formatComplex(branchCurrents[branchIndex]));
                    painter.drawText(currentPos, currentText);

                    QPoint powerPos = midPoint + QPoint(0, 30);
                    QString powerText = QString("P=%1").arg(formatComplex(branchPowers[branchIndex]));
                    painter.drawText(powerPos, powerText);

                    // 恢复画笔设置
                    painter.setPen(oldPen);
                }
                branchIndex++;
            }
            edges->next();
        }
    }

    // 3. 绘制节点
    QPen nodePen(Qt::black);
    nodePen.setWidth(2);
    painter.setPen(nodePen);

    QBrush nodeBrush(Qt::green);
    painter.setBrush(nodeBrush);

    int nodeRadius = 15;
    for (int i = 0; i < nodeCount; ++i) {
        painter.drawEllipse(nodePositions[i], nodeRadius, nodeRadius);
        painter.drawText(nodePositions[i], QString::number(i));

        // 修改节点电压显示部分
        if (showVoltage && i < int(nodeVoltages.size())) { // toInt
            QPoint voltagePos = nodePositions[i] + QPoint(0, -30);
            QString voltageText = QString("V=%1").arg(formatComplex(nodeVoltages[i]));
            painter.drawText(voltagePos, voltageText);
        }
    }
}

void paintwidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 设置背景
    painter.setBrush(QColor(240, 240, 240));
    painter.drawRect(rect());

    // 绘制邻接矩阵图
    drawAdjacencyMatrix(painter);
}

