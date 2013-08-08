

namespace Camera
{
	
	void Move(const Vector &Start_, const Vector &End_=NULLVECTOR, float Duration_ = 0.0f);
	void Move(const char* pathname,const float duration = 0);

	void Rotate(float stepx = 0, float stepy = 0, float stepz = 0, float speed = 0);
	void Set(const Vector &Pos_);
	Vector Get();
		
	void SetRotation(float x, float y, float z);
	void GetRotation(float &roll_, float &pitch_, float &yaw_);

	void SetCameraRotationTo(const float x,const  float y,const  float z);

	void ZoomIn(const float ZoomIn);
	void ZoomOut(const float ZoomOut);
	void ZoomInTo(const float ZoomIn);
	void ZoomOutTo(const float ZoomOut);

	void Restrict(const float radius = 0);

	void FollowTarget(const GameObject *object_, const Vector &Pos_, bool useCurrentCamPos_ = false);	
	void LookAtTarget(const GameObject *object_, bool smoothTransition_ = false,
					  float zoomSpeed_ = 0.0f, float zoomDuration_ = 1.0f);	
	void LookAtPoint(const Vector &Point_, bool smoothTransition_, float zoomSpeed_, float zoomDuration_);
	void LookAt(const Vector &From_, const Vector &To_);
	void GetDirection(float &x, float &y, float &z);
	void SynchronizeWithPhysics();
	void SynchronizeWithGame();

	const bool IsMoving  ();
	const bool IsRotating();
	void StartTransition(const char *Target_, float Duration_, bool stopSmooth_ = true, bool startSmooth_ = false);	
	void StartTransition(const Vector &pos_, float yaw_, float pitch_, float roll_, float duration_, bool stopSmooth_ = true, bool startSmooth_ = false);
	void StartTransition(const Vector &Pos_, float height_, float yaw_, float pitch_, float roll_, float duration_, bool stopSmooth_ = true, bool startSmooth_ = false);
	void GetTransition(const char *name_, Vector &pos_, float &yaw_, float &pitch_, float &roll_);
	bool IsCameraTransitioning();

	void SetCameraToLocation(const char *Target_);

	void LockCameraMovement();
	void UnlockCameraMovement();
	void LockCameraRotation();
	void UnlockCameraRotation();
	void LockCameraZoom();
	void UnlockCameraZoom();

	void EnableEntryPoint();
	void DisableCameraXYMovement();
	void EnableCameraXYMovement();
	void DisableCameraZMovement();
	void EnableCameraZMovement();
	void DisableCameraRotation();
	void EnableCameraRotation();

	void SetMinCamZ(float value_);
	float GetMinCamZ();
	void SetMaxCamZ(float value_);
	float GetMaxCamZ();

	void SetMinCamPitch(float value_);
	float GetMinCamPitch();
	void SetMaxCamPitch(float value_);
	float GetMaxCamPitch();

	void SetShakingEnabled(bool enable_);
};