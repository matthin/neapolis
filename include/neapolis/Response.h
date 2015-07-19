#pragma once

#include <string>

namespace nea {

class Response {
public:
  Response(const short code, const std::string& text)
      : code(code), text(std::move(text)), successful(detectSuccess(code)) {}

  const short code;
  const std::string text;
  const bool successful;

private:
  bool detectSuccess(const short code) {
    // Neocity only returns 200 on success. It's kind of dumb, but whatever.
    return code == 200;
  }
};

} // namespace nea

