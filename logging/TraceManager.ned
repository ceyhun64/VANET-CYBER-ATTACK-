
// TraceManager - manages trace writing in AMPS

package VANETSIMULATION.logging;

//
// manages trace writing in AMPS
//
simple TraceManager
{
    parameters:
        string filepath = default("results/trace.log");
        @display("i=msg/paperclip");
        @labels(node);
        @class(VANETSIMULATION::logging::TraceManager);
}