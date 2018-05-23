#include <iostream>
# include <ctime>
#include "SubsetSum.h"

void solutionOne(std::string fileName, int minToSpare);
void solutionTwo(std::string fileName, int minToSpare);



int main()
{

    std::cout << std::endl;
    std::cout << "###################" << std::endl;
    std::cout << "#####Solution1#####" << std::endl;
    std::cout << "###################" << std::endl;
    int minToSpare = 100;
    std::cout << "Reserved amount of minutes: " << minToSpare << std::endl;
    solutionOne("Operationer_1b.txt", minToSpare);
    minToSpare = 50;
    std::cout << "Reserved amount of minutes: " << minToSpare << std::endl;
    solutionOne("Operationer_1b.txt", minToSpare);
    minToSpare = 0;
    std::cout << "Reserved amount of minutes: " << minToSpare << std::endl;
    solutionOne("Operationer_1b.txt", minToSpare);

    std::cout << std::endl;
    std::cout << "###################" << std::endl;
    std::cout << "#####Solution2#####" << std::endl;
    std::cout << "###################" << std::endl;
    minToSpare = 100;
    std::cout << "Reserved amount of minutes: " << minToSpare << std::endl;
    solutionTwo("Operationer_2.txt", minToSpare);
    minToSpare = 50;
    std::cout << "Reserved amount of minutes: " << minToSpare << std::endl;
    solutionTwo("Operationer_2.txt", minToSpare);
    minToSpare = 0;
    std::cout << "Reserved amount of minutes: " << minToSpare << std::endl;
    solutionTwo("Operationer_2.txt", minToSpare);

    return 0;
}


void solutionOne(const std::string fileName, int minToSpare)
{

    clock_t start;
    clock_t end;

    SubsetSum binPacking(fileName, 3);

    int timeCapacity = 660;
    binPacking.setHours(0, 0, timeCapacity);
    binPacking.setHours(1, 0, timeCapacity);
    binPacking.setHours(2, 0, timeCapacity);

    binPacking.sortSurgeriesAsc();
    binPacking.constructMatrix();
    //binPacking.printMatrix(timeCapacity);

    start = clock();
    int nrOfSurgeries = binPacking.getNrOfSurgeries() - 1;
    binPacking.planSurgeries(0, nrOfSurgeries, timeCapacity, minToSpare);
    binPacking.planSurgeries(1, nrOfSurgeries, timeCapacity, minToSpare);
    binPacking.planSurgeries(2, nrOfSurgeries, timeCapacity, minToSpare);
    end = clock();

    binPacking.viewAllTheatres();
    binPacking.printAllSurgeries();
    std::cout << std::endl << "#########################" << std::endl;
    std::cout << "TIME: " << std::setprecision (10) << std::fixed << (end - start) / (double) CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "#########################" << std::endl;
}

void solutionTwo(std::string fileName, int minToSpare)
{
    clock_t start;
    clock_t end;


    SubsetSum binPacking(fileName, 6);
    binPacking.setHours(0, 0, 660);
    binPacking.setHours(1, 0, 660);
    binPacking.setHours(2, 0, 840);
    binPacking.setHours(3, 0, 840);
    binPacking.setHours(4, 0, 540);
    binPacking.setHours(5, 0, 540);

    binPacking.sortSurgeriesAsc();
    binPacking.constructMatrix();
    //binPacking.printMatrix(timeCapacity);

    start = clock();
    binPacking.planSurgeries(2, 38, 840, minToSpare);
    binPacking.planSurgeries(3, 38, 840, minToSpare);
    binPacking.planSurgeries(4, 38, 540, minToSpare);
    binPacking.planSurgeries(5, 38, 540, minToSpare);
    binPacking.planSurgeries(0, 38, 660, minToSpare);
    binPacking.planSurgeries(1, 38, 660, minToSpare);
    end = clock();

    binPacking.viewAllTheatres();
    binPacking.printAllSurgeries();
    std::cout << std::endl << "#########################" << std::endl;
    std::cout << "TIME: " << std::setprecision (10) << std::fixed << (end - start) / (double) CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "#########################" << std::endl;
}
