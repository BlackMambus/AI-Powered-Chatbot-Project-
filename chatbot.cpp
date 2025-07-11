#include <iostream>
#include <string>
#include <algorithm>
#include <map>

// Convert string to lowercase
std::string toLower(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

// Simple rule-based response engine
std::string getResponse(const std::string& input) {
    static std::map<std::string, std::string> knowledgeBase = {
        {"hello", "Hi there! How can I help you today?"},
        {"how are you", "I'm just a bunch of code, but I'm doing great!"},
        {"bye", "Goodbye! Have a great day!"},
        {"your name", "I'm a simple C++ chatbot."}
    };

    std::string lowerInput = toLower(input);
    for (const auto& pair : knowledgeBase) {
        if (lowerInput.find(pair.first) != std::string::npos) {
            return pair.second;
        }
    }

    return "I'm not sure how to respond to that.";
}

int main() {
    std::string userInput;

    std::cout << "🤖 Chatbot: Hello! Type 'bye' to exit.\n";

    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        if (toLower(userInput) == "bye") {
            std::cout << "🤖 Chatbot: " << getResponse(userInput) << "\n";
            break;
        }

        std::string response = getResponse(userInput);
        std::cout << "🤖 Chatbot: " << response << "\n";
    }

    return 0;
}



