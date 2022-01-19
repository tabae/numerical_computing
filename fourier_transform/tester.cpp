#include <cassert>
#include "dft.hpp"
#include "idft.hpp"

using namespace std;

int main() {
    assert(dft_test());
    assert(idft_test());
}