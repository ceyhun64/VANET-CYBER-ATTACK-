
//

package vasp.driver;
import org.car2x.veins.modules.application.ieee80211p.DemoBaseApplLayer;

simple CarApp extends DemoBaseApplLayer
{
    parameters:
        @display("i=block/app2");
        @class(vasp::driver::CarApp);

        int    attackPolicy        = default(0); // Persistent = 0, Periodic = 1, Sporadic = 2
        double sporadicInsertionRate = default(0.0);

        string mapFile;
        double maliciousProbability;

        string resultDir = default("results");
        string runID;
        string bsmData = default("genuine"); // gives knowledge of car type on receiving a BSM

        int attackType = default(0);	// 0 - no attack

        int beaconPriority = default(1);
        int nDosMessages = default(1);

        double posAttackOffset @unit(m) = default(10m);
        double dimensionAttackOffset @unit(m) = default(4m);
        double headingAttackOffset @unit(rad) = default(0.5235987756rad);
        double yawRateAttackOffset = default(4);
        double accelerationAttackOffset = default(2);
        double speedAttackOffset @unit(mps) = default(10mps);
}
