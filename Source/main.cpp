#include "DxLib.h"
#include "keyboard.h"
#include "Scene_Mgr.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetMainWindowText("ゼミ ゲーム制作");
	SetWindowSize(1472, 768);
	SetGraphMode(1472,768,32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	//初期化管理関数の呼び出し
	Scene_Mgr_Init();
	//Init_Mgr();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//ここに処理を追加
		Keyboard_Update();

		Scene_Mgr_Dpct();   //計算処理
			
		Scene_Mgr_Draw();   //描写処理
	}
	Scene_Mgr_End();	//終了処理

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}
