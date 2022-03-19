#include <iostream>
#include <string>

constexpr auto MAX = 1000; // 最大人数

using namespace std;
// 版本v0.0.2

//联系人结构体
struct Person {
	string m_Name;
	int m_Sex=0;
	int m_Age=0;
	string m_Phone;
	string m_Addr;
};

//通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size=0;	
};


// 显示主菜单
void showMenu() {
	cout << "************************ " << endl;
	cout << "***** 1.添加联系人 ***** " << endl;
	cout << "***** 2.显示联系人 ***** " << endl;
	cout << "***** 3.删除联系人 ***** " << endl;
	cout << "***** 4.查找联系人 ***** " << endl;
	cout << "***** 5.修改联系人 ***** " << endl;
	cout << "***** 6.清空联系人 ***** " << endl;
	cout << "***** 0.退出系统   ***** " << endl;
	cout << "************************ " << endl;
}


//添加联系人
void addPerson(Addressbooks* abs) {
	if (abs->m_Size==MAX)
	{
		cout << "通讯录已满,无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex=0;		
		cout << "请输入性别数字(1男,2女):" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误, 请重新输入性别数字(1男,2女):" << endl;
			}
		}
		
		int age = 0;
		cout << "请输入年龄:" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "请输入电话:" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "请输入地址:" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "联系人添加成功!" << endl;

		system("pause");
		system("cls");
	}
}


void showPerson(Addressbooks* abs) {

	if (abs->m_Size==0)
	{
		cout << "当前通讯录为空"<< endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名: " << abs->personArray[i].m_Name << "\t";
			cout << "性别: " <<( abs->personArray[i].m_Sex == 1? "男":"女") << "\t";
			cout << "年龄: " << abs->personArray[i].m_Age << "\t";
			cout << "电话: " << abs->personArray[i].m_Phone << "\t";
			cout << "住址: " << abs->personArray[i].m_Addr << endl;			
		}
	}

	system("pause");
	system("cls");
}


//检查联系人是否存在, 如果存在返回数组下标, 不存在返回-1
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name==name)
		{
			return i;
		}
	}
	return -1;
}


void deletePerson(Addressbooks* abs) {
	cout << "请输入删除联系人的姓名:" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		// 进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
	}

	system("pause");
	system("cls");
}


void findPerson(Addressbooks* abs) {
	cout << "请输入要查找的联系人姓名:" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "姓名: " << abs->personArray[ret].m_Name << "\t";
		cout << "性别: " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄: " << abs->personArray[ret].m_Age << "\t";
		cout << "电话: " << abs->personArray[ret].m_Phone << "\t";
		cout << "住址: " << abs->personArray[ret].m_Addr << endl;
	}

	system("pause");
	system("cls");
}


void modifyPerson(Addressbooks* abs) {
	cout << "请输入要修改的联系人姓名:" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = 0;
		cout << "请输入性别数字(1男,2女):" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误, 请重新输入性别数字(1男,2女):" << endl;
			}
		}

		int age = 0;
		cout << "请输入年龄:" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string phone;
		cout << "请输入电话:" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string address;
		cout << "请输入地址:" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "联系人修改成功!" << endl;
	}

	system("pause");
	system("cls");
}


void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}


int main() {
	Addressbooks *abs = new Addressbooks;
	abs->m_Size = 0;

	int select = 0;
	while (true)
	{
		showMenu();
		cout << "请选择功能:" << endl;
		cin >> select;
		switch (select)
		{
		case 1: //添加联系人
			addPerson(abs);
			break;
		case 2: //显示联系人
			showPerson(abs);
			break;
		case 3: //删除联系人
			deletePerson(abs);
			break;
		case 4: //查找联系人
			findPerson(abs);
			break;
		case 5: //修改联系人
			modifyPerson(abs);
			break;
		case 6: //清空联系人
			cleanPerson(abs);
			break;
		case 0: //退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	delete abs;
	return 0;
}