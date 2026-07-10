#pragma once

#include <string>

#include "../core/BaseEntity.h"

namespace AgroResQ
{
namespace Entities
{

class Disaster : public Core::BaseEntity
{
private:
    std::string name;
    std::string type;
    std::string location;
    std::string date;
    int severity;

public:
    Disaster();

    Disaster(
        int id,
        const std::string& name,
        const std::string& type,
        const std::string& location,
        const std::string& date,
        int severity
    );

    void setName(const std::string& name);
    void setType(const std::string& type);
    void setLocation(const std::string& location);
    void setDate(const std::string& date);
    void setSeverity(int severity);

    std::string getName() const;
    std::string getType() const;
    std::string getLocation() const;
    std::string getDate() const;
    int getSeverity() const;

    std::string toString() const;
};

}
}