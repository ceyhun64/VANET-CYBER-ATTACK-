//ağ bağlantısı yönetimi
#pragma once

#include "veins/base/connectionManager/ConnectionManager.h"

namespace VANETSIMULATION {
namespace connection {
class Manager final : public veins::ConnectionManager {
public:
    double getInterfDist();
};
} // namespace connection
} // namespace VANETSIMULATION