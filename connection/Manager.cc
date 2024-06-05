
#include <vasp/connection/Manager.h>

namespace vasp {
namespace connection {

Define_Module(Manager);

double Manager::getInterfDist()
{
    return calcInterfDist();
}

} // namespace connection
} // namespace vasp
