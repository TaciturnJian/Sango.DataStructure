#include <vector>
#include <string>

namespace Sango {
	class KMPSolution {
	private:
		int pattern_length;
		int* next;
		std::string pattern;
		void FindNext() {
			next[0] = 0;
			for (int i = 1, j = 0; i < pattern_length; i++) {
				while (j > 0 && pattern[i] != pattern[j]) {
					j = next[j - 1];
				}

				if (pattern[i] == pattern[j]) {
					j++;
				}

				next[i] = j;
			}
		}

	public:
		KMPSolution(std::string _pattern) {
			pattern = _pattern;
			pattern_length = pattern.length();
			next = new int[pattern_length] {0};

			FindNext();
		}

		~KMPSolution() {
			delete[] next;
		}

		int SearchFirst(std::string text) {
			// ����next�����Ѿ�����ó�����:
			// ���ʧ�䣬ֻ��Ҫ:	
			// while (text[i] != pattern[j] && j > 0)
			//		j = next[j - 1];		//��j�򷴷�����ת���Ǹ���Զ������
			// if (text[i] == pattern[j]) {
			//		j = 1;					//�����Ż�һ�£���jֱ����ת��j = 1
			// }
			// 
			// //��ʼ�µ�ƥ��(ע���ʱj�������תλ��)
			// pattern : ABAB
			// next    : 0012
			// text    :     ABCBABD
			//				 ^ ^		//ʧ��
			//               i j
			//                ^^		//��ת
			//                ij
			// ���ƥ�䣬ֻ��Ҫ:
			// j++;							//j������ǰ�ƶ�
			// if (j == pattern.length())
			//		return i - j + 1;		//�ж��Ƿ�Ƚ���ɣ������ֱ�ӷ��ؼ���

			int text_length = text.length();
			for (int i = 0, j = 0; i < text_length; i++) {
				while (j > 0 && text[i] != pattern[j]) {
					j = next[j];
				}

				if (text[i] == pattern[j]) {
					j++;
				}

				if (j == pattern_length) {
					return i - j + 1;
				}
			}

			return -1;
		}
	};
	
	class BruteForce {
	private:
		std::string pattern;
		int pattern_length;
		const char *patternP;

	public:
		BruteForce(std::string _pattern) {
			pattern = _pattern;
			pattern_length = pattern.length();
			patternP = pattern.c_str();
		}

		int SearchFirst(std::string text) {
			const char *textP = text.c_str();
			
			int i = 0;
			while (*(textP + i)) {
				int j = 0;
				while (j < pattern_length && *(patternP + j) == *(textP + i + j)) {
					j++;
				}

				if (j == pattern_length) {
					return i;
				}
				i++;
			}

			return -1;
		}

	};
}