

#pragma once

#include <omnetpp/csimplemodule.h>
#include <omnetpp/simtime_t.h>
#include <string>

// forward declarations
namespace veins {
class BasicSafetyMessage;
}

namespace vasp {
namespace logging {
class TraceManager final : public omnetpp::cSimpleModule {
public:
    void initialize(int const stage) override;
    int numInitStages() const override;

    void logTrace(
        veins::BasicSafetyMessage const* rvBsm,
        veins::BasicSafetyMessage const* hvBsm,
        omnetpp::simtime_t_cref bsmReceiveTime,
        bool const eeblWarning,
        bool const imaWarning);

private:
    void writeHeader() const noexcept;

private:
    // Variables to define logging path
    std::string filepath_{};
};
} // namespace logging
} // namespace vasp
