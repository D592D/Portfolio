//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Daniel Dyall
// Version     : 1.3
// Description : CS-300 Project Two - ABCU Advising Assistance Program
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

//============================================================================
// Course structure
//============================================================================

/*
 * Stores one course record from the advising input file.
 */
struct Course {
    string courseId;
    string title;
    vector<string> prerequisites;

    Course() {
        courseId = "";
        title = "";
    }
};

//============================================================================
// Helper functions
//============================================================================

/*
 * Removes leading and trailing whitespace.
 */
string trim(const string& text) {
    size_t first = text.find_first_not_of(" \t\r\n");
    if (first == string::npos) {
        return "";
    }

    size_t last = text.find_last_not_of(" \t\r\n");
    return text.substr(first, last - first + 1);
}

/*
 * Converts a string to uppercase for course lookup.
 */
string toUpperCase(string text) {
    for (size_t i = 0; i < text.size(); ++i) {
        text[i] = static_cast<char>(toupper(static_cast<unsigned char>(text[i])));
    }
    return text;
}

/*
 * Splits a simple CSV line using commas.
 */
vector<string> splitCSVLine(const string& line) {
    vector<string> tokens;
    string token;
    stringstream stream(line);

    while (getline(stream, token, ',')) {
        tokens.push_back(trim(token));
    }

    return tokens;
}

/*
 * Reads and validates a menu choice.
 */
int getMenuChoice() {
    int choice;
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }

    return choice;
}

//============================================================================
// Binary Search Tree node
//============================================================================

/*
 * Represents one node in the binary search tree.
 */
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }

    Node(const Course& aCourse) : Node() {
        course = aCourse;
    }
};

//============================================================================
// Binary Search Tree class
//============================================================================

/*
 * Stores Course objects in a binary search tree by course ID.
 */
class BinarySearchTree {
private:
    Node* root;

    void addNode(Node* node, const Course& course);
    void inOrder(Node* node) const;
    void clear(Node*& node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void Insert(const Course& course);
    Course Search(const string& courseId) const;
    void InOrder() const;
    bool IsEmpty() const;
    void Clear();
};

/*
 * Constructs an empty tree.
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

/*
 * Destroys the tree and frees memory.
 */
BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

/*
 * Clears all nodes from the tree.
 */
void BinarySearchTree::Clear() {
    clear(root);
}

/*
 * Recursive helper to clear the tree.
 */
void BinarySearchTree::clear(Node*& node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }
}

/*
 * Returns true if the tree is empty.
 */
bool BinarySearchTree::IsEmpty() const {
    return root == nullptr;
}

/*
 * Inserts a course into the tree.
 */
void BinarySearchTree::Insert(const Course& course) {
    if (root == nullptr) {
        root = new Node(course);
    }
    else {
        addNode(root, course);
    }
}

/*
 * Recursive helper to insert a course into the tree.
 */
void BinarySearchTree::addNode(Node* node, const Course& course) {
    if (course.courseId < node->course.courseId) {
        if (node->left == nullptr) {
            node->left = new Node(course);
        }
        else {
            addNode(node->left, course);
        }
    }
    else if (course.courseId > node->course.courseId) {
        if (node->right == nullptr) {
            node->right = new Node(course);
        }
        else {
            addNode(node->right, course);
        }
    }
    else {
        node->course = course;
    }
}

/*
 * Searches for a course by course ID.
 */
Course BinarySearchTree::Search(const string& courseId) const {
    string key = toUpperCase(courseId);
    Node* current = root;

    while (current != nullptr) {
        if (current->course.courseId == key) {
            return current->course;
        }

        if (key < current->course.courseId) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return Course();
}

/*
 * Prints all courses in sorted order.
 */
void BinarySearchTree::InOrder() const {
    inOrder(root);
}

/*
 * Recursive in-order traversal.
 */
void BinarySearchTree::inOrder(Node* node) const {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->course.courseId << ", " << node->course.title << endl;
        inOrder(node->right);
    }
}

