using System;
using System.Linq;
class HelloWorld
{
  static int Main(string[] args)
  {
    Console.WriteLine("Hello, {0}", args[0]);
    Console.WriteLine("Welcome to C#.");

    string test = RemoveSpaces("Tell      MMMEEE la ");

    return 0;
  }

  public static string RemoveSpaces(string str)
  {
    return new string(str.ToCharArray().Where(c => !Char.IsWhiteSpace(c)).ToArray());
  }
}