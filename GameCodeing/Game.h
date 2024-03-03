#pragma once

#include "Graphics.h"
#include "GameObject.h"

class Game
{
private:
	HWND _hWnd;

	shared_ptr<Graphics> _graphics;
	shared_ptr<Pipeline> _pipeline;

	// Temp
	shared_ptr<GameObject> _monster;
	shared_ptr<GameObject> _camera;

public:
	void Init(HWND _hwnd);
	void Update();
	void Render();

public:
	Game();
	~Game();
};

