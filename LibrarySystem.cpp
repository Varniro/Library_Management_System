#include <iostream>
#include <fstream> // file handling
#include <string>
#include <sstream> // string stream
using namespace std;

class student{
    string name, branch, enroll;
    string books[10];
    int year, bookNum = 0;

    public:

    student(){}
    student(int temp);// Sign Up
    student(string tName, string tEnroll){ // Sign In
        name = tName;
        enroll = tEnroll;
    }

    int operator== (student a){
        if(name == a.name && enroll == a.enroll){
            return 1;
        }else{
            return 0;
        }
    }

    void showData(){
        cout<<"Name: "<<name<<endl;
        cout<<"Branch: "<<branch<<endl;
        if(year == 1){
            cout<<"Year: 1st";
        }else if(year == 2){
            cout<<"Year: 2nd";
        }else if(year == 3){
            cout<<"Year: 3rd";
        }else{
            cout<<"Year: "<<year<<"th";
        }

        cout<<endl;
    }

    void issue(){
        string bookName;
        cin.ignore();
        getline(cin, bookName);
        books[bookNum] = bookName;
        bookNum++;
        cout<<"You have successfully issused "<<bookName<<endl;
    }

    void retBook(){
        string bookName;
        cin.ignore();
        getline(cin, bookName);
        for(int i = 0; i<bookNum; i++){
            if(bookName == books[i]){
                cout<<"Returned "<<bookName<<endl;
                break;
            }
        }
    }

};

student::student(int temp){

    ofstream db;
    db.open("LibData.txt", ios::app);// append mode -> any new data added will be added to the end of the file i.e. after already exsisting.

    cout<<"Please enter your full name: ";
    cin.ignore();
    getline(cin, name, '\n');
    
    cout<<"Please enter your Enrollment Number: ";
    reenter:
    cin>>enroll;

    if(enroll.substr(0,4) != "0901"){ // "0901CD211024" = 0901
        cout<<"ERORR: Incorrect Enrollment Number, Please Re-enter: ";
        goto reenter;
    }else{
        switch ((int)enroll[4]*1000 + (int)enroll[5])// 0901CE211024 enroll[4] = c, enroll[5] = e, (int)c = 45, (int)d = 47, 45*1000+ 47 = 45047
        {
        case (int)'c'*1000 + (int)'d': // 45046
            branch = "Computer Science and Design";
            break;
        case (int)'C'*1000 + (int)'D':
            branch = "Computer Science and Design";
            break;
        case (int)'c'*1000 + (int)'s':
            branch = "Computer Science";
            break;
        case (int)'C'*1000 + (int)'S':
            branch = "Computer Science";
            break;
        case (int)'m'*1000 + (int)'e':
            branch = "Mechanical Engineering";
            break;
        case (int)'M'*1000 + (int)'E':
            branch = "Mechanical Engineering";
            break;
        case (int)'a'*1000 + (int)'d':
            branch = "Artificial Intelligence(AI) and Data Science";
            break;
        case (int)'A'*1000 + (int)'D':
            branch = "Artificial Intelligence(AI) and Data Science";
            break;
        case (int)'a'*1000 + (int)'i':
            branch = "Artificial Intelligence and Robotics";
            break;
        case (int)'A'*1000 + (int)'I':
            branch = "Artificial Intelligence and Robotics";
            break;
        case (int)'a'*1000 + (int)'m':
            branch = "Artificial Intelligence and Machine Learning";
            break;
        case (int)'A'*1000 + (int)'M':
            branch = "Artificial Intelligence and Machine Learning";
            break;
        case (int)'a'*1000 + (int)'r':
            branch = "Architecture";
            break;
        case (int)'A'*1000 + (int)'R':
            branch = "Architecture";
            break;
        case (int)'a'*1000 + (int)'u':
            branch = "Automobile Engineering";
            break;
        case (int)'A'*1000 + (int)'U':
            branch = "Automobile Engineering";
            break;
        case (int)'c'*1000 + (int)'e'://45047
            branch = "Civil Engineering";
            break;
        case (int)'C'*1000 + (int)'E':
            branch = "Civil  Engineering";
            break;
        case (int)'c'*1000 + (int)'m':
            branch = "Chemical Engineering";
            break;
        case (int)'C'*1000 + (int)'M':
            branch = "Chemical Engineering";
            break;
        case (int)'e'*1000 + (int)'c':
            branch = "Electronics Engineering";
            break;
        case (int)'E'*1000 + (int)'C':
            branch = "Electronics Engineering";
            break;
        case (int)'e'*1000 + (int)'o':
            branch = "Internet of Things(EE)";
            break;
        case (int)'E'*1000 + (int)'O':
            branch = "Internet of Things(EE)";
            break;
        case (int)'e'*1000 + (int)'t':
            branch = "Electronics & Telecommunication Engineering";
            break;
        case (int)'E'*1000 + (int)'T':
            branch = "Electronics & Telecommunication Engineering";
            break;
        case (int)'i'*1000 + (int)'o':
            branch = "Internet of Things(IT)";
            break;
        case (int)'I'*1000 + (int)'O':
            branch = "Internet of Things(IT)";
            break;
        case (int)'i'*1000 + (int)'t':
            branch = "Information Technology";
            break;
        case (int)'I'*1000 + (int)'T':
            branch = "Information Technology";
            break;
        case (int)'m'*1000 + (int)'c':
            branch = "Mathematics and Computing";
            break;
        case (int)'M'*1000 + (int)'C':
            branch = "Mathematics and Computing";
            break;
        case (int)'e'*1000 + (int)'e':
            branch = "Electrical Engineering";
            break;
        case (int)'E'*1000 + (int)'E':
            branch = "Electrical Engineering";
            break;
        default:
            cout<<"ERORR: Incorrect Enrollment Number, Please Re-enter: ";
            goto reenter;
            break;
        }

        switch ((int)enroll[6]*100 + (int)enroll[7])// 0901CD211024
        {
        case (int)'1'*100 + (int)'7':
            year = 5;
            break;
        case (int)'1'*100 + (int)'8':
            year = 4;
            break;
        case (int)'1'*100 + (int)'9':
            year = 3;
            break;
        case (int)'2'*100 + (int)'0':
            year = 2;
            break;
        case (int)'2'*100 + (int)'1':
            year = 1;
            break;
        
        default:
            break;
        }
    }

    //db.write((char*)this, sizeof(student));

    cout<<"\n<---------------------------------------------->\n";
    cout<<"New Student Registered!\n";
    cout<<"Name: "<<name<<endl;
    cout<<"Branch: "<<branch<<endl;
    if(year == 1){
        cout<<"Year: 1st";
    }else if(year == 2){
        cout<<"Year: 2nd";
    }else if(year == 3){
        cout<<"Year: 3rd";
    }else{
        cout<<"Year: "<<year<<"th";
    }

    cout<<endl;
}

