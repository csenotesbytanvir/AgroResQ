#pragma once

#include "../services/VictimService.h"

namespace AgroResQ
{
    namespace UI
    {

        class VictimMenu
        {
        private:
            Services::VictimService victimService;

            void addVictim();

            void viewAllVictims();

            void searchVictim();

            void updateVictim();

            void deleteVictim();
            void searchFamily();

            void viewMissingVictims();
            void assignShelter();

        public:
            VictimMenu();

            void show();
        };

    }
}