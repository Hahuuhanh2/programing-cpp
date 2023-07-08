#include<iostream>
#include<map>
#include<string>
#include<limits>

using namespace std;
int main()
{
    map<string, string>dictionary;
    string word, defination;

    char choice;

    do
    {
        cout << "Nhap tu: ";
        cin>> word;

        cout << "Nhap nghia cua tu: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, defination);

        dictionary[word] = defination;

        cout<< "Dou you want to countinute?Y/N";
        cin >> choice;


    }while(choice == 'y' || choice == 'Y');

    string searchword;
    cout << "Nhap tu muon tra: ";
    cin >> searchword;

   auto aito = dictionary.find(searchword);
   if(aito != dictionary.end())
   {
       cout<< "Tu " << searchword <<" Co nghia la:" << aito->second<< endl;
   }
   else
   {
       cout <<"Khong tim thay tu" << searchword << " trong tu dien."<< endl;
   }
    return 0;

}
