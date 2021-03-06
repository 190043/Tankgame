#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Tank : public GameObject
{
	int hModel_;    //モデル番号

	//移動するための処理
	//引数　なし
	//戻り値　なし
	void Move();

	//地面に沿って動くための処理
	//引数　なし
	//戻り値 なし
	void FitHeightToGround();

public:
	//コンストラクタ
	Tank(GameObject* parent);

	//デストラクタ
	~Tank();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};