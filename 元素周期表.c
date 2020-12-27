/*
	**�����������ݽ���FaithBook-_-���ֹ����� 
	** �������ս���Ȩ�� FaithBook-_-���� 
	** �ļ�����ѧϰ�ο� 
*/


#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<malloc.h>
#include<math.h>
#define LEN sizeof(struct element)
#define WIDTH 78	//���ڿ��    
#define N 118		//Ԫ�ظ��� 


//*************************************************/
//************         ��Ϣ�ļ�       *************/
//*************************************************/
char name_e_filename[]="English_name.FaithBook-_-";						//Ԫ��Ӣ�ķ��� 
char name_c_filename[]="Chinese_name.FaithBook-_-";						//Ԫ�������� 
char weight_filename[]="Weight_of_Element.FaithBook-_-";					//ԭ���� 
char period_filename[]="Period.FaithBook-_-"; 							//���� 
char group_filename[]="group.FaithBook-_-";								//�� 
char valence_filename[]="Valence.FaithBook-_-";							//�������ϼ� 
char property_filename[]="Property.FaithBook-_-";						//���� 
char brief_introduction_filename[]="Breif_introduction.FaithBook-_-";	//Ԫ�����ڱ��� 
char founder_filename[]="Founder.FaithBook-_-";							//Ԫ�����ڱ�ʼ�˼�� 
char x_filename[]="X.FaithBook-_-";										//Ԫ��λ�ã���Ժ����꣩ 
char y_filename[]="Y.FaithBook-_-";										//Ԫ��λ�ã���������꣩ 
char Readme[]="ReadMe.FaithBook-_-";
//*********************************************/
//**************     �ṹ��     ***************/
//*********************************************/
struct element
{
	int num;				//Ԫ����� 
	char C_name[5];			//�������� 
	char E_name[4];			//���� 
	char weight[8];			//ԭ���� 
	char Period;			//���� 
	char Group[6];			//�� 
	char Valence[11];		//�������ϼ� 
	char Property[9];		//���� 
	char adr_x;				//���λ�ã������꣩ 
	char adr_y;				//���λ�ã������꣩ 
	struct element *next;	//�� 
}*h=NULL;					//����ͷָ�� 

//***********************************************/ 
//**************     ��������     ***************/
//***********************************************/

/*******    ��Ҫ���ܺ���   *******/ 
void information_set(void);
char kb_hit(void);
void pause(void);
void printy(char str[]);
void printn(char str[]);
/*******      Ŀ¼������     *******/ 

void Constent(void);
void Constent_print(void); 
void Table(char L);
void table(void);
void find(void);
void version_information(void);
void exit_system(void);
void TXT_READ(char text[],char str[]); 
/*******    Ŀ¼��֧����     *******/
void head_txt(void);
void shadow_txt(void);
void find_table(struct element *P);
void txt_print(FILE *p,char str[]);

//***********************************************/
//**************     ģ�麯��     ***************/
//***********************************************/

