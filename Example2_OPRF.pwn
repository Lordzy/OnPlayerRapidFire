#define FILTERSCRIPT //It's a filterscript version.
#include <a_samp>
#include <OPRF2>

new
	bool:OPRF_Processed[MAX_PLAYERS] = {false, ...};

public OnPlayerConnect(playerid)
{
	OPRF_Processed[playerid] = false;
	return 1;
}

public OnFilterScriptInit()
{
	for(new i = 0; i< GetMaxPlayers(); i++) {
	    if(!IsPlayerConnected(i)) continue;
	    OPRF_Processed[i] = false;
	}
	return 1;
}

public OnPlayerRapidFire(playerid, weaponid, intervals)
{
	if(OPRF_Processed[playerid] == true) return 0;
	new
		string[128],
		Lname[MAX_PLAYER_NAME];
	GetPlayerName(playerid, Lname, sizeof(Lname));
	format(string, sizeof(string), "AntiCheat : %s (ID:%d) has been kicked from the server! (Reason : Rapid Fire with weapon ID %d in %d milli seconds)", Lname, playerid, weaponid, intervals);
	SendClientMessageToAll(0xFF0000FF, string);
	OPRF_Processed[playerid] = true;
	return !SetTimerEx("OPRFKickPlayer", 150, false, "d", playerid);
}


forward OPRFKickPlayer(playerid);
public OPRFKickPlayer(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	Kick(playerid);
	return 1;
}


