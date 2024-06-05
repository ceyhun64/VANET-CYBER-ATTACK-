

#pragma once

#include "veins/base/connectionManager/ConnectionManager.h"

namespace vasp {
namespace connection {
class Manager final : public veins::ConnectionManager {
public:
    double getInterfDist();
};
} // namespace connection
} // namespace vasp