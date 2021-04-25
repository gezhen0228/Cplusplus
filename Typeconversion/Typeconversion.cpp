#include <iostream>
/* c++中的四种类型转换
  1. static_cast
  2. reinterpret_cast
  3. dynamic_cast
  4. const_cast
*/

/*
  1. static_cast
    语法：static_cast<type-id> (expression)
      编译时处理
  (1) 基本数据类型转换
  (2) 父类指针和子类指针(引用)的转换(将子类指针转化为父类指针(引用) 
  (3) 把空指针转换成目标类型的空指针
  (4) 把任何类型的表达式转换为void类型
   
   备注：static_cast 不能去除类型的 const 或者 volatile 属性；不能进行无关类型转换（如非基类和子类）。
*/

// 1.1 基本数据类型转换
void static_cast_test_for_basic_type() {
  int i = 1;
  double j = static_cast <double> (i);
  std::cout << "i = " << i << std::endl;
  std::cout << "j = " << j << std::endl;
}

// 1.2  父类指针和子类指针的转换
class Base { };
class Derived : public Base { };
Base *p1 = new Base;
Derived *d1 = new Derived;

// Derived *d2 = static_cast<Base*>(p1); //error 
// (进行下行转换（把基类的指针或引用转换为派生类表示）
//由于没有动态类型检查，所以是不安全的)
Base *p2 = static_cast<Derived*>(d1);

/*
  2. reinterpret_cast
    语法：reinterpret_cast<type_id> (expression)
         编译时处理
    type-id必须是一个指针、引用、算术类型、函数指针或者成员指针。
  (1) 改变指针或者引用的类型
  (2) 将指针或引用转换为一个足够长度的整型 
  (3) 将整型转换为指针或引用类型

   备注：使用reinterpret_cast强制转换过程仅仅只是比特位的拷贝
*/

void reinterpret_cast_test() {
  int *a = new int;
  double *d = reinterpret_cast<double*>(a);
}

/*
  3. dynamic_cast
    语法：dynamic_cast<type_id> (expression)
          运行时处理，运行时要进行类型检查。
          type_id内部所描述的目标类型必须为指针或引用
    (1) 只能用于对象指针之间的转换
    (2) 不能用于内置的基本数据类型的强制转换
    (3) dynamic_cast转换如果成功的话返回的是指向类的指针或引用，转换失败的话则会返回NULL
    (4) 使用dynamic_cast进行转换的，基类中一定要有虚函数，否则编译不通过。
         基类中需要检测有虚函数的原因：类中存在虚函数，就说明它有想要让基类指针或引用指向派生类对象的情况，此时转换才有意义。
         由于运行时类型检查需要运行时类型信息，而这个信息存储在类的虚函数表中，只有定义了虚函数的类才有虚函数表。
    (5) 在类的转换时，在进行下行转换时(即将父类指针转化子类指针)，dynamic_cast具有类型检查的功能，比static_cast更安全。
*/

/*
  4. const_cast
     语法：const_cast<type_id> (expression)
     修改类型的const或volatile属性。除了const 或volatile修饰之外， type_id和expression的类型是一样的。
     const_cast不是用于去除变量的常量性，而是去除指向常数对象的指针或引用的常量性，其去除常量性的对象必须为指针或引用。
    (1) 常量指针被转化成非常量指针，并且仍然指向原来的对象；
    (2) 常量引用被转换成非常量引用，并且仍然指向原来的对象；常量对象被转换成非常量对象。
*/

void const_cast_test() {
  const int a = 10;
  const int *p = &a;
  int *q;
  q = const_cast<int*>(p);
  *q = 20; 
}

int main()
{
  static_cast_test_for_basic_type();
  return 0;
}
