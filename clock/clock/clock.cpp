#include "clock.hpp"

Clock::~Clock() {};

Clock::Clock() 
  : row(""), col(""), time_stamp("")
{}

void Clock::run()
{
  bool should_run = true;
  auto display = [&, this]() 
  {
    while(should_run)
    {
      std::system("clear");
      update_time();
      update_center();

      print_oversize();

      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  };

  std::jthread program_display(display);

  std::cin.get();
  should_run = false;
}

void Clock::update_time()
{
  time_stamp.clear();

  std::time_t       current_time_stamp  = std::time(nullptr);
  std::string_view  current_time_string = std::asctime(std::localtime(&current_time_stamp));
  
  uint32_t scope = 0;
  for(const auto& item : current_time_string)
  {
    if((int)item >= 48 && (int)item <= 57)
    {
      if(scope > 6) break;
      if(scope > 0)
      {
        time_stamp.push_back(item);
      }

      scope++;
    }
  }
}

void Clock::update_center()
{
  row.clear();
  col.clear();

  winsize window_size;
  ioctl(0, TIOCGWINSZ, &window_size);

  const uint32_t row_offset = (window_size.ws_row/2) - 2; 
  const uint32_t col_offset = (window_size.ws_col/2) - 18; 

  for(uint32_t i = 0; i < row_offset; i++)
  {
    row.push_back('\n'); 
  }

  for(uint32_t i = 0; i < col_offset; i++)
  {
    col.push_back(' '); 
  }
}

void Clock::print_oversize() const
{
  uint32_t scope = 0;

  std::cout << row;
  for(uint32_t i = 0; i < 6; i++)
  { 
    std::cout << col;
    for(const auto& item : time_stamp)
    {
      std::cout << find_bigger(item, i);

      if(scope % 2 && (scope != 5 && scope != 11 && scope != 17 && scope != 23 && scope != 29))
        std::cout << find_bigger(':', i);
      scope++;
    }

    std::cout << std::endl;
    std::cout.flush();
  }
}

std::string_view Clock::find_bigger(const char& input, const int& indice) const
{
  switch(input) 
  {
    case '0': 
      return zero[indice];
      break;
    case '1': 
      return one[indice];
      break;
    case '2': 
      return two[indice];
      break;
    case '3': 
      return three[indice];
      break;
    case '4': 
      return four[indice];
      break;
    case '5': 
      return five[indice];
      break;
    case '6': 
      return six[indice];
      break;
    case '7': 
      return seven[indice];
      break;
    case '8': 
      return eight[indice];
      break;
    case '9': 
      return nine[indice];
      break;
    case ':': 
      return dot[indice];
      break;
  };

  return "";
}

