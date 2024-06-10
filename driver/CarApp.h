//araçlar arası iletişim
#pragma once

#include <json.h>
#include <memory>
#include <omnetpp/simtime_t.h>
#include <string>
#include <VANETSIMULATION/attack/AttackPolicy.h>
#include <veins/modules/application/ieee80211p/DemoBaseApplLayer.h>

// forward declarations

namespace VANETSIMULATION {
namespace attack {
class Interface;
} // namespace attack

namespace logging {
class TraceManager;
} // namespace logging

namespace connection {
class Manager;
} // namespace connection
} // namespace VANETSIMULATION

using json = nlohmann::json;

namespace veins {
class BasicSafetyMessage;
} // namespace veins

namespace VANETSIMULATION {
namespace driver {
class CarApp final : public veins::DemoBaseApplLayer {
public:
    void initialize(int stage) override;
    void finish() override;

protected:
    void handleSelfMsg(cMessage* msg) override;
    void handlePositionUpdate(cObject* obj) override;
    void onBSM(veins::DemoSafetyMessage* dsm) override;
    void populateWSM(veins::BaseFrame1609_4* wsm, veins::LAddress::L2Type rcvId = veins::LAddress::L2BROADCAST(), int serial = 0) override;

private:
    void writeTrace(veins::BasicSafetyMessage const* rvBsm, simtime_t_cref rvBsmReceiveTime);
    void runIMA();
    void executeV2XApplications(veins::BasicSafetyMessage const* rvBsm);
    void injectGhostAttack(veins::BasicSafetyMessage const* bsm);
    void injectAttack(veins::BasicSafetyMessage* bsm);
    void setUniqueGhostAddress(std::string const& key, veins::BasicSafetyMessage* ghostBsm);
    void setGhostMsgCount(std::string const& key, veins::BasicSafetyMessage* ghostBsm);

private:
    VANETSIMULATION::logging::TraceManager* traceManager_;
    veins::BaseWorldUtility* world_;
    VANETSIMULATION::connection::Manager* connManager_;

    std::string resultDir_;
    std::string simRunID_;
    std::string bsmData_;

    // IMA related
    std::shared_ptr<cMessage> runIMA_{nullptr};
    bool approachingIntersection_{false};
    veins::Coord junctionPos_;
    std::string mapFile_;
    json mapJson_;

    // attack related
    int attackType_;
    std::shared_ptr<VANETSIMULATION::attack::Interface> attack_{nullptr};
    std::shared_ptr<VANETSIMULATION::attack::Interface> ghostAttack_{nullptr};
    int nDosMessages_;
    VANETSIMULATION::attack::AttackPolicy attackPolicy_;
    double sporadicInsertionRate_;
    double maliciousProbability_;
    bool isMalicious_;
    double posAttackOffset_{};
    double dimensionAttackOffset_{};
    double headingAttackOffset_{};
    double yawRateAttackOffset_{};
    double accelerationAttackOffset_{};
    double speedAttackOffset_{};

    // V2X apps related
    bool eeblWarning_{};
    bool imaWarning_{};

    // yaw-rate calculation related
    simtime_t prevBeaconTime_{-1};
    veins::Heading prevHvHeading_{INFINITY};
    double curYawRate_{-1.0};
    simtime_t lastUpdate_{-1.0};
    double lastAngleRad_{-1.0};

    // ghost vehicle related
    std::map<std::string, int> ghostMsgCountMap_;
    std::map<std::string, long> ghostRvIdMap_;
    double ghostVehicleDistance_{0.0};
    veins::Coord ghostPos_;
    bool targetConstPosAttackFlag_{true};
};
} // namespace driver
} // namespace VANETSIMULATION
