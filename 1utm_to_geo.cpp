//g++ -o final1 utm_to_geo.cpp datum.cpp utm.cpp
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "datum.h"
#include "utm.h"

int main(int argc, char** argv)
{
    // 打开输入文件 "XY.txt"
    
    std::ifstream inputFile("file/UTM坐标1加偏移量.txt");
    if (!inputFile) {
        std::cerr << "无法打开输入文件 XY.txt" << std::endl;
        return 1;
    }

    // 打开输出文件 "经纬度坐标.txt"
    std::ofstream outputFile("output/经纬度坐标1.txt");
    if (!outputFile) {
        std::cerr << "无法创建输出文件 经纬度坐标.txt" << std::endl;
        return 1;
    }

    // 跳过输入文件的标题行
    std::string header;
    std::getline(inputFile, header);

    // 写入输出文件的标题行
    outputFile << "lon\t\tlat" << std::endl;

    // 定义 UTM 区域和半球
    GridZone zone = UTM_ZONE_49;
    Hemisphere hemi = HEMI_NORTH;
    const Ellipse* e = standard_ellipse(ELLIPSE_WGS84);

    // 读取每行的 UTM 数据并转换
    double E, N;
    while (inputFile >> E >> N) {
        double lat, lon;
        
        // UTM 转换为经纬度
        grid_to_geographic(e->a, e->e2, zone, hemi, N, E, &lat, &lon);
        
        // 将结果写入输出文件
        outputFile << std::fixed << std::setprecision(12) 
                   << lon / M_PI * 180.0 << "\t" 
                   << lat / M_PI * 180.0 << std::endl;
    }

    // 关闭文件
    inputFile.close();
    outputFile.close();

    std::cout << "转换完成，结果已写入: 经纬度坐标.txt" << std::endl;

    return 0;
}
