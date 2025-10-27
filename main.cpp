#include"Calculation.h"
#include <Novice.h>
#include <cmath>
#include <numbers>
#include <algorithm>
#include<imgui.h>
#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp"
#include "glm/gtx/norm.hpp"


const char kWindowTitle[] = "LE2D_12_サトウ_シオン";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Calculation* calculation = new Calculation();
	Calculation::Vector3 from0 = calculation->Normalize(Calculation::Vector3{ 1.0f,0.7f,0.5f });
	Calculation::Vector3 to0 = from0;
	Calculation::Vector3 from1 = calculation->Normalize(Calculation::Vector3{ -0.6f,0.9f,0.2f });
	Calculation::Vector3 to1 = calculation->Normalize(Calculation::Vector3{ 0.4f,0.7f,-0.5f });
	Calculation::Matrix4x4 rotateMatrix0 = { calculation->DirectionToDirection(calculation->Normalize(Calculation::Vector3{1.0f,0.0f,0.0f}),calculation->Normalize(Calculation::Vector3{-1.0f,0.0f,0.0f})) };
	Calculation::Matrix4x4 rotateMatrix1 =  calculation->DirectionToDirection(from0,to0);
	Calculation::Matrix4x4 rotateMatrix2 = calculation->DirectionToDirection(from1, to1);
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
	
		


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		calculation->MatrixScreenPrintf(0, 0, rotateMatrix0,"rotateMatrix0");
		calculation->MatrixScreenPrintf(0, calculation->kRowHeight * 5, rotateMatrix1, "rotateMatrix1");
		calculation->MatrixScreenPrintf(0, calculation->kRowHeight * 10, rotateMatrix2, "rotateMatrix2");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}