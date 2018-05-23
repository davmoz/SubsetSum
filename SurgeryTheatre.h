//
// Created by quartie on 2018-05-13.
//

#pragma once

#include <iostream>
#include <string>
#include "Surgery.h"


class SurgeryTheatre
{
private:
    Surgery *surgeries;
    int numOfSurgeries;
    int timeScheduled;
    int opening;
    int closing;
public:

    SurgeryTheatre();
    ~SurgeryTheatre();

    void setHours(int opening, int closing);
    int getTheatreCapacity() const;
    bool timeLeft(Surgery surgery) const;
    int getTimeScheduled() const;
    void planSurgery(Surgery surgery);
    void showTheatreSchedule();
};

