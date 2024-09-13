#include "game/damath.h"

namespace DamathZero::Game {

Board::Board() {
  pieces_[5][2] = std::make_unique<Pawn>(Player::White, 0);
  pieces_[2][5] = std::make_unique<Pawn>(Player::Black, 0);

  pieces_[3][2] = std::make_unique<Dama>(Player::White, -1);
  pieces_[4][5] = std::make_unique<Dama>(Player::Black, -1);

  pieces_[7][2] = std::make_unique<Dama>(Player::White, 2);
  pieces_[0][5] = std::make_unique<Dama>(Player::Black, 2);

  pieces_[1][2] = std::make_unique<Pawn>(Player::White, -3);
  pieces_[6][5] = std::make_unique<Pawn>(Player::Black, -3);

  pieces_[4][1] = std::make_unique<Pawn>(Player::White, 4);
  pieces_[3][6] = std::make_unique<Pawn>(Player::Black, 4);

  pieces_[2][1] = std::make_unique<Dama>(Player::White, -5);
  pieces_[5][6] = std::make_unique<Dama>(Player::Black, -5);

  pieces_[6][1] = std::make_unique<Dama>(Player::White, 6);
  pieces_[1][6] = std::make_unique<Dama>(Player::Black, 6);

  pieces_[0][1] = std::make_unique<Pawn>(Player::White, -7);
  pieces_[7][6] = std::make_unique<Pawn>(Player::Black, -7);

  pieces_[5][0] = std::make_unique<Pawn>(Player::White, 8);
  pieces_[2][7] = std::make_unique<Pawn>(Player::Black, 8);

  pieces_[3][0] = std::make_unique<Pawn>(Player::White, -9);
  pieces_[4][7] = std::make_unique<Pawn>(Player::Black, -9);

  pieces_[7][0] = std::make_unique<Dama>(Player::White, 10);
  pieces_[0][7] = std::make_unique<Dama>(Player::Black, 10);

  pieces_[1][0] = std::make_unique<Dama>(Player::White, -11);
  pieces_[6][7] = std::make_unique<Dama>(Player::Black, -11);
}

Operator operators[8][8] = {
    {Operator::Multiply, Operator::None, Operator::Divide, Operator::None,
     Operator::None, Operator::None, Operator::Plus, Operator::None},
    {Operator::None, Operator::Divide, Operator::None, Operator::Multiply,
     Operator::None, Operator::Plus, Operator::None, Operator::None},
    {Operator::None, Operator::None, Operator::Plus, Operator::None,
     Operator::Multiply, Operator::None, Operator::Divide, Operator::None},
    {Operator::None, Operator::Plus, Operator::None, Operator::None,
     Operator::None, Operator::Multiply, Operator::None, Operator::Divide},
    {Operator::Multiply, Operator::None, Operator::Divide, Operator::None,
     Operator::None, Operator::None, Operator::Plus, Operator::None},
    {Operator::None, Operator::Divide, Operator::None, Operator::Multiply,
     Operator::None, Operator::Plus, Operator::None, Operator::None},
    {Operator::None, Operator::None, Operator::Plus, Operator::None,
     Operator::Multiply, Operator::None, Operator::Divide, Operator::None},
    {Operator::None, Operator::Plus, Operator::None, Operator::None,
     Operator::None, Operator::Multiply, Operator::None, Operator::Divide},
};

auto Board::GetOperator(int x, int y) -> Operator { return operators[x][y]; }

Damath::Damath() {}

}  // namespace DamathZero::Game
