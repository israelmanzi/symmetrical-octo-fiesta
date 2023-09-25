//  Query Parser (Imitation of js implementation in CPP; Location: ./index.js)

#include<iostream>
#include<string>
#include<vector>

class CException: public std::exception
{
	private:
		const char *message;

	public:
		explicit CException(const char* _msg) : message(_msg) {}

		const char *to_string()
		{
			return message;
		}
};

std::string trim_input(const std::string& _string_to_trim)
{
    // Position of the first non-whitespace character
	size_t start = _string_to_trim.find_first_not_of(" \t\n\r");

    // If there is no non-whitespace character throw an exception
	if (start == std::string::npos) {
        throw CException("Invalid string!");
	}

    // Position of the last non-whitespace character
    size_t end = _string_to_trim.find_last_not_of(" \t\n\r");
    size_t length = end - start + 1; // Length of the string without whitespace characters

    // Trim the string from the starting position for a specified length
    return _string_to_trim.substr(start, length);
}

std::vector<std::string> split_string(const std::string& _string_to_split)
{
    // Trim the string from whitespace characters
    const std::string& trimmed_string = trim_input(_string_to_split);
    const std::string& delimiter = "&";

    // If the string is empty return an empty vector
    size_t start = 0, end, delimiter_length = delimiter.length();
    std::string token;
    std::vector<std::string> tokens;

    // Split the string by the delimiter
    while ((end = trimmed_string.find(delimiter, start)) != std::string::npos) {
        token = trimmed_string.substr(start, end - start);

        // If the token is empty throw an exception
        if (token.empty()) {
            throw CException("Invalid string!");
        }

        tokens.push_back(token);
        start = end + delimiter_length;
    }

    // Add the last token
    token = trimmed_string.substr(start);
    tokens.push_back(token);

    return tokens;
}

int main()
{
	try {
        const std::string& input = "a=1&b=2&c=3";
        const std::vector<std::string>& tokens = split_string(input);

        for (const std::string& token : tokens) {
            std::cout << token << std::endl;
        }
    } catch (CException& exc) {
        std::cerr << exc.to_string() << std::endl;
	}

	return 0;
}