//============================================================================
// Application functions
//============================================================================

/*
 * Loads course data from a CSV file into the binary search tree.
 * Returns true if the file was opened and processed successfully.
 */
bool loadCourses(const string& fileName, BinarySearchTree& courseTree) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: Could not open file \"" << fileName << "\"." << endl;
        return false;
    }

    courseTree.Clear();

    string line;
    while (getline(file, line)) {
        line = trim(line);

        if (line.empty()) {
            continue;
        }

        vector<string> tokens = splitCSVLine(line);
        if (tokens.size() < 2) {
            continue;
        }

        Course course;
        course.courseId = toUpperCase(tokens[0]);
        course.title = trim(tokens[1]);

        if (course.courseId.empty() || course.title.empty()) {
            continue;
        }

        for (size_t i = 2; i < tokens.size(); ++i) {
            string prereq = toUpperCase(trim(tokens[i]));
            if (!prereq.empty()) {
                course.prerequisites.push_back(prereq);
            }
        }

        courseTree.Insert(course);
    }

    file.close();
    return true;
}

/*
 * Prints all courses in alphanumeric order.
 */
void printCourseList(const BinarySearchTree& courseTree) {
    cout << "Here is a sample schedule:" << endl << endl;
    courseTree.InOrder();
}

/*
 * Prints the selected course and its prerequisites.
 * The first line after Prerequisites keeps the sample style,
 * and additional lines include prerequisite titles for rubric alignment.
 */
void printCourseInformation(const BinarySearchTree& courseTree, const string& courseId) {
    Course course = courseTree.Search(courseId);

    if (course.courseId.empty()) {
        cout << "Course " << toUpperCase(courseId) << " not found." << endl;
        return;
    }

    cout << course.courseId << ", " << course.title << endl;

    if (course.prerequisites.empty()) {
        cout << "Prerequisites: None" << endl;
        return;
    }

    cout << "Prerequisites: ";
    for (size_t i = 0; i < course.prerequisites.size(); ++i) {
        cout << course.prerequisites[i];
        if (i < course.prerequisites.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    for (size_t i = 0; i < course.prerequisites.size(); ++i) {
        Course prerequisite = courseTree.Search(course.prerequisites[i]);
        if (!prerequisite.courseId.empty()) {
            cout << prerequisite.courseId << ", " << prerequisite.title << endl;
        }
    }
}

/*
 * Displays the user menu.
 */
void displayMenu() {
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl << endl;
    cout << "What would you like to do? ";
}

//============================================================================
// Main
//============================================================================

int main() {
    BinarySearchTree courseTree;
    bool dataLoaded = false;
    int choice = 0;

    cout << "Welcome to the course planner." << endl << endl;

    while (choice != 9) {
        displayMenu();
        choice = getMenuChoice();

        if (choice == -1) {
            cout << "\nThat is not a valid option.\n" << endl;
            continue;
        }

        cout << endl;

        switch (choice) {
        case 1: {
            string fileName;
            cout << "Enter the file name that contains the course data: ";
            cin.ignore();
            getline(cin, fileName);
            cout << endl;

            dataLoaded = loadCourses(fileName, courseTree);
            cout << endl;
            break;
        }

        case 2:
            if (!dataLoaded || courseTree.IsEmpty()) {
                cout << "Please load the data structure first." << endl << endl;
            }
            else {
                printCourseList(courseTree);
                cout << endl << endl;
            }
            break;

        case 3:
            if (!dataLoaded || courseTree.IsEmpty()) {
                cout << "Please load the data structure first." << endl << endl;
            }
            else {
                string courseId;
                cout << "What course do you want to know about? ";
                cin >> courseId;
                printCourseInformation(courseTree, toUpperCase(courseId));
                cout << endl << endl;
            }
            break;

        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;

        default:
            cout << choice << " is not a valid option." << endl << endl;
            break;
        }
    }

    return 0;
}