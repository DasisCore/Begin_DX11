#pragma once
#include "Types.h"

// �������� ����� struct�� ����


struct Vertex
{
	Vec3 position;	// 12 BYTE
	//Color color;
	Vec2 uv;
};

// constant buffer�� ���鶧�� 16����Ʈ ������ �ؾ��ϱ� ������
// Vec3�� float�� 3���� 12����Ʈ �ڷ����̹Ƿ�, ���� float�� �ϳ� �߰��Ѵ�.

struct CameraData
{
	Matrix matView = Matrix::Identity;
	Matrix matProjection = Matrix::Identity;
};

struct TransformData
{
	Matrix matWorld = Matrix::Identity;
};