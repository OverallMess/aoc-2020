#pragma once
#include "common_includes.h"


static void part1(std::istream& in)
{
	std::unordered_set<size_t> set;
	std::string line;
	size_t total = 0;

	while (std::getline(in, line))
	{
		if (line.empty())
		{
			total += set.size();
			set.clear();
		}
		else
		{
			for (const char c : line)
			{
				set.insert((int)c);
			}
		}
	}

	total += set.size();

	std::cout << total << std::endl;
}


static void part2(std::istream& in)
{
	std::unordered_set<size_t> set;
	std::string line;
	size_t total = 0;
	bool added = false;

	while (std::getline(in, line))
	{
		if (line.empty())
		{
			added = false;
			total += set.size();
			set.clear();
		}
		else
		{
			if (!added)
			{
				added = true;
				for (const char c : line)
					set.insert((int)c);
				continue;
			}

			std::erase_if(set, [&line](size_t val) {
				return std::find(line.begin(), line.end(), val) == line.end();
			});
		}
	}

	total += set.size();

	std::cout << total << std::endl;

}
