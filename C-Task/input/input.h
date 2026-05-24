#pragma once
#include<vector>
#include<concepts>

class input final
{
public:
//---------------------------------------------------------------------------------------------------

	//=====  ランダム抽選  =====

	//@brief	=== ランダム整数値取得関数 ===
	//@param	length	範囲
	//@param	vec	ランダムで出したい配列
	[[nodiscard]] static int pick_Random_int_value(int length);
	[[nodiscard]] static int pick_Random_int_value(std::vector<int>& vec);

//---------------------------------------------------------------------------------------------------

	//=====  数値⼊⼒  =====

	//@brief	=== 入力取得関数 ===
	//@return	入力された値
	[[nodiscard]] static int input_int();
	[[nodiscard]] static bool input_bool();

//---------------------------------------------------------------------------------------------------
};