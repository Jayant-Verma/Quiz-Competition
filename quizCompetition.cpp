#include<iostream>
#include<conio.h>
#include<random>
#include<ctime>

using namespace std;

void welcome();
void request();
void request(string);
void admin();
void user();

class login
{
	private :
		string admin_name[5]={"purti","pirti2"};
		string admin_password[5]={"123@","1234"};
		string user_name[5]={"HaveFun","prince","pooja"};
		string user_password[5]={"123456","12345678","fhhfwwe"};
		string id,pswrd;
	public :
		login(string ID, string pass) {
			id=ID;
			pswrd=pass;
		}
		login()
		{
		}
		bool admin_check()
		{
			int i;
			for(i=0;i<5;i++)
				if(admin_name[i]==id && admin_password[i]==pswrd)
					return true;
			return false;
		}
		bool user_check()
		{
			int i;
			for(i=0;i<5;i++)
				if(user_name[i]==id && user_password[i]==pswrd)
					return true;
			return false;
		}
		friend void show_user(login);
};

class quiz
{
	private:
		string quiz[4]={"C Language Quiz","C++ Language Quiz","Java Language Quiz","Python Language Quiz"};
		int i,ch;
		int Q_NO = 1;
		int CORRECT = 0;
		int WRONG = 0;
		bool ask[10] = {true , true , true , true , true , true , true , true , true , true};
	public:
		void listquiz(int type)
		{
			welcome();
			cout<<"\n\t\t# List of Quizes\n";
			for(i=0;i<4;i++)
				cout<<"\n\t\t\t-> "<<i+1<<". "<<quiz[i]<<endl;
			cout<<"\n\t\tChoose any of the options : ";
			cin>>ch;
			if(ch<=0&&ch>4)
			{
				cout<<"Wrong input !";
				getch();
				listquiz(type);
			}
			else
			{
				if(type==0)
					rules();
				else if(type==1)
					showquiz();
			}
		}

		void showquiz()
		{
			welcome();
			cout<<"\n\t\t\t\t"<<quiz[ch-1]<<endl;
			cout<<"\t\t\t\t----------------\n";
			displayquiz(ch,"admin");
		}

		void rules()
		{
			welcome();
			cout<<"\n\t\tWelcome to "<<quiz[ch-1]<<endl;
			cout<<"\t\t----------------------------\n";
			cout<<"\t\tThese are the following rules for the quiz..\n";
			cout<<"\t\t1. You have 10 question in the quiz.\n";
			cout<<"\t\t2. There will be four options for each question.\n";
			cout<<"\t\t3. Only one answer is correct among all four options.\n";
			cout<<"\t\t4. Please enter corresponding alphabate assosiated with your answer.\n";
			cout<<"\t\t5. You will get 1 point for each right answer and will lose 1 point for each wrong answer.\n";
			cout<<"\t\t6. Please do not write whole statement as your answer.\n";
			cout<<"\t\t7. After completion of quiz your calculated score will be display.\n";
			cout<<"\n\t\t\t\tALL THE BEST !!!\n";
			getch();
			displayquiz(ch);
		}

		void displayquiz(int ch,string ID="user")
		{
			welcome();
			if(ID=="user")
    			cout << "\n\tQuestion NO:" << Q_NO << "\t\tCorrect Answers:" << CORRECT << "\t\tWrong Answers:" << WRONG<< endl<<endl <<"\t";
    		else
    			cout<<"\n\t"<<Q_NO<<". ";
		    switch(ch)
		    {
		    	case 1:
		    		c_quiz(ID);
		    		break;
		    	case 2:
					cpp_quiz(ID);
		    		break;
		    	case 3:
		    		java_quiz(ID);
		    		break;
		    	case 4:
		    		python_quiz(ID);
		    		break;
		    	default:
		    		cout<<"\twrong choice";
			}
		}

