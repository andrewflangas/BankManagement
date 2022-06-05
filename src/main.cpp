#include "Hashtable.h"
#include "BST_Tree.h"
#include "admin.h"
#include "staff.h"
#include "customer.h"
#include "string.h"

void Boot()
{
    Hashtable h;
    BST_Tree t;
    h.Starthash();
    t.LoadServer();
}

int main()
{
   Boot();

   int condition = 0;

   while(condition != 4)
   {
       cout << "You want to login as:\t\t\t\t\t\t" << endl << endl;
       cout << "1-ADMIN" << endl;
       cout << "2-STAFF" << endl;
       cout << "3-CUSTOMER" << endl;
       cin >> condition;

       if(condition == 1)
       {
           Admin();
       }

       if(condition == 2)
       {
           Staff();
       }
       if(condition == 3)
       {
            Customer();
       }

       if(condition == 4)
       {
           condition = 4;
       }
   }

   system("pause");
   return 0;
}
