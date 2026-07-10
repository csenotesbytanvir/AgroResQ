#include "DisasterRepository.h"

#include <sstream>

namespace AgroResQ
{
namespace Repositories
{

DisasterRepository::DisasterRepository()
{
    filePath = "database/disaster.txt";
}

Entities::Disaster DisasterRepository::parse(const std::string& line) const
{
    std::stringstream stream(line);

    std::string id;
    std::string name;
    std::string type;
    std::string location;
    std::string date;
    std::string severity;

    std::getline(stream, id, ',');
    std::getline(stream, name, ',');
    std::getline(stream, type, ',');
    std::getline(stream, location, ',');
    std::getline(stream, date, ',');
    std::getline(stream, severity);

    return Entities::Disaster(
        std::stoi(id),
        name,
        type,
        location,
        date,
        std::stoi(severity));
}

bool DisasterRepository::add(const Entities::Disaster& disaster)
{
    return fileManager.appendFile(
        filePath,
        disaster.toString() + "\n");
}

std::vector<Entities::Disaster> DisasterRepository::getAll()
{
    std::vector<Entities::Disaster> disasters;

    std::vector<std::string> lines =
        fileManager.readLines(filePath);

    for (const std::string& line : lines)
    {
        disasters.push_back(parse(line));
    }

    return disasters;
}

bool DisasterRepository::getById(
    int id,
    Entities::Disaster& disaster)
{
    std::vector<Entities::Disaster> disasters =
        getAll();

    for (const auto& item : disasters)
    {
        if (item.getId() == id)
        {
            disaster = item;
            return true;
        }
    }

    return false;
}

bool DisasterRepository::update(
    const Entities::Disaster& disaster)
{
    std::vector<Entities::Disaster> disasters =
        getAll();

    bool found = false;
    std::string data;

    for (auto& item : disasters)
    {
        if (item.getId() == disaster.getId())
        {
            item = disaster;
            found = true;
        }

        data += item.toString() + "\n";
    }

    if (!found)
    {
        return false;
    }

    return fileManager.writeFile(filePath, data);
}

bool DisasterRepository::remove(int id)
{
    std::vector<Entities::Disaster> disasters =
        getAll();

    bool found = false;
    std::string data;

    for (const auto& item : disasters)
    {
        if (item.getId() == id)
        {
            found = true;
            continue;
        }

        data += item.toString() + "\n";
    }

    if (!found)
    {
        return false;
    }

    return fileManager.writeFile(filePath, data);
}

}
}