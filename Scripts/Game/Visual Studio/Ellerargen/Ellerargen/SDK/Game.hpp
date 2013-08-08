namespace Game
{
	ActorList GetActors();
	ActorList GetActors(const char *Name_);
	ActorList GetActors(ActorType type_);
	Actor GetActor(int ID_);
	int GetNumActors(ActorType type_);
	int GetNumInjuredPersonNotOnTransport();
	
	GameObjectList GetGameObjects();
	GameObjectList GetGameObjects(GameObjectType type_);
	GameObjectList GetGameObjects(const char *Name_);
	GameObjectList GetGameObjectsWithPrefix(const char* Prefix_);
	GameObjectList GetSelectedGameObjects();
	int GetNumSelectedGameObjects();
	bool IsParamedicWithInjuredInSelection(GameObject *Caller_);

	PersonList GetParamedics();
	PersonList GetDoctors();
	PersonList GetFirefighters();
	
	GameObject CreateObject(const char* Prototype_, const char *Name_);
	Person CreatePerson(const char *Prototype_, const char *Name_);
	Vehicle CreateVehicle(const char* Prototype_, const char *Name_);

	void RemoveGameObject(GameObject *obj_);
	
	bool ExecuteCommand(const char *Command_, GameObject *Caller_);
	bool ExecuteCommand(const char *Command_, GameObject *Caller_, Actor *Target_);
	
	float MetersToUnits(float Meters_);
	float UnitsToMeters(float Units_);
	void PrintObjectText(Actor &Obj_, const char *Text_);
	
	bool LoadMap(const char* MapName_);	
	void ScheduleMissionStart(int Mission_, bool isNewMission_ = false);

	void PlayEmitter(const char *File_, const Vector &Pos_);
	float GetGameSpeed();
	void SetGameSpeed(float Speed_);
	float GetLastTickDuration();

	float GetRealTime();
	float GetTime();

	void SetDefaultMessageGroup(const char* Default_);
	void ShowHelpText(const char *Text_, float Duration_ = -1.0f);
	void ShowHelpTextWindow(const char *Text_, float Duration = -1.0f);
	void CloseHelpTextWindow();

	bool CollectObstaclesOnPath(const char* path, GameObjectList &list);
	bool CollectObstaclesOnTrigger(const char* trigger, GameObjectList &list, unsigned int typefilter_ = ACTOR_VEHICLE|ACTOR_PERSON|ACTOR_OBJECT);
	bool CollectObstaclesOnVirtualObject(const char* vobj, GameObjectList &list, unsigned int typefilter_ = ACTOR_VEHICLE|ACTOR_PERSON|ACTOR_OBJECT);
	bool IsSquadInTrigger(const char* trigger, unsigned int typefilter_ = ACTOR_PERSON|ACTOR_VEHICLE);
	bool IsCivilianInTrigger(const char* trigger, unsigned int typefilter_ = ACTOR_PERSON, bool isInjured_=false);
	bool IsSquadInVirtualObject(const char* vobj);
	bool IsCivilianInVirtualObject(const char* vobj);
	bool IsBurningObjectInVirtualObject(const char* vobj);
	void HideObjects(const GameObjectList &list);
	void ShowObjects(const GameObjectList &list);
	int GetNrObjectsWithFlagSet(int flag_);

	bool ExistsObjectWithFlagSet(int flag_);
	bool ExistsNormalObjectWithFlagSet(int flag_); //checks only objects with status != FULLBURNED, which arent hidden
	bool ExistsFreeLandingStage(bool tfmb_);	//
	bool ExistsFreeBridgeInstallPoint();		//
	bool ExistsFreeTFMB();
	bool ExistsFreeFMB();
	bool ExistsFreeDLKInstallPosition();		//
	bool ExistsEmptyFGRR_TRL();
	bool ExistsEmptyFGRR_RL();
	bool ExistsCoolableobject();
	bool ExistsExtinguishableObject();
	bool ExistsDrowningPerson();				//
	bool ExistsInjuredPerson();					//
	bool ExistsNonInjuredPerson();				//
	bool ExistsWoundedSquad();
	bool ExistsAccessibleHouse();
	bool ExistsFreeRescueDog();
	bool ExistsDiveArea();						//
	bool ExistsCarWithEnclosedPerson();			
	bool ExistsCutableObject();
	bool ExistsLockedHouse();
	bool ExistsFreeHoseConnection();
	bool ExistsAskablePerson();
	bool ExistsFreeDLK();
	bool ExistsRepairableCar();
	bool ExistsHouseForJumpad();
	bool ExistsInstalledJumppad();
	bool ExistsInstalledRoadblock();
	bool ExistsFreeVehicle(VehicleType type_, int minFreePassengers, int minFreeTransports);
	bool ExistsFreeVehicle(VehicleType type_, VehicleType type2_, int minFreePassengers, int minFreeTransports);
	bool ExistsFreeVehicle(VehicleType type_, VehicleType type2_, VehicleType type3_, int minFreePassengers, int minFreeTransports);
	bool ExistsFreeVehicle(VehicleType type_, VehicleType type2_, VehicleType type3_, VehicleType type4_, int minFreePassengers, int minFreeTransports);
	bool ExistsFreeSquadVehicle(VehicleType type_, int minFreePassengers, int minFreeTransports);
	bool ExistsFreeSquadVehicle(VehicleType type_, VehicleType type2_, int minFreePassengers, int minFreeTransports);
	bool ExistsFreeSquadVehicle(VehicleType type_, VehicleType type2_, VehicleType type3_, int minFreePassengers, int minFreeTransports);
	bool ExistsFreeSquadVehicle(VehicleType type_, VehicleType type2_, VehicleType type3_, VehicleType type4_, int minFreePassengers, int minFreeTransports);

	bool ActivateTrigger(const char *name);
	bool DeactivateTrigger(const char *name);
	bool ActivateWaitingPoint(const char *name_);
	bool DeactivateWaitingPoint(const char *name_);
	bool IsInTrigger(const char *name, const Vector &Pos_);
	void CreateAreaLightsAroundTrigger(const char *name_, const char *nameForLights_, float gap_);

	bool ActivateLiquid(const char *name);
	bool DeactivateLiquid(const char *name);

	bool IsWater(const Vector &Pos_, bool ignoreHeight_ = true);
	bool IsSubmergible(const Vector &Pos_);

	int GetPhysicsStep();
	int GetTick();

	bool FindFreePosition(GameObject *obj_, Vector &Pos_, float radius_ = 100.0f);
	bool FindAvailablePosition(GameObject *obj_, Vector &Pos_, float radius_ = 50.0f, bool allowHouses_ = true);
	bool GetPotentialCollisions(Actor *obj_, ActorList &list_, float radius_, unsigned int typefilter_);

	void ExtinguishAllFires();
	
	void ActivateSceneLens(bool active_);

	void StopAmbientSound(const char* name_);
	void SetAmbientSoundVolumeByName(const char *name_, float volume_);
	void SetAmbientSoundVolumeBySound(const char *sound_, float volume_);

	void SetObjectsSelectable(bool enable_);
	void SetMapBoundsBlockCamera(bool enable_);
	void ForceShowContextMenu(bool enable_);
	void EnableMultiSelection(bool enable_);

	void GetTime(int &hour_, int &minute_, int &second_);
	void SetTime(int hour_, int minute_, int second_);
	int GetTimeSpeed();
	void SetTimeSpeed(int speed_);
	float GetGroundHeight(float posx_, float posy_);
	float GetFloorHeight(float posx_, float posy_);

	void DrawPermanentLine(Vector &start, Vector &end, int R, int G, int B);

 	Vector GetCommandPos();
	GameMode GetGameMode();

	bool HasNamePrefix(const char* Name_, const char *Prefix_);
 	void EnableUpdateMissionOnPause(bool enable_);

	bool IsFreeplay();
	bool IsMultiplayer();
	bool IsCampaign();
	bool IsMission();

	void AddToGroup(GameObject *object_, int group_);
	bool RemoveFromGroup(GameObject *object_, int group_);
	bool IsInGroup(GameObject *object_, int group_);
};