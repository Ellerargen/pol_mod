namespace System
{
	void Print(const char *Fmt, ...);
	void Error(const char *Fmt, ...);
	void Log(const char *Fmt, ...);
	void LogFile(const char *Fmt, ...);
	void Break();
	void Sleep(int Time);
	unsigned int GetTickCount();

	// zugriff auf laufzeitvariablen
	int GetEnvInt(const char *Name);
	const char* GetEnvString(const char *Name);
	float GetEnvFloat(const char *Name);

	bool SetEnv(const char *Name, int Value);
	bool SetEnv(const char *Name, const char *Value);
	bool SetEnv(const char *Name, float Value);
	
	const char* GetGFXVendorString();
	const char* GetGFXExtensionsString();
	const char* GetGFXRendererString();
	void SetGFXFeatureFlag(const char *FlagName_, bool Value_);
};