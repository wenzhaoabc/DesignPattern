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
 * 线程池模式函数
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
            printf("\r垃圾车%d已行驶里程[%.2lf%%]:",x-100+1, i * 100.0 / (all_block_num - 1));
        }
        else
        {
            printf("\r垃圾车%d到达目的的[%.2lf%%]:",x-100+1, i * 100.0 / (all_block_num - 1));
        }
        int show_num = i * 20 / all_block_num;
        for (int j = 1; j <= show_num; j++)
        {
            std::cout << "█";
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
 * 工厂模式
 */
void FactoryGarbageBin() {
    GarbageFactory garbageFactory;
    // 根据垃圾类型获得相应垃圾桶
    GarbageBin* dryGarbageBin = garbageFactory.get_garbage_bin(Dry);
    // 垃圾桶盛放垃圾
    std::string res = dryGarbageBin->contain_garbage();
    std::cout << res << std::endl;
    delete dryGarbageBin;
}
/**
 * 抽象工厂模式测试
 */
void AbstractFactory() {
    // 从抽象工厂种获取一个工厂
    ConcreteProProcess* pre = new ConcreteProProcess();
    DryPipeLine* dryProcess = pre->CreateDryPipeLine();
    // 获取该工厂的产品
    std::string res = dryProcess->dry_process();
    std::cout << res << std::endl;
}

void singleton()
{
    GeneralManager::getInstance().setName("总经理");
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
        cout << "           1.包装包裹（装饰期模式）          " << endl;
        cout << "           2.生产包裹（享元模式）     " << endl;
        cout << "           3.人员管理（数据访问对象模式）  " << endl;
        cout << "           0.退出                 " << endl;
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
            cout << "请正确输入选项！！\n\n";
    }
}

//装饰器模式，用于包装可回收包裹
void Decoration() {
    cout << endl;
    cout << "==========组装包裹!========" << endl;
    Piece* plasticPiece = new PlasticPiece();//实例化一个蔬菜罐头
    Piece* paperPiece = new PaperPiece();//实例化一个肉罐头
    SmallPiece smallPlasticPiece = SmallPiece(plasticPiece);//生产小型蔬菜罐头
    BigPiece bigPaperPiece = BigPiece(paperPiece);//生产大型肉罐头
    smallPlasticPiece.show();
    bigPaperPiece.show();
    cout << "=======================================\n" << endl;
    cout << "\n\n\n";
}

