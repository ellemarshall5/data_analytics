#include <iostream>
#include "containers.h"

using namespace std;

// Main Function
int main()
{
    std::vector<Data> information;
    std::string input = "../../data/sample_data.csv";
    Load_Data(information, input);
    std::cout << "Information size: " << information.size() << std::endl;

    std::cout << "Number of Males " << Count_Gender(information, "Male") << std::endl;
    std::cout << "Number of Females " << Count_Gender(information, "Female") << std::endl;
    std::cout << "Number of Cars " << Count_Gender(information, "Car") << std::endl;
    std::map<std::string, int> states;
    Count_by_State(information, states);
    Display_by_State(states);


    return 0;
}