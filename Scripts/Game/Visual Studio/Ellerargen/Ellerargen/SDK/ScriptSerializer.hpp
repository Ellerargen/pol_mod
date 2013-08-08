class ScriptSerializer
{
public:
		ScriptSerializer();
		~ScriptSerializer(void);

		bool IsValid() const;

		int Write(const char *String_);
		int Write(int Value_);
		int Write(unsigned int Value_);
		int Write(long Value_);
		int Write(float Value_);
		int Write(char Value_);
		int Write(unsigned char Value_);
		int Write(unsigned short Value_);
		int Write(bool Value_);
		int Write(Actor &Actor_);
		int Write(GameObject &Obj_);
		int Write(Person &Person_);
		int Write(Vehicle &Vehicle_);
		int Write(OpenHouse &House_);
		int Write(FireObject &Fireobject_);
		int Write(SpawnPoint &SpawnPoint_);
		int Write(Path &Path_);
		int Write(ActorList &List_);
		int Write(GameObjectList &List_);
		int Write(PersonList &List_);
		int Write(VehicleList &List_);
		int Write(FireObjectList &List_);
		int Write(OpenHouseList &List_);
		int Write(PathList &List_);
		int Write(Vector &Value_);

		int Read(char *&String_);
		int Read(int &Value_);
		int Read(unsigned int &Value_);
		int Read(long &Value_);
		int Read(float &Value_);
		int Read(char &Value_);
		int Read(unsigned char &Value_);
		int Read(unsigned short &Value_);
		int Read(bool &Value_);
		bool ReadBool();
		int Read(Actor &Actor_);
		int Read(GameObject &Obj_);
		int Read(Person &Person_);
		int Read(Vehicle &Vehicle_);
		int Read(OpenHouse &House_);
		int Read(FireObject &Fireobject_);
		int Read(SpawnPoint &SpawnPoint_);
		int Read(Path &Path_);
		int Read(ActorList &List_);
		int Read(GameObjectList &List_);
		int Read(PersonList &List_);
		int Read(VehicleList &List_);
		int Read(FireObjectList &List_);
		int Read(OpenHouseList &List_);
		int Read(PathList &List_);
		int Read(Vector &Value_);

		unsigned int GetVersion() const;
};