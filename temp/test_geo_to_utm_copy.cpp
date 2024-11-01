// Sample code: test_geo_to_utm.cpp
// Compile: g++ -o copy test_geo_to_utm_copy.cpp datum.cpp utm.cpp

#include<iostream>
#include<iomanip>
#include<cmath>
#include"datum.h"
#include"utm.h"

int main(int argc, char** argv)
{
    // 定义多组经纬度测试数据（单位为度）
    double test_data[][2] = {
        {110.930856080, 19.598519694},
        {110.930856114, 19.598519735},
        {110.930856116, 19.598519721},
        {110.930856062, 19.598519730},
        {110.930856064, 19.598519723},
        {110.930856061, 19.598519743},
        {110.930856016, 19.598519741},
        {110.930856018, 19.598519751},
        {110.930855998, 19.598519754},
        {110.930856012, 19.598519735},
        {110.930856004, 19.598519746},
        {110.930856015, 19.598519741},
        {110.930856000, 19.598519728},
        {110.930856015, 19.598519760},
        {110.930856007, 19.598519744},
        {110.930855995, 19.598519750},
        {110.930856026, 19.598519744},
        {110.930856006, 19.598519746},
        {110.930856018, 19.598519741},
        {110.930856026, 19.598519752}
    };

    int num_tests = sizeof(test_data) / sizeof(test_data[0]);

    const Ellipse* e = standard_ellipse(ELLIPSE_WGS84);
    for (int i = 0; i < num_tests; ++i) {
        double lat = test_data[i][1] * M_PI / 180.0;  // 转换为弧度
        double lon = test_data[i][0] * M_PI / 180.0;  // 转换为弧度
        double N, E;
        GridZone zone = GRID_AUTO;
        Hemisphere hemi = HEMI_AUTO;

        geographic_to_grid(e->a, e->e2, lat, lon, &zone, &hemi, &N, &E);

        std::cout << "Test Case " << i+1 << ": \n";
        // std::cout << "Latitude: " << std::fixed << std::setprecision(9) << test_data[i][1]
        //           << " Longitude: " << std::fixed << std::setprecision(9) << test_data[i][0] << "\n";
        std::cout << "Longitude: " << std::fixed << std::setprecision(9) << test_data[i][0]
                  << " Latitude: " << std::fixed << std::setprecision(9) << test_data[i][1] << "\n";
        std::cout << "UTM Easting: " << std::fixed << std::setprecision(4) << E 
                  << " Northing: " << std::fixed << std::setprecision(4) << N 
                  << " Zone: " << zone 
                  << " Hemisphere: " << (hemi == HEMI_NORTH ? "North" : "South") 
                  << std::endl << std::endl;
    }

    return 0;
}