/*******    ���д�ӡ������     *******/ 
void printn(char str[])
{
	int length=strlen(str);
	int blank=(WIDTH-length)/2;
	while(blank>0)
	{
		printf(" ");
		blank--;
	}
	printf("%s",str);
}
/*******    ���д�ӡ����     *******/ 
void printy(char str[])
{
	printn(str);
	printf("\n");
}
/*******    ��Ϣ��ʼ��     *******/ 
void  information_set(void)
{
	//�ļ�ָ�� 
	FILE *e_name,*c_name,*ele_weight,*period,*group,*valence,*property,*px,*py;	
	//���ļ���ز������� 
	if(
		(e_name=fopen(name_e_filename,"r"))==NULL||
		(c_name=fopen(name_c_filename,"r"))==NULL||
		(ele_weight=fopen(weight_filename,"r"))==NULL||
		(period=fopen(period_filename,"r"))==NULL||
		(group=fopen(group_filename,"r"))==NULL||
		(valence=fopen(valence_filename,"r"))==NULL||
		(property=fopen(property_filename,"r"))==NULL||
		(py=fopen(y_filename,"r"))==NULL||
		(px=fopen(x_filename,"r"))==NULL)
		{	
			printf("�ļ���ʧ�ܣ�����");
			exit(0); 
			return ; 
		}

	int n;
	struct element *p1,*p2;
	p1=p2=(struct element*)malloc(LEN);		//�����ռ� 
	p2=h;			//ָ��ͷָ�� 
	for(n=1;n<=N;n++)		//��ÿ��Ԫ�ؽ���ͬ������Ϣ��ʼ������ 
	{
		//��ʼ������ 
		int i;
		char ch;
		p1->num=n;
		
		//Ӣ������
		i=0; 
		while((ch=fgetc(e_name))!='\n')
		{
			p1->E_name[i]=ch;
			i++;
		}
		for(;i<4;i++)
			p1->E_name[i]='\0';
		
		//�������� 
		i=0;
		while((ch=fgetc(c_name))!='\n')
		{
			p1->C_name[i]=ch;
			i++;
		}
		for(;i<5;i++)
			p1->C_name[i]='\0';
			
		//ԭ���������
		i=0;
		while((ch=fgetc(ele_weight))!='\n')
		{
			p1->weight[i]=ch;
			i++;
		}
		for(;i<8;i++)
			p1->weight[i]='\0';
		
		//����
		p1->Period=fgetc(period);
		fgetc(period);
		
		//�� 
		i=0;
		while((ch=fgetc(group))!='\n')
		{
			p1->Group[i]=ch;
			i++;
		}
		for(;i<6;i++)
			p1->Group[i]='\0';
		
		//�������ϼ� 
		i=0;
		while((ch=fgetc(valence))!='\n')
		{
			p1->Valence[i]=ch;
			i++;
		}
		for(;i<11;i++)
			p1->Valence[i]='\0';
		
		//����
		i=0;
		while((ch=fgetc(property))!='\n')
		{
			p1->Property[i]=ch;
			i++;
		}
		for(;i<9;i++)
			p1->Property[i]='\0';
		
		//y
		p1->adr_y=fgetc(py);
		fgetc(py);
		
		//x
		p1->adr_x=fgetc(px);
		fgetc(px);
		
		//�������� 
		if(n==1)
		{
			h=p1;
		}
		else
		{
			p2->next=p1;	
		}
		p2=p1;
		p1=(struct element*)malloc(LEN);
	}	
	//�ر���Ϣ�ļ� 
	fclose(e_name);
	fclose(c_name);
	fclose(ele_weight);
	fclose(period);
	fclose(group);
	fclose(valence);
	fclose(property);
	fclose(px);
	fclose(py);
}
/************     �б��ӡ����     ***************/ 
void table(void)
{
	system("cls");		//���� 
	struct element *p;	//�ṹ��ָ�� 
	p=h;
	head_txt();			//��ͷ 
	
	//������Ϣ 
	do
	{
		if(p->num%15==1&&p->num!=1)
		{
			shadow_txt();
			pause();
			system("cls");
			head_txt();	
		}
		printf("       |=====|====|======|=========|====|=======|============|==========|\n"); 	
		printf("       | %-4d| %-3s|  %-4s|%8s |  %c | %5s | %10s | %8s |\n",p->num,p->E_name,p->C_name,p->weight,p->Period,p->Group,p->Valence,p->Property);
		p=p->next;
	}while(p!=NULL);
	shadow_txt();		//��β 
}

/************     ��ͷ��ӡ����     ***************/ 
void head_txt(void)
{
	printf("       |================================================================|\n"); 	
	printf("       |                          3 Ԫ�ػ�����Ϣ                        |\n");
	printf("       |=====v====v======v=========v============v============v==========|\n"); 	
	printf("       |��� | Ӣ |  ��  |  ԭ���� |����|   ��  | �������ϼ� |   ����   |\n"); 	
}
/************     ��β��ӡ����     ***************/ 
void shadow_txt(void)
{
	printf("       |=====^====^======^=========^====^=======^============^==========|\n"); 	//v
}

int txt_num;	//������������

