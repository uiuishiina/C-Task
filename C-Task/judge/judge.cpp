#include"judge.h"
#include<iostream>
#include <windows.h>

using namespace std;

//@brief	=== 初期化関数 ===
void judge::Initialize() {
	SetConsoleOutputCP(CP_UTF8);	//utf-8が出なかったため無理やり解決
}

//@brief	=== 出力関数 ===
void judge::out_put(const char* c) {
	cout << c << endl;
}

//一応オーバーロード...多分使わない
void judge::out_put(const wchar_t* c) {
	wcout << c << endl;
}