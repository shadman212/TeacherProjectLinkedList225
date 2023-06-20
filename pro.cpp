#include <iostream>
#include <fstream>
using namespace std;
struct Teacher
{
    string Tname;
    string Tinitial;
    string Temail;
    string Tphone;
    int Tage;
    Teacher* next;
};
   struct Teacher *head =0;

  string filename = "Teacher_list.txt";

   void saveToFile(Teacher* head, const string& filename)
{
    ofstream file(filename);//ios::app

    Teacher* temp = head;
    while (temp != nullptr)
    {

    file <<temp->Tname<< "\n";
    file <<temp->Tinitial<< "\n";
    file <<temp->Temail<< "\n";
    file <<temp->Tphone<< "\n";
    file <<temp->Tage<< "\n";
    temp = temp->next;

    }
    file.close();


}
Teacher* createTeacher(string Tname,string Tinitial,string Temail,string Tphone, int Tage)
{


    struct Teacher *temp;

    Teacher* newTeacher = new Teacher;

    newTeacher->Tname=Tname;
    newTeacher->Tinitial=Tinitial;
    newTeacher->Temail=Temail;
    newTeacher->Tphone=Tphone;
    newTeacher->Tage=Tage;
    newTeacher->next=nullptr;

    if (head==NULL)
    {
       head=newTeacher;
    }
    else
    {
        temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newTeacher;


    }

    saveToFile(head,filename);

}


  void loadFromFile(Teacher* head,const string& filename)
{
   Teacher* temp=head;
   ifstream file(filename);

    string name;
    string initial;
    string email;
    string phone;
    int age;

    while(getline(file,name)&& getline(file, initial)&& getline(file, email)&& getline(file, phone)&&file >> age&&file.ignore() )
    {
        createTeacher(name,initial,email,phone,age);

    }
    file.close();
}



void insertTeacher()
{

    Teacher* temp = head;

    string name;
    string initial;
    string email;
    string phone;
    int age;

    cout << "Enter Teacher Name: ";
    cin.ignore();
    getline(cin,name);



        cout << "Enter Teacher Initial: ";
       getline(cin,initial);



        Teacher* current = head;
        bool initialExists = false;
        while (current != nullptr)
        {
            if (current->Tinitial == initial)
            {
                initialExists = true;
                break;
            }
            current = current->next;
        }

        if (initialExists==true)
        {
            cout << "Initial already exists. Please enter a unique initial." << endl;
            return;
        }


    cout << "Enter Teacher Email: ";
    getline(cin,email);



    cout << "Enter Teacher Phone: ";
    getline(cin,phone);


    cout << "Enter Teacher Age: ";
    cin >> age;


    createTeacher(name, initial, email, phone, age);

}






void displayTeachers(Teacher* head)
{
    Teacher *temp=head;
    while(temp!=nullptr)
    {
        cout<<"Name    : "<<temp->Tname<<"\n";
        cout<<"Initial : " <<temp->Tinitial<<"\n";
        cout<<"Email   : " <<temp->Temail<<"\n";
        cout<<"Phone   : " <<temp->Tphone<<"\n";
        cout<<"Age     : " <<temp->Tage<<"\n\n";
        temp=temp->next;
    }

}

