#pragma once

#include "Graphics.h"

class Game
{
private:
	HWND _hWnd;
	// uint32 _width = 0;
	// uint32 _height = 0;
	shared_ptr<Graphics> _graphics;
	shared_ptr<Pipeline> _pipeline;

public:
	void Init(HWND _hwnd);
	void Update();
	void Render();

private:
	// Geometry -> 언리얼에서는 메쉬의 정보를 나타냄. 
	shared_ptr<Geometry<VertexTextureData>> _geometry;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<InputLayout> _inputLayout;

	// VS
	shared_ptr<VertexShader> _vertexShader;

	// RS
	shared_ptr<RasterizerState> _rasterizerState;

	// PS
	shared_ptr<PixelShader> _pixelShader;

	// SRV - shader resource view
	shared_ptr<Texture> _texture1;
	
	shared_ptr<SamplerState> _samplerState;
	shared_ptr<BlendState> _blendState;


private:
	TransformData _transformData;
	shared_ptr<ConstantBuffer<TransformData>> _constantBuffer;

	Vec3 _localPosition = { 0.f, 0.f, 0.f };
	Vec3 _localRotation = { 0.f, 0.f, 0.f };
	Vec3 _localScale = { 1.f, 1.f, 1.f };


public:
	Game();
	~Game();
};

