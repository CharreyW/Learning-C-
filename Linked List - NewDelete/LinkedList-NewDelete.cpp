#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>
//#include <string>

using namespace std;
//using text_t = string;   typedef replacement
//getline(cin, name)       to include space character
//getline(cin>>ws, name)   ws=widespace/space
//#include <cmath>         math function
//array.empty()
//string.append (@gmail.com) 
//const = constant value   (pi=3.14)
//array[] = {x, "xxx", etc};
//sizeof()                 size in bytes
//for(data type : variable_name)  foreach loop array
//& = adress (ex: cout<<&name)
//recrusive function=more clean, more memory and cpu aka slower (used for search algorithm)
//template <typename T>    function template (same function, different data type)
//function template example> T fName(T datatype);
/*auto biggerNum(T x, U y)    can have 2 datatype parameter
auto=return automatic data type> maxNum(1, 2.1)
will return bigger value double 2.1*/
//enum {"Monday"=1, "Tuesday=2", etc} for switch()  
//(struct Node*)malloc(sizeof(struct Node));

struct Node{
   string name;
   struct Node *next=nullptr, *child=nullptr;
   //struct Node *previous;
};

void insertFamily();
void insertChild();
void showList();
void deleteFamily();
void deleteChild();
int checkFamily(string fName);
int checkChild (string fName, string cName);

Node *fHead = nullptr;
Node *fTail = nullptr;

int main() 
{
   int menu;

   do{
      cout << "\n=====FAMILY REGISTRATION=====\n";
      cout << "1. Insert Family\n";
      cout << "2. Insert Child\n";
      cout << "3. Delete Family\n";
      cout << "4. Delete Child\n";
      cout << "5. Show Family and Child\n";
      cout << "6. EXIT\n";
      cout << "Enter Menu: ";
      cin >> menu;

      switch(menu)
      {
         case 1: insertFamily();
                  //if u want to make "insert at/before/after"
                  //1st make input for at/before/after "parent name" 
                  //then make input for the "inserted name"
                  //then just search the name using while()
                  //using pointer Node *previous could make it easier
            break;
         case 2: insertChild();
            break;
         case 3: deleteFamily();
            break;
         case 4: deleteChild();
            break;
         case 5: showList();
            break;
         case 6: cout << "***Thank you for using our service!***\n";
            break;
         default: cout << "***Please enter only 1-6***\n";
            break;
      }
      cin.get();
   }while (menu!=6 || menu<1 || menu>6);

   return 0;
}

void insertFamily()
{
   string fName;

   cout << "Insert Family name: ";
   cin >> fName;

   if(fHead==nullptr)
   {
      fHead = new Node;
      fHead->name=fName;
      fTail=fHead;
   }
   else
   {
      Node *temp = fHead;
      while(temp->next!=nullptr)
      {
         temp=temp->next;
      }
      temp->next=new Node;
      temp->next->name=fName;
      fTail=temp->next;
   }
   cout << "Family successfully inserted!\n";
}

void insertChild()
{
   if(fHead==nullptr)
   {
      cout<<"Family is empty!\n";
   }
   else
   {
      string fName, cName;
      Node *tempf=fHead, *tempc;

      do{
         cout << "Insert Family name: ";
         cin >> fName;
         if(checkFamily(fName)==0)
         {
            cout << "Family not found!\n";
         }
      }while(checkFamily(fName)==0);

      cout << "Insert Child name: ";
      cin >> cName;

      while(tempf->name!=fName)
      {
         tempf=tempf->next;
      }

      if(tempf->child==nullptr)
      {
         tempf->child=new Node;
         tempf->child->name=cName;
      }
      else
      {
         tempc=tempf->child;
         while(tempc->next!=nullptr)
         {
            tempc=tempc->next;
         }
         tempc->next=new Node;
         tempc->next->name=cName;
      }
      cout << "Child successfully inserted!\n";
   }
}

void deleteFamily()
{
   string fName;

   if(fHead==nullptr)
   {
      cout << "\nList empty!\n";
   }
   else
   {
      Node *temp = fHead, *temp2, *temp3;
      do{
         cout << "Insert Family name: ";
         cin >> fName;
         if(checkFamily(fName)==0)
         {
            cout << "Family not found!\n";
         }
      }while(checkFamily(fName)==0);

      if(temp->name==fName)
      {
         fHead=temp->next;
         if(temp->child!=nullptr)
         {
            temp2=temp->child;
            while(temp2!=nullptr)
            {
               temp3=temp2;
               temp2=temp2->next;
               delete(temp3);
            }
         }
         delete(temp);
         temp=nullptr;
      }
      else
      {
         while(temp->next->name!=fName&&temp->next->next!=nullptr)
         {
            temp=temp->next;
         }
         temp2=temp->next;
         temp->next=temp->next->next;
         delete(temp2);
      }
      cout << "Family successfully deleted!\n";    
   }
}

void deleteChild()
{
   if(fHead==nullptr)
   {
      cout << "\nList empty!\n";
   }
   else
   {
      string fName, cName;
      Node *tempf=fHead, *tempc, *temp;
      do{
         cout << "Insert Family name: ";
         cin >> fName;
         if(checkFamily(fName)==0)
         {
            cout << "Family not found!\n";
         }
      }while(checkFamily(fName)==0);

      do{
         cout << "Insert Child name: ";
         cin >> cName;
         if(checkChild(fName, cName)==0)
         {
            cout << "Child not found!\n";
         }
      }while(checkChild(fName, cName)==0);

      while(tempf->name!=fName)
      {
         tempf=tempf->next;
      }
    
      if(tempf->child->name==cName)
      {
         delete(tempf->child);
         tempf->child=nullptr;
      }
      else
      {         
         tempc=tempf->child;
         while(tempc->next->name!=cName&&tempc->next->next!=nullptr)
         {
            tempc=tempc->next;
         }
         temp=tempc->next;
         tempc->next=tempc->next->next;
         delete(temp);
      }
      cout << "Child successfully deleted!\n";
   }
}

void showList()
{
   if(fHead==nullptr)
   {
      cout << "\nList empty!\n";
   }
   else
   {
      Node *tempf = fHead, *tempc;
      cout << "===FAMILY LIST===\n";
      while(tempf!=nullptr)
      {
         cout << "Family: " << tempf->name;
         if(tempf->child!=nullptr)
         {
            tempc=tempf->child;
            cout << " | Child: ";
            while(tempc!=nullptr)
            {
               cout << tempc->name;
               if (tempc->next!=nullptr)
               {
                  cout<<", ";
               }
               tempc=tempc->next;
            }
         }
         cout << '\n';
         tempf=tempf->next;
      }
   }
}

int checkFamily (string fName)
{
   Node *temp=fHead;
   while(temp->name!=fName&&temp->next!=nullptr)
   {
      temp=temp->next;
   }

   if(temp->name==fName)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int checkChild (string fName, string cName)
{
   Node *temp=fHead, *tempc;

   while(temp->name!=fName&&temp->next!=nullptr)
   {
      temp=temp->next;
   }

   tempc=temp->child;
   while(tempc->name!=cName&&tempc->next!=nullptr)
   {
      tempc=tempc->next;
   }

   if(tempc->name==cName)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}