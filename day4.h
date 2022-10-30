#pragma once
#include "common_includes.h"
#include "helpers.h"

static bool is_passport_valid(std::unordered_map<std::string, std::string>& map)
{
	constexpr size_t all_fields = 8;
	return map.size() == all_fields || (map.size() == all_fields - 1 && map.find("cid") == map.end());
}

static bool is_passport_valid_2(std::unordered_map<std::string, std::string>& map)
{
	//if (!is_passport_valid(map)) return false;

	//if (
	//	!(map["byr"].size() == 4 && std::stoi(map["byr"]) >= 1920 && std::stoi(map["byr"]) <= 2002) ||
	//	!(map["iyr"].size() == 4 && std::stoi(map["iyr"]) >= 2010 && std::stoi(map["iyr"]) <= 2020) ||
	//	!(map["eyr"].size() == 4 && std::stoi(map["eyr"]) >= 2020 && std::stoi(map["eyr"]) <= 2030)
	//) return false;

	size_t idx = map["hgt"].find_first_of("cm");
	std::string unit = map["hgt"].substr(idx);
	size_t val = std::stoi(map["hgt"].substr(0, idx));

	if (unit == "cm")
		return (!(val >= 150 && val <= 193));
	else if (unit == "in")
		return (!(val >= 59 && val <= 76));

	return true;
}

static void part1(std::istream& in)
{
	std::stringstream line;
	std::unordered_map<std::string, std::string> map;
	size_t num_valid = 0;

	while (getline_ss(in, line, '\n'))
	{
		if (line.str().empty())
		{
			num_valid += is_passport_valid(map);
			map.clear();
		}
		else
		{
			std::stringstream field;
			std::string field_name, field_val;
			while (getline_ss(line, field, ' '))
			{
				std::getline(field, field_name, ':');
				std::getline(field, field_val);
				map[field_name] = field_val;
			}
		}
	}

	num_valid += is_passport_valid(map);

	std::cout << num_valid << std::endl;
}