#define FILTERSCRIPT //It's a filterscript version.
#include <a_samp>
#include <OPRF>

public OnPlayerRapidFire(playerid, weaponid, intervals)
{
  return !Kick(playerid);
}
