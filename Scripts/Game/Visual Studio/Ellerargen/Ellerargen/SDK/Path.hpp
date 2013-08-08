enum PathType
{
	PATH_FORWARD,
	PATH_BACKWARD,
	PATH_LOOP,
	PATH_PINGPONG
};

class Path : public Actor
{
public:
		Path();
		Path(const Path& Obj_);
		Path(const Actor* Act_);
		~Path();

		virtual bool IsValid() const;
		void SetOnFinishDeleteObject( bool delete_);
		bool GetOnFinishDeleteObject() const;

		void SetPathType(PathType type_);
		PathType GetPathType() const;
		
		Vector GetStartPosition() const;
		float GetDistance(const Vector &Pos_) const;
		float GetPathSpeed();

		int GetNumPoints();
		Vector GetPoint(int index_);
		int GetPointID(int index_);
		Vector GetNearestPoint(const Vector &v_);
		int GetNearestPointIndex(const Vector &v_);
};