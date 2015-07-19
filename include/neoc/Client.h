#pragma once

#include <string>

namespace neoc {

class Client {
public:
  Client(const std::string& user, const std::string pass);

  bool upload(const std::string& name, const std::string& location);
  bool remove(const std::string& name);
  std::string info();
  std::string info(const std::string& user);

private:
  static constexpr char rootPath[] = "https://neocities.org/api/";

  const std::string user;
  const std::string pass;
};

} // namespace neoc

