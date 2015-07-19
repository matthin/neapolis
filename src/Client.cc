#include "Client.h"
#include <cpr.h>
#include <utility>
#include <iostream>

namespace nea {

constexpr char Client::rootPath[];

Client::Client(const std::string& user, const std::string pass)
    : user(std::move(user)), pass(std::move(pass)) {
}

bool Client::upload(const std::string& name, const std::string& location) {
  const auto response = send("upload", Multipart{{name, File{location}}});
  return response.status_code == 200;
}

bool Client::remove(const std::string& name) {
  const auto response = send("delete", Multipart{{"filenames[]", name}});
  return response.status_code == 200;
}

std::string Client::info() {
  const auto response = send("info", Parameters{{"sitename", user}});
  return response.text;
}

std::string Client::info(const std::string& user) {
  const auto response = send("info", Parameters{{"sitename", user}});
  return response.text;
}

} // namespace nea

