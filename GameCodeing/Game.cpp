#include "pch.h"
#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}


void Game::Init(HWND hwnd)
{
	_hWnd = hwnd;

	_graphics = make_shared<Graphics>(hwnd);
	_vertexBuffer = make_shared<VertexBuffer>(_graphics->GetDevice());
	_indexBuffer = make_shared<IndexBuffer>(_graphics->GetDevice());
	_inputLayout = make_shared<InputLayout>(_graphics->GetDevice());
	_geometry = make_shared<Geometry<VertexTextureData>>();
	_vertexShader = make_shared<VertexShader>(_graphics->GetDevice());
	_pixelShader = make_shared<PixelShader>(_graphics->GetDevice());
	_constantBuffer = make_shared<ConstantBuffer<TransformData>>(_graphics->GetDevice(), _graphics->GetDeviceContext());
	_texture1 = make_shared<Texture>(_graphics->GetDevice());

	_rasterizerState = make_shared<RasterizerState>(_graphics->GetDevice());
	_samplerState = make_shared<SamplerState>(_graphics->GetDevice());
	_blendState = make_shared<BlendState>(_graphics->GetDevice());

	_pipeline = make_shared<Pipeline>(_graphics->GetDeviceContext());


	// 삼각형 생성
		// Vertex Data
		GeometryHelper::CreateRectangle(_geometry);

		// VertexBuffer
		_vertexBuffer->Create(_geometry->GetVertices());

		// IndexBuffer
		_indexBuffer->Create(_geometry->GetIndices());

	// 쉐이더 로드
	_vertexShader->Create(L"Default.hlsl", "VS", "vs_5_0");

	_inputLayout->Create(VertexTextureData::descs, _vertexShader->GetBlob());	// 구조체의 생김새 자체를 Layout으로 만듬.

	_pixelShader->Create(L"Default.hlsl", "PS", "ps_5_0");

	_texture1->Create(L"Mush.png");
	_constantBuffer->Create();
}



void Game::Update()
{
	// scale rotation translation // SRT
	
	Matrix matScale = Matrix::CreateScale(_localScale / 3);
	Matrix matRotation = Matrix::CreateRotationX(_localRotation.x);
	matRotation *= Matrix::CreateRotationY(_localRotation.y);
	matRotation *= Matrix::CreateRotationZ(_localRotation.z);
	Matrix matTranslation = Matrix::CreateTranslation(_localPosition);

	Matrix matWorld = matScale * matRotation * matTranslation; // SRT
	_transformData.matWorld = matWorld;

	_constantBuffer->CopyData(_transformData);
}
 
void Game::Render()
{
	_graphics->RenderBegin();

	// IA - VS - RS - PS - OM
	{
		PipelineInfo info;
		info.inputLayout = _inputLayout;
		info.vertexShader = _vertexShader;
		info.pixelShader = _pixelShader;
		info.rasterizerState = _rasterizerState;
		info.blendState = _blendState;
		_pipeline->UpdatePipeline(info);

		auto _deviceContext = _graphics->GetDeviceContext();
		_pipeline->SetVertexBuffer(_vertexBuffer);
		_pipeline->SetIndexBuffer(_indexBuffer);
		_pipeline->SetConstantBuffer(0, SS_VertexShader, _constantBuffer);
		_pipeline->SetTexture(0, SS_PixelShader, _texture1);
		_pipeline->SetSamplerState(0, SS_PixelShader, _samplerState);

		_pipeline->DrawIndexed(_geometry->GetIndexCount(), 0, 0);
	}

	_graphics->RenderEnd();
}
