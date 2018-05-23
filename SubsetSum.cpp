//
// Created by quartie on 2018-05-13.
//

#include "SubsetSum.h"

void SubsetSum::expandSurgeryArray()
{
    if(numberOfSurgeries >= surgeryArrayCapacity)
    {
        Surgery *newExpandedSurgeryArray = new Surgery[surgeryArrayCapacity * 2];
        for (int i = 0; i < numberOfSurgeries; i++)
        {
            newExpandedSurgeryArray[i] = allSurgeries[i];
        }
        delete[] allSurgeries;
        allSurgeries = newExpandedSurgeryArray;
        surgeryArrayCapacity *= 2;
    }
}

SubsetSum::SubsetSum(const std::string fileLocation, const int numOfTheatres)
{
    numberOfTheatres = numOfTheatres;
    numberOfSurgeries = 0;
    surgeryArrayCapacity = 10;
    totalMinutes = 0;
    theatres = new SurgeryTheatre[numOfTheatres];
    allSurgeries = new Surgery[surgeryArrayCapacity];
    matrix = nullptr;
    read(fileLocation, allSurgeries);
    matrix = new bool*[numberOfSurgeries];
}

SubsetSum::~SubsetSum()
{
    delete[] theatres;
    delete[] allSurgeries;
    if(matrix != nullptr)
    {
        for (int i = 0; i < numberOfSurgeries; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

}

void SubsetSum::read(const std::string fileLocation, Surgery surgeries[])
{
    std::ifstream fromFile;
    fromFile.open(fileLocation);

    if (fromFile.is_open())
    {
        int id, duration, separator, counter = 0;
        std::string line, label;


        while(getline(fromFile, line) && !line.empty())
        {
            expandSurgeryArray();

            separator = static_cast<int>(line.find(','));
            id = stoi(line.substr(0, static_cast<unsigned long>(separator)));

            line = line.substr(static_cast<unsigned long>(separator + 1));

            separator = static_cast<int>(line.find(','));
            label = line.substr(0, static_cast<unsigned long>(separator));

            line = line.substr(static_cast<unsigned long>(separator + 1));

            duration = stoi(line);

            Surgery temp(id, duration, label);

            totalMinutes += duration;

            allSurgeries[counter] =  temp;
            numberOfSurgeries++;
            counter++;
        }
    }
    fromFile.close();
}

void SubsetSum::printAllSurgeries()
{

    for (int i = 0; i < numberOfSurgeries; i++)
    {
        std::cout << allSurgeries[i];
        if(!allSurgeries[i].isScheduled())
            std::cout << " Not Scheduled!" << std::endl;
        else
            std::cout << std::endl;

    }
}

void SubsetSum::viewAllTheatres() const
{
    std::cout << std::endl;
    for (int i = 0; i < numberOfTheatres; i++)
    {
        std::cout << "#####################################" << std::endl;
        std::cout << "Theater: " << i + 1 << std::endl;
        theatres[i].showTheatreSchedule();
        std::cout << "#####################################" << std::endl << std::endl;
    }
}

void SubsetSum::setHours(const int theatre, const int opening, const int closing)
{
    theatres[theatre].setHours(opening, closing);
}

void SubsetSum::initilizeMatrix(int res)
{
    for (int i = 0; i < numberOfSurgeries; i++)
    {
        for (int j = 0; j < res; j++)
        {
            matrix[i][j] = j == 0;
        };
    }
}

void SubsetSum::sortSurgeriesAsc()
{
    quickSort(allSurgeries, 0, numberOfSurgeries);
}

void SubsetSum::constructMatrix()
{
    int biggestTheatre = 0;
    for (int i = 1; i < numberOfTheatres; i++)
    {
        if(theatres[i].getTheatreCapacity() > theatres[biggestTheatre].getTheatreCapacity())
            biggestTheatre = i;
    }

    int res = theatres[biggestTheatre].getTheatreCapacity() + 1;


    for (int k = 0; k < numberOfSurgeries; k++)
    {
        matrix[k] = new bool[res];
    }
    initilizeMatrix(res);

    for (int i = 0; i < numberOfSurgeries; i++)
    {
        for (int j = 1; j < res; j++)
        {
            // For the first row
            if(i == 0 && allSurgeries[i].getDuration() == j)
            {
                matrix[i][j] = true;
            }
            else if(i > 0)
            {
                if(j - allSurgeries[i].getDuration() >= 0)
                    matrix[i][j] = matrix[i - 1][j] || matrix[i - 1][j - allSurgeries[i].getDuration()];
                else
                    matrix[i][j] = matrix[i - 1][j];
            }
        }
    }
}

void SubsetSum::printMatrix(int x)
{
    x += 1;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "     " << std::left << std::setw(6) << std::setfill(' ');
    for (int j = 0; j < x; j++)
    {
        std::string temp = "[";
        temp += std::to_string(j);
        temp += "]";
        std::cout << std::left << std::setw(6) << std::setfill(' ') << temp;
    };
    std::cout << std::endl;
    for (int i = 0; i < numberOfSurgeries; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if(j == 0)
            {
                std::string temp = "[";
                temp += std::to_string(allSurgeries[i].getDuration());
                temp += "]";
                std::cout << std::left << std::setw(6) << std::setfill(' ') << temp;
            }
            std::cout << std::left << std::setw(6) << std::setfill(' ') << matrix[i][j];
        };
        std::cout << std::endl;
    }
}

void SubsetSum::planSurgeries(int theatre, int y, int x, int timeToSave)
{
    if (x <= timeToSave)
        return;
    if (matrix[y][x - allSurgeries[y].getDuration()] && !allSurgeries[y].isScheduled() && theatres[theatre].timeLeft(allSurgeries[y]))
    {
        theatres[theatre].planSurgery(allSurgeries[y]);
        allSurgeries[y].schedule();
        return planSurgeries(theatre, y - 1, x - allSurgeries[y].getDuration(), timeToSave);
    }
    else if(matrix[y - 1][x])
    {
        return planSurgeries(theatre, y - 1, x, timeToSave);
    }
    else if(!matrix[y - 1][x])
    {
        return planSurgeries(theatre, y, x - 1, timeToSave);
    }
}

int SubsetSum::getNrOfSurgeries() const
{
    return numberOfSurgeries;
}
