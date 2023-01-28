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

	// seed�l�̌���
	// https://cpprefjp.github.io/reference/random.html
	std::random_device seed_gen;
	std::mt19937 engine(seed_gen());
	std::uniform_real_distribution<> dist1(MinRange, MaxRange);

	// �ۑ�0��
	// float�^�ŗv�f��10�̔z����쐬�A�S�ĂO�ŏ���������B
	VecType	issueArray[10] = { 0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f };

	// �ۑ�1��
	// �ۑ�0�ԂŎg���Ă���z���vector�R���e�ivec1�ɕύX�A0~1.0�͈̗̔͂����ŏ���������B�Ȃ��A�������͒ʏ�ǂ���Y������p�������[�v�����ōs�����ƁB
	std::vector<VecType> vec1(std::begin(issueArray), std::end(issueArray));
	const auto vec1Size = sizeof(issueArray) / sizeof(VecType);
	for (int i = 0; i < vec1Size; ++i) {
		vec1[i] = dist1(engine);

		// ��s�ɓZ�߂�Ȃ�
		// std::uniform_real_distribution<>(MinRange, MaxRange)(engine)
	}

	// �ȉ��͈�for�ŏ���������ꍇ
	/*
	for (const auto& i : issueArray) {
		dist1 = std::uniform_real_distribution<>(MinRange, MaxRange);
		vec1.emplace_back(dist1(engine));
	}
	*/

	VecElemChack("Debug:vec1�̗v�f", vec1);

	// �ۑ�2��
	// ���ɃT�C�Y���O��vector�R���e�ivec2��ʓr�p�ӂ��A�ۑ�1�Ԃ̃R���e�i�N���X��S�ăR�s�[����B
	std::vector<VecType> vec2;
	vec2 = vec1;

	// �ۑ�3��
	// ����vec2�̃��T�C�Y���s���A�v�f����15�Ɋg�傷��
	vec2.resize(15);
	VecElemChack("vec2�̗v�f", vec2);

	// �ۑ�4��
	// vec2�̒��g�����ɑS�ĕ\������B�ۑ�1�ԓ��l�Y������p����for���ōs���B
	// �\��
	std::cout << "================================================================" << std::endl;
	std::cout << "�ȉ�vec2�̗v�f�ꗗ" << std::endl;
	const int vec2Size = vec2.size();
	for (int i = 0; i < vec2Size; ++i) {
		std::cout << "�v�f�ԍ�:" << i << " �v�f:" << vec2[i] << std::endl;
	}
	std::cout << "================================================================" << std::endl;

	// �ۑ�5��
	// �C�e���[�^��p�������[�v�������쐬��vec1��S�ĉ�ʂɕ\��
	// �\��
	std::cout << "================================================================" << std::endl;
	std::cout << "�ȉ�vec1�̗v�f�ꗗ" << std::endl;
	for (auto itr = vec1.begin(); itr != vec1.end(); itr++) {
		std::cout << *itr << std::endl;
	}
	std::cout << "================================================================" << std::endl;

	// �ۑ�6��
	// �͈̓x�[�Xfor��p���āAvec2��S�ĉ�ʂɕ\������
	std::cout << "================================================================" << std::endl;
	std::cout << "�ȉ�vec2�̗v�f�ꗗ" << std::endl;
	for (auto itr : vec2) {
		std::cout << itr << std::endl;
	}
	std::cout << "================================================================" << std::endl;

	// * ================================================================
	// * 
	// * �ȉ��ǉ��v�f
	// * 
	// * ================================================================

	// 0 �ȉ��̗v�f���폜����
	const int preEraceSize = vec1.size();
	std::cout << "vec1��0.5�ȉ��̗v�f���폜���܂�" << std::endl;
	for (auto itr = vec1.begin(); itr < vec1.end();) {
		if (*itr < 0.5f) {
			itr = vec1.erase(itr);
		} else {
			itr++;
		}
	}

	std::cout << "vec1��0.5�ȉ��̗v�f��" << preEraceSize - vec1.size() << "�폜���܂���" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "�ȉ�vec1�̗v�f�ꗗ" << std::endl;
	for (auto itr : vec1) {
		std::cout << itr << std::endl;
	}
	std::cout << "================================================================" << std::endl;

	/*
	std::cout << "vec1�̗v�f" << std::endl;
	for (auto itr : vec1) {
		std::cout << itr << std::endl;
	}
	vec2.emplace_back(1.0f);


	*/
	// 

	return 0;
}
