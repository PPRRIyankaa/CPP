#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
void registers(){
        string name, password;
            cout<<"__________________________________"<<endl;
            cout<<"           Register         "<<endl;
            cout<<"Please Enter your username:  ";
            cin>>name;
            cout<<"Please Enter your password:  ";
            cin>>password;

            ofstream of1;
            of1.open("file.txt",ios::app);
            if(of1.is_open()){
                of1<<name<<" ";
                of1<<password<<"\n";
                cout<<"Registration Successfull"<<endl;
            }
            of1.close();
}
void login(){
    string name, password, text, nm, pw;

    cout<<"__________________________________"<<endl;
    cout<<"           Login         "<<endl;
    cout<<"__________________________________"<<endl;

    ifstream of1;
    of1.open("file.txt");
    cout<<"Please Enter your username:  ";
    cin>>name;
    cout<<"Please Enter your password:  ";
    cin>>password;

    if(of1.is_open()){
            while(getline(of1,text)){
                cout<<text<<endl;
                istringstream iss(text);
                iss>>nm;
                iss>>pw;
                if(nm==name && pw==password) break;
            }
                
            if(name==nm && password == pw){
                cout<<"           Login successfull         "<<endl<<endl;
                cout<<"Details: "<<endl;
                cout<<"Username: "+name<<endl;
                cout<<"Password: "+password<<endl;
            }
            else{
                cout<<endl<<endl;
                cout<<"            Incorrect Details         "<<endl;
                cout<<"          2. Login           "<<endl;
                cout<<"          3. Change Password           "<<endl;
                cout<<"          4. End Program           "<<endl;
            }
    }
    of1.close();
}
void changePassword(){
    int i=0, ind = 0, length = 0;
    string oldPassword, password1, password2, text, name, nm, pw, pwd;
    cout<<"           Change Password         "<<endl<<endl;

    fstream of1;
    of1.open("file.txt",ios::in|ios::out);
    cout<<"Enter the old password:-";
    cin>>oldPassword;
    if(of1.is_open()){
        while(getline(of1,text)){
            istringstream iss(text);
            iss>>name;
            nm = name;
            iss>>pwd;
            pw = pwd;
            ind = of1.tellg();  
            length = pw.length();
            if(oldPassword==pw) break;
        }
        if(oldPassword==pw){
            ind = ind - length;
                cout<<"Enter your new password:-"; 
                cin>>password1;
                cout<<"Enter your password again:-";
                cin>>password2;

                if(password1==password2){
                    of1.seekp(ind-1,ios::beg);
                    of1<<password1;
                    cout<<"Password changed successfully"<<endl;
                }
                else{
                    cout<<"Password does not matches"<<endl;
                }
        }
        else{
            cout<<"Please enter the valid Password"<<endl;
        }
        of1.close();
    }
}
void endProgram(){
    cout<<"-------------------Thank You-------------------"<<endl;
}
int main(){
    int a, i=0;
    string name, password;

    cout<<"          Security System         "<<endl;
    cout<<"__________________________________"<<endl;
    cout<<"          1. Register         "<<endl;
    cout<<"          2. Login         "<<endl;
    cout<<"          3. Change Password         "<<endl;
    cout<<"          4. End Program         "<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter Your choice:  ";
        cin>>a;
        switch (a)
        {
        case 1:
            registers();        
            break;
        case 2:
            login();
            break;
        case 3:
            changePassword();
            break;
        case 4:
            endProgram();
            break;
        default:
            cout<<"Enter the Valid Password"<<endl;
            break;
        }
    }while(a!=4);
    return 0;
}


