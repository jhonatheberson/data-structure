cmake_minimum_required(VERSION 3.8)
set(This testTabelaHash)
set(Sources
testTabelaHash.cpp
)
add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
  gtest_main
  Hashexercicio
)
add_test(
NAME ${This}
COMMAND ${This}
)