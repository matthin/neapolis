#include "Client.h"
#include <iostream>

int main(int argc, char* argv[]) {
  nea::Client client(argv[1], argv[2]);
  std::cout << client.upload("indexx.html", "../src/main.cc").successful;
  std::cout << client.info().successful << std::endl;
  std::cout << client.remove("indexx.html").successful;
  return 0;
}

