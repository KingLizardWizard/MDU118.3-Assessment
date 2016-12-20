#include "stdafx.h"
#include "GameManager.h"
#include "Rock.h"
#include "Barrel.h"
#include "HealingMist.h"
#include "Fire.h"
#include "Pickaxe.h"
#include "Medkit.h"
#include "ArrowTrap.h"
#include "CaveBat.h"
#include "Player.h"
#include <fstream>

GameManager& GameManager::Instance()
{
	static GameManager instance;

	return instance;
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}


const char* rockImage1 = "RockImage1";
const char* floorImage = "FloorImage";
bool createRun = false;

void GameManager::BeginPlay()
{
	//Load all of the images from the Images Directory and set names to them
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Rock.gif"), "RockImage");
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Floor.png"), "FloorImage");

	//Input for the Player Object
	Player* player1 = new Player;
	player1->type = egotPlayer;
	player1->location = Vector2i(800, 600);
	player1->name = "Player";
	player1->rotation = 1.0f;
	player1->xScale = 3.0f;
	player1->yScale = 3.0f;
	player1->imageName = "PlayerImage";
	player1->health = 100;
	player1->moveSpeed = 5;
	player1->fireRate = 1;
	player1->damage = 10;

	std::ofstream outputFile("objects.csv");

	AABBi boundingBox(Vector2i(playerLocation.X - 32, playerLocation.Y - 32), Vector2i(playerLocation.X + 32, playerLocation.Y + 32));
	AABBi bigbox(Vector2i(10, 5), Vector2i(1200, 600));

	//Version Number
	outputFile << 2 << std::endl;

	//Number of Objects
	outputFile << 3 << std::endl;

	//Save all of the objects to a textfile
	player1->SaveAsText(outputFile);
	//rock1->SaveAsText(outputFile);
	//barrel1->SaveAsText(outputFile);
	/*healingMist1->SaveAsText(outputFile);
	fire1->SaveAsText(outputFile);
	pickaxe1->SaveAsText(outputFile);
	medkit1->SaveAsText(outputFile);
	arrowTrap1->SaveAsText(outputFile);
	caveBat1->SaveAsText(outputFile);
	caveBat2->SaveAsText(outputFile);
	outputFile.close();*/

	//Free up memory by deleting the unneeded objects
	delete player1;

	std::ifstream inputFile("objects.csv");
	int versionNumber = 4;
	int numObjects = 1;
	inputFile >> versionNumber;
	inputFile >> numObjects;

	int typeValue;
	inputFile >> typeValue;
	
	GameObjectType type = (GameObjectType)typeValue;

	//Read the enumeration into a integer and then cast it to the specific enum	
	GameObject* loadedObjectPtr = nullptr;
	loadedObjectPtr = new Player;

	//Load the correct object type from the text file
	loadedObjectPtr->LoadFromText(inputFile);
	playerObject.push_back(loadedObjectPtr);
}

void GameManager::EndPlay()
{
	//Iterate over all of the game objects in the Vector
	std::vector<GameObject*>::iterator objectIt;
	for (objectIt = objects.begin(); objectIt != objects.end(); ++objectIt)
	{
		GameObject* objectPtr = *objectIt;
		delete objectPtr;
	}

	//Empty all of the elements out of the Vector
	objects.clear();
}

// activates whenever W A S or D is pressed
void GameManager::PlayerInput(int axisH, int axisV)
{
	PlayerOffset += Vector2i(axisH, axisV);
}

// activates whenever W A S or D is pressed
void GameManager::PlayerLocation(int playerAxisH, int playerAxisV)
{
	playerLocation += Vector2i(playerAxisH, playerAxisV);
}

