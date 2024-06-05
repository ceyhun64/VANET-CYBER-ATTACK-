

#include <veins/base/utils/Heading.h>
#include <vasp/attack/heading/Interface.h>

namespace vasp {
namespace attack {
namespace heading {

veins::Heading const Interface::getNewHeading(veins::Heading const& prevHeading, double const yawRate, simtime_t_cref prevBeaconTime) const
{
    auto tmpHeading{prevHeading.getRad() + yawRate * (simTime() - prevBeaconTime).dbl()};

    // sanitize heading to fall within 2*Pi
    while (tmpHeading > 2 * M_PI) {
        tmpHeading -= 2 * M_PI;
    }

    return veins::Heading(tmpHeading);
}

} // namespace heading
} // namespace attack
} // namespace vasp