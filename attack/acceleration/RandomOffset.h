

#pragma once

#include <vasp/attack/Interface.h>

namespace vasp {
namespace attack {
namespace acceleration {
class RandomOffset final : public Interface {
public:
    RandomOffset(double const offset);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    double offset_{};
};
} // namespace acceleration
} // namespace attack
} // namespace vasp