int main(){
    student studentData[100];

    ofstream file2("Config.txt", ios::app);
    file2.close();
    fstream config("Config.txt", ios::app | ios::in);

    int num;

    config.seekg(0, ios::end);  // 09876re5678909876
    if(config.tellg() == 0) {    
        num = 0;
    }else{
        config.close();
        ifstream config;
        config.open("Config.txt");//44
        stringstream ss;
        string aa;
        config>>aa;  // "44" = StringStream = int = 44
        
        ss<<aa;
        ss>>num;
        config.close();

        // for (int i = 0; i < num; i++)
        // {
        //      db.read((char*) &studentData, sizeof(student));
        //      studentData[i].showData();
        // }

       // ofstream file1("LibData.txt", ios::app);
        //file1.close();
        ifstream db;
        db.open("LibData.txt",ios::in);
        db.seekg(0);

        student oo;
        cout<<num;
        db.read((char*)&oo, sizeof(oo));
        oo.showData();
        db.close();
    }

    ofstream configOut;
    configOut.open("Config.txt");
    
    start:
    int choice;

    cout<<"<---------------------------------------------->\n";
    cout<<"Welcome to the MITS E-Library.\n";
    cout<<"Choose the action you would like to perform.\n";
    cout<<"\n1. Register new student.\n";
    cout<<"\n2. Issue a new book.\n";
    cout<<"\n3. Return a previously issued book.\n";
    cout<<"\n4. Exit the E-Libaray.\n";

    cout<<"->";
    cin>>choice;

    if(choice == 1){
        student s(0);
        ofstream file1("LibData.txt", ios::app);
        file1.write((char*)&s, sizeof(s));
        file1.close();
        studentData[num] = s;
        num++;
        goto start;
    }else if(choice == 2){
        string tempName, tempEnroll;
        cout<<"<---------------------------------------------->\n";
        cout<<"Login using your Name and Enrollment Number->\n";
        cout<<"Enter your name:";
        cin.ignore();
        getline(cin, tempName, '\n');
        cout<<"Enter your Enrollment Number: ";
        cin>>tempEnroll;
        student tempStu(tempName, tempEnroll);
        for (int i = 0; i < num; i++)
        {
            if(tempStu == studentData[i]){
                studentData[i].showData();
                cout<<"\nEnter the name of the book you want to issue: ";
                studentData[i].issue();
                break;
            }
            if(i == num-1){
                 cout<<"No record found, please register yourself.\n";
                 goto start;       
            }
        }
        
        goto start;
    }else if(choice == 3){
        string tempName, tempEnroll;
        cout<<"<---------------------------------------------->\n";
        cout<<"Login using your Name and Enrollment Number->\n";
        cout<<"Enter your name:";
        cin.ignore();
        getline(cin, tempName, '\n');
        cout<<"Enter your Enrollment Number: ";
        cin>>tempEnroll;
        student tempStu(tempName, tempEnroll);
        for (int i = 0; i < num; i++)
        {
            if(tempStu == studentData[i]){
                studentData[i].showData();
                cout<<"\nEnter the name of the book you want to return: ";
                studentData[i].retBook();
                break;
            }
            if(i == num-1){
                 cout<<"No record found, please register yourself.\n";
                 goto start;       
            }
        }
        
        goto start;
    }else if(choice == 4){
        configOut<<to_string(num); // 47 = "47"
        configOut.close();
        return 0;
    }else{
        cout<<"<---------------------------------------------->\n";
        cout<<"Not a Valid Choice!\n";
        goto start;
    }

    return 0;
}