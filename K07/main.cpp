#include <vector>
#include <random>
#include <iostream>
#include <string>

#ifdef _DEBUG
template <class T>
void debugChack(const std::string& str, std::vector<T>& vec) {
	std::cout << "================================================================" << std::endl;
	std::cout << "Debug:" << str << std::endl;
	for (auto itr : vec) {
		std::cout << "Debug: elem->" << itr << std::endl;
	}
	std::cout << "================================================================" << std::endl;
}

# define VecElemChack(str, vec) debugChack(str, vec)

#else
# define VecElemChack(str, vec)
#endif // _DEBUG



int main(void) {
	using VecType = float;

	const VecType MinRange = 0.0f;
	const VecType MaxRange = 1.0f;

	// seed値の決定
	// https://cpprefjp.github.io/reference/random.html
	std::random_device seed_gen;
	std::mt19937 engine(seed_gen());
	std::uniform_real_distribution<> dist1(MinRange, MaxRange);

	// 課題0番
	// float型で要素数10個の配列を作成、全て０で初期化する。
	VecType	issueArray[10] = { 0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f };

	// 課題1番
	// 課題0番で使っている配列をvectorコンテナvec1に変更、0~1.0の範囲の乱数で初期化する。なお、初期化は通常どおり添え字を用いたループ処理で行うこと。
	std::vector<VecType> vec1(std::begin(issueArray), std::end(issueArray));
	const auto vec1Size = sizeof(issueArray) / sizeof(VecType);
	for (int i = 0; i < vec1Size; ++i) {
		vec1[i] = dist1(engine);

		// 一行に纏めるなら
		// std::uniform_real_distribution<>(MinRange, MaxRange)(engine)
	}

	// 以下範囲forで初期化する場合
	/*
	for (const auto& i : issueArray) {
		dist1 = std::uniform_real_distribution<>(MinRange, MaxRange);
		vec1.emplace_back(dist1(engine));
	}
	*/

	VecElemChack("Debug:vec1の要素", vec1);

	// 課題2番
	// 次にサイズが０のvectorコンテナvec2を別途用意し、課題1番のコンテナクラスを全てコピーする。
	std::vector<VecType> vec2;
	vec2 = vec1;

	// 課題3番
	// 次にvec2のリサイズを行い、要素数を15個に拡大する
	vec2.resize(15);
	VecElemChack("vec2の要素", vec2);

	// 課題4番
	// vec2の中身を順に全て表示する。課題1番同様添え字を用いたfor文で行う。
	// 表示
	std::cout << "================================================================" << std::endl;
	std::cout << "以下vec2の要素一覧" << std::endl;
	const int vec2Size = vec2.size();
	for (int i = 0; i < vec2Size; ++i) {
		std::cout << "要素番号:" << i << " 要素:" << vec2[i] << std::endl;
	}
	std::cout << "================================================================" << std::endl;

	// 課題5番
	// イテレータを用いたループ処理を作成しvec1を全て画面に表示
	// 表示
	std::cout << "================================================================" << std::endl;
	std::cout << "以下vec1の要素一覧" << std::endl;
	for (auto itr = vec1.begin(); itr != vec1.end(); itr++) {
		std::cout << *itr << std::endl;
	}
	std::cout << "================================================================" << std::endl;

	// 課題6番
	// 範囲ベースforを用いて、vec2を全て画面に表示する
	std::cout << "================================================================" << std::endl;
	std::cout << "以下vec2の要素一覧" << std::endl;
	for (auto itr : vec2) {
		std::cout << itr << std::endl;
	}
	std::cout << "================================================================" << std::endl;

	// * ================================================================
	// * 
	// * 以下追加要素
	// * 
	// * ================================================================

	// 0 以下の要素を削除する
	const int preEraceSize = vec1.size();
	std::cout << "vec1の0.5以下の要素を削除します" << std::endl;
	for (auto itr = vec1.begin(); itr < vec1.end();) {
		if (*itr < 0.5f) {
			itr = vec1.erase(itr);
		} else {
			itr++;
		}
	}

	std::cout << "vec1の0.5以下の要素を" << preEraceSize - vec1.size() << "個削除しました" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "以下vec1の要素一覧" << std::endl;
	for (auto itr : vec1) {
		std::cout << itr << std::endl;
	}
	std::cout << "================================================================" << std::endl;

	/*
	std::cout << "vec1の要素" << std::endl;
	for (auto itr : vec1) {
		std::cout << itr << std::endl;
	}
	vec2.emplace_back(1.0f);


	*/
	// 

	return 0;
}
