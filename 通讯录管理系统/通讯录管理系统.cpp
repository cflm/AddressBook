#include <iostream>
#include <string>

#define MAX 1000 // �������

using namespace std;


//��ϵ�˽ṹ��
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size;
	
};


// ��ʾ���˵�
void showMenu() {
	cout << "************************ " << endl;
	cout << "***** 1.�����ϵ�� ***** " << endl;
	cout << "***** 2.��ʾ��ϵ�� ***** " << endl;
	cout << "***** 3.ɾ����ϵ�� ***** " << endl;
	cout << "***** 4.������ϵ�� ***** " << endl;
	cout << "***** 5.�޸���ϵ�� ***** " << endl;
	cout << "***** 6.�����ϵ�� ***** " << endl;
	cout << "***** 0.�˳�ϵͳ   ***** " << endl;
	cout << "************************ " << endl;

}


//�����ϵ��
void addPerson(Addressbooks* abs) {
	if (abs->m_Size==MAX)
	{
		cout << "ͨѶ¼����,�޷����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex=0;		
		cout << "�������Ա�����(1��,2Ů):" << endl;
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
				cout << "��������, �����������Ա�����(1��,2Ů):" << endl;
			}
		}
		
		int age = 0;
		cout << "����������:" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "������绰:" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "�������ַ:" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "��ϵ����ӳɹ�!" << endl;

		system("pause");
		system("cls");
	}
}


void showPerson(Addressbooks* abs) {

	if (abs->m_Size==0)
	{
		cout << "��ǰͨѶ¼Ϊ��"<< endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����: " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�: " <<( abs->personArray[i].m_Sex == 1? "��":"Ů") << "\t";
			cout << "����: " << abs->personArray[i].m_Age << "\t";
			cout << "�绰: " << abs->personArray[i].m_Phone << "\t";
			cout << "סַ: " << abs->personArray[i].m_Addr << endl;			
		}
	}

	system("pause");
	system("cls");
}


//�����ϵ���Ƿ����, ������ڷ��������±�, �����ڷ���-1
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
	cout << "������ɾ����ϵ�˵�����:" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		// ����ɾ������
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
	cout << "������Ҫ���ҵ���ϵ������:" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "����: " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�: " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "����: " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰: " << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ: " << abs->personArray[ret].m_Addr << endl;

	}

	system("pause");
	system("cls");
}


void modifyPerson(Addressbooks* abs) {
	cout << "������Ҫ�޸ĵ���ϵ������:" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		string name;
		cout << "����������:" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = 0;
		cout << "�������Ա�����(1��,2Ů):" << endl;
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
				cout << "��������, �����������Ա�����(1��,2Ů):" << endl;
			}
		}

		int age = 0;
		cout << "����������:" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string phone;
		cout << "������绰:" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string address;
		cout << "�������ַ:" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "��ϵ���޸ĳɹ�!" << endl;
	}

	system("pause");
	system("cls");
}


void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}


int main() {
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		showMenu();
		cout << "��ѡ����:" << endl;
		cin >> select;
		switch (select)
		{
		case 1: //�����ϵ��
			addPerson(&abs);
			break;
		case 2: //��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: //������ϵ��
			findPerson(&abs);
			break;
		case 5: //�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //�����ϵ��
			cleanPerson(&abs);
			break;
		case 0: //�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}