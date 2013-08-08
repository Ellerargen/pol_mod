


enum GameObjectType
{
	TYPE_UNKNOWN,
	TYPE_OBJECT,
	TYPE_PERSON,
	TYPE_HOUSE,
	TYPE_VEHICLE,
	TYPE_OPEN_HOUSE
};

enum FloorPlacement
{
	PLACEMENT_NONE,				// frei dreh- und positionierbar
	PLACEMENT_AXISALIGNED,		// Objekt wird nicht gedreht, Pivotpunkt mit Offset entscheidet die Höhe
	PLACEMENT_BOXALIGNED,			// Objekt frei drehbar, Boundingbox-Auflagepunkte mit Offset entscheiden über Höhe
	PLACEMENT_ALIGNED_CORNERS,	// Ecken der Boundingbox entscheiden über Höhe und Ausrichtung, unterste Seite der bbop zählt
	PLACEMENT_ALIGNED_SAMPLED,	// genauer als boundingcorners, zeitaufwendiger
	PLACEMENT_PHYSICS,			// physik benutzen. Nicht im Game möglich!
	PLACEMENT_CUSTOM_PLACEMENT	// placement wird von abgeleiteter Klasse berechnet (e.g. Person, Vehicle)
};

enum PhysicCollisionMode
{
	PHYSIC_COLLISION_ALL = 0,
	PHYSIC_COLLISION_NOWORLD = 1,
	PHYSIC_COLLISION_NOEXTERNALBODIES = 2,
	PHYSIC_COLLISION_NOINTERNALBODIES = 4,
	PHYSIC_COLLISION_USECATEGORIES = 8,
	PHYSIC_COLLISION_NOTRACELINE = 16,
	PHYSIC_COLLISION_NORESPONSE = 32,
	PHYSIC_COLLISION_NONE = ~PHYSIC_COLLISION_ALL & ~PHYSIC_COLLISION_USECATEGORIES
};

enum EnergyType
{
	ENERGYTYPE_UNKNOWN,
	ENERGYTYPE_FIRE,
	ENERGYTYPE_SHOT,
	ENERGYTYPE_WATER,
	ENERGYTYPE_POLICEBLOCK,
	ENERGYTYPE_CARPUSH,
	ENERGYTYPE_PHYSIC,
	ENERGYTYPE_WATER_FROM_OUSIDE,
	ENERGYTYPE_WATER_FROM_INSIDE,
	ENERGYTYPE_SHOTSOUND,
	ENERGYTYPE_FLIGHTSHOT
};

// constants for object-flags
enum ObjectFlag
{
	OF_NONE						= 0x00000000,
	OF_PERSON_ENCLOSED			= 0x00000001,	// object has enclosed person
	OF_LOCKED					= 0x00000002,	// object is locked
	OF_USABLE					= 0x00000004,	// object can be used (special action)
	OF_BULLDOZABLE				= 0x00000008,	// can be planated by the bulldozer (wheel loader)
	OF_TRANSPORTABLE			= 0x00000010,	// object can be loaded up (by vehicle)
	OF_PULLABLE					= 0x00000020,	// object can be pulled
	OF_ACCESSIBLE				= 0x00000040,	// object can be entered
	OF_COOLABLE					= 0x00000080,   // object can be cooled by fire fighters
	OF_SHOOTABLE				= 0x00000100,	// object can be shooted at
	OF_CUTABLE					= 0x00000200,	// object can be cut down with chainsaw
	OF_USABLE_WITH_MEGAPHONE	= 0x00000400,	// megaphone can be used on object
	OF_RECOVERABLE				= 0x00000800,	// object can be recovered by recovery crane
	OF_FLOTSAM					= 0x00001000,	// object can be picked up by motor boat
	OF_HIDDEN					= 0x00002000,	// object is invisible
	OF_CARRYABLE_BY_BULLDOZER	= 0x00008000,   // can be carried by the bulldozer (wheel loader)
	OF_HAS_FIRE_EXTINGUISHER	= 0x00010000,	// object carries one/many fire extinguishers
	OF_HAS_SHEARS				= 0x00020000,	// object carries one/many jaws of life
	OF_HAS_CHAINSAW				= 0x00040000,	// object carries one/many chainsaws
	OF_HAS_HOSE					= 0x00080000,	// object carries one/many fire hoses
	OF_HAS_JUMPPAD				= 0x00100000,	// object carries one/many jumppads
	OF_HAS_ROADBLOCK			= 0x00200000,	// object carries one/many roadblocks
	OF_HAS_FLASHGRENADE			= 0x00400000,	// object carries one/many flashgrenades
	OF_HAS_FIREAXE				= 0x00800000,	// object carries one/many fireaxes

