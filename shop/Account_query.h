#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

class account_query
{
private:
    char member_code[20];
    char firstName[10];
    char lastName[10];
    char phone_no[8];
    float total_Balance;
public:
    void read_data();
    void show_data();
    void write_rec();
    void read_rec();
    void search_rec();
    void edit_rec();
    void delete_rec();
};
void account_query::read_data()
{
    cout<<"\nEnter Membership Code: ";
    cin>>member_code;
    cout<<"Enter First Name: ";
    cin>>firstName;
    cout<<"Enter Last Name: ";
    cin>>lastName;
    cout<<"Enter Phone Number: ";
    cin>>phone_no;
    cout<<"Enter Balance: ";
    cin>>total_Balance;
    cout<<endl;
}
void account_query::show_data()
{
    cout<<"Account Number: "<<member_code<<endl;
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Phone Number: "<<phone_no<<endl;
    cout<<"Current Balance: "<<total_Balance<<endl;
    cout<<"-------------------------------"<<endl;
}
void account_query::write_rec()
{
    ofstream outfile;
    outfile.open("record.dat", ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}
void account_query::read_rec()
{
    ifstream infile;
    infile.open("record.dat", ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    cout<<"\n****Data from file****"<<endl;
    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
        {
            show_data();
        }
    }
    infile.close();
}
void account_query::search_rec()
{
    int n;
    ifstream infile;
    infile.open("record.dat", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_data();
}
void account_query::edit_rec()
{
    int n;
    fstream iofile;
    iofile.open("record.dat", ios::in|ios::binary);
    if(!iofile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to edit: ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
    show_data();
    iofile.close();
    iofile.open("record.dat", ios::out|ios::in|ios::binary);
    iofile.seekp((n-1)*sizeof(*this));
    cout<<"\nEnter data to Modify "<<endl;
    read_data();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void account_query::delete_rec()
{
    int n;
    ifstream infile;
    infile.open("record.dat", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("tmpfile.dat", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("record.dat");
    rename("tmpfile.dat", "record.dat");
}