/***********    �ı���Ϣ��ӡ����    ***************/ 
void txt_print(FILE *p,char str[])
{	while(!feof(p))
	{
		if(txt_num==0)		//�����ӡ 
		{
			printy("|=====================| "); 	
			printf("                           |  %16s |\n",str);
			printy("|=====================|"); 
			printf("\n");
		}
		//���ݴ�ӡ 
		printf("%c",fgetc(p));
		txt_num++;
	} 
}
/************     ��ѯ����     ***************/ 
void find(void)
{
	int i,sum=0;
	char str[9]="\0\0\0\0\0\0\0\0\0";		//��Ϣ��ʼ�� 
	struct element *p=h;
	system("cls");
	printf("\n\n\n");
	printy("4 ��Ϣ��ѯ��");
	printf("\n\n"); 
	printy("��������Ҫ��ѯ����Ϣ");
	printy("������Ԫ����š���Ӣ�����ơ�Ԫ�����ڡ��塢�������ϼۼ�������");
	printn(":  ");
	scanf("%s",str);
	
	//������������ת�� 
	for(i=strlen(str)-1;i>=0;i--)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			sum+=((str[i]-48)*pow(10,strlen(str)-i-1)) ;
		}
		else break;
	}
	if(i<0)	
	{
		i=0;		//��ѯ��Ԫ������ 
		do
		{
			if(sum==p->num||(strlen(str)==1&&str[0]==p->Period))				//��������ڶԱ� 
			{
				if(i==0)
				{
					printf("\n\n");
					printy("��ѯ���");
					printf("\n");
					head_txt(); 
				}
				printf("       |=====|====|======|=========|====|=======|============|==========|\n"); 	
				printf("       | %-4d| %-3s|  %-4s|%8s |  %c | %5s | %10s | %8s |\n",p->num,p->E_name,p->C_name,p->weight,p->Period,p->Group,p->Valence,p->Property);
				i++;
			}
			p=p->next;
		}while(p!=NULL);
		if(i!=0)shadow_txt();		//��β��ӡ 
	}else
	{
		i=0;
		do
		{
			if(strcmp(str,p->E_name)==0||strcmp(str,p->C_name)==0||strcmp(str,p->Group)==0||strcmp(str,p->Property)==0)			//������� 
			{
							//������&&Ӣ�ķ���&&��&&���ʶԱ� 
				if(i==0)
				{
					printf("\n\n");
					printy("��ѯ���");
					printf("\n");
					head_txt(); 
				}
				printf("       |=====|====|======|=========|====|=======|============|==========|\n"); 	
				printf("       | %-4d| %-3s|  %-4s|%8s |  %c | %5s | %10s | %8s |\n",p->num,p->E_name,p->C_name,p->weight,p->Period,p->Group,p->Valence,p->Property);
				i++;
			}
			p=p->next;
		}while(p!=NULL);
		if(i!=0)shadow_txt();
	}
	if(i==0)		//δ��ѯ������ 
	{
		printf("\n");
		printy("δ��ѯ�������Ϣ"); 
	}
	else return ;
}
/************     ��ѯ�����ӡ����     ***************/ 
void find_table(struct element *p)
{
	printf("\n\n");
	printy("��ѯ���");
	printf("\n");
	head_txt();
	printf("       |=====|====|======|=========|====|=======|============|==========|\n"); 	
	printf("       | %-4d| %-3s|  %-4s|%8s |  %c | %5s | %10s | %8s |\n",p->num,p->E_name,p->C_name,p->weight,p->Period,p->Group,p->Valence,p->Property);
	shadow_txt();
	printf("\n");
	printy("��ѯ��ϣ�");
}

/************     ������������     ***************/ 
void TXT_READ(char text[],char str[])
{
	FILE *p;
	if((p=fopen(str,"r"))==NULL)
	{
		printf("%s��ʧ��",str);
		return ;
	}
	system("cls");	//���� 
	printf("\n\n");
	txt_num=0;
//	txt_print(p,"");	//�ı���Ϣ��ӡ�������� 
	txt_print(p,text);	//�ı���Ϣ��ӡ�������� 
	fclose(p);
}

