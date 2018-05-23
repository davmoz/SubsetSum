//
// Created by quartie on 2018-05-13.
//

#pragma once
#include <fstream>
#include <iomanip>
#include "SurgeryTheatre.h"
#include "FunctionTemplates.h"

class SubsetSum
{
private:
    int numberOfTheatres;
    int numberOfSurgeries;
    int surgeryArrayCapacity;
    int totalMinutes;
    bool* *matrix;
    SurgeryTheatre *theatres;
    Surgery *allSurgeries;
    void expandSurgeryArray();
public:
    SubsetSum(std::string fileLocation, int numOfTheatres);
    ~SubsetSum();

    void read(std::string fileLocation, Surgery surgeries[]);
    void printAllSurgeries();
    void viewAllTheatres() const;
    void setHours(int theatre, int opening, int closing);
    void initilizeMatrix(int res);
    void constructMatrix();
    void printMatrix(int x);
    void sortSurgeriesAsc();
    void planSurgeries(int theatre, int x, int y, int timeToSave);
    int getNrOfSurgeries() const;
};