	OF_BLOCKED					= 0x80000000	// no interaction with object possible
};

enum ObjectBurnStatus
{
	OBS_NORMAL			= 0x01,	// object is in normal mode / visible in normal mode
	OBS_HALFBURNED		= 0x02,	// object is halfburned / visible in halfburned mode
	OBS_FULLBURNED		= 0x04	// object is fullburned / visible in fullburned mode
};

enum TrafficLightType
{
	TLT_NONE,
	TLT_GREEN,
	TLT_YELLOW,
	TLT_RED
};

enum BlinkerLightType
{
	BLT_NONE,
	BLT_LEFT,
	BLT_RIGHT,
	BLT_BOTH
};

enum HaltType
{
	HALT_PERSONS,
	HALT_VEHICLES,
	HALT_BOTH
};

enum ContaminationType
{
	CONTAMINATION_ATOMIC,
	CONTAMINATION_CHEMICAL,
	CONTAMINATION_BIOLOGICAL
};

union ActionParameters
{
	float fValue;
	int iValue;
	bool bValue;
	char *cValue;
	class Actor *aValue;
	void *pValue;
};

struct ActionCallback
{
	class GameObject *Owner;
	ActionParameters Parameters[8];
	ActionCallback();
};

class GameObject : public Actor
{
public:
		GameObject();
		GameObject(const GameObject &Obj_);
		GameObject(const Actor *Act_);
		virtual ~GameObject();
		virtual bool IsValid() const;
	
		bool HasAnimation(const char *Anim_);
		void SetAnimation(const char *Anim_);
		bool IsCurrentAnimation(const char *Anim_);
		bool IsAnimationFinished() const;	

		bool AssignCommand(const char *Command_);
		void RemoveCommand(const char *Command_);
		void EnableCommand(const char *Command_, bool Enabled_);
		void DisableAllCommands();
		bool IsCommandEnabled(const char *Command_);
		bool HasCommand(const char *Command_);
		void SetCommandable(bool Commandable_);

		void EnableOnContactCallback(bool enable_);
		GameObjectType GetObjectType() const;
		GameObjectList GetCarriedObjects();

		virtual void UpdatePlacement(void);
		virtual void SetPlacementNone(void);
		virtual void SetPlacement(FloorPlacement placement_);
		virtual void ComputePlacement(float &x_, float &y_, float &z_);

		virtual void SetPosition(const Vector &v_);
		virtual void SetPosition(const GameObject* obj_);
		virtual void SetRotation(const GameObject* obj_);
		virtual void SetRotation(float r00, float r01, float r02,
								 float r10, float r11, float r12,
								 float r20, float r21, float r22);
		virtual void SetRotationPutInXY(float r00, float r01, float r02,
										float r10, float r11, float r12,
										float r20, float r21, float r22);
		virtual void GetRotation(float &r00, float &r01, float &r02,
								 float &r10, float &r11, float &r12,
								 float &r20, float &r21, float &r22);
		
		virtual Vector GetPosition() const;
		
		virtual Vector GetLookatDir();
		virtual void GetLookatDir(float &x_, float &y_, float &z_);
		virtual void SetLookatDir(float x_, float y_, float z_);
		virtual void SetLookatDir(Vector &dir_);

		virtual void GetModelPosition(float &x_, float &y_, float &z_);
		virtual float GetPositionOffset();
		const char *GetPrototypeName();
		const char *GetPrototypeFileName();
		const char *GetModelFileName();

