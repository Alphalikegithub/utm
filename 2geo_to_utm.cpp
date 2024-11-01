//g++ -o final2 geo_to_utm.cpp datum.cpp utm.cpp
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "datum.h"
#include "utm.h"

int main(int argc, char** argv)
{
    // 打开输入文件 "LB.txt"
    std::ifstream inputFile("file/LB5.txt");
    if (!inputFile) {
        std::cerr << "无法打开输入文件 LB.txt" << std::endl;
        return 1;
    }

    // 打开输出文件 "UTM坐标.txt"
    std::ofstream outputFile("output/UTM坐标5.txt");
    if (!outputFile) {
        std::cerr << "无法创建输出文件 UTM坐标.txt" << std::endl;
        return 1;
    }

    // 跳过输入文件的标题行
    std::string header;
    std::getline(inputFile, header);

    // 写入输出文件的标题行
    outputFile << "X\t\tY" << std::endl;

    const Ellipse* e = standard_ellipse(ELLIPSE_WGS84);
    double lon, lat;
    while (inputFile >> lon >> lat) {
        // 将经纬度从度转换为弧度
        double lat_rad = lat * M_PI / 180.0;
        double lon_rad = lon * M_PI / 180.0;

        double N, E;
        GridZone zone = GRID_AUTO;
        Hemisphere hemi = HEMI_AUTO;

        // 经纬度转换为 UTM 坐标
        geographic_to_grid(e->a, e->e2, lat_rad, lon_rad, &zone, &hemi, &N, &E);

        // 将结果写入输出文件，以 X（Easting）、Y（Northing）格式输出
        outputFile << std::fixed << std::setprecision(9) << E << "\t" 
                   << std::fixed << std::setprecision(9) << N << std::endl;
    }

    // 关闭文件
    inputFile.close();
    outputFile.close();

    std::cout << "转换完成，结果已写入: UTM坐标.txt" << std::endl;

    return 0;
}
