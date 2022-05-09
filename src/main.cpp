#include <array_utils/print_array.hpp>
#include <config/glfw_glad_template_config.hpp>
#include <iostream>
#include <string>
#include <vector>

std::string GetExecutableName(char const* path) {
    std::string executable_name(path);
    executable_name = executable_name.substr(executable_name.find_last_of('\\') + 1);
    return executable_name;
}

int main(int argc, char const* argv[]) {
    if (argc <= 1)  // argc <= 1 means there are no command line arguments, 1 default argument is LOCATION to exe
    {
        std::cout << GetExecutableName(argv[0]) << " VERSION-" << PROJECT_VERSION_MAJOR << '.' << PROJECT_VERSION_MINOR << '\n';
    }

    int t1[] = {1, 2, 3, 4, 5};
    char t2[] = {'1', '2', '3', '4', '5'};
    std::string t3[] = {"this", "is", "echo", "31"};
    float t4[] = {1.23, 2.23, 3.23, 4.23, 5.23};
    double t5[] = {1.23, 2.23, 3.23, 4.23, 5.23};

    array_utils::PrintArray(t1, 5, '\n');
    array_utils::PrintArray(t2, 5, '\n');
    array_utils::PrintArray(t3, 4, '\n');
    array_utils::PrintArray(t4, 5, '\n');
    array_utils::PrintArray(t5, 5, '\n');

    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << vec << '\n';

    array_utils::Hello();
    return 0;
}