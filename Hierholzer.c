#include <stdio.h>
#include <stdlib.h>

#define MAX_V 501
#define MAX_E 2000

int adj[MAX_V][MAX_E];   // 邻接表
int size[MAX_V] = {0};   // 每个顶点的邻接点数量
int stack[2*MAX_E];    // 栈用于Hierholzer算法
int top = 0;
int path[2*MAX_E];     // 存储最终路径
int path_size = 0;

// 比较函数：降序排列，确保每次取最小的顶点
int compare_ints(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

// 二分查找在降序数组中找到第一个匹配项的位置
int find_position(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            // 向左找到第一个出现的位置
            while (mid > 0 && arr[mid - 1] == key) mid--;
            return mid;
        } else if (arr[mid] > key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void hierholzer(int start) {
    stack[top++] = start;  // 初始节点入栈
    while (top > 0) {
        int u = stack[--top];  // 弹出栈顶
        if (size[u] == 0) {
            path[path_size++] = u;  // 无未访问边，加入路径
        } else {
            // 取邻接表中最后一个元素（最小顶点）
            int v = adj[u][--size[u]];  
            // 删除反向边v->u
            int pos = find_position(adj[v], size[v], u);
            if (pos != -1) {
                // 将后面的元素前移覆盖pos
                for (int i = pos; i < size[v] - 1; i++) {
                    adj[v][i] = adj[v][i + 1];
                }
                size[v]--;
            }
            // 重新压栈u，并压入v
            stack[top++] = u;
            stack[top++] = v;
        }
    }
}

int main() {
    int e;
    scanf("%d", &e);

    // 初始化邻接表
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    // 对每个顶点的邻接表降序排序
    for (int i = 1; i < MAX_V; i++) {
        if (size[i] > 0) {
            qsort(adj[i], size[i], sizeof(int), compare_ints);
        }
    }

    // 寻找起点：奇数度顶点或最小编号顶点
    int start = 1;
    int count = 0;
    for (int i = 1; i < MAX_V; i++) {
        if (size[i] % 2 != 0) {
            count++;
            start = i;  // 取第一个奇数度顶点
            break;
        }
    }
    if (count == 0) {
        // 全为偶数度，找到第一个有边的顶点
        while (start < MAX_V && size[start] == 0) start++;
    }

    hierholzer(start);

    // 逆序输出路径
    for (int i = path_size - 1; i >= 0; i--) {
        printf("%d\n", path[i]);
    }

    return 0;
}