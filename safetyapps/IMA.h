//ıma devamı

#pragma once

namespace veins {
class Coord;
class BasicSafetyMessage;
} // namespace veins

namespace VANETSIMULATION {
namespace safetyapps {
class IMA final {
public:
    bool warning(
        veins::Coord const& myPos,
        veins::Coord const& mySpeed,
        veins::BasicSafetyMessage const* rvBsm,
        veins::Coord const& junctionPos);
};
} // namespace safetyapps
} // namespace VANETSIMULATION