		void c_quiz(string ID)
		{
    		srand(time(0));
	    	bool is_question_remaining = false;
    		for(int i=0; i<10; i++)
	    	{
    	    	if(ask[i])
        		{
            		is_question_remaining = true;
            		break;
        		}
    		}
    		while(is_question_remaining)
    		{
        		int no = rand()%10;
        		if(ask[no])
        		{
            		ask[no] = false;
            		switch(no)
            		{
            			case 0 :
                			question("Which of the following are valid data types in c?" , "int,double,char,boolean", "int,float,double,char" , "int,bool,string" , "int,float,string,char" , 'b',ID);
	                        break;
    	        		case 1 :
        	        		question("Which of the following statements about functions is false?" , "The main() function can be called recursively" , "Functions cannot return more than one value at a time" , "A function can have multiple return statements with different return values" , "The maximum number of arguments a function can take is 128" , 'd',ID);
            	            break;
            			case 2 :
                			question("What is the correct way of treating 9.81 as a long double?" , "9.81L" , "9.81LD" , "9.81D" , "9.81DL" , 'a',ID);
                        	break;
	            		case 3 :
    	            		question("What is a variable?" , "A empty container in which we store data" , "box" , "Data type" , "language" , 'a',ID);
        	                break;
            			case 4 :
                			question("Which is true for pointers?" , "pointers can be used in expressions just as any variable" , "pointers are useless and make programmers lives a nightmare" , "pointers are storing the values of variables" , "none of the above" , 'a',ID);
                    	    break;
	            		case 5 :
    	            		question("Variables scope refers to" , "the number of variables in a program" , "the number of declared functions" , "the visibility of variables within a program" , "none of the above" , 'c',ID);
        	                break;
            			case 6 :
                			question("Which function would you use to convert 1.98 to 1?" , "ceil()" , "floor()" , "fabs()" , "abs()" , 'b',ID);
                    	    break;
	            		case 7 :
    	            		question("Which of the following has a global scope in the program?" , "Formal parameters" , "Constants" , "Macros" , "Local Variables" , 'c',ID);
        	                break;
            			case 8 :
                			question("What is the range of double data type for a 16-bit compiler?" , "-1.7e-328 to +1.7e-328" , "-1.7e-348 to +1.7e-348" , "-1.7e-308 to +1.7e-308" , "-1.7e-338 to +1.7e-338" , 'c',ID);
                    	    break;
	            		case 9 :
    	            		question("Which of the following statements about unions is incorrect?" , "A bit fiels can not be used in a union" , "A pointer to a union exists" , "Union elements can be of different sizes" , "A union can be nested into a structure" , 'a',ID);
        	                break;
            		}
        		}
    		}
    		if(ID=="user")
	    		result();
	    	else
	    		admin();
		}

