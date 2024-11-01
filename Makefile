# Makefile for automating the build and run process

# 编译器
CXX = g++
# 编译标志
CXXFLAGS = -std=c++11
# 目标文件名称
TARGET1 = final1
TARGET2 = final2
# 源文件
SRC1 = 1utm_to_geo.cpp datum.cpp utm.cpp
SRC2 = 2geo_to_utm.cpp datum.cpp utm.cpp
# 生成文件路径
OUTPUT_DIR = output

# 目标1：编译 final1
$(TARGET1): $(SRC1)
	$(CXX) $(CXXFLAGS) -o $(TARGET1) $(SRC1)

# 目标2：编译 final2
$(TARGET2): $(SRC2)
	$(CXX) $(CXXFLAGS) -o $(TARGET2) $(SRC2)

# 执行 final1 并输出结果到指定目录
run1: $(TARGET1)
	./$(TARGET1)
	@echo "final1 执行完成，结果已生成到 $(OUTPUT_DIR)/经纬度坐标.txt"

# 执行 final2 并输出结果到指定目录
run2: $(TARGET2)
	./$(TARGET2)
	@echo "final2 执行完成，结果已生成到 $(OUTPUT_DIR)/UTM坐标.txt"

# 清理生成的可执行文件和输出
clean:
	rm -f $(TARGET1) $(TARGET2)
	rm -f $(OUTPUT_DIR)/*.txt
	@echo "已清理所有生成的文件。"

# 默认目标，编译和运行
all: $(TARGET1) $(TARGET2) run1 run2
