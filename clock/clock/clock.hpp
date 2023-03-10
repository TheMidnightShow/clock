#include <sys/ioctl.h>
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <ctime>
#include <map>

#ifndef CLOCK
#define CLOCK

static const std::string_view zero  [5] = { "▄▄▄▄▄ ", "█   █ ", "█ ▄▀█ ", "█▀  █ ", "▀▀▀▀▀ ", };
static const std::string_view one   [5] = { "▄▄▄   ", "  █   ", "  █   ", "  █   ", "▀▀▀▀▀ ", };
static const std::string_view two   [5] = { "▄▄▄▄▄ ", "    █ ", "█▀▀▀▀ ", "█     ", "▀▀▀▀▀ ", };
static const std::string_view three [5] = { "▄▄▄▄▄ ", "    █ ", "▀▀▀▀█ ", "    █ ", "▀▀▀▀▀ ", };
static const std::string_view four  [5] = { "▄   ▄ ", "█   █ ", "▀▀▀▀█ ", "    █ ", "    ▀ ", };
static const std::string_view five  [5] = { "▄▄▄▄▄ ", "█     ", "▀▀▀▀█ ", "    █ ", "▀▀▀▀▀ ", };
static const std::string_view six   [5] = { "▄▄▄▄▄ ", "█     ", "█▀▀▀█ ", "█   █ ", "▀▀▀▀▀ ", };
static const std::string_view seven [5] = { "▄▄▄▄▄ ", "    █ ", "    █ ", "    █ ", "    ▀ ", };
static const std::string_view eight [5] = { "▄▄▄▄▄ ", "█   █ ", "█▀▀▀█ ", "█   █ ", "▀▀▀▀▀ ", };
static const std::string_view nine  [5] = { "▄▄▄▄▄ ", "█   █ ", "▀▀▀▀█ ", "    █ ", "▀▀▀▀▀ ", };
static const std::string_view dot   [5] = { "   ", "██ ", "   ", "██ ", "   ", };

class Clock
{
  public:
    Clock();
   ~Clock();
    void run();

  private:
    std::string time_stamp;
    std::string row;
    std::string col;

    void              update_time();
    void              update_center();
    void              print_oversize() const;
    std::string_view  find_bigger(const char& input, const int& indic) const;
};

#endif
