#include "containers.h"
#include "csvstream.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


/**
 * @brief Display the content of a map
 * 
 * @param st_count: Reference to map with key-> states, value-> count 
 */
void Display_by_State(std::map<std::string, int> &st_count)
{
    int total = 0;

    // Iterate over the map using c++11 range based for loop
	for (std::pair<std::string, int> element : st_count) 
    {
		// std::cout << element.first << " :: " << element.second << std::endl;
		// Or more explicitly

        // Accessing KEY from element
		std::string word = element.first;
		// Accessing VALUE from element.
		int count = element.second;
		std::cout << word << " :: " << count << std::endl;
        
        total += count;
	}
    cout << "A total of "<< total << " records for all states" << endl;
}

void Load_Data(std::vector<Data> &data, const std::string &in_file) {
    Data temp;
    csvstream csvin(in_file);
    std::map<std::string, std::string> row;
    while(csvin >> row){
        temp.id = std::stoi(row["id"]);
        temp.gender = row["gender"];
        temp.school = row["school"];
        temp.state = row["state"];
        data.push_back(temp);
    }
}

int Count_Gender(std::vector<Data> &data, const std::string gender) {
    int gender_count = 0;

    for(const auto &value: data){
        if (value.gender == gender) {
            gender_count++;
        }
    }
    return gender_count;
}

void Count_by_State(std::vector<Data> &data, std::map<std::string, int> &st_count){

    std::map<string,int>::iterator it;

    for(const auto &value: data){
        it = st_count.find(value.state);

        if(it == st_count.end()){
            st_count.insert(make_pair(value.state, 1));
        }
        else{
            it -> second = ++it -> second;
        }
    }
}
