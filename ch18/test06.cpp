/*********************************8
Lambda 表达式的定义形式如下：

[外部变量访问方式说明符] (参数表) -> 返回值类型
{
   语句块
}

下面是一个合法的Lambda表达式：

[=] (int x, int y) -> bool {return x%10 < y%10; }
Lambda 表达式实际上是一个函数，只是它没有名字。下面的程序段使用了上面的 Lambda 表达式：

    int a[4] = {11, 2, 33, 4};
    sort(a, a+4, [=](int x, int y) -> bool { return x%10 < y%10; } );
    for_each(a, a+4, [=](int x) { cout << x << " ";} );


下面是用到了外部变量的Lambda表达式的程序：

    #include <iostream>
    #include <algorithm>
    using namespace std;
    int main()
    {
        int a[4] = { 1, 2, 3, 4 };
        int total = 0;
        for_each(a, a + 4, [&](int & x) { total += x; x *= 2; });
        cout << total << endl;  //输出 10
        for_each(a, a + 4, [=](int x) { cout << x << " "; });
        return 0;
    }

[&]表示该 Lambda 表达式中用到的外部变量 total 是传引用的，其值可以在表达式执行过程中被改变
（如果使用[=]，编译无法通过）

实际上，“外部变量访问方式说明符”还可以有更加复杂和灵活的用法。例如：

    [=, &x, &y]表示外部变量 x、y 的值可以被修改，其余外部变量不能被修改；
    [&, x, y]表示除 x、y 以外的外部变量，值都可以被修改。


例如下面的程序：

    #include <iostream>
    using namespace std;
    int main()
    {   
        int x = 100,y=200,z=300;
        auto ff  = [=,&y,&z](int n) {
            cout <<x << endl;
            y++; z++;
            return n*n;
        };
        cout << ff(15) << endl;
        cout << y << "," << z << endl;
    }

程序的输出结果如下：
100
225
201, 301

第 6 行定义了一个变量 ff，ff 的类型是 auto，表示由编译器自动判断其类型（这也是 C++11 的新特性）。本行将一个 Lambda 表达式赋值给 ff，以后就可以通过 ff 来调用该 Lambda 表达式了。

第 11 行通过 ff，以 15 作为参数 n 调用上面的 Lambda 表达式。该 Lambda 表达式指明，对于外部变量 y、z，可以修改其值；对于其他外部变量，例如 x，不能修改其值。因此在该表达式执行时，可以修改外部变量 y、z 的值，但如果出现试图修改 x 值的语句，就会编译出错。

**********************************/

#include <iostream>

template <typename T>
void Show2(double x, T& fp)
{
	std::cout<<x<<" -> "<<fp(x)<<"\n";
}

double f1(double x)
{
	return 1.8*x+32;
}

template <typename T>
void Show3(double x, T fp)
{
    std::cout<<x<<" -> "<<fp(x)<<"\n";
}
int main()
{
	Show2(18.0,f1);
    Show3(18.0, [=](double x){return 1.8*x+32;});
	return 0;
}