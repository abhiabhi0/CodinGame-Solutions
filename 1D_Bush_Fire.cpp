#include <iostream>
#include <string>

int min_drops(std::string& strip)
{
    int drops = 0;

    for (int i = 0; i < strip.length();)
    {
        if (strip[i] == 'f')
        {
            if (i < strip.length()-2 && strip[i+2] == 'f')
            {
                drops++;
                i = i+3;
            }
            else if (i < strip.length()-1 && strip[i+1] == 'f')
            {
                drops++;
                i = i+2;
            }
            else
            {
                drops++;
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return drops;
}

int main()
{
    int N;
    std::cin >> N; std::cin.ignore();
    
    while (N--)
    {
        std::string strip;
        getline(std::cin, strip);

        int res = min_drops(strip);
        std::cout << res << "\n";
    }
}
