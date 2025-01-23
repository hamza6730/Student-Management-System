#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;
string arr1[25],arr2[25],arr3[25],arr4[25],arr5[25];
int total=0;
void add()
{
	int a;
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	cout<<"No of Students: ";
	cin>>a;
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	if(total==0){
	total=total+a;
	for(int i=0;i<a;i++)
	{
		cout<<"\nEnter the record of the student: "<<i+1<<endl<<endl;
		cout<<"Enter name: ";
		cin>>arr1[i];
		
		cout<<"Enter Roll No:";
		cin>>arr2[i];
		cout<<"Enter Course:";
		cin>>arr3[i];
		cout<<"Enter Class: ";
		cin>>arr4[i];
		cout<<"Enter Contact No: ";
		cin>>arr5[i];
		cout<<"--------------------------------------------------------------------------------------"<<endl;
	}
}
else{	
        for(int i=total;i<total+a;i++)
		{
	
		cout<<"\nEnter the record of the student: "<<i+1<<endl;
		cout<<"Enter name: ";
		cin>>arr1[i];
		cout<<"Enter Roll No:";
		cin>>arr2[i];
		cout<<"Enter Course:";
		cin>>arr3[i];
		cout<<"Enter Class: ";
		cin>>arr4[i];
		cout<<"Enter Contact No: ";
		cin>>arr5[i];
		cout<<"--------------------------------------------------------------------------------------"<<endl;
			
  }

  total=total+a;
 }
}
void display()
{
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	if(total==0){
		cout<<"No data is entered."<<endl;
		cout<<"--------------------------------------------------------------------------------------"<<endl;
	}
	else{
	
	for(int i=0;i<total;i++)
	{

		cout<<"\nRecord of student: "<<i+1<<endl;
		cout<<"Name: "<<arr1[i]<<endl;
		cout<<"Roll No:"<<arr2[i]<<endl;
		cout<<"Course: "<<arr3[i]<<endl;
		cout<<"Class: "<<arr4[i]<<endl;
		cout<<"Conatct No: "<<arr5[i]<<endl;
		cout<<"--------------------------------------------------------------------------------------"<<endl;
	}
}
}
void search()
{
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	if(total==0){
		cout<<"No data is entered."<<endl;
		cout<<"--------------------------------------------------------------------------------------"<<endl;
	}
	else{
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	string rollno;
	cout<<"Enter Roll No: ";
	cin>>rollno;
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	bool found=false;
	for(int i=0;i<total;i++)
	{
		if(rollno==arr2[i])
		{
		
		cout<<"\nRecord of student: "<<i+1<<endl;
		cout<<"Name: "<<arr1[i]<<endl;
		cout<<"Roll No:"<<arr2[i]<<endl;
		cout<<"Course: "<<arr3[i]<<endl;
		cout<<"Class: "<<arr4[i]<<endl;
		cout<<"Conatct No: "<<arr5[i]<<endl;
		cout<<"--------------------------------------------------------------------------------------"<<endl;
		found=true;
		break;
		}	
	}
	if(!found)
	{
		cout<<"Record NOT found."<<endl;
		cout<<"\n--------------------------------------------------------------------------------------";
	}
	cout<<endl;
}
}
void update()
{
	cout<<"--------------------------------------------------------------------------------------"<<endl;
		if(total==0){
		cout<<"No data is entered."<<endl;
		cout<<"--------------------------------------------------------------------------------------"<<endl;
	}
	else{
	
	string rollno;
	cout<<"Enter Roll No:";
	cin>>rollno;
	bool found=false;
	for(int i=0;i<total;i++)
	{
		if(rollno==arr2[i])
		{
		cout<<"\nPrevious record of student: "<<i+1<<endl;
		cout<<"Name: "<<arr1[i]<<endl;
		cout<<"Roll No:"<<arr2[i]<<endl;
		cout<<"Course: "<<arr3[i]<<endl;
		cout<<"Class: "<<arr4[i]<<endl;
		cout<<"Conatct No: "<<arr5[i]<<endl;
		cout<<"Enter new record of student"<<endl; 
		cout<<"Enter name: ";
		cin>>arr1[i];
		cout<<"Enter Roll No:";
		cin>>arr2[i];
		cout<<"Enter Course:";
		cin>>arr3[i];
		cout<<"Enter Class: ";
		cin>>arr4[i];
		cout<<"Enter Contact No: ";
		cin>>arr5[i];
		cout<<"--------------------------------------------------------------------------------------"<<endl;
		found=true;
		break;
		}
	}
	if(!found)
	{
		cout<<"Record NOT found.";
		cout<<"--------------------------------------------------------------------------------------"<<endl;
	}
	cout<<endl;
}
}
void deleterecord()
{
	cout<<"--------------------------------------------------------------------------------------"<<endl;
		if(total==0){
		cout<<"No data is entered."<<endl;
		cout<<"--------------------------------------------------------------------------------------"<<endl;
	}
	else{

	int a;
	cout<<"To delete FULL record PRESS 1."<<endl;
	cout<<"To delete SPECIFIC record PRESS 2."<<endl;
	cin>>a;
	cout<<"--------------------------------------------------------------------------------------"<<endl;
	if(a==1)
	{
		total=0;
		cout<<"All record DELETED."<<endl;
		cout<<"--------------------------------------------------------------------------------------"<<endl;
	}
	else if(a==2)
	{
		string rollno;
		cout<<"Enter Roll No: "<<endl;
		cin>>rollno;
		cout<<"--------------------------------------------------------------------------------------"<<endl;
		bool found=false;
		for(int i=0;i<total;i++)
		{
			if(rollno==arr2[i])
			{
				for(int j=i;j<total;j++)
				{
					arr1[j]=arr1[j+1];
					arr2[j]=arr2[j+1];
					arr3[j]=arr3[j+1];
					arr4[j]=arr4[j+1];
					arr5[j]=arr5[j+1];
				}
				total--;
				cout<<"Required record is DELETED..!!"<<endl;
				cout<<"--------------------------------------------------------------------------------------"<<endl;
			    found=true;
		        break;
			}
		
		}
		if(!found)
		{
			cout<<"Record NOT found."<<endl;
			cout<<"--------------------------------------------------------------------------------------"<<endl;
		}
	}
	else{
		cout<<"Please select the valid option."<<endl;
		cout<<"--------------------------------------------------------------------------------------"<<endl;
	}
}
}
int main()
{
	ifstream inFile("students.txt");
	string line;
	total=0;
	while(getline(inFile,line)){
		stringstream ss(line);
		getline(ss, arr1[total], ',');
        getline(ss, arr2[total], ',');
        getline(ss, arr3[total], ',');
        getline(ss, arr4[total], ',');
        getline(ss, arr5[total], ',');
        total++;
	}
	inFile.close();
	ofstream outFile;
	cout<<"-----------------------------Student Management System--------------------------------"<<endl;
	int c;
	while(true)
	{
		cout<<"Press 1 to Add Student Record"<<endl;
		cout<<"Press 2 to Display Student "<<endl;
		cout<<"Press 3 to Search Student"<<endl;
		cout<<"Press 4 to Update Student Record"<<endl;
		cout<<"Press 5 to Delete Student Record"<<endl;
		cout<<"Press 6 to Exit."<<endl;
		cout<<"--------------------------------------------------------------------------------------"<<endl;
		cout<<"Select your option:";
		cin>>c;
		switch(c)
		{
			case 1:
				add();
				break;
	        case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
				update();
				break;
			case 5:
				deleterecord();
				break;
			case 6:
				outFile.open("students.txt");
				for(int i=0;i<total;i++){
					outFile<<arr1[i]<<","<<arr2[i]<<","<<arr3[i]<<","<<arr4[i]<<","<<arr5[i]<<endl;
				}
				outFile.close();
				cout<<"Exiting......."<<endl;
				return 0;
				default:
				cout<<"Please select the valid option."<<endl;
				break;
		}
	
		}
	}