//装饰器模式，用于生产不同大小和内容的包裹
//其中菜单选择部分为外观模式
void Flyweight() {
    cout << "新增加的包裹类型：\n";
    Kind* rigidPlasticKind = new RigidPlasticKind();
    Kind* softPlasticKind = new SoftPlasticKind();
    MiddlePiece* middlePiece = new MiddlePiece(softPlasticKind);   //生产中型软质塑料包裹
    middlePiece->make();
    Factory* factory = new Factory();

    //外观模式
    cout << " \n\n请输入要生产的包裹类型（输入1-4）         " << endl;
    cout << "===============================================" << endl;
    cout << "                                              " << endl;
    cout << "              1.大型纸质包裹          " << endl;
    cout << "              2.小型纸质包裹          " << endl;
    cout << "              3.大型塑料包裹          " << endl;
    cout << "              4.小型塑料包裹          " << endl;
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

//数据访问对象模式，对职工进行增删改查
void DAO()
{
    printf("-------------------职员信息管理系统-----------------------\n");
    printf("1：初始化管理系统\n");
    printf("2：新增一个职员信息并录入\n");
    printf("3：删除一个职员信息\n");
    printf("4：查找一个职员的成绩\n");
    printf("5：修改一个职员的成绩\n");
    printf("6：清空所有职员信息\n");
    printf("7：打印所有职员信息\n");
    printf("8：退出系统\n");
    printf("------------------ 请输入您的选择1-8 -----------------------\n");

    EmployeeData* data = new EmployeeData;
    init_Employee_Data_m_head(data);
    while (1)
    {
        int num;
        cout << "请输入指令（1-8）,按回车确认：";
        cin >> num;
        switch (num)
        {
        case 1:
            //初始化头节点
            init_Employee_Data_m_head(data);
            cout << "当前指令,即将创建一个职员管理系统并初始化\n";
            printf("初始化职员管理系统成功!\n");
            cout << endl;
            break;
        case 2:
            //新增一个职员并初始化
            cout << "当前指令,即将添加一个职员 \n";
            Employee_Link(data, init_Employee());
            cout << endl;
            break;
        case 3:
            //删除一个职员 
            cout << "当前指令,即将删除一个职员 \n";
            Employee_Delete(data);
            cout << endl;
            break;
        case 4:
            //查询某个职员的成绩
            cout << "当前指令,即将查询一个职员 的成绩\n";
            Employee_Select(data);
            cout << endl;
            break;
        case 5:
            //修改某个 的信息
            cout << "当前指令,即将修改一个职员 的成绩\n";
            Employee_Set(data);
            cout << endl;
            break;
        case 6:
            //清空所有职员数据
            cout << "当前指令,即将删除所有数据\n";
            Free_Employee(data);
            cout << endl;
            break;
        case 7:
            //打印所有职员数据
            cout << "当前指令,打印所有 数据\n";
            Employee_Show(data);
            cout << endl;
            break;
        default:
            cout << "输入指令有误，请重新输入！" << endl;
            break;
        }
        if(num==8)
        {
            break;
        }
    }
}

/**
 *@author 赵帅涛
 *@since 2022年12月16日
 */
int main()
{
    std::cout << "垃圾处理工厂正在启动..." << std::endl;
    
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

    std::cout << "欢迎来到垃圾处理工厂!" << std::endl;

    while (getchar() != '\n');

    std::cout << "*******************入厂须知*******************" << std::endl;
    std::cout << R"(
    1. 垃圾的旅程
       垃圾的回收，放置，运输，处理，再利用
    2. 人事管理
       员工应聘上岗，请假，奖惩，离岗，评价
    3. 工厂改革
       服务调研，自我革新
        )" << std::endl;
    std::cout << "**********************************************" << std::endl;

    std::cout << "开始设计模式之旅" << std::endl;
    while (getchar() != '\n');

    /**
     * 代理模式演示
     */
    std::cout << "*****委托本垃圾站前去处理垃圾*****" << std::endl;
    //while (getchar() != '\n');
    ProxyPatternDemo();
    /**
     * 线程池模式
     */
    while (getchar() != '\n');
    std::cout << "*****工厂派出3辆垃圾车同时运输垃圾*****" << std::endl;
    //while (getchar() != '\n');
    thread_local_test();

    /**
     * 桥接模式
     */
    while (getchar() != '\n');
    std::cout << "*****判别垃圾属性*****" << std::endl;
    //while (getchar() != '\n');
    test_bridge();
    /**
     *解释器模式
     */
    while (getchar() != '\n');
    std::cout << "*****根据垃圾名判断垃圾类别*****" << std::endl;
    //while (getchar() != '\n');
    test_explain();

    /**
     * 工厂模式
     */
    while (getchar() != '\n');
    std::cout << "*****根据垃圾类别放入相应垃圾桶*****" << std::endl;
    //while (getchar() != '\n');
    FactoryGarbageBin();

    /**
     * 建造者模式
     */
    while (getchar() != '\n');
    std::cout << "*****建造垃圾桶*****" << std::endl;
    //while (getchar() != '\n');
    BuilderPattern();

    /**
     * 策略模式
     */
    while (getchar() != '\n');
    std::cout << "*****根据不同的垃圾类别运送到相应的流水线*****" << std::endl;
    //while (getchar() != '\n');
    //StrategicPatternDemo();

    /**
     * 组合模式
     */
    while (getchar() != '\n');
    std::cout << "*****一条垃圾处理流水线由多台机器组成*****" << std::endl;
    //while (getchar() != '\n');
    test_composite();
    //StrategicPatternDemo();

    /**
     * 抽象工厂模式
     */
    while (getchar() != '\n');
    std::cout << "*****获取多条流水线中一台机器的状态*****" << std::endl;
    //while (getchar() != '\n');
    AbstractFactory();

    /**
     * 业务代表模式
     */
    while (getchar() != '\n');
    std::cout << "*****存在功能相同的机器*****" << std::endl;
    //while (getchar() != '\n');
    BusinessService();

    /**
     *模板模式
     */
    while (getchar() != '\n');
    std::cout << "*****不同的流水线对垃圾进行不同的处理*****" << std::endl;
    //while (getchar() != '\n');
    TemplatePatternDemo();

    /**
     * 过滤器模式
     */
    while (getchar() != '\n');
    std::cout << "*****从垃圾桶中筛选能处理的垃圾*****" << std::endl;
    //while (getchar() != '\n');
    test_filter();

    /**
     * 命令模式
     */
    while (getchar() != '\n');
    std::cout << "*****从垃圾桶中筛选能处理的垃圾*****" << std::endl;
    //while (getchar() != '\n');
    CommandPatternDemo();

    /**
     * 享元模式
     */
    while (getchar() != '\n');
    std::cout << "*****生产包裹*****" << std::endl;
    //while (getchar() != '\n');
    Flyweight();

    /**
     * 装饰器模式
     */
    while (getchar() != '\n');
    std::cout << "*****包装可回收包裹*****" << std::endl;
    //while (getchar() != '\n');
    Decoration();
    /**
     * 外观模式
     */
    while (getchar() != '\n');
    std::cout << "*****选择菜单*****" << std::endl;
    //while (getchar() != '\n');
    Menu();

    /**
     * 单例模式
     */
    while (getchar() != '\n');
    std::cout << "*****只有一个总经理*****" << std::endl;
    //while (getchar() != '\n');
    singleton();

    /**
     * 责任链模式
     */
    while (getchar() != '\n');
    std::cout << "*****视请假天数安排审批人员*****" << std::endl;
    //while (getchar() != '\n');
    ChainOfReponsibilityPatternDemo();
    /**
     * 状态模式
     */
    while (getchar() != '\n');
    std::cout << "*****视请假天数安排审批人员*****" << std::endl;
    //while (getchar() != '\n');
    ChainOfReponsibilityPatternDemo();

    ///**
    // * 观察者模式
    // */
    //while (getchar() != '\n');
    //std::cout << "*****更新的排班表通知给员工*****" << std::endl;
    ////while (getchar() != '\n');
    //MyVisitor my_visitor;
    //my_visitor.chooseProfession();

    /**
     * 迭代器模式
     */
    while (getchar() != '\n');
    std::cout << "*****遍历垃圾种类*****" << std::endl;
    test_iterator();

    /**
     * 备忘录模式
     */
    while (getchar() != '\n');
    std::cout << "*****员工考核-判断垃圾种类*****" << std::endl;
    //choose();

    /**
     * 拦截过滤器模式
     */
    while (getchar() != '\n');
    std::cout << "*****跟踪应用程序请求*****" << std::endl;
    test_intercept();//拦截过滤

    /**
     * 数据访问对象模式
     */
    while (getchar() != '\n');
    std::cout << "*****读取职员类*****" << std::endl;
    DAO();//拦截过滤
    /**
     * 适配器模式
     */
    while (getchar() != '\n');
    std::cout << "*****适配垃圾桶*****" << std::endl;
    DAO();//拦截过滤
    Adapterfunction();
    /**
     * 访问者模式
     */
    while (getchar() != '\n');
    std::cout << "*****垃圾筛分细分*****" << std::endl;
    MyVisitor mv;
    mv.chooseProfession();
    /**
     * 空对象模式
     */
    while (getchar() != '\n');
    std::cout << "*****居民服务满意度调研*****" << std::endl;
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