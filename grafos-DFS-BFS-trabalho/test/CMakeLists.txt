cmake_minimum_required(VERSION 3.8)
set(This testGrafoListaAdj)
set(Sources
testGrafoListaAdj.cpp
)
add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
  gtest_main
  Grafolistaadjexercicio
)
add_test(
NAME ${This}
COMMAND ${This}
)