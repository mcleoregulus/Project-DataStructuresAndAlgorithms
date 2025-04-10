#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <vector>
#include <complex>

class paintwidget : public QWidget
{
    Q_OBJECT
public:
    explicit paintwidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

    // 新增辅助方法
    QPoint calculateNodePosition(int nodeIndex, int totalNodes);
    void drawAdjacencyMatrix(QPainter &painter);

    // 设置分析数据
    void setAnalysisData(const std::vector<std::complex<double>>& voltages,
                         const std::vector<std::complex<double>>& currents,
                         const std::vector<std::complex<double>>& powers);

    // 控制是否显示分析结果
    void showAnalysisResults(bool show);

    // 修改控制显示方法
    void showVoltageResults(bool show);
    void showCurrentPowerResults(bool show);

private:
    std::vector<QPoint> nodePositions;
    int gridSize;

    // 分析数据
    std::vector<std::complex<double>> nodeVoltages;
    std::vector<std::complex<double>> branchCurrents;
    std::vector<std::complex<double>> branchPowers;
    bool showAnalysis = false;

    // 辅助函数：格式化复数
    QString formatComplex(const std::complex<double>& c);

    bool showVoltage = false;
    bool showCurrentPower = false;
};

#endif // PAINTWIDGET_H

