#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct KeyValue {
    char key[100];
    char value[100];
};

struct KeyValue* parseQuery(const char* input, int* size) {
    if (input == NULL || strlen(input) == 0) {
        *size = 0;
        return NULL;
    }

    char* token;
    char* inputCopy = strdup(input);
    token = strtok(inputCopy, "&");

    struct KeyValue* result = (struct KeyValue*)malloc(sizeof(struct KeyValue) * 100);
    *size = 0;

    while (token != NULL) {
        char* subtoken;
        char* key, *value;
        subtoken = strtok(token, "=");
        key = subtoken;
        subtoken = strtok(NULL, "=");
        value = subtoken;

        if (key != NULL && value != NULL) {
            strcpy(result[*size].key, key);
            strcpy(result[*size].value, value);
            (*size)++;
        }

        token = strtok(NULL, "&");
    }

    free(inputCopy);
    return result;
}

int main() {
    const char* input = "key1=value1&key2=value2&key3=value3";
    int size;
    struct KeyValue* keyValuePairs = parseQuery(input, &size);

    for (int i = 0; i < size; i++) {
        printf("Key: %s, Value: %s\n", keyValuePairs[i].key, keyValuePairs[i].value);
    }

    free(keyValuePairs);
    return 0;
}