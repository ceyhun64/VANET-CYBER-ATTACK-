

#pragma once

#include <vasp/attack/heading/Interface.h>
#include <veins/base/utils/Heading.h>
#include <omnetpp/simtime_t.h>

namespace vasp {
namespace attack {
namespace heading {
class High final : public Interface {
public:
    void update(veins::Heading const& prevHeading, omnetpp::simtime_t_cref prevBeaconTime);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    veins::Heading prevHeading_;
    omnetpp::simtime_t prevBeaconTime_;
};
} // namespace heading
} // namespace attack
} // namespace vasp