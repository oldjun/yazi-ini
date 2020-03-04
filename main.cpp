#include <iostream>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <fstream>
#include <sstream>
using namespace std;

#include "IniFile.h"
using namespace yazi::utility;

int main()
{
    // loading a ini file by construct function
    const string & filename = "./main.ini";
    IniFile ini(filename);

    // loading a ini file by calling the load function
    const string & filename2 = "./main.ini";
    IniFile ini2;
    ini2.load(filename2);

    // showing the ini file content
    ini.show();

    // dumping the ini file to another file
    ini.save("./main2.ini");

    // get config option by array access
    const string & name = ini["profile"]["name"];
    std::cout << "in section profile name is " << name << std::endl;

    // get config option by call get method
    int age = ini.get("profile", "age");
    std::cout << "in section profile age is " << age << std::endl;

    // set config option by array access
    ini["profile"]["age"] = 31;

    // set config option by call set method
    ini.set("profile", "age", 32);

    age = ini["profile"]["age"];
    std::cout << "in section profile change age to " << age << std::endl;

    // if the server section is exist
    if (ini.has("server"))
    {
        std::cout << "the server section is exist" << std::endl;
    }

    // if the server section and ip key is exist
    if (ini.has("server", "ip"))
    {
        std::cout << "the server section and ip key is exist" << std::endl;
    }

    // remove the key ip in server section
    ini.remove("server", "ip");

    // remove the sever section
    ini.remove("server");

    // clear the ini file
    ini.clear();

    return 0;
}
