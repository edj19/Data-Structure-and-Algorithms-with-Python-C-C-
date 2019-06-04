# 线性表的链式表示和实现

线性表的顺序存储结构是逻辑位置和物理位置都相邻，而链式存储结构是逻辑位置相邻，但物理位置不一定相邻，相比顺序存储结构，它不能随机存取，但是在插入和删除操作时不需要移动元素，大大提高了增加和删除元素的效率。



通常链式存储结构会有一个个结点组成，结点中包含两个域一个是数据域，一个是指针域，数据域中存储数据，指针域中存储下一个后继元素的地址，如下图所示，这一个个结点组成链表，也称线性链表或者单链表。

![fig1](<https://github.com/edj19/Data-Structure-and-Algorithms_edj/blob/master/figures/fig_01.jpg>)

单链表的逻辑结构如下图所示

![fig2](<https://github.com/edj19/Data-Structure-and-Algorithms_edj/blob/master/figures/fig_2.jpg>)



除了单链表之外还有循环链表和双向链表，循环链表的特点是最后一个结点的指针指向头结点，形成一个环，双向链表的特点是结点中多了一个指向前驱元素的指针，这两种链表的逻辑结构如下面两张图所示：

**循环链表**

![fig3](<https://github.com/edj19/Data-Structure-and-Algorithms_edj/blob/master/figures/fig_03.jpg>)

**双向链表**

![fig4](<https://github.com/edj19/Data-Structure-and-Algorithms_edj/blob/master/figures/fig_04.jpg>)

