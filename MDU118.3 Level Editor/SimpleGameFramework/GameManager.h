#pragma once

#include "GameFramework.h"
#include "GameObject.h"


class GameManager
{
public:
	static GameManager& Instance();

	/** BeginPlay is called when the game first launches. It is only called once per launch. */
	void BeginPlay();

	/** EndPlay is called when the game is closing down. It is only called once and only on exit. */
	void EndPlay();

	/**
	 * Update is called every frame. Update is always called before render
	 *
	 * @param deltaTime The time in seconds since Update was last called.
	 */
	void Update(double deltaTime);

	/**
	 * Render is called every frame after Update is called. All drawing must happen in render.
	 *
	 * @param [in,out] canvas The canvas.
	 * @param clientRect	  The rectangle representing the drawable area.
	 */
	void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);

	void PlayerInput(int axisH, int axisV);

	void PlayerLocation(int playerAxisH, int playerAxisV);

	Vector2i PlayerOffset = Vector2i::Zero;

	void CreateObject(GameObjectType);

	Vector2i playerLocation = Vector2i(800,600);

public:
	bool editMode = false;
	int noObjects = 0;
	int numBarrels = 0;

private:
	GameManager();
	~GameManager();

	std::vector<GameObject*> objects;
	std::vector<GameObject*> playerObject;
};

/**
 * Retrieves the GameManagerInstance for the game.
 *
 * @return The game manager instance
 */
#define GameManagerInstance (GameManager::Instance())
