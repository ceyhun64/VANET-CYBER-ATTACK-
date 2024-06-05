
// TraceManager - manages trace writing in AMPS

package vasp.logging;

//
// manages trace writing in AMPS
//
simple TraceManager
{
    parameters:
        string filepath = default("results/trace.log");
        @display("i=msg/paperclip");
        @labels(node);
        @class(vasp::logging::TraceManager);
}