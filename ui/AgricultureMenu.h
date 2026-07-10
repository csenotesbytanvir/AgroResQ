#pragma once

#include "FarmMenu.h"
#include "SoilMenu.h"
#include "WeatherMenu.h"
#include "CropMenu.h"
#include "DecisionSupportMenu.h"

namespace AgroResQ
{
    namespace UI
    {

        class AgricultureMenu
        {
        private:
            FarmMenu farmMenu;

            SoilMenu soilMenu;

            WeatherMenu weatherMenu;

            CropMenu cropMenu;

            DecisionSupportMenu decisionSupportMenu;

        public:
            AgricultureMenu();

            void show();
        };

    }
}