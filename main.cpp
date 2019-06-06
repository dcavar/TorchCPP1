/**
 * TorchCPP1 test
 *
 * This is an example testing environment.
 *
 * See README.md for more details.
 */


#include <torch/torch.h>
#include <iostream>


int main() {
    torch::Tensor tensor = torch::rand({2, 3});
    std::cout << tensor << std::endl;
}
