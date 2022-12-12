#pragma once
//年末居民评价表实体类ResidentEvaluationForm
class ResidentEvaluationForm;
////创建抽象类PrintREF打印年末居民评价表
class PrintREF;
//创建扩展了抽象类PrintREF的实体类RealPrintREF
class RealPrintREF;
//创建扩展了抽象类PrintREF的空类NullPrintREF
class NullPrintREF;
//创建PrintREFDemo类，用来获取实体类或空类的实例
class PrintREFDemo;
//空对象模式的实现函数
void EmptyObjectPatternDemo();
