OnPlayerRapidFire
=================

"OnPlayerRapidFire" is a callback which gets called for 0.3z SA-MP versions when a player does rapid fire. "Rapid Fire" is a cheat which could be done through Cleo scripts and could entirely be harmful for DM servers. This anti-cheat can prevent and determine rapid shots.

Currently, there's a small issue in with detecting assault rifles which will be soon fixed. So while using the callback, give exception to assault rifles or do a warning system in regarding detecting Assault rifles.


new
  LastAssaultRapid[MAX_PLAYERS],
  AssaultRapidCounts[MAX_PLAYERS];

public OnPlayerRapidFire(playerid, weaponid, intervals)
{

  if(weaponid == 31 || weaponid == 30)
  {
    if((GetTickCount() - LastAssaultRapid[playerid]) <= 40)
    {
      AssaultRapidCounts[playerid]++;
      LastAssaultRapid[playerid] = GetTickCount();
    }
    else 
    {
      if(AssaultRapidCounts[playerid] >= 1)
      {
        AssaultRapidCounts[playerid]--;
        return 1;
      }
    }
    if(AssaultRapidCounts[playerid] >= 5)
    {
      //The stuffs to do: (Probably kick ?)
      return 0;
    }
  }
  return 0;
}

public OnPlayerConnect(playerid)
{
  AssaultRapidCounts[playerid] = 0;
  LastAssaultRapid[playerid] = 0;
  return 1;
}