		bool IsInsideMap();
		void GetOrientedBBoxPoint( unsigned int corner_, float &x_, float &y_, float &z_);
		void DrawOrientedBBox(unsigned char red_=255, unsigned char green_=255, unsigned char blue_=255);
		
		bool IsJumppad() const;
		bool IsRoadblock() const;
		bool IsHydrant() const;
		bool IsHydrantInUse() const;
		bool IsInsideWater() const;
		bool IsIdle() const;
 		bool CanStopAction() const;
		bool IsWaiting() const;
		bool HasFireChilds() const;
		bool IsSelected() const;
		bool IsShooted() const;
		bool IsEquipped() const;
		bool IsCarryingAnything() const;
		bool IsCarryingObjects() const;
		bool IsAiming() const;
		bool IsPulling() const;
		bool IsCarried() const;
		bool IsMoving() const;
		bool IsCommandInRange(float maxDist_) const;
		
		int GetFirehoseID() const;
		GameObject GetHydrant();
		void SetInsideWater(bool inWater_);

		void GetFirehoseWaypoints(int which_, Vector &v1_, Vector &v2_);
		
		int GetNumFirehoseWaypoints(float x_, float y_);
		void Select();
		void Deselect();
		void SetSelectable(bool selectable_);
		
		void SetEquipment(EquipmentType Equip_);
		EquipmentType GetEquipment(void) const;
		void RemoveEquipment();

		int GetFlags(void) const;
		void SetFlags(int flags_);
		void ClearFlags(void);

		const ObjectBurnStatus GetBurningStatus()const;
		void Burn();
		void StopBurning();
		bool IsBurning();
		bool IsCompletelyBurning();
		bool IsBurningInside();
		bool IsBurningOutside();
		void SetFireObjectBurning(const char* name_);
		bool IsFireObjectBurning(const char* name_);
		FireObject GetFireChild(const char* name_);
		FireObject GetFireChild(int index_);
		int GetNumFireChilds();

		bool IsFlagSet(int flag_) const;
		void SetFlag(int flag_);
		void ClearFlag(int flag_);
		void ToggleFlag(int flag_);

		void StartParticleEffect();
		void StopParticleEffect();
		void SetParticleEffectStrength(const float strength_);
		void SetParticleEffectDirection(const float x,const float y,const float z);
		void SetParticleEffectSpeed(const float constant);
		void SetParticleEffectSize(const float size);
		bool HasParticleEffectEnded();

		void StopAnimation();
		void Explode();
		void Explode(float force);	// Diese Funktion ist veraltet. Bitte nicht mehr verwenden.
		void ApplyForce(int bodyNum_, const Vector &Pos_, const Vector &Force_);
		void AddExplosionForceField(const char* material_);

		void SetObjectPath(const char* pathname, float speed = 0.0f, bool forward = true);
		void SetObjectPath(Path *path_, float speed = 0.0f, bool forward = true);
		void RemoveObjectPath();
		bool HasObjectPath(const char* pathname);	// if no name is given check if ANY objectpath is set
		bool IsForwardOnPath() const;
		Path GetObjectPath() const;

		bool IsPathPaused() const;
		void SetPausePath(bool enable_);
		void SetCurrentPathSpeed(float speed, float acceleration = 0.0f);
		float GetCurrentPathSpeed() const;

		bool HasArrived(const char* pathname,const float accuracy = 100.f);
		bool GetDestination(float &x, float &y, float &z) const;

		void DisablePhysics();
		void EnablePhysics();		
		bool EnablePhysicsSimulation(bool keepSpeed_ = false, bool freeze_ = false, bool clearActions_=true);
		void SetPhysicsVelocity(float speedX_, float speedY_, float speedZ_);
		bool GetPhysicsLinearVelocity(int bodyNum, Vector &linVel_);
		bool GetPhysicsAngularVelocity(int bodyNum, Vector &angVel_);
		float GetPhysicsMass();
		void SetPhysicsFriction(float friction_);
		bool DisablePhysicsSimulation(bool forceUseOfPhysicsGeometry_ = false);
		bool IsPhysicsFreezed() const;		// tests if physic object has ceased any movement
		bool IsPhysicsSimulationEnabled();
		void SetFloatage(float densityFactor_);
		bool IsPhysicsObjectFloating();
		bool ReplacePhysicsObject(const GameObject* obj_);
		bool SetCollisionResponseByForces(float force_ = 5.0f);
		void DisableCollisionResponse();
		void SetPhysicsStatic(bool enable_);
		bool ActivateOBBCollision();
		bool GetOBBCollision();
		bool StartPhysicsEvent(int steps_);
		void SetCollisionMode(PhysicCollisionMode mode_);
		bool FreezePhysics() const;
		bool UnfreezePhysics() const;
		bool HasHadContact() const;
		
