

#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>
#include <VANETSIMULATION/attack/heading/RandomOffset.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace heading {

void RandomOffset::update(double const offset, veins::Heading const& prevHeading, simtime_t_cref prevBeaconTime)
{
    offset_ = offset;
    prevHeading_ = prevHeading;
    prevBeaconTime_ = prevBeaconTime;
}

void RandomOffset::attack(veins::BasicSafetyMessage* bsm)
{
    auto rng = getEnvir()->getRNG(0);

    if (offset_ > 2 * M_PI or offset_ < -2 * M_PI) {
        return;
    }

    switch (type_) {
    case kHyraTypeHeading: {
        bsm->setAttackType("RandomHeadingOffset");
        // get new randomly offset heading
        bsm->setHeading(
            veins::Heading(fmod(bsm->getHeading().getRad() + uniform(rng, -offset_, offset_), 2 * M_PI)));
        break;
    }
    case kHyraTypeYawRate: {
        bsm->setAttackType("RandomYawRateOffset");
        bsm->setYawRate(fmod(bsm->getYawRate() + uniform(rng, -offset_, offset_), 2 * M_PI));
        break;
    }
    case kHyraTypeBoth: {
        bsm->setAttackType("RandomHeadingYawRateOffset");
        auto const kYawRate{bsm->getYawRate() + uniform(rng, -offset_, offset_)};
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