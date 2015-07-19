#pragma once

#include <cpr.h>
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

  // I should look into using something like boost::variant,
  // since I only really care about using Multipart or Parameters.
  template<typename T>
  Response send(const std::string& path, const T& uriParams) const {
    const auto response = cpr::Post(
      Url{std::string(rootPath) + path},
      Authentication{user, pass},
      uriParams
    );
    return response;
  }
};

} // namespace neoc

