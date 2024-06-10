

#pragma once

#include <VANETSIMULATION/attack/Interface.h>
#include <VANETSIMULATION/attack/dimension/Type.h>
#include <string>

namespace VANETSIMULATION {
namespace attack {
namespace dimension {
class Interface : public attack::Interface {
public:
    void setType(Type const type)
    {
        type_ = type;
    }
    virtual void attack(veins::BasicSafetyMessage* bsm) = 0;

protected:
    void setParams(veins::BasicSafetyMessage* bsm, std::string const& str, double const length, double const width);

private:
    Type type_;
};
} // namespace dimension
} // namespace attack
} // namespace VANETSIMULATION