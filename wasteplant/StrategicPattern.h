#pragma once
//创建垃圾处理抽象类，即接口
class WasteDisposal;
//创建干垃圾处理的策略抽象类
class DryWasteDisposal;
//创建湿垃圾处理的策略抽象类
class WetWasteDisposal;
//创建可回收垃圾处理的策略抽象类
class RecoverWasteDisposal;
//创建有害垃圾处理的策略抽象类
class HarmfulWasteDisposal;
//创建上下文类，根据垃圾类型使得垃圾处理的实现接口自动选择策略去处理垃圾
class Waste;
//策略模式实现函数
void StrategicPatternDemo();

