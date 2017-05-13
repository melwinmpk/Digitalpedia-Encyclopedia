#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;

		struct users{							
						int type;
						char uid[30],upswd[20];
					}ob,us;
		struct content							
					{
		    			char conten[500],author[30],subhead[40];
					};
		struct con{
					char name[40]; 
				  }e,n,m;						

		class data{
						protected:
							content co;
		     						
						public:
									void search(char s[],int t=2);
									void list();
									void didyoumean(char c[]);
									inline void link(char head[])
									{		char a[]=".txt",b[]="Library/";
											strcat(head,a);
											strcat(b,head);
											strcpy(head,b);
									}
							
			  		};

		class editor:public data					//the data class is publically inherited to editor.
					{
				       int type;
						public: editor(int a=2)		//paramaterised constructor.
								{type=a;}			
					 			void menu();
					 			void add();
					 			void modify();
					 			void Delete();
					 			void listd(char b[]);
					 			void listdel(char a[]);
					 			int subhead(char head[]);
				    };
				    
				    void line()
				    { for(int i=0;i<80;i++)
				    	{cout<<"=";}
				    	cout<<"\n";
					}
				    
				    void editor::menu()
				    { 	system("cls");
				    	line();
				    	cout<<"<<<<<<<<<<<<<<<<<<<<<<Digitalpedia>>>>>>>>>>>>>>>>>>> \n";
				    	cout<<" ========== Welcom "<<us.uid<<" ========"<<endl;
				    	line();
				    	char ch,ch1[40];
						cout<<"\n  1.search\n  2.list\n  3.add\n  4.modify\n";
						if(us.type==0)
						{cout<<"  5.Delete";}
						cout<<"\n  0.logout";
						cout<<"\nEnter the choice:";
						
						ch=getche();
						
						switch(ch)
						{
							case '1': 	cout<<"\n Enter the word to be searched:";
										cin>>ch1;
										search(ch1,us.type);
										break;
							case '2':	list();
										break;
							case '3':	add();
										break;
							case '4':	modify();
										break;
							case '0':   int main();
										return;
										break;			
							case '5':
										if(us.type==0)
										{ Delete();
										}
										else{ return;
										}
										break;
																				
											}
											getchar();
											menu();				    
				    	
					}
					void editor::add()
					{		system("cls");
							char ch,h[20],head[20];
							int i=0,flag=0;
							line();
							cout<<"\n Enter the term which is to be entered:";
							cin>>head;
							getchar();
							strcpy(h,head);
							link(head);									//to make a link to liberary folder.
							ifstream check(head,ios::binary|ios::in);	//it is to check weather the file is aldready exist or not so as per to add in the list.
				
									if(check==NULL)
									{
										flag=1;
										check.close();
									}
									check.close();
									
							ofstream disp(head,ios::binary|ios::app);
							
							cout<<"\t\t"<<h;
								while(1)
										{
											
											cout<<"\n Enter the sub heading(Enter \"#\" to end of the sub heading ):";
											i=0;
											while((ch=getchar())!='#')
											{ 				
											             if(ch=='\b')
																{
																	cout<<" \b";
																	co.subhead[--i]=ch;
																}
														 if(ch=='/')
													 			{	
													 				co.conten[i++]=ch;
													 				ch=getchar();
													 				if(ch=='#')
													 				{
													 	 				co.subhead[--i]=ch;
														 			}
													 			}	
															  
											 				 co.subhead[i++]=ch;
											}
											co.subhead[i]='\0';
											i=0;
											getchar();
										
											cout<<"\n Enter the content (Enter \"#\" to end of the Content )\n";
							
											while((ch=getchar())!='#')
												{   
													if(i>=500)
													{
														break;
													 } 
													 if(ch=='/')
													 {	co.conten[i++]=ch;
													 	ch=getchar();
													 	if(ch=='#')
													 	{
													 	 	co.subhead[--i]=ch;
														 }
													 }
													if(ch=='\b')
														{
															cout<<" \b";
															co.subhead[--i]=ch;
														}
													 
														 
													co.conten[i++]=ch;
												}
												
												co.conten[i]='\0';
												getchar();
											
							
											cout<<"\n Do you want to save it (y/n):";
											
											ch=getchar();
											getchar();
											if(ch=='y'||ch=='Y')
													{			strcpy(co.author,ob.uid);
																disp.write((char*)&co,sizeof(co));
																if(flag==1)
																{
																	listd(h);
																	flag=0;
																}
																
													}
											line();
											cout<<"\n Do you want to add the new content in same topic (y/n):";
											ch=getchar();
											getchar();
											if(ch=='y'||ch=='Y')
													{
													continue;	
													}
											else{
													disp.close();
														break;
											}		
													
										}	
					}
					void editor::Delete()
					{	system("cls");
						char ch,head[20],h[20];
						int i=0,flag=0,d=0,option,x=0;
						line();
						cout<<"\t\t\t Delete Menu\n";
						line();
						cout<<" 1.Delete entire file"<<"\n 2.Delete a content in file"<<"\n Enter the choice:";
						ch=getche();
						if(ch!='1'&&ch!='2')
						{	cout<<"\n wrong input....";
							getch();
							return;
						}
						cout<<"\n Enter the name of the file :";
				  		cin>>head;
				  			strcpy(h,head);
							link(head);
							ifstream check(head,ios::binary|ios::in);
						if(check!=NULL)
						{
							flag=1;	
						}
							if(flag==0)
							{
								cout<<"\n File not found";
								getch();
								return;	
							}
							check.close();
						
				

							switch(ch)
							{
								case '1': 			remove(head);
													listdel(h);
														cout<<"\n File deleted\n";
															line();
														getch();
										  			
													break;
								case '2': 			
													if((x=subhead(head))==1)
													{	return;
													}
													cout<<"\n Enter the no which is to be deleted:";
													cin>>option;
													i=0;
													ifstream fp(head,ios::binary|ios::in);
													ofstream pt("temp.txt",ios::binary|ios::out);
													while((fp.read((char*)&co,sizeof(co)))!=NULL)
													{	++i;
													if(i!=option)
													{	flag=1;
														pt.write((char*)&co,sizeof(co));
													}
														
													}
													pt.close();
													fp.close();
													remove(head);
													rename("temp.txt",head);
													if(flag==0)
													{ cout<<"\n Content not found.........\n";
														line();
														getch();
														return;
													}
													cout<<"\n Content deleted.......\n";
													line();
													getch();
													
													
													
							}
						
					}
					void data::didyoumean(char c[])
					{
						char name[40],*list[40];
						strcpy(name,c);
					    int i=1,count=1,j=0,k=1,l=0;
					    	fstream fp("List.txt",ios::in);
					    	
					    	while((fp.read((char*)&e,sizeof(e)))!=NULL)
					    	{   
					    		i=0;l=0;count=0;
					    	
					    						
					    		while(i<=strlen(e.name) && name[i]!='\0')
					    			{    
					    				if(e.name[l]==name[i])
										{
										count++;i++;l++;
										continue;
													}
										if((name[i]==e.name[l+1]))
										{ 
											count++;i++;l+=2;
											continue;
																}
							/*				if((name[i+1]==e.name[l]))
										{ 
											count++;l++;i+=2;
											continue;
																}				*/		
																i++;l++;						
									}
					    				
								
								
					    		if(((count*100)/strlen(e.name))>=50)
					    		{ // cout<<"\n"<<count;
					    		//cout<<strlen(e.name)<<"\t"<<count<<endl;
					    			list[j]= new char[40];
					    			strcpy(list[j],e.name);
					    			++j;
								}
							}
							if(j==0)
							{ cout<<"\n Match not found....";
								getch(); 
								return;
							}
							cout<<"\n not found\n DO you mean";
							i=0;
							while(i<j)
							{cout<<"\n"<<k++<<":"<<list[i++];
							}
							cout<<"\n Select the choice:";
							cin>>i;
							getch();
							i--;
							if(i>=0 && i<j){
							
							strcpy(name,list[i]);
							
  						//	delete [] list;
  							fp.close();
							search(name,us.type);
							return;}
							else{
									delete [] list;
									fp.close();
								cout<<"\n NOT found.........";
								getch();
								return;
							}
					}
					void data::list()
					{		system("cls");
							int k=0;
									fstream pt("list.txt",ios::in);
									line();
									while((pt.read((char *)&e,sizeof(e)))!=NULL)
										{
											cout<<++k<<":"<<e.name<<endl;
										}
										line();
										getch();
					}
					void editor::listd(char ch[])
					{	
						long int a=sizeof(e);
						strcpy(n.name,ch);
						
						int count=0,i=0;	
						long int z=(-1)*a;
					    char choice='y';
					    fstream fp;
					    while(n.name[i]!='\0')
					    {
					    	if(isupper(n.name[i]))
					    	{ n.name[i]=tolower(n.name[i]);
							}
							i++;
						}
					     fp.open("List.txt",ios::binary|ios::in|ios::out);

						if(fp==NULL)
						{
							fp.close();
						fp.open("List.txt",ios::binary|ios::out);	
						
								    fp.write((char*)&n,sizeof(n));
								    fp.close();
								    return;
						
						
						}

									  while((fp.read((char*)&e,sizeof(e)))!=NULL)
									 {
									
									if(strcmp(e.name,n.name) > 0){ 
									
									   m=e;

									 fp.seekp(z,ios::cur);
										fp.write((char*)&n,sizeof(n));
									 fp.seekp(z,ios::cur);

									      n=m;

									}
							    
								}   
								fp.close();
								fp.open("List.txt",ios::binary|ios::app);
									fp.write((char*)&n,sizeof(n));

									 fp.close();
									    

					}
					void editor::listdel(char a[])
					{
						strcpy(n.name,a);
						int flag=0;
						 ifstream pt1("list.txt",ios::in|ios::binary);
						 if(pt1==NULL)
						 {
						 cout<<"\n File cant open\n";
						 getch();
						 return;
						 }
						 ofstream pt2("temp.txt",ios::out|ios::binary);

						     while(pt1.read((char*)&e,sizeof(e))!=NULL)
						     {
				
						     if(!(strcmp(n.name,e.name)==0))
						     { // flag=1;
						      pt2.write((char*)&e,sizeof(e));
						     continue;
						     }
						    // pt2.write((char*)&ob,sizeof(ob));
						    flag=1;
						     }//while
						     
						     
						     getch();
						     pt1.close();
						     pt2.close();
						     remove("List.txt");
						     rename("temp.txt","List.txt");
							
					}
					int editor::subhead(char head[])
					{	int i=0;
						ifstream fp(head,ios::binary|ios::in|ios::out);
							if(fp==NULL)
							{
								cout<<"\n File not found!.........";
								getch();
								return(1);
							}
							while((fp.read((char*)&co,sizeof(co)))!=NULL)
							{
								cout<<"\n"<<++i<<":"<<co.subhead;
							}
							fp.close();
							return(0);
					}
					void editor::modify()
					{		system("cls");
							char ch,head[20],h[20];
							int i=0,flag=0,d=0,option,e=0,x=0;
								long int pos=sizeof(co);
								pos=(-1)*pos;
								line();
								
						cout<<"\t\t\t Modify\n";
						line();
							cout<<"\n Enter the name of the file :";
							cin>>head;
				  			getchar();
				  			strcpy(h,head);
							link(head);
							if((x=subhead(head))==1)
							{	return;
							}
							
							//fp.seekg(0);
							cout<<"\n Enter the no which is to be modified:";
							cin>>option;
							getchar();
							e=0;flag=0;
							fstream pt(head,ios::binary|ios::in|ios::out);
							while((pt.read((char*)&co,sizeof(co)))!=NULL)
							{	++e;
							if(e==option)
							{  flag=1;
									cout<<"\n Enter the sub heading:";
					i=0;
					while((ch=getchar())!='#')
					{ 				
					             if(ch=='\b')
										{
											cout<<" \b";
											co.subhead[--i]=ch;
										}
								 if(ch=='/')
							 			{	
							 				co.conten[i++]=ch;
							 				ch=getchar();
							 				if(ch=='#')
							 				{
							 	 				co.subhead[--i]=ch;
								 			}
							 			}	
									  
					 				 co.subhead[i++]=ch;
					}
					co.subhead[i]='\0';
					i=0;
					getchar();
				
					cout<<"\n Enter the content\n";
	
					while((ch=getchar())!='#')
						{   
							if(i>=500)
							{
								break;
							 } 
							 if(ch=='/')
							 {	co.conten[i++]=ch;
							 	ch=getchar();
							 	if(ch=='#')
							 	{
							 	 	co.subhead[--i]=ch;
								 }
							 }
							if(ch=='\b')
								{
									cout<<" \b";
									co.subhead[--i]=ch;
								}
							 
								 
							co.conten[i++]=ch;
						}
						
						co.conten[i]='\0';
						getchar();
					
	 
						
							  pt.seekp(pos,ios::cur);
							  pt.write((char*)&co, sizeof(co));
						}
								
							}
							pt.close();
							if(flag==0)
							{ cout<<"\n Content not found.............\n";
								line();
								getch();
								return;
							}
							
								cout<<"\n Data is modified sucessfully....\n";
								line();
								getch();
							
							
					}
					void data::search(char head[],int t)
					{
									char ch,h[20];
									 int i=0,type=t;
									 
									strcpy(h,head);
									link(head);
									ifstream disp(head,ios::binary|ios::in);
									
										if(disp==NULL)
										{
											   while(h[i]!='\0')
												    {
												    	if(isupper(h[i]))
												    	{ h[i]=tolower(h[i]);
														}
														i++;
													}
											didyoumean(h);
											getch();
											return;
											
										}
											cout<<"\t\t\t"<<h<<endl;
										while((disp.read((char*)&co,sizeof(co)))!=NULL)
											{
												cout<<"\n"<<co.subhead<<": \n";
												cout<<co.conten<<endl;
												if(type==0)
												{cout<<"Given by:"<<co.author<<endl;}
											}
											disp.close();
											line();
											getch();	
					}
					void login()
					{
						int flag1=0,i=0;
						char ch;
					cout<<"\n Enter the usrename:";
					cin>>us.uid;
					
					cout<<"\n Enter the password:";
					
						while(1)
							{
							ch=getche();
				
						if(isalnum(ch))
								{
						       cout<<"\b*";
							us.upswd[i++]=ch;
								}
				
						else if(ch=='\b')
								{
							cout<<" \b";
							us.upswd[--i]=ch;
								}
				
						else    {//j=a[--i]-'0';
				
							 us.upswd[i]='\0';
							break;
							 }
				
							}//end of while
							
							fstream pt;
							pt.open("users.dat",ios::in|ios::out);
							if(pt==NULL)
							{
								cout<<"\n File not open...........";
								getch();
								pt.close();
								return;
							}
							while((pt.read((char *)&ob,sizeof(ob)))!=NULL)
							{
								if(strcmp(ob.uid,us.uid)==0)
								{
								  if(strcmp(ob.upswd,us.upswd)==0)
								  { flag1=1;break;
								  }
								}
							}
							if(flag1==0)
							{ cout<<"\n USER id or password is wrong";
							getch();
								cout<<"\n Do you want to continue(y/n)";
								ch=getchar();
								getch();
								if(ch=='Y'||ch=='y')
								{ 	login(); 
									return;
								}
								return;
							}
						getchar();
						us=ob;
						editor user1(us.type);
						user1.menu();
						return;
					}
					int main()
					{	
						char b,s[20];
						editor user;
						us.type=2;
						while(1)
						{	system("cls");
							line();
							cout<<"<<<<<<<<<<<<<<<<<<<<<<Digitalpedia>>>>>>>>>>>>>>>>>>> \n";
							line();
							cout<<"\n 1:Search"<<"\n 2:list"<<"\n 3.login"<<"\n 4.Exit";
						
							cout<<"\n Enter the choice:";
							b=getche();
							switch(b)
							{
								case '1': cout<<"\nEnter the file to be searched:";
										  cin>>s;
										  //getchar();
											user.search(s);
											break;
								case '2': user.list();
											break;
								case '3': login();
											break;						
								default:	return(0);			
							}
						}
					}
					
		