// This function spawns all of the objects
void GameManager::CreateObject(GameObjectType)
{
		//Input for the Rock Object
		Rock* rock1 = new Rock;
		rock1->type = egotRock;
		rock1->location = Vector2i(playerLocation.X, playerLocation.Y);
		rock1->name = "Rock";
		rock1->rotation = 1.0f;
		rock1->xScale = 3.0f;
		rock1->yScale = 3.0f;
		rock1->imageName = "RockImage";
		rock1->destructible = true;

		//Input for the Barrel Object
		Barrel* barrel1 = new Barrel;
		barrel1->type = egotBarrel;
		barrel1->location = Vector2i(playerLocation.X, playerLocation.Y);
		barrel1->name = "Barrel";
		barrel1->rotation = 1.0f;
		barrel1->xScale = 3.0f;
		barrel1->yScale = 3.0f;
		barrel1->imageName = "BarrelImage";
		barrel1->destructible = false;

		//Input for the Healing Mist Object
		HealingMist* healingMist1 = new HealingMist;
		healingMist1->type = egotHealingMist;
		healingMist1->location = Vector2i(600, 500);
		healingMist1->name = "HealingMist";
		healingMist1->rotation = 1.0f;
		healingMist1->xScale = 3.0f;
		healingMist1->yScale = 3.0f;
		healingMist1->imageName = "HealingMistImage";
		healingMist1->healingAmount = 5;

		//Input for the Fire Object
		Fire* fire1 = new Fire;
		fire1->type = egotFire;
		fire1->location = Vector2i(900, 500);
		fire1->name = "Fire";
		fire1->rotation = 1.0f;
		fire1->xScale = 3.0f;
		fire1->yScale = 3.0f;
		fire1->imageName = "FireImage";
		fire1->damageAmount = 5;

		//Input for the Pickaxe Object
		Pickaxe* pickaxe1 = new Pickaxe;
		pickaxe1->type = egotPickaxe;
		pickaxe1->location = Vector2i(1200, 300);
		pickaxe1->name = "Pickaxe";
		pickaxe1->rotation = 1.0f;
		pickaxe1->xScale = 3.0f;
		pickaxe1->yScale = 3.0f;
		pickaxe1->imageName = "PickaxeImage";
		pickaxe1->durability = 5;
		pickaxe1->maxAmount = 1;

		//Input for the Medkit Object
		Medkit* medkit1 = new Medkit;
		medkit1->type = egotMedkit;
		medkit1->location = Vector2i(1200, 500);
		medkit1->name = "Medkit";
		medkit1->rotation = 1.0f;
		medkit1->xScale = 3.0f;
		medkit1->yScale = 3.0f;
		medkit1->imageName = "MedkitImage";
		medkit1->healingAmount = 30;
		medkit1->maxAmount = 1;

		//Input for the ArrowTrap Object
		ArrowTrap* arrowTrap1 = new ArrowTrap;
		arrowTrap1->type = egotArrowTrap;
		arrowTrap1->location = Vector2i(600, 700);
		arrowTrap1->name = "ArrowTrap";
		arrowTrap1->rotation = 1.0f;
		arrowTrap1->xScale = 3.0f;
		arrowTrap1->yScale = 3.0f;
		arrowTrap1->imageName = "ArrowTrapImage";
		arrowTrap1->damage = 25;
		arrowTrap1->fireRate = 1;

		//Input for the CaveBat Object
		CaveBat* caveBat1 = new CaveBat;
		caveBat1->type = egotCaveBat;
		caveBat1->location = Vector2i(900, 700);
		caveBat1->name = "CaveBat";
		caveBat1->rotation = 1.0f;
		caveBat1->xScale = 3.0f;
		caveBat1->yScale = 3.0f;
		caveBat1->imageName = "CaveBatImage";
		caveBat1->health = 15;
		caveBat1->damage = 10;


		std::ofstream outputFile("objects.csv");

		//Version Number
		outputFile << 2 << std::endl;

		//Number of Objects
		outputFile << 1 << std::endl;

		// Saving files to a text document
		rock1->SaveAsText(outputFile);
		barrel1->SaveAsText(outputFile);
		healingMist1->SaveAsText(outputFile);
		fire1->SaveAsText(outputFile);
		pickaxe1->SaveAsText(outputFile);
		medkit1->SaveAsText(outputFile);
		arrowTrap1->SaveAsText(outputFile);
		caveBat1->SaveAsText(outputFile);
		outputFile.close();

		// Freeing up memory
		delete rock1;
		delete barrel1;
		delete healingMist1;
		delete fire1;
		delete pickaxe1;
		delete medkit1;
		delete arrowTrap1;
		delete caveBat1;
	
	std::ifstream inputFile("objects.csv");

	// Back end information
	int versionNumber = 4;
	int numObjects = 1;

	inputFile >> versionNumber;
	inputFile >> numObjects;

		int typeValue = 2;
		inputFile >> typeValue;

		GameObjectType type = (GameObjectType)typeValue;

		//Read the enumeration into a integer and then cast it to the specific enum
		GameObject* loadedObjectPtr = nullptr;
		switch (type)
		{
		case egotBase:
			DebugLog("Error - Object has base type");
			break;

		case egotRock:
			loadedObjectPtr = new Barrel();
			break;

		case egotBarrel:
			loadedObjectPtr = new Barrel();
			break;

		case egotHealingMist:
			loadedObjectPtr = new HealingMist();
			break;

		case egotFire:
			loadedObjectPtr = new Fire();
			break;

		case egotPickaxe:
			loadedObjectPtr = new Pickaxe();
			break;
			
		case egotMedkit:
			loadedObjectPtr = new Medkit();
			break;

		case egotArrowTrap:
			loadedObjectPtr = new ArrowTrap();
			break;

		case egotCaveBat:
			loadedObjectPtr = new CaveBat();
			break;
		}
		//Load the correct object type from the text file
		loadedObjectPtr->LoadFromText(inputFile);
		objects.push_back(loadedObjectPtr);
		
}

void GameManager::Update(double deltaTime)
{
	
}

void GameManager::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//Save the current transformation properties of the scene
	Gdiplus::Matrix transform;
	canvas.GetTransform(&transform);

	canvas.ScaleTransform(0.5f, 0.5f);

	// During this SetTransform all of the objects excluding the player will move
	canvas.TranslateTransform((Gdiplus::REAL)PlayerOffset.X, (Gdiplus::REAL)PlayerOffset.Y);

	//Tell all of the GameObjects to render (includes children)
		for (GameObject* objectPtr : objects)
		{
			objectPtr->Render(canvas, clientRect);
		}
	
	canvas.SetTransform(&transform);

	// Same as above function, however this one isn't affect by a ScaleTransform
	// Creates the floor
	canvas.TranslateTransform((Gdiplus::REAL)PlayerOffset.X, (Gdiplus::REAL)PlayerOffset.Y);

	ImageWrapper* floorImage = GameFrameworkInstance.GetLoadedImage("FloorImage");
	GameFrameworkInstance.DrawImage(canvas, Vector2i(0, 493), floorImage);

	//Restore transformation of scene
	canvas.SetTransform(&transform);

	canvas.ScaleTransform(0.5f, 0.5f);

	//Allows only the player to move
	if (editMode == false)
	{
		for (GameObject* objectPtr : playerObject)
		{
			objectPtr->Render(canvas, clientRect);
		}
	}
	else
	{
		GameFrameworkInstance.DrawRectangle(canvas, AABBi(Vector2i(768, 568), Vector2i(832, 632)), false, Gdiplus::Color::White);
	}

	//Restore transformation of scene
	canvas.SetTransform(&transform);

}