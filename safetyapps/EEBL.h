//eebl in devamı araç güvenliği

#pragma once

// forward declarations
namespace veins {
class BasicSafetyMessage;
class Coord;
class Heading;
} // namespace veins

namespace VANETSIMULATION {
namespace safetyapps {
class EEBL final {
public:
    bool warning(
        veins::BasicSafetyMessage const* bsm,
        const veins::Coord& myPos,
        const veins::Heading& myDirection,
        const veins::Coord& mySpeed,
        int const myId);
};
} // namespace safetyapps
} // namespace VANETSIMULATION