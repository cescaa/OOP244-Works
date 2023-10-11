#include "Item.h"
using namespace sdds;
int main()
{
   Item A; // object of Item class

   A.setEmpty(); // set object to empty state
   A.display();

   A.set("hot dog buns", 4.99, false);
   A.display();

   return 0;
}

/*
Output:
| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |
| Hot dog buns........ |    4.99 | No  |

*/