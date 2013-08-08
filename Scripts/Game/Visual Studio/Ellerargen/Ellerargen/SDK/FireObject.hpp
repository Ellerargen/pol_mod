class FireObject: public Actor
{
public:
	virtual bool IsValid() const;

	void Burn();
	void SetTemperature(float degree_);		//!< Handle with care!
	float GetMaxMaterialTemperature() const;
	void SetMaterial(const char *material_);

	void Large();
	void Small();
	void StopLarge();
	void StopSmall();
	void Stop();

	bool IsBurning();
	bool IsBurned();

	void SetActive(bool active_);
	void Restart();

	virtual Vector GetPosition() const;
	virtual void SetPosition(const Vector &v_);
};