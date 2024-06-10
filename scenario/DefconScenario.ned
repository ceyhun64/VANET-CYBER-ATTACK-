

import org.car2x.veins.nodes.RSU;
import org.car2x.veins.nodes.Scenario;
import VANETSIMULATION.connection.Manager;
import VANETSIMULATION.logging.TraceManager;

network DefconScenario extends Scenario
{
    submodules:
        rsu[1]: RSU {
            @display("p=150,140;i=veins/sign/yellowdiamond;is=vs");
        }
        connectionManager : Manager {
            parameters:
                @display("p=150,0;i=abstract/multicast");
        }
        traceManager : TraceManager {
            @display("p=115,30");
        }
}
