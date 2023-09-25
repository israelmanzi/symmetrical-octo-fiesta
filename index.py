def parse_query(_input) -> list[tuple[str, str]]:
    """
    Parses a query string into a list of tokens
    """

    # Split the input string by the '&' character
    tokens = _input.split('&')

    result = []

    if not tokens:
        raise Exception("Invalid query string")

    for token in tokens:
        # Split the token by the '=' character
        key, value = token.split('=', 1)
        # If the value is empty, set it to None
        value = value or None

        result.append((key, value))

    return result


if __name__ == '__main__':
    inputQuery = "key1=value1&key2="

    output = parse_query(inputQuery)

    print(output)