		bool GetPhysicsPosition(Vector &Pos_) const;
		bool SetPhysicsPosition(const Vector &Pos_);
		bool HasPhysicsCollision();

		Vector RelativeToWorldPosition(const Vector &Rel_) const;
		void SetAnimationTime(float time_, bool halt_ = true);

		GameObjectList GetObjectsInRange(float radius_, int filter_ = ACTOR_OBJECT | ACTOR_PERSON | ACTOR_VEHICLE | ACTOR_HOUSE | ACTOR_OPEN_HOUSE);
		// sucht das nächstgelegene Objekt in Reichweite
		GameObject GetClosestObjectInRange(float radius_, int filter_ = ACTOR_OBJECT | ACTOR_PERSON | ACTOR_VEHICLE | ACTOR_HOUSE | ACTOR_OPEN_HOUSE);
		// sucht das nächstgelegene Objekt in Reichweite, welches mindestens minDist_ entfernt ist
		GameObject GetClosestObjectInRange(float radius_, float minDist_, int filter_ = ACTOR_OBJECT | ACTOR_PERSON | ACTOR_VEHICLE | ACTOR_HOUSE | ACTOR_OPEN_HOUSE);

		bool IsBridge(void) const;

		bool IsCollidingWithTrigger(const char *triggerName);
		bool IsCollidingWithTrigger(GameObject *trigger_);
		bool IsCollidingWithVirtualObject(const char *voName_);
		bool ActivateTrigger();
		bool DeactivateTrigger();

		float Distance(GameObject* obj2);
		float Distance(GameObject& obj2);
		float DistanceXY(GameObject* obj2);
		float DistanceXY(GameObject& obj2);
		float Distance(float x_, float y_, float z_);

		void Show();
		void Hide();
		bool IsHidden() const;

		void SetTraceAccuracy_NoCollision();
		void SetTraceAccuracy_AABox();
		void SetTraceAccuracy_OBox();
		void SetTraceAccuracy_Polygons();

		void SetChildTraceAccuracy_NoCollision(const char* name_);
		void SetChildTraceAccuracy_AABox(const char* name_);
		void SetChildTraceAccuracy_OBox(const char* name_);
		void SetChildTraceAccuracy_Polygons(const char* name_);
		
		bool HasChild(const char* name_) const;
		Vector GetChildPosition(int childID_) const;
		void SetChildEnabled(const char* name_, bool enabled_);
		bool IsChildEnabled(const char* name_);
		bool IsChildEnabled(int ChildID_);
		const char *GetChildName(int ChildID_);

		bool IsCurrentAction(const char *Action) const;
		bool HasAnyAction() const;
		int GetNumActions() const;
		bool CheckCollision(const Vector &Pos_) const;
		bool OccludesSightLine(GameObject &Obj_);
		
		void EnableBlueLights(bool enable_);
		bool IsBlueLightEnabled() const;
		void EnableHeadLights(bool enable_);
		void EnableBreakLights(bool enable_); // aus Kombatibilitätsgründen noch da
		void EnableBrakeLights(bool enable_);
		bool IsBrakeLightEnabled() const;
		void EnableSpecialLights(bool enable_);
		bool IsSpecialLightEnabled() const;
		void EnableTrafficLight(TrafficLightType type_);
		void EnableBlinker(BlinkerLightType type_);
		BlinkerLightType GetBlinkerStatus() const;
		void SetLightEnabled(int id_, bool enable_);

