//
// Created by quartie on 2018-05-13.
//

#include "SurgeryTheatre.h"


SurgeryTheatre::SurgeryTheatre()
{
    numOfSurgeries = 0;
    timeScheduled = 0;
    opening = 0;
    closing = 0;
    surgeries = new Surgery[19];
}

SurgeryTheatre::~SurgeryTheatre()
{
    delete[] surgeries;
}

void SurgeryTheatre::setHours(const int opening, const int closing)
{
    this->opening = opening;
    this->closing = closing;
}

int SurgeryTheatre::getTheatreCapacity() const
{
    return (closing - opening);
}

bool SurgeryTheatre::timeLeft(Surgery surgery) const
{
    return ((closing - opening) - timeScheduled >= surgery.getDuration());
}

void SurgeryTheatre::planSurgery(const Surgery surgery)
{
    surgeries[numOfSurgeries] = surgery;
    timeScheduled += surgery.getDuration();
    numOfSurgeries ++;
}

void SurgeryTheatre::showTheatreSchedule()
{
    std::cout << "Total time Initially: " << closing - opening << " minutes" << std::endl;
    std::cout << "Total time scheduled: " << timeScheduled << " minutes" << std::endl;
    std::cout << "Total time available: " << (closing - opening) - timeScheduled << " minutes" << std::endl;
    std::cout << "Number of surgeries : " << numOfSurgeries << std::endl;
    for (int i = 0; i < numOfSurgeries; i++)
    {
        std::cout << surgeries[i] << std::endl;
    }
}

int SurgeryTheatre::getTimeScheduled() const
{
    return timeScheduled;
}
