

#include <vasp/attack/dimension/Low.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace dimension {
void Low::attack(veins::BasicSafetyMessage* bsm)
{
    // plausible length range: [0.1, 102.2]m [ETSI TS 102 894-2]
    // plausible width range: [0.1, 6.1]m [ETSI TS 102 894-2]
    double constexpr kLength{0.09};
    double constexpr kWidth{0.09};

    setParams(bsm, "Low", kLength, kWidth);
}
} // namespace dimension
} // namespace attack
} // namespace vasp
