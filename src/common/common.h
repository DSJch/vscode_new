// common.h - 项目公共头文件
#ifndef COMMON_H
#define COMMON_H

// 标准库头文件
#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <chrono>
#include <fstream>
#include <sstream>
#include <random>
#include <type_traits>
#include <execution> // 并行算法支持
#include <cstdlib>
#include <filesystem>

// 是否使用标准库
constexpr bool USE_STANDARD_LIBRARY = true;

inline std::string getProjectRoot() {
	const char *envRoot = std::getenv("PROJECT_ROOT");
	if (envRoot != nullptr && std::filesystem::path(envRoot).is_absolute()) {
		return std::string(envRoot);
	}
	return "";
}

// 测试规模常量
constexpr int MAX_TEST_SIZE = 1000000;
constexpr int TEST_SIZE_FOR_BUBBLE = 10000;

// 是否默认输入测试规模
constexpr bool DEFAULT_INPUT_TEST_SIZE = false;

// 错误码常量
constexpr int ERRNO_ALGORITHM_INIT_FAILED = 1;		// 算法初始化失败
constexpr int ERRNO_ALGORITHM_NAME_MISMATCH = 2;	// 算法数量与算法名称数量不匹配
constexpr int ERRNO_TEST_SIZE_INVALID = 3;			// 测试规模无效
constexpr int ERRNO_TEST_SIZE_EXCEED_MAX = 4;		// 测试规模超过最大值
constexpr int ERRNO_TEST_SIZE_POSITIVE_INTEGER = 5; // 测试规模必须是正整数

// 算法类型枚举
enum AlgorithmType {
	QUICK_SORT = 0,	 // 快速排序
	HEAP_SORT,		 // 堆排序
	MERGE_SORT,		 // 归并排序
	BUBBLE_SORT,	 // 冒泡排序
	INSERTION_SORT,	 // 插入排序
	PARALLEL_SORT,	 // 并行排序
	ALGORITHM_COUNT, // 算法数量
};

// 算法名称常量
constexpr std::array<const char *, ALGORITHM_COUNT> ALGORITHM_NAMES = {"快速排序", "堆排序", "归并排序", "冒泡排序", "插入排序", "并行排序"};

#endif // COMMON_H
