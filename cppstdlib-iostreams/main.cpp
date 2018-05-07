
#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>

#include <fstream>
#include <iomanip>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>

template <typename T, typename Traits = char_traits<T>>
std::basic_ostream<T, Traits>&
NL(std::basic_ostream<T, Traits>& out)
{
    return out << out.widen('\n');
}

template <typename T>
void PrintVector(const std::vector<T>& vector)
{
    for (auto& v : vector)
    {
        std::cout << v << NL;
    }
}


int main()
{
    std::vector<std::string> words;

    //char input[128] = { 0 };
    char input[] = "Jose Fernando Lopez Fernandez Gomez Gutierrez";

    /*std::cout << "Enter message: ";
    std::cin >> std::setw(128) >> input;

    if (std::cin.fail())
    {
        std::cerr << "[Error]: Failed to read user input." << NL;

        return EXIT_FAILURE;
    }*/

    char *singleWord = std::strtok(input, " ");

    while (singleWord)
    {
        words.emplace_back(singleWord);

        singleWord = std::strtok(nullptr, " ");
    }

    PrintVector(words);

    return EXIT_SUCCESS;
}