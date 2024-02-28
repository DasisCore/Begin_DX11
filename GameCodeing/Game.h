#pragma once

#include "Graphics.h"
#include "GameObject.h"

class Game
{
private:
	HWND _hWnd;

	shared_ptr<Graphics> _graphics;
	shared_ptr<Pipeline> _pipeline;

	shared_ptr<GameObject> _gameObject;

public:
	void Init(HWND _hwnd);
	void Update();
	void Render();

public:
	Game();
	~Game();
};

