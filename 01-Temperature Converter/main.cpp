#include <iostream>
#include <cstdlib> // needed for system("cls")
#include <cctype> // needed for tolower()
using namespace std;


// defining constants for units names
const string C = "Celsius"; 
const string F = "Fahreneheit"; 
const string K = "Kelvin"; 

// function to get the unit from the user
int getUnit(){
    int result = 0;
    bool running = true;
    while(running){
        cout << "1)" << C << "      ";
        cout << "2)" << F << "      ";
        cout << "3)" << K << "      \nType here: ";
        cin >> result;  
        system("cls");
        if(result > 0 && result < 4){
            running = false;
            break;
        } else{
            system("cls");
            cout << "Not a valid unit. Retry" << endl;
        }
    }
    cout << endl;
    return result;
}

// function to covert the input of the usare into a usefull string
string getUnitName(int unitCode){
    string unitName = " ";
    switch(unitCode){
        case 1:
            unitName = C;
            break;
        case 2:
            unitName = F;
            break;
        case 3:
            unitName = K;
            break; 
        default:
            cout << "YOU'VE A FOUND BUG: Invalid value in Starting Unit" << endl;
    }
    return unitName;
}

// getting temperature from the user
float getTemp(int startingUnit){
    float temp = 0;
    string unitName = getUnitName(startingUnit);
    cout << "Insert the temperature in " << unitName << ": ";
    cin >> temp;
    system("cls");
    return temp;

}

// convert startTemp from StartUnit to finalUnit
float convert(float startTemp, string startUnit, string finalUnit){
    float finalTemp = 0;

    // from celsius 
    if(startUnit == C){
        // to farhanheit
        if(finalUnit == F){
            return startTemp * 1.8 + 32;
        }
        // to kelvin
        if(finalUnit == K){
            return startTemp + 273.15;
        }
    }

    // from farhaneit
    if(startUnit == F){
        // to celsius
        if(finalUnit == C){
            return (startTemp - 32) / 1.8;
        }
        // to kelvin
        if(finalUnit == K){
            return (startTemp + 459.67) * 1.8;
        }
    }

    // from kelvin
    if(startUnit == K){
        // to celsius
        if(finalUnit == C){
            return startTemp - 273.15;
        }
        // to fahranheit
        if(finalUnit == F){
            return startTemp * 1.8 - 459.67;
        }
    }

    // should never get here, therefore there is an error
    cout << "YOU'VE A FOUND BUG: Something went wrong during the convertion." << endl;
    return finalTemp;
}

int main(){

    int startingUnitCode = 0, finalUnitCode = 0;
    float startingTemp = 0, finalTemp = 0;
    string startingUnit = " ", finalUnit = " ";
    char keepGoing = ' ';
    bool running1 = true;
    bool running2 = true;
    
    system("cls"); // clear console
    cout << "Welcome, this is a temperature converter!" << endl;
    while(running1){
        // getting the units of measurement
        cout << "Insert the starting unit of measurement: " << endl;
        startingUnitCode = getUnit();
        startingTemp = getTemp(startingUnitCode);

        while(running2){
            cout << endl;
            cout << "Insert unit of measurement to convert to: " << endl;
            finalUnitCode = getUnit();
            if(startingUnitCode != finalUnitCode){
                running2 = false;
            }
            else{
                cout << "The starting and the final units can't be the same!!!" << endl;
            }
        }

        // converting unit codes to name
        startingUnit = getUnitName(startingUnitCode);
        finalUnit = getUnitName(finalUnitCode);


        finalTemp = convert(startingTemp, startingUnit, finalUnit);

        cout << "Result: " << finalTemp << " in " << finalUnit << endl;
        cout << "Do you want to convert another temperature? (E to exit, any to continue)";
        cin >> keepGoing;
        system("cls");
        if(tolower(keepGoing) == 'e'){
            running1 = false;
        }
    }

    

    cout << "Program terminated. \nBye, bye" << endl;
    return 0;
}