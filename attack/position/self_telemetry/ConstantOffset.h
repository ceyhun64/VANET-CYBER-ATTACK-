

#pragma once

#include <vasp/attack/Interface.h>

namespace vasp {
namespace attack {
namespace position {
class ConstantOffset final : public Interface {
public:
    ConstantOffset(double const offset);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    double offset_{};
};
} // namespace position
} // namespace attack
} // namespace vasp