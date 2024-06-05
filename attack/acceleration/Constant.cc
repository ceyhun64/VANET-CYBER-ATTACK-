//güvenlik mesajlarının içeriğini manipüle 

#include <vasp/attack/acceleration/Constant.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace acceleration {
void Constant::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("ConstantAcceleration");
    bsm->setAcceleration(5);
}
} // namespace acceleration
} // namespace attack
} // namespace vasp