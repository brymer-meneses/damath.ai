#include "neural/network.h"

namespace DamathZero::Neural {

Network::Network() { register_module("fc1", fc1); register_module("fc2", fc2); register_module("fc3", fc3); }

auto Network::forward(torch::Tensor x) -> torch::Tensor {
  x = torch::relu(fc1->forward(x));
  x = torch::dropout(x, 0.5, is_training());
  x = torch::relu(fc2->forward(x));
  x = torch::log_softmax(fc3->forward(x), 1);
  return x;
}

}  // namespace DamathZero::Neural