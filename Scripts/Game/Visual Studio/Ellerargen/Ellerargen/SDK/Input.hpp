namespace Input
{
	int GetMouseX();
	int GetMouseY();
	bool LeftButtonPressed();
	bool RightButtonPressed();
	bool MiddleButtonPressed();
	bool LCtrlPressed();
	bool LShiftPressed();

	Vector GetFloorPos();
	
	void GetFloorPos(float &x_, float &y_, float &z_);

	bool PriorityKeyPressed();
};