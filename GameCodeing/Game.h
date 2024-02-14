#pragma once

#include "Graphics.h"

class Game
{
private:
	HWND _hWnd;
	// uint32 _width = 0;
	// uint32 _height = 0;
	shared_ptr<Graphics> _graphics;


public:
	void Init(HWND _hwnd);
	void Update();
	void Render();

private:
	void CreateGeometry();
	void CreateInputLayout();

	void CreateVS();
	void CreatePS();

	void CreateRasterizerState();

	void CreateSamplerState();
	void CreateBlendState();

	void CreateSRV(); // shader resource view

	void CreateConstantBuffer();

	void LoadShaderFromFile(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob);






private:
	// Geometry -> 언리얼에서는 메쉬의 정보를 나타냄. 
	vector<Vertex> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;
	//ComPtr<ID3D11Buffer> _vertexBuffer = nullptr;

	vector<uint32> _indices;
	shared_ptr<IndexBuffer> _indexBuffer;
	//ComPtr<ID3D11Buffer> _indexBuffer = nullptr;
	//ComPtr<ID3D11InputLayout> _inputLayout = nullptr;
	shared_ptr<InputLayout> _inputLayout;

	// VS
	ComPtr<ID3D11VertexShader> _vertexShader = nullptr;
	ComPtr<ID3DBlob> _vsBlob = nullptr;


	// RS
	ComPtr<ID3D11RasterizerState> _rasterizerState = nullptr;


	// PS
	ComPtr<ID3D11PixelShader> _pixelShader = nullptr;
	ComPtr<ID3DBlob> _psBlob = nullptr;

	// SRV - shader resource view
	ComPtr<ID3D11ShaderResourceView> _shaderResourceView = nullptr;

	
	ComPtr<ID3D11SamplerState> _samplerState = nullptr;
	ComPtr<ID3D11BlendState> _blendState = nullptr;



private:
	TransformData _transformData;
	ComPtr<ID3D11Buffer> _constantBuffer;

	Vec3 _localPosition = { 0.f, 0.f, 0.f };
	Vec3 _localRotation = { 0.f, 0.f, 0.f };
	Vec3 _localScale = { 1.f, 1.f, 1.f };


public:
	Game();
	~Game();
};