		void SetHighlighted(bool enable_);

		float GetSpeedFactor(const Vector &Pos_) const;
		float GetTerrainSpeed(GameObject * object_);
		bool IsBarricade();
		void RemoveRouterObject();
	
		bool IsTriggering(const char *Trigger_);
		bool IsPontonBridge();
		bool IsBridgeInstalled();
		bool IsBridgeInUse();
		int GetBridgeInstallPoint();

		int GetNumActiveFireChilds() const;

		bool IsWaitingPointCreationEnabled() const;
		void EnableWaitingPointCreation(bool enable_);
		bool HasWaitingPoint() const;
		bool AddWaitingPoint();
		bool AddWaitingPoint(float gazerRadius_, float catchmentRadius_);
		bool RemoveWaitingPoint();

		int GetParentHouseID() const;
		
		bool IsWaterCannonActive();	// nur für wasserwerfer

		void CheckContamination(int contamType_, float radius_);

		void DumpObjectPositionAndRotation(const char* varName);

		int GetContainerObjectID() const;
		void SetLinkedPersonID(int id_);

		void SetSpeed(float Spd_);
		float GetSpeed();

		void SetPlayerMP(int playerID_);
		int GetPlayerMP() const;

		bool HasBlockedPerson();

		bool IsInSight();
		
		// persons within this area will be contaminated
		void SetContaminationArea( ContaminationType contaminationType_, float range_ );
		void RemoveContaminationArea();
		
