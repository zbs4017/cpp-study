# 构造函数不可以是虚拟函数
1. 从语义上说不可以，因为虚函数本身就是为了实现多态，需要使用构造函数构造出完整的实例，使用指针或者引用，来调用虚函数，从而实现多态。在构造函数上使用多态不是很合理
2. 从实现上，虚函数表在只读数据段，不同的类有不同的续表，同一个类的不同实例指向同一个虚表。而构建对象，让实例的指针指向虚表，这个过程是在构造函数中完成的。

并且，这个似乎是C++标准的规定。
如果我们这么写，会直接报错
# 构造函数中调用虚拟函数
