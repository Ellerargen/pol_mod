

enum PersonState
{
	PERSONSTATE_NORMAL,
	PERSONSTATE_INJURED,
	PERSONSTATE_COMATOSE,
	PERSONSTATE_DEAD
};

enum InjuryReason
{
	INJUREREASON_UNKNOWN,
	INJUREREASON_FIRE,
	INJUREREASON_SHOT,
	INJUREREASON_ENERGY,
	INJUREREASON_DROWN,
	INJUREREASON_CONTAM_ATOM,	// unbedingt gleiche Reihenfolge wie ContaminationType
	INJUREREASON_CONTAM_CHEM,
	INJUREREASON_CONTAM_BIO
};

enum PersonRole
{
	ROLE_UNKNOWN,
	ROLE_CIVILIAN,
	ROLE_SQUAD,
	ROLE_GANGSTER,
	ROLE_DROWNING,
	ROLE_ANIMAL
};

enum PersonGender
{
	GENDER_MALE,
	GENDER_FEMALE,
	GENDER_CHILD,
	GENDER_ANIMAL
};

enum PersonBehaviour
{
	BEHAVIOUR_UNKNOWN				= 0,
	BEHAVIOUR_CIVILIAN_NORMAL		= 0,
	BEHAVIOUR_CIVILIAN_GAZER		= 1,
	BEHAVIOUR_CIVILIAN_HOSTAGE		= 2,
	BEHAVIOUR_CIVILIAN_TAXIUSER		= 3,
	BEHAVIOUR_CIVILIAN_BUSUSER		= 4,
	BEHAVIOUR_CIVILIAN_DRIVER		= 5,
	BEHAVIOUR_CIVILIAN_PANIC		= 6,
	BEHAVIOUR_SQUAD_UNKNOWN			= 0,
	BEHAVIOUR_SQUAD_FIREFIGHTER		= 1,
	BEHAVIOUR_SQUAD_POLICE			= 2,
	BEHAVIOUR_SQUAD_RESCUE			= 3,
	BEHAVIOUR_SQUAD_THW				= 4,
	BEHAVIOUR_GANGSTER_ATTACKALL	= 0,
	BEHAVIOUR_GANGSTER_ATTACKSQUAD	= 1,
	BEHAVIOUR_GANGSTER_GUARDHOSTAGE	= 2,
	BEHAVIOUR_GANGSTER_GUARDPASSAGE = 3,
	BEHAVIOUR_GANGSTER_CIVILARMED	= 4,
	BEHAVIOUR_GANGSTER_CIVILUNARMED = 5,
	BEHAVIOUR_GANGSTER_THROWSTONES  = 6,
	BEHAVIOUR_GANGSTER_FISTFIGHT	= 7,
	BEHAVIOUR_GANGSTER_ATTACKSQUAD_SMART = 8,
	BEHAVIOUR_GANGSTER_THROWMOLOTOV	= 9,
	BEHAVIOUR_ANIMAL_NORMAL			= 0,
	BEHAVIOUR_ANIMAL_CAT			= 1,
	BEHAVIOUR_ANIMAL_SHEEP			= 2,
	BEHAVIOUR_ANIMAL_COW			= 3,
	BEHAVIOUR_ANIMAL_WOLF			= 4,
	BEHAVIOUR_ANIMAL_HORSE			= 5,
	BEHAVIOUR_ANIMAL_DEER			= 6,
	BEHAVIOUR_ANIMAL_CROW			= 7,
	BEHAVIOUR_ANIMAL_DOVE			= 8,
	BEHAVIOUR_ANIMAL_SEAGULL		= 9,
	BEHAVIOUR_ANIMAL_ATTACKINGWOLF	= 10,
	BEHAVIOUR_ANIMAL_PIGEON			= 11,
	BEHAVIOUR_ANIMAL_POLARBEAR		= 12
};

enum PersonType
{
	PT_NOSQUAD,
	PT_UNKNOWN,
	PT_ENGINEER,
	PT_FIREFIGHTER_NORMAL,
	PT_FIREFIGHTER_MASK,
	PT_FIREFIGHTER_ABC,
	PT_DIVER,
	PT_SHOOTER,
	PT_SHARPSHOOTER,
	PT_PSYCHOLOGIST,
	PT_SCOUT,
	PT_POLICEMEN,
	PT_DOCTOR,
	PT_PARAMEDIC,
	PT_LEADERRESCUEDOG
};

class Person : public GameObject
{
public:
		Person();
		Person(const Person& Obj_);
		Person(const Actor* Act_);
		Person(const GameObject* Obj_);
		~Person();
		virtual bool IsValid() const;
		
		void ReceiveEnergy(EnergyType Type_, float Amount_, Actor *Originator = NULL);
		void Hurt(InjuryReason Reason_, float amount);
		bool Heal(float Amount_);
		void Injure(InjuryReason Reason_, bool becomeUnconscious_ = true);
		void Kill(InjuryReason Reason_ = INJUREREASON_UNKNOWN);
		void Contaminate(ContaminationType Type_);
		void Decontaminate(ContaminationType Type_);
		void ExposeContamination(ContaminationType Type_);

