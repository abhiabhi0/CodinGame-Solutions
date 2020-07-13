#include <iostream>
#include <vector>
#include <algorithm>

bool sudoku_validator(std::vector<std::vector<int>>& grid)
{
    bool status = true;
    
    for (int i = 0; i < 9; ++i)
    {
        std::vector<bool> row_values(9, false);
        std::vector<bool> col_values(9, false);
        std::vector<bool> subgrid_values(9, false);

        for (int r = 0; r < 9; ++r)
        {
            if (row_values[grid[r][i] - 1] == false)
            {
                row_values[grid[r][i] - 1] = true;
            }
            else
            {
                status = false;
                return status;
            }
        }

        for (int c = 0; c < 9; ++c)
        {
            if (col_values[grid[i][c] - 1] == false)
            {
                col_values[grid[i][c] - 1] = true;
            }
            else
            {
                status = false;
                return status;
            }
        }

        if (i == 0)
        {
            for (int r_sub = i; r_sub < i+3; ++r_sub)
            {
                for (int c_sub = i; c_sub < i+3; ++c_sub)
                {
                    if (subgrid_values[grid[r_sub][c_sub] - 1] == false)
                    {
                        subgrid_values[grid[r_sub][c_sub] - 1] = true;
                    }
                    else
                    {
                        status = false;
                        return status;
                    }
                }
            }
        }
        else if (i % 3 == 0)
        {
            for (int r_sub = i; r_sub < i+3; ++r_sub)
            {
                for(int c_sub = 0; c_sub < 3; ++c_sub)
                {
                    if (subgrid_values[grid[r_sub][c_sub] - 1] == false)
                    {
                        subgrid_values[grid[r_sub][c_sub] - 1] = true;
                    }
                    else
                    {
                        status = false;
                        return status;
                    }
                }
            }

            std::fill(subgrid_values.begin(), subgrid_values.end(), false);

            for (int r_sub = 0; r_sub < 3; ++r_sub)
            {
                for(int c_sub = i; c_sub < i+3; ++c_sub)
                {
                    if (subgrid_values[grid[r_sub][c_sub] - 1] == false)
                    {
                        subgrid_values[grid[r_sub][c_sub] - 1] = true;
                    }
                    else
                    {
                        status = false;
                        return status;
                    }
                }
            }

            std::fill(subgrid_values.begin(), subgrid_values.end(), false);

            if (i == 6)
            {
                for (int r_sub = i; r_sub < i+3; ++r_sub)
                {
                    for(int c_sub = 3; c_sub < 6; ++c_sub)
                    {
                        if (subgrid_values[grid[r_sub][c_sub] - 1] == false)
                        {
                            subgrid_values[grid[r_sub][c_sub] - 1] = true;
                        }
                        else
                        {
                            status = false;
                            return status;
                        }
                    }
                }

                std::fill(subgrid_values.begin(), subgrid_values.end(), false);

                for (int r_sub = 3; r_sub < 6; ++r_sub)
                {
                    for(int c_sub = i; c_sub < i+3; ++c_sub)
                    {
                        if (subgrid_values[grid[r_sub][c_sub] - 1] == false)
                        {
                            subgrid_values[grid[r_sub][c_sub] - 1] = true;
                        }
                        else
                        {
                            status = false;
                            return status;
                        }
                    }
                }
            }
            std::fill(subgrid_values.begin(), subgrid_values.end(), false);

            for (int r_sub = i; r_sub < i+3; ++r_sub)
            {
                for (int c_sub = i; c_sub < i+3; ++c_sub)
                {
                    if (subgrid_values[grid[r_sub][c_sub] - 1] == false)
                    {
                        subgrid_values[grid[r_sub][c_sub] - 1] = true;
                    }
                    else
                    {
                        status = false;
                        return status;
                    }
                }
            }
        }
    }
    return status;  
}

int main()
{
    std::vector< std::vector<int> > sudoku_grid;
    for (int i = 0; i < 9; i++) 
    {
        std::vector<int> row;
        for (int j = 0; j < 9; j++) 
        {
            int n;
            std::cin >> n; std::cin.ignore();
            row.push_back(n);
        }
        sudoku_grid.push_back(row);
    }

    bool result = sudoku_validator(sudoku_grid);

    if (result)
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "false\n";
    }
    
}
