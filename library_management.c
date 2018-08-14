// PROJECT ON LIBRARY MANAGEMENT
#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct
{
	int book_no;
	char bok_nam[20];
	char wri_nam[20];
}book;
typedef struct
{
	int stu_id;
	char name[20];
	char dep_nt[20];
}student;
typedef struct
{
	int stu_id;
	int book_no;
	char issue_d[9];
	char submit_d[9];
}library;
void afopen()
{
	FILE *fp1,*fp2,*fp3;
	fp1=fopen("book_file1","ab");
	fp2=fopen("student_file","ab");
	fp3=fopen("issue_return","ab");
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
void add_book()
{
	FILE *fp;
	book b;
	int n,i;
	fp=fopen("book_file1","ab");
	printf("enter no of book detail you want's to enter \n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\nenter book record %d-> no, name , writer\n",i);
		scanf("%d",&b.book_no);
		fflush(stdin);
		gets(b.bok_nam);
		fflush(stdin);
		gets(b.wri_nam);
		fwrite(&b,sizeof(b),1,fp);
		printf("\n*************record added**********\n");
	}
		fclose(fp);
}
void traverse_book()
{
	FILE *fp;
	book b;
	fp=fopen("book_file1","rb");
	if(fp==NULL)
	{
		printf("\nunable to open file\n");
		return;
	}
	while(fread(&b,sizeof(b),1,fp))
	printf("\n%6d%30s%30s",b.book_no,b.bok_nam,b.wri_nam);
	fclose(fp);
}
void update_book()
{
	FILE *fp;
	book b;
	int no;
	fp=fopen("book_file1","rb+");
	if(fp==NULL)
	{
		printf("\n unable to open file \n");
		return;
	}
	printf("enter book number to be updated \n");
	scanf("%d",&no);
	while(fread(&b,sizeof(b),1,fp))
	{
		if(no==b.book_no)
		{
			printf("\nenter book detail->book name, writer\n");
			fflush(stdin);
			gets(b.bok_nam);
			fflush(stdin);
			gets(b.wri_nam);
			fseek(fp,-(long int)sizeof(b),1 );
			fwrite(&b,sizeof(b),1,fp);
			printf("\nrecord updated\n");
			fclose(fp);
			return;
		}
	}
	printf("book no does'nt exist\n");
}
void search_book()
{
	FILE *fp;
	book b;
	int no;
	fp=fopen("book_file1","rb");
	if(fp==NULL)
	{
		printf("\n unable to open file \n");
		return;
	}
	printf("\n enter book no to be search \n");
	 scanf("%d",&no);
	while(fread(&b,sizeof(b),1,fp))
	{
		if(no==b.book_no)
		{
			printf("\n book is available in library \n");
			printf("\n %6d%20s%20s\n",b.book_no,b.bok_nam,b.wri_nam);
			fclose(fp);
			return ;
		}
	}
	printf("book is not available\n");
	fclose(fp);
}

void add_student()
{
	FILE *fp;
	student s;
	int n,i;
	fp=fopen("student_file","ab");
	printf("\nenter no of student record you want's to add\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("enter student record %d->id,name,department\n",i);
		scanf("%d",&s.stu_id);
		fflush(stdin);
		gets(s.name);
		gets(s.dep_nt);
		fwrite(&s,sizeof(s),1,fp);
		printf("\n************record added*********\n");
	}
	fclose(fp);
}
void traverse_student()
{
	FILE *fp;
	student s;
	fp=fopen("student_file","rb");
	if(fp==NULL)
	{
		printf("unable to open fife");
		return;
	}
	while(fread(&s,sizeof(s),1,fp))
	{
		printf("\n%6d%30s%30s",s.stu_id,s.name,s.dep_nt);
	}
	fclose(fp);
}
void update_student()
{
	FILE *fp;
	student s;
	int n;
	fp=fopen("student_file","rb+");
	if(fp==NULL)
	{
		printf("\n uunable to open file \n");
		return;
	}
	printf("\nenter student id to be updated\n");
	scanf("%d",&n);
	while(fread(&s,sizeof(s),1,fp))
	{
		if(n==s.stu_id)
		{
			printf("\nenter student detail->name , department\n");
			fflush(stdin);
			gets(s.name);
			fflush(stdin);
			gets(s.dep_nt);
			fseek(fp,-(long int)sizeof(s),1);
			fwrite(&s,sizeof(s),1,fp);
			printf("\n *********record updated*********\n ");
			fclose(fp);
			return;
		}
	}

		printf("\n student record not found\n");
		fclose(fp);

}
void search_student()
	{
		FILE *fp;
		student s;
		int n;
		fp=fopen("student_file","rb");
		if(fp==NULL)
		{
			printf("\n unable to open file ");
			return;
		}
		printf("\nenter student id to be search\n");
		scanf("%d",&n);
		while(fread(&s,sizeof(s),1,fp))
		{
			if(n==s.stu_id)
			{
				printf("\n****record found*******\n");
				printf("%10d%30s%5s",s.stu_id,s.name,s.dep_nt);
				fclose(fp);
				return;
			}
		}
		printf("\n*********record not found*********\n");
		fclose(fp);
	}
