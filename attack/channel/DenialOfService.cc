//hizmet reddi saldırısı

#include <VANETSIMULATION/attack/channel/DenialOfService.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace channel {

bool DenialOfService::updateBeaconInterval_ = true;

DenialOfService::DenialOfService(omnetpp::simtime_t& beaconInterval, int const nDosMessages)
{
    if (updateBeaconInterval_) {
        beaconInterval.setRaw(beaconInterval.raw() / nDosMessages);
        updateBeaconInterval_ = false;
    }
}

void DenialOfService::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("DenialOfService");
    // actual attack is implemented in the update() method since the Interface won't allow any other parameters
}
} // namespace channel
} // namespace attack
} // namespace VANETSIMULATION