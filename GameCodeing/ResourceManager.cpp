#include "pch.h"
#include "ResourceManager.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Animation.h"

ResourceManager::ResourceManager(ComPtr<ID3D11Device> device)
	: _device(device)
{
}

void ResourceManager::Init()
{
	CreateDefaultTexture();
	CreateDefaultMesh();
	CreateDefaultShader();
	CreateDefaultMaterial();
	CreateDefaultAnimation();
}

void ResourceManager::CreateDefaultTexture()
{
	{
		auto texture = make_shared<Texture>(_device);
		texture->SetName(L"Snake");
		texture->Create(L"Snake.bmp");
		Add(texture->GetName(), texture);
	}

	{
		auto texture = make_shared<Texture>(_device);
		texture->SetName(L"Mush");
		texture->Create(L"Mush.png");
		Add(texture->GetName(), texture);
	}
}

void ResourceManager::CreateDefaultMesh()
{
	shared_ptr<Mesh> mesh = make_shared<Mesh>(_device);
	mesh->SetName(L"Rectangle");
	mesh->CreateDefaultRectangle();
	Add(mesh->GetName(), mesh);
}

void ResourceManager::CreateDefaultShader()
{
	shared_ptr<VertexShader> vertexShader = make_shared<VertexShader>(_device);
	vertexShader->Create(L"Default.hlsl", "VS", "vs_5_0");

	shared_ptr<InputLayout> inputLayout = make_shared<InputLayout>(_device);
	inputLayout->Create(VertexTextureData::descs, vertexShader->GetBlob());	// 구조체의 생김새 자체를 Layout으로 만듬.

	shared_ptr<PixelShader> pixelShader = make_shared<PixelShader>(_device);
	pixelShader->Create(L"Default.hlsl", "PS", "ps_5_0");

	// Shader
	shared_ptr<Shader> shader = make_shared<Shader>();
	shader->SetName(L"Default");
	shader->_inputLayout = inputLayout;
	shader->_vertexShader = vertexShader;
	shader->_pixelShader = pixelShader;

	Add(shader->GetName(), shader);
}

void ResourceManager::CreateDefaultMaterial()
{
	shared_ptr<Material> material = make_shared<Material>();
	material->SetName(L"Default");
	material->SetShader(Get<Shader>(L"Default"));
	material->SetTexture(Get<Texture>(L"Mush"));
	Add(material->GetName(), material);
}

void ResourceManager::CreateDefaultAnimation()
{
	shared_ptr<Animation> animation = make_shared<Animation>();
	animation->SetName(L"SnakeAnim");
	animation->SetTexture(Get<Texture>(L"Snake"));
	animation->SetLoop(true);

	animation->AddKeyframe(Keyframe{ Vec2{0.f, 0.f}, Vec2{100.f, 100.f}, 0.1f });
	animation->AddKeyframe(Keyframe{ Vec2{100.f, 0.f}, Vec2{100.f, 100.f}, 0.1f });
	animation->AddKeyframe(Keyframe{ Vec2{200.f, 0.f}, Vec2{100.f, 100.f}, 0.1f });
	animation->AddKeyframe(Keyframe{ Vec2{300.f, 0.f}, Vec2{100.f, 100.f}, 0.1f });

	Add(animation->GetName(), animation);

	// XML + JSON
	animation->Save(L"TestAnim.xml");

	shared_ptr<Animation> anim2 = make_shared<Animation>();

	animation->Load(L"TestAnim.xml");


}
