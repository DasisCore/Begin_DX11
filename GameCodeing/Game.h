#pragma once
class Game
{
private:
	HWND _hWnd;
	uint32 _width = 0;
	uint32 _height = 0;


public:
	void Init(HWND _hwnd);
	void Update();
	void Render();

private:
	void RenderBegin();
	void RenderEnd();

private:
	void CreateDeviceAndSwapChain();
	void CreateRenderTargetView(); 
	void SetViewport();

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
	// DX

	// Device & SwapChain
	// 메모리 관리용 스마트포인터 / wrl
	ComPtr<ID3D11Device> _device = nullptr;
	ComPtr<ID3D11DeviceContext> _deviceContext = nullptr;
	ComPtr<IDXGISwapChain> _swapChain = nullptr;

	// RTV  => Render Target View
	ComPtr<ID3D11RenderTargetView> _renderTargetView;

	// Mics
	D3D11_VIEWPORT _viewport = { 0 };
	float _clearColor[4] = { 0.f, 0.f, 0.f, 0.f };

private:
	// Geometry -> 언리얼에서는 메쉬의 정보를 나타냄. 
	vector<Vertex> _vertices;
	ComPtr<ID3D11Buffer> _vertexBuffer = nullptr;
	vector<uint32> _indices;
	ComPtr<ID3D11Buffer> _indexBuffer = nullptr;
	ComPtr<ID3D11InputLayout> _inputLayout = nullptr;


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

