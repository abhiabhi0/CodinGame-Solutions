#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int calculate_heist_time(std::vector<int>& vault_time, int num_of_robbers)
{
    std::vector<int> robber_time(num_of_robbers, 0);

    int vaults_opened = 0;
    for (int i = 0; i < num_of_robbers; ++i)
    {
        robber_time[i] += vault_time[vaults_opened];
        vaults_opened++;
    }
    
    while (vaults_opened < vault_time.size())
    {
        std::sort(robber_time.begin(), robber_time.end());

        robber_time[0] += vault_time[vaults_opened];
        vaults_opened++;
    }

    auto total_time = std::max_element(robber_time.begin(), robber_time.end());

    return *total_time;
}

int main()
{
    int R;
    std::cin >> R; std::cin.ignore();
    int V;
    std::cin >> V; std::cin.ignore();
    
    std::vector<int> vault_time(V, 0);
    
    for (int i = 0; i < V; ++i) 
    {
        int C;
        int N;
        std::cin >> C >> N; std::cin.ignore();
        vault_time[i] += pow(10, N) * pow(5, C-N);
    }
    
    std::cout << calculate_heist_time(vault_time, R) << "\n";
}
