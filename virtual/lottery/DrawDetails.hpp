#ifndef _DRAW_DETAILS
#define _DRAW_DETAILS


struct DrawDetails{
  int64_t timestamp;
  std::vector<std::vector<uint8_t>> numbers;
  std::vector<std::vector<uint8_t>> extras;
  std::vector<std::string> lucky_string;
};

#endif
