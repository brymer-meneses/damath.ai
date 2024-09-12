#pragma once

#include <string>

namespace damath {

class Board {
  int board[4][8];
  int player;
  int action[8];

 public:
  Board() = default;
  Board(const std::string& state) { SetFromState(state); }

  auto SetFromState(const std::string& state) -> void;

  auto GetMirror() -> Board;
  auto GetNextState() -> Board;
  auto GetValidMoves() -> Board;

  auto HasGameEnded() -> bool;
};

}  // namespace damath