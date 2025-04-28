

#include <iostream>
#include <string>

using namespace std;

struct node
{
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
    // Add courses

    void Add_course() {
        node* newnode = new node;

        cout << "Enter Course id: ";
        cin >> newnode->c_id;

        cin.ignore();
        cout << "Enter Course Name: ";
        getline(cin, newnode->c_name);

        cout << "Enter Credit Hours: ";
        cin >> newnode->cre_hrs;


        if (root == NULL) {
            root = newnode;
        }
        else {
            node* temp = root;

            while (true) {
                if (newnode->c_id < temp->c_id) {
                    if (temp->left == NULL) {
                        temp->left = newnode;
                        break;
                    }
                    temp = temp->left;
                }
                else if (newnode->c_id > temp->c_id) {
                    if (temp->right == NULL) {
                        temp->right = newnode;
                        break;
                    }
                    temp = temp->right;
                }
                else {
                    cout << "Invalid Entery.";
                    return;
                }
            }
        }
    }
    // Add course end
    
    //Search course
    bool Search_course(int search_id) {
              

        if (root == NULL) {
            return false;
        }
        else {
            node* temp = root;

            while (temp != NULL) {
                if (search_id < temp->c_id) {
                  
                     temp = temp->left;
                    
                }
                else if(search_id == temp->c_id){

                     return true;

                }
                else if (search_id > temp->c_id) {
                  
                    temp = temp->right;
                }
                else{

                    return false;
                }
            }
        }
    }
    

    // Search course end
  

    // traversal fun

    void preorder() {
        node* temp = root;

    }
};
int main()
{
    int search_id;
    unsigned int choice;
    Course_info_BST bst;

    do {
        cout << "--------------Menu-------------\n";
        cout << "1. Enter Course data\n";
        cout << "2. Search Course data\n";
        cout << "3. Display\n";
        cout << "4. Count \n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            bst.Add_course();
            break;

        case 2:
            cout << "Enter Course id You want to Search: ";
            cin >> search_id;

            bst.Search_course(search_id);
            break;

        case 3:
           
            break;

        case 4:
           
            break;
      
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (true);


    return 0;
}