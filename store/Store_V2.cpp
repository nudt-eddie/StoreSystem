/********************************************* 
 * ���ƣ���������ϵͳ
 * ���ܣ�������Ʒ�����룬���ƺͼ۸����Ϣ�洢���ı��ļ��У�ϵͳ����ʱ�Զ����룬��������Ա�����������Լ������������Զ�ͳ��֮�����ҿɽ��˺������ۻ�СƱ�ļ��� 
 * ��ע�����й���Ա�˺�ͨ���ӿ��Ѿ��г������Խ�һ�����ƣ�
 		 �����嵥�л����Խ�һ���Ż���ͬ����ϲ����ܣ�����û����ɡ� 
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
		int getCode();		//�����Ʒ���� 
		char *getName();	//�����Ʒ���� 
		float getPrice();	//�����Ʒ�۸� 
		int getNum();		//�����Ʒ���� 
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
	cout<<"-                ��ӭʹ�ó��л���������!                    -"<<endl;
	cout<<"-                                                             -"<<endl; 
	cout<<"-   * ѡ��1: �������Ա�˻�                                   -"<<endl;
	cout<<"-                                                             -"<<endl; 	
	cout<<"-   * ѡ��2: ��������ϵͳ                                     -"<<endl;
	cout<<"-                                                             -"<<endl; 
	cout<<"-   * ѡ��0���˳�                                             -"<<endl;
	cout<<"-                                                             -"<<endl; 
	cout<<"---------------------------------------------------------------"<<endl;
}
void adminFrame()
{
	cout<<endl<<endl<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"|                ����Աר���˺�-��Ʒ����                      |"<<endl;
	cout<<"|                                                             |"<<endl; 
	cout<<"|   * ѡ��1����ȡ��ǰ���ﵵ�������޸�����(����Ա���ڴ���)     |"<<endl;
	cout<<"|                                                             |"<<endl; 
	cout<<"|   * ѡ��2���鿴��ǰ����ֽ�                                 |"<<endl;
	cout<<"|                                                             |"<<endl; 
	cout<<"|   * ѡ��0������������                                       |"<<endl;
	cout<<"|                                                             |"<<endl; 
	cout<<"---------------------------------------------------------------"<<endl;
}
void passFrame()
{
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"����������������Ʒ���ۣ�"<<endl<<endl;;
	cout<<"��Ʒ��        ��Ʒ����        ����"<<endl;
	cout<<"__________________________________________________"<<endl; 
}
void exitFrame()
{
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"|                                                             |"<<endl;
	cout<<"|               ��лʹ�ñ������ף���������!                 |"<<endl;
	cout<<"|                                                             |"<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
} 
int main()
{
//	Store store(1001,"ѩ��",10.5);

	int mainInp = 2;
	int adminInp = -1;
	char key[6] = "admin";
	char inKey[6] = "00000";
	int errorFlag = 0;
	float money = 0;		//��¼����ֽ� 

	reInput_main:;
	mainFrame();
	cin>>mainInp;
	switch(mainInp)
	{
		case 1://�������Աҳ�棬���������ӻ�������۸�ͻ��������ȵ�����
				system("cls");
				cout<<"�������Ա���루�Ҳ��������������123456�ģ�:"; 
				char inp_admin;  //�����������ݣ� 
				
				while(strcmp(key,inKey))
				{
					cin>>inKey;
					errorFlag++;
					cout<<endl<<"��ʵ������admin"<<endl<<endl; 
					if(errorFlag == 3)
					{
						cout<<"���Ѿ�����������������Σ���Ҫ�����ˣ�"<<endl;
						exitFrame();
						return 0;
					}
					cout<<"�������������:";

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
							cout<<"����˵�˳���Ա���ڴ����𣡣���"<<endl<<endl;
							exitFrame(); 
							break; 
						} 
					case 2:
						{
							fstream chkMoney;
							chkMoney.open("money.txt");
							chkMoney>>money;
							cout<<"����ֽ���"<<money<<" Ԫ."<<endl;
							cout<<endl<<"��������ֵ�����ϼ�Ŀ¼"<<endl;
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
					default:cout<<"����������������!"<<endl;
							goto reInput_Admin;
				}
				break;
		case 2://����ӪҵԱ���棬������ɻ������嵥֧�����ܣ�
			{	
				loop:;
				
				int thingsCode = -1;	//��Ʒ���� 
				float totalMoney = 0;		//�����ܼ� 
				int thingsNum = -1;		//������Ʒ���� 
				int kind_of_store = 10;  //Ĭ���������10����Ʒ�� 
				
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
					cout<<"��ȡԭ�ļ������������¼����Ա�˺Ž�������⣡"<<endl;
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
				cout<<endl<<"��������Ʒ���빺����Ʒ������0���㣺";
				cin>>thingsCode;							//�������Ʒ��� 
				if(thingsCode>kind_of_store) 
					{
						cout<<"�������������ԣ�"<<endl; 
						thingsNum--;
						goto shopLoop;
					}
				switch(thingsCode)
				{
					case 0://�������ģ��
					{
						int jump = -1;
						system("cls");
						cout<<endl<<"=====================�����嵥====================="<<endl;
						cout<<"���ι��������������»��"<<endl<<endl;
						cout<<"��Ʒ��        ��Ʒ����        ����        ����"<<endl;
						cout<<"__________________________________________________"<<endl; 
						outList<<"=====================����СƱ====================="<<endl; 
						outList<<"��Ʒ��        ��Ʒ����        ����        ����"<<endl;
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
						outList<<setfill('-')<<left<<"����:"<<totalMoney<<" Ԫ"<<endl;
						outList<<"=====================лл�ݹ�====================="<<endl;
						cout<<"__________________________________________________"<<endl; 
						cout<<"�ܼƻ��ѣ�"<<totalMoney<<" Ԫ"<<endl; 
						cout<<"=====================лл�ݹ�====================="<<endl;
						cout<<endl<<endl<<endl<<"1-�������˵�    0-�˳�"<<endl;
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
									cout<<"�������������"<<endl;
									goto  loop_inp;
									break;
						}
						break;
					}
					
					default:
					{
						shopList_Code[thingsNum] = thingsCode;
						cout<<"�����빺�� "<<store[thingsCode-1].getName()<<" ��������";
						cin>>shopList_Number[thingsNum];
						goto shopLoop; 
					 } 
				}
				rdStore.close(); 

				break;
			}
		case 0://�˳�ϵͳ 
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
