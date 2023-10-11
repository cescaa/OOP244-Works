
#include "LibApp.h"
// #include "Menu.h"

namespace sdds
{
  LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
  {
    // Populate the main menu's title
    m_mainMenu << "Add New Publication"
               << "Remove Publication"
               << "Checkout publication from library"
               << "Return publication to library";

    m_exitMenu << "Save changes and exit"
               << "Cancel and go back to the main menu";

    load();
  }

  // Instantiate a Menu in this function and initialize it with the message argument.
  bool LibApp::confirm(const char *message)
  {
    bool result = false;

    // constructor argument list
    Menu menuObj(message);
    menuObj << "Yes";

    if (menuObj.run() == 1)
    {
      result = true;
    };
    return result;
  }

  void LibApp::load()
  {
    cout << "Loading Data" << endl;
  }

  void LibApp::save()
  {
    cout << "Saving Data" << endl;
  }

  void LibApp::search()
  {
    // cout << endl;

    cout << "Searching for publication" << endl;
  }

  void LibApp::returnPub()
  {
    search();
    cout << "Returning publication" << endl;
    cout << "Publication returned" << endl
         << endl;
    m_changed = true;
  }

  void LibApp::newPublication()
  {
    cout << "Adding new publication to library" << endl;

    if (confirm("Add this publication to library?") == true)
    {
      m_changed = true;
      cout << "Publication added" << endl;
    };

    cout << endl;
  }

  void LibApp::removePublication()
  {
    cout << "Removing publication from library" << endl;
    search();

    if (confirm("Remove this publication from the library?") == true)
    {
      m_changed = true;
      cout << "Publication removed" << endl;
    };

    cout << endl;
  }

  void LibApp::checkOutPub()
  {
    search();

    if (confirm("Check out publication?") == true)
    {
      m_changed = true;
      cout << "Publication checked out" << endl;
    };
    cout << endl;
  }

  void LibApp::run()
  {

    int flag = 0;
    int outerFlag = 0;

    int exitAns;       // Changes have been made to the data
    int userInput = 0; // seneca library app
    int confirmAns = 0;

    while (outerFlag == 0)
    {
      while (flag == 0)
      {
        userInput = m_mainMenu.run();
        if (userInput == 1)
        {
          newPublication();
          /*
                  if (m_changed == true)
                  {
                    flag = 1;
                  }
                  */
        }
        else if (userInput == 2)
        {
          removePublication();
        }
        else if (userInput == 3)
        {
          checkOutPub();
        }
        else if (userInput == 4)
        {
          returnPub();
        }
        else if (userInput == 0)
        {

          flag = 1;
        }
      };

      if (m_changed == true)
      {
        exitAns = m_exitMenu.run();

        if (exitAns == 1)
        {
          save();
          outerFlag = 1; // ***
        }
        else if (exitAns == 2)
        {
          // go back to main menu (first loop)
          flag = 0;

          cout << endl;
        }
        else if (exitAns == 0)
        {
          confirmAns = confirm("This will discard all the changes are you sure?");
          if (confirmAns == 1)
          {
            outerFlag = 1;
          }
        }
      }
      else
      {
        outerFlag = 1;
      }
    }

    cout << endl
         << "-------------------------------------------" << endl;
    cout << "Thanks for using Seneca Library Application" << endl;
  }

}

// display title:  cout << m_mainMenu << " YOOO!" << endl;

/*
- displays the main menu
- based on the user's selection, calls the corresponding private method
- repeats the above until the user chooses to exit.

When the user selects exit: If the m_changed is false, the program terminates. If true, the m_exitMenu is used by calling its run method.

Doing so the user has the selection:
- If first, the save() method is called and the program terminates.
- If second, program goes back to the main menu and continues.
- If the exit, then the confirm menu will be called using the message: "This will discard all the changes are you sure?".
    - If the user selects Yes, the program terminates.
    - Otherwise, the program goes back to the main menu

When the program is terminated, print message:
*/

/*
if (confirm("This will discard all the changes are you sure?") == false)
      {
        save();
      }; // ADD CONDITION
*/