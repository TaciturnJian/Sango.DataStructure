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
			// 假设next数组已经计算得出，即:
			// 如果失配，只需要:	
			// while (text[i] != pattern[j] && j > 0)
			//		j = next[j - 1];		//让j向反方向跳转到那个最远的坐标
			// if (text[i] == pattern[j]) {
			//		j = 1;					//可以优化一下，让j直接跳转到j = 1
			// }
			// 
			// //开始新的匹配(注意此时j是最佳跳转位置)
			// pattern : ABAB
			// next    : 0012
			// text    :     ABCBABD
			//				 ^ ^		//失配
			//               i j
			//                ^^		//跳转
			//                ij
			// 如果匹配，只需要:
			// j++;							//j继续向前移动
			// if (j == pattern.length())
			//		return i - j + 1;		//判断是否比较完成，完成则直接返回即可

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