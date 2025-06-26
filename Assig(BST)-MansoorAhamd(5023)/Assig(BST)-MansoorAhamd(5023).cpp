#include <iostream>
#include <string>

using namespace std;

struct node {
    int c_id;
    string c_name;
    int cre_hrs;

    node* left;
    node* right;

    node() {
        left = right = NULL;
    }
};

class Course_info_BST {
    node* root;

public:
    Course_info_BST() {
        root = NULL;
    }

    // Add a new course
    void Add_course() {
        node* newnode = new node;

        cout << "Enter Course ID: ";
        cin >> newnode->c_id;

        cin.ignore();
        cout << "Enter Course Name: ";
        getline(cin, newnode->c_name);

        cout << "Enter Credit Hours: ";
        cin >> newnode->cre_hrs;

        if (root == NULL) {
            root = newnode;
        } else {
            node* temp = root;
            while (true) {
                if (newnode->c_id < temp->c_id) {
                    if (temp->left == NULL) {
                        temp->left = newnode;
                        break;
                    }
                    temp = temp->left;
                } else if (newnode->c_id > temp->c_id) {
                    if (temp->right == NULL) {
                        temp->right = newnode;
                        break;
                    }
                    temp = temp->right;
                } else {
                    cout << "Duplicate Course ID not allowed.\n";
                    delete newnode;
                    return;
                }
            }
        }
    }

    // Search for a course by ID
    bool Search_course(int search_id) {
        node* temp = root;

        while (temp != NULL) {
            if (search_id < temp->c_id) {
                temp = temp->left;
            } else if (search_id == temp->c_id) {
                return true;
            } else {
                temp = temp->right;
            }
        }
        return false;
    }

    // Return the root node
    node* giveroot() {
        return root;
    }

    // Helper function to find minimum value in right subtree
    node* findMin(node* temp) {
        while (temp && temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    // Recursive function to delete a node
    node* deleteNode(node* root, int key) {
        if (root == NULL) {
            cout << "Course with ID " << key << " not found.\n";
            return root;
        }

        if (key < root->c_id) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->c_id) {
            root->right = deleteNode(root->right, key);
        } else {
            // Found the node to delete
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->left == NULL) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                node* temp = root->left;
                delete root;
                return temp;
            } else {
                node* temp = findMin(root->right);
                root->c_id = temp->c_id;
                root->c_name = temp->c_name;
                root->cre_hrs = temp->cre_hrs;
                root->right = deleteNode(root->right, temp->c_id);
            }
        }
        return root;
    }

    // Public interface to delete a course
    void deleteCourse(int id) {
        root = deleteNode(root, id);
        cout << "Deletion process complete.\n";
    }

    // Inorder traversal of BST
    void inorder(node* root) {
        if (root == NULL) return;

        inorder(root->left);
        cout << "Course ID: " << root->c_id
             << "\tCourse Name: " << root->c_name
             << "\tCredit Hours: " << root->cre_hrs << endl;
        inorder(root->right);
    }
};

int main() {
    unsigned int choice;
    Course_info_BST bst;
    int course_count = 0;

    do {
        cout << "\n-------------- Course Management Menu -------------\n";
        cout << "1. Add Course\n";
        cout << "2. Search Course\n";
        cout << "3. Display All Courses\n";
        cout << "4. Count Courses\n";
        cout << "5. Delete Course\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                do {
                    bst.Add_course();
                    course_count++;

                    char choic;
                    cout << "\nDo you want to enter another course? (Y/N): ";
                    cin >> choic;
                    cout << endl;
                    if (!(choic == 'y' || choic == 'Y'))
                        break;
                } while (true);
                break;

            case 2: {
                int search_id;
                cout << "Enter Course ID to Search: ";
                cin >> search_id;
                if (bst.Search_course(search_id)) {
                    cout << "\n✔ Course Found with ID: " << search_id << endl;
                } else {
                    cout << "\n✘ Course Not Found.\n";
                }
                break;
            }

            case 3:
                cout << "All Courses (Inorder Traversal):\n";
                bst.inorder(bst.giveroot());
                break;

            case 4:
                cout << "Number of courses: " << course_count << endl;
                break;

            case 5: {
                int delete_id;
                cout << "Enter Course ID to Delete: ";
                cin >> delete_id;
                bst.deleteCourse(delete_id);
                course_count--;  // optional: be careful if deletion fails
                break;
            }

            case 6:
                cout << "Exiting...\n";
                exit(0);
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (true);

    return 0;
}
