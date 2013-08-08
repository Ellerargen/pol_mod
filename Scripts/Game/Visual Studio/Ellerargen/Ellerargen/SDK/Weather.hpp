namespace Weather
{
	void SetRainIntensity(float intensity_);
	float GetRainIntensity();
	void SetSnowIntensity(float intensity_);
	float GetSnowIntensity();
	void SetFogIntensity(float intensity_);
	float GetFogIntensity();
	void SetFogColor(int component_, unsigned char value_);
	unsigned char GetFogColor(int component_);
	void SetStormIntensity(float intensity_);
	float GetStormIntensity();
	void SetStormSpeed(float speed_);
	float GetStormSpeed();
	void SetFlashIntensity(float intensity_);
	float GetFlashIntensity();
	void SetFlashNow();
	bool IsFlashing();
	void SetRainVisible(bool visible_);
	void SetFogVisible(bool visible_);
	void SetSnowVisible(bool visible_);
	void SetStormVisible(bool visible_);
	void SetFlashVisible(bool visible_);
	bool IsRainVisible();
	bool IsFogVisible();
	bool IsSnowVisible();
	bool IsStormVisible();
	bool IsFlashVisible();
};