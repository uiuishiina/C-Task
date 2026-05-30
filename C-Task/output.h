#pragma once
#include<iostream>
#include<concepts>
#include<string>

template<typename T>
concept ToStringAble = requires(T a) {
	{ std::to_string(a) } -> std::convertible_to<std::string>;
};

class OutPut final
{
public:
	//--------------------------------------------------------------------------------------------------

	//@brief	=== 出力関数 ===
	template<typename T>
	static void output(const T& value) {

		//コンパイル時型check
		if constexpr (std::convertible_to<T, std::string>) {
			//文字列なら
			std::cout << static_cast<std::string>(value) << std::endl;
		}
		else if constexpr (std::same_as<T, char>) {
			//char型なら
			std::cout << value << std::endl;
		}
		else if constexpr(ToStringAble<T>){
			//文字列以外かつ文字列変換可能なら
			std::cout << std::to_string(value) << std::endl;
		}
		else {
			//それ以外ならコンパイルエラー
			static_assert(false, "output convertible Failed");
		}
	}

	//--------------------------------------------------------------------------------------------------
};