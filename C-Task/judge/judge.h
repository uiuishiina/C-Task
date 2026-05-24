#pragma once
#include<concepts>
#include<compare>

//@brief	=== 比較結果識別子 ===
enum class Comparison {
	Big,Equals,Small
};

class judge final
{
public:
	//---------------------------------------------------------------------------------------------------
	
	//@brief	=== 初期化関数 ===
	static void Initialize();

	//---------------------------------------------------------------------------------------------------
	
	//=====  ⽐較  =====

	//@brief	=== 比較関数 ===
	//@return	比較結果
	template<std::totally_ordered T>
	static [[nodiscard]] Comparison comparison(const T& standard,const T& target) {
		if (standard == target) {
			return Comparison::Equals;
		}
		return standard < target ? Comparison::Big : Comparison::Small;
	}

	//---------------------------------------------------------------------------------------------------

	//=====  結果表⽰  =====

	//@brief	=== 出力関数 ===
	static void out_put(const char* c);
	static void out_put(const wchar_t* c);
};