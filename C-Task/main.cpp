#include<iostream>
#include"input/input.h"
#include"judge/judge.h"

class Game {
public:
	//---------------------------------------------------------------------------------------------------

	//コンストラクタ
	Game() {
		judge::Initialize();
	}

	//---------------------------------------------------------------------------------------------------

	//@brief	=== ゲーム開始関数 ===
	void game_entry(int length = 10) {
		while (true) {

			//ループ開始
			game_loop(length);
			judge::out_put("おめでとうございます\n");

			//継続判定
			judge::out_put("まだ続けられますか？");
			judge::out_put("続けられるなら '1' を、終了するなら '0' を押してください");

			//falseなら終了
			if (!input::input_bool()) {
				break;
			}
		}
		judge::out_put("\nゲーム終了");
	}

	//---------------------------------------------------------------------------------------------------
private:
	//---------------------------------------------------------------------------------------------------

	//@brief	=== ゲームループ関数 ===
	void game_loop(int length) {

		auto random = input::pick_Random_int_value(length);

		while (true)
		{
			judge::out_put("整数値を入力してください");
			auto input_value = input::input_int();
			switch (judge::comparison(random, input_value))
			{
			case Comparison::Equals:
				judge::out_put("目標の値が見つかりました");
				return;
			case Comparison::Big:
				judge::out_put("目標の値より大きいようです");
				break;
			case Comparison::Small:
				judge::out_put("目標の値より小さいようです");
				break;
			}
		}
	}

	//---------------------------------------------------------------------------------------------------
};

int main() {
	Game game;
	game.game_entry(101);

	return 0;
}