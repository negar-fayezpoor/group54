# group54
project
// Negar fayezpoor


#include <iostream>
#include <string>
using namespace std;
enum OS { iOS, Android, windowsPhone };
enum RAM { r2GB, r4GB, r6GB, r8GB, r12GB, r16GB, r32GB, r64GB };
enum STORAGE{ s16GB, s32GB, s64GB, s128GB, s256GB, s512GB, s1TB, s2TB };
enum COLOR{white,gray,black};

struct MOBILE {
    string name;
    string company;
    OS os;
    RAM ram;
    STORAGE storage;
    COLOR color;
    float price;
    int Remain;
    int sold;



    void copy(MOBILE msrc);
    void add_phone(MOBILE m);
    void add_phone(string n, string c, int x);
    int search(string n, string c);
    void remove_phone(int index);
    void print_phones();
    void sort_by_price ();
    void sell_a_phone (string n,string c );
    void most_sold_item();
    void newMobile(MOBILE * m);
};
MOBILE* mobiles;
int quantity;
void MOBILE::copy(MOBILE msrc)
{
    name= msrc.name;
    company = msrc.company;
    os= msrc.os;
    ram= msrc.ram;
    storage= msrc.storage;
    price= msrc.price;
    Remain= msrc.Remain;
    sold= msrc.sold;
    color = msrc.color;
}
void MOBILE::add_phone(MOBILE m)
{
    MOBILE* mobilesNew = new MOBILE[quantity + 1];
    if (quantity > 0)
    {
        for (int i = 0; i < quantity; i++)
            mobilesNew[i].copy(mobiles[i]);
        delete[] mobiles;
        mobiles = mobilesNew;
        //delete[] mobilesNew;
        mobiles[quantity].copy(m);
    }
    else
        mobiles[0].copy(m);
    quantity++;
}
int MOBILE::search(string n, string c)
{
    for (int i = 0; i < quantity; i++)
        if (mobiles[i].company == c && mobiles[i].name == n)
            return i;
    return -1;
}
void MOBILE::add_phone(string n, string c, int x)
{
    int index = search(n, c);
    if (index == -1)
        cout << "\nmobile not exist...";
    else
        mobiles[index].Remain += x;
}

void MOBILE::remove_phone(int index)
{
    if (quantity > 1)
    {
        MOBILE* mobilesNew = new MOBILE[quantity - 1];
        for (int i = 0 ; i < quantity ; i++)
        {
            if (i > index)
                mobilesNew[i-1].copy(mobiles[i]);
            else if (i < index)
            mobilesNew[i].copy(mobiles[i]);
        }
        delete[] mobiles;
        mobiles = mobilesNew;
    }
    else
            delete[] mobiles;
        quantity--;
}