/************     ͣ�ٺ���     ***************/ 
void pause(void)
{
	//���˻س�����������������Ӧ 
	printf("\n\n");
	printy("��Enter����...");
	while(1)
	if(kbhit())	//�м��̲��� 
	{
		char ch=getch();
		if(ch==13)		//����س�����ѭ������������ 
			return; 
	}
}
/************     ϵͳ�˳�����     ***************/ 
void exit_system(void)
{
	system("cls");
	printf("\n\n\n\n");
	printy("��ӭʹ�ã���!");
	printy("FaithBook-_-������ģ�"); 
	printf("\n\n");
	printf(" ������������������������)\n");
	printf("  �ף���׵������Ŷ��    )\n");
	printf(" �����ţ�����������������\n\n");
	printf("     ( O - O ) balalala~\n");
	printf("�� ��������    '\'\n");
	printf("  /������  ��  ��'\'\n");
	printf("/�� /  ����   '\'   '\' \n");
	printf("|��/�� ������  '\'��|\n");
	printf(" '\'?��������     ?/\n");
	printf("  ��?����    �D��\n");
	printf("�� '\'����/'\'��  /\n");
	printf("��   �ᡡ   ��\n");
	pause();
	exit(0) ;//�˳����� 
}
/************     ���̷���ֵ����     ***************/ 
char kb_hit(void)
{
	while(1)
		if(kbhit())
		{
			char ch=getch(); 
			if(ch>='0'&&ch<='8')		//��Ч������ϢΪ��0��~��7�� 
				return (ch);
		}
}
/************     Ŀ¼��Ϣ��ӡ����     ***************/ 
void Constent_print(void)
{
	printy("Ԫ�����ڱ�"); 
	printy("* 1 Ԫ�����ڱ�Ӣ��  *");
	printy("* 2 Ԫ�����ڱ��У�  *");
	printy("* 3 Ԫ�ػ�����Ϣ��    *"); 
	printy("* 4 Ԫ�ز�ѯ          *"); 
	printy("* 5 Ԫ�����ڱ���    *");
	printy("* 6 ���ڱ�ʼ�˼��  *");
	printy("* 7 ��������          *"); 
	printy("* 8 �汾��Ϣ          *"); 
	printy("* 0 �˳�              *");
}
/************     Ŀ¼����     ***************/ 
void Constent(void)
{
	system("cls");
	Constent_print();	//��ӡĿ¼ 
	switch(kb_hit())
	{
		//��Ӧ���� 
		case '1':Table('E');break;
		case '2':Table('C');break;
		case '3':table();break;
		case '4':find();break;
		case '5':TXT_READ(" 5 Ԫ�����ڱ��� ",brief_introduction_filename);break;
		case '6':TXT_READ("6 ���ڱ�ʼ�˼��",founder_filename);break;
		case '7':TXT_READ("    7 �����ļ�    ",Readme);break;
		case '8':version_information();break;
		case '0':exit_system();break;
	}
	pause();	//ͣ�ٺ��� 
	Constent();	//�����ݹ飬����ѭ�� 
	return ;
} 
/************     �汾��Ϣ��ӡ     ***************/ 
void version_information(void)
{
	system("cls");
	printf("\n\n\n\n");
	printy("**  8 �汾��Ϣ  **"); 
	printy("*---------------------------*");
	printy("*    �汾����: 2018\\2\\8     *");
	printy("*   �����ˣ� FaithBook-_-    *");
	printy("*  ���䣺1203339302@qq.com  *");
	printy("*---------------------------*");
}
/************     Ԫ�����ڱ��ӡ����     ***************/ 
void Table(char L)
{
	int x,y,i,j,sm=4,ym=4;
	#define X 18*4+sm+1 
	#define Y 10*3+ym+1
	system("cls");
	printf("\n\n\n");
	if(L=='E')printy("1 Ԫ�����ڱ�Ӣ��");
	else if(L=='C')printy("2 Ԫ�����ڱ��У�");
	char Group[55]=" 1A 2A 3B 4B 5B 6B 7B    8     1B 2B 3A 4A 5A 6A 7A 0 ";		//����Ϣ�ַ����� 
	struct element *p=h;
	char str[Y][X];			//Ԫ�����ڱ��λ�ַ����� 
	for(y=0;y<Y;y++)
		for(x=0;x<X;x++)
			str[y][x]=' ';		//������Ϣ��ʼ�� 
	x=0;
	//����Ϣ���� 
	for(i=0;i<=2;i++)
		for(j=4;j<=18*4+sm;j++)
		{
			if((i==0||i==2)&&(j%4==0)&&(j<8*4+sm||j>9*4+sm))	//�� 
				str[i][j]='*';
			else if(i==0||i==2)				//���±� 
				str[i][j]='-';
			else if(j%4==0&&(j<8*4+sm||j>9*4+sm))		//���ұ� 
				str[i][j]='|';
			else if(i==1&&j%4==2)			//����Ϣ��ӡ 
			{
				str[i][j]=Group[x+1];
				str[i][j+1]=Group[x+2];
				x+=3;
			}
		}
	//������Ϣ���� 
	for(i=ym;i<=21+ym;i++)
		for(j=0;j<sm-1;j++)
		{
			if(i%3==ym%3&&(j==0||j==sm-2))		//�� 
				str[i][j]='*';
			else if(i%3==ym%3)			//���±� 
				str[i][j]='-';
			else if(j==0||j==sm-2)			//���ұ� 
				str[i][j]='|';
			else if(i%3==ym%3-1&&j==1)		//���ڴ�ӡ 
				str[i][j]=(i/3)+46+ym%3;		
		}
	//Ԫ����Ϣλ������ 
	do
	{
		//��ȡ���λ�� 
		y=p->adr_y-48;	 
		x=p->adr_x-48;
		for(i=(y-1)*3+ym;i<=(y-1)*3+3+ym;i++)		//��Ҫλ����Ϣ���� 
			for(j=(x-1)*4+sm;j<=(x-1)*4+4+sm;j++)
			{
				if(i%3==ym%3&&j%4==sm-4)		//�� 
					str[i][j]='*';
				else if(i==(y-1)*3+ym||i==(y-1)*3+3+ym)		//���±� 
					str[i][j]='-';
				else if(j==(x-1)*4+sm||j==(x-1)*4+4+sm)		//���ұ� 
					str[i][j]='|';
				else
				{	
					if(p->num<10)		//һλ������� 
					{
						str[(y-1)*3+1+ym][(x-1)*4+1+sm]=p->num%10+48;
					}
					else if(p->num<100)		//��λ�������  
					{
						str[(y-1)*3+1+ym][(x-1)*4+1+sm]=(p->num/10)%10+48;
						str[(y-1)*3+1+ym][(x-1)*4+2+sm]=p->num%10+48;
					}
					else	//��λ�������  
					{
						str[(y-1)*3+1+ym][(x-1)*4+1+sm]=(p->num/100)%10+48;
						str[(y-1)*3+1+ym][(x-1)*4+2+sm]=(p->num/10)%10+48;
						str[(y-1)*3+1+ym][(x-1)*4+3+sm]=p->num%10+48;
					}
				}
			}
		if(L=='E')			//Ӣ�ķ��Ŵ�ӡ 
		{
			str[(y-1)*3+2+ym][(x-1)*4+sm]='|';
			if(strlen(p->E_name)==1)		//һλ���Ŵ�ӡ 
			{
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->E_name[0];
			}
			else if(strlen(p->E_name)==2)		//��λ���Ŵ�ӡ
			{
				str[(y-1)*3+2+ym][(x-1)*4+2+sm]=p->E_name[0];
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->E_name[1];
			}
			else		//��λ���Ŵ�ӡ
			{
				
				str[(y-1)*3+2+ym][(x-1)*4+1+sm]=p->E_name[0];
				str[(y-1)*3+2+ym][(x-1)*4+2+sm]=p->E_name[1];
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->E_name[2];
				
			}
			str[(y-1)*3+2+ym][(x-1)*4+4+sm]='|';	
		}
		else if(L=='C')			//���� 
		{
			str[(y-1)*3+2+ym][(x-1)*4+sm]='|';
			if(p->num>=105&&p->num<=111)			//��λ������ֻѡȡ������ַ� 
			{
				str[(y-1)*3+2+ym][(x-1)*4+2+sm]=p->C_name[2];
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->C_name[3];
			}
			else if(p->num>=112)			//��λӢ����ĸ��ӡ 
			{
				str[(y-1)*3+2+ym][(x-1)*4+1+sm]=p->C_name[0];
				str[(y-1)*3+2+ym][(x-1)*4+2+sm]=p->C_name[1];
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->C_name[2];
			}
			else		//����һλ��������ӡ 
			{
				
				str[(y-1)*3+2+ym][(x-1)*4+2+sm]=p->C_name[0];
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->C_name[1];
			}
		}
		p=p->next;		//��һλ���� 
	}while(p!=NULL);
	//��ϸ��
	char more[28]="*-* L  X *-* A  X *-*";
	for(i=3*5+ym;i<3*6+ym+4;i++)			//��ϵ�� Ax�����ӡ 
		for(j=2*4+1+sm;j<=2*4+3+sm;j++)
		{
			str[i][j]=more[(i-(3*5+ym))*3+(j-(2*4+1+sm))];
			str[i+3*3][j-6]=str[i][j];
		}
	//Ԫ����Ϣ���ӡ 
	printf("\n");
	for(y=0;y<Y;y++)
	{
		for(x=0;x<X;x++)
			printf("%c",str[y][x]);
		printf("\n");
	}
}
 
//*********************************************/
//**************     ������     ***************/
//*********************************************/
int main()
{
	information_set();	//Ԫ����Ϣ��ʼ�� 
	Constent();			//����ѭ�� 
	return 0;
}
