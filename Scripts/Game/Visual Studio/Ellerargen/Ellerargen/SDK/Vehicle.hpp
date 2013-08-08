


enum VehicleType
{
	VT_NOSQUAD,				// kein Einsatzfahrzeug
	VT_THW_FGRR_BKF,		// Bergekran
	VT_THW_FGRB_BLF,		// Brückenleger
	VT_THW_FGRI_EKW,		// Transportfzg. Ingenieur
	VT_FIREFIGHTERS_ASF,	// Abschleppfzg.	TODO: ist jetzt THW
	VT_FIREFIGHTERS_DEKONP,	// Dekontaminationsfzg.
	VT_FIREFIGHTERS_DLK,	// Drehleiterfzg.
	VT_FIREFIGHTERS_RW,		// Rüstwagen
	VT_FIREFIGHTERS_TLF,	// Tanklöschfzg.
	VT_FIREFIGHTERS_LF,		// Löschflugzeug
	VT_FIREFIGHTERS_FLB,	// Feuerlöschboot
	VT_FIREFIGHTERS_LPF,	// Löschpanzer
	VT_FIREFIGHTERS_FMB,	// Feuerwehrmotorboot
	VT_FIREFIGHTERS_TFMB,	// Transportfzg. für FMB
	VT_POLICE_SW,			// Sonderwagen
	VT_POLICE_MTW,			// Mannschaftstransportwagen
	VT_POLICE_PHC,			// Polizeiheli
	VT_POLICE_STW,			// Streifenwagen
	VT_POLICE_WAW,			// Wasserwerfer
	VT_POLICE_GETAWAY,		// Fluchtwagen im Besitz der Polizei
	VT_AMBULANCE_ITW,		// Intensivtransportwagen
	VT_AMBULANCE_NEF,		// Notarztfzg.
	VT_AMBULANCE_RHC,		// Rettungsheli
	VT_AMBULANCE_RHF,		// Rettungshundefzg.
	VT_AMBULANCE_RTW,		// Rettungstransportwagen
	VT_TAXI,
	VT_BUS,
	VT_DRIVERCAR,
	VT_GANGSTER_GETAWAY,	// Fluchtwagen im Besitz von Gangster
	VT_TV_HELI,
	VT_THW_FGRR_RL = 100,	// bulldozer
	VT_THW_FGRR_TRL = 101,	// Transportfzg. für RL
	VT_THW_FGRT_BH = 102,
	VT_FIREFIGHTERS_GTF = 200,
	VT_POLICE_GTW = 300,
	VT_AMBULANCE_TRANSEVAC = 400,
	VT_ALL_SQUAD_VEHICLES = 500, // nur der Komplettheit halber ...


	VT_NUMTYPES = VT_TV_HELI + 7
};

enum DoorActionType
{
	DAT_NONE			= 0x00,
	// vehicle doors
	DAT_EQUIPMENT		= 0x01,
	DAT_PERSON			= 0x02,
	DAT_SPECIAL		= 0x03
};

class Vehicle : public GameObject
{
public:
		Vehicle();
		Vehicle(const Vehicle& Obj_);
		Vehicle(const Actor* Act_);
		Vehicle(const GameObject* Obj_);
		~Vehicle();
		virtual bool IsValid() const;

		void SetEnergy(float energy_);
		float GetEnergy() const;
		float GetMaxEnergy() const;
		bool IsDestroyed() const;
		bool IsSmoking() const;

		void Destroy();		//!< destroys the vehicle as in an explosion but without the force and particles.
		void SetSmoking(bool smoking_); // it starts to smoke and looses energy and will explode or stops smoking
		void SetSmokeLevelDuration(float smokeLevelDuration_);
		float GetSmokeLevelDuration();

		int GetNumPassengers() const;
		PersonList GetPassengers() const;
		bool AddPassenger(Person &Passenger_);
		bool RemovePassenger(Person &Passenger_);
		int GetFreePassengers() const;
		void SetMaxPassengers(int max_, bool discard_ = false);

		bool IsInstalled();
		bool IsUplifted();
		bool IsUplifting();
		bool IsBasketEmpty();
		bool IsCannonInUse();
		bool IsFGRBEmpty();
		bool IsBucketMoving();
		bool IsBucketUp();
		int GetInstallTargetID() const;
		bool HasBoatUploaded();
		bool HasVehicleUploaded();
		bool IsParking() const;
		bool IsDecontaminating() const;

