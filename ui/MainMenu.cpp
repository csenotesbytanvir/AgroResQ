#include "MainMenu.h"

#include <iostream>

namespace AgroResQ
{
    namespace UI
    {

        MainMenu::MainMenu() = default;

        void MainMenu::show()
        {

            int choice;

            do
            {

                std::cout
                    << "\n=========================================\n";

                std::cout
                    << "              AgroResQ SYSTEM\n";

                std::cout
                    << "=========================================\n";

                std::cout
                    << "1. Disaster Management\n";

                std::cout
                    << "2. Victim Management\n";

                std::cout
                    << "3. Shelter Management\n";
                std::cout
                    << "4. Relief Management\n";

                std::cout
                    << "5. Rescue Team Management\n";

                std::cout
                    << "6. Agriculture Management\n";

                std::cout
                    << "7. Report Management\n";

                std::cout
                    << "0. Exit\n";

                std::cout
                    << "=========================================\n";

                std::cout
                    << "Enter Choice: ";

                std::cin >> choice;

                switch (choice)
                {

                case 1:
                    disasterMenu.show();
                    break;

                case 2:
                    victimMenu.show();
                    break;

                case 3:
                    shelterMenu.show();
                    break;

                case 4:
                    reliefMenu.show();
                    break;

                case 5:
                    rescueTeamMenu.show();
                    break;

                case 6:
                    agricultureMenu.show();
                    break;

                case 7:
                    reportMenu.show();
                    break;

                case 0:
                    std::cout
                        << "\nThank you for using AgroResQ.\n";
                    break;

                default:

                    std::cout
                        << "\nInvalid Choice.\n";
                }

            } while (choice != 0);
        }

    }
}