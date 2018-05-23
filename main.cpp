#include <iostream>
# include <ctime>
#include "SubsetSum.h"



int main()
{
    clock_t start;
    clock_t end;


    SubsetSum binPacking("Operationer_1a.txt", 3);
    binPacking.setHours(0, 0, 660);
    binPacking.setHours(1, 0, 660);
    binPacking.setHours(2, 0, 660);

    binPacking.sortSurgeriesAsc();



    binPacking.constructMatrix();
    start = clock();
    binPacking.planSurgeries(0, 18, 660);
    binPacking.planSurgeries(1, 18, 660);
    binPacking.planSurgeries(2, 18, 660);
    end = clock();
    std::cout << "TIME: " << end - start << std::endl;
    binPacking.viewAllTheatres();
    binPacking.printAllSurgeries();


    /*SubsetSum binPacking2("Operationer_1b.txt", 3);
    binPacking2.setHours(0, 0, 660);
    binPacking2.setHours(1, 0, 660);
    binPacking2.setHours(2, 0, 660);

    binPacking2.sortSurgeriesAsc();

    binPacking2.constructMatrix();
    start = clock();
    binPacking2.planSurgeries(0, 16, 660);
    binPacking2.planSurgeries(1, 16, 660);
    binPacking2.planSurgeries(2, 16, 660);
    end = clock();
    std::cout << "TIME: " << end - start << std::endl;
    binPacking2.viewAllTheatres();

    binPacking2.printAllSurgeries();*/



    /*SubsetSum binPacking3("Operationer_2.txt", 6);
    binPacking3.setHours(0, 0, 660);
    binPacking3.setHours(1, 0, 660);
    binPacking3.setHours(2, 0, 840);
    binPacking3.setHours(3, 0, 840);
    binPacking3.setHours(4, 0, 540);
    binPacking3.setHours(5, 0, 540);

    binPacking3.sortSurgeriesAsc();
    binPacking3.constructMatrix();

    start = clock();
    std::cout << std::endl << std::endl << "Sal 1: " << std::endl;
    binPacking3.planSurgeries(4, 38, 540);
    std::cout << "Sal 2: " << std::endl;
    binPacking3.planSurgeries(5, 38, 540);
    std::cout << "Sal 3: " << std::endl;
    binPacking3.planSurgeries(0, 38, 660);
    std::cout << "Sal 4: " << std::endl;
    binPacking3.planSurgeries(1, 38, 660);
    std::cout << "Sal 5: " << std::endl;
    binPacking3.planSurgeries(2, 38, 840);
    std::cout << "Sal 6: " << std::endl;
    binPacking3.planSurgeries(3, 38, 840);


    end = clock();
    binPacking3.viewAllTheatres();
    binPacking3.printAllSurgeries();
    std::cout << "TIME: " << end - start << std::endl;*/

    return 0;
}
