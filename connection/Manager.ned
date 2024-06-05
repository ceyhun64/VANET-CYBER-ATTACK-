

package vasp.connection;
import org.car2x.veins.base.connectionManager.ConnectionManager;

simple Manager extends org.car2x.veins.base.connectionManager.ConnectionManager
{
    parameters:
        @class(vasp::connection::Manager);
        @display("i=abstract/multicast");
}

