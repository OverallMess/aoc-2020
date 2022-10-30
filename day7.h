#pragma once
#include "common_includes.h"
#include "helpers.h"

static auto parse_input_1(std::istream& in)
{
	std::unordered_map<std::string, std::vector<std::string>> bag_mapping;
	std::string line;
	while (std::getline(in, line))
	{
		size_t idx = line.find("contain");
		std::string field = line.substr(0, idx - 1);
		helpers::trim_end(field, "s");

		std::stringstream other;

		other.str(line.substr(idx + sizeof("contain")));

		std::vector<std::string> contained_bags;
		std::string bag_type;
		while (std::getline(other, bag_type, ','))
		{
			std::erase_if(bag_type, ::isdigit);
			helpers::trim(bag_type);
			helpers::trim_end(bag_type, ".");
			helpers::trim_end(bag_type, "s");

			contained_bags.emplace_back(bag_type);
		}
		bag_mapping[field] = contained_bags;
	}

	return bag_mapping;
}


static bool check_contains(
	const std::unordered_map<std::string, std::vector<std::string>>& map,
	const std::vector<std::string>& vec,
	const std::string& target
)
{
	std::stack<std::vector<std::string>> stack;
	stack.push(vec);

	while (!stack.empty())
	{
		if (helpers::vec_contains(stack.top(), target))
			return true;

		const std::vector<std::string> vec = std::move(stack.top());
		stack.pop();
		for (const std::string& str : vec)
			if (str != "no other bag")
				stack.push(map.at(str));
	}
	return false;
}

static void part1(std::istream& in)
{
	auto mapping = parse_input_1(in);

	std::string target = "shiny gold bag";
	size_t result = 0;

	for (const auto& [k, v] : mapping)
		result += check_contains(mapping, v, target);

	std::cout << result;
}

//static auto parse_input_2(std::istream& in)
//{
//	std::unordered_map<std::string, std::vector<std::string>> bag_mapping;
//	std::string line;
//	while (std::getline(in, line))
//	{
//		size_t idx = line.find("contain");
//		std::string field = line.substr(0, idx - 1);
//		helpers::trim_end(field, "s");
//
//		std::stringstream other;
//
//		other.str(line.substr(idx + sizeof("contain")));
//
//		std::vector<std::string> contained_bags;
//		std::string bag_type;
//		while (std::getline(other, bag_type, ','))
//		{
//			std::erase_if(bag_type, ::isdigit);
//			helpers::trim(bag_type);
//			helpers::trim_end(bag_type, ".");
//			helpers::trim_end(bag_type, "s");
//
//			contained_bags.emplace_back(bag_type);
//		}
//		bag_mapping[field] = contained_bags;
//	}
//
//	return bag_mapping;
//}

static void part2(std::istream& in)
{
	//auto mapping = parse_input_2(in);

	/*std::string target = "shiny gold bag";
	size_t result = 0;

	for (const auto& [k, v] : mapping)
		result += check_contains(mapping, v, target);

	std::cout << result;*/
}