void MOBILE :: sort_by_price (){

    MOBILE temp;
    for (int i = 0 ; i < quantity - 1 ; i++) {
        for (int j = 0 ; j < quantity - 1 ; j++) {
            if (mobiles[j].price > mobiles[j+1].price){
                temp.copy(mobiles[j]);
            mobiles[j].copy(mobiles[j+1]);
            mobiles[j+1].copy(temp);

            }
        }
    }
}
void MOBILE :: sell_a_phone (string n,string c )
{

    int position = search (n,c);

    if (position==-1)
    {
        cout<<"doesnt exist.";
    }
    else
    {
        mobiles[position].Remain--;
        mobiles[position].sold ++;
        quantity --;
    }
}
void MOBILE::print_phones()
{
    for (int i = 0; i < quantity; i++)
    {
        cout << "\nmobile " << i + 1 << " : \n";
        cout << "\tname: " << mobiles[i].name << endl;
        cout << "\tcompany: " << mobiles[i].company << endl;
        cout << "\tos: ";
        switch (mobiles[i].os) {
        case 1:
            cout << "iOS";
            break;
        case 2:
            cout << "Android";
            break;
        case 3:
            cout << " windowsPhone";
            break;
        }
        cout<< endl;
        cout << "\tprice: " << mobiles[i].price << endl;
        cout << "\tram: ";
        switch (mobiles[i].ram) {
        case 1:
            cout << "2GB";
            break;
        case 2:
            cout << "4GB";
            break;
        case 3:
            cout << "6GB";
            break;
        case 4:
            cout << " 8GB";
            break;
        case 5:
            cout << "12GB";
            break;
        case 6:
            cout << "16GB";
            break;
        case 7:
            cout << "32GB";
            break;
        case 8:
            cout << "64GB";
            break;
        }
        cout << endl;
        cout << "\tstorage: ";
        switch (mobiles[i].storage) {
        case 1:
            cout << "16GB";
            break;
        case 2:
            cout << "32GB";
            break;
        case 3:
            cout << "64GB";
            break;
        case 4:
            cout << "128GB";
            break;
        case 5:
            cout << "256GB";
            break;
        case 6:
            cout << "512GB";
            break;
        case 7:
            cout << "1TB";
            break;
        case 8:
            cout << "2TB";
            break;
        }
        cout << endl;
        cout << "\tcolor: ";
        switch (mobiles[i].color) {
        case 1:
            cout << "white";
            break;
        case 2:
            cout << "gray";
            break;
        case 3:
            cout << "black";
            break;
        }
        cout << endl;
        cout << "\tRemain: " << mobiles[i].Remain << endl;
        cout << "\tsold: " << mobiles[i].sold << endl;

    }
    cout << endl;
}
void MOBILE::most_sold_item()
{
    int i, j;
    struct MOBILE temp;
    struct MOBILE* mobilesNew = new MOBILE[quantity];
    for (int i = 0; i < quantity; i++)
    {
        mobilesNew[i].copy(mobiles[i]);
    }

    for (i = 0; i < quantity - 1; i++)
        for (j = 0; j < quantity - i - 1; j++)
            if (mobilesNew[j].sold < mobilesNew[j + 1].sold)
            {
                temp.copy(mobilesNew[j]);
                mobilesNew[j].copy(mobilesNew[j + 1]);
                mobilesNew[j + 1].copy(temp);
            }
    for (int i = 0; i < quantity; i++)
    {
        cout << "\nmobile " << i + 1 << " : \n";
        cout << "\tname: " << mobilesNew[i].name << endl;
        cout << "\tcompany: " << mobilesNew[i].company << endl;
        cout << "\tos: ";
        switch (mobilesNew[i].os) {
        case 0:
            cout << "iOS";
            break;
        case 1:
            cout << "Android";
            break;
        case 2:
            cout << " windowsPhone";
            break;
        }
        cout << endl;
        cout << "\tprice: " << mobilesNew[i].price << endl;
        cout << "\tram: ";
        switch (mobilesNew[i].ram) {
        case 0:
            cout << "2GB";
            break;
        case 1:
            cout << "4GB";
            break;
        case 2:
            cout << "6GB";
            break;
        case 3:
            cout << " 8GB";
            break;
        case 4:
            cout << "12GB";
            break;
        case 5:
            cout << "16GB";
            break;
        case 6:
            cout << "32GB";
            break;
        case 7:
            cout << "64GB";
            break;
        }
        cout << endl;
        cout << "\tstorage: "; switch (mobilesNew[i].storage) {
        case 0:
            cout << "16GB";
            break;
        case 1:
            cout << "32GB";
            break;
        case 2:
            cout << "64GB";
            break;
        case 3:
            cout << "128GB";
            break;
        case 4:
            cout << "256GB";
            break;
        case 5:
            cout << "512GB";
            break;
        case 6:
            cout << "1TB";
            break;
        case 7:
            cout << "2TB";
            break;
        }
        cout << endl;
        cout << "\tcolor: ";
        switch (mobilesNew[i].color) {
        case 0:
            cout << "white";
            break;
        case 1:
            cout << "gray";
            break;
        case 2:
            cout << "black";
            break;
        }
        cout << endl;
        cout << "\tRemain: " << mobilesNew[i].Remain << endl;
        cout << "\tsold: " << mobilesNew[i].sold << endl;

    }
    cout << endl;
    delete[] mobilesNew;
}

