#include "file_utils.hpp"

void read_lines_from_file(std::string fileName, std::function<void(std::string)> func);

std::list<int> read_ints_from_file(std::string fileName)
{
    std::list<int> result;
    read_lines_from_file(
        fileName,
        [&result](std::string line)
        {
            result.push_back(std::stoi(line));
        });
    return result;
}

std::list<std::string> read_strings_from_file(std::string fileName)
{
    std::list<std::string> result;
    read_lines_from_file(
        fileName,
        [&result](std::string line)
        {
            result.push_back(line);
        });
    return result;
}

void read_lines_from_file(std::string fileName, std::function<void(std::string)> func)
{
    std::ifstream myfile(fileName);
    std::string line;

    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            func(line);
        }
        myfile.close();
    }
    else
    {
        std::cout << "Couldn't open file" << std::endl;
    }
}