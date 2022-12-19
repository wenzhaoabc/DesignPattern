#define HAS_STD_BYTE 0
#include <iostream>
#include <random>
//#include <Windows.h>

#include "ThreadPool.h"
#include "Proxy.h"
#include "AbstractFactory.h"
#include "Adapter.h"
#include "Bridge.h"
#include "BuilderPattern.h"
#include "BusinessService.h"
#include "ChainOfResponsibility.h"
#include "Command.h"
#include "DAO.h"
#include "factory.h"
#include "Flyweight.h"
#include "header.h"
#include "Piece.h"
#include "StrategicPattern.h"
#include "TemplatePattern.h"
#include "WasteScreening.h"
#include "cmd_console_tools.h"
#include "Composite.h"
#include "EmptyObjectPattern.h"
#include "Filter.h"
#include "lmq.h"
#include "Singleton.h"


using namespace std;
/**
 * �̳߳�ģʽ����
 */

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(-1000, 1000);
auto rnd = std::bind(dist, mt);
void simulate_hard_computation() {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000 + rnd()));
}

void progress_bar(int x, int Y)
{
    //simulate_hard_computation();
    int all_block_num = x;
    for (int i = 0; i < all_block_num; i++)
    {
        cct_gotoxy(0, Y);
        if (i < all_block_num - 1)
        {
            printf("\r������%d����ʻ���[%.2lf%%]:",x-100+1, i * 100.0 / (all_block_num - 1));
        }
        else
        {
            printf("\r������%d����Ŀ�ĵ�[%.2lf%%]:",x-100+1, i * 100.0 / (all_block_num - 1));
        }
        int show_num = i * 20 / all_block_num;
        for (int j = 1; j <= show_num; j++)
        {
            std::cout << "��";
            std::this_thread::sleep_for(std::chrono::microseconds(3));
            //Sleep(3);
        }

    }
    //std::cout << std::endl;
}
void multiply(const int a, const int b) {
    simulate_hard_computation();
    const int res = a * b;
    std::cout << a << " * " << b << " = " << res << std::endl;
}
void thread_local_test()
{
    ThreadPool pool(3);
    pool.init();
    std::cout << std::endl;
    int X, Y;
    cct_getxy(X, Y);
    for (int i = 0; i < 3; ++i) {
            pool.submit(progress_bar, 100+i,Y+i);
    }
    //cct_getxy(X, Y);

    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    pool.shutdown();
}
/**
 * ����ģʽ
 */
void FactoryGarbageBin() {
    GarbageFactory garbageFactory;
    // �����������ͻ����Ӧ����Ͱ
    GarbageBin* dryGarbageBin = garbageFactory.get_garbage_bin(Dry);
    // ����Ͱʢ������
    std::string res = dryGarbageBin->contain_garbage();
    std::cout << res << std::endl;
    delete dryGarbageBin;
}
/**
 * ���󹤳�ģʽ����
 */
void AbstractFactory() {
    // �ӳ��󹤳��ֻ�ȡһ������
    ConcreteProProcess* pre = new ConcreteProProcess();
    DryPipeLine* dryProcess = pre->CreateDryPipeLine();
    // ��ȡ�ù����Ĳ�Ʒ
    std::string res = dryProcess->dry_process();
    std::cout << res << std::endl;
}

void singleton()
{
    GeneralManager::getInstance().setName("�ܾ���");
    std::string name = GeneralManager::getInstance().getName();

    std::cout << name << std::endl;
}

void Flyweight();
void DAO();
void Menu() {
    int choice = -1;
    while (true) {
        cout << " please choose what to show:                  " << endl;
        cout << "===============================================" << endl;
        cout << "                                              " << endl;
        cout << "           1.��װ������װ����ģʽ��          " << endl;
        cout << "           2.������������Ԫģʽ��     " << endl;
        cout << "           3.��Ա�������ݷ��ʶ���ģʽ��  " << endl;
        cout << "           0.�˳�                 " << endl;
        cout << "                                              " << endl;
        cout << "                                              " << endl;
        cout << "===============================================" << endl;
        cin >> choice;
        if (!choice)
            return;
        else if (choice == 1)
            Decoration();
        else if (choice == 2)
            Flyweight();
        else if (choice == 3)
            DAO();
        else
            cout << "����ȷ����ѡ���\n\n";
    }
}

