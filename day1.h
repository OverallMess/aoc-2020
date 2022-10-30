#pragma once
#include "common_includes.h"

static void part_1(std::istream& in)
{
	constexpr size_t target_num = 2020;
	std::unordered_set<int> set;
	std::ranges::transform(
		std::ranges::istream_view<std::string>(in),
		std::inserter(set, set.end()),
		[](auto str) {
			return std::stoi(str);
		}
	);

	auto it = std::find_if(set.begin(), set.end(), [target_num, &set](const int num) {
		return set.find(target_num - num) != set.end();
		});

	std::cout << "Multiplication result: " << (*it * (target_num - *it)) << std::endl;
}

static void part_2(std::istream& in)
{
	constexpr size_t target_num = 2020;
	std::unordered_set<int> numbers;
	std::unordered_set<int>::iterator p1;

	std::ranges::transform(
		std::ranges::istream_view<std::string>(in),
		std::inserter(numbers, numbers.end()),
		[](auto str) {
			return std::stoi(str);
		}
	);

	p1 = numbers.begin();

	while (p1 != std::next(numbers.begin(), numbers.size() / 2))
	{
		auto it = std::find_if(std::next(p1), numbers.end(), [target_num = target_num - *p1, &numbers](const int num) {
			return numbers.find(target_num - num) != numbers.end();
			});

		if (it != numbers.end())
		{
			std::cout << "Multiplication Result: " << (*p1 * *it * (target_num - *it - *p1));
			break;
		}
		p1++;
	}
}