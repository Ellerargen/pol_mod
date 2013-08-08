


class ActorList
{
public:
		ActorList();
		ActorList(const char *Name_);
		ActorList(const ActorList &Copy_);
		ActorList(ActorType type_);
		~ActorList();
		
		inline int GetNumActors() const ;
		Actor *GetActor(int Index_) const;
};

class GameObjectList
{
public:
		GameObjectList();
		GameObjectList(const char *Name_);
		GameObjectList(const GameObjectList &Copy_);
		GameObjectList GetGameObjects();
		GameObjectList GetGameObjects(GameObjectType type_);
		GameObjectList GetGameObjects(const char *Name_);
		GameObjectList GetGameObjectsWithPrefix(const char* Prefix_);
		GameObjectList GetSelectedGameObjects();
		~GameObjectList();
		
 		inline int GetNumObjects() const;
		GameObject *GetObject(int Index_) const;
		int GetNumBurningObjects() const;
		int GetNumObjectsWithStatus(int status_);
		bool ContainsSquad() const;
		bool ContainsNonSquad() const;
		bool ContainsPoliceSquad() const;
};

class PersonList
{	
public:
		PersonList();
		PersonList(const char *Name_);
		PersonList(PersonRole role_);
		PersonList(const PersonList &Copy_);
		~PersonList();
		
		inline int GetNumPersons() const;
		Person *GetPerson(int Index_) const;
};

class VehicleList
{
public:
		VehicleList();
		VehicleList(const char *Name_);
		VehicleList(VehicleType min_, VehicleType max_);	// only vehicles with types in given range (inclusive min and max)
		VehicleList(const VehicleList &Copy_);
		~VehicleList();
		
		inline int GetNumVehicles() const;
		Vehicle *GetVehicle(int Index_) const;
};

class FireObjectList
{	
public:
		FireObjectList();
		FireObjectList(const char *Name_);
		FireObjectList(const FireObjectList &Copy_);
		~FireObjectList();

		inline int GetNumFireObjects() const;
		FireObject *GetFireObject(int Index_) const;
};

class OpenHouseList
{		
public:
	OpenHouseList();
	OpenHouseList(const char *Name_);
	OpenHouseList(const OpenHouseList &Copy_);
	~OpenHouseList();

	inline int GetNumOpenHouses() const;
	OpenHouse *GetOpenHouse(int Index_) const;
};

class PathList
{	
public:
	PathList();
	PathList(const char *Name_);
	PathList(const PathList &Copy_);
	~PathList();

	inline int GetNumPaths() const;
	Path *GetPath(int Index_) const;
};

class SpawnPointList
{		
public:
	SpawnPointList();
	SpawnPointList(const char *Name_);
	SpawnPointList(const SpawnPointList &Copy_);
	~SpawnPointList();

	inline int GetNumSpawnPoints() const;
	SpawnPoint *GetSpawnPoint(int Index_) const;
};

