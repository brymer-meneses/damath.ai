#pragma once

#include <memory>

namespace DamathZero::Game {

enum class Player { White, Black };
enum class Operator { Plus, Minus, Multiply, Divide, None };

class Piece {
  Player owner_;
  int value_ = 0;

 public:
  Piece(Player owner, int value = 0) : owner_(owner), value_(value) {}

  auto owner() -> Player* { return &owner_; }
  auto value() -> int* { return &value_; }
};

class Pawn : public Piece {
 public:
  Pawn(Player owner, int value = 0) : Piece(owner, value) {}
};

class Dama : public Piece {
 public:
  Dama(Player owner, int value = 0) : Piece(owner, value) {}
};

class Board {
  std::unique_ptr<Piece> pieces_[8][8];
  Player currentPlayer_ = Player::White;

 public:
  Board();

  auto GetOperator(int x, int y) -> Operator;

  auto pieces() -> std::unique_ptr<Piece> (*)[8][8] { return &pieces_; }
  auto currentPlayer() -> Player* { return &currentPlayer_; }
};

class Damath {
  Board board_;

 public:
  Damath();

  auto board() -> Board* { return &board_; }
};

}  // namespace DamathZero::Game