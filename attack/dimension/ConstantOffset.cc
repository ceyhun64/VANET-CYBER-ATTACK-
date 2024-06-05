//güvenlik mesajlarının boyutunu sabit offsetle değiştirir

#include <vasp/attack/dimension/ConstantOffset.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace dimension {
void ConstantOffset::update(double const offset)
{
    offset_ = offset;
}

void ConstantOffset::attack(veins::BasicSafetyMessage* bsm)
{
    // plausible length range: [0.1, 102.2]m [ETSI TS 102 894-2]
    // plausible width range: [0.1, 6.1]m [ETSI TS 102 894-2]
    double const kLength{bsm->getLength() + offset_};
    double const kWidth{bsm->getWidth() + offset_};

    setParams(bsm, "ConstantOffset", kLength, kWidth);
}
} // namespace dimension
} // namespace attack
} // namespace vasp
