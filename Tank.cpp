#include "Tank.h"

#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Ground.h"
//�R���X�g���N�^
Tank::Tank(GameObject * parent)
	:GameObject(parent, "Tank"), hModel_(-1)
{
}

//�f�X�g���N�^
Tank::~Tank()
{
}

//������
void Tank::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);//assert = �A�T�[�g�ƓǂށI�@�@�@���������ꍇ�O�ȏ�̐��������邪�A���s�����ꍇ-1������A��΂ɂł��Ȃ��悤�ɂȂ��Ă���B
}

//�X�V
void Tank::Update()
{
	XMVECTOR move = { 0.0f, 0.0f, 0.1f, 0.0f };     //���Ԃ� x, y, z, ������Ƃ��������ԂɂȂ��Ă���B������͎l��������Ȃ̂ŁA3�����̏ꍇ��
	//�قƂ�ǎg�����Ƃ͂Ȃ�

	XMMATRIX matt;
	matt = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.vecY));//���̏ꍇ�́Amatt�Ƃ����ϐ���vecY�x�ɉ�]������

	move = XMVector3TransformCoord(move, matt);
	//�x�N�g�����s��ɓK���ł���悤�ɂ���B���̏ꍇ�A()�ɂ���move��matt�ɉ����Ăł���悤�ɂ���


	if (Input::IsKey(DIK_W))
	{
		transform_.position_ += move;
	}

	if (Input::IsKey(DIK_S))
	{
		transform_.position_ -= move;
	}

	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.vecY -= 3;
	}

	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.vecY += 3;
	}
	Camera::SetTarget(transform_.position_);
	//�J�����̈ʒu
	XMVECTOR camVec = { 0,6.0f,-15.0f };//�J�����̈ʒu��ݒ肷��
	
	matt = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.vecY));
	camVec = XMVector3TransformCoord(camVec, matt);
	Camera::SetPosition(transform_.position_ + camVec );//�J�����̃|�W�V�����́A��Ԃ̈ʒu�{�J�����̈ʒu��ݒ肵�����̂Ŏʂ���悤�ɂł���B
	//�n�ʂɓY�킹��
	Ground* pGround = (Ground*)FindObject("Ground.fbx");    //�O���E���h.fbx�Ƃ����Q�[���I�u�W�F�N�g��T��
	int hGroundModel = pGround->GetModelHandle();    //���f���ԍ����擾

	//���C���΂�
	RayCastData data;
	data.start = transform_.position_;   //���C�̔��ˈʒu
	data.dir = XMVectorSet(0, -1, 0, 0); //���C�̕���
	Model::RayCast(hGroundModel, &data); //���C�𔭎�

	//���C������������
	if (data.hit)
	{
		//���̕��ʒu��������
		transform_.position_.vecY -= data.dist;
	}
}

//�`��
void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Tank::Release()
{
}