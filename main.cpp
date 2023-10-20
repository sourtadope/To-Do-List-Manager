#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task{
    string taskName;
    int year;

    Task(string taskName, int year) {
        this->taskName = taskName; this->year = year;
    }

    string toString() const {
        return "Task(" + taskName + ", " + to_string(year) + ")";
    }
};

void addTask(vector<Task> &tasks);
void displayAllTasks(vector<Task> &tasks);
void deleteTask(vector<Task> &tasks, string& taskName);
void searchTasks(vector<Task> &tasks);


int main()
{
    vector<Task> tasks;
    int option; 
    while(true)
    {
        cout << "\n";
        cout << "To-do list manager:" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Display all tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;


        if (option == 1) {
            addTask(tasks);            
        } else if (option == 2) {
            displayAllTasks(tasks);
        } else if (option == 3) {
            string deletingBookName;
                cout << "Enter a name of deleting task: ";
                
                cin >> deletingBookName;

                deleteTask(tasks, deletingBookName);

        } else if (option == 4) {
            searchTasks(tasks);

        } else if (option == 5) {
            break;

        } else{
            break;
        }

    }
}


void addTask(vector<Task> &tasks) {
    string taskName;
    int year;

    cout << "Enter a name of a task: ";
    cin.ignore();
    getline(cin, taskName);

    cout << "Enter a due date of the task(DD): ";
    cin >> year;
    cin.ignore();
    tasks.push_back(Task(taskName, year));
}




void displayAllTasks(vector<Task> &tasks) {
    for (Task& currentTask: tasks) {
        cout << currentTask.toString();
    }
}

void deleteTask(vector<Task> &tasks, string &taskName) {
    int index = 1;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].taskName == taskName) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        tasks.erase(tasks.begin() + index);
    } else {
        cout << "Task not found!" << endl;
    }
}


void searchTasks(vector<Task> &tasks) {
    string taskName;
    cout << "Enter a name of the task you want to search: ";
    cin.ignore(); 
    getline(cin, taskName); 

    bool found = false;
    for (const Task& task: tasks) {
        if (task.taskName == taskName) {
            cout << task.toString() << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Task not found!" << endl;
    }
}
