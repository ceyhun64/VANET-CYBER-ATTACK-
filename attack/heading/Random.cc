

#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>
#include <vasp/attack/heading/Random.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace heading {

void Random::update(veins::Heading const& prevHeading, simtime_t_cref prevBeaconTime)
{
    prevHeading_ = prevHeading;
    prevBeaconTime_ = prevBeaconTime;
}

void Random::attack(veins::BasicSafetyMessage* bsm)
{
    auto rng = getEnvir()->getRNG(0);

    switch (type_) {
    case kHyraTypeHeading: {
        bsm->setAttackType("RandomHeading");
        bsm->setHeading(veins::Heading(uniform(rng, -2 * M_PI, 2 * M_PI)));
        break;
    }
    case kHyraTypeYawRate: {
        bsm->setAttackType("RandomYawRate");
        bsm->setYawRate(uniform(rng, -2 * M_PI, 2 * M_PI));
        break;
    }
    case kHyraTypeBoth: {
        bsm->setAttackType("RandomHeadingYawRate");
        auto constexpr kExtremeYawRate{-5.71892036};
        auto const kYawRate{uniform(rng, -kExtremeYawRate, kExtremeYawRate)};
        bsm->setYawRate(kYawRate);

        veins::Heading newHeading{getNewHeading(prevHeading_, kYawRate, prevBeaconTime_)};
        bsm->setHeading(newHeading);
        break;
    }
    }
}

} // namespace heading
} // namespace attack
} // namespace vasp