//bsm ye boyut değişikliği atar

#include <vasp/attack/dimension/Interface.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace dimension {
void Interface::setParams(veins::BasicSafetyMessage* bsm, std::string const& str, double const length, double const width)
{
    switch (type_) {
    case kDimensionAttackTypeLength: {
        bsm->setAttackType((str + "Length").c_str());
        bsm->setLength(length);
        break;
    }
    case kDimensionAttackTypeWidth: {
        bsm->setAttackType((str + "Width").c_str());
        bsm->setWidth(width);
        break;
    }
    case kDimensionAttackTypeBoth: {
        bsm->setAttackType((str + "Dimension").c_str());
        bsm->setLength(length);
        bsm->setWidth(width);
        break;
    }
    }
}
} // namespace dimension
} // namespace attack
} // namespace vasp