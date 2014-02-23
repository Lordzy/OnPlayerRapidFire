/*______________________________________________________________________________

					OnPlayerRapidFire - OPRF.inc
					    By Lordz AKA Lordzy
						- 2014

	"OPRF" AKA OnPlayerRapidFire is a simple include which provides a callback
	called "OnPlayerRapidFire" which is called when a player does rapid shots.
	Rapid shots can be harmful for DM servers which are on 0.3z versions as it
	could kill a player in less than a second. This include determines and is
	able to prevent damage caused from rapid shots!
	
      This Source Code Form is subject to the
      terms of the Mozilla Public License, v.
      2.0. If a copy of the MPL was not
      distributed with this file, You can
      obtain one at
      http://mozilla.org/MPL/2.0/.

Author : Lordzâ„¢ AKA Lordzy.

Callbacks:
OnPlayerRapidFire(playerid, weaponid, intervals);
 playerid - returns the player who does rapid shots.
 weaponid - returns the weapon's ID which is being used for rapid shots.
 intervals - returns the difference between the last shot and the current one.

_____________________________________________________________________________*/

#if defined _included_L_OnPlayerRapidFire
	#endinput
#endif

#define _included_L_OnPlayerRapidFire

#tryinclude <a_samp>

static
	Lrapid_oldticks[MAX_PLAYERS] = {0, ...};

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	if(Lrapid_oldticks[playerid] == 0) Lrapid_oldticks[playerid] = GetTickCount();
	else {
		new Lrapid_intervals,
			Lrapid_checkreturn;
		if((Lrapid_intervals = GetTickCount() - Lrapid_oldticks[playerid]) <= 35 && GetPlayerWeapon(playerid) != 38) { //Minigun got a higher fire rate.
	    	Lrapid_checkreturn = CallLocalFunction("OnPlayerRapidFire", "iii", playerid, weaponid, Lrapid_intervals);
		}
		Lrapid_oldticks[playerid] = GetTickCount();
		if(!Lrapid_checkreturn) return 0; //Doesn't allow to call the rest 'OnPlayerWeaponShot' works anymore.
	}
	#if defined LRAPID_OnPlayerWeaponShot
	return LRAPID_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
	#else
	return 1;
	#endif
}

	
public OnPlayerConnect(playerid)
{
	Lrapid_oldticks[playerid] = 0;
	#if defined LRAPID_OnPlayerConnect
	LRAPID_OnPlayerConnect(playerid);
	#endif
	return 1;
}


#if defined _ALS_OnPlayerWeaponShot
	#undef OnPlayerWeaponShot
#else
	#define _ALS_OnPlayerWeaponShot
#endif

#define OnPlayerWeaponShot LRAPID_OnPlayerWeaponShot

#if defined LRAPID_OnPlayerWeaponShot
forward LRAPID_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
#endif

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect LRAPID_OnPlayerConnect

#if defined LRAPID_OnPlayerConnect
forward LRAPID_OnPlayerConnect(playerid);
#endif

forward OnPlayerRapidFire(playerid, weaponid, intervals);
/*
playerid - returns the player who does rapid shots.
weaponid - returns the weapon's ID which is being used for rapid shots.
intervals - returns the difference between the last shot and the current one.*/

