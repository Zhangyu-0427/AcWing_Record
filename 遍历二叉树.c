#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct {
    Node* nodes[35];
    int head;
    int tail;
}queue;

queue* init_queue() {
    queue* q = (queue*)malloc(sizeof(*q));
    q->head = 0;
    q->tail = 0;
    return q;
}

int queue_empty(queue* q) { return q->head == q->tail; }

void queue_push(queue* q, Node* n) { q->nodes[q->tail++] = n; }

Node* queue_pop(queue* q) { return q->nodes[q->head++]; }

int n, PostOrder[35], InOrder[35];

// DFS模拟：找后序遍历中的根 + 中序遍历中的根所分割成的 左子树 + 根 + 右子树
Node* dfs(int rootIndex, int l, int r) {
    if (l > r)
        return NULL;

    Node* root = (Node*)malloc(sizeof(Node));
    root->data = PostOrder[rootIndex];
    int div = l - 1;
    while (InOrder[++div] != PostOrder[rootIndex]);

    root->right = dfs(rootIndex - 1, div + 1, r); // 右子树
    root->left = dfs(rootIndex - (r - div) - 1, l, div - 1); // 左子树
    return root;
}

// BFS遍历二叉树
void LevelOrder(Node* root) {
    queue* q = init_queue();
    queue_push(q, root);
    while (!queue_empty(q)) {
        Node* front = queue_pop(q);
        printf("%d ", front->data);
        if (front->left)
            queue_push(q, front->left);
        if (front->right)
            queue_push(q, front->right);
    }
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &PostOrder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &InOrder[i]);

    Node* root = dfs(n - 1, 0, n - 1);
    LevelOrder(root);

    return 0;
}