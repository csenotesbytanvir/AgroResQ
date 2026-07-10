#include "Disaster.h"

#include <sstream>

namespace AgroResQ
{
namespace Entities
{

Disaster::Disaster()
    : severity(1)
{
}

Disaster::Disaster(
    int id,
    const std::string& name,
    const std::string& type,
    const std::string& location,
    const std::string& date,
    int severity)
{
    setId(id);

    this->name = name;
    this->type = type;
    this->location = location;
    this->date = date;
    this->severity = severity;
}

void Disaster::setName(const std::string& name)
{
    this->name = name;
}

void Disaster::setType(const std::string& type)
{
    this->type = type;
}

void Disaster::setLocation(const std::string& location)
{
    this->location = location;
}

void Disaster::setDate(const std::string& date)
{
    this->date = date;
}

void Disaster::setSeverity(int severity)
{
    this->severity = severity;
}

std::string Disaster::getName() const
{
    return name;
}

std::string Disaster::getType() const
{
    return type;
}

std::string Disaster::getLocation() const
{
    return location;
}

std::string Disaster::getDate() const
{
    return date;
}

int Disaster::getSeverity() const
{
    return severity;
}

std::string Disaster::toString() const
{
    std::stringstream stream;

    stream << getId() << ","
           << name << ","
           << type << ","
           << location << ","
           << date << ","
           << severity;

    return stream.str();
}

}
}