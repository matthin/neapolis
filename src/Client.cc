#include "Client.h"
#include <utility>

namespace nea {

constexpr char Client::rootPath[];

Client::Client(const std::string& user, const std::string pass)
    : user(std::move(user)), pass(std::move(pass)) {
}

Response Client::upload(
  const std::vector<std::pair<std::string, std::string>>& files
) {
  Multipart uriParams{};
  for (const auto& file : files) {
    uriParams.parts.push_back({file.first, File{file.second}});
  }
  return send("upload", uriParams);
}

Response Client::remove(const std::string& name) {
  return send("delete", Multipart{{"filenames[]", name}});
}

Response Client::info() {
  return send("info", Parameters{{"sitename", user}});
}

Response Client::info(const std::string& user) {
  return send("info", Parameters{{"sitename", user}});
}

} // namespace nea

