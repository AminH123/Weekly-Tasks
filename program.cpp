    #include "splashkit.h"
    #include <string>
    #include <iostream>
    #include <cstdlib>

    //this is where the console Colors are defined

    #define CONSOLE_ORANGE "\x1b[36m"
    #define CONSOLE_GREEN "\x1b[35m"
    #define CONSOLE_WHITE "\x1b[37m"
    #define CONSOLE_BOLD "\x1b[1m"
    #define CONSOLE_RESET "\x1b[0m"

    using namespace std;


    void nice_display(string message) //This function Prints the Message which is placed decorative border. 
    {
        write_line("\n\n");
        write_line("************************************************************");
        write_line("\t\t" + message + "\t\t");
        write_line("************************************************************");
    }

    void swap_by_pointer(string *z, string *names_p)//This Swaps the two string values through pointer. 
    {
        write_line("\nInside swap_by_pointer");
        write_line("---------------------------");
        write_line("Parameters that was passed by pointer: \ts = " + *z + ",\tname = " + *names_p);

        string temp = *z;
        *z = *names_p;
        *names_p= temp;

        write_line("Values after swap: \t\ts = " + *z + ",\tname = " + *names_p);
    }

    void swap_by_value(string s, string name)//Same as the function above however, this swaps through pass by value
    {
        write_line("\nInside swap_by_value");
        write_line("---------------------------");
        write_line("Parameters passed by value: \ts =  " + s + ",\tname =  " + name);

        string temp = s;
        s = name;
        name = temp;

        write_line("Values after swap: \t\ts =  " + s + ",\tname =  " + name);
    }

    void pointer_information() //This function Shows the pointer Information
    {
        double d = 7.99, *x;
        string s = "SIT102", *z;
        string name;
        cout << "Please enter your name:  ";
        cin >> name;
        string *name_ptr; 
        name_ptr = &name;

        x = &d;
        z = &s;

        //this is Part A 
        write_line(CONSOLE_ORANGE);
        nice_display("Part A: Ordinary Variables");
        write_line("Ordinary Variables\t\t --->  d = " + to_string(d) + ",\ts = " + s);
        write_line("Memory Addresses\t\t --->  &d = " + to_string((int64_t)d) + ",\t &s = " + to_string((int64_t)&s));

        //This is Part B 
        write_line(CONSOLE_GREEN);
        nice_display("Part B: Pointer Variables");
        write_line("Pointer Variables\t\t --->  x =  " + to_string((int64_t)x) + ",\tz =  " + to_string((int64_t)z));
        write_line("Memory Addresses\t\t --->  &d =  " + to_string((int64_t)&x) + ",\t&s =  " + to_string((int64_t)&z));
        write_line(CONSOLE_RESET);

        nice_display("Part C: Pass by Value vs. Pass by Pointer");

        write_line(CONSOLE_WHITE);
        write_line("\nPass by Value");
        swap_by_value(s, name);
        write_line("\nBack in pointer_information()");
        write_line("---------------------------");
        write_line("After swap call in pointer_information(): \ts = " + s + ",\tname = " + name);
        write_line(CONSOLE_RESET);

        write_line(CONSOLE_GREEN);
        write_line("\nPass by Pointer");
        swap_by_pointer(z, name_ptr);
        write_line("\nBack in pointer_information()");
        write_line("---------------------------");
        write_line("After swap call in pointer_information(): \ts = " + *z + ",\tname = " + *name_ptr);
        write_line(CONSOLE_RESET);
    }

    int main()
    {
        write_line("Let's explore pointers for data manipulation!");
        pointer_information();

        return 0;
    }

