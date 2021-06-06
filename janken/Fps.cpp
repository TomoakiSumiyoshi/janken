#include "DxLib.h"
#include "Fps.h"

const static int LIST_LEN_MAX = 120;	//最大120フレームで待機処理を計算する(2以上にする)
const static int FPS = 60;				//FPS
const static int UPINTVL = 60;			//60フレームに一度更新する

Fps::Fps() : counter(0), fps(0) 
{
}

void Fps::wait()
{
	counter++;
	Sleep(getWaitTime());	//待つべき時間を取得して待つ。
	regist();
	if (counter == UPINTVL) {	//更新タイミングに1回平均値を更新する
		updateAverage();
		counter = 0;
	}
}

void Fps::draw() const
{
	if (fps == 0) {
		return;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%04.1ffps", fps);
}

void Fps::regist()
{
	timeList.push_back(GetNowCount());
	if (timeList.size() > LIST_LEN_MAX) {
		timeList.pop_front();
	}
}

unsigned int Fps::getWaitTime() const
{
	int len = (int)timeList.size();
	if (len == 0) {
		return 0;
	}
	int shouldTookTime = (int)(1000 / 60.f * (len));			//計算上かかるべき時間
	int actuallyTookTime = GetNowCount() - timeList.front();	//実際にかかった時間
	int waitTime = shouldTookTime - actuallyTookTime;			//待つべき時間
	waitTime = waitTime > 0 ? waitTime : 0;
	return (unsigned int)waitTime;
}

void Fps::updateAverage()
{
	int len = (int)timeList.size();
	if (len < LIST_LEN_MAX) {	//まだ平均を計算するレベルにまでたまっていなければ計算しない
		return;
	}
	int tookTime = timeList.back() - timeList.front();	//LIST_LEN_MAXフレームにかかった時間
	float average = (float)tookTime / (len - 1);		//平均を取る
	if (average == 0) {
		return;
	}
	fps = roundf((1000 / average) * 10) / 10;			//少数第2位で四捨五入する
}
