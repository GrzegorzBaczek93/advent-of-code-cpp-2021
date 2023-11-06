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
    int result = 0;
    int previous = -1;

    std::list<int> list = read_ints_from_file("input.txt");

    for (int const &i : list)
    {
        if (previous == -1)
        {
            previous = i;
        }
        else
        {
            if (previous < i)
            {
                result++;
            }
            previous = i;
        }
    }
    return result;
}

int second_solution()
{
    int result = 0;
    int previous = -1;
    std::list<int> list = read_ints_from_file("input.txt");
    auto iterator = list.begin();

    for (int i = 0; i < list.size() - 2; i++)
    {
        int sum = *iterator + *std::next(iterator, 1) + *std::next(iterator, 2);

        if (previous == -1)
        {
            previous = sum;
        }
        else
        {
            if (previous < sum)
            {
                result++;
            }
            previous = sum;
        }

        iterator++;
    }
    return result;
}