#include<iostream>
#include<string>
#include<vector>
#include <sstream>

class CException: public std::exception
{
	private:
        std::string message;

	public:
		explicit CException(const char* _msg) : message(_msg) {}

		const char* what() const noexcept override
		{
			return message.c_str();
		}
};

typedef std::pair<std::string, std::string> Query;

std::string trim_input(const std::string& _string_to_trim)
{
    // Position of the first non-whitespace character
    std::string_view string_view(_string_to_trim);
	size_t start = string_view.find_first_not_of(" \t\n\r");

    // If there is no non-whitespace character throw an exception
	if (start == std::string_view::npos) {
        throw CException("Invalid string!");
	}

    // Position of the last non-whitespace character
    size_t end = _string_to_trim.find_last_not_of(" \t\n\r");

    // Trim the string from the starting position for a specified length
    return _string_to_trim.substr(start, end - start + 1);
}

std::vector<Query> split_string(const std::string& _string_to_split)
{
    std::istringstream ss(trim_input(_string_to_split));
    std::string token;
    std::vector<Query> queries;

    while (std::getline(ss, token, '&')) {
        std::istringstream token_ss(token);
        std::string key, value;

        if (std::getline(token_ss, key, '=') && std::getline(token_ss, value)) {
            Query query(key, value);
            queries.emplace_back(query);
        } else {
            throw CException("Invalid string!");
        }
    }

    return queries;
}

int main()
{
	try {
        const std::string& input = "a=1&b=2&c=3";
        std::cout << "Input: " << input << std::endl;

        const std::vector<Query>& tokens = split_string(input);

        for (const auto& token : tokens) {
            std::cout << "{" << token.first << ": " << token.second << "}" << std::endl;
        }
    } catch (CException& exc) {
        std::cerr << exc.what() << std::endl;
	}

	return 0;
}
