### 如题，底层本身就给了这么一个接口
首先要添加头文件typeinfo

其次调用typeid(variable).name() 即可得到类型名，由于编译器的原因，可能不是完全的类型名，如string类型传入，得到的name()是Ss，int得到的是i
> 显然这typeid(variable)返回的是一个类型。