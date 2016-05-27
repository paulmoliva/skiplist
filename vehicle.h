#ifndef VEHICLE_H
#define VEHICLE_H
#include<string>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"Lists.h"

class Vehicle
{
    public:
        /** Default constructor */
        Vehicle();
        /** Default destructor */
        ~Vehicle();
        /** Access ID
         * \return The current value of ID
         */

         Vehicle(int setID, std::string setMake, std::string setModel, char setEngineType, int setCarryingCapacity, int setCustomerRating);

         int GetID() { return *ID; }
        /** Set ID
         * \param val New value to set
         */
        void SetID( int* val) { ID = val; }
        /** Access make
         * \return The current value of make
         */
        std::string* Getmake() { return make; }
        /** Set make
         * \param val New value to set
         */
        void Setmake(std::string* val) { make = val; }
        /** Access model
         * \return The current value of model
         */
        std::string Getmodel() { return *model; }
        /** Set model
         * \param val New value to set
         */
        void Setmodel(std::string* val) { model = val; }
        /** Access engineType
         * \return The current value of engineType
         */
        char GetengineType() { return *engineType; }
        /** Set engineType
         * \param val New value to set
         */
        void SetengineType(char* val) { engineType = val; }
        /** Access carryingCapacity
         * \return The current value of carryingCapacity
         */
        int GetcarryingCapacity() { return *carryingCapacity; }
        /** Set carryingCapacity
         * \param val New value to set
         */
        void SetcarryingCapacity(int val) { *carryingCapacity = val; }
        /** Access customerRating
         * \return The current value of customerRating
         */
        int GetcustomerRating() { return *customerRating; }
        /** Set customerRating
         * \param val New value to set
         */
        void SetcustomerRating(int* val) { customerRating = val; }

        class SLL* readFile();

        void print();
        int stringToInt(std::string inCC);
        void API();
        int index;

    protected:
        int* ID; //!< Member variable "ID"
        std::string* make; //!< Member variable "make"
        std::string* model; //!< Member variable "model"
        char* engineType; //!< Member variable "engineType"
        int* carryingCapacity; //!< Member variable "carryingCapacity"
        int* customerRating; //!< Member variable "customerRating"

    private:

};

#endif // VEHICLE_H
