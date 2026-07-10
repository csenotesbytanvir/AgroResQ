#pragma once

#include "DisasterMenu.h"
#include "VictimMenu.h"
#include "ReportMenu.h"
#include "AgricultureMenu.h"
#include "ShelterMenu.h"
#include "RescueTeamMenu.h"
#include "ReliefMenu.h"

namespace AgroResQ
{
    namespace UI
    {

        class MainMenu
        {

        private:
            DisasterMenu disasterMenu;

            VictimMenu victimMenu;

            ReportMenu reportMenu;

            AgricultureMenu agricultureMenu;
            ShelterMenu shelterMenu;
            RescueTeamMenu rescueTeamMenu;
            ReliefMenu reliefMenu;

        public:
            MainMenu();

            void show();
        };

    }
}