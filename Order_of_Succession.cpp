/**
One test case is not passed
**/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Details
{
    std::string name;
    std::string parent_name;
    int birth; // year of birth
    std::string death;
    std::string religion;
    std::string gender;
    int index;
    bool has_child = false;
    bool processed = false;

    Details * parent;
    Details * sibling;
    Details * first_child;

    Details(){}

    Details(std::string name_, std::string parent_name_, int birth_, std::string death_, std::string religion_, std::string gender_, int index_):
        name(name_), parent_name(parent_name_), birth(birth_), death(death_), religion(religion_), 
        gender(gender_), index(index_), parent(nullptr), sibling(nullptr), first_child(nullptr) {}
};

void map_siblings(std::vector<int> & male_idx, std::vector<int> & female_idx, std::vector<Details>& family, int curr_ruler_idx)
{
    Details first_child;

    if (!male_idx.empty())
    {
        family[curr_ruler_idx].first_child = &family[male_idx[0]];
        if (male_idx.size() == 1)
        {
            if (!female_idx.empty())
            {
                family[male_idx[0]].sibling = &family[female_idx[0]];
            }
        }
        else
        {
            for (int i = 0; i < male_idx.size()-1; ++i)
            {
                family[male_idx[i]].sibling = &family[male_idx[i+1]];
            }

        }
    }
    else
    {
        family[curr_ruler_idx].first_child = &family[female_idx[0]];
    }

    if (!female_idx.empty())
    {
        if (male_idx.size() > 1)
        {
            family[male_idx.back()].sibling = &family[female_idx[0]];
        }

        if (female_idx.size() > 1)
        {
            for (int i = 0; i < female_idx.size()-1; ++i)
            {
                family[female_idx[i]].sibling = &family[female_idx[i+1]];
            }
        }
    }
}

void map_parent_children(std::vector<Details>& family, int curr_ruler_idx)
{
    std::vector<int> next_gen_m_idx; // stores index of male members of next generation
    std::vector<int> next_gen_f_idx; // stores index of female members of next generation
    
    for (int i = 0; i < family.size(); ++i)
    {
        if (family[i].parent_name == family[curr_ruler_idx].name)
        {
            family[curr_ruler_idx].has_child = true;
            family[i].parent = &family[curr_ruler_idx]; // mapping parent
            if (family[i].gender == "M")
            {
                next_gen_m_idx.push_back(i);
            }
            else
            {
                next_gen_f_idx.push_back(i);
            }
        }  
    }
    //sort both vectors according to age
    if (family[curr_ruler_idx].has_child)
    {
        static const auto by_age = [family](const int i, const int j)
        {
            return family[i].birth < family[j].birth; // year of birth is smaller means age is bigger
        };   

        std::sort(next_gen_m_idx.begin(), next_gen_m_idx.begin(), by_age);
        std::sort(next_gen_f_idx.begin(), next_gen_f_idx.begin(), by_age);

        map_siblings(next_gen_m_idx, next_gen_f_idx, family, curr_ruler_idx);
    }
}


std::vector<std::string> order_of_succession(std::vector<Details>& family, int first_ruler_idx)
{
    std::vector<std::string> rulers;
    int curr_ruler_idx = first_ruler_idx;

    map_parent_children(family, first_ruler_idx);

    while (true)
    {
        if (family[curr_ruler_idx].death == "-" && 
            family[curr_ruler_idx].religion != "Catholic" && !family[curr_ruler_idx].processed)
        {
            rulers.push_back(family[curr_ruler_idx].name);
        }
        family[curr_ruler_idx].processed = true;

        if (family[curr_ruler_idx].has_child)
        {
            curr_ruler_idx = family[curr_ruler_idx].first_child->index;
        }
        else
        {
            if (family[curr_ruler_idx].sibling != nullptr)
            {
                curr_ruler_idx = family[curr_ruler_idx].sibling->index;
            }
            else
            {
                while (curr_ruler_idx != first_ruler_idx &&
                    family[curr_ruler_idx].parent->sibling == nullptr)
                {
                    curr_ruler_idx = family[curr_ruler_idx].parent->index;   
                }

                if (curr_ruler_idx == first_ruler_idx)
                {
                    break;
                }

                if (family[curr_ruler_idx].parent->sibling != nullptr)
                {
                    curr_ruler_idx = family[curr_ruler_idx].parent->sibling->index;
                }
            }
        }
        map_parent_children(family, curr_ruler_idx); 
    }
   
    return rulers;
}

int main()
{
    int n;
    std::cin >> n; std::cin.ignore();

    std::vector<Details> family_details;
    int first_ruler_idx;

    for (int i = 0; i < n; i++) 
    {
        std::string name;
        std::string parent;
        int birth;
        std::string death;
        std::string religion;
        std::string gender;
        std::cin >> name >> parent >> birth >> death >> religion >> gender; std::cin.ignore();

        if (parent == "-")
        {
            first_ruler_idx = i;
        }

        family_details.push_back( Details(name, parent, birth, death, religion, gender, i));
        
    }

    std::vector<std::string> ruler_order = order_of_succession(family_details, first_ruler_idx);
    for (int i = 0; i < ruler_order.size(); ++i)
    {
        std::cout << ruler_order[i] << "\n";
    }
}
