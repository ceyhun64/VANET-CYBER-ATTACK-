//güvenlik mesajlarının boyutunu sabit ve yükseğe ayarlar

#include <vasp/attack/dimension/High.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace dimension {
void High::attack(veins::BasicSafetyMessage* bsm)
{
    // plausible length range: [0.1, 102.2]m [ETSI TS 102 894-2]
    // plausible width range: [0.1, 6.1]m [ETSI TS 102 894-2]
    double constexpr kLength{102.3};
    double constexpr kWidth{6.2};

    setParams(bsm, "High", kLength, kWidth);
}
} // namespace dimension
} // namespace attack
} // namespace vasp
