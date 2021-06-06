#include "Dxlib.h"
#include "SystemMain.h"
#include "Looper.h"
#include "Define.h"

bool SystemMain::initialize() const
{
	SetAlwaysRunFlag(TRUE);										//ウィンドウがノンアクティブでも実行
	SetWindowSizeChangeEnableFlag(TRUE);						//ウィンドウサイズを自由に変更できるようにする
	SetOutApplicationLogValidFlag(FALSE);						//ログを出力しない
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);	//フルスクリーン時に縦横比を維持する
	SetWindowText("じゃんけん");								//ウィンドウタイトルをつける
	ChangeWindowMode(TRUE);										//ウィンドウモードに変更
	//SetWindowSizeExtendRate(1.0);								//ウィンドウサイズを変更したい時はここに倍率を指定する
	const int COLOR_BIT = 32;									//色のbit数　通常は32 軽くする場合16
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);		//ゲームの解像度を設定する
	SetWindowInitPosition(0, 0);								//ウィンドウの初期位置を設定する
	if (DxLib_Init()) {											//DXライブラリ初期化処理
		return false;											//異常終了したら即座に終了
	}
	SetDrawScreen(DX_SCREEN_BACK);								//裏画面処理を設定する
	return true;
}

void SystemMain::finalize() const
{
	DxLib_End();
}

void SystemMain::main() const
{
	Looper looper;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {	//左から順に裏画面を表画面に反映,メッセージ処理,画面クリア
		if (!looper.loop()) {
			break;
		}
	}
}