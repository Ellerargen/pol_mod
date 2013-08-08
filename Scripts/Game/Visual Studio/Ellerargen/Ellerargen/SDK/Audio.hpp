

namespace Audio
{
	int PlaySample(const char *File_);
	
	int PlaySample3D(const char *File_, const Vector &Pos_, bool looping_ = false);
	void PlaySample3D(int ref_, const Vector &Pos_, bool looping_ = false);
	int PlaySample3DAndReplace(const char* Sample_, const char* Sample2_, const Vector &Pos_);
	void UpdatePos(int ref_, const Vector &Pos_, const bool ImmediateUpdate_ = false);
	void SetVolume(int ref_, float volume_);
	
	void StopSample(int ref_);

	bool IsPlaying(int ref_);
	void PlayVideo(const char *File_);
	void SetMusicLevel(float Level_);
	float GetMusicLevel();
	void PlaySoundtrack(const char *Track_, float Level_=0.0f);
	void StopSoundtrack();

	bool PlayTextureVideo(const char *Texture_, const char *Video_, bool Loop_ = true );
	bool StopTextureVideo(const char *Texture_);
	bool IsTextureVideoPlaying(const char *Texture_);
};