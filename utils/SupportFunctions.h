

#pragma once

#include <cmath>
#include <veins/base/utils/Coord.h>
#include <veins/base/utils/Heading.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <vasp/utils/SupportFunctions.h>

namespace vasp {
namespace utils {

inline double toPositiveAngle(double angle)
{
    angle = std::fmod(angle, 360);
    while (angle < 0)
        angle += 360.0;
    return angle;
}

inline bool isBehind(veins::Coord const& p0, veins::Coord const& p2, veins::Heading const& direction)
{
    double const angle{toPositiveAngle(direction.getRad() * 180 / M_PI)};

    // east bound
    if (angle == 0 || angle == 360) {
        // choose point perpendicularly below x axis
        veins::Coord const p1{p0.x, p0.y + 5};
        return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x) > 0;
    }
    // north-east bound
    else if (angle > 0 && angle < 90) {
        // choose point on positive y axis
        veins::Coord const p1{0, p0.y};
        return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x) > 0;
    }
    // north bound
    else if (angle == 90) {
        // choose point perpendicularly left of y axis
        veins::Coord const p1{p0.x - 5, p0.y};
        return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x) > 0;
    }
    // north-west bound
    else if (angle > 90 && angle < 180) {
        // choose point on positive y axis
        veins::Coord const p1{0, p0.y};
        return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x) < 0;
    }
    // west bound
    else if (angle == 180) {
        // choose point perpendicularly above x axis
        veins::Coord const p1{p0.x, p0.y + 5};
        return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x) < 0;
    }
    // south-west bound
    else if (angle > 180 && angle < 270) {
        // choose point on negative y axis
        veins::Coord const p1{0, p0.y};
        return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x) > 0;
    }
    // south bound
    else if (angle == 270) {
        // choose point perpendicularly right of y-axis
        veins::Coord const p1{p0.x + 5, p0.y};
        return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x) > 0;
    }
    // south-east bound
    else if (angle > 270 && angle < 360) {
        // choose point on negative y-axis
        veins::Coord const p1{0, p0.y};
        return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x) < 0;
    }
    return false;
}

inline double getSafetyDistance(veins::Coord const& speed)
{
    // https://en.wikipedia.org/wiki/Braking_distance#Total_stopping_distance
    // D_total = D_perceptionToReaction + D_braking
    //         = v*t_perceptionToReaction + v^2/2*mu*g
    // common baseline value for t_perceptionToReaction = 1.5s, mu = 0.7, g = 9.8m/s^2
    // i.e. 2*mu*g = 13.72931 m/s^2

    auto const rmsSpeed = speed.length(); // m/s
    auto constexpr timeBetweenPerceptionToReaction = 1.5; // seconds
    auto constexpr mu = 0.7; // friction coefficient
    auto constexpr g = 9.8; // m/s^2
    auto const distanceTraveledBetweenPerceptionToReaction = rmsSpeed * timeBetweenPerceptionToReaction; // m
    auto const distanceTraveledDuringBraking = (rmsSpeed * rmsSpeed) / (2 * mu * g); // m

    return distanceTraveledBetweenPerceptionToReaction + distanceTraveledDuringBraking;
}

inline veins::Coord getPosOffset(veins::BasicSafetyMessage const* rvBsm, double const& offset)
{
    veins::Coord const heading{rvBsm->getHeading().toCoord()};
    veins::Coord const pos{rvBsm->getSenderPos()};
    return pos + heading * offset; // equivalent to return attacker_pos + (distance + attacker_pos.distance(target_pos)) * u;
}

} // namespace utils
} // namespace vasp