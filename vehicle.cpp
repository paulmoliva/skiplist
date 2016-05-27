#include "vehicle.h"
using namespace std;
Vehicle::Vehicle()
{
    //ctor
}

Vehicle::Vehicle(int setID, string setMake, string setModel, char setEngineType, int setCarryingCapacity, int setCustomerRating)
{
    ID = new int(setID);
    make = new string(setMake);
    model = new string(setModel);
    engineType = new char(setEngineType);
    carryingCapacity = new int(setCarryingCapacity);
    customerRating = new int(setCustomerRating);
    index = 0;
}

Vehicle::~Vehicle()
{
    //dtor
    delete ID;
    delete make; //!< Member variable "make"
    delete model; //!< Member variable "model"
    delete engineType; //!< Member variable "engineType"
    delete carryingCapacity; //!< Member variable "carryingCapacity"
    delete customerRating;

}



void Vehicle::print()
{
    cout << *ID << "\t" << *make << "\t" << *model << "\t" << *engineType
    << "\t" << *carryingCapacity << "\t" << *customerRating << endl;
}

SLL* Vehicle::readFile() //reads from file and creates vehicle objects
{
    Vehicle *newCar;
    SLL *allVehicles;
    string inMake, inModel, type, inCC, inCR;
    char inType;
    int CCint, CRint, ID;
    ID =1;
    allVehicles = new SLL();
    ifstream vehicleFile("vehicles.txt");
    while(vehicleFile.good())
    {
        vehicleFile >> inMake >> inModel >> type >> inCC >> inCR;
        char foo = inCC[0];
        int i =0;
        while(foo!=NULL)
        {
            foo = inCC[i+1];
            i++;
        }
        if (i == 3)
            CCint = (((inCC[0] - '0') *100) + ((inCC[1] - '0') *10) + (inCC[2] - '0'));
        if (i == 4)
            CCint = (((inCC[0] - 48) *1000) + ((inCC[1] - 48) *100) + ((inCC[2] - 48) * 10) + (inCC[3] - 48));

        CRint = (inCR[0] - '0');
        inType = type[0];
        newCar = new Vehicle(ID, inMake, inModel, inType, CCint, CRint);
        allVehicles->add(newCar);
        ID++;
    }
    vehicleFile.close();
    return allVehicles;
}
//HomeMade string to int converter
int Vehicle::stringToInt(string inCC)
{
    char foo = inCC[0];
    int CCint;
    int i =0;
    while(foo!=NULL)
    {
        foo = inCC[i+1];
        i++;
    }
    if (i == 1)
        CCint = (inCC[0] - '0');

    if (i==2)
        CCint = (((inCC[0] - '0') *10) + (inCC[1] - '0'));

    if (i == 3)
        CCint = (((inCC[0] - '0') *100) + ((inCC[1] - '0') *10) + (inCC[2] - '0'));

    if (i == 4)
        CCint = (((inCC[0] - 48) *1000) + ((inCC[1] - 48) *100) + ((inCC[2] - 48) * 10) + (inCC[3] - 48));

    return CCint;
}




