

#include <VANETSIMULATION/attack/heading/High.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace heading {

void High::update(veins::Heading const& prevHeading, omnetpp::simtime_t_cref prevBeaconTime)
{
    prevHeading_ = prevHeading;
    prevBeaconTime_ = prevBeaconTime;
}

void High::attack(veins::BasicSafetyMessage* bsm)
{
    // maximal yaw-rate (as defined in ETSI 102 894-2) = 327.66 degrees/second i.e. 5.7187458271 rads/second
    double constexpr kYawRate{5.71892036}; // 327.67 degrees/second

    switch (type_) {
    case kHyraTypeHeading:
        break;
    case kHyraTypeYawRate: {
        bsm->setAttackType("HighYawRate");
        bsm->setYawRate(kYawRate);
        break;
    }
    case kHyraTypeBoth: {
        bsm->setAttackType("HighHeadingYawRate");
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