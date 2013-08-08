class GameDialog
{
public:
	GameDialog();
	~GameDialog(void);

	bool Load(const char *file_);
	
	void Show(bool show_);
	void Show(const char *element_, bool show_);

	const char* StaticText_GetText(const char *element_);
	bool StaticText_SetText(const char *element_, const char *text_);

	const char* TextEdit_GetText(const char *element_);
	bool TextEdit_SetText(const char *element_, const char* text_);

	// togglebutton interface
	bool Togglebutton_GetValue(const char *toggleButton_);
	bool Togglebutton_SetValue(const char *toggleButton_, bool down_);
};