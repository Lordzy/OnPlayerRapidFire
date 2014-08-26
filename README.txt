					OnPlayerRapidFire - OPRF.inc
					    By Lordz AKA Lordzy
						- 2014

						Version : 3
	
	"OPRF" AKA OnPlayerRapidFire is an include which provides a callback called
	"OnPlayerRapidFire" which is called when a player does rapid fire cheat.
	Rapid shots, especially on DM servers with lagcompmode 'On' can be very -
	harmful because quick kills are possible with rapid fires. This include
	detects if a player does rapid fire or not for the following weapons :
	
	    Colt,
	    Desert Eagle,
	    Silenced Pistol,
	    Shotgun,
	    Sawnoff Shotgun,
	    Combat Shotgun,
		Uzi,
		MP5,
		Tec9,
		AK47,
		M4,
		Country Rifle,
		Sniper Rifle.

      This Source Code Form is subject to the
      terms of the Mozilla Public License, v.
      2.0. If a copy of the MPL was not
      distributed with this file, You can
      obtain one at
      http://mozilla.org/MPL/2.0/.

Author : Lordz AKA Lordzy.

Callbacks:
OnPlayerRapidFire(playerid, weaponid, intervals);
 playerid - returns the player who does rapid shots.
 weaponid - returns the weapon's ID which is being used for rapid shots.
 intervals - returns the difference between the last shot and the current one.

Changelogs:

23-02-2014
 - Initial Release.
 - Fixed some issues with arrays.
 - Fixed the problem for sub-machine guns like Tec9 (ID:32) and uzi (ID:28)

24-02-2014 (v2 Released)
 - Added support for Sniper Rifle and Country Rifle.
 (Thanks to 'West X' for reporting about it)

26-8-2014

 - Improved the way of detection.
 - Added : GetPlayerLastShotTick which would return the last shot time data.