void deleteTeacher()
{
    if (head == nullptr)
    {
        cout << "Teacher list is empty." << endl;
        return;
    }

    string initial;
    cout << "Enter Teacher Initial to delete: ";
    cin >> initial;


    if (head->Tinitial == initial)
    {
        Teacher* temp = head;
        head = head->next;
        delete temp;
        cout << "Teacher with initial " << initial << " has been deleted." << endl;
        saveToFile(head, filename);
        return;
    }

    Teacher* prev = head;
    Teacher* curr = head->next;

    while (curr != nullptr)
    {
        if (curr->Tinitial == initial)
        {
            prev->next = curr->next;
            delete curr;
            cout << "Teacher with initial " << initial << " has been deleted." << endl;
            saveToFile(head, filename);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "Teacher with initial " << initial << " not found." << endl;
}
void modifyTeacher()
{
    if (head == nullptr)
    {
        cout << "Teacher list is empty." << endl;
        return;
    }

    string initial;
    cout << "Enter Teacher Initial to modify: ";
    cin >> initial;

    Teacher* temp = head;

    while (temp != nullptr)
    {
        if (temp->Tinitial == initial)
        {
            string newName;
            string newEmail;
            string newPhone;
            int newAge;

            cout << "Enter new name: ";
            cin >> newName;
            cout << "Enter new email: ";
            cin >> newEmail;
            cout << "Enter new phone: ";
            cin >> newPhone;
            cout << "Enter new age: ";
            cin >> newAge;


            temp->Tname = newName;
            temp->Temail = newEmail;
            temp->Tphone = newPhone;
            temp->Tage = newAge;

            cout << "Teacher with initial " << initial << " has been modified." << endl;
            saveToFile(head, filename);
            return;
        }

        temp = temp->next;
    }

    cout << "Teacher with initial " << initial << " not found." << endl;
}

 struct Course
{
    string Cname;
    string cTeacher;
    string cTime;
    string cRoom;
    Course* next;
};
   struct Course *head2 =0;



string filename2 = "Course_list.txt";


  void CourseSaveToFile(Course* head, const string& filename2)
{
    ofstream file(filename2);//ios::app

    Course* temp = head2;
    while (temp != nullptr)
    {

    file <<temp->Cname<< "\n";
    file <<temp->cTeacher<< "\n";
    file <<temp->cTime<< "\n";
    file <<temp->cRoom<< "\n";
    temp = temp->next;

    }
    file.close();


}

  Course* createCourse(string Cname,string cTeacher,string cTime,string cRoom)
{


    struct Course *temp;

    Course* newCourse = new Course;

    newCourse->Cname=Cname;
    newCourse->cTeacher=cTeacher;
    newCourse->cTime=cTime;
    newCourse->cRoom=cRoom;
   newCourse->next=nullptr;

    if (head2==NULL)
    {
       head2=newCourse;
    }
    else
    {
        temp = head2;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newCourse;


    }

    CourseSaveToFile(head2,filename2);

}

void loadCourseListFromFile(Course* head, const string& filename2)
{
    ifstream inputFile(filename2);

    if (!inputFile)
    {
        cout << "Error opening file.\n";
        return;
    }

    string courseName;
    string courseFaculty;
    string courseTime;
    string courseRoom;

    while (getline(inputFile, courseName) && getline(inputFile, courseFaculty) && getline(inputFile, courseTime) && getline(inputFile, courseRoom))
    {
        createCourse(courseName, courseFaculty, courseTime, courseRoom);
    }

    inputFile.close();
}


    void insertCourse()
{
    Teacher *temp = head;
    Course *temp2=head2;

    string courseName;
    string courseFaculty;
    string courseTime;
    string courseRoom;
    string Cfac;
    string TcourseTime;
    cout << "Enter Course Name:   \n";
    cin >> courseName;
    cout<<"\n";
    cout<<"Faculty have to register in the Register Book"<<endl;
    cout << "\n\nEnter Faculty of the Course:   "<<endl;
    cin >> Cfac;

    bool facultyExists = false;
    while (temp != nullptr)
    {
        if (temp->Tinitial == Cfac)
        {
            courseFaculty = temp->Tinitial;
            facultyExists = true;
            break;
        }
        temp = temp->next;
    }

    if (!facultyExists)
    {
        cout << "Faculty Does Not Exist in Register Book! Try Again with a valid Faculty\n"<<endl;
        cout<<"Thank You "<<endl ;
        return insertCourse();
    }




    int c=0;
    while (temp2 != nullptr)
    {
        if (temp2->cTeacher==courseFaculty)
        {
            c++;
        }
        temp2 = temp2->next;
    }
    if(c>3)
    {
        cout<<"Faculty Already Have 3 courses"<<endl;
        cout<<"Try again with another Faculty"<<endl;
        cout<<"Thank You"<<endl;
        return insertCourse() ;
    }







    cout <<"There are 15 time slot in 6 days :   " <<endl;

       cout <<"ST1 : 08:00 TO 09:30 AM " "\t" "\t" "MW1 : 08:00 TO 09:30 AM" "\t" "\t" "RA1 : 08:00 TO 09:30 AM"<<endl;
       cout <<"ST2 : 09:40 TO 11:10 AM " "\t" "\t" "MW2 : 09:40 TO 11:10 AM" "\t" "\t" "RA2 : 09:40 TO 11:10 AM" <<endl;
       cout <<"ST3 : 11:20 TO 12:50 PM " "\t" "\t" "MW3 : 11:20 TO 12:50 PM" "\t" "\t" "RA3 : 11:20 TO 12:50 PM"<<endl;
       cout <<"ST4 : 01:00 TO 02:30 PM " "\t" "\t" "MW4 : 01:00 TO 02:30 PM" "\t" "\t" "RA4 : 01:00 TO 02:30 PM"<<endl;
       cout <<"ST5 : 02:40 TO 04:10 PM " "\t" "\t" "MW5 : 02:40 TO 04:10 PM" "\t" "\t" "RA5 : 02:40 TO 04:10 PM"<<endl;
       cout<< "ST : Sunday and Tuesday"    <<endl;
       cout<< "MW : Monday and Wednesday"  <<endl;
       cout<< "RA : Thursday and Saturday" <<endl;


        cout << "Enter Course Time:   ";
        cin >> TcourseTime;


          bool IT = false;
            while (temp2 != nullptr)
    {

        if(temp2->cTeacher==courseFaculty&&temp2->cTime==TcourseTime)
        {

            IT=true;
       }
      temp2 = temp2->next;


    }

        if (IT==true)
        {
            cout << "Initial already Have This time slot." << endl;

            cout<<"Please Try Again With Another Time Slot"<<endl;

            cout<<"Thank You "<<endl;

            return insertCourse();

        }
        else
        {
            courseTime=TcourseTime;
        }


    cout << "Enter Course Room:   ";
    cin >> courseRoom;


    createCourse(courseName, courseFaculty, courseTime, courseRoom);
}


void displayCourse(Course* head2)
{
    Course *temp=head2;
    while(temp!=nullptr)
    {
        cout<<"Course Name     : " <<temp->Cname<<"\n";
        cout<<"Faculty Initial : " <<temp->cTeacher<<"\n";
        cout<<"Course Time     : " <<temp->cTime<<"\n";
        cout<<"Course Room     : " <<temp->cRoom<<"\n\n";

        temp=temp->next;
    }

}

void searchTeacher(Teacher *head)
{
    int r=0;
    string s;
    cout<<"Enter The Initial You want to Search"<<endl;
    cin>>s;

    Teacher *temp=head;

    while(temp!=nullptr)
    {
        if(temp->Tinitial==s)
        {

        cout<<"Found That Faculty "<<endl;
        cout<<"Name    : "<<temp->Tname<<"\n";
        cout<<"Initial : " <<temp->Tinitial<<"\n";
        cout<<"Email   : " <<temp->Temail<<"\n";
        cout<<"Phone   : " <<temp->Tphone<<"\n";
        cout<<"Age     : " <<temp->Tage<<"\n\n";
        r=1;

        }

          temp=temp->next;



    }
    if(r==0)
    {
        cout<<"Invalid Faculty Initial" <<endl;
    }
    else
        return;



}

    int main()
{

    int choice;


    loadFromFile(head, filename);
    loadCourseListFromFile(head2, filename2);


    do {

        cout<<"\n-- Menu --\n"<<endl;
         cout<<"       1. Display All Teachers\n"<<endl;
         cout<<"       2. Display All Courses\n"<<endl;
         cout<<"       3. Insert Teacher To   Register Book\n"<<endl;
         cout<<"       4. Delete Teacher from Register Book\n"<<endl;
         cout<<"       5. Modify Teacher from Register Book\n"<<endl;
         cout<<"       6. Insert Course\n"<<endl;
         cout<<"       7. Search Teacher\n"<<endl;
         cout<<"       0. Exit\n"<<endl;
         cout<<"Enter your choice: "<<endl;
         cin>>choice;


        switch (choice) {
            case 0:
                printf("Exiting the program.\n");
                break;
            case 1:
                displayTeachers(head);
                break;
            case 2:
                displayCourse(head2);
                break;
            case 3:
                displayTeachers(head);
                insertTeacher();
                break;
            case 4:
                displayTeachers(head);
                deleteTeacher();
                break;
            case 5:
                displayTeachers(head);
                modifyTeacher();
                break;
            case 6:
                displayCourse(head2);
                displayTeachers(head);
                insertCourse();
                break;
            case 7:
               searchTeacher(head)  ;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
















