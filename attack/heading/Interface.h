

#pragma once

#include <omnetpp/simtime_t.h>
#include <vasp/attack/Interface.h>
#include <vasp/attack/heading/Type.h>

namespace veins {
class Heading;
} // namespace veins

namespace vasp {
namespace attack {
namespace heading {
class Interface : public attack::Interface {
public:
    virtual void attack(veins::BasicSafetyMessage* bsm) = 0;
    void setType(Type const type)
    {
        type_ = type;
    }

protected:
    veins::Heading const getNewHeading(veins::Heading const& prevHeading, double const yawRate, omnetpp::simtime_t_cref prevBeaconTime) const;

protected:
    Type type_;
};
} // namespace heading
} // namespace attack
} // namespace vasp