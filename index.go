package main

import (
	"fmt"
	"strings"
)

type Output struct {
	Key   string
	Value string
}

func parseQuery(input string) []Output {
	if strings.TrimSpace(input) == "" {
		return nil
	}

	parts := strings.Split(input, "&")
	output := []Output{}

	for _, element := range parts {
		keyValue := strings.Split(element, "=")
		if len(keyValue) != 2 {
			continue
		}
		key, value := keyValue[0], keyValue[1]

		if key != "" && value != "" {
			output = append(output, Output{Key: key, Value: value})
		}
	}

	return output
}

func main() {
	input := "key1=value1&key2=value2&key3=value3"
	output := parseQuery(input)
	fmt.Println(output)
}