#include "clock.hpp"

void set_time(std::string& time)
{
  std::time_t time_stamp  = std::time(nullptr);
  std::string time_string = std::asctime(std::localtime(&time_stamp));

  for(int i = 0; i < time_string.size(); i++)
  {
    if(time_string[i+2] == ':')
    {
      time.push_back(time_string[i]);
      time.push_back(time_string[i+1]);

      time.push_back(time_string[i+3]);
      time.push_back(time_string[i+4]);

      time.push_back(time_string[i+6]);
      time.push_back(time_string[i+7]);

      break;
    }
  }
}


int main()
{
  Clock my_clock;

  my_clock.run();

  /*
  winsize window_size;

  for(int i = 0; i < 3600; i++)
  {
    std::string time;
    set_time(time);

    // get window dimensions 
    ioctl(0, TIOCGWINSZ, &window_size);

    // set boundaries 
    std::string left;
    std::string top;

    for(int j = 0; j < (window_size.ws_row - 7) / 2; j++)
    {
      top   += "\n";
    }

    for(int j = 0; j < (window_size.ws_col - 41) / 2; j++)
    {
      left += " ";
    }

    std::system("clear");

    if(top.size() < 1 || left.size() < 5)
    {
      std::cout << "[!] uncapable to display window, limited space" << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      continue;
    }

    // display clock and wait 
    std::cout 
      << top
      << left 
      << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"
      << std::endl;

    for(int i = 0; i < 5; i++)
    {
      std::cout 
      << left 
      << "█ "
      << get_number(time[0], i) 
      << get_number(time[1], i) 
      << dot[i] 
      << get_number(time[2], i) 
      << get_number(time[3], i) 
      << dot[i] 
      << get_number(time[4], i) 
      << get_number(time[5], i) 
      << "█"
      << std::endl;
    }
    std::cout 
      << left
      << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"
      << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
  }*/
}
