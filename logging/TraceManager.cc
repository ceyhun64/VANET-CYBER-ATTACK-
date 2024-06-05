//simülasyon analiz

#include <CSVWriter.h>
#include <veins/modules/mobility/traci/TraCICommandInterface.h>
#include <vasp/logging/TraceManager.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace logging {

Define_Module(TraceManager);

void TraceManager::initialize(int const stage)
{
    if (stage == 0) {
        filepath_ = par("filepath").stdstringValue();
    }

    if (stage == 1) {
        writeHeader();
    }
}

int TraceManager::numInitStages() const
{
    return std::max(cSimpleModule::numInitStages(), 2);
}

void TraceManager::logTrace(
    veins::BasicSafetyMessage const* rvBsm,
    veins::BasicSafetyMessage const* hvBsm,
    omnetpp::simtime_t_cref bsmReceiveTime,
    bool const eeblWarning,
    bool const imaWarning)
{
    CSVWriter csv{","};

    // clang-format off
    // columns useful for quick sorting/analysis
    csv << rvBsm->getAddress()
        << hvBsm->getAddress()
        << rvBsm->getRecipientId()
        << rvBsm->getMsgGenerationTime()
        << bsmReceiveTime

        // remote vehicle columns
        << rvBsm->getMsgCount()
        << rvBsm->getData()
        << rvBsm->getSenderPos().x
        << rvBsm->getSenderPos().y
        << rvBsm->getSenderPos().z
        << rvBsm->getSenderSpeed().length()
        << rvBsm->getAcceleration()
        << rvBsm->getHeading().getRad()
        << rvBsm->getYawRate()
        << rvBsm->getLength()
        << rvBsm->getWidth()
        << rvBsm->getHeight()

        // host vehicle columns
        << hvBsm->getMsgCount()
        << hvBsm->getData()
        << hvBsm->getSenderPos().x
        << hvBsm->getSenderPos().y
        << hvBsm->getSenderPos().z
        << hvBsm->getSenderSpeed().length()
        << hvBsm->getAcceleration()
        << hvBsm->getHeading().getRad()
        << hvBsm->getLength()
        << hvBsm->getWidth()
        << hvBsm->getHeight()

        // ground truth columns
        << rvBsm->getAttackType()

        // v2x-applications columns
        << eeblWarning
        << imaWarning;
    // clang-format on

    csv.writeToFile(filepath_, true);
}

void TraceManager::writeHeader() const noexcept
{
    CSVWriter csv{","};

    // general columns for quick sorting/analysis
    csv << "rv_id"
        << "hv_id"
        << "target_id"
        << "msg_generation_time"
        << "msg_rcv_time"

        // remote vehicle columns
        << "rv_msg_count"
        << "rv_wsm_data"
        << "rv_pos_x"
        << "rv_pos_y"
        << "rv_pos_z"
        << "rv_speed"
        << "rv_accel"
        << "rv_heading"
        << "rv_yaw_rate"
        << "rv_length"
        << "rv_width"
        << "rv_height"

        // host vehicle columns
        << "hv_msg_count"
        << "hv_wsm_data"
        << "hv_pos_x"
        << "hv_pos_y"
        << "hv_pos_z"
        << "hv_speed"
        << "hv_accel"
        << "hv_heading"
        << "hv_length"
        << "hv_width"
        << "hv_height"

        // ground truth columns
        << "attack_type"

        // v2x-applications columns
        << "eebl_warn"
        << "ima_warn";

    csv.writeToFile(filepath_);
}

} // namespace logging
} // namespace vasp