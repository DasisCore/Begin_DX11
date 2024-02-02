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
	// DX

	// Device & SwapChain
	// �޸� ������ ����Ʈ������ / wrl
	ComPtr<ID3D11Device> _device = nullptr;
	ComPtr<ID3D11DeviceContext> _deviceContext = nullptr;
	ComPtr<IDXGISwapChain> _swapChain = nullptr;

	// RTV
	ComPtr<ID3D11RenderTargetView> _renderTargetView;

	// Mics
	D3D11_VIEWPORT _viewport = { 0 };
	float _clearColor[4] = { 0.5f, 0.5f, 0.5f, 0.5f };


public:
	Game();
	~Game();
};