		void cpp_quiz(string ID)
		{
    		srand(time(0));
	    	bool is_question_remaining = false;
    		for(int i=0; i<10; i++)
	    	{
    	    	if(ask[i])
        		{
            		is_question_remaining = true;
            		break;
        		}
    		}
    		while(is_question_remaining)
    		{
        		int no = rand()%10;
        		if(ask[no])
        		{
            		ask[no] = false;
            		switch(no)
            		{
            			case 0 :
                			question("C++ does not support the following." , "Multilevel Inheritance", "Hierarchical Inheritance" , "Hybrid Inheritance" , "None of the above" , 'd',ID);
	                        break;
    	        		case 1 :
        	        		question("Which is the storage specifier used to modify the member variable even though the class object is a constant object ?","Auto","Register","static","Mutable" , 'd',ID);
            	            break;
            			case 2 :
                			question("Compiler generates ____ file.","Executable Code","Object Code","Assembly Code","None of the above",'b',ID);
                        	break;
	            		case 3 :
    	            		question("Identify the C++ compiler of linux.","CPP","G++","Borland","VC++",'b',ID);
        	                break;
            			case 4 :
                			question("What is a correct syntax to output \"Hello World\" in C++","system.out.println(\"Hello World\");","print(\"Hello World\");","cout<<\"Hello World\";","Console.WriteLine(\"Hello World\");",'c',ID);
                    	    break;
	            		case 5 :
    	            		question("How do you insert SINGLE LINE COMMENTS in C++ code","/*This is a comment.*/","#This is a comment.","//This is a comment.","None of them",'c',ID);
        	                break;
            			case 6 :
                			question("Which datatype is used to create a variable that should store text ?","txt","string","myString","String",'b',ID);
                    	    break;
	            		case 7 :
    	            		question("How do you create a variable with the numeric value 5 ?","num x=5","int x=5;","x=5;","double x=5;",'b',ID);
        	                break;
            			case 8 :
                			question("How do you create a variable with the floating number 2.8 ?","int x=2.8;","byte x=2.8","x=2.8;","double x=2.8;",'d',ID);
                    	    break;
	            		case 9 :
    	            		question("Which method can be used to find the length of a string ?","getSize()","length()","len()","getLength()",'b',ID);
        	                break;
            		}
        		}
    		}
    		if(ID=="user")
	    		result();
	    	else
	    		admin();
		}
		void java_quiz(string ID)
		{
    		srand(time(0));
	    	bool is_question_remaining = false;
    		for(int i=0; i<10; i++)
	    	{
    	    	if(ask[i])
        		{
            		is_question_remaining = true;
            		break;
        		}
    		}
    		while(is_question_remaining)
    		{
        		int no = rand()%10;
        		if(ask[no])
        		{
            		ask[no] = false;
            		switch(no)
            		{
            			case 0 :
                			question("What is a correct syntax to output \"Hello World\" in Java?","echo (\"Hello World\");","print(\"Hello World\");","System.out.println(\"Hello World\");","Console.WriteLine(\"Hello World\");",'c',ID);
	                        break;
    	        		case 1 :
        	        		question("Which data type is used to create a variable that should store text ?","string","myString","String","Txt",'c',ID);
            	            break;
            			case 2 :
                			question("Which of the following is not a keyword in java ?","static","Boolean","void","private",'b',ID);
                        	break;
	            		case 3 :
    	            		question("What is the size of float variable ?","8 bit","16 bit","32 bit","64 bit",'c',ID);
        	                break;
            			case 4 :
                			question("What is the default value of char variable ?","'\\u0000'","0","null","not defined",'a',ID);
                    	    break;
	            		case 5 :
    	            		question("What is Abstraction ?","Abstraction is a technique to define different method of same type.","Abstraction is the ability of an object to take on many forms.","It refers to the ability to make a class abstract in OOP","None of the above",'c',ID);
        	                break;
            			case 6 :
                			question("Method Overloading is an example of ","Static Binding","Dynamic Binding","Both of the above","None of the above",'a',ID);
                    	    break;
	            		case 7 :
    	            		question("What is a transient variable ?","A transient variable is a variable which is serialized during serialization","A transient variable is a variable that may not be serialized during serialization","A transient variable is a variable which is to be marked as serializable","None of the above",'b',ID);
        	                break;
            			case 8 :
                			question("Under what conditions is an object's finalize() method invoked by the garbage collector ?","When is detects that the object has become unrachable.","As soon as object is set in null.","At fixed intervalm it checks for null value.","None of the above",'a',ID);
                    	    break;
	            		case 9 :
    	            		question("Which of the following is a marker interface ?","Serializable","Comparable","Cloneable","None of the above",'a',ID);
        	                break;
            		}
        		}
    		}
    		if(ID=="user")
	    		result();
	    	else
	    		admin();
		}
		void python_quiz(string ID)
		{
    		srand(time(0));
	    	bool is_question_remaining = false;
    		for(int i=0; i<10; i++)
	    	{
    	    	if(ask[i])
        		{
            		is_question_remaining = true;
            		break;
        		}
    		}
    		while(is_question_remaining)
    		{
        		int no = rand()%10;
        		if(ask[no])
        		{
            		ask[no] = false;
            		switch(no)
            		{
            			case 0 :
                			question("What is output for following code - \ny = [4, 5,1j]\ny.sort()","[1j,4,5]","[5,4,1j]","[4,5,1j]","Type Error",'d',ID);
	                        break;
    	        		case 1 :
        	        		question("When the given code is executed how many times ' 'you are learning python ' ' will be printed.\na = 0\nwhile a<10:\n\tprint(''you are learning python'')\n\tpass","9","10","11","Infinite number of times",'d',ID);
            	            break;
            			case 2 :
                			question("What is output of following code -\ns = ''mnopqr ''\ni = ''m ''\nwhile i in s:\n   print('i', end= '' '')","i i i i i i i i��..","m m m m m �..","m n o p q r","no output",'a',ID);
                        	break;
	            		case 3 :
    	            		question("What is output of following - \nprint('any'.encode())","'any'","'yan'","b'any'","x'any'",'c',ID);
        	                break;
            			case 4 :
                			question("Which of the following is more accurate for the following declaration ?\nx = Circle()","Now you can assign int value to x.","x contains a reference to a Circle object.","x actually contains an object of type Circle.","x contains an int value.",'b',ID);
                    	    break;
	            		case 5 :
    	            		question("Which of the function among will return 4 on the set s = {3, 4, 1, 2} ?","Sum(s)","Len(s)","Min(s)","Four(s)",'b',ID);
        	                break;
            			case 6 :
                			question("Which function can be used on the file to display a dialog for saving a file ?","Filename = savefilename()","Filename = asksavefilename()","Filename = asksaveasfilename()","No such option in python.",'c',ID);
                    	    break;
	            		case 7 :
    	            		question("Suppose you are using a grid manager then which option is best suitable to place a component in multiple rows and columns ?","Columnspan and rowspan","Only row","Only column","Only rowspan",'a',ID);
        	                break;
            			case 8 :
                			question("We can create an image in canvas. Select the option to do so ?","Image = PhotoImage(imagefilename)","Canvas.create_image(filename)","Image = Photoimage(file=imagefilename)","Image = Photoimage(imagefilename)",'c',ID);
                    	    break;
	            		case 9 :
    	            		question("What is the output for -\n'you are doing well' [2:999]","'you are doing well'","' '","Index error.","'u are doing well'",'d',ID);
        	                break;
            		}
        		}
    		}
    		if(ID=="user")
	    		result();
	    	else
	    		admin();
		}

