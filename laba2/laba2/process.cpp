#include <string>
#include <locale.h>
#include "process.h"

using namespace std;

string process(char text[], int length) {
    setlocale(LC_ALL, "RU");
    string input = text;
    input.pop_back();
    string shortest_word = "";
    string current_word = "";
    for (int i = 0; i < length; i++) {
        if (i == length || input[i] == ' ') {
            if (current_word.length() > 0) {
                if (shortest_word.length() == 0 || current_word.length() < shortest_word.length()) {
                    shortest_word = current_word;
                }
                current_word = "";
            }
        }
        else {
            current_word += input[i];
        }
    }
    string result = shortest_word + " " + input + " " + shortest_word;
    return result;
}