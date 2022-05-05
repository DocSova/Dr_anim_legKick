class CfgPatches
{
	class Dr_anim_legKick
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.0099999998;
		requiredAddons[]= {"A3_Anims_F_Mark_Deployment","A3_Anims_F","A3_Anims_F_Exp_A","A3_Anims_F_Exp_Revive","A3_Anims_F_Config_Sdr"};
		version=1;
	};
};

class CfgMovesBasic
{
	class ManActions {
        Dr_legKick = "Dr_legKick";
    };
    class Actions {
        class NoActions: ManActions {
            Dr_legKick[] = {"Dr_legKick", "Gesture"};
        };
    };
};

class CfgFunctions
{
	class Dr
	{
		class Main
		{
			file = "Dr_anim_legKick\functions";
			class legKick {};
		};
	};
};

class CfgUserActions
{
	class DrlegKick
	{
		displayName = "leg kick";
		tooltip = "leg kick action";
		onActivate = "['play',[_this]] spawn Dr_fnc_legKick";
		onDeactivate = "";
		onAnalog = "";
		analogChangeThreshold = 0.1;
	};
};

class CfgDefaultKeysPresets
{
	class Arma2
	{
		class Mappings
		{
			DrlegKick[] = {
				0x15 // DIK_Y
			};
		};
	};
};

class UserActionGroups
{
	class DrlegKickSection
	{
		name = "leg Kick";
		isAddon = 1;
		group[] = {"DrlegKick"};
	};
};

class CfgGesturesMale {
    class BlendAnims {
       Dr_legKick_blend[] = {"Pelvis", 1, "Spine", 1, "Spine1", 1, "Spine2", 1, "Spine3", 1, "Camera", 1, "launcher", 1, "neck", 1, "neck1", 1, "head", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "LeftUpLeg", 1, "LeftUpLegRoll", 1, "LeftLeg", 1, "LeftLegRoll", 1, "LeftFoot", 1, "LeftToeBase", 1, "RightUpLeg", 1, "RightUpLegRoll", 1, "RightLeg", 1, "RightLegRoll", 1, "RightFoot", 1, "RightToeBase", 1};
    };

    class States {
		class GestureCeaseFire ;
        class Dr_legKick_base: GestureCeaseFire {
			actions = "NoActions";
			canPullTrigger = 0;
			connectAs = "";
			connectFrom[] = {};
			connectTo[] = {};
			disableWeapons = 0;
			enableBinocular = 1;
			enableMissile = 1;
			enableOptics = 0;
			equivalentTo = "";
			file = "\A3\anims_f\Data\Anim\Sdr\gst\GestureHi.rtm";
			forceAim = 0;
			headBobMode = 0;
			headBobStrength = 0;
			interpolateFrom[] = {};
			interpolateTo[] = {};
			interpolateWith[] = {};
			interpolationRestart = 0;
			interpolationSpeed = 6;
			looped = 0;
			minPlayTime = 0.5;
			preload = 0;
			ragdoll = 0;
			relSpeedMax = 1;
			relSpeedMin = 1;
			showHandGun = 0;
			showItemInHand = 0;
			showItemInRightHand = 0;
			showWeaponAim = 1;
			soundEdge[] = {0.5,1};
			soundEnabled = 1;
			soundOverride = "";
			speed = -2;
			static = 0;
			terminal = 0;
			Walkcycles = 1;
			weaponIK = 1;

			leftHandIKBeg = 1;
			LeftHandIKCurve[] = {0,1,0.05,0,0.95,0,1,1};
			leftHandIKEnd = 1;

			rightHandIKBeg = 1;
			RightHandIKCurve[] = {0,1,0.05,0,0.95,0,1,1};
			rightHandIKEnd = 1;
		};
		class Dr_legkick: Dr_legKick_base {
			file = "Dr_anim_legKick\anims\kick.rtm";
			speed = 0.6666666666666667;
		    mask = "Dr_legKick_blend";
		};
	};
};