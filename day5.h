#pragma once
#include "common_includes.h"

[[nodiscard]]
static size_t calculate(
	std::string& str,
	const std::string::iterator& beg,
	const std::string::iterator& end,
	char c)
{
	std::string::iterator it = beg;

	size_t left = 0;
	size_t right = std::pow(2, std::distance(beg, end));

	for (; it != end; ++it)
	{
		if (*it == c)
			right = std::floor((left + right) / 2);
		else
			left = std::ceil((left + right) / 2);
	}

	return *(it - 1) == c ? right : left;
}

static void part1(std::istream& in)
{
	std::string line;
	size_t max_id = 0;

	while (std::getline(in, line))
	{
		size_t col = calculate(line, line.begin(), line.end() - 3, 'F') - 1;
		size_t row = calculate(line, line.end() - 3, line.end(), 'L');

		max_id = std::max(col * 8 + row, max_id);
	}

	std::cout << max_id - 1 << std::endl;
}