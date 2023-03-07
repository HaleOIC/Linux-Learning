## Programming C++ in google style

- .h & .cpp 文件创建

使用#define 宏 进行 .h 重复include保护

```
#ifndef THIS_IS_A_HEADER_
#define THIS_IS_A_HEADER_
#endif // THIS_IS_A_HEADER_
```

在头文件中能够include文件来使用具体类型，尽量避免使用前置声明。前置声明仅用在头文件中只使用指针的情况。而且会影响函数的类型匹配。

.cpp 文件的 include顺序如下：

```
#include "this_is_a_header.h" //关联头文件

#include <stdio.h> // c库文件
#include <string> // c++库文件
#include "glog.h" // 其他项目的头文件
#include "same_project_header.h" // 本项目中的其他头文件
```

- 命名规则

创建文件之后就要写具体的内容了，在写内容之前明确如何命名是第一步的。

```
* 通用规则：命名有描述性，尽量少用缩写，例如: DoSpecificThing()
* 文件命名：my_useful_class.h 下滑线连接的具体描述性名字
* 类型命名：采用CamelCase，例: MyUsefulClass
* 变量命名：
** 普通变量：table_name
** 类数据成员: table_name_，结构体成员和普通变量一致
** 常量：const kTableName
** 函数：采用CamelCase: ValidateFuncName()
** 枚举命名：
   enum UrlTableErrors {
    kOK = 0,
    kErrorOutOfMemory,
    kErrorMalformedInput,
   };
** 宏命名：MY_MACRO_THAT_SCARES_SMALL_CHILDREN
** 命名空间：命名独特不冲突即可
```

了解了命名规则，我们按照从大到小的概念来讲讲具体对象的规范

- 命名空间

```
* 将函数包裹在命名空间中，不要使用无意义的类和类静态成员
* 不要修改约定俗成的namespace，如:std
```

- 类

```txt
* 构造函数不要使用虚函数（因为不会调），及时抛出异常，不要有失败初始化这种不确定操作
* 构造函数使用explicit 防止隐式类型转换
* 拷贝构造，赋值构造，移动构造，移动赋值。这些成套使用，要么都不用(可参考题图，使用DISALLOW宏)。
  当类型可能存在浅拷贝等情况时，尤其要注意
* 组合优于继承，has-a比is-a关系更灵活。可以使用override，final等关键字表示出继承方法，便于阅读。
  尽量不适用多继承，如果有看看还有没有其他方法。
* 对于纯方法的类，建议使用Interface作为后缀
* 只在合适的时候使用运算符重载，不要给通俗的运算符赋予让人意外的操作
```

- 函数

```
* 函数参数顺序：输入参数在前，输入能用const就const，输出参数在后。引用参数最好都加上const，如有
  改变的可能，使用指针更直白
* 函数如果超过40行，就考虑能不能进一步分割
* 有类型后置的声明方法了：auto foo(int x) -> int;
* 函数默认参数和重载需要清晰，最好能做到看到调用点就知道是哪个函数
```

说完代码主体，再看看与代码息息相关的存在

- 注释

```
应该始终遵守自注释代码，简洁易懂
* 文件开头要有版权注释（为了开源和负责）
* 类注释：让读者知道这个类大致干了啥
* 不要的注释：代码体现的不用注释重复一遍
* TODO(someone): someone will do it
* 启用注释: //DEPRECATED
```

- 格式

```
* 一行80个字符 最长不超过120
* 正常缩进使用2个空格
* 函数返回类型和函数名在同一行，实在长，形参可以换行。参数直接换行用4个空格缩进。如果首个参数没
  换行，后续参数换了，和首个参数对齐
* 细节可以按照个人的爱好，如果团队有规范，优先遵循团队的规范
```

Google 代码规范中还讲了很多C++的tips

- TIPS

```
* 静态变量和全局变量要慎用。要明确他们的构造和析构顺序，想想有没有不确定性
* 采用Modern C++ 
  * auto
  * nullptr
  * const, constexpr
  * 前置自增，自减
  * 能够使用智能指针，尽量使用智能指针
* 指针的传递代表了所有权的交接，要想清楚谁own对象的生命周期
* RTTI(运行时类型识别) dynamic_cast<**> 能不用就不用，很有可能有其他优化方式
```