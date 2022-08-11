- &是取地址，*是解引用
- 对于单个的L来说

  - L是SqList类型的结构体
  - 单个L是SqList类型存的地址，SqList \*L是 SqList\*类型，是结构体指针
  - 当是L或者&L(L的地址)时用圆点符取成员值，~~且传入形参不改变实参（C语言？不知道对不对）~~   C++用&是引用传递也改变实参
  - 当是\*L时已解应用 用->取成员 改变形参就改变实参
- C语言

  表达式必须具有结构或联合类型，但它具有类型 "SqList *"C/C++(154)

  ```C
  //错误代码
  void InitList(SqList *L){
      //L.data = new ElemType [MAX_LENGTH];
      L.data = (ElemType *)malloc(MAX_LENGTH*sizeof(ElemType));
      L.length = 0;
  }

  //正确的
  L->data = (ElemType *)malloc(MAX_LENGTH*sizeof(ElemType));
  L->length = 0;
  ```
- 运算符 -> 或 ->* 应用于 "SqList" 而不是指针类型C/C++(3364)

  ```C
  //错误代码
  int Length(SqList L){
      return L->length;
  }
  //正确的
  return L.length;
  ```
