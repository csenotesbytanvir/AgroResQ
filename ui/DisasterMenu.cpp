#include "DisasterMenu.h"

#include <iostream>
#include <iomanip>

namespace AgroResQ
{
namespace UI
{

DisasterMenu::DisasterMenu() = default;

void DisasterMenu::show()
{
    int choice;

    do
    {
        std::cout << "\n=========================================\n";
        std::cout << "        DISASTER MANAGEMENT MENU\n";
        std::cout << "=========================================\n";
        std::cout << "1. Add Disaster\n";
        std::cout << "2. View All Disasters\n";
        std::cout << "3. Search Disaster\n";
        std::cout << "4. Update Disaster\n";
        std::cout << "5. Delete Disaster\n";
        std::cout << "0. Back\n";
        std::cout << "=========================================\n";
        std::cout << "Enter Choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            addDisaster();
            break;

        case 2:
            viewAllDisasters();
            break;

        case 3:
            searchDisaster();
            break;

        case 4:
            updateDisaster();
            break;

        case 5:
            deleteDisaster();
            break;

        case 0:
            break;

        default:
            std::cout << "\nInvalid Choice!\n";
        }

    } while (choice != 0);
}

void DisasterMenu::addDisaster()
{
    std::string name;
    std::string type;
    std::string location;
    std::string date;
    int severity;

    std::cin.ignore();

    std::cout << "\nDisaster Name: ";
    std::getline(std::cin, name);

    std::cout << "Disaster Type: ";
    std::getline(std::cin, type);

    std::cout << "Location: ";
    std::getline(std::cin, location);

    std::cout << "Date (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    std::cout << "Severity (1-10): ";
    std::cin >> severity;

    if (disasterService.addDisaster(
            name,
            type,
            location,
            date,
            severity))
    {
        std::cout << "\nDisaster Added Successfully.\n";
    }
    else
    {
        std::cout << "\nFailed to Add Disaster.\n";
    }
}

void DisasterMenu::viewAllDisasters()
{
    std::vector<Entities::Disaster> disasters =
        disasterService.getAllDisasters();

    if (disasters.empty())
    {
        std::cout << "\nNo Disaster Found.\n";
        return;
    }

    std::cout << "\n---------------------------------------------------------------\n";
    std::cout << std::left
              << std::setw(5) << "ID"
              << std::setw(20) << "Name"
              << std::setw(15) << "Type"
              << std::setw(18) << "Location"
              << std::setw(12) << "Date"
              << std::setw(10) << "Severity"
              << "\n";
    std::cout << "---------------------------------------------------------------\n";

    for (const auto& disaster : disasters)
    {
        std::cout << std::left
                  << std::setw(5) << disaster.getId()
                  << std::setw(20) << disaster.getName()
                  << std::setw(15) << disaster.getType()
                  << std::setw(18) << disaster.getLocation()
                  << std::setw(12) << disaster.getDate()
                  << std::setw(10) << disaster.getSeverity()
                  << "\n";
    }
}

void DisasterMenu::searchDisaster()
{
    int id;

    std::cout << "\nEnter Disaster ID: ";
    std::cin >> id;

    Entities::Disaster disaster;

    if (disasterService.searchDisaster(id, disaster))
    {
        std::cout << "\nID        : " << disaster.getId();
        std::cout << "\nName      : " << disaster.getName();
        std::cout << "\nType      : " << disaster.getType();
        std::cout << "\nLocation  : " << disaster.getLocation();
        std::cout << "\nDate      : " << disaster.getDate();
        std::cout << "\nSeverity  : " << disaster.getSeverity() << "\n";
    }
    else
    {
        std::cout << "\nDisaster Not Found.\n";
    }
}

void DisasterMenu::updateDisaster()
{
    int id;
    std::string name;
    std::string type;
    std::string location;
    std::string date;
    int severity;

    std::cout << "\nEnter Disaster ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "New Name: ";
    std::getline(std::cin, name);

    std::cout << "New Type: ";
    std::getline(std::cin, type);

    std::cout << "New Location: ";
    std::getline(std::cin, location);

    std::cout << "New Date (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    std::cout << "New Severity (1-10): ";
    std::cin >> severity;

    if (disasterService.updateDisaster(
            id,
            name,
            type,
            location,
            date,
            severity))
    {
        std::cout << "\nUpdated Successfully.\n";
    }
    else
    {
        std::cout << "\nUpdate Failed.\n";
    }
}

void DisasterMenu::deleteDisaster()
{
    int id;

    std::cout << "\nEnter Disaster ID: ";
    std::cin >> id;

    if (disasterService.deleteDisaster(id))
    {
        std::cout << "\nDeleted Successfully.\n";
    }
    else
    {
        std::cout << "\nDelete Failed.\n";
    }
}

}
}