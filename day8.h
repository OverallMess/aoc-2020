#pragma once
#include "common_includes.h"
#include "helpers.h"
struct operation_pair
{
	std::string op;
	int32_t value;
	bool flag;
};

std::istream& operator>>(std::istream& in, operation_pair& pair)
{
	in >> pair.op >> pair.value;
	return in;
}

static void part1(std::istream& in)
{
	size_t num_lines = helpers::count_lines(in, 1024);
	in.clear(); in.seekg(0);

	std::vector<operation_pair> operations;
	operations.reserve(num_lines);

	std::copy(
		std::istream_iterator<operation_pair>(in),
		std::istream_iterator<operation_pair>(),
		std::back_inserter(operations)
	);

	int32_t accumulator = 0;
	uint32_t ptr = 0;

	std::unordered_map<std::string, std::function<void(void)>> map;

	map["nop"] = [&ptr]() { ++ptr; };
	map["jmp"] = [&]() { ptr += operations[ptr].value; };
	map["acc"] = [&]() { accumulator += operations[ptr++].value; };

	while (true)
	{
		if (operations[ptr].flag) break;

		operations[ptr].flag = true;

		map[operations[ptr].op]();
	}

	std::cout << accumulator;
}
