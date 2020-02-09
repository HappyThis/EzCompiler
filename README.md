# EzCompiler
一个根本不能用的编译器
---
#### 为啥写这种没有实际用途的烂玩意儿？
1. 正如你们所见，Sophon是我第一个可以称之为项目的作品。其中有一些地方处理的相当糟糕，比如说构建工具的使用，静态库的使用。
2. 写这个编译器的想法来源于编译原理课程。这个项目不但可以作为课程设计，而且可以打破对未知的恐惧。
3. 我对系统的底层非常感兴趣。
4. 我觉得做自己喜欢的项目是一种乐趣。
5. 经过了第一个项目，我已经体会到了完成一个项目是多么令人富成就感。
---
#### 所使用的技术
+ Lel(词法分析)
+ Yacc(语法分析)
+ Scons(项目构建)
+ c++(表达工具)
---
#### 实现功能
+ 静态强类型(可以提供部分隐式类型转换)
+ 基础类型:int|double|char|bool|自定义类型(class)
+ 关键字:class|def|continue|break|return|if...else..|while()...|new
+ 语句:复合语句|控制语句|空语句
+ 运算:() + - x ÷ & | ~ ^ %
+ 逻辑:== < > != <= >= ! && ||
+ 拉链回填(可以处理在拉链过程中产生的类型转换)
+ class支持成员函数(支持返回值) 成员变量 构造函数
+ 自创了三不像语法(c++ python java)
+ 实现了EzVM<del>虚拟机</del>执行编译之后的代码
---
#### 部分语法（先贴一点吧 实在太多）
+ program : %empty | program class
+ class: K_CLASS V_ID S_LBRACE dec_vars dec_funs S_RBRACE
+ dec_vars: %empty | dec_vars dec_var
+ dec_var: val_type id_list S_SEM
+ id_list: id_list S_COM V_ID | V_ID
+ val_type: K_DOUBLE | K_INT | K_CHAR | K_BOOL | V_ID
+ dec_funs: %empty | dec_funs dec_fun
+ dec_fun: K_DEF val_type V_ID S_LPAREN informal_args S_RPAREN cmpd_stat
+ informal_args: %empty | val_types
+ val_types: val_type V_ID | val_types	S_COM	val_type V_ID
+ stat: S_SEM | exp S_SEM	| ctrl_stat | cmpd_stat
---
#### 编译效果
![demo0](https://github.com/HappyThis/EzCompiler/blob/master/screenshot/demo0.png)
![demo1](https://github.com/HappyThis/EzCompiler/blob/master/screenshot/demo1.png)
![demo2](https://github.com/HappyThis/EzCompiler/blob/master/screenshot/demo2.png)
![demo3](https://github.com/HappyThis/EzCompiler/blob/master/screenshot/deme3.png)
![demo4](https://github.com/HappyThis/EzCompiler/blob/master/screenshot/demo4.png)
![demo5](https://github.com/HappyThis/EzCompiler/blob/master/screenshot/deme5.png)
