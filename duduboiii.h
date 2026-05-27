#ifndef DUDUBOIII_H
#define DUDUBOIII_H

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

vector<string> dir;
vector<vector<string>> files;
vector<vector<string>> history;

void shell(string cmd, string args)
{
    history.push_back({cmd, args});

    if (cmd == "--help" || cmd == "-h")
    {
        cout << "Commands:\n";

        cout << "version\n";
        cout << "echo\n";
        cout << "nano\n";
        cout << "cat\n";
        cout << "ls\n";
        cout << "cd\n";
        cout << "mkdir\n";
        cout << "rmdir\n";
        cout << "clear\n";
        cout << "history\n";
        cout << "<-----Few Intersting Commands : -----> \n";
        cout << "btop\n";
        cout << "fastfetch\n";
        cout << "cmatrix\n";
        cout << "ip\n";
        cout << "<-----             -----> \n";
        cout << "exit\n";
    }

    else if (cmd == "version")
    {
        cout << "DuduCLI v69.69\n";
    }

    else if (cmd == "echo")
    {
        cout << args << endl;
    }

    else if (cmd == "nano")
    {
        string content;

        cout << "Write content: ";

        getline(cin >> ws, content);

        files.push_back({args, content});

        cout << "File saved\n";
    }

    else if (cmd == "cat")
    {
        bool found = false;

        for (auto file : files)
        {
            if (file[0] == args)
            {
                cout << file[1] << endl;
                found = true;
            }
        }

        if (!found)
        {
            cout << "File not found\n";
        }
    }

    else if (cmd == "ls")
    {
        cout << "Directories:\n";

        for (const string &dirs : dir)
        {
            cout << dirs << endl;
        }

        cout << "\nFiles:\n";

        for (auto file : files)
        {
            cout << file[0] << endl;
        }
    }

    else if (cmd == "cd")
    {
        cout << "Changed directory to " << args << endl;
    }

    else if (cmd == "mkdir")
    {
        cout << "Directory created: " << args << endl;

        dir.push_back(args);
    }

    else if (cmd == "rmdir")
    {
        cout << "Directory removed: " << args << endl;

        dir.erase(remove(dir.begin(), dir.end(), args), dir.end());
    }

    else if (cmd == "clear")
    {
        system("clear"); // Linux
        // system("cls"); // Windows
    }

    else if (cmd == "History")
    {
        for (auto h : history)
        {
            cout << h[0];

            if (h[1] != "")
            {
                cout << " " << h[1];
            }

            cout << endl;
        }
    }

    else if (cmd == "exit")
    {
        cout << "Exiting...\n";
    }
else if(cmd == "btop")
{
    system("btop");
}

else if(cmd == "fastfetch")
{
    system("fastfetch");
}

else if(cmd == "cmatrix")
{
    system("cmatrix");
}

else if(cmd == "ip")
{
    system("ip a");
}
    else
    {
        cout << "Unknown command\n";
    }
}

#endif