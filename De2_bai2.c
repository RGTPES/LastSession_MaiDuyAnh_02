#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct Contact {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

typedef struct TreeNode {
    Contact data;
    struct TreeNode *left, *right;
} TreeNode;
TreeNode* createTree(Contact c) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = c;
    node->left = NULL;
    node->right = NULL;
    return node;

}
TreeNode* insert(TreeNode* root, Contact c) {
    if (root == NULL) {
        return createTree(c);
    }
    if (strcmp(c.name, root->data.name) < 0) {
        root->left = insert(root->left, c);
    } else if (strcmp(c.name, root->data.name) > 0) {
        root->right = insert(root->right, c);
    }
    return root;
}
void inOder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOder(root->left);
    printf("%s\n", root->data.name);
    printf("%s\n", root->data.phone);
    printf("%s\n", root->data.email);
    inOder(root->right);
}
TreeNode* search(TreeNode* root, char* name) {
    if (root == NULL || strcmp(root->data.name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->data.name) < 0) {
        return search(root->left, name);
    }
        return search(root->right, name);


}
TreeNode* find(TreeNode* root) {
    while (root != NULL) {
        root = root->left;

    }
    return root;
}



int main() {
    TreeNode* root=NULL;
    int choice = 0;
    Contact c;
    char name[50];
    do {
        printf("\n1. Them vao danh ba \n");
        printf("2. Hien thi danh ba theo ABC\n");
        printf("3. Tim nguoi theo ten \n");
        printf("4. Xoa nguoi theo ten \n");
        printf("5. EXIT\n");
        printf("Moi ban nhapp lua chon: \n");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Nhap  ten: \n");
                fgets(c.name, 50, stdin);
                c.name[strcspn(c.name, "\n")] = 0;
                printf("Nhap sdt: \n");
                fgets(c.phone, 15, stdin);
                c.phone[strcspn(c.phone, "\n")] = 0;
                printf("Nhap email: \n");
                fgets(c.email, 50, stdin);
                c.email[strcspn(c.email, "\n")] = 0;
                    if (search(root,c.name)) {
                        printf("Da ton tai danh ba \n");
                    }else {
                        root = insert(root,c);

                    }
                break;
            case 2:
                if (root == NULL) printf("Danh ba Rong ");
                inOder(root);

                break;
            case 3:
                printf("Moi ban nhap ten:  \n");
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;
                TreeNode* found = search(root, name);
                if (found) {
                    printf("%s",found->data.name);
                    printf("%s",found->data.phone);
                    printf("%s",found->data.email);
                }else {
                    printf("ko tim thay \n");
                }
            break;
            case 4:
                break;
                default:
                printf("Nhap lai \n");
                break;
        }
    }while (choice != 5);
    return 0;
}