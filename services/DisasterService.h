#pragma once
#include <vector>
#include "../core/IDGenerator.h"
#include "../core/Validator.h"
#include "../entities/Disaster.h"
#include "../repositories/disaster/DisasterRepository.h"
#include "../algorithms/AlertSystem.h"

namespace AgroResQ
{
    namespace Services
    {
        class DisasterService
        {
        private:
            Repositories::DisasterRepository disasterRepository;
            Core::Validator validator;
            Core::IDGenerator idGenerator;
            Algorithms::AlertSystem alertSystem;

        public:
            DisasterService();

            bool addDisaster(const std::string& name, const std::string& type,
                             const std::string& location, const std::string& date, int severity);
            bool updateDisaster(int id, const std::string& name, const std::string& type,
                                const std::string& location, const std::string& date, int severity);
            bool deleteDisaster(int id);
            bool searchDisaster(int id, Entities::Disaster& disaster);
            std::vector<Entities::Disaster> getAllDisasters();
        };
    }
}