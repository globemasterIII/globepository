#include <iostream>
#include <iomanip>
#include <string>
#include <list>

using namespace std;

// Creating state class
class State {
public:
    State(const string& name, double energyConsumption, long long stateSize):
        name(name), energyConsumption(energyConsumption), stateSize(stateSize)
    {
        calculatePanelPercentage();
    }

    const string& getName() const
    {
        return name;
    }

    double getEnergyConsumption() const
    {
        return energyConsumption;
    }

    long long getStateSize() const
    {
        return stateSize;
    }

    double getPanelPercentage() const
    {
        return panelPercentage;
    }

    void calculatePanelPercentage()
    //  Conversion of BTU, setting solar panel efficiency and energy production of one square foot solar panel
    {
        const double solarPanelEfficiency = 0.15;  // 15% efficiency
        const double wattsPerSquareFoot = 15.0;
        const double btuPerPanel = wattsPerSquareFoot * 51.0;
        panelPercentage = (energyConsumption * 1.055056E+12) / (stateSize * btuPerPanel);
    }
// Setting private data for state class
private:
    string name;
    double energyConsumption;
    long long stateSize;
    double panelPercentage;
};
bool compareStates(const State& state1, const State& state2)
{
    return state1.getPanelPercentage() < state2.getPanelPercentage();
}




int main()
{
    list<State> states;

    //List of the states with thier energy consumption and size
    
    State tx("Texas", 7.0, 7487580672000);
    tx.calculatePanelPercentage();
    cout << tx.getName() << " would use " << tx.getPanelPercentage() << "% of its area" << endl;
    states.push_back(tx);

    State ca("California", 6922.8, 4563554688000);
    ca.calculatePanelPercentage();
    cout << ca.getName() << " would use " << ca.getPanelPercentage() << "% of its area" << endl;
    states.push_back(ca);
    
    State la("Louisiana", 4200.4, 1445216256000);
    la.calculatePanelPercentage();
    cout << la.getName() << " would use " << la.getPanelPercentage() << "% of its area" << endl;
    states.push_back(la);
    
    State fl("Florida", 4003.1, 1805265792000);
    fl.calculatePanelPercentage();
    cout << fl.getName() << " would use " << fl.getPanelPercentage() << "% of its area" << endl;
    states.push_back(fl);
    
    State il("Illinois", 3612.9, 1614549657600);
    il.calculatePanelPercentage();
    cout << il.getName() << " would use " << il.getPanelPercentage() << "% of its area" << endl;
    states.push_back(il);
    
    State pa("Pennsylvania", 3413.0, 1283967590400);
    pa.calculatePanelPercentage();
    cout << il.getName() << " would use " << pa.getPanelPercentage() << "% of its area" << endl;
    states.push_back(pa);
    
    State oh("Ohio", 3413.0, 1283967590400);
    oh.calculatePanelPercentage();
    cout << oh.getName() << " would use " << oh.getPanelPercentage() << "% of its area" << endl;
    states.push_back(oh);
    
    State ny("New York", 3354.2, 1520933990400);
    ny.calculatePanelPercentage();
    cout << ny.getName() << " would use " << ny.getPanelPercentage() << "% of its area" << endl;
    states.push_back(ny);
    
    State ga("Georgia", 3354.2, 1520933990400);
    ga.calculatePanelPercentage();
    cout << ga.getName() << " would use " << ga.getPanelPercentage() << "% of its area" << endl;
    states.push_back(ga);
    
    State mi("Michigan", 2610.6, 2696287334400);
    mi.calculatePanelPercentage();
    cout << mi.getName() << " would use " << mi.getPanelPercentage() << "% of its area" << endl;
    states.push_back(mi);

    // Sorting the states based on the solar panel percentage amount
    states.sort(compareStates);

    // Output display of the state solar panel percetage
    cout << left << setw(10) << "State" << setw(15) << "Solar Panel %" << endl;
    for (const State& state : states)
    {
        cout << setw(10) << state.getName() << setw(15) << fixed << setprecision(2) << state.getPanelPercentage() << "%" << endl;
    }

    return 0;
}


