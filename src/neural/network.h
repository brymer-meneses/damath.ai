#pragma once

#include <torch/torch.h>

namespace DamathZero::Neural {

class Network : public torch::nn::Module {
  torch::nn::Linear fc1{784, 256};
  torch::nn::Linear fc2{256, 128};
  torch::nn::Linear fc3{128, 10};

 public:
  Network();

  auto forward(torch::Tensor x) -> torch::Tensor;
};

}  // namespace DamathZero::Neural