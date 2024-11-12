#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

int main() {
    char str[500] = "Karen knew keeping the kitchen clean was key, but Kevin kept knocking things over, creating a mess. Meanwhile, the kids continued kicking a ball in the backyard, blissfully unaware of the chaos inside.";
    char* context = nullptr;
    char* curWord = strtok_s(str, " ,.", &context);  

    cout << "Words starting with 'k' or 'K':" << endl;

    while (curWord) {
        if (curWord[0] == 'k' || curWord[0] == 'K') {
            cout << curWord << endl; 
        }
        curWord = strtok_s(NULL, " .,", &context); 
    }

    return 0;
}
