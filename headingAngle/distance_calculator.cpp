#include <iostream>
#include <cmath>

int main() {
    // 已知参数
    double d = 30.5286; // 距离，单位为厘米
    double theta = 31.6075; // 固定角度 θ，单位为度

    std::cout << "请输入航向角 α (单位：度): (输入 -1 结束)" << std::endl;
    
    while (true) {
        double alpha;
        std::cout << "航向角: ";
        std::cin >> alpha;

        // 如果用户输入 -1，则结束程序
        if (alpha == -1) {
            break;
        }

        // 将角度转换为弧度
        double alpha_rad = alpha * M_PI / 180.0; // 航向角
        double theta_rad = theta * M_PI / 180.0; // θ角

        // 计算东向和北向的距离
        double d_east = d * sin(alpha_rad - theta_rad);
        double d_north = d * cos(alpha_rad - theta_rad); 

        // 输出结果
        std::cout << "d(东向): " << d_east << " cm" << std::endl;
        std::cout << "d(北向): " << d_north << " cm" << std::endl;

        // 添加分隔线
        std::cout << "---------" << std::endl;
    }

    std::cout << "程序结束。" << std::endl;
    return 0;
}
