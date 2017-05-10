#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
using namespace std;
struct users{
	int type;
	char uid[30],upswd[20];

}ob;
	//void getdata();
	//void displaydata();

	int check(char c[])
	{ if(strcmp(ob.uid,c)==0)
	    {	return(1); }
	   else
	    {	return(0); }
	}
	

	void displaydata()
	{
	cout<<"\n"<<ob.uid;
	}

	void getdata()
	{
			int i=0;
			char ch,n;

		cout<<"\nEnter the email id:";
		cin>>ob.uid;
		cout<<"\nEnter the type(0 => Editor(who can add/delete the content) 1 => Employee (who can only add the content)):";
		cin>>ob.type;
		cout<<"\nEnter the passowrd:";
			while(1)
			{
			ch=getche();

		if(isalnum(ch))
				{
		       cout<<"\b*";
			ob.upswd[i++]=ch;
				}

		else if(ch=='\b')
				{
			cout<<" \b";
			ob.upswd[--i]=ch;
				}

		else    {//j=a[--i]-'0';

			 ob.upswd[i]='\0';
			break;
			 }

			}//end of while

	}//get data.
	void create();
	void Delete();
	void display();
	void modify();

	int main()
	 {

			//remove("users.dat");
			system("cls");

		char choice;

		while(1)
	       {

		//clrscr();
		system("cls");
		cout<<"\n DIGITALPEDIA ADMIN";
		cout<<"\n 1.Add a user\n";
		cout<<"\n 2.delete a user\n";
		cout<<"\n 3.modify a user\n";
		cout<<"\n 4.display all user\n";
		cout<<"\n 5.exit\n";
		cout<<"\n Enter the choice:";
		choice=getche();

		switch(choice)
			{

			case '1': create();
			break;

			case '2': Delete();
			break;

			case '3': modify();
			break;

			case '4': display();
			break;

			default: return(0);

			}//switch
		}//while
	       }//main

	void create()
	{
	ofstream pt;

		       pt.open("users.dat",ios::binary|ios::app);


			getdata();
			pt.write((char*)&ob,sizeof(ob));
			pt.close();
		     }//Create

	   void modify()
	   {       char id[30],ch;

		   int flag=0;
		   fstream pt("users.dat",ios::binary|ios::in|ios::out);
		     cout<<"\n Enter the user id to be modified\n";
		     cin>>id;
		      //	 pt.seekg(0);
		     while((pt.read((char*)&ob,sizeof(ob))!=NULL) && (flag==0))
		     {    //pt.read((char*)&ob,sizeof(ob));
		   //   cout<<"\n n";
		     if(check(id)==1)
		     {  flag=1;
				getdata();

			      long int pos=(-1)*sizeof(ob);
			  pt.seekp(pos,ios::cur);
			  pt.write((char*) &ob, sizeof(ob));
		     }


		     }//while
		 if(flag!=1)
		     {
		     cout<<"\n User not modified";
		     getch();
		     }

		else{
			cout<<"\n User modified";
		     getch();
		     }
			pt.close();

	   }//modify

	   void Delete()
		{
		int flag=0;
		 ifstream pt1("users.dat",ios::in|ios::binary);
		 if(pt1==NULL)
		 {
		 cout<<"\n File cant open\n";
		 getch();
		 return;
		 }
		 ofstream pt2("temp.dat",ios::out|ios::binary);
		 char id[30];

		     cout<<"\n Enter the user id to be deleted\n";
		     cin>>id;
		     while(pt1.read((char*)&ob,sizeof(ob))!=NULL)
		     {

		     if(check(id)!=1)
		     { // flag=1;
		      pt2.write((char*)&ob,sizeof(ob));
		     continue;
		     }
		    // pt2.write((char*)&ob,sizeof(ob));
		    flag=1;
		     }//while
		     if(flag==0)
		     {
		     cout<<"\n User not found";
		     getch();
		     }
		     else{
		     cout<<"\nUser Deleted";}
		     getch();
		     pt1.close();
		     pt2.close();
		     remove("users.dat");
		     rename("temp.dat","users.dat");
		      }

		    void display()
		    { int i=0;
		      ifstream pt("users.dat",ios::binary|ios::in);
		       if(pt==NULL)
		       {
		       cout<<"\n File Empty\n";
		       getch();
		       return;
		       }
		while((pt.read((char*)&ob,sizeof(ob)))!=NULL)
		{i=1;

		displaydata();
		}
		  if(i==0)
		  {
		cout<<"file Empty ";
		getch();
		}
		getch();
		pt.close();
		}//display
