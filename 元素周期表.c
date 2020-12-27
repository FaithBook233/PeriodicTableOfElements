/*
	**程序所有内容皆由FaithBook-_-纯手工打造 
	** 程序最终解释权归 FaithBook-_-所有 
	** 文件仅供学习参考 
*/


#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<malloc.h>
#include<math.h>
#define LEN sizeof(struct element)
#define WIDTH 78	//窗口宽度    
#define N 118		//元素个数 


//*************************************************/
//************         信息文件       *************/
//*************************************************/
char name_e_filename[]="English_name.FaithBook-_-";						//元素英文符号 
char name_c_filename[]="Chinese_name.FaithBook-_-";						//元素中文名 
char weight_filename[]="Weight_of_Element.FaithBook-_-";					//原子量 
char period_filename[]="Period.FaithBook-_-"; 							//周期 
char group_filename[]="group.FaithBook-_-";								//族 
char valence_filename[]="Valence.FaithBook-_-";							//常见化合价 
char property_filename[]="Property.FaithBook-_-";						//性质 
char brief_introduction_filename[]="Breif_introduction.FaithBook-_-";	//元素周期表简介 
char founder_filename[]="Founder.FaithBook-_-";							//元素周期表创始人简介 
char x_filename[]="X.FaithBook-_-";										//元素位置（相对横坐标） 
char y_filename[]="Y.FaithBook-_-";										//元素位置（相对纵坐标） 
char Readme[]="ReadMe.FaithBook-_-";
//*********************************************/
//**************     结构体     ***************/
//*********************************************/
struct element
{
	int num;				//元素序号 
	char C_name[5];			//中文名称 
	char E_name[4];			//符号 
	char weight[8];			//原子量 
	char Period;			//周期 
	char Group[6];			//族 
	char Valence[11];		//常见化合价 
	char Property[9];		//性质 
	char adr_x;				//相对位置（横坐标） 
	char adr_y;				//相对位置（纵坐标） 
	struct element *next;	//链 
}*h=NULL;					//链表头指针 

//***********************************************/ 
//**************     函数声明     ***************/
//***********************************************/

/*******    主要功能函数   *******/ 
void information_set(void);
char kb_hit(void);
void pause(void);
void printy(char str[]);
void printn(char str[]);
/*******      目录主函数     *******/ 

void Constent(void);
void Constent_print(void); 
void Table(char L);
void table(void);
void find(void);
void version_information(void);
void exit_system(void);
void TXT_READ(char text[],char str[]); 
/*******    目录分支函数     *******/
void head_txt(void);
void shadow_txt(void);
void find_table(struct element *P);
void txt_print(FILE *p,char str[]);

//***********************************************/
//**************     模块函数     ***************/
//***********************************************/

