#include "Tank.h"

#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

#include "Ground.h"
#include "Cannon.h"

//コンストラクタ
Tank::Tank(GameObject * parent)
	:GameObject(parent, "Tank"), hModel_(-1)
{
}

//デストラクタ
Tank::~Tank()
{
}

//初期化
void Tank::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);//assert = アサートと読む！　　　成功した場合０以上の数字が入るが、失敗した場合-1が入り、絶対にできないようになっている。

	Instantiate<Cannon>(this); //CannonをTankの子供として出していく。 PlaySceneのTankとGroundと同じもの
}

//更新
void Tank::Update()
{
	Move();

	FitHeightToGround();

	
}

//移動のための処理
void Tank::Move() 
{
	XMVECTOR move = { 0.0f, 0.0f, 0.1f, 0.0f };     //順番に x, y, z, もう一つといった順番になっている。もう一つは四次元限定なので、3次元の場合は
	//ほとんど使うことはない

	XMMATRIX matt;
	matt = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.vecY));//この場合は、mattという変数がvecY度に回転させる

	move = XMVector3TransformCoord(move, matt);
	//ベクトルを行列に適応できるようにする。この場合、()にあるmoveはmattに応じてできるようにする


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
		transform_.rotate_.vecY -= 1;
	}

	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.vecY += 1;
	}
	Camera::SetTarget(transform_.position_);
	//カメラの位置
	XMVECTOR camVec = { 0,8.0f,-15.0f };//カメラの位置を設定する

	
	Camera::SetPosition(transform_.position_ + camVec);//カメラのポジションは、戦車の位置＋カメラの位置を設定したもので写せるようにできる。
}

//高さを地面に合わせる
void Tank::FitHeightToGround() 
{
	//地面に添わせる
	Ground* pGround = (Ground*)FindObject("Ground");    //グラウンドというゲームオブジェクトを探す
	int hGroundModel = pGround->GetModelHandle();    //モデル番号を取得

	//レイを飛ばす
	RayCastData data;
	data.start.vecX = transform_.position_.vecX;   //レイの発射位置 X
	data.start.vecY = 0.0f;                        //レイの発射位置 Y
	data.start.vecZ = transform_.position_.vecZ;   //レイの発射位置 Z

	data.dir = XMVectorSet(0, -1, 0, 0); //レイの方向
	Model::RayCast(hGroundModel, &data); //レイを発射

	//レイが当たったら
	if (data.hit)
	{
		//その分位置を下げる
		transform_.position_.vecY = -data.dist;
	}
}

//描画
void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Tank::Release()
{
}