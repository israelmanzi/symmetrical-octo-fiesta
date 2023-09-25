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

int main()
{
	try {
        const std::string input = "    What a world this is!";

        std::string output = trim_input(input);

        std::cout << "Original string: <" << input << ">" << std::endl;
        std::cout << "Trimmed string: <" << output << ">" << std::endl;
    } catch (CException& exc) {
        std::cerr << exc.to_string() << std::endl;
	}

	return 0;
}
