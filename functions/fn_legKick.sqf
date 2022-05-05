params [["_mode","play"],["_params",[]]];
switch (_mode) do {
	case "play" : {
	if (gestureState player == "dr_legkick") exitWith {};
	player playActionNow "Dr_legkick";
	UiSleep 0.8;
	_start = (getPosASL player) vectorAdd [0,0,1];
	_end = (_start vectorAdd ((vectorDir player) vectorMultiply 4));
	_obj = (lineIntersectsSurfaces [_start,_end,player,objNull,true,-1,"GEOM"] param [0,[]]) param [2,objNull];
	if (isNull _obj) exitWith {};
	playSound3D ["Dr_anim_legKick\sounds\" + (selectRandom ["kick_1","kick_2","kick_3","kick_4"]) + ".wss", player, false, getPosASL player, 2, 1, 40];
	
	//ArmA 2.0 ver bug with getRelDir and setUnconscious

	_dir = (vectorDir player) vectorMultiply 1000;
	
	player allowDamage false;
	
	if (_obj isKindOf "Man") then {
		["process",[_obj,_dir]] remoteExec ["Dr_fnc_legKick",_obj];
	};
	player allowDamage true;
	};
	case "process" : {
		_params params ["_obj","_dir"];
		_obj allowDamage false;
		//ArmA 2.04 addForce instead setVelocity and setUnconscious
		_obj addForce [_dir,_obj selectionPosition "SPINE"];
		UiSleep 0.2;
		_obj allowDamage true;
		UiSleep 5;
		_obj setUnconscious false;
	};
};