void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.85 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		// Static Items - Bag, Bandages, Flare
		player.GetInventory().CreateInInventory( "ImprovisedBag" );
		player.GetInventory().CreateInInventory( "Roadflare" );
		// Assign Roadflare to slot 3
		
		// Random Food Item(s)
		string foodArray[] = { "BakedBeansCan_Opened", "TacticalBaconCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened" };
		int foodIndex = Math.RandomInt( 0, 3 );
		player.GetInventory().CreateInInventory( foodArray[foodIndex] );
		
		// Random Beret
		string beretArray[] = { "MilitaryBeret_CDF", "MilitaryBeret_ChDKZ", "MilitaryBeret_NZ", "MilitaryBeret_Red", "MilitaryBeret_UN" };
		int beretIndex = Math.RandomInt( 0, 4 );
		player.GetInventory().CreateInInventory( beretArray[beretIndex] );
		
		// Random Sweater		
		string sweaterArray[] = { "Sweater_Blue", "Sweater_Gray", "Sweater_Green", "Sweater_Red" };
		int sweaterIndex = Math.RandomInt( 0, 3 );
		player.GetInventory().CreateInInventory( sweaterArray[sweaterIndex] );
		
		// Static Items - Heatpack
		player.GetInventory().CreateInInventory( "Heatpack" );

		// Random Pants
		string pantsArray[] = { "CargoPants_Beige", "CargoPants_Black", "CargoPants_Blue", "CargoPants_Green", "CargoPants_Grey" };
		int pantsIndex = Math.RandomInt( 0, 4 );
		player.GetInventory().CreateInInventory( pantsArray[pantsIndex] );
		
		// Static Items - Bag, Bandages, Flare
		player.GetInventory().CreateInInventory( "Bandages" );
		player.GetInventory().CreateInInventory( "Bandages" );
		// Assign Bandages to slot 2
		
		// Random Shoes
		string shoesArray[] = { "HikingBootsLow_Beige", "HikingBootsLow_Black", "HikingBootsLow_Blue", "HikingBootsLow_Grey" };
		int shoesIndex = Math.RandomInt( 0, 3 );
		player.GetInventory().CreateInInventory( shoesArray[shoesIndex] );
		
		// Random Gloves
		string gloveArray[] = { "WoolGlovesFingerless_Black", "WoolGlovesFingerless_Green", "WoolGlovesFingerless_Tan", "WoolGlovesFingerless_White" };
		int gloveIndex = Math.RandomInt( 0, 3 );
		player.GetInventory().CreateInInventory( gloveArray[gloveIndex] );
		
		// Random Bandana
		string danaArray[] = { "Bandana_Blackpattern", "Bandana_Camopattern", "Bandana_Greenpattern", "Bandana_Polkapattern", "Bandana_Redpattern" };
		int danaIndex = Math.RandomInt( 0, 4 );
		player.GetInventory().CreateInInventory( danaArray[danaIndex] );
		
		// Random Armband
		string armbArray[] = { "Armband_APA", "Armband_Bear", "Armband_CHEL", "Armband_HunterZ", "Armband_NAPA", "Armband_Pirates", "Armband_RSTA", "Armband_SSahrani", "Armband_TEC", "Armband_UEC", "Armband_Wolf", "Armband_Zagorky" };
		int armbIndex = Math.RandomInt( 0, 11 );
		player.GetInventory().CreateInInventory( armbArray[armbIndex] );
		
		// Random Smoke Grenade
		string smokeArray[] = { "M18SmokeGrenade_Green", "M18SmokeGrenade_Purple", "M18SmokeGrenade_Red", "M18SmokeGrenade_White", "M18SmokeGrenade_Yellow" };
		int smokeIndex = Math.RandomInt( 0, 4 );
		player.GetInventory().CreateInInventory( smokeArray[smokeIndex] );
		// Assign Smoke to slot 4
		
		// Random Frag Grenade
		string fragArray[] = { "FlashGrenade", "M67Grenade", "RGD5Grenade" };
		int fragIndex = Math.RandomInt( 0, 2 );
		player.GetInventory().CreateInInventory( fragArray[fragIndex] );
		// Assign Frag to slot 5
		
		// Health Boost
		player.GetStatWater().Add(2000);
		player.GetStatEnergy().Add(2000);
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}