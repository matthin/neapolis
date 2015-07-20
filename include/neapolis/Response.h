#pragma once

#include <string>

namespace nea {

class Response {
public:
  Response(const short code, const std::string& text)
      : code(code), text(std::move(text)) {}

  const short code;
  const std::string text;

  bool successful() {
    // Neocity only returns 200 on success. It's kind of dumb, but whatever.
    return code == 200;
  }
};

} // namespace nea