		void result()
		{
    		welcome();
		    cout << "\n\tTotal Question = " << Q_NO-1 << endl;
    		cout << "\tCorrect Answers = " << CORRECT << endl;
	    	cout << "\tWrong Answers = " << WRONG << endl;
	    	if(CORRECT > WRONG)
    	    	cout << "\tResult = PASS" << endl;
    		else if(WRONG > CORRECT)
        		cout << "\tResult = FAIL" << endl;
    		else
        		cout << "\tResult = Tie" << endl;
        	cout<<"\n\tPress any key to return on home page..";
        	getch();
        	Q_NO = 1;
			CORRECT = 0;
			WRONG = 0;
			for(int i=0;i<10;i++)
				ask[i] = true;
			::user();
		}

		void question(string question , string a , string b , string c , string d , char correct_answer,string ID)
		{
			cout << question << endl;
	    	cout << "\tA.\t" << a << endl;
    		cout << "\tB.\t" << b << endl;
		    cout << "\tC.\t" << c << endl;
    		cout << "\tD.\t" << d << endl;
    		if(ID=="user")
    		{
				char answer;
    			cout<<"\t";
    			cin >> answer;
    			if(answer == correct_answer)
        			CORRECT++;
	    		else
    	    		WRONG++;
    		}
    		else
    		{
    			cout<<"\n\tCorrect Answer = "<<correct_answer;
    			getch();
			}
			Q_NO++;
    		displayquiz(ch,ID);
		}
};

void show_user(login user)
{
	welcome();
    cout<<"\n\t\tRegistered user\t\tPasswords";
    cout<<"\n\t\t---------------         ---------\n";
	for(int i=0;i<3;i++)
		cout<<"\t\t"<<i+1<<". "<<user.user_name[i]<<"\t\t"<<user.user_password[i]<<endl;
	cout<<"\n\t\tPress any key to return.";
	getch();
}

int main()
{
	int choice;
	welcome();
	cout<<"\n\n\t\t1. Admin Login\n\n";
	cout<<"\t\t2. User Login\n\n";
	cout<<"\t\t0. EXIT\n\n";
	cout<<"\n\t\tPlease enter required option :";
	do {
		cin>>choice;
		switch(choice)
		{
			case 1 :
				request();
				break;
			case 2 :
				request("user");
				break;
			case 0 :
				exit(0);
				break;
			default :
				cout<<"Retry...";
		}
	}while(choice!=1 && choice!=2 && choice!=0);
	return 0;
}

void welcome()
{
	system("cls");
	cout<<"\n\n\t\t\tNational Institute of Technology, Warangal\n";
	cout<<"\t\t\t=======================================\n";
}

void request()
{
	int choice,i,check;
	string id,password;
	welcome();
	cout<<"\n\n\t\tEnter Admin UserID :";
	cin>>id;
 	cout<<"\n\n\t\tEnter Password :";
	cin>>password;
	login admin_rqst(id,password);
	check=admin_rqst.admin_check();
	if(check)
		admin();
	else
	{
		cout<<"\n\t\tInvalid ID/password !\n\t\tPress any key to Retry.";
		getch();
		request();
	}
}

void request(string)
{
	int choice,i,check;
	string id,password;
	welcome();
	cout<<"\n\n\t\tEnter UserID :";
	cin>>id;
 	cout<<"\n\n\t\tEnter Password :";
	cin>>password;
	login user_rqst(id,password);
	check=user_rqst.user_check();
	if(check)
		user();
	else
	{
		cout<<"\n\t\tInvalid ID/password !\n\t\tPress any key to Retry.";
		getch();
		request("user");
	}
}

void admin()
{
	int ch;
	login user;
	quiz list;
	label1:
    welcome();
    cout<<"\t\t\t\t\tADMIN PAGE\n\n";
    cout<<"\t\t1. Registered Users\n\n";
    cout<<"\t\t2. List of Quizes\n\n";
    cout<<"\t\t3. Log Out\n\n";
    cout<<"\n\t\tPlease enter your choice :";
    do {
        cin>>ch;
        switch(ch)
        {
            case 1:
                show_user(user);
                goto label1;
                break;
            case 2:
            	welcome();
            	cout<<"\t\t\t\t\tADMIN PAGE\n";
                list.listquiz(1);
                goto label1;
                break;
            case 3:
                main();
                break;
            default:
                cout<<"\t\tRetry ";
        }
    }while(ch!=1 && ch!=2 && ch!=3);
}

void user()
{
	int ch;
    welcome();
    quiz play;
    cout<<"\t\t\t\t\tUSER PAGE\n";
    cout<<"\t\t1. Play Quiz\n\n";
    cout<<"\t\t2. Log Out\n\n";
    cout<<"\n\t\tPlease enter your choice :";
    do {
        cin>>ch;
        switch(ch)
        {
            case 1:
                play.listquiz(0);
                break;
            case 2:
                main();
                break;
            default:
                cout<<"\t\tRetry ";
        }
    }while(ch!=1 && ch!=2);
}
