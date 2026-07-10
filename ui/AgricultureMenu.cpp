#include "AgricultureMenu.h"

#include <iostream>

namespace AgroResQ
{
    namespace UI
    {

        AgricultureMenu::AgricultureMenu() = default;

        void AgricultureMenu::show()
        {
            int choice;

            do
            {
                std::cout << "\n=========================================\n";
                std::cout << "          AGRICULTURE MANAGEMENT\n";
                std::cout << "=========================================\n";
                std::cout << "1. Farm Management\n";
                std::cout << "2. Soil Management\n";
                std::cout << "3. Weather Management\n";
                std::cout << "4. Crop Management\n";
                std::cout << "5. Decision Support\n";
                std::cout << "0. Back\n";
                std::cout << "=========================================\n";
                std::cout << "Enter Choice: ";

                std::cin >> choice;

                switch (choice)
                {
                case 1:
                    farmMenu.show();
                    break;

                case 2:
                    soilMenu.show();
                    break;

                case 3:
                    weatherMenu.show();
                    break;

                case 4:
                    cropMenu.show();
                    break;

                case 5:
                    decisionSupportMenu.show();
                    break;

                case 0:
                    break;

                default:
                    std::cout << "\nInvalid Choice.\n";
                }

            } while (choice != 0);
        }

    }
}