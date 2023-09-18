#include <iostream>
#include <iomanip>

using namespace std;

//Growth rate function
double GrowthRate (double birth, double death)
{
return birth - death;
}

//Estimated population function
double EstimatedPopulation(double currentPopulation, double birth, double death)
{
return currentPopulation + (birth * currentPopulation) / 100 - (death * currentPopulation) / 100;
}

//These fuctions listed above will be used later on in the program.

int main()
{
    //Setting variables
    double initialPopulation;
    double birth;
    double death;
    int years;

    
        //Establishing the user interface
        cout << "Enter the initial population (Enter number greater than 2): ";
        cin >> initialPopulation;
    
        cout << "Enter the birth rate (Do not enter negative numbers): ";
        cin >> birth;

        cout << "Enter the death rate (Do not enter negative numbers): ";
        cin >> death;

        cout << "Enter the number of years to project: ";
        cin >> years;
        cout << endl;
    
    //Using setw to organize the output
    cout << "Year: " <<
            setw(15) << "Population: " <<
            setw(10) << "Growth: " << endl;
    
    for (int year = 1; year <= years; ++year)
    {
        
        double growthRate = GrowthRate(birth, death);
        
        //Establishing the estimated population
        double nextYearPopulation = EstimatedPopulation(initialPopulation, birth, death);

        cout << year << setw(15) << nextYearPopulation << setw(10) << growthRate << "%" << endl;

        initialPopulation = nextYearPopulation;
    }

    cout << endl;
    return 0;
}

