#include <iostream>
#include <fstream>

#include "nlohmann/json.hpp"

using std::ifstream;    using std::cin;
using std::cout;        using std::string;
using json = nlohmann::json;

int main(){

    ifstream file("../filmReel.json");
    json films;

    if(!file)
    {
        cout << "\nError: file is not open.";
        exit(1);
    }

    file >> films;
    file.close();

    string actor;

    cout << "\nEnter the actor`s first or last name:\n";
    cin >> actor;

    for(auto filmName : films)
        for(int j = 0; j < filmName["characters"].size(); j++)
            for(int k = 0; k < filmName["characters"][j]["actor"].size(); k++)

                if(filmName["characters"][j]["actor"][k] == actor)
                {
                    cout << "\n\nActor: " << filmName["characters"][j]["actor"][0] << " "
                         << filmName["characters"][j]["actor"][1]

                         << "\nCharacter name: " << filmName["characters"][j]["name"]
                         << "\nFilm: " << filmName["name"];
                }
    return 0;
}
