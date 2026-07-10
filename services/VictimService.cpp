#include "VictimService.h"
#include "../repositories/disaster/ShelterRepository.h"
#include "../entities/Shelter.h"

namespace AgroResQ
{
    namespace Services
    {

        VictimService::VictimService() = default;

        bool VictimService::addVictim(
            const std::string &name,
            int age,
            const std::string &gender,
            const std::string &address,
            bool vulnerable,
            int familyId,
            const std::string &healthStatus,
            bool disabled,
            bool rescued,
            bool reliefReceived,
            bool missing,
            int priorityScore,
            int shelterId)
        {

            if (name.empty())
                return false;

            if (age <= 0)
                return false;

            int id =
                idGenerator.generateNextId(
                    "database/victims.txt");

            Entities::Victim victim(
                id,
                name,
                age,
                gender,
                address,
                vulnerable,
                familyId,
                healthStatus,
                disabled,
                rescued,
                reliefReceived,
                missing,
                priorityScore,
                shelterId);
            victim.setPriorityScore(
                static_cast<int>(
                    priorityCalculator.calculateVictimPriority(victim)));

            return victimRepository.add(victim);
        }

        bool VictimService::updateVictim(
            int id,
            const std::string &name,
            int age,
            const std::string &gender,
            const std::string &address,
            bool vulnerable,
            int familyId,
            const std::string &healthStatus,
            bool disabled,
            bool rescued,
            bool reliefReceived,
            bool missing,
            int priorityScore,
            int shelterId)
        {

            if (name.empty())
                return false;

            if (age <= 0)
                return false;

            Entities::Victim victim(
                id,
                name,
                age,
                gender,
                address,
                vulnerable,
                familyId,
                healthStatus,
                disabled,
                rescued,
                reliefReceived,
                missing,
                priorityScore,
                shelterId);
            victim.setPriorityScore(
                static_cast<int>(
                    priorityCalculator.calculateVictimPriority(victim)));

            return victimRepository.update(victim);
        }

        bool VictimService::deleteVictim(
            int id)
        {

            return victimRepository.remove(id);
        }

        bool VictimService::searchVictim(
            int id,
            Entities::Victim &victim)
        {

            return victimRepository.getById(
                id,
                victim);
        }

        std::vector<Entities::Victim> VictimService::getAllVictims()
        {

            return victimRepository.getAll();
        }
        std::vector<Entities::Victim>
        VictimService::getVictimsByFamily(
            int familyId)
        {
            std::vector<Entities::Victim> result;

            auto victims =
                victimRepository.getAll();

            for (const auto &victim : victims)
            {
                if (victim.getFamilyId() == familyId)
                {
                    result.push_back(victim);
                }
            }

            return result;
        }
        std::vector<Entities::Victim>
        VictimService::getMissingVictims()
        {
            std::vector<Entities::Victim> result;

            auto victims =
                victimRepository.getAll();

            for (const auto &victim : victims)
            {
                if (victim.isMissing())
                {
                    result.push_back(victim);
                }
            }

            return result;
            
        }
        bool VictimService::assignShelter(
    int victimId,
    int shelterId)
{
    Entities::Victim victim;

    if(!victimRepository.getById(
        victimId,
        victim))
    {
        return false;
    }

    Repositories::ShelterRepository shelterRepository;

    Entities::Shelter shelter;

    if(!shelterRepository.getById(
        shelterId,
        shelter))
    {
        return false;
    }

    if(shelter.getOccupied() >= shelter.getCapacity())
    {
        return false;
    }

    victim.setShelterId(
        shelterId);

    shelter.setOccupied(
        shelter.getOccupied() + 1);

    victimRepository.update(
        victim);

    shelterRepository.update(
        shelter);

    return true;
}

    }
}