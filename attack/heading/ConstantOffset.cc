

#include <VANETSIMULATION/attack/heading/ConstantOffset.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace heading {

void ConstantOffset::update(double const offset, veins::Heading const& prevHeading, simtime_t_cref prevBeaconTime)
{
    offset_ = offset;
    prevHeading_ = prevHeading;
    prevBeaconTime_ = prevBeaconTime;
}

void ConstantOffset::attack(veins::BasicSafetyMessage* bsm)
{
    if (offset_ > 2 * M_PI) {
        return;
    }

    switch (type_) {
    case kHyraTypeHeading: {
        bsm->setAttackType("ConstantHeadingOffset");
        bsm->setHeading(veins::Heading(bsm->getHeading().getRad() + offset_));
        break;
    }
    case kHyraTypeYawRate: {
        bsm->setAttackType("ConstantYawRateOffset");
        bsm->setYawRate(fmod(bsm->getYawRate() + offset_, 2 * M_PI));
        break;
    }
    case kHyraTypeBoth: {
        bsm->setAttackType("ConstantHeadingYawRateOffset");
        auto const kYawRate{bsm->getYawRate() + offset_};
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