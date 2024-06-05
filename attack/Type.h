

#pragma once

namespace vasp {
namespace attack {
enum Type {
    _kAttackMinValue = -1,
    // No attacks
    kAttackNo,

    // Position attacks (self telemetry based)
    kAttackRandomPosition,
    kAttackRandomPositionOffset,
    kAttackConstantPositionOffset,
    kAttackPlaygroundConstantPosition,
    kAttackSuddenDisappearance,

    // Position attacks (ghost vehicle based)
    kAttackSuddenAppearance,
    kAttackTargetedConstantPosition,

    // Mobility attacks (ghost vehicle based)
    kAttackCommRangeBraking,

    // Channel attacks
    kAttackDenialOfService,

    // EEBL-specific attacks (ghost vehicle based)
    kAttackFakeEEBLJustAttack,
    kAttackFakeEEBLStopPositionUpdateAfterAttack,

    // IMA-specific attacks
    kAttackIMAPosOffset,
    kAttackIMAJunctionPos,
    kAttackIMAHighSpeed,
    kAttackIMALowSpeed,
    kAttackIMAHighAcceleration,
    kAttackIMALowAcceleration,

    // Dimension attacks
    kAttackHighDimension,
    kAttackLowDimension,
    kAttackRandomDimension,
    kAttackRandomDimensionOffset,
    kAttackConstantDimensionOffset,
    kAttackBadRatioDimension,

    // Length attacks
    kAttackHighLength,
    kAttackLowLength,
    kAttackRandomLength,
    kAttackRandomLengthOffset,
    kAttackConstantLengthOffset,
    kAttackBadRatioLength,

    // Width attacks
    kAttackHighWidth,
    kAttackLowWidth,
    kAttackRandomWidth,
    kAttackRandomWidthOffset,
    kAttackConstantWidthOffset,
    kAttackBadRatioWidth,

    // Heading attacks
    kAttackOppositeHeading,
    kAttackPerpendicularHeading,
    kAttackRotatingHeading,
    kAttackConstantHeading,
    kAttackRandomHeading,
    kAttackRandomHeadingOffset,
    kAttackConstantHeadingOffset,

    // Yaw-rate attacks
    kAttackHighYawRate,
    kAttackLowYawRate,
    kAttackConstantYawRate,
    kAttackRandomYawRate,
    kAttackRandomYawRateOffset,
    kAttackConstantYawRateOffset,

    // Heading and Yaw-rate matching attacks
    kAttackHighHeadingYawRate,
    kAttackLowHeadingYawRate,
    kAttackConstantHeadingYawRate,
    kAttackRandomHeadingYawRate,
    kAttackRandomHeadingYawRateOffset,
    kAttackConstantHeadingYawRateOffset,

    // Acceleration attacks
    kAttackHighAcceleration,
    kAttackLowAcceleration,
    kAttackConstantAcceleration,
    kAttackRandomAcceleration,
    kAttackRandomAccelerationOffset,
    kAttackConstantAccelerationOffset,

    // Speed attacks
    kAttackHighSpeed,
    kAttackLowSpeed,
    kAttackConstantSpeed,
    kAttackRandomSpeed,
    kAttackRandomSpeedOffset,
    kAttackConstantSpeedOffset,

    // All attack randomly chosen
    kAttackRandomlySelectedAttack,
    kAttackAlwaysRandomAttack,

    _kAttackMaxValue
};
} // namespace attack
} // namespace vasp