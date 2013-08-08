
class SpawnPoint : public Actor
{
public:
		SpawnPoint();
		SpawnPoint(const SpawnPoint& Obj_);
		SpawnPoint(const Actor* Act_);
		~SpawnPoint();

		virtual bool IsValid() const;
		virtual Vector GetPosition() const;
		
		virtual void GetPosition(float &x_, float &y_, float &z_);
		
		GameObject SpawnSingleObject(const char* Name_);
		void SetEnabled(bool Enabled_);
};