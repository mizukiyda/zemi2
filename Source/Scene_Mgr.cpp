#include "DxLib.h"
#include "Scene_Mgr.h"
#include "StartMenu.h"
#include "Player.h"
#include "Enemy.h"
#include "MAP.h"
#include "UI.h"

static E_Scene Sceneflag = E_Scene_StartMenu;		//今のシーン
static E_Scene n_Sceneflag = E_Scene_None;			//次のシーン

static void Scene_Mgr_Init_Module(E_Scene scene);	//指定モジュールを初期化する
static void Scene_Mgr_End_Module(E_Scene scene);	//指定モジュールの終了処理を行う
													//init 初期化
void Scene_Mgr_Init() {
	Scene_Mgr_Init_Module(Sceneflag);
}

//Dpct 計算
void Scene_Mgr_Dpct() {
	if (n_Sceneflag != E_Scene_None) {		//次のシーンがセットされていたら
		Scene_Mgr_End_Module(Sceneflag);	    //現在のシーンの終了処理を実行
		Sceneflag = n_Sceneflag;			//次のシーンを現在のシーンにセット
		n_Sceneflag = E_Scene_None;			//次のシーン情報をクリア
		Scene_Mgr_Init_Module(Sceneflag);	//現在のシーンを初期化
	}

	switch (Sceneflag) {
	case E_Scene_StartMenu:
		//スタートメニュー
		StartMenu_Dpct();
		break;

	case E_Scene_Game:
		//ゲーム画面		
		MAP_Dpct();
	    Enemy_Dpct();
		Player_Dpct();
		UI_Dpct();

		break;

	case E_Scene_GameMenu:
		//ゲームメニュー
		break;
	}
}

//Drow 描画
void Scene_Mgr_Draw() {
	switch (Sceneflag) {
	case E_Scene_StartMenu:
		//スタートメニュー
		StartMenu_Draw();
		break;
	case E_Scene_Game:
		//ゲーム画面
		MAP_Draw();
		Enemy_Draw();
		Player_Draw();
		UI_Draw();
		break;
	
		break;
	case E_Scene_GameMenu:
		//ゲームメニュー
		DrawFormatString(0, 00, GetColor(255, 255, 255), "ゲームメニュー");
		break;
	}
}

//End
void Scene_Mgr_End() {
	Scene_Mgr_End_Module(Sceneflag);
}

void Scene_Mgr_ChangeScene(E_Scene NextScene) {
	n_Sceneflag = NextScene;
}

//指定モジュールの初期化をする
static void Scene_Mgr_Init_Module(E_Scene scene) {
	switch (scene) {
	case E_Scene_StartMenu:
		//スタートメニュー
		StartMenu_Init();
		break;
	case E_Scene_Game:
		//ゲーム画面
		Player_Init();
		Enemy_Init();
		MAP_Init();
		UI_Init();
		break;

	case E_Scene_GameMenu:
		//ゲームメニュー
		break;
	}
}

//指定モジュールの終了処理を行う
static void Scene_Mgr_End_Module(E_Scene scene) {
	switch (scene) {
	case E_Scene_StartMenu:
		//スタートメニュー
		StartMenu_End();
		break;
	case E_Scene_Game:
		//ゲーム画面
		Enemy_End();
		Player_End();
		MAP_End();
		UI_End();

	case E_Scene_GameMenu:
		//ゲームメニュー
		break;
	}
}
