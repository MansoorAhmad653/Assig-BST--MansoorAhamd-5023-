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
    
    //Giving Root
    node* giveroot() {
        return root;
    }
    //Giving Root end
    
    // Delete Course
    void deleteCourse( int delcour) {
        node* temp = root;
        if (delcour == temp->c_id) {
            temp = temp -> left;
            delete temp;
        }
    }
    // Delete Course end
    
    // traversal function
    void preorder(struct node *root) {
        node *temp = root;
        if (temp == NULL) {
            return;
        }
        preorder(temp->left);
        cout <<"\t Course id: "<< temp->c_id << "\tCourse Name: "<< temp->c_name << "\t Credit Hours: " << temp->cre_hrs << endl;
        preorder(temp->right);
    }
    // traversal function end
};
int main()
{
    unsigned int choice, course_count = 0;
    Course_info_BST bst;

    do {
        cout << "--------------Menu-------------\n";
        cout << "1. Add Course data.\n";
        cout << "2. Search Course.\n";
        cout << "3. Display.\n";
        cout << "4. Count Courses.\n";
        cout << "5. Delete Course.\n";
        cout << "6. Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            do {

                bst.Add_course();
                course_count++;

                char choic;
                cout << "\nDo you want to Enter Another Course(Y/N)?";
                cin >> choic;
                cout << endl;
                if (!(choic == 'y' || choic == 'Y')){

                    break;
                }
              
            } while (true);
            break;

        case 2:
            int search_id;

            cout << "Enter Course id You want to Search: ";
            cin >> search_id;

            if(bst.Search_course(search_id)){

                cout<<"\n ******************** Course is found with Course id: "<< search_id<<" ******************** " << endl;

                break;
            }
            else {
                cout<<"\n******************** Course is not found. ******************** "<<endl;
                break;
            }

        case 3:
            bst.preorder(bst.giveroot());

            break;

        case 4:
            cout << "Number of Course are " << course_count << endl;
            
            break;
        case 5:
            int delete_id;

            cout << "Enter Course id You want to delete: ";
            cin >> delete_id;
            bst.deleteCourse(delete_id);
            break;
        case 6:
            exit(-1);
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (true);


    return 0;
}