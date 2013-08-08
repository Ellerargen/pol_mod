class Vector
{
public:
		float x, y, z;
		
		Vector();
		Vector(float x_, float y_, float z_);
		Vector(const Vector &V_);

		void Set(float x_, float y_, float z_);
		float GetLen();
		Vector GetNormal();
};

extern const Vector NULLVECTOR;