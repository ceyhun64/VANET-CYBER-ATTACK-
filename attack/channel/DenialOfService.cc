//hizmet reddi saldırısı

#include <vasp/attack/channel/DenialOfService.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
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
} // namespace vasp