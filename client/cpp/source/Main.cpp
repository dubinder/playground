#include <string>
#include <iostream>
#include <Array.h>
#include <fstream>

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

struct Vector3
{
  float m_x;
  float m_y;
  float m_z;
  static const Vector3 GRAVITY;
  static const Vector3 ORIGIN;
  static const Vector3 X;
  static const Vector3 Y;
  static const Vector3 Z;

  float operator()(const int index)
  {
    return (&m_x)[index];
  }
  
  friend std::istream& operator>>(std::istream& input, Vector3& lhs)
  {
    input >> lhs.m_x
      >> lhs.m_y
      >> lhs.m_z;
    return input;
  }
};

std::string ToHexString(const char* hex)
{
  std::string tmp;
  const char *hexAlpha = "0123456789ABCDF";
  for (int i = 0; i < strlen(hex); ++i)
  {
    //tmp.append(hexAlpha[hex[i] >> 4]);
    tmp += (*hexAlpha + (hex[i] >> 4));
    tmp += (*hexAlpha + (hex[i] & 0xF));
  }
  return tmp;
}

int main(int argc, char* argv[])
{
  std::ifstream inFile;
  inFile.open("test.txt", std::ios_base::in);
  char test[256] = { "A string with spaces" };
  char test2[256] = { "A  string  with  more           spaces" };
  Array<int> temp(10);
  const char *byte = "THISISTRYHARD";
  ToHexString(byte);
  Vector3 vec;
  inFile >> vec;
  vec.m_x = 1;
  std::cout << vec(0);
  std::cout << temp.GetLength();
  
  std::cout << strlen(test);
  removeSpaces(test);
  std::cout << strlen(test);
  removeSpaces(test2);

  return 0;
}