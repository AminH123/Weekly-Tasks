    #include "splashkit.h"   
    #include <string>
    #include <vector>
    using  std::vector;
    using namespace std;

    struct knight_data
    {
        string name;
        int age;
        string Month; 
        int Year; 
        vector<string> tools; //This has been added for the tools array
    };

    struct kingdom_data
    {
        string name; 
        vector<knight_data>knights;
    };


    string read_string(string prompt)
    {
        string Results;
        write (prompt);
        Results = read_line();
        return Results;
    }

    int read_integer(string prompt)
    {
        write(prompt);
        return convert_to_integer(read_line());
    }
    knight_data read_knight()
    {
    knight_data result;

        result.name = read_string("Enter Your Name: " );
        result.age = read_integer("Enter Your Age: " ); 
        return result;
    }

    void write_knight(const knight_data &knight)
    {
    write_line(knight.name + " Aged  " + to_string(knight.age));
    if (!knight.tools.empty())
    {
        write_line("Tools for this Knight"); 
        for (const string &tool : knight.tools)
        {
            write_line("-->" + tool);
        }
    }
    }
    enum knight_update_option
    {
        UPDATE_NAME,
        UPDATE_AGE,
        UPDATE_MONTH,
        UPDATE_YEAR,
        ADD_TOOL,
        DELETE_TOOL,
        FINISH_UPDATE,
    };

    knight_update_option read_knight_update_option()
    {
        int result; 
        
            write_line("1:  Update name"); 
            write_line("2:  Update Age");
            write_line("3:  Update Month");
            write_line("4   Update Year of Birth");
            write_line("5:  Add a Tool");
            write_line("5:  finish Update");
            result = read_integer("Please Select Option:  ");
            return static_cast<knight_update_option>(result - 1);
    }

    void update_knight(knight_data &knight)
    {
        knight_update_option option; 
        
        do 
        {
            write_line();
            write_line("** Update Knight **"); 
            write_knight(knight);
            write_line();
            option = read_knight_update_option();

            switch (option)
            {
            case UPDATE_NAME: 
                knight.name = read_string("Enter New name: ");
                break;
            case UPDATE_AGE:
                knight.age = read_integer("Enter New Age: "); 
                break; 
            case UPDATE_MONTH:
                knight.Month = read_string("Enter New  Month: ");
                break;
            case UPDATE_YEAR:
                knight.Year = read_integer("Enter you new Year Of Birth: ");
                break;
            case ADD_TOOL:
            {
                string tool = read_string("Enter the name of the new tool: ");
                knight.tools.push_back(tool);

            }
            case DELETE_TOOL:
                if (!knight.tools.empty())
                {
                    write_line("Your Tools:");
                    for (int i = 0; i < knight.tools.size(); i++)
                    {
                        write_line(to_string(i + 1) + "--> " + knight.tools[i]);
                    }
                        int toolIndex = read_integer("Please Select from the option above which tool you want to delete ");
                    if (toolIndex >= 1 && toolIndex <= knight.tools.size())
                    {
                        knight.tools.erase(knight.tools.begin() + toolIndex - 1);
                        write_line("Tool deleted.");
                    }
                    else
                    {
                        write_line("Invalid Option try Again.");
                    }
                }
                else
                {
                    write_line("404: No tool is found in record.");
                }
                break;
            case FINISH_UPDATE: 
                break;
            default:
            write_line("Please Select a valid Option");
                break;
            }
        } while (option != FINISH_UPDATE); 
    }

    void add_knight(kingdom_data &kingdom)
    {
    knight_data new_knight;
    new_knight = read_knight(); 
    kingdom.knights.push_back(new_knight);
    }

    void write_kingdom(const kingdom_data &kingdom)
    {
    write_line("=====================");
    write_line(kingdom.name);
    write_line("====Knights list=====");
    for (int i=0; i < kingdom.knights.size(); i++)
    {
        write_knight(kingdom.knights[i]);
    }
    write_line("======================");
    }

    void delete_knight(kingdom_data &kingdom, int index)
    {
    if (index >= 0 and index < kingdom.knights.size() )
    {
        int last_idx;
        last_idx = kingdom.knights.size() - 1; 
        kingdom.knights[index] = kingdom.knights[last_idx];
        kingdom.knights.pop_back();
    }
    }

    kingdom_data read_kingdom()
    {
        kingdom_data result;
        result.name = read_string("Please Enter Kingdom's name: ");
        return result; 
    }
    int select_knight(const kingdom_data &kingdom)
    {
        int index;
        do 
        {
            write_line("Select a knight:");
            for (int i = 0; i < kingdom.knights.size(); i++)
            {
                write_line(to_string(i + 1) + "--> " + kingdom.knights[i].name);
            }
                index = read_integer("Please once of the knights above: ");
        } while (index < 1 || index > kingdom.knights.size());

        return index - 1;
        }
    // this creates a menu for the users to be able to update and edit knight details
    void update_kingdom(kingdom_data &kingdom)
    {
        int option; 

        do
        {
            write_line("=======Menu======"); 
            write_line("1. Add a Knight"); 
            write_line("2. Inquire about a Knight"); 
            write_line("3. Update a Knight");
            write_line("4. Delete a Knight");
            write_line("5. Display Kingdom Details");
            write_line("6. Exit");
            
            option =  read_integer("Please Select from the Options above: ");
            switch (option)
            {
            case 1:
                add_knight(kingdom);
                write_line("");
                write_line("......Please Wait........");
                write_line("");
                write_line("============");
                write_line("");
                write_line("Knight added");
                write_line("");
                break;
            case 2:
                if (!kingdom.knights.empty())
                {
                    int index = select_knight(kingdom);
                    write_knight(kingdom.knights[index]);
                }
                else
                {
                    write_line("No knights was found in the kingdom.");
                }
                break;
                case 3:
                if (!kingdom.knights.empty())
                {
                    int index = select_knight(kingdom);
                    update_knight(kingdom.knights[index]);
                }
                else
                {
                    write_line("No knights was found in the kingdom.");
                }
                break;
            case 4:
                if (!kingdom.knights.empty())
                {
                    int index = select_knight(kingdom);
                    delete_knight(kingdom, index);
                }
                else
                {
                    write_line("No knights was found in the kingdom.");
                }
                break;
            case 5:
                if (!kingdom.knights.empty())
                {
                    write_kingdom(kingdom);
                }
                else
                {
                    write_line("No knights was found in the kingdom.");
                }
                break;
            case 6:
                write_line("........Exiting the program.......");
                write_line("........Bye for now...............");
                break;
            default:
                write_line("Invalid choice. Please select a valid option.");
                break;
            }
        } while (option != 6);
                
    }
    int main()
    {
        kingdom_data my_kingdom = read_kingdom();
        int num; 
        num = read_integer("How many knights would you like to add to this Kingdom: ");
        for (int i= 0; i< num; i++ )
        {
        add_knight(my_kingdom);
        }

        write_kingdom(my_kingdom);
        update_kingdom(my_kingdom);
    }