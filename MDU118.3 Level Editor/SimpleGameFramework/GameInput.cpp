#include "stdafx.h"
#include "GameInput.h"
#include "GameManager.h"

GameInput& GameInput::Instance()
{
	static GameInput instance;

	return instance;
}

GameInput::GameInput()
{
}

GameInput::~GameInput()
{
}

void GameInput::BeginPlay()
{

}

void GameInput::EndPlay()
{

}

void GameInput::Update(double deltaTime)
{
	// The code below polls individual keys to determine if they are currently down.
	if (GetKeyState('W') & 0x8000)
	{
	}
	if (GetKeyState('A') & 0x8000)
	{
	}
	if (GetKeyState('S') & 0x8000)
	{
	}
	if (GetKeyState('D') & 0x8000)
	{
	}
}

void GameInput::OnKeyDown(UINT keyCode, UINT repeatCount)
{
	// NOTE: This method will not detect multiple simultaneous key presses.
	// To detect simultaneous presses you must use GetKeyState and check
	// each key of interest.
	
	// Movement of the camera
	int axisH = 0;
	int axisV = 0;

	// Shows where the player currently is, allowing objects to easily be spawned on it
	int playerAxisH = 0;
	int playerAxisV = 0;

	switch (keyCode)
	{
		// Upon hitting the WASD keys the camera and player location move in different positions
	case 'W':
		axisV += 64;
		playerAxisV -= 64;
		break;
	case 'A':
		axisH += 64;
		playerAxisH -= 64;
		break;
	case 'S':
		axisV -= 64;
		playerAxisV += 64;
		break;
	case 'D':
		axisH -= 64;
		playerAxisH += 64;
		break;
	case 'Q':
		break;
		// Allows editing mode to be turned on and off
	case 'E':
		if (GameManagerInstance.editMode == true)
			GameManagerInstance.editMode = false;
		else
			GameManagerInstance.editMode = true;
		break;
	case 'F':
		break;
	case 'C':
		break;


	case VK_LEFT:	
		break;
	case VK_RIGHT:
		break;
	case VK_UP:
		break;
	case VK_DOWN:
		break;

	case VK_CONTROL:
		break;
	case VK_SPACE:
		break;
	case VK_SHIFT:
		break;

	case VK_F1:
		break;
	case VK_F2:
		break;
	case VK_F3:
		break;
	case VK_F4:
		break;
	case VK_F5:
		break;
	case VK_F6:
		break;
	case VK_F7:
		break;
	case VK_F8:
		break;
	case VK_F9:
		break;
	case VK_F10:
		break;
	case VK_F11:
		break;
	case VK_F12:
		break;
	}

	GameManagerInstance.PlayerInput(axisH, axisV);
	GameManagerInstance.PlayerLocation(playerAxisH, playerAxisV);

}

void GameInput::OnKeyUp(UINT keyCode, UINT repeatCount)
{
	// NOTE: This method will not detect multiple simultaneous key presses.
	// To detect simultaneous presses you must use GetKeyState and check
	// each key of interest.

	switch (keyCode)
	{
	case 'W':
		break;
	case 'A':
		break;
	case 'S':
		break;
	case 'D':
		break;
	case 'Q':
		break;
	case 'E':
		break;
	case 'F':
		break;
	case 'C':
		break;

		// Depending which number is pressed, the corresponding object is placed
	case '1':
		if (GameManagerInstance.editMode == true)
		{
			//The paramater of this function is the object which will be placed
			GameManagerInstance.CreateObject(egotBarrel);
		}
		break;
	case '2':
		if (GameManagerInstance.editMode == true)
		{
			GameManagerInstance.CreateObject(egotRock);
		}
		break;
	case '3':
		if (GameManagerInstance.editMode == true)
		{
			GameManagerInstance.CreateObject(egotHealingMist);
		}
		break;
	case '4':
		if (GameManagerInstance.editMode == true)
		{
			GameManagerInstance.CreateObject(egotFire);
		}
		break;
	case '5':
		if (GameManagerInstance.editMode == true)
		{
			GameManagerInstance.CreateObject(egotPickaxe);
		}
		break;
	case '6':
		if (GameManagerInstance.editMode == true)
		{
			GameManagerInstance.CreateObject(egotMedkit);
		}
		break;

	case VK_LEFT:
		break;
	case VK_RIGHT:
		break;
	case VK_UP:
		break;
	case VK_DOWN:
		break;

	case VK_CONTROL:
		break;
	case VK_SPACE:
		break;
	case VK_SHIFT:
		break;

	case VK_F1:
		break;
	case VK_F2:
		break;
	case VK_F3:
		break;
	case VK_F4:
		break;
	case VK_F5:
		break;
	case VK_F6:
		break;
	case VK_F7:
		break;
	case VK_F8:
		break;
	case VK_F9:
		break;
	case VK_F10:
		break;
	case VK_F11:
		break;
	case VK_F12:
		break;
	}
}

void GameInput::OnLButtonDown(const Vector2i& point)
{
	DebugLog("OnLButtonDown at " << point.X << "," << point.Y);
}

void GameInput::OnLButtonUp(const Vector2i& point)
{
	DebugLog("OnLButtonUp at " << point.X << "," << point.Y);
}

void GameInput::OnLButtonDblClk(const Vector2i& point)
{
	DebugLog("OnLButtonDblClk at " << point.X << "," << point.Y);
}

void GameInput::OnRButtonDown(const Vector2i& point)
{
	DebugLog("OnRButtonDown at " << point.X << "," << point.Y);
}

void GameInput::OnRButtonUp(const Vector2i& point)
{
	DebugLog("OnRButtonUp at " << point.X << "," << point.Y);
}

void GameInput::OnRButtonDblClk(const Vector2i& point)
{
	DebugLog("OnRButtonDblClk at " << point.X << "," << point.Y);
}

void GameInput::OnMouseMove(const Vector2i& point)
{
}
