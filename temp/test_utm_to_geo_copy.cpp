// Sample code: test_utm_to_geo.cpp
// Compile: g++ -o copy2 test_utm_to_geo_copy.cpp datum.cpp utm.cpp

#include<iostream>
#include<iomanip>
#include<cmath>
#include"datum.h"
#include"utm.h"

int main(int argc, char** argv)
{
    // 定义多组 UTM 坐标测试数据（单位：米）
    double test_data[][2] = {
        {492749.0228, 2167055.962},
        {492749.0264, 2167055.966},
        {492749.0266, 2167055.965},
        {492749.0209, 2167055.966},
        {492749.0211, 2167055.965},
        {492749.0208, 2167055.967},
        {492749.0161, 2167055.967},
        {492749.0163, 2167055.968},
        {492749.0142, 2167055.968},
        {492749.0157, 2167055.966},
        {492749.0148, 2167055.968},
        {492749.016, 2167055.967},
        {492749.0144, 2167055.966},
        {492749.016, 2167055.969},
        {492749.0152, 2167055.967},
        {492749.0139, 2167055.968},
        {492749.0171, 2167055.967},
        {492749.0151, 2167055.968},
        {492749.0163, 2167055.967},
        {492749.0171, 2167055.968}
    };

    int num_tests = sizeof(test_data) / sizeof(test_data[0]);
    GridZone zone = UTM_ZONE_49; // 指定 UTM 区域
    Hemisphere hemi = HEMI_NORTH; // 指定半球

    const Ellipse* e = standard_ellipse(ELLIPSE_WGS84);
    
    for (int i = 0; i < num_tests; ++i) {
        double N = test_data[i][1]; // 北向坐标
        double E = test_data[i][0]; // 东向坐标
        double lat, lon;

        // 转换 UTM 到经纬度
        grid_to_geographic(e->a, e->e2, zone, hemi, N, E, &lat, &lon);
        
        // 输出经纬度，转换为度
        std::cout << "Test Case " << i + 1 << ": \n";
        std::cout << "UTM Easting: " << std::fixed << std::setprecision(4) << E
                  << " Northing: " << std::fixed << std::setprecision(4) << N << "\n";
        std::cout << "Latitude: " << std::fixed << std::setprecision(6) << lat / M_PI * 180.0 
                  << " Longitude: " << std::fixed << std::setprecision(6) << lon / M_PI * 180.0 << std::endl << std::endl;
    }

    return 0;
}
