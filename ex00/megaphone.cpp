#include <iostream>

int main(int argc, char **v)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    int i = 0;
    int y = 1;
    while (y < argc)
    {
        i = 0;
        while (v[y][i])
        {
            v[y][i] = toupper(v[y][i]);
            i++;
        }
        std::cout << v[y];
        y++;
    }
    std::cout << "\n";
}