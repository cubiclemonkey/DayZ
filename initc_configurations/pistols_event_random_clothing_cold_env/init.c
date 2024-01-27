void main()
    /*	This 'init.c' file created by: https://github.com/cubiclemonkey
     *	Created on DayZ Serve version: 1.23.157045
     */
{
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

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
		player.GetInventory().CreateInInventory( "Heatpack" );
		
		// Assign Roadflare to slot 3
		private EntityAI light;
		light = player.GetInventory().CreateInInventory("Roadflare");
		player.SetQuickBarEntityShortcut(light, 2);
		
		// Assign Bandages to slot 2
		private EntityAI healing;
		healing = player.GetInventory().CreateInInventory("BandageDressing");
		player.SetQuickBarEntityShortcut(healing, 1);		
		player.GetInventory().CreateInInventory( "BandageDressing" ); 
				
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

		// Random Pants
		string pantsArray[] = { "CargoPants_Beige", "CargoPants_Black", "CargoPants_Blue", "CargoPants_Green", "CargoPants_Grey" };
		int pantsIndex = Math.RandomInt( 0, 4 );
		player.GetInventory().CreateInInventory( pantsArray[pantsIndex] );
		
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
		
		// Random Smoke Grenade: Assign Smoke to slot 4
		string smokeArray[] = { "M18SmokeGrenade_Green", "M18SmokeGrenade_Purple", "M18SmokeGrenade_Red", "M18SmokeGrenade_White", "M18SmokeGrenade_Yellow" };
		int smokeIndex = Math.RandomInt( 0, 4 );
		private EntityAI smogren;
		smogren = player.GetInventory().CreateInInventory( smokeArray[smokeIndex] );
		player.SetQuickBarEntityShortcut(smogren, 3);
		
		// Random Frag Grenade: Assign Frag to slot 5
		string fragArray[] = { "FlashGrenade", "M67Grenade", "RGD5Grenade" };
		int fragIndex = Math.RandomInt( 0, 2 );
		private EntityAI fraggren;
		fraggren = player.GetInventory().CreateInInventory( fragArray[fragIndex] );
		player.SetQuickBarEntityShortcut(fraggren, 4);
		
		// Random Pistol: Assign Pistol to slot 0
		string pistolArray[] = { "MKII", "Colt1911", "FNX45", "Magnum", "Deagle" };
		int pistolIndex = Math.RandomInt( 0, 4 );
		private EntityAI primary;
		primary = player.GetHumanInventory().CreateInHands( pistolArray[pistolIndex] );
		player.SetQuickBarEntityShortcut(primary, 0);
		
		// Associated Magazines
		string magArray[] = { "Mag_MKII_10Rnd", "Mag_1911_7Rnd", "Mag_FNX45_15Rnd", "Ammo_357", "Deagle_Mag_9rnd" };
		player.GetInventory().CreateInInventory( magArray[pistolIndex] );
		player.GetInventory().CreateInInventory( magArray[pistolIndex] );
		player.GetInventory().CreateInInventory( magArray[pistolIndex] );
		
		// Health Boost
		//player.GetStatWater().Add(2000);
		//player.GetStatEnergy().Add(2000);
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}