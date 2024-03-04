#pragma once
#include "Types.h"

// 공용으로 사용할 struct를 관리


struct Vertex
{
	Vec3 position;	// 12 BYTE
	//Color color;
	Vec2 uv;
};

// constant buffer를 만들때는 16바이트 정렬을 해야하기 때문에
// Vec3는 float가 3개인 12바이트 자료형이므로, 더미 float를 하나 추가한다.

struct CameraData
{
	Matrix matView = Matrix::Identity;
	Matrix matProjection = Matrix::Identity;
};

struct TransformData
{
	Matrix matWorld = Matrix::Identity;
};