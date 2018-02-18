#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_

#include <WPILib.h>
#include <SerialPort.h>
#include <CompPrefs.h>
#include <CompPrefsAutonomous.h>
#include <DiffDrive.h>
#include <Collector.h>
#include <CollectorArm.h>
#include <JrimmyGyro.h>
#include <AutonomousHelper.h>
#include <UltrasonicSerial.h>

enum AutoStateV0 {
	kMoveToSwitch0 = 0,
	kAutoIdle0
};

enum AutoStateV1 {
	kMoveToSwitch1 = 0,
	kMoveArm1,
	kReleaseCube1,
	kAutoIdle1
};

enum AutoStateV2 {
	kMoveToSideOfSwitch = 0,
	kTurnLeft2,
	kMoveToEdgeOfSwitch,
	kMoveArm2,
	kReleaseCube2,
	kAutoIdle2
};

enum AutoStateV3 {
	kMoveToSideOfScale = 0,
	kTurnLeft3,
	kMoveToEdgeOfScale,
	kMoveArm3,
	kReleaseCube3,
	kAutoIdle3
};

enum AutoStateV4
{
	kMoveHalfToSwitch = 0,
	kTurnRight4,
	kMoveFlushWithSwitch,
	kTurnLeft4,
	kMoveToFrontOfSwitch,
	kMoveArm4,
	kReleaseCube4,
	kAutoIdle4
};

enum AutoStateV5
{
	kMoveTopOfSwitch = 0,
	kTurnRight5,
	kMoveFlushWithScale,
	kTurnLeft5,
	kMoveToFrontOfScale,
	kMoveArm5,
	kReleaseCube5,
	kAutoIdle5
};

class Autonomous
{
public:
	Autonomous(AutonomousHelper &AutoBot, CollectorArm &CollectorArm, DiffDrive &DiffDrive, JrimmyGyro &Gyro, SerialPort &Arduino, UltrasonicSerial &UltraSoul);
	virtual ~Autonomous() = default;
	void Init();
	void AutonomousPeriodicV0();
    void AutonomousPeriodicV1();
    void AutonomousPeriodicV2();
    void AutonomousPeriodicV3();
    void AutonomousPeriodicV4();
    void AutonomousPeriodicV5();
private:
	AutonomousHelper &a_AutoBot;

	CollectorArm &a_CollectorArm;

	DiffDrive &a_DiffDrive;

	JrimmyGyro &a_Gyro;

	SerialPort &a_Arduino;

	UltrasonicSerial &a_UltraSoul;

	AutoStateV0 a_AutoStateV0;
    AutoStateV1 a_AutoStateV1;
    AutoStateV2 a_AutoStateV2;
    AutoStateV3 a_AutoStateV3;
    AutoStateV4 a_AutoStateV4;
    AutoStateV5 a_AutoStateV5;

};

#endif