		void SetParking(bool parking_);

		int GetNumTransported() const;
		PersonList GetTransports() const;
		bool AddTransport(Person &Transported_);
		bool RemoveTransport(Person &Transported_);
		int GetFreeTransports() const;
		void SetMaxTransports(int max_, bool discard_ = false);
		const VehicleType GetVehicleType()const;
		void SetVehicleRole(VehicleType type_);		//!< Handle with care!
		
		bool CheckUnloadPossible(GameObject *obj_, const Vector &V_) const;
		
		bool CheckUnloadPossible(GameObject *obj_, float _x, float _y, float _z);
		
		bool HasEnclosedPerson() const;
		bool SetEnclosedPerson(const char* name);
		bool RemoveEnclosedPerson();

		float GetValidLandingAngle(GameObject *target_, const Vector &Pos_) const;
		
		float IsValidLandingPosition(GameObject *target_, float x_, float y_, float z_) const;
		
		bool IsValidRopeDropPosition(GameObject *target_, const Vector &Pos_) const;

		bool IsValidEngineerDropPosition(GameObject *target_, const Vector &Pos_) const;
		
		bool IsValidRopeDropPosition(GameObject *target_, float x_, float y_, float z_) const;
		
		bool FindReachablePosition(GameObject* obj_, Vector &Pos_) const;
		
		bool FindReachablePosition(GameObject* obj_, float &tx_, float &ty_, float &tz_); 
		
		bool CanBeDropped(const Vector &Pos_) const;
		
		bool CanBeDropped(float x_, float y_, float z_);

		bool CanBeDropped(GameObject* obj_);
		
		bool CanBeTaken(GameObject* obj_);
	
		int FindLandingStage(bool tfmb_, Vector &Pos_, float distFactor) const;
		
		int FindLandingStage(bool tfmb_, float &x_,float &y_, float &z_, float distFactor);
		
		bool FindLandingStageFMB(Vector &Pos_, float distFactor) const;

		bool FindLandingStageFMB(float &x_,float &y_, float &z_, float distFactor);

		int IsInLandingStage(bool tfmb_, Vector &Pos_, float distFactor) const;

		int IsInLandingStage(bool tfmb_, float &x_,float &y_, float &z_, float distFactor);

		bool IsReady() const;	// only for fgrr
		bool IsOnGround() const;
		bool IsSearchlightOn() const;
		bool IsLightOn() const;
		bool HasTransportOnStretcher() const;
		bool HasEngineerOnBoard() const;
		GameObject GetFollowTarget() const;
		
		int GetBridgeInstallPoint(Vector &Pos_) const;

		int GetBridgeInstallPoint(float &x_, float &y_, float &z_);

		bool CheckExtinguishDistance(const GameObject &Object_);

		const char *GetStandardPath();
		void EnableAutoTarget(bool enable_);
		void SetIgnoreUserData(int data_);

		bool WasStoppedByRoadblock() const;
		bool IsDriveByShooting() const;
		bool AddRifleToGetawayCar();
		void ShootOutOfGetawayCar(GameObject *target_, float damage_);
		bool SetAutoShoot(bool enable_);
		bool GetAutoShoot() const;

		FireObject GetFireObject();

		void PlayAnimOpenDoor(DoorActionType doorType_, float time_, GameObject *Caller_=NULL);
		void PlayAnimCloseDoor(DoorActionType doorType_, float time_, GameObject *Caller_=NULL);

		bool IsConnectorFree() const;
		bool GetUsedConnectorPosition(GameObject *Caller_, Vector &Pos_);
		bool IsUsingConnector(GameObject *Caller_);
		bool CanUnloadTransEvac() const;
		bool AddSquad(Person *person_);

		bool IsFirefighter() const;
		bool IsAmbulance() const;
		bool IsThw() const;
		bool IsPolice() const;
		bool IsCivilCar() const;
		void Damage(float amount_);

		bool AddTrainWaggon(GameObject *waggon_);

		int GetHeliSound();
		void SetSirenFile(const char * sirenFile_);
};