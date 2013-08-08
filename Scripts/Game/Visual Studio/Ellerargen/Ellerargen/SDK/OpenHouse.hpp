

class OpenHouse : public GameObject
{
public:
		OpenHouse();
		OpenHouse(const OpenHouse& Obj_);
		OpenHouse(const Actor* Act_);
		OpenHouse(const GameObject* Obj_);
		~OpenHouse();

		virtual bool IsValid() const;
		
		bool IsLocked(void) const;
		bool IsOpen(void) const;
		bool IsDoorLocked(int childID_) const;
		void OpenDoor(int childID_);
		void CloseDoor(int childID_);
		bool IsCeilingOpen()const;
		void ShowCeiling(bool show_, bool openEntrance_ = true, bool immediatelyClose_ = true) const;

		void Close();

		int GetEntranceDoorID(void) const;
		
		Vector GetDoorPosition(int childID_, bool front_) const;
		Vector GetEntrancePosition(bool front_, float offset = 0.f) const;
		
		void GetDoorPosition(int childID_, bool front_, float &x_, float &y_, float &z_) const;
		void GetEntrancePosition(bool front_, float &x_, float &y_, float &z_) const;

		bool IsDoor(int childID_) const;
		bool IsEntranceDoor(int childID_) const;
		void SetDoorCollision(int childID_, bool enable_);

		bool HasGroundEntrance(void) const;

		int NumSquadPersonsInside() const;
		int NumNonSquadPersonsInside() const;

		PersonList GetSquadPersonsInside();
		PersonList GetNonSquadPersonsInside();

		bool HasJumppadTarget() const;
		Vector GetJumppadTarget() const;
		void GetJumppadTarget(float &x_, float &y_, float &z_) const;
 
		bool HasJumppad() const; // in any state
		bool IsJumppadInstalling() const;
		bool IsJumppadInstalled() const;
		bool IsJumppadDeinstalling() const;
		int GetJumppadID() const;

		bool GetInhouseFires(FireObjectList &list_);

		void SetCeilingCollision(bool enable_);
};