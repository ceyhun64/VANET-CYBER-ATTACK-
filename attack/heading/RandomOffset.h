

#pragma once

#include <VANETSIMULATION/attack/heading/Interface.h>
#include <veins/base/utils/Heading.h>
#include <omnetpp/simtime_t.h>

namespace VANETSIMULATION {
namespace attack {
namespace heading {
class RandomOffset final : public Interface {
public:
    void update(double const offset, veins::Heading const& prevHeading, simtime_t_cref prevBeaconTime);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    double offset_;
    veins::Heading prevHeading_;
    simtime_t prevBeaconTime_;
};
} // namespace heading
} // namespace attack
} // namespace VANETSIMULATION