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
}
