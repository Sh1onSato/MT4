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
	Calculation::Vector3 axis = calculation->Normalize(Calculation::Vector3(1.00f, 1.00f, 1.00f));
	float angle = 0.440f;
	Calculation::Matrix4x4 rotateMatrix = calculation->MakeRotateAxisAngle(axis, angle);
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
		calculation->MatrixScreenPrintf(0, 0, rotateMatrix, "rotateMatrix");
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