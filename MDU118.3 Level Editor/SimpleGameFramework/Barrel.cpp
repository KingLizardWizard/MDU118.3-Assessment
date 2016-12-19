#include "stdafx.h"
#include "Barrel.h"

Barrel::Barrel() :
	GameObject()
{
	type = egotBarrel;
}

Barrel::~Barrel()
{
}

//Draws the class specific shape/name/colour
void Barrel::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawText(canvas, Vector2i(location.X - 55, location.Y - 100), 16, "Arial", "Barrel", Gdiplus::Color::White);
	GameFrameworkInstance.DrawRectangle(canvas, AABBi(Vector2i(location.X, 110), Vector2i(300, 200)), true, Gdiplus::Color::Blue);
}

//Saving Object specific variables
void Barrel::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << destructible;
}

//Loading Object specific variables
void Barrel::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> destructible;
}