/*******    居中打印不换行     *******/ 
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
/*******    居中打印换行     *******/ 
void printy(char str[])
{
	printn(str);
	printf("\n");
}
/*******    信息初始化     *******/ 
void  information_set(void)
{
	//文件指针 
	FILE *e_name,*c_name,*ele_weight,*period,*group,*valence,*property,*px,*py;	
	//打开文件相关操作操作 
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
			printf("文件打开失败！！！");
			exit(0); 
			return ; 
		}

	int n;
	struct element *p1,*p2;
	p1=p2=(struct element*)malloc(LEN);		//创建空间 
	p2=h;			//指向头指针 
	for(n=1;n<=N;n++)		//对每个元素进行同样的信息初始化操作 
	{
		//初始化链表 
		int i;
		char ch;
		p1->num=n;
		
		//英文名称
		i=0; 
		while((ch=fgetc(e_name))!='\n')
		{
			p1->E_name[i]=ch;
			i++;
		}
		for(;i<4;i++)
			p1->E_name[i]='\0';
		
		//中文名称 
		i=0;
		while((ch=fgetc(c_name))!='\n')
		{
			p1->C_name[i]=ch;
			i++;
		}
		for(;i<5;i++)
			p1->C_name[i]='\0';
			
		//原子相对质量
		i=0;
		while((ch=fgetc(ele_weight))!='\n')
		{
			p1->weight[i]=ch;
			i++;
		}
		for(;i<8;i++)
			p1->weight[i]='\0';
		
		//周期
		p1->Period=fgetc(period);
		fgetc(period);
		
		//族 
		i=0;
		while((ch=fgetc(group))!='\n')
		{
			p1->Group[i]=ch;
			i++;
		}
		for(;i<6;i++)
			p1->Group[i]='\0';
		
		//常见化合价 
		i=0;
		while((ch=fgetc(valence))!='\n')
		{
			p1->Valence[i]=ch;
			i++;
		}
		for(;i<11;i++)
			p1->Valence[i]='\0';
		
		//性质
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
		
		//构建链表 
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
	//关闭信息文件 
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
/************     列表打印函数     ***************/ 
void table(void)
{
	system("cls");		//清屏 
	struct element *p;	//结构体指针 
	p=h;
	head_txt();			//表头 
	
	//表中信息 
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
	shadow_txt();		//表尾 
}

/************     表头打印函数     ***************/ 
void head_txt(void)
{
	printf("       |================================================================|\n"); 	
	printf("       |                          3 元素基本信息                        |\n");
	printf("       |=====v====v======v=========v============v============v==========|\n"); 	
	printf("       |序号 | 英 |  中  |  原子量 |周期|   族  | 常见化合价 |   性质   |\n"); 	
}
/************     表尾打印函数     ***************/ 
void shadow_txt(void)
{
	printf("       |=====^====^======^=========^====^=======^============^==========|\n"); 	//v
}

int txt_num;	//计数操作变量

/***********    文本信息打印函数    ***************/ 
void txt_print(FILE *p,char str[])
{	while(!feof(p))
	{
		if(txt_num==0)		//标题打印 
		{
			printy("|=====================| "); 	
			printf("                           |  %16s |\n",str);
			printy("|=====================|"); 
			printf("\n");
		}
		//内容打印 
		printf("%c",fgetc(p));
		txt_num++;
	} 
}
/************     查询函数     ***************/ 
void find(void)
{
	int i,sum=0;
	char str[9]="\0\0\0\0\0\0\0\0\0";		//信息初始化 
	struct element *p=h;
	system("cls");
	printf("\n\n\n");
	printy("4 信息查询：");
	printf("\n\n"); 
	printy("请输入需要查询的信息");
	printy("可输入元素序号、中英文名称、元素周期、族、常见化合价及其性质");
	printn(":  ");
	scanf("%s",str);
	
	//输入内容类型转换 
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
		i=0;		//查询到元素数量 
		do
		{
			if(sum==p->num||(strlen(str)==1&&str[0]==p->Period))				//序号与周期对比 
			{
				if(i==0)
				{
					printf("\n\n");
					printy("查询结果");
					printf("\n");
					head_txt(); 
				}
				printf("       |=====|====|======|=========|====|=======|============|==========|\n"); 	
				printf("       | %-4d| %-3s|  %-4s|%8s |  %c | %5s | %10s | %8s |\n",p->num,p->E_name,p->C_name,p->weight,p->Period,p->Group,p->Valence,p->Property);
				i++;
			}
			p=p->next;
		}while(p!=NULL);
		if(i!=0)shadow_txt();		//表尾打印 
	}else
	{
		i=0;
		do
		{
			if(strcmp(str,p->E_name)==0||strcmp(str,p->C_name)==0||strcmp(str,p->Group)==0||strcmp(str,p->Property)==0)			//相等条件 
			{
							//中文名&&英文符号&&族&&性质对比 
				if(i==0)
				{
					printf("\n\n");
					printy("查询结果");
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
	if(i==0)		//未查询到操作 
	{
		printf("\n");
		printy("未查询到相关信息"); 
	}
	else return ;
}
/************     查询结果打印函数     ***************/ 
void find_table(struct element *p)
{
	printf("\n\n");
	printy("查询结果");
	printf("\n");
	head_txt();
	printf("       |=====|====|======|=========|====|=======|============|==========|\n"); 	
	printf("       | %-4d| %-3s|  %-4s|%8s |  %c | %5s | %10s | %8s |\n",p->num,p->E_name,p->C_name,p->weight,p->Period,p->Group,p->Valence,p->Property);
	shadow_txt();
	printf("\n");
	printy("查询完毕！");
}

/************     程序自述函数     ***************/ 
void TXT_READ(char text[],char str[])
{
	FILE *p;
	if((p=fopen(str,"r"))==NULL)
	{
		printf("%s打开失败",str);
		return ;
	}
	system("cls");	//清屏 
	printf("\n\n");
	txt_num=0;
//	txt_print(p,"");	//文本信息打印函数调用 
	txt_print(p,text);	//文本信息打印函数调用 
	fclose(p);
}

/************     停顿函数     ***************/ 
void pause(void)
{
	//除了回车，其他按键均无响应 
	printf("\n\n");
	printy("按Enter继续...");
	while(1)
	if(kbhit())	//有键盘操作 
	{
		char ch=getch();
		if(ch==13)		//输入回车跳出循环，结束函数 
			return; 
	}
}
/************     系统退出函数     ***************/ 
void exit_system(void)
{
	system("cls");
	printf("\n\n\n\n");
	printy("欢迎使用！！!");
	printy("FaithBook-_-会想你的！"); 
	printf("\n\n");
	printf(" ￣￣￣￣￣￣￣￣￣￣￣￣)\n");
	printf("  亲！大白等你回来哦！    )\n");
	printf(" ￣￣∨￣￣￣￣￣￣￣￣￣\n\n");
	printf("     ( O - O ) balalala~\n");
	printf("　 ／　　　    '\'\n");
	printf("  /　　　  ○  　'\'\n");
	printf("/　 /  　　   '\'   '\' \n");
	printf("|　/　 　　　  '\'　|\n");
	printf(" '\'?　　　　     ?/\n");
	printf("  卜?　　    ―イ\n");
	printf("　 '\'　　/'\'　  /\n");
	printf("　   ︶　   ︶\n");
	pause();
	exit(0) ;//退出函数 
}
/************     键盘返回值函数     ***************/ 
char kb_hit(void)
{
	while(1)
		if(kbhit())
		{
			char ch=getch(); 
			if(ch>='0'&&ch<='8')		//有效输入信息为‘0’~‘7’ 
				return (ch);
		}
}
/************     目录信息打印函数     ***************/ 
void Constent_print(void)
{
	printy("元素周期表"); 
	printy("* 1 元素周期表（英）  *");
	printy("* 2 元素周期表（中）  *");
	printy("* 3 元素基本信息表    *"); 
	printy("* 4 元素查询          *"); 
	printy("* 5 元素周期表简介    *");
	printy("* 6 周期表创始人简介  *");
	printy("* 7 程序自述          *"); 
	printy("* 8 版本信息          *"); 
	printy("* 0 退出              *");
}
/************     目录函数     ***************/ 
void Constent(void)
{
	system("cls");
	Constent_print();	//打印目录 
	switch(kb_hit())
	{
		//相应函数 
		case '1':Table('E');break;
		case '2':Table('C');break;
		case '3':table();break;
		case '4':find();break;
		case '5':TXT_READ(" 5 元素周期表简介 ",brief_introduction_filename);break;
		case '6':TXT_READ("6 周期表创始人简介",founder_filename);break;
		case '7':TXT_READ("    7 自述文件    ",Readme);break;
		case '8':version_information();break;
		case '0':exit_system();break;
	}
	pause();	//停顿函数 
	Constent();	//函数递归，功能循环 
	return ;
} 
/************     版本信息打印     ***************/ 
void version_information(void)
{
	system("cls");
	printf("\n\n\n\n");
	printy("**  8 版本信息  **"); 
	printy("*---------------------------*");
	printy("*    版本日期: 2018\\2\\8     *");
	printy("*   制作人： FaithBook-_-    *");
	printy("*  邮箱：1203339302@qq.com  *");
	printy("*---------------------------*");
}
/************     元素周期表打印函数     ***************/ 
void Table(char L)
{
	int x,y,i,j,sm=4,ym=4;
	#define X 18*4+sm+1 
	#define Y 10*3+ym+1
	system("cls");
	printf("\n\n\n");
	if(L=='E')printy("1 元素周期表（英）");
	else if(L=='C')printy("2 元素周期表（中）");
	char Group[55]=" 1A 2A 3B 4B 5B 6B 7B    8     1B 2B 3A 4A 5A 6A 7A 0 ";		//族信息字符数组 
	struct element *p=h;
	char str[Y][X];			//元素周期表二位字符数组 
	for(y=0;y<Y;y++)
		for(x=0;x<X;x++)
			str[y][x]=' ';		//数组信息初始化 
	x=0;
	//族信息设置 
	for(i=0;i<=2;i++)
		for(j=4;j<=18*4+sm;j++)
		{
			if((i==0||i==2)&&(j%4==0)&&(j<8*4+sm||j>9*4+sm))	//角 
				str[i][j]='*';
			else if(i==0||i==2)				//上下边 
				str[i][j]='-';
			else if(j%4==0&&(j<8*4+sm||j>9*4+sm))		//左右边 
				str[i][j]='|';
			else if(i==1&&j%4==2)			//族信息打印 
			{
				str[i][j]=Group[x+1];
				str[i][j+1]=Group[x+2];
				x+=3;
			}
		}
	//周期信息设置 
	for(i=ym;i<=21+ym;i++)
		for(j=0;j<sm-1;j++)
		{
			if(i%3==ym%3&&(j==0||j==sm-2))		//角 
				str[i][j]='*';
			else if(i%3==ym%3)			//上下边 
				str[i][j]='-';
			else if(j==0||j==sm-2)			//左右边 
				str[i][j]='|';
			else if(i%3==ym%3-1&&j==1)		//周期打印 
				str[i][j]=(i/3)+46+ym%3;		
		}
	//元素信息位置设置 
	do
	{
		//获取相对位置 
		y=p->adr_y-48;	 
		x=p->adr_x-48;
		for(i=(y-1)*3+ym;i<=(y-1)*3+3+ym;i++)		//主要位置信息设置 
			for(j=(x-1)*4+sm;j<=(x-1)*4+4+sm;j++)
			{
				if(i%3==ym%3&&j%4==sm-4)		//角 
					str[i][j]='*';
				else if(i==(y-1)*3+ym||i==(y-1)*3+3+ym)		//上下边 
					str[i][j]='-';
				else if(j==(x-1)*4+sm||j==(x-1)*4+4+sm)		//左右边 
					str[i][j]='|';
				else
				{	
					if(p->num<10)		//一位序号设置 
					{
						str[(y-1)*3+1+ym][(x-1)*4+1+sm]=p->num%10+48;
					}
					else if(p->num<100)		//二位序号设置  
					{
						str[(y-1)*3+1+ym][(x-1)*4+1+sm]=(p->num/10)%10+48;
						str[(y-1)*3+1+ym][(x-1)*4+2+sm]=p->num%10+48;
					}
					else	//三位序号设置  
					{
						str[(y-1)*3+1+ym][(x-1)*4+1+sm]=(p->num/100)%10+48;
						str[(y-1)*3+1+ym][(x-1)*4+2+sm]=(p->num/10)%10+48;
						str[(y-1)*3+1+ym][(x-1)*4+3+sm]=p->num%10+48;
					}
				}
			}
		if(L=='E')			//英文符号打印 
		{
			str[(y-1)*3+2+ym][(x-1)*4+sm]='|';
			if(strlen(p->E_name)==1)		//一位符号打印 
			{
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->E_name[0];
			}
			else if(strlen(p->E_name)==2)		//二位符号打印
			{
				str[(y-1)*3+2+ym][(x-1)*4+2+sm]=p->E_name[0];
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->E_name[1];
			}
			else		//三位符号打印
			{
				
				str[(y-1)*3+2+ym][(x-1)*4+1+sm]=p->E_name[0];
				str[(y-1)*3+2+ym][(x-1)*4+2+sm]=p->E_name[1];
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->E_name[2];
				
			}
			str[(y-1)*3+2+ym][(x-1)*4+4+sm]='|';	
		}
		else if(L=='C')			//中文 
		{
			str[(y-1)*3+2+ym][(x-1)*4+sm]='|';
			if(p->num>=105&&p->num<=111)			//两位中文名只选取后面的字符 
			{
				str[(y-1)*3+2+ym][(x-1)*4+2+sm]=p->C_name[2];
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->C_name[3];
			}
			else if(p->num>=112)			//三位英文字母打印 
			{
				str[(y-1)*3+2+ym][(x-1)*4+1+sm]=p->C_name[0];
				str[(y-1)*3+2+ym][(x-1)*4+2+sm]=p->C_name[1];
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->C_name[2];
			}
			else		//其余一位中文名打印 
			{
				
				str[(y-1)*3+2+ym][(x-1)*4+2+sm]=p->C_name[0];
				str[(y-1)*3+2+ym][(x-1)*4+3+sm]=p->C_name[1];
			}
		}
		p=p->next;		//下一位操作 
	}while(p!=NULL);
	//详细的
	char more[28]="*-* L  X *-* A  X *-*";
	for(i=3*5+ym;i<3*6+ym+4;i++)			//镧系与 Ax标题打印 
		for(j=2*4+1+sm;j<=2*4+3+sm;j++)
		{
			str[i][j]=more[(i-(3*5+ym))*3+(j-(2*4+1+sm))];
			str[i+3*3][j-6]=str[i][j];
		}
	//元素信息表打印 
	printf("\n");
	for(y=0;y<Y;y++)
	{
		for(x=0;x<X;x++)
			printf("%c",str[y][x]);
		printf("\n");
	}
}
 
//*********************************************/
//**************     主函数     ***************/
//*********************************************/
int main()
{
	information_set();	//元素信息初始化 
	Constent();			//功能循环 
	return 0;
}
