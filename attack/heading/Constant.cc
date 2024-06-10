

#include <VANETSIMULATION/attack/heading/Constant.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace heading {

void Constant::update(veins::Heading const& prevHeading, simtime_t_cref prevBeaconTime)
{
    prevHeading_ = prevHeading;
    prevBeaconTime_ = prevBeaconTime;
}

void Constant::attack(veins::BasicSafetyMessage* bsm)
{
    switch (type_) {
    case kHyraTypeHeading:
        bsm->setAttackType("ConstantHeading");
        bsm->setHeading(veins::Heading(M_PI_2));
        break;
    case kHyraTypeYawRate: {
        bsm->setAttackType("ConstantYawRate");
        bsm->setYawRate(M_PI_2);
        break;
    }
    case kHyraTypeBoth: {
        bsm->setAttackType("ConstantHeadingYawRate");
        double constexpr kYawRate{0};
        bsm->setYawRate(kYawRate);

        veins::Heading newHeading{getNewHeading(prevHeading_, kYawRate, prevBeaconTime_)};
        bsm->setHeading(newHeading);
        break;
    }
    }
}

} // namespace heading
} // namespace attack
} // namespace VANETSIMULATION