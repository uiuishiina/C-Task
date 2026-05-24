#include"input.h"
#include<iostream>
#include<random>
#include<limits> 

using namespace std;

//---------------------------------------------------------------------------------------------------

//@brief	=== ランダム値取得ベース関数 ===
//@param    value   範囲
template<typename T>
[[nodiscard]] static T pick_Random_value(const T& value) {

    //ランダム初期化
    static std::random_device rd;
    static std::mt19937 gen(rd());

    //軽く調べた限りこの二つでしかできなさそうだった
    if constexpr (std::is_integral_v<T>) {  //int型
        std::uniform_int_distribution<T> dist(0, value);
        return dist(gen);
    }
    else if constexpr (std::is_floating_point_v<T>) {   //float型 or double型
        std::uniform_real_distribution<T> dist(0, value);
        return dist(gen);
    }
}

//配列内の要素用...今回いらないがアイデアとして思い浮かんだため
template<typename T>
[[nodiscard]] static T pick_Random_value(std::vector<T>& vec) {

    //ランダム初期化
    static std::random_device rd;
    static std::mt19937 gen(rd());

    if constexpr (std::is_integral_v<T>) {
        std::uniform_int_distribution<T> dist(0, vec.size());
        return vec[dist(gen)];
    }
}

//---------------------------------------------------------------------------------------------------

//@brief	=== 入力取得ベース関数 ===
//	オーバーロードで取得したい値を変えれるようにしてみたくなったため、明示的な特殊化で対応してみることにする
template<typename T>
[[nodiscard]] static T get_input() {

    //変数初期化
    T value{};
    while (true) {

        if (cin >> value) {
            return value;
        }

        // EOF検出
        if (cin.eof()) {    //ここら辺をどう対応しようか悩んだため、おとなしく調べることにした
            throw std::runtime_error("入力終了");
        }

        // エラー回復処理
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

//---------------------------------------------------------------------------------------------------

//@brief	=== ランダム整数値取得関数 ===
[[nodiscard]] int input::pick_Random_int_value(int length) {
    return  pick_Random_value<int>(length);
}

//配列用
[[nodiscard]] int input::pick_Random_int_value(std::vector<int>& vec) {
    return pick_Random_value<int>(vec);
}

//---------------------------------------------------------------------------------------------------

//int
[[nodiscard]] int input::input_int() {
    return get_input<int>();
}

//bool
[[nodiscard]] bool input::input_bool() {
    return get_input<bool>();
}