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

void showElements(vector<int> vec);
void showElementsR(vector<int> vec);

int main() 
{
   int menu, value, index, times;
   vector<int> v, v2;

   do{
      cout<<"\n=====MAIN MENU=====\n";
      cout<<"1. Push Back Vector\n";
      cout<<"2. Insert Vector\n";
      cout<<"3. Asssign Vector\n";
      cout<<"4. Pop Back Vector\n";
      cout<<"5. Erase Vector\n";
      cout<<"6. Clear Vector\n";
      cout<<"7. Swap Vector\n";
      cout<<"8. Emplace Vector\n";
      cout<<"9. Show Vector\n";
      cout<<"0. EXIT\n";
      do{
         cout<<"Enter Menu: ";
         cin>>menu;
         if(menu<0||menu>9)
            cout<<"Enter only 1-9\n";
      }while(menu<0||menu>9);
   
      switch(menu)
      {
         case 1: cout<<"Enter value: ";
                 cin>>value;
                 v.push_back(value);
            break;
         case 2: cout<<"Enter value: ";
                 cin>>value;
                 cout<<"Enter index: ";
                 cin>>index;
                 v.insert(v.begin()+index, value);
            break;
         case 3: cout<<"Enter value: ";
                 cin>>value;
                 cout<<"Enter times: ";
                 cin>>times;
                 v.assign(times, value);
            break;
         case 4: v.pop_back();
                 cout<<"Hasil pop back: ";
                 showElements(v);
            break;
         case 5: cout<<"Enter index: ";
                 cin>>index;
                 v.erase(v.begin()+index);
            break;
         case 6: v.clear();
                  cout<<"Hasil clear: ";
                  showElements(v);
            break;
         case 7: v.swap(v2);
                 cout<<"v2 elements: ";
                 showElements(v2);                 
            break;
         case 8: cout<<"Enter value: ";
                 cin>>value;
                 cout<<"Enter index: ";
                 cin>>index;
                 v.emplace(v.begin()+index, value);
            break;
         case 9: if(v.empty()==true)
               {
                  cout<<"Vector is empty!!!\n";
               }
               else
               {
                  cout<<"Elements: ";
                  showElements(v);
                  cout<<"First element: "<<v.front();
                  cout<<"\nLast element: "<<v.back();
                  cout<<"\nReverse elements: ";
                  showElementsR(v);
                  cout<<"Size: "<<v.size();
                  cout<<"\nCapacity: "<<v.capacity();
                  cout<<"\n***Shrink to fit"; 
                  v.shrink_to_fit();
                  cout<<"\nSize: "<<v.size();
                  cout<<"\nCapacity: "<<v.capacity();
               }
            break;
         case 0: cout<<"\nThank you!\n";
            break;
         default:
            break;
      }
   }while(menu!=0);

   //cin.get();
   return 0;
}  

void showElements(vector<int> vec)
{
   for(int i=0; i<vec.size(); i++)
   {
      cout<<vec[i]<<" ";
   }
   cout<<'\n';
}

void showElementsR(vector<int> vec)
{
   for(auto i=vec.rbegin(); i!=vec.rend(); i++)
   {
      cout<<*i<<" ";
   }
   cout<<'\n';
}