#include "CSVImporter.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

CSVImporter::CSVImporter(const std::string& filename) {
    parseCSV(filename); // 调用解析函数
}

void CSVImporter::parseCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    int nodeIndex = 0;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string busPair, r, x;
        std::getline(ss, busPair, ',');
        std::getline(ss, r, ',');
        std::getline(ss, x, ',');

        if (busPair == "Line bus to bus") continue; // 跳过标题行

        std::string bus1 = busPair.substr(0, busPair.find('-'));
        std::string bus2 = busPair.substr(busPair.find('-') + 1);

        // 如果节点未映射，添加到 nodeMapping
        if (nodeMapping.find(bus1) == nodeMapping.end()) {
            nodeMapping[bus1] = nodeIndex++;
        }
        if (nodeMapping.find(bus2) == nodeMapping.end()) {
            nodeMapping[bus2] = nodeIndex++;
        }

        // 计算阻抗
        double resistance = std::stod(r);
        double reactance = std::stod(x);
        double impedance = std::sqrt(resistance * resistance + reactance * reactance);

        // 调整邻接矩阵大小
        int size = nodeMapping.size();
        if (adjMatrix.size() < size) {
            adjMatrix.resize(size, std::vector<std::complex<double>>(size, {0, 0}));
        }

        // 填充邻接矩阵
        adjMatrix[nodeMapping[bus1]][nodeMapping[bus2]] = {impedance, 0};
        adjMatrix[nodeMapping[bus2]][nodeMapping[bus1]] = {impedance, 0};
    }
}

std::vector<std::vector<std::complex<double>>> CSVImporter::getAdjMatrix() const {
    return adjMatrix;
}

std::map<std::string, int> CSVImporter::getNodeMapping() const {
    return nodeMapping;
}