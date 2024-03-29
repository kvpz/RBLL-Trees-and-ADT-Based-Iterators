/*
    ranstring.cpp
    02/23/14
    Chris Lacher

    creates random <string, int> data for testing of tables

    Copyright 2014, R.C. Lacher
*/

#include <fstream>

#include <xstring.cpp>
#include <xran.cpp>
#include <xranxstr.cpp>

int main(int argc, char* argv[])
{
  if (argc != 5)
  {
    std::cout << " ** program requires 4 arguments\n"
	      << "    1 = number of generated entries\n"
	      << "    2 = min length of string\n"
	      << "    3 = max length of string\n"
	      << "    4 = output filename\n"
	      << " ** try again\n";
    exit(0);
  }

  std::cout << "Program generating file string entries, one per line.\n"
	    << " strings have length in [" << argv[2] << ',' << argv[3] << "]\n"
	    << " ...\n";

  std::ofstream out1;
  out1.open(argv[4]);
  if (out1.fail())
  {
    std::cout << " ** Unable to open file " << argv[4] << '\n'
	      << " ** program closing\n";
    exit(0);
  }

  fsu::Random_String ranString;
  fsu::Random_int ranint;
  size_t num = atoi(argv[1]), min = atoi(argv[2]), max = atoi(argv[3]) + 1, len;
  for (size_t i = 0; i < num; ++i)
  {
    len = ranint(min, max);
    out1 << ranString(len) << '\n';
  }

  // close outfile
  out1.close();

  // terminate program
  std::cout << "File of strings constructed:\n"
	    << " filename:        " << argv[4] << '\n'
	    << " number of strings: " << num << '\n'
	    << " string lengths:  [" << min << ',' << max - 1 << "]\n";

  return 0;
}
