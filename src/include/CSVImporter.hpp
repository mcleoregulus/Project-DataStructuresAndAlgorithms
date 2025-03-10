#ifndef CSVIMPORTER_HPP
#define CSVIMPORTER_HPP

#include <vector>
#include <string>
#include <map>
#include <complex>

class CSVImporter {
public:
    CSVImporter(const std::string& filename);
    std::vector<std::vector<std::complex<double> > > getAdjMatrix() const;
    std::map<std::string, int> getNodeMapping() const;

private:
    std::vector<std::vector<std::complex<double> > > adjMatrix; // 邻接矩阵
    std::map<std::string, int> nodeMapping; // 节点名称到索引的映射
    void parseCSV(const std::string& filename); // CSV 文件解析函数
};

#endif // CSVIMPORTER_HPP