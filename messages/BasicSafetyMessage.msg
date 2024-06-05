//araç konumları ve hızları

import veins.base.utils.Coord;
import vasp.messages.Heading;
import veins.base.utils.SimpleAddress;
import veins.modules.messages.DemoSafetyMessage;

namespace veins;

packet BasicSafetyMessage extends veins::DemoSafetyMessage {
    int msgCount;
	double msgGenerationTime;
    veins::LAddress::L2Type address = -1;
	double acceleration;
	Heading heading;
	string attackType = "Genuine";
	double width = 2.0; //meters
	double length = 5.0; //meters
	double height = 1.8; //meters
	veins::LAddress::L2Type recipientId = -1;
	double yawRate;
	string data;

	// Vehicle Safety Extensions
	bool eventHardBraking = false;
}
