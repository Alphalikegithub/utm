//g++ -o distance_calculator distance_calculator.cpp
#include <iostream>
#include <cmath>

int main() {
    // 已知距离 d 和角度 θ
    const double d = 30.5286;  // 距离，单位为厘米
    const double theta = 31.6075;  // 固定角度，单位为度

    // 将角度转换为弧度
    double theta_rad = theta * M_PI / 180.0;

    // 输入航向角 α
    double alpha;
    std::cout << "请输入航向角 α (单位：度): ";
    std::cin >> alpha;

    // 将航向角 α 转换为弧度
    double alpha_rad = alpha * M_PI / 180.0;

    // 计算东向和北向的距离
    double d_east = d * sin(alpha_rad - theta_rad);
    double d_north = d * cos(alpha_rad - theta_rad);

    // 输出结果
    std::cout << "d(东向) = " << d_east << " cm" << std::endl;
    std::cout << "d(北向) = " << d_north << " cm" << std::endl;

    return 0;
}
