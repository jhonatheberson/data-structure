cmake_minimum_required(VERSION 3.8)
set(This testGrafoMatrizAdj)
set(Sources
testGrafoMatrizAdj.cpp
)
add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
  gtest_main
  grafomatadjexercicio
)
add_test(
NAME ${This}
COMMAND ${This}
)