#include<iostream>
#include<string>
using namespace std;
//������Ϊ���֣�������Dry,ʪ����Wet,�ɻ�������Recoverable,�к�����Harmful
//����������������࣬���ӿ�
class WasteDisposal
{
public:

	virtual void Disposal() = 0;//��������

};
//��������������Ĳ��Գ�����
class DryWasteDisposal :public WasteDisposal
{
public:
	void Disposal()
	{
		cout << "ת�������������ˮ�ߡ���" << endl;
		cout << "������������ϣ�" << endl;
	}
};
//����ʪ��������Ĳ��Գ�����
class WetWasteDisposal :public WasteDisposal
{
public:
	void Disposal()
	{
		cout << "ת��ʪ����������ˮ�ߡ���" << endl;
		cout << "ʪ����������ϣ�" << endl;
	}
};
//�����ɻ�����������Ĳ��Գ�����
class RecoverWasteDisposal :public WasteDisposal
{
public:
	void Disposal()
	{
		cout << "ת��ɻ�������������ˮ�ߡ���" << endl;
		cout << "�ɻ�������������ϣ�" << endl;
	}
};
//�����к���������Ĳ��Գ�����
class HarmfulWasteDisposal :public WasteDisposal
{
public:
	void Disposal()
	{
		cout << "ת���к�����������ˮ�ߡ���" << endl;
		cout << "�к���������������ϣ�" << endl;
	}
};
//�����������࣬������������ʹ�����������ʵ�ֽӿ��Զ�ѡ�����ȥ��������
class Waste
{
public:
	Waste()
	{
		//����������ָ������ΪNullptr
		m_WasteDisposal = nullptr;
	}

	~Waste()
	{
		//�������ͷ�
		delete m_WasteDisposal;
	}

	void PerformWasteDisposal()
	{
		m_WasteDisposal->Disposal();
	}

	void SetWasteDisposal(WasteDisposal* wasteDisposal)
	{
		//��ֹ�ڴ�й©
		delete m_WasteDisposal;
		m_WasteDisposal = wasteDisposal;
	}

private:
	WasteDisposal* m_WasteDisposal;
};
//����ģʽʵ�ֺ���
void StrategicPatternDemo()
{
	Waste* waste = new Waste();
	//һ��ʼ��������Ϊ������
	cout << "������������������վ����ʼ����" << endl;
	waste->SetWasteDisposal(new DryWasteDisposal);
	//ִ�в���
	waste->PerformWasteDisposal();

	//һ��ʼ��������Ϊʪ����
	cout << "ʪ����������������վ����ʼ����" << endl;
	waste->SetWasteDisposal(new WetWasteDisposal);
	//ִ�в���
	waste->PerformWasteDisposal();

	//һ��ʼ��������Ϊ�ɻ�������
	cout << "�ɻ�������������������վ����ʼ����" << endl;
	waste->SetWasteDisposal(new RecoverWasteDisposal);
	//ִ�в���
	waste->PerformWasteDisposal();

	//һ��ʼ��������Ϊ�к�����
	cout << "�к�����������������վ����ʼ����" << endl;
	waste->SetWasteDisposal(new HarmfulWasteDisposal);
	//ִ�в���
	waste->PerformWasteDisposal();

}