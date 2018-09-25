#include "olcPixelGameEngine.h"
#include "olcController.h"

#include <stdio.h>

class Application : public olc::PixelGameEngine
{
private:
	ControllerManager controller;

	olc::Sprite* controllerBase;
	olc::Sprite* stick;

	olc::Sprite* up;
	olc::Sprite* down;
	olc::Sprite* left;
	olc::Sprite* right;
	olc::Sprite* start;
	olc::Sprite* back;

	olc::Sprite* a;
	olc::Sprite* b;
	olc::Sprite* x;
	olc::Sprite* y;

public:
	Application()
	{
		sAppName = "Controller Demo";
	}
public:
	bool OnUserCreate() override
	{
		controller.Initialize();

		controllerBase = new olc::Sprite("res/controller_base.png");
		stick = new olc::Sprite("res/stick.png");

		up = new olc::Sprite("res/up.png");
		down = new olc::Sprite("res/down.png");
		left = new olc::Sprite("res/left.png");
		right = new olc::Sprite("res/right.png");
		start = new olc::Sprite("res/start.png");
		back = new olc::Sprite("res/back.png");

		a = new olc::Sprite("res/a.png");
		b = new olc::Sprite("res/b.png");
		x = new olc::Sprite("res/x.png");
		y = new olc::Sprite("res/y.png");

		return true;
	}

	bool OnUserUpdate(float dt) override
	{
		Clear(olc::GREY);

		SetPixelMode(olc::Pixel::ALPHA);

		DrawSprite(10, 10, controllerBase);

		DrawSprite(47 + (controller.GetLeftStickX() * 7), 38 + (-controller.GetLeftStickY() * 7), stick);
		DrawSprite(126 + (controller.GetRightStickX() * 7), 69 + (-controller.GetRightStickY() * 7), stick);

		if (controller.GetButton(UP).bHeld) DrawSprite(78, 66, up);
		if (controller.GetButton(DOWN).bHeld) DrawSprite(78, 87, down);
		if (controller.GetButton(LEFT).bHeld) DrawSprite(67, 77, left);
		if (controller.GetButton(RIGHT).bHeld) DrawSprite(88, 77, right);
		if (controller.GetButton(START).bHeld) DrawSprite(120, 44, start);
		if (controller.GetButton(BACK).bHeld) DrawSprite(90, 44, back);

		if (controller.GetButton(A).bHeld) DrawSprite(155, 55, a);
		if (controller.GetButton(B).bHeld) DrawSprite(169, 42, b);
		if (controller.GetButton(X).bHeld) DrawSprite(141, 42, x);
		if (controller.GetButton(Y).bHeld) DrawSprite(155, 28l, y);

		if (controller.GetLeftTrigger() != 0)
		{
			char buf[128];
			sprintf_s(buf, "%.02f", controller.GetLeftTrigger());
			DrawString(0, 0, buf, olc::BLACK);
		}

		if (controller.GetRightTrigger() != 0)
		{
			char buf[128];
			sprintf_s(buf, "%.02f", controller.GetRightTrigger());
			DrawString(188, 0, buf, olc::BLACK);
		}

		controller.Update(dt);
		return true;
	}
};

int main()
{
	Application app;
	app.Construct(220, 161, 2, 2);
	app.Start();

	return 0;
}
