//güvenlik mesajlarının içeriğini manipüle 

#include <VANETSIMULATION/attack/acceleration/Constant.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace acceleration {
void Constant::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("ConstantAcceleration");
    bsm->setAcceleration(5);
}
} // namespace acceleration
} // namespace attack
} // namespace VANETSIMULATION