		bool IsInjured() const;
		bool IsComatose() const;
		bool IsDead() const;
		bool IsWoundedSquad() const;
		bool IsContaminated() const;
		bool IsArrested() const;
		bool IsCarryingPerson() const;
		bool IsCarryingContaminatedPerson() const;
		bool IsLinkedWithPerson() const;
		bool IsLinkedWithContaminatedPerson() const;
		bool IsCarried() const;
		bool IsDrowning() const;
		bool IsGazing() const;
		bool IsFleeing() const;
		bool IsHealing() const;
		bool IsClassified() const;
		bool IsInHouseWithGroundEntrance() const;
		bool IsBeingHealed() const;

		void SetIdleAnimation();
		void SetInjuredAnimation();
		void SetClassified(bool Classified_);

		float GetLife() const;
		float GetHealth() const;
		void SetHealth(float Health_);
		void SetMaxHealth(float maxHealth_);
		float GetMaxHealth() const;
		void SetLife(float Life_);
		void SetMaxLife(float maxLife_);
		float GetMaxLife();
		void SetInjuredLifeDrain(float drain_);
		float GetInjuredLifeDrain();
		void SetMedicalLifeGain(float gain_);
		float GetMedicalLifeGain();

		bool IsContaminated(ContaminationType Type_) const;
		
		bool CanDive()const;
		PersonState GetState() const;

		InjuryReason GetInjuryReason() const;
		float GetResistance(InjuryReason type_) const;
		bool SetResistance(InjuryReason type_, float amount_);

		int GetArrestedID();
		Person GetArrested()const;
		Person GetCarried()const;
		void Arrested(bool arrested_, GameObject *capturer_ = NULL);
		
		PersonRole GetRole() const;
		void SetRole(PersonRole Role_);
		bool SetBehaviour(PersonBehaviour Behaviour_);
		PersonBehaviour GetBehaviour() const;
		bool IsDoctor() const;
		bool IsParamedicTeam() const;
		bool IsPsychologist() const;
		bool IsHostage() const;
		bool IsRescueDog() const;
		bool IsRescueDogLeader() const;
		bool IsShooter() const;
		bool IsEngineer() const;
		bool IsFireFighterABC() const;
		bool IsPolarBear() const;
		void SetFoundByDog(bool Found_);
		void SetShootAtPsychologist(bool shoot_);
		void SetShootPower(float power_);
		void SetShootFrequency(float freq_);
		void SetShootRange(float range_);
		void SetPrimaryTarget(GameObject *target_);
		void SetBloodPuddle(bool bleeding_);
		bool SetObjectToEquipmentLocation(GameObject &object_, bool personLocation_ = true);

		int GetAimTargetID() const;
		int GetEnteredHouseID() const;
		bool SetEnteredHouseID(int houseID_);
		int GetEnteredCarID() const;
		int GetEnteredCarTargetID() const;

		bool GetNeverResort() const;
		void SetNeverResort(bool neverdo_);
		void SetFleeing(bool flee_, bool clearActions_=true);
		bool IsResorting() const;
		void PushIgnoreEnergy();
		void PopIgnoreEnergy();
		void ClearReceivedEnergies();

		void PlaceObjectInRightHand(const char* modelPath_);
		void RemoveObjectInRightHand();
		void StopMovement();

		void SetDefaultMessageGroup();
		void SetMessageGroup(const char* MsgGroup_);
		const char *GetMessageGroup() const;
		bool HasMsgGroup() const;
		bool CanBeAsked() const;

		bool GetThrowPosition(Vector &Pos_) const;
		
		bool GetThrowPosition(float &x_, float &y_, float &z_);
		
		bool CheckDLKExtinguishDistance(const Actor *target_);
		bool CanEnterHouseFromDLK(const OpenHouse *target_);
		bool CanUseDLKCannon();
		bool CanStopUseDLKCannon();
		bool CanLeaveDLK();
		bool IsInDLKBasket();
		void SetEscapePath(const char* pathname_);
		void SetStandardPath(const char* pathname_);

		bool CanEnterDekonP();
		Vector GetEnteredHouseEntrancePosition(bool front_) const;
		
		void GetEnteredHouseEntrancePosition(bool front_, float &x_, float &y_, float &z_) const;

		bool IsSquadInRange(float radius) const;
		bool IsPoliceSquadInRange(float radius) const;
		bool IsSquadCarInRange(float radius) const;
		void OnAskPerson(Person *questioner_);

		void SetStoneThrowLifeDuration(float seconds_);
		void Revive();
		void SetCivilsFleeRange(float range_);
		void SetCivilsFleeing(bool flee_); // sollen Zivilisten vor dem Gangster fliehen

		PersonType GetPersonType() const;
		void EnableAutoTarget(bool enable_);
		bool IsAutoTargetEnabled() const;
		void SetAutoHealDistance(float distance_);
		PersonGender GetGender() const;
 };

