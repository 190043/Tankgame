#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Cannon : public GameObject
{
	//const float SWING_SPEED;	
	int hModel_;
public:
	//�R���X�g���N�^
	Cannon(GameObject* parent);

	//�f�X�g���N�^
	~Cannon();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};