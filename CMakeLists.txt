cmake_minimum_required(VERSION 3.23)
project(ChessProject3)

set(CMAKE_CXX_STANDARD 23)

add_executable(ChessProject3 main.cpp Color.h Piece.h Piece.cpp Field.h Field.cpp Bishop.h Bishop.cpp Queen.h Queen.cpp Horse.h Horse.cpp Castle.h Castle.cpp King.h King.cpp Empty.h Empty.cpp Board.h Board.cpp Game.h Game.cpp Pawn.h Pawn.cpp)
