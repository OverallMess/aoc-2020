#pragma once
#include "common_includes.h"

namespace helpers
{
	template<typename T>
	bool vec_contains(const std::vector<T>& vec, const T& target)
	{
		return std::any_of(vec.begin(), vec.end(), [&](const T& str) {
			return target == str;
		});
	}

	bool getline_ss(std::istream& in, std::stringstream& ss, char delim)
	{
		std::string temp;
		const auto& ret = std::getline(in, temp, delim);
		ss.clear();
		ss.str(temp);
		return static_cast<bool>(ret);
	}

	void trim(std::string& str, const std::string& whitespace = " ")
	{
		const size_t str_begin = str.find_first_not_of(whitespace);

		if (str_begin == std::string::npos)
			return;

		const size_t str_end = str.find_last_not_of(whitespace) + 1;
		const size_t str_range = str_end - str_begin;
		str = str.substr(str_begin, str_range);
	}

	void trim_end(std::string& str, const std::string& whitespace = " ")
	{
		const size_t str_end = str.find_last_not_of(whitespace) + 1;
		const size_t str_range = str_end;
		str = str.substr(0, str_range);
	}
}