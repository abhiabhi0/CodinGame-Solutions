#include <iostream>
#include <string>
#include <vector>
#include <limits>

int shortest_path_map_index(std::vector< std::vector<std::string> >& maps, int start_row, int start_col, 
                            int num_maps, int width, int height)
{
    int index = -1;
    int shortest_distance = std::numeric_limits<int>::max();

    for (int i = 0; i < num_maps; ++i)
    {
        int count = 0;
        int next_row = start_row;
        int next_col = start_col;
        while(1)
        {

            if (count >= shortest_distance) //current map does not have shortest distance, so break
            {
                break;
            }

            if (maps[i][next_row][next_col] == '^') // Up
            {
                next_row = next_row - 1;
                count++;
            }
            else if (maps[i][next_row][next_col] == 'v') // Down
            {
                next_row = next_row + 1;
                count++;
            }
            else if (maps[i][next_row][next_col] == '<') // Left
            {
                next_col = next_col - 1;
                count++;
            }
            else if (maps[i][next_row][next_col] == '>') // Right
            {
                next_col = next_col + 1;
                count++;
            }
            else if (maps[i][next_row][next_col] == '.' || maps[i][next_row][next_col] == '#') // empty sqaure or wall
            {
                break;
            }

            if (next_row == start_row && next_col == start_col)//forms loop, so break
            {
                break;
            }
            else if (next_row < 0 || next_row >= width)//exceeding boundary(width)
            {
                break;
            }
            else if (next_col < 0 || next_col >= height)//exceeding boundary(height)
            {
                break;
            }

            if (maps[i][next_row][next_col] == 'T')//finds treasure
            {
                count++;
                if (shortest_distance > count)
                {
                    index = i;
                    shortest_distance = count;
                }
                break;
            }
        }
    }
    return index;
}

int main()
{
    int w;
    int h;
    std::cin >> w >> h; std::cin.ignore();
    int start_row;
    int start_col;
    std::cin >> start_row >> start_col; std::cin.ignore();
    int n;
    std::cin >> n; std::cin.ignore();

    std::vector< std::vector<std::string> > maps(n, std::vector<std::string>(h));
    for (int i = 0; i < n; i++) 
    {
        std::vector<std::string> map(h);

        for (int j = 0; j < h; j++) 
        {
            std::string map_row;
            std::getline(std::cin, map_row);
            map[j] = map_row;
        }
        maps[i] = map;
    }

    int map_index = shortest_path_map_index(maps, start_row, start_col, n, w, h);
    if (map_index == -1)
    {
        std::cout << "TRAP\n";
    }
    else
    {
        std::cout << map_index << "\n";
    }
}