void delete_student()
{
	FILE *fp1,*fp2;
	student s;
	int  id,flag=0;
	fp1=fopen("student_file" ,"rb" );
	if(fp1==NULL)
	{
		printf("\n unable to open file \n");
		return;
	}
	fp2=fopen("tstudent_file","wb");
	printf("\n enter student id to be deleted \n");
	scanf("%d",&id);
	while(fread(&s,sizeof(s),1,fp1))
	{
		if(id!=s.stu_id)
		{
			fwrite(&s,sizeof(s),1,fp2);
		}
		else
		{
			printf("\n********record deleted*********\n");
			flag=1;
		}
	}
	if(flag==0)
	printf("\n record does  not found\n");
	fclose(fp1);
	fclose(fp2);
	remove("student_file");
	rename("tstudent_file","student_file");
}
void issue_book()
{
	FILE *fp,*fp1,*fp2;
	library l,m;
	book b;
	student s;
	int flag1=0,flag2=0;
	int a=0;
	fp1=fopen("book_file","rb");
	if(fp==NULL)
	{
		printf("file unable to open");
		return;
	}
	fp2=fopen("student_file","rb");
	if(fp2==NULL)
	{
		printf("\nfile unable to open ");
		return;
	}
	fp=fopen("issue_return","rb+");
	if(fp==NULL)
	{
		printf("file unable to open ");
		return;
	}
	printf("\nenter student id ,book no\n");
	scanf("%d%d",&l.stu_id,&l.book_no);
	printf("\n enter issue date in formate dd/mm/yy\n ");
	fflush(stdin);
	gets(l.issue_d);
	strcpy(l.submit_d," ");
	while(fread(&b,sizeof(b),1,fp1))
	{
		if(l.book_no==b.book_no)
		{
			flag1=1; break;

		}
	}
	 while(fread(&s,sizeof(s),1,fp2))
	 {
		if(l.stu_id==s.stu_id)
		{
			flag2=1; break;
		}
	 }
	      if(flag1==1&&flag2==1)
	      {
		while(fread(&m,sizeof(m),1,fp))
		{
			if((l.stu_id==m.stu_id)&&strcmp(m.submit_d," ")==0)
			a++;
		}
		if(a==5)
		printf("\n you already have 5 books we can't issue\n");
		else
		{
			fwrite(&l,sizeof(l),1,fp);
			printf("book issue");
			fclose(fp);
		}
	      }
	      else
	      {
		printf("\nwe can not issue book\n");
		if(flag1==0)
		printf("\n book is not present in library \n");
		if(flag2==0)
		printf("\nstudent data is not add in lib, so please first add your detail\n");
	      }
}
void traverse_issue()
{
	FILE *fp;
	library l;
	fp= fopen("issue_return","rb");
	if(fp==NULL)
	{
		printf("file unable to open ");
		return ;
	}
	while(fread(&l,sizeof(l),1,fp))
	printf("\n%6d%6d%20s%20s",l.stu_id,l.book_no,l.issue_d,l.submit_d);
	fclose(fp);
}
void submit_book()
{
	FILE *fp;
	library l;
	int no;
	fp=fopen("issue_return","rb+");
	if(fp==NULL)
	{
		printf("\n sorry  file does not available\n");
		return ;
	}
	printf("\nenter book number\n");
	scanf("%d",&no);
	while(fread(&l,sizeof(l),1,fp))
	{
		if((no==l.book_no)&&(strcmp(l.submit_d," "))==0)
		{
			printf("\n enter submit date in formate dd/nn/yy");
			fflush(stdin);
			gets(l.submit_d);
			fseek(fp,-(long int)sizeof(l),1);
			fwrite(&l,sizeof(l),1,fp);
			fclose(fp);
			return;
		}
	}
	printf("\nBook Not Found");
}
void main()
{
	int n;
	afopen();
	do
	{
		clrscr();
		printf("\n ***************************MENU********************************\n");
		printf("\n enter\t  1 for issue book");
		printf("\n enter\t  2 for submit book");
		printf("\n *****************book_record******************");
		printf("\n enter\t  3 for add book record");
		printf("\n enter\t  4 for traverse book record");
		printf("\n enter\t  5 for update book record");
		printf("\n enter\t  6 for search book record");
		printf("\n *****************student record***************");
		printf("\n enter\t  7 for add student record ");
		printf("\n enter\t  8 for traverse student record");
		printf("\n enter\t  9 for update student record");
		printf("\n enter\t 10 for search student record");
		printf("\n enter\t 11 for delete student record");
		printf("\n enter\t  12 for traverse issue ");
		printf("\n enter\t ********** 0 for exit *********");
		printf("\n enter your choice     ");
		scanf("%d",&n);


	switch(n)
	{
		case 1:		issue_book();		break;
		case 2: 	submit_book();	 	break;
		case 3: 	add_book();		break;
		case 4:		traverse_book();	break;
		case 5: 	update_book();		break;
		case 6:		search_book();		break;
		case 7:		add_student();		break;
		case 8:		traverse_student();	break;
		case 9:		update_student();	break;
		case 10:        search_student();	break;
		case 11:	delete_student();	break;
		case 12:        traverse_issue();	break;
		case 0: 	printf("************thanks for using**********");
						break;
		default:	printf("\n invalid choice");
	}
	getch();
	}while(n!=0)  ;
}

