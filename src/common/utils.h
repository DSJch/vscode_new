#ifndef UTILS_H
#define UTILS_H

#include "common.h"
#include <iomanip>  // 用于 std::setprecision

namespace Utils {

// 生成随机数组
template <typename T>
void generateRandomArray(std::vector<T>& arr, size_t size, T min = 0, T max = 100000) {
    std::random_device rd;
    std::mt19937 gen(rd());

    if constexpr (std::is_integral_v<T>) {
        std::uniform_int_distribution<T> dist(min, max);
        arr.resize(size);
        for (auto& elem : arr) {
            elem = dist(gen);
        }
    } else if constexpr (std::is_floating_point_v<T>) {
        std::uniform_real_distribution<T> dist(min, max);
        arr.resize(size);
        for (auto& elem : arr) {
            elem = dist(gen);
        }
    }
}

// 验证数组是否有序
template <typename T>
bool isSorted(const std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// 打印数组
template <typename T>
void printArray(const std::vector<T>& arr, size_t limit = 20) {
    size_t size = std::min(arr.size(), limit);
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    if (arr.size() > limit) {
        std::cout << ", ...";
    }
    std::cout << std::endl;
}

// 输入验证：检查是否为正整数
bool isValidPositiveInteger(const std::string& input);

// 输入数组长度
int inputArrayLength();

// 输入数组元素（通用模板）
template <typename T>
void inputElements(std::vector<T>& arr) {
    std::cout << "请输入数组元素（空格分隔）：";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    T element;
    while (iss >> element) {
        arr.push_back(element);
    }
}

// 测试算法性能
template <typename T, typename F>
void testAlgorithm(const std::string& name, F sortFunc, std::vector<T> arr) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << name << " 时间: " << elapsed.count() << " 秒" << std::endl;
}

// 测试算法并返回执行时间（秒）
template <typename T, typename F>
double testAlgorithmReturnTime(const std::string& name, F sortFunc, std::vector<T> arr) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << name << " 时间: " << elapsed.count() << " 秒" << std::endl;
    return elapsed.count();
}

} // namespace Utils

// CSV 输出工具类
class CSVExporter {
public:
    CSVExporter(const std::string &filename) : filename(filename) {
        file.open(filename, std::ios::out);
        if (!file.is_open()) {
            std::cerr << "Error: 无法打开文件 " << filename << std::endl;
        }
    }

    ~CSVExporter() {
        if (file.is_open()) {
            file.close();
        }
    }

    // 写入表头
    void writeHeader(const std::vector<std::string> &headers) {
        if (!file.is_open()) return;
        for (size_t i = 0; i < headers.size(); ++i) {
            if (i > 0) file << ",";
            file << headers[i];
        }
        file << "\n";
    }

    // 写入一行数据
    void writeRow(const std::vector<std::string> &data) {
        if (!file.is_open()) return;
        for (size_t i = 0; i < data.size(); ++i) {
            if (i > 0) file << ",";
            file << data[i];
        }
        file << "\n";
    }

    // 写入一行数据（整数）
    void writeRow(const std::vector<int> &data) {
        if (!file.is_open()) return;
        for (size_t i = 0; i < data.size(); ++i) {
            if (i > 0) file << ",";
            file << data[i];
        }
        file << "\n";
    }

    // 写入一行数据（浮点数）
    void writeRow(const std::vector<double> &data) {
        if (!file.is_open()) return;
        for (size_t i = 0; i < data.size(); ++i) {
            if (i > 0) file << ",";
            // 特殊处理：-1 表示该算法未测试（跳过），显示为空
            if (data[i] < 0) {
                file << "";
            } else {
                // 使用固定精度输出，避免科学计数法
                file << std::fixed << std::setprecision(8) << data[i];
            }
        }
        file << "\n";
    }

    // 关闭文件
    void close() {
        if (file.is_open()) {
            file.close();
        }
    }

private:
    std::string filename;
    std::ofstream file;
};

#endif // UTILS_H