void MOBILE::newMobile(MOBILE* NewItem){
        cout << "enter new name :";
        cin >> NewItem->name;
        cout << "enter new company :";
        cin >> NewItem->company;
        bool valid = true;
        int enumVal;

        do {
            cout << "\nenter new os :\n\t1.Android \n\t2.iOS \n\t3.windowsPhone\n\t4.return \n\tselect (1,2,3,4): ";
            cin >> enumVal;
            switch (enumVal)
            {
            case 1:
                NewItem->os = OS::Android;
                break;
            case 2:
                NewItem->os = OS::iOS;
                break;
            case 3:
                NewItem->os = OS::windowsPhone;
                break;
            case 4:
                valid = true;
                break;
            default:
                cout << "ivalid selection..";
                valid = false;
                break;
            }
        } while (valid != true);


        do {
            valid = true;
            cout << "\nenter new ram (\n\t1.r2GB, \n\t2.r4GB, \n\t3.r6GB, \n\t4.r8GB, \n\t5.r12GB, \n\t6.r16GB, \n\t7.r32GB, \n\t8.r64GB \n\t9.return:\n\tselect (1,2,..,9): ";
            cin >> enumVal;
            switch (enumVal)
            {
            case 1:
                NewItem->ram = RAM::r2GB;
                break;
            case 2:
                NewItem->ram = RAM::r4GB;
                break;
            case 3:
                NewItem->ram = RAM::r6GB;
                break;
            case 4:
                NewItem->ram = RAM::r8GB;
                break;
            case 5:
                NewItem->ram = RAM::r12GB;
                break;
            case 6:
                NewItem->ram = RAM::r16GB;
                break;
            case 7:
                NewItem->ram = RAM::r32GB;
                break;
            case 8:
                NewItem->ram = RAM::r64GB;
                break;
            case 9:
                valid = true;
                break;
            default:
                cout << "ivalid selection..";
                valid = false;
                break;
            }
        } while (valid != true);

        do {
            valid = true;
            cout << "\nenter new Storage (\n\t1.s16GB, \n\t2.s32GB, \n\t3.s64GB, \n\t4.s128GB, \n\t5.s256GB, \n\t6.s512GB, \n\t7.s1TB, \n\t8.s2TB \n\t9.return:\n\tselect (1,2,..,9): ";
            cin >> enumVal;
            switch (enumVal)
            {
            case 1:
                NewItem->storage = STORAGE::s16GB;
                break;
            case 2:
                NewItem->storage = STORAGE::s32GB;
                break;
            case 3:
                NewItem->storage = STORAGE::s64GB;
                break;
            case 4:
                NewItem->storage = STORAGE::s128GB;
                break;
            case 5:
                NewItem->storage = STORAGE::s256GB;
                break;
            case 6:
                NewItem->storage = STORAGE::s512GB;
                break;
            case 7:
                NewItem->storage = STORAGE::s1TB;
                break;
            case 8:
                NewItem->storage = STORAGE::s2TB;
                break;
            case 9:
                valid = true;
                break;
            default:
                cout << "ivalid selection..";
                valid = false;
                break;
            }
        } while (valid != true);
        cout << "enter new price :";
        cin >> NewItem->price;

        do {
            valid = true;
            cout << "\nenter new color :\n\t1.black \n\t2.gray \n\t3.white\n\t4.return \n\tselect (1,2,3,4): ";
            cin >> enumVal;
            switch (enumVal)
            {
            case 1:
                NewItem->color = COLOR::black;
                break;
            case 2:
                NewItem->color = COLOR::gray;
                break;
            case 3:
                NewItem->color = COLOR::white;
                break;
            case 4:
                valid = true;
                break;
            default:
                cout << "ivalid selection..";
                valid = false;
                break;
            }
        } while (valid != true);
        cout << "enter new remain :";
        cin >> NewItem->Remain;

        cout << "enter new sold :";
        cin >> NewItem->sold;
}


    int main()
    {
        mobiles = new MOBILE[1];
            quantity = 0;
            int select=0;
            do {
                    cout<<"\n\n1 - Add a phone\n";
                    cout << "2 - Remove a phone\n";
                    cout << "3 - Sort phones by price\n";
                    cout << "4 - Search a phone\n";
                    cout << "5 - Change mobile info\n";
                    cout << "6 - Sell a phone\n";
                    cout << "7 - Print phones\n";
                    cout << "8 - Print phones sorted by the most sold to the least\n";
                    cout << "9 - Quit\n";
                    cout << "enter your select: ";
                    cin >> select;
                    MOBILE m;
                    string n, c;
                    int index;
                    switch (select)
                    {
                    case 1:
                        mobiles->newMobile(&m);
                        mobiles->add_phone(m);
                        break;
                    case 2:
                        if (quantity == 0)
                            cout << "\nthere is no mobile in list..";
                        else {
                            do{
                            cout << "\nenter mobile index to remove (1 to" << quantity <<") :";
                            cin >> index;
                            }while(index - 1 < 0 || index - 1 > quantity);
                            mobiles->remove_phone(index - 1);
                            cout << "\nmobile in entered index is removed..";
                        }
                        break;
                    case 3:
                        if (quantity == 0)
                            cout << "\nthere is no mobile at list..";
                        else {
                            mobiles->sort_by_price();
                            cout << "\nmobile list sorted..";
                        }
                        break;
                    case 4:
                        if (quantity == 0)
                            cout << "\nthere is no mobile i list..";
                        else{
                            cout << "enter mobile name : ";
                            cin >> n;
                            cout <<"\n enter company name :";
                            cin >> c;
                            index=mobiles->search(n , c);
                            cout << "\nmobile found in index " << index;
                        }
                    case 6:
                        cout << "\nenter selled mobile name: ";
                        cin >> n;
                        cout << "\nenter selled mobile company: ";
                        cin >> c;
                        mobiles->sell_a_phone(n , c);
                        break;
                    case 7:
                        if (quantity == 0)
                            cout << "\nthere is no mobile i list..";
                        else
                            mobiles->print_phones();
                        break;
                    case 8:
                        if (quantity == 0)
                            cout << "\nthere is no mobile i list..";
                        else
                        mobiles->most_sold_item();
                    default:
                        cout << "\ninvalid selection..";
                        break;
                    }
            } while (select !=9 );
            return 0;
        }


