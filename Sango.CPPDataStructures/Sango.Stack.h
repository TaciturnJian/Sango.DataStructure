#pragma once

#include <vector>

namespace Sango {
	template <class T>
	class Stack {
		typedef T ElementType, *ElementPointer;
	private:
		std::vector<ElementType> elements;
		//ָ������һ��Ԫ�ص��ϲ�
		int top;
		int max_size;

	public:
		void PushIn(ElementType element) {
			if (top >= max_size) {
				throw std::exception();
			}

			elements.push_back(element);
			top++;
		}

		ElementType PopOut() {
			if (top <= 0) {
				throw std::exception();
			}

			top--;
			return elements.pop_back();
		}
	};
}
