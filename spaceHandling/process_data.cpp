//g++ process_data.cpp -o process_data

#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::string input_file = "UTM坐标1加偏移量.txt";  // 输入文件名
    std::string output_file = "output_cpp.txt";  // 输出文件名

    std::ifstream infile(input_file);
    std::ofstream outfile(output_file);

    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "无法打开文件。" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string x, y;

        // 读取两个数值
        if (iss >> x >> y) {
            // 格式化为 "x,y" 格式并写入输出文件
            outfile << x << "," << y << std::endl;
        }
    }

    infile.close();
    outfile.close();

    std::cout << "数据处理完成，结果已保存到 " << output_file << std::endl;

    return 0;
}
