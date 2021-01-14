#include "exectutor.h"

int main() {
    Executor e("jdfjd");

    auto x = e.clone_repository("https://github.com/AleksMVPdfd/decenf.git");

    std::cout << x.get_description() << std::endl;
    std::cout << x.get_status_code() << std::endl;
}