		void ClearActions();
		void PushActionNOP(ActionInsertMode Mode_);
		void PushActionMove(ActionInsertMode Mode_, const Vector &Pos_, bool direct_ = false);
		void PushActionMove(ActionInsertMode Mode_, Actor* Target_, TargetPoint Pnt_, bool direct_ = false);
		void PushActionMove(ActionInsertMode Mode_, int TargetID_, TargetPoint Pnt_, bool direct_ = false);
		void PushActionMoveFollow(ActionInsertMode Mode_, Actor* Target_, float NearDist_, float HaltDist_);
		void PushActionSwitchAnim(ActionInsertMode Mode_, const char *Anim_);
		void PushActionShowHide(ActionInsertMode Mode_, bool Hide_);
		void PushActionEnterCar(ActionInsertMode Mode_, Actor* Target_);
		void PushActionLeaveCar(ActionInsertMode Mode_, Actor* Target_);
		void PushActionPickUp(ActionInsertMode Mode_, Actor* Target_);
		void PushActionPush(ActionInsertMode Mode_, Actor* Target_, float Power_=200.f);
		void PushActionDrop(ActionInsertMode Mode_);
		void PushActionGetEquipment(ActionInsertMode Mode_, Actor* Target_, EquipmentType equipment_);
		void PushActionRemoveEquipment(ActionInsertMode Mode_);
		void PushActionExtinguish(ActionInsertMode Mode_, Actor* Target_, float Energy_);
		void PushActionTag(ActionInsertMode Mode_, const char *Tag_);
		void PushActionLoadUp(ActionInsertMode Mode_, Actor* Target_);
		void PushActionUnload(ActionInsertMode Mode_, int unloadPointID_ = -1);
		void PushActionMoveBucket(ActionInsertMode Mode_, Actor* Target_, bool up_);
		void PushActionPlanate(ActionInsertMode Mode_, Actor* Target_);
		void PushActionReturnToBase(ActionInsertMode Mode_);
		void PushActionHeal(ActionInsertMode Mode_, Actor* Target_, bool JustStabilize_=false);
		void PushActionArrest(ActionInsertMode Mode_, Actor* Target_, bool Fight_=false);
		void PushActionRelease(ActionInsertMode Mode_);
		void PushActionAskPerson(ActionInsertMode Mode_, Actor* Target_);
		void PushActionUseEquipment(ActionInsertMode mode_, Actor* Target_, int childID_, float time_);
		void PushActionUseEquipment(ActionInsertMode mode_, const Vector &Target_, float time_);
	    void PushActionWait(ActionInsertMode mode_, float time_);
		void PushActionTurnTo(ActionInsertMode mode_, Actor *Target_, float Duration_=0.f);
		void PushActionTurnTo(ActionInsertMode mode_, const Vector &Pos_, float Duration_=0.f);
		void PushActionLift(ActionInsertMode Mode_, Actor* Target_);
		void PushActionUnloadPerson(ActionInsertMode Mode_);
		void PushActionAim(ActionInsertMode Mode_, Actor* Target_, float range_);
		void PushActionPrepareAim(ActionInsertMode Mode_);
		void PushActionAimEnd(ActionInsertMode Mode_);
		void PushActionThrow(ActionInsertMode Mode_, const Vector &Pos_);
		void PushActionEquipWeapon(ActionInsertMode Mode_, bool equip_);
		void PushActionShoot(ActionInsertMode Mode_, Actor *Target_);
		void PushActionRedirect(ActionInsertMode Mode_);
		void PushActionRedirectCar(ActionInsertMode Mode_, bool doNotChangePathDirection_=false, bool skipCheckOnFirst_ = false);
		void PushActionNegotiate(ActionInsertMode Mode_, Actor *Target_);
		void PushActionUsePath(ActionInsertMode Mode_, const char *Path_, float Speed_);
		void PushActionUsePath(ActionInsertMode Mode_, Path *Path_, bool Forward_, float Speed_, bool forceUseRF_ = false);
		void PushActionFlyTo(ActionInsertMode Mode_, const Vector &Pos_, bool landing_, float landingDirection_);
		void PushActionFlyTo(ActionInsertMode Mode_, Path *path_, int startNode_ = -1, int endNode_ = -1);
   		void PushActionRepair(ActionInsertMode Mode_, Actor *Target_);
		void PushActionAirExtinguish(ActionInsertMode Mode_, const Vector &Pos_);
		void PushActionInstall(ActionInsertMode Mode_, Actor *Target_);
		void PushActionInstall(ActionInsertMode Mode_, int ID_);
		void PushActionDeinstall(ActionInsertMode Mode_);
		void PushActionDeleteOwner(ActionInsertMode Mode_);
		void PushActionEmitParticles(ActionInsertMode Mode_, const char * name_, float time_);
		void PushActionMoveWithHose(ActionInsertMode Mode_, const Vector &Pos_);
		void PushActionMoveWithDog(ActionInsertMode Mode_, const Vector &Pos_);
		void PushActionPull(ActionInsertMode Mode_,Actor *Target_);
		void PushActionStopPulling(ActionInsertMode Mode_);
		void PushActionPutInCar(ActionInsertMode Mode_, Actor *Target_);
		void PushActionOpenDoor(ActionInsertMode Mode_, Actor *Target_, int childID_);
		void PushActionEnterBasket(ActionInsertMode Mode_, Actor *Target_);
		void PushActionBasketDown(ActionInsertMode Mode_, const Vector &Pos_);
		void PushActionEnterHouse(ActionInsertMode Mode_, Actor *Target_);
		void PushActionEnterHouse(ActionInsertMode Mode_, int TargetID_);
		void PushActionLeaveHouse(ActionInsertMode Mode_, Actor *Target_);
		void PushActionBasketUp(ActionInsertMode Mode_);
		void PushActionUseCannon(ActionInsertMode Mode_);
		void PushActionStopUseCannon(ActionInsertMode Mode_);
		void PushActionCannonExtinguish(ActionInsertMode Mode_, Actor *Target_, float Energy_, bool Cool_ = false);
		void PushActionTurnBase(ActionInsertMode Mode_, Actor *Target_);
		void PushActionEvacuate(ActionInsertMode Mode_, Actor *Target_);
		void PushActionHalt(ActionInsertMode Mode_, float radius, HaltType type);
		void PushActionEnableEffect(ActionInsertMode Mode_, bool enable_);
		void PushActionDive(ActionInsertMode Mode_,float duration);
		void PushActionInterruptAnim(ActionInsertMode Mode_, const char *Anim_);
		void PushActionInterruptAnim(ActionInsertMode Mode_, const char *Anim_, float Time_, bool ReturnToIdle_ = false);
		void PushActionLiftWithRope(ActionInsertMode Mode_, Actor *Target_);
		void PushActionLetDownOnRope(ActionInsertMode Mode_, const Vector &Pos_);
		void PushActionCool(ActionInsertMode Mode_, Actor *Target_);
		void PushActionLiftWithCrane(ActionInsertMode Mode_, Actor *Target_);
		void PushActionDropWithCrane(ActionInsertMode Mode_, const Vector &Pos_);
		void PushActionUse(ActionInsertMode Mode_, Actor *Target_);
		void PushActionRotateTarget(ActionInsertMode Mode_, Actor *Target_, float pitch_, float yaw_, float roll_, float timeInSec_ );
		void PushActionHeliFollow(ActionInsertMode Mode_, Actor *Target_);
		void PushActionDogSearch(ActionInsertMode Mode_);
		void PushActionThrowStone(ActionInsertMode Mode_, const Vector &Pos_, float lifeDuration_);
		void PushActionCallDog(ActionInsertMode Mode_, Actor* Target_);
		void PushActionDogDig(ActionInsertMode Mode_, float time_);
		void PushActionFistFight(ActionInsertMode Mode_, Actor* Target_, bool StreetFight_ = false);
		void PushActionJumpOnPad(ActionInsertMode Mode_, Actor* Target_);
		void PushActionEmptyBoat(ActionInsertMode Mode_);
		void PushActionCrossBridge(ActionInsertMode Mode_, int BridgeID_);
		void PushActionExamineVehicle(ActionInsertMode Mode_, Actor* Target_);
		void PushActionJump(ActionInsertMode Mode_, const Vector &Pos_, bool useFindFreePos_=false);
		void PushActionWaterOn(ActionInsertMode Mode_);
		void PushActionWaterOff(ActionInsertMode Mode_);
		void PushActionWolfpackWait(ActionInsertMode Mode_, Actor* VObject_, int TargetNumber_);
		void PushActionDisappear(ActionInsertMode Mode_, float DisappearTime_, float WaitTime_ = 0.f, bool fadeOut_ = false);
		void PushActionPutInBase(ActionInsertMode Mode_);
		void PushActionLightOn(ActionInsertMode Mode_, bool on_);
		void PushActionExecuteCommand(ActionInsertMode Mode_, const char* Command_, Actor* Target_=NULL, int ChildID_=0, bool CheckTarget_=true);
		void PushActionExecuteCommand(ActionInsertMode Mode_, const char* Command_, Vector &Pos_);
		void PushActionScoutHouse(ActionInsertMode Mode_, Actor* Target_);
		void PushActionScoutArea(ActionInsertMode Mode_);
		void PushActionEvacuatePerson(ActionInsertMode Mode_, Actor *Target_);
		void PushActionLetDownEngineer(ActionInsertMode Mode_);
		void PushActionUnfastenPerson(ActionInsertMode Mode_);
		void PushActionUnloadTransEvac(ActionInsertMode Mode_);
		void PushActionSendPeople(ActionInsertMode Mode_, float Radius_, const Vector& TargetPos_);
		void PushActionEquipmentToObject(ActionInsertMode Mode_, GameObject *equipment_);
		void PushActionContaminationByObject(ActionInsertMode Mode_, GameObject *parent_, ContaminationType contaminationType_, float range_);
		void PushActionLiftDown(ActionInsertMode Mode_, float targetHeight_, float speed_, bool downward_ = true);
		void PushActionAppear(ActionInsertMode Mode_, float speed_);
		void PushActionThrowMolotov(ActionInsertMode Mode_, const Vector& TargetPos_, float Power_, float Radius_ = 250.f);
		void PushActionLinkPerson(ActionInsertMode Mode_, Person *Person_);
		void PushActionCheckFreeConnector(ActionInsertMode Mode_, Actor *Target_);
		void PushActionMoveToPoint(ActionInsertMode Mode_, GameObject *Target_, float Speed_, float Time_ = 0.0f);

		void ChangePrototype(const char *Proto_);
		void ChangeModel(const char *Model_);
};

