#ifndef CIRCUIT_VISUALIZER_HPP
#define CIRCUIT_VISUALIZER_HPP

#include "CircuitSimulator.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

class CircuitVisualizer {
private:
    const CircuitSimulator& simulator;
    // const Graphl& circuit;
    Graphl& circuit;

    // 生成DOT语言格式的图形描述
    string generateDotGraph() {
        stringstream dot;
        dot << "digraph CircuitGraph {\n";
        dot << "    rankdir=LR;\n";
        dot << "    node [shape=circle];\n";
        
        // 获取电压和电流数据
        const auto& voltages = simulator.getNodeVoltages();
        const auto& currents = simulator.getBranchCurrents();
        
        // 添加节点
        for(int i = 0; i < circuit.n(); i++) {
            dot << "    " << (i+1) << " [label=\"Node " << (i+1) << "\\n"
                << fixed << setprecision(2) 
                << voltages[i].real() << (voltages[i].imag() >= 0 ? "+" : "")
                << voltages[i].imag() << "j V\"];\n";
        }
        
        // 添加边（支路）
        int branchIndex = 0;
        for(int i = 0; i < circuit.n(); i++) {
            for(int j = i + 1; j < circuit.n(); j++) {
                if(circuit.getAdjMatrix()[i][j] != complex<double>(0, 0)) {
                    // 获取支路阻抗
                    complex<double> Z = circuit.getAdjMatrix()[i][j];
                    // 获取支路电流
                    complex<double> I = currents[branchIndex++];
                    
                    // 根据电流方向决定箭头方向
                    int from = I.real() >= 0 ? i+1 : j+1;
                    int to = I.real() >= 0 ? j+1 : i+1;
                    
                    dot << "    " << from << " -> " << to 
                        << " [label=\"Z=" << Z.real() 
                        << (Z.imag() >= 0 ? "+" : "") << Z.imag() 
                        << "j Ω\\nI=" << abs(I.real()) 
                        << (I.imag() >= 0 ? "+" : "") << I.imag() 
                        << "j A\"];\n";
                }
            }
        }
        
        dot << "}\n";
        return dot.str();
    }

public:
    CircuitVisualizer(const CircuitSimulator& sim, Graphl& cg) // const Graphl&
        : simulator(sim), circuit(cg) {}

    // 生成DOT文件
    void generateDotFile(const string& filename) {
        ofstream file(filename);
        if(!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }
        
        file << generateDotGraph();
        file.close();
    }

    // 生成PNG图像（需要系统安装Graphviz）
    void generatePNG(const string& dotFile, const string& pngFile) {
        string command = "dot -Tpng " + dotFile + " -o " + pngFile;
        system(command.c_str());
    }
};

#endif // CIRCUIT_VISUALIZER_HPP 