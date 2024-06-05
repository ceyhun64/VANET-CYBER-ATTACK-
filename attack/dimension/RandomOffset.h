

#pragma once

#include <vasp/attack/dimension/Interface.h>

namespace vasp {
namespace attack {
namespace dimension {
class RandomOffset final : public Interface {
public:
    void update(double const offset);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    double offset_;
};
} // namespace dimension
} // namespace attack
} // namespace vasp
