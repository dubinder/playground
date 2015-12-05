#include <string>
#include <iostream>
#include <Array.h>

void removeSpaces(char *inString)
{
  char *start;
  char *space;
  start = space = inString;
  int len = strlen(inString);

  // Find first space
  while (*start != ' ')
  {
    ++start;
  }
  space = start;

  for (int i = 0; i < len; ++i)
  {

    if (*start != ' ')
    {
      *space = *start;
      ++space;
    }
    ++start;
  }
  *start = 0;
}

int main(int argc, char* argv[])
{
  char test[256] = { "A string with spaces" };
  char test2[256] = { "A  string  with  more           spaces" };
  Array<int> temp(10);

  std::cout << temp.GetLength();
  
  std::cout << strlen(test);
  removeSpaces(test);
  std::cout << strlen(test);
  removeSpaces(test2);

  return 0;
}