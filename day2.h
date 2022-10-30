#pragma once
#include "common_includes.h"

struct Line
{
	int min;
	int max;
	char c;
	std::string str;
};

static std::istream& operator>>(std::istream& is, Line& output)
{
	char garbage;
	is >> output.min
		>> garbage
		>> output.max
		>> output.c
		>> garbage
		>> output.str;
	return is;
}

static void part_1(std::istream& in)
{
	std::cout << std::count_if(
		std::istream_iterator<Line>(in),
		std::istream_iterator<Line>(),
		[](const Line& line) {
			auto freq = std::count_if(line.str.begin(), line.str.end(), [&line](char c) {
				return line.c == c;
				});
			return freq >= line.min && freq <= line.max;
		}
	) << std::endl;
}

static void part_2(std::istream& in)
{
	std::wcout << std::count_if(
		std::istream_iterator<Line>(in),
		std::istream_iterator<Line>(),
		[](const Line& line) {
			return line.str[line.min - 1] != line.str[line.max - 1] &&
				(line.str[line.min - 1] == line.c || line.str[line.max - 1] == line.c);
		}
	) << std::endl;
}