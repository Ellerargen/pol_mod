enum OrderGroupID
{
	GROUP_FIREDEPT,
	GROUP_POLICE,
	GROUP_AMBULANCE,
	GROUP_TEC
};

namespace ScriptInterface
{
	void CloseObjectives();
	
	void SetMission(const char* mission_);

	void DisableMap(bool sleep_ = true);
	void DisableRadar(bool sleep_ = true);
	void DisableNavigator(bool sleep_ = true);
	void DisableInfoBar(bool sleep_ = true);
	void DisableVehicleBrowser(bool sleep_ = true);

	void ShowMap();
	void HideMap();
	void ShowRadar();
	void OpenRadar();
	void HideRadar();
	void ShowNavigator();
	void OpenNavigator();
	void HideNavigator();
	void ShowInfoBar();
	void OpenInfoBar();
	void HideInfoBar();
	void ShowVehicleBrowser();
	void HideVehicleBrowser();
	
	void ShowBriefing();
	void HideBriefing();
	void ShowTips();
	void OpenTips();
	void HideTips();
	void ShowActionBar();
	void OpenActionBar();
	void HideActionBar();
	void ShowObjectives();
	void HideObjectives();

	void OpenObjectives();

	void EnableTutorialMode();
	void DisableTutorialMode();

	void ShowVisibleTutorialOverlay();
	void ShowInvisibleTutorialOverlay();
	void HideTutorialOverlay();
	void HideInterface();
	void ResumeFromHideInterface();

	void ShowTutorialMessage(const char *MessageID_, const char *VoiceMessageURL_, float y_ = -1.0f);
	bool IsTutorialMessageOpen();

	int ShowTutorialInstruction(const char *instructionID_, int soundRef = -1, float x_ = -1.0f, float y_ = -1.0f);
	void CloseTutorialInstruction(int soundRef=-1);	// wird auch von ShowTutorialMessage() aufgerufen
	void ShowMainMenu();

	void ShowNotice(const char *textName_);
	void HideNotice();
	bool NoticeIsHidden();
	bool DidUserHitOK();

	void BlinkNavigatorOpenCloseButton(bool Blink_);
	void BlinkNavigatorObjectivesButton(bool Blink_);
	void BlinkObjectivesOpenCloseButton(bool Blink_);
	void BlinkNavigatorFireDepartmentButton(bool Blink_);
	void EnableNavigatorFireDepartmentButton(bool enable_);
	void BlinkNavigatorAmbulanceButton(bool Blink_);
	void EnableNavigatorAmbulanceButton(bool enable_);
	void BlinkSendVehicleButton(bool Blink_);
	void BlinkSendVehicleTargetButton(bool Blink_);
	void BlinkFireDepartmentVehicle(const char *VehicleName_, bool Blink_);
	void BlinkAmbulanceVehicle(const char *VehicleName_, bool Blink_);
	void BlinkCrewButton(const char *CrewName_, bool Blink_);
	bool IsNavigatorWindowOpen();
	bool IsObjectivesWindowOpen();
	bool IsFireDepartmentWindowOpen();
	bool IsAmbulanceWindowOpen();
	bool IsMessageTickerOpen();
	void SetMessageTickerSpeed(float speed_);
	bool IsFireDepartmentVehicleSelected(const char *VehicleName_);
	bool IsAmbulanceVehicleSelected(const char *VehicleName_);
	bool IsTargetOkButtonBlinking();
	void UnlockActionButton(int index_);
	void LockObjectivesWindow();
	void BlinkActionButton(int index_);
	void BlinkActionButton(const char *name_);
	void SetEnableActionButtonsBlinking(bool enable_);	
	bool IsEquipmentMenuOpen();
	void BlinkEquipmentButton(int index_);
	void BlinkEquipmentButton(const char *name_);
	bool IsCurrentCommand(const char* name_);
	void SetCurrentCommand(const char* name_);
	void SetShowVehiclePageAfterOrder(bool enable_);
	bool IsVehicleOrdered(const char *name_);
	bool IsVehicleOrderedWithTarget(const char *name_);
	void SetVehicleBrowserAutohide(bool autohide_);
	void EnableOpenCloseBaseWindow();
	void ShowBriefing();

	void SetBaseWindowKeepOpen(bool keepOpen_);

	void UnlockObjectivesWindow();
	void UnlockExit();

	void BlinkPopupMenuCommand(const char *CommandName_, bool Blink_);

	int GetNumVehicleCrewMembersAdded();

	void CloseAllVehicleBrowsers();
	void GetMousePos(float &x_, float &y_);
	bool GetOrderTargetMode();

	void ShowMessageTickerTextForAll(const char *text_, float red_=1.0f, float green_=1.0f, float blue_=1.0f);
	void ShowMessageTickerTextForSinglePlayer(const GameObject* obj_, const char *text_, float red_=1.0f, float green_=1.0f, float blue_=1.0f);

	void SetRadarTexture(const char *filename_);
};