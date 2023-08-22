#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

map<string, int> cityCounts = {};

void Setup() {
    cityCounts["Invercargill"] = 56800;
    cityCounts["Hamilton"] = 179900;
    cityCounts["Tauranga"] = 158300;
    cityCounts["Napier"] = 157400;
    cityCounts["Dunedin"] = 130400;
    cityCounts["Whangarei"] = 100500;
    cityCounts["Auckland"] = 1652000;
    cityCounts["Palmerston North"] = 90400;
    cityCounts["Christchurch"] = 389300;
    cityCounts["New Plymouth"] = 87700;
    cityCounts["Rotorua"] = 76800;
    cityCounts["Nelson"] = 54500;
    cityCounts["Gisborne"] = 52100;
    cityCounts["Whanganui"] = 48700;
    cityCounts["Timaru"] = 48500;
    cityCounts["Wellington"] = 434900;
}

string MakeLowerCase(string name) {
    for (int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);
    return name;
}

void GetCity(string cityName) {
    if (cityName == "*") {
        for (auto city : cityCounts) {
            cout << city.first << ": "<< city.second << endl;
        }
    }
    else {
        cityName = MakeLowerCase(cityName);

        for (auto city : cityCounts) {
            string currentCity = MakeLowerCase(city.first);

            if (currentCity.find(cityName) != string::npos) {
                cout << city.first << ": " << city.second << endl;
                break;
            }
        }
    }
}

int main()
{
    Setup();
    while (true) {
        cout << "Which city would you like to view?" << endl;
        string city;
        cin >> city;

        GetCity(city);
        cout << "Type clear to clear window" << endl;
        string input;
        cin >> input;
        system("cls");
    }
}