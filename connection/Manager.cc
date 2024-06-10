//ağ simülasyonu ve yönetim
#include <VANETSIMULATION/connection/Manager.h>

namespace VANETSIMULATION {
namespace connection {

Define_Module(Manager);

double Manager::getInterfDist()
{
    return calcInterfDist();
}

} // namespace connection
} // namespace VANETSIMULATION
