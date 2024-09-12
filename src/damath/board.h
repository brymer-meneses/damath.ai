#pragma once

#include <string>

namespace damath {

class Board {
 public:
  Board() = default;
  Board(const std::string& state) { SetFromState(state); }

  auto SetFromState(const std::string& state) -> void;

  auto Mirror() -> void;

  auto GetNextState() -> Board;
  auto GetValidMoves() -> Board;

  auto HasGameEnded() -> bool;

 private:
  int board[4][8];
  int player;
  int action[8];
};

}  // namespace damath