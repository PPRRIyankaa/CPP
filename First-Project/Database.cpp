#include <iostream>
#include <vector>
using namespace std;


class Operation{
    public:
        void AddDetails(vector<Student> &stud){
            string name;
            string branch;
            string email;
            string phoneNo;
             
            bool duplicate = false;
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Branch: ";
            cin>>branch;
            cout<<"Enter Email :" ;
            cin>>email;
            for(int i=0;i<stud.size();i++){
                if(stud[i].getEmail()==email){
                    duplicate=true;
                    cout<<"Duplicate cannot be stored";
                    break;
                }
            }
            if(!duplicate){
            cout<<"Enter Phone Number: ";
            cin>>phoneNo;
            
            
            Student st(name,branch,email,phoneNo);
            stud.push_back(st);
            }
        }

        void UpdateData(vector<Student> &stud){
            string email;
            cout<<"Enter the Email of student whose details needs to be updated"<<endl;
            cin>>email;
            bool update = false;

            for(int i=0;i<stud.size();i++){
                if(stud[i].getEmail()==email){
                    update = true;
                    cout<<"Press 1 to update Name"<<endl;
                    cout<<"Press 2 to update Branch"<<endl;
                    cout<<"Press 3 to update Email"<<endl;
                    cout<<"Press 4 to update Phone Number"<<endl;

                    int choose;
                    cin>>choose;

                    switch(choose){
                        case 1: 
                            {
                                string name;
                                cout<<"Enter the updated Name:  ";
                                cin>>name;
                                stud[i].setName(name);
                                break;
                            }
                        case 2: 
                            {
                                string branch;
                                cout<<"Enter the updated branch:  ";
                                cin>>branch;
                                stud[i].setName(branch);
                                break;
                            }
                        case 3: 
                            {
                                string email;
                                cout<<"Enter the updated Email:  ";
                                cin>>email;
                                stud[i].setName(email);
                                break;
                            }
                        case 4: 
                            {
                                string phoneNo;
                                cout<<"Enter the updated Phone Number:  ";
                                cin>>phoneNo;
                                stud[i].setName(phoneNo);
                                break;
                            }
                            default: {
                                cout<<"Enter the correct choice";
                            }
                    }
                }
                if(!update){
                    cout<<"Enter the correct Email id. It is not present in the database";
                }
            }
        }

        void DeleteData(vector<Student> &stud){
            string email;
            cout<<"Enter the Email of student whose details needs to be updated"<<endl;
            cin>>email;
            bool deleted = false;

            for(int i=0;i<stud.size();i++){
                if(stud[i].getEmail()==email){
                    deleted = true;
                    stud.erase(stud.begin()+i);
                }
            }

            if(!deleted){
                cout<<"Enter the correct email that needs to be deleted";
            }
        }
};
class Student{
    private:
        string name;
        string branch;
        string email;
        string phoneNo;
        public:
     Student(string name, string branch , string email, string phoneNo){
            this->name =name;
            this->branch =branch;
            this->email=email;
            this->phoneNo =phoneNo;
     }
    string getEmail(){
        return this->email;
    }

    void setName(string name){
        this->name =name;
    }
    void setBranch(string branch){
        this->branch = branch;
    }
    void setEmail(string email){
        this->email =email;
    }
    void setPhoneNo(string phoneno){
        this->phoneNo = phoneno;
    }
};
int main(){
    cout<<"Press 1 for adding new Data"<<endl; 
    cout<<"Press 2 for update the Data"<<endl; 
    cout<<"Press 3 for deleting row"<<endl; 
    vector<Student> stud;
    Operation oper;
    int choose;
    cin>>choose;
    switch(choose){
        case 1 :
            {
                oper.AddDetails(stud);
                break;
            }
        case 2 :
            {
                oper.UpdateData(stud);
                break;
            }
        case 3 :
            {
                oper.DeleteData(stud);
                break;
            }
        default: {
            cout<<"Enter the correct number"
        }
    }

    return 0;
}