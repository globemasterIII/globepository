/*
 Name: Michael B
 Project #: 05
 Date: 03 Dec 2023
 Description:
    Write a program that allows a user to explore dog populations using Hash.
 */
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class Dogs 
{
private:
    map<string, int> dogData;
    int totalDogs;

public:
    Dogs(const string& filename) 
    {
        totalDogs = 0;
        if (!loadFile(filename))
        {
            cerr << "Error loading data from file. Try again";
            
        }
    }

    bool loadFile(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open()) 
        {
            cerr << "Error opening file.";
            return false;
        }

        string line;
        while (getline(file, line)) 
        {
            size_t pos = line.find(',');
            if (pos != string::npos) 
            {
                string country = line.substr(0, pos);
                int population = stoi(line.substr(pos + 2));
                dogData[country] = population;
                totalDogs += population;
            }
        }

        file.close();
        return true;
    }

    void Menu()
    {
        cout << "1. See the total number of dogs in the world." << endl;
        cout << "2. Input a country name to find out how many dogs are in that country." << endl;
        cout << "3. Exit.";
    }

    void TotalDogs()
    {
        cout << "Total number of dogs in the world: " << totalDogs << endl;
    }

    void getDogsInCountry(const string& country) 
    {
        if (dogData.find(country) != dogData.end()) 
        {
            int population = dogData.at(country);
            cout << "Number of dogs in " << country << ": " << population << endl;
        } 
        
        else
            
        {
            cerr << "Error: Country not found" << endl;
        }
    }
};

int main() 
{
    Dogs dogs("Dog.txt");

    int choice;
    do 
    {
        dogs.Menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                dogs.TotalDogs();
                break;
            case 2: 
            {
                string country;
                cout << "Enter the country name: ";
                cin >> country;
                dogs.getDogsInCountry(country);
                break;
            }
            case 3:
                cout << "Exiting program.";
                break;
            default:
                cerr << "Choice Invalid. Try again.";
        }
    } while (choice != 3);

    return 0;
}

