#pragma once

#include <cpr.h>
#include <string>
#include "Response.h"

namespace nea {

class Client {
public:
  Client(const std::string& user, const std::string pass);

  Response upload(const std::string& name, const std::string& location);
  Response remove(const std::string& name);
  Response info();
  Response info(const std::string& user);

private:
  static constexpr char rootPath[] = "https://neocities.org/api/";

  const std::string user;
  const std::string pass;

  // I should look into using something like boost::variant,
  // since I only really care about using Multipart or Parameters.
  template<typename T>
  Response send(const std::string& path, const T& uriParams) {
    const auto rawResponse = cpr::Post(
      Url{std::string(rootPath) + path},
      Authentication{user, pass},
      uriParams
    );
    return Response(rawResponse.status_code, rawResponse.text);
  }
};

} // namespace nea

