//
// Created by quartie on 2018-05-10.
//

#pragma once

#include <string>
#include <fstream>

class Surgery
{

private:
    int id;
    int duration;
    std::string label;
    bool planned;
public:
    explicit Surgery(int id = -1, int duration = -1, std::string label = "");
    ~Surgery();

    int getId() const;
    int getDuration() const;
    std::string getLabel() const;
    bool operator>(const Surgery &source);
    bool operator<(const Surgery &source);
    friend std::ostream& operator<<(std::ostream& out, const Surgery& source);
    bool schedule();
    bool isScheduled() const;
};