#pragma once
#include "common_includes.h"

struct position
{
	int x, y;
	void move(int dx, int dy, size_t size)
	{
		x += dx;
		x %= size;
		y += dy;
	}
};

static void part1(std::istream& in)
{
	position pos{};

	std::cout << std::count_if(
		std::istream_iterator<std::string>(in),
		std::istream_iterator<std::string>(),
		[&pos](const std::string& str)
		{
			bool ret = str[pos.x] == '#';
			pos.move(3, 1, str.size());
			return ret;
		}
	);
}

static void part2(std::istream& in)
{
	std::map<std::pair<size_t, size_t>, size_t> positions{
		{ { 1, 1 }, 0 },
		{ { 3, 1 }, 0 },
		{ { 5, 1 }, 0 },
		{ { 7, 1 }, 0 },
		{ { 1, 2 }, 0 },
	};
	std::array<size_t, 5> freqs{};
	std::ranges::for_each(
		std::ranges::istream_view<std::string>(in),
		[&, curr_line = 0](const std::string& str) mutable {
			uint8_t current_idx = 0;
			for (auto& pos : positions) {
				if (curr_line % pos.first.second == 0) {
					freqs[current_idx] += str[pos.second] == '#';
					pos.second += pos.first.first;
					pos.second %= str.size();
				}
				++current_idx;
			}
			++curr_line;
		}
	);
	std::cout << std::reduce(freqs.begin(), freqs.end(), 1ul, std::multiplies<size_t>{});
}