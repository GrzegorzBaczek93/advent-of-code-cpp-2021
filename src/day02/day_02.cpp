#include <file_utils.hpp>
#include <iostream>
#include <list>
#include <string>

int first_solution();
int second_solution();

int main()
{
    std::cout << "Result for first solution: " << first_solution() << std::endl;
    std::cout << "Result for second solution: " << second_solution() << std::endl;

    return 0;
}

int first_solution()
{
    std::list<std::string> list = read_strings_from_file("input.txt");
    int length = 0;
    int depth = 0;

    for (auto const &i : list)
    {
        switch (i[0])
        {
        case 'f':
            length += (i[8] - 48);
            break;
        case 'u':
            depth -= (i[3] - 48);
            break;
        case 'd':
            depth += (i[5] - 48);
            break;
        default:
            std::cout << "Unsupported opperation" << std::endl;
        }
    }

    return length * depth;
}

int second_solution()
{
    std::list<std::string> list = read_strings_from_file("input.txt");
    int length = 0;
    int depth = 0;
    int aim = 0;

    for (auto const &i : list)
    {
        switch (i[0])
        {
        case 'f':
            length += (i[8] - 48);
            depth += aim * (i[8] - 48);
            break;
        case 'u':
            aim -= (i[3] - 48);
            break;
        case 'd':
            aim += (i[5] - 48);
            break;
        default:
            std::cout << "Unsupported opperation" << std::endl;
        }
    }

    return length * depth;
}