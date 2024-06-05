

#pragma once

#include <omnetpp/simtime_t.h>
#include <vasp/attack/Interface.h>

namespace vasp {
namespace attack {
namespace channel {
class DenialOfService final : public Interface {
public:
    DenialOfService(omnetpp::simtime_t& beaconInterval, int const nDosMessages);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    static bool updateBeaconInterval_;
};
} // namespace channel
} // namespace attack
} // namespace vasp