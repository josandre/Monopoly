cmake_minimum_required(VERSION 3.23)
project(Monopoly)

set(CMAKE_CXX_STANDARD 14)

add_executable(Monopoly main.cpp  Core/Node.cpp Core/Node.h Models/Property.cpp Models/Property.h Models/Enums/SpotType.h Models/Spot.cpp Models/Spot.h Models/Enums/SpecialCardAction.h Models/SpecialCard.cpp Models/SpecialCard.h Models/Tax.cpp Models/Tax.h Models/Jail.cpp Models/Jail.h Models/Free.cpp Models/Free.h)
