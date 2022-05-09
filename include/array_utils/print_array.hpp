#if !defined(ARRAY_UTILS)
#define ARRAY_UTILS

#include <iostream>
#include <vector>

//:: use the same file for template function(applied for all normal function, namespace members, class members, structure member)
//! otherwise linker errors

namespace array_utils {
template <typename T>
void PrintArray(T* arr, int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
}

template <typename T>
void PrintArray(T* arr, int size, char ending_char) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
    std::cout << ending_char;
}

void Hello();  //:: for other function can define in another file(applied for all normal function, namespace members, class members, structure member)
}  // namespace array_utils

template <typename T>
std::ostream& operator<<(std::ostream& p_cout, std::vector<T>& arr) {
    for (auto&& i : arr)
        p_cout << i << ' ';
    return p_cout;
}

#endif  // ARRAY_UTILS
