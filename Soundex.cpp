/*
#include "Soundex.h"
#include <cctype>

char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}
*/

#include "Soundex.h"
#include <unordered_map>
#include <cctype>

char encodeChar(char c) {
    static const std::unordered_map<char, char> soundex_map = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'}, {'L', '4'},
        {'M', '5'}, {'N', '5'}, {'R', '6'}
    };
    
    char upper_c = std::toupper(c);
    auto it = soundex_map.find(upper_c);
    return it != soundex_map.end() ? it->second : '0';
}

std::string removeConsecutiveDuplicates(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (result.empty() || result.back() != c) {
            result += c;
        }
    }
    return result;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "0000";

    char first_letter = std::toupper(name[0]);

    std::string encoded;
    for (size_t i = 1; i < name.size(); ++i) {
        char code = encodeChar(name[i]);
        if (code != '0') {
            encoded += code;
        }
    }

    encoded = removeConsecutiveDuplicates(encoded);

    std::string soundex_code = first_letter + encoded;
    soundex_code = soundex_code.substr(0, 4);
    soundex_code.resize(4, '0');

    return soundex_code;
}
