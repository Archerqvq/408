// 汉诺塔问题是递归算法的一个经典例子。该问题可以描述为：有三根柱子（A，B，C），其中A柱子上有从小到大依次放置的n个盘子，目标是将所有盘子从A柱子移动到C柱子上，每次只能移动一个盘子，并且在移动过程中大盘子不能放在小盘子上面。

// 汉诺塔问题的递归解决方案基于一个简单的观察：要移动n个盘子，你可以先移动上面的n-1个盘子，将它们放到B柱子上，然后移动最大的盘子到C柱子，最后将那n-1个盘子从B柱子移动到C柱子上。

// 汉诺塔的递归解法可以分为三个步骤：

// 将前n-1个盘子从A移动到B，以C为中转柱子。
// 将最大的盘子（第n个盘子）从A移动到C。
// 将n-1个盘子从B移动到C，以A为中转柱子。
// 递归的基本情况是当只有一个盘子时，可以直接将其从A移动到C。

// 下面是汉诺塔问题的一个递归解法示例代码：
#include <stdio.h>

void hanoi(int n, char from_rod, char to_rod, char aux_rod, int *cnt) {
    (*cnt) = (*cnt) + 1;
    if (n == 1) {
        printf("\n- Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod, cnt);
    printf("\n= Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod, cnt);
}

int main() {
    int n = 3, cnt = 0; // Number of disks
    hanoi(n, 'A', 'C', 'B', &cnt);  // A, B and C are names of rods
    printf("\nIt takes %d times to finish %d layer(s) hanoi\n", cnt, n);
    
    return 0;
}