//װ����ģʽ�����ڰ�װ�ɻ��հ���
void Decoration() {
    cout << endl;
    cout << "==========��װ����!========" << endl;
    Piece* plasticPiece = new PlasticPiece();//ʵ����һ���߲˹�ͷ
    Piece* paperPiece = new PaperPiece();//ʵ����һ�����ͷ
    SmallPiece smallPlasticPiece = SmallPiece(plasticPiece);//����С���߲˹�ͷ
    BigPiece bigPaperPiece = BigPiece(paperPiece);//�����������ͷ
    smallPlasticPiece.show();
    bigPaperPiece.show();
    cout << "=======================================\n" << endl;
    cout << "\n\n\n";
}

//װ����ģʽ������������ͬ��С�����ݵİ���
//���в˵�ѡ�񲿷�Ϊ���ģʽ
void Flyweight() {
    cout << "�����ӵİ������ͣ�\n";
    Kind* rigidPlasticKind = new RigidPlasticKind();
    Kind* softPlasticKind = new SoftPlasticKind();
    MiddlePiece* middlePiece = new MiddlePiece(softPlasticKind);   //���������������ϰ���
    middlePiece->make();
    Factory* factory = new Factory();

    //���ģʽ
    cout << " \n\n������Ҫ�����İ������ͣ�����1-4��         " << endl;
    cout << "===============================================" << endl;
    cout << "                                              " << endl;
    cout << "              1.����ֽ�ʰ���          " << endl;
    cout << "              2.С��ֽ�ʰ���          " << endl;
    cout << "              3.�������ϰ���          " << endl;
    cout << "              4.С�����ϰ���          " << endl;
    cout << "                                              " << endl;
    cout << "===============================================" << endl;

    int choice;
    cin >> choice;
    Piece* f;
    if (choice == 1)
        f = factory->GetFlyweights("bigpaper");
    else if (choice == 2)
        f = factory->GetFlyweights("smallpaper");
    else if (choice == 3)
        f = factory->GetFlyweights("bigplastic");
    else if (choice == 4)
        f = factory->GetFlyweights("smallplatic");
    cout << "\n\n\n";
}

//���ݷ��ʶ���ģʽ����ְ��������ɾ�Ĳ�
void DAO()
{
    printf("-------------------ְԱ��Ϣ����ϵͳ-----------------------\n");
    printf("1����ʼ������ϵͳ\n");
    printf("2������һ��ְԱ��Ϣ��¼��\n");
    printf("3��ɾ��һ��ְԱ��Ϣ\n");
    printf("4������һ��ְԱ�ĳɼ�\n");
    printf("5���޸�һ��ְԱ�ĳɼ�\n");
    printf("6���������ְԱ��Ϣ\n");
    printf("7����ӡ����ְԱ��Ϣ\n");
    printf("8���˳�ϵͳ\n");
    printf("------------------ ����������ѡ��1-8 -----------------------\n");

    EmployeeData* data = new EmployeeData;
    init_Employee_Data_m_head(data);
    while (1)
    {
        int num;
        cout << "������ָ�1-8��,���س�ȷ�ϣ�";
        cin >> num;
        switch (num)
        {
        case 1:
            //��ʼ��ͷ�ڵ�
            init_Employee_Data_m_head(data);
            cout << "��ǰָ��,��������һ��ְԱ����ϵͳ����ʼ��\n";
            printf("��ʼ��ְԱ����ϵͳ�ɹ�!\n");
            cout << endl;
            break;
        case 2:
            //����һ��ְԱ����ʼ��
            cout << "��ǰָ��,�������һ��ְԱ \n";
            Employee_Link(data, init_Employee());
            cout << endl;
            break;
        case 3:
            //ɾ��һ��ְԱ 
            cout << "��ǰָ��,����ɾ��һ��ְԱ \n";
            Employee_Delete(data);
            cout << endl;
            break;
        case 4:
            //��ѯĳ��ְԱ�ĳɼ�
            cout << "��ǰָ��,������ѯһ��ְԱ �ĳɼ�\n";
            Employee_Select(data);
            cout << endl;
            break;
        case 5:
            //�޸�ĳ�� ����Ϣ
            cout << "��ǰָ��,�����޸�һ��ְԱ �ĳɼ�\n";
            Employee_Set(data);
            cout << endl;
            break;
        case 6:
            //�������ְԱ����
            cout << "��ǰָ��,����ɾ����������\n";
            Free_Employee(data);
            cout << endl;
            break;
        case 7:
            //��ӡ����ְԱ����
            cout << "��ǰָ��,��ӡ���� ����\n";
            Employee_Show(data);
            cout << endl;
            break;
        default:
            cout << "����ָ���������������룡" << endl;
            break;
        }
        if(num==8)
        {
            break;
        }
    }
}

