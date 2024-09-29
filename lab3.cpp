#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string text = "Karen knew keeping the kitchen clean was key, but Kevin kept knocking things over, creating a mess. Meanwhile, the kids continued kicking a ball in the backyard, blissfully unaware of the chaos inside.";
    std::vector<std::string> words;
    std::stringstream ss(text);
    std::string word;

    while (ss >> word) {
        if (word[0] == 'k' || word[0] == 'K') {
            words.push_back(word);
        }
    }

    std::cout << "Words starting with k:" << std::endl;
    for (const auto& w : words) {
        std::cout << w << std::endl;
    }

    return 0;
}
