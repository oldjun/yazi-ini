# yazi-ini
a tiny c++ inifile parser，provides a C++ interface for parsing (reading) and dumping (writing) .ini files.

|Author|junping|
|---|---|
|E-mail|oldjun@sina.com|
|Wechat|chenjunping1024|

## Definition of Initialization file
```ini
[server]
ip = 127.0.0.1
port = 80

[profile]
name = junping
phone = 189****5599
sex = man
age = 30
height = 1.70
```

## Load & dump a ini file
```c++
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
    
    return 0;
}
```

## Get & Set configuration option

```c++
#include "IniFile.h"
using namespace yazi::utility;

int main()
{
    // loading a ini file by construct function
    const string & filename = "./main.ini";
    IniFile ini(filename);

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
    
    return 0;
}
```

## Modify section & key

```c++
#include "IniFile.h"
using namespace yazi::utility;

int main()
{
    // loading a ini file by construct function
    const string & filename = "./main.ini";
    IniFile ini(filename);
    
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
```

## Compile & Run the project
download the source code, cd into the yazi-ini project working directory, run command make && ./main 
```bash
cd ./yazi-ini
make
./main
```
## Testing
file main.ini used to test the ini file parse function. 
