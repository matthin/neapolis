#include "Client.h"
#include <iostream>

int main(int argc, char* argv[]) {
  neoc::Client client(argv[1], argv[2]);
  std::cout << client.upload("indexx.html", "../src/main.cc");
  std::cout << client.info() << std::endl;;
  std::cout << client.remove("indexx.html");
  return 0;
}

