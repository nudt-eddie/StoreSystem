/********************************************* 
 * 名称：超市收银系统
 * 功能：超市商品的条码，名称和价格等信息存储在文本文件中，系统启动时自动读入，接受收银员输入多个条码以及购买数量后自动统计之，并且可结账后生成售货小票文件。 
 * 备注：还有管理员账号通道接口已经列出，可以进一步完善；
 		 购物清单中还可以进一步优化相同货物合并功能，这里没有完成。 
 *********************************************/
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h> 
#include<iomanip>
using namespace std;
 
class Store
{
	public:
		void setStore(int CODE = 0, char NAME[20] = 0, float PRICE = 0)
		{
			code = CODE;
			strcpy(name,NAME);
			price = PRICE;
		}
		void setNum(int m)
		{
			num = m;
		}
		int getCode();		//获得商品条码 
		char *getName();	//获得商品名称 
		float getPrice();	//获得商品价格 
		int getNum();		//获得商品数量 
	private:
		int code;
		char name[20];
		float price;
		int num;
} ;

int Store::getCode()
{
	return code;
} 
char *Store::getName()
{
	return name; 
}
float Store::getPrice()
{
	return price;
}
int Store::getNum()
{
	return num;
}

void mainFrame()
{
	cout<<endl<<endl<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"-                欢迎使用超市货物管理软件!                    -"<<endl;
	cout<<"-                                                             -"<<endl; 
	cout<<"-   * 选项1: 进入管理员账户                                   -"<<endl;
	cout<<"-                                                             -"<<endl; 	
	cout<<"-   * 选项2: 进入收银系统                                     -"<<endl;
	cout<<"-                                                             -"<<endl; 
	cout<<"-   * 选项0：退出                                             -"<<endl;
	cout<<"-                                                             -"<<endl; 
	cout<<"---------------------------------------------------------------"<<endl;
}
void adminFrame()
{
	cout<<endl<<endl<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"|                管理员专用账号-商品管理                      |"<<endl;
	cout<<"|                                                             |"<<endl; 
	cout<<"|   * 选项1：读取当前货物档案并且修改内容(程序员正在打盹)     |"<<endl;
	cout<<"|                                                             |"<<endl; 
	cout<<"|   * 选项2：查看当前库存现金                                 |"<<endl;
	cout<<"|                                                             |"<<endl; 
	cout<<"|   * 选项0：返回主界面                                       |"<<endl;
	cout<<"|                                                             |"<<endl; 
	cout<<"---------------------------------------------------------------"<<endl;
}
void passFrame()
{
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"现在我们有如下商品在售："<<endl<<endl;;
	cout<<"商品码        商品名称        单价"<<endl;
	cout<<"__________________________________________________"<<endl; 
}
void exitFrame()
{
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"|                                                             |"<<endl;
	cout<<"|               感谢使用本软件，祝您生活愉快!                 |"<<endl;
	cout<<"|                                                             |"<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
} 
int main()
{
//	Store store(1001,"雪碧",10.5);

	int mainInp = 2;
	int adminInp = -1;
	char key[6] = "admin";
	char inKey[6] = "00000";
	int errorFlag = 0;
	float money = 0;		//记录库存现金； 

	reInput_main:;
	mainFrame();
	cin>>mainInp;
	switch(mainInp)
	{
		case 1://进入管理员页面，可以完成添加货物，调整价格和货物数量等等任务；
				system("cls");
				cout<<"输入管理员密码（我不会告诉你密码是123456的）:"; 
				char inp_admin;  //监控输入的内容； 
				
				while(strcmp(key,inKey))
				{
					cin>>inKey;
					errorFlag++;
					cout<<endl<<"其实密码是admin"<<endl<<endl; 
					if(errorFlag == 3)
					{
						cout<<"您已经错误的输入密码三次，我要报警了！"<<endl;
						exitFrame();
						return 0;
					}
					cout<<"密码错误，请重试:";

				}
				errorFlag = 0; 
				loop_adminFrame:;
				system("cls");
				
				adminFrame();
				reInput_Admin:;
				cin>>adminInp;
				switch(adminInp)
				{
					case 1:
						{
							system("cls");
							cout<<"不是说了程序员正在打盹吗！！！"<<endl<<endl;
							exitFrame(); 
							break; 
						} 
					case 2:
						{
							fstream chkMoney;
							chkMoney.open("money.txt");
							chkMoney>>money;
							cout<<"库存现金余额："<<money<<" 元."<<endl;
							cout<<endl<<"输入任意值返回上级目录"<<endl;
							chkMoney.close();
							cin>>inp_admin;
								goto loop_adminFrame;

							 exitFrame();
							 break;
						}
					case 0: system("cls");
							strcpy(inKey,"00000"); 
							goto reInput_main;
							break;
					default:cout<<"输入代码错误，请重试!"<<endl;
							goto reInput_Admin;
				}
				break;
		case 2://进入营业员界面，可以完成基本的清单支付功能；
			{	
				loop:;
				
				int thingsCode = -1;	//商品编码 
				float totalMoney = 0;		//购物总计 
				int thingsNum = -1;		//购买商品次序 
				int kind_of_store = 10;  //默认情况下有10种商品； 
				
				int tempcode_Code;
				char tempcode_Name[20];
				float tempcode_Price;
				
				int shopList_Code[kind_of_store];
				int shopList_Number[kind_of_store]; 
				
				ifstream rdStore;
				rdStore.open("store.txt");
				
				ifstream rdMoney;
				rdMoney.open("money.txt");
				if(!rdMoney)
				{
					cout<<"error in Readin Money!"<<endl;
					return 0; 
				} 
				rdMoney>>money;
				rdMoney.close();
				
				if(!rdStore)
				{
					cout<<"读取原文件发生错误，请登录管理员账号解决此问题！"<<endl;
					return 0; 
				}
				
				ofstream outList;
				outList.open("listdata.txt");
				if(!outList)
				{
					cout<<"error in open listdata.txt!"<<endl;
					return 0; 
				} 

				system("cls");
				passFrame();
				
				rdStore>>kind_of_store;
				Store store[kind_of_store];
				
				for(int i = 0; i < kind_of_store; i++)
				{
					rdStore>>tempcode_Code>>tempcode_Name>>tempcode_Price; 
					store[i].setStore(tempcode_Code,tempcode_Name,tempcode_Price);
				}
				
				for(int i = 0; i < kind_of_store; i++)
				{
					cout<<"    "<<setw(10)<<left<<store[i].getCode()<<setw(16)<<left<<store[i].getName()<<store[i].getPrice()<<endl;
				}
				cout<<"---------------------------------------------------------------"<<endl;
				shopLoop:;
				thingsNum++; 
				cout<<endl<<"请输入商品编码购买商品，输入0结算：";
				cin>>thingsCode;							//购买的商品编号 
				if(thingsCode>kind_of_store) 
					{
						cout<<"输入有误，请重试！"<<endl; 
						thingsNum--;
						goto shopLoop;
					}
				switch(thingsCode)
				{
					case 0://进入结算模块
					{
						int jump = -1;
						system("cls");
						cout<<endl<<"=====================购物清单====================="<<endl;
						cout<<"本次购物您购买了以下货物："<<endl<<endl;
						cout<<"商品码        商品名称        单价        数量"<<endl;
						cout<<"__________________________________________________"<<endl; 
						outList<<"=====================购物小票====================="<<endl; 
						outList<<"商品码        商品名称        单价        数量"<<endl;
						outList<<"__________________________________________________"<<endl; 
						for(int j = 0;j < thingsNum;j++)
						{
							int t = shopList_Code[j]-1; 
							totalMoney = shopList_Number[j]*store[t].getPrice() + totalMoney; 
							cout<<setw(6)<<right<<shopList_Code[j]<<"        "<<setw(16)<<left<<store[t].getName()<<setw(12)<<
								left<<store[t].getPrice()<<shopList_Number[j]<<endl;
							
								outList<<setw(6)<<right<<shopList_Code[j]<<"        "<<setw(16)<<left<<store[t].getName()<<setw(12)<<
								left<<store[t].getPrice()<<shopList_Number[j]<<endl;
						}
						outList<<"__________________________________________________"<<endl; 
						outList<<setfill('-')<<left<<"共计:"<<totalMoney<<" 元"<<endl;
						outList<<"=====================谢谢惠顾====================="<<endl;
						cout<<"__________________________________________________"<<endl; 
						cout<<"总计花费："<<totalMoney<<" 元"<<endl; 
						cout<<"=====================谢谢惠顾====================="<<endl;
						cout<<endl<<endl<<endl<<"1-返回主菜单    0-退出"<<endl;
						money += totalMoney;
						
						ofstream rdMoney;
						rdMoney.open("money.txt");
						rdMoney<<money<<endl;
						rdMoney.close();
						outList.close();
						loop_inp:;
						cin>> jump;
						switch(jump)
						{
							case 1:
									system("cls");
									goto reInput_main;
									break;
							case 0:
									system("cls");
									exitFrame();
									return 0;
							default:
									cout<<"输入错误！请重试"<<endl;
									goto  loop_inp;
									break;
						}
						break;
					}
					
					default:
					{
						shopList_Code[thingsNum] = thingsCode;
						cout<<"请输入购买 "<<store[thingsCode-1].getName()<<" 的数量：";
						cin>>shopList_Number[thingsNum];
						goto shopLoop; 
					 } 
				}
				rdStore.close(); 

				break;
			}
		case 0://退出系统 
				system("cls");
				exitFrame();
				break;
		default:
				system("cls");
				cout<<"Your must have input the wrong code, check it again!"<<endl;
				goto reInput_main; 
	}
	return 0;
} 
