#include "Cannon.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"
//コンストラクタ
Cannon::Cannon(GameObject * parent)
	:GameObject(parent, "Cannon"), hModel_(-1),
	SWING_SPEED(3.0f)
{
}

//デストラクタ
Cannon::~Cannon()
{
}

//初期化
void Cannon::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);  
}

//更新
void Cannon::Update()
{
	if (Input::IsKey(DIK_RIGHT))
	{//右矢印をクリックした場合、右へ回転する。
		transform_.rotate_.vecY += SWING_SPEED;
	}

	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.vecY -= SWING_SPEED;
	}

	if (Input::IsKeyDown(DIK_SPACE))
	{   //SPACEを押した場合、弾が出る
		Bullet* pBullet = Instantiate<Bullet>(FindObject("PlayScene"));
		pBullet->SetPosition(transform_.position_);
	}
}

//描画
void Cannon::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Cannon::Release()
{
}