#include <iostream>
#include <vector>
#include <limits>

int largest_loss(std::vector<int>& values)
{
    int loss = std::numeric_limits<int>::max();

    int maxima = std::numeric_limits<int>::min();
    int minima = std::numeric_limits<int>::max();
    int maxima_index = 0, minima_index = 0;

    int i = 0;
 
    int j = i+1;

    while (j < values.size())
    {
        if (values[i] > values[j])
        {
            int local_loss = values[j] - values[i];

            if (local_loss < loss)
            {
                loss = local_loss;
                if (values[i] >= maxima)
                {
                    maxima = values[i];
                    maxima_index = i;
                    minima = values[j];
                    minima_index = j;
                }
            }

        }
        else if (values[i] < values[j])
        {
            i = j;
            j = i;
        }
        j++;
    }
    loss = values[minima_index] - values[maxima_index];
    return loss;
}

int main()
{
    int n;
    std::cin >> n; std::cin.ignore();
    std::vector<int> values(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i]; 
        std::cin.ignore();
    }

    int loss = largest_loss(values);

    std::cout << loss << std::endl;
}
