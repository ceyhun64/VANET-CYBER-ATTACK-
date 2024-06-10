

#include <VANETSIMULATION/attack/heading/Low.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace heading {

void Low::update(veins::Heading const& prevHeading, omnetpp::simtime_t_cref prevBeaconTime)
{
    prevHeading_ = prevHeading;
    prevBeaconTime_ = prevBeaconTime;
}

void Low::attack(veins::BasicSafetyMessage* bsm)
{
    // minimal yaw-rate (as defined in ETSI 102 894-2) = -327.66 degrees/second i.e. -5.7187458271 rads/second
    double constexpr kYawRate{-5.71892036}; // -327.67 degrees/second

    switch (type_) {
    case kHyraTypeHeading:
        break;
    case kHyraTypeYawRate: {
        bsm->setAttackType("LowYawRate");
        bsm->setYawRate(kYawRate);
        break;
    }
    case kHyraTypeBoth: {
        bsm->setAttackType("LowHeadingYawRate");
        bsm->setYawRate(kYawRate);

        // add the delta change in heading to previous heading to get new heading value
        veins::Heading newHeading{getNewHeading(prevHeading_, kYawRate, prevBeaconTime_)};
        bsm->setHeading(newHeading);
        break;
    }
    }
}

} // namespace heading
} // namespace attack
} // namespace VANETSIMULATION