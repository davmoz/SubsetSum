//
// Created by quartie on 2018-05-10.
//

#include "Surgery.h"
#include <utility>

Surgery::Surgery(int id, int duration, std::string label)
{
    this->id = id;
    this->duration = duration;
    this->label = std::move(label);
    planned = false;
}

Surgery::~Surgery()
= default;

int Surgery::getId() const
{
    return id;
}

int Surgery::getDuration() const
{
    return duration;
}

std::string Surgery::getLabel() const
{
    return label;
}

bool Surgery::schedule()
{
    bool succeed = false;
    if(!planned)
    {
        planned = true;
        succeed = true;
    }
    return succeed;
}

bool Surgery::isScheduled() const
{
    return planned;
}

bool Surgery::operator>(const Surgery &source)
{
    return (duration > source.getDuration());
}

bool Surgery::operator<(const Surgery &source)
{
    return (duration < source.getDuration());
}

std::ostream &operator<<(std::ostream &out, const Surgery &source)
{
    out << "ID: " << source.getId();
    out << " Label: " << source.getLabel();
    out << " Duration: " << source.getDuration();
    return out;
}