/**
 *@author ��˧��
 *@since 2022��12��16��
 */
int main()
{
    std::cout << "������������������..." << std::endl;
    
    std::cout<<R"(
    
      ,----..                                                                              ,---,                           ____             
 /   /   \                        ,---,                                              .'  .' `\                       ,'  , `.,-.----.   
|   :     :              __  ,-.,---.'|                                            ,---.'     \          ,--,     ,-+-,.' _ |\    /  \  
.   |  ;. /            ,' ,'/ /||   | :                 ,----._,.                  |   |  .`\  |       ,'_ /|  ,-+-. ;   , |||   :    | 
.   ; /--`    ,--.--.  '  | |' |:   : :      ,--.--.   /   /  ' /   ,---.          :   : |  '  |  .--. |  | : ,--.'|'   |  |||   | .\ : 
;   | ;  __  /       \ |  |   ,':     |,-.  /       \ |   :     |  /     \         |   ' '  ;  :,'_ /| :  . ||   |  ,', |  |,.   : |: | 
|   : |.' .'.--.  .-. |'  :  /  |   : '  | .--.  .-. ||   | .\  . /    /  |        '   | ;  .  ||  ' | |  . .|   | /  | |--' |   |  \ : 
.   | '_.' : \__\/: . .|  | '   |   |  / :  \__\/: . ..   ; ';  |.    ' / |        |   | :  |  '|  | ' |  | ||   : |  | ,    |   : .  | 
'   ; : \  | ," .--.; |;  : |   '   : |: |  ," .--.; |'   .   . |'   ;   /|        '   : | /  ; :  | : ;  ; ||   : |  |/     :     |`-' 
'   | '/  .'/  /  ,.  ||  , ;   |   | '/ : /  /  ,.  | `---`-'| |'   |  / |        |   | '` ,/  '  :  `--'   \   | |`-'      :   : :    
|   :    / ;  :   .'   \---'    |   :    |;  :   .'   \.'__/\_: ||   :    |        ;   :  .'    :  ,      .-./   ;/          |   | :    
 \   \ .'  |  ,     .-./        /    \  / |  ,     .-./|   :    : \   \  /         |   ,.'       `--`----'   '---'           `---'.|    
  `---`     `--`---'            `-'----'   `--`---'     \   \  /   `----'          '---'                                       `---`    
                                                         `--`-'                                                                         
    
    )"<<std::endl;

    std::cout << "��ӭ��������������!" << std::endl;

    while (getchar() != '\n');

    std::cout << "*******************�볧��֪*******************" << std::endl;
    std::cout << R"(
    1. �������ó�
       �����Ļ��գ����ã����䣬����������
    2. ���¹���
       Ա��ӦƸ�ϸڣ���٣����ͣ���ڣ�����
    3. �����ĸ�
       ������У����Ҹ���
        )" << std::endl;
    std::cout << "**********************************************" << std::endl;

    std::cout << "��ʼ���ģʽ֮��" << std::endl;
    while (getchar() != '\n');

    /**
     * ����ģʽ��ʾ
     */
    std::cout << "*****ί�б�����վǰȥ��������*****" << std::endl;
    //while (getchar() != '\n');
    ProxyPatternDemo();
    /**
     * �̳߳�ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****�����ɳ�3��������ͬʱ��������*****" << std::endl;
    //while (getchar() != '\n');
    thread_local_test();

    /**
     * �Ž�ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****�б���������*****" << std::endl;
    //while (getchar() != '\n');
    test_bridge();
    /**
     *������ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****�����������ж��������*****" << std::endl;
    //while (getchar() != '\n');
    test_explain();

    /**
     * ����ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****����������������Ӧ����Ͱ*****" << std::endl;
    //while (getchar() != '\n');
    FactoryGarbageBin();

    /**
     * ������ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****��������Ͱ*****" << std::endl;
    //while (getchar() != '\n');
    BuilderPattern();

    /**
     * ����ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****���ݲ�ͬ������������͵���Ӧ����ˮ��*****" << std::endl;
    //while (getchar() != '\n');
    //StrategicPatternDemo();

    /**
     * ���ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****һ������������ˮ���ɶ�̨�������*****" << std::endl;
    //while (getchar() != '\n');
    test_composite();
    //StrategicPatternDemo();

    /**
     * ���󹤳�ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****��ȡ������ˮ����һ̨������״̬*****" << std::endl;
    //while (getchar() != '\n');
    AbstractFactory();

    /**
     * ҵ�����ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****���ڹ�����ͬ�Ļ���*****" << std::endl;
    //while (getchar() != '\n');
    BusinessService();

    /**
     *ģ��ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****��ͬ����ˮ�߶��������в�ͬ�Ĵ���*****" << std::endl;
    //while (getchar() != '\n');
    TemplatePatternDemo();

    /**
     * ������ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****������Ͱ��ɸѡ�ܴ��������*****" << std::endl;
    //while (getchar() != '\n');
    test_filter();

    /**
     * ����ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****������Ͱ��ɸѡ�ܴ��������*****" << std::endl;
    //while (getchar() != '\n');
    CommandPatternDemo();

    /**
     * ��Ԫģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****��������*****" << std::endl;
    //while (getchar() != '\n');
    Flyweight();

    /**
     * װ����ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****��װ�ɻ��հ���*****" << std::endl;
    //while (getchar() != '\n');
    Decoration();
    /**
     * ���ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****ѡ��˵�*****" << std::endl;
    //while (getchar() != '\n');
    Menu();

    /**
     * ����ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****ֻ��һ���ܾ���*****" << std::endl;
    //while (getchar() != '\n');
    singleton();

    /**
     * ������ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****�������������������Ա*****" << std::endl;
    //while (getchar() != '\n');
    ChainOfReponsibilityPatternDemo();
    /**
     * ״̬ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****�������������������Ա*****" << std::endl;
    //while (getchar() != '\n');
    ChainOfReponsibilityPatternDemo();

    ///**
    // * �۲���ģʽ
    // */
    //while (getchar() != '\n');
    //std::cout << "*****���µ��Ű��֪ͨ��Ա��*****" << std::endl;
    ////while (getchar() != '\n');
    //MyVisitor my_visitor;
    //my_visitor.chooseProfession();

    /**
     * ������ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****������������*****" << std::endl;
    test_iterator();

    /**
     * ����¼ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****Ա������-�ж���������*****" << std::endl;
    //choose();

    /**
     * ���ع�����ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****����Ӧ�ó�������*****" << std::endl;
    test_intercept();//���ع���

    /**
     * ���ݷ��ʶ���ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****��ȡְԱ��*****" << std::endl;
    DAO();//���ع���
    /**
     * ������ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****��������Ͱ*****" << std::endl;
    DAO();//���ع���
    Adapterfunction();
    /**
     * ������ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****����ɸ��ϸ��*****" << std::endl;
    MyVisitor mv;
    mv.chooseProfession();
    /**
     * �ն���ģʽ
     */
    while (getchar() != '\n');
    std::cout << "*****�����������ȵ���*****" << std::endl;
    EmptyObjectPatternDemo();

    std::cout << R"(
                                     ,-.. _. ,. ,._                 
                                  .-'         .     '.              
                                 /             .      /_./.         
                                '                        '.         
                               .                           '        
                              '            =\ : , \         \       
                             '            '` `   `  =        '      
                             |,.        _\           ',       \     
                             /   \    ."               ',.    /     
                            || ,' `  ,                  ' \_.'      
                            |\ -. / ,       `'":,      /            
                          ,-= .   ,'       '_   `;.    |            
                         /  /  -'            "'`    ,:,             
                      _,/|,'    ,                   '               
               ___,--' | |                    (    /                
          _,-'`        . .      .            , '- _'          .-.   
        ,'              \        .       `,'"`';/.          ,'   )  
      ,`                 .'       :     /  ';\\   '.     ,'    .'   
    ,'                   |.\       ';.'.,. .;.\\  ,..:_'_    .      
   /  .                    '.       .'';_:;'`  '_(        ' '-.     
   |   .                     '.'.,-'   ,       (    '" - ._    )    
  / .   `                      '.             _,'-._        ` (     
 /    .       [lf]             _ |   '      .' '.    ' .  _    )    
                              (:)          '      '        '   '    
)"<<std::endl;
    return 0;
}