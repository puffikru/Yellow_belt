#include <iostream>
#include <tuple>
#include <map>
#include <utility>
#include <sstream>
#include <vector>


using namespace std;

enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;

ostream& operator <<(ostream& out, const TaskStatus& status) {
    string statusName;
    switch (status) {
        case TaskStatus::NEW:
            statusName = "\"NEW\"";
            break;
        case TaskStatus::IN_PROGRESS:
            statusName = "\"IN_PROGRESS\"";
            break;
        case TaskStatus::TESTING:
            statusName = "\"TESTING\"";
            break;
        case TaskStatus::DONE:
            statusName = "\"DONE\"";
            break;
    }
    return out << statusName;
}


class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        if(developers.count(person) > 0){
            return developers.at(person);
        }
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        developers[person][TaskStatus::NEW]++;
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count) {
        TasksInfo updated_tasks;
        TasksInfo remaining_tasks;

        if(task_count > 0) {
            if (developers[person][TaskStatus::NEW] != 0) {
                if (task_count >= developers[person][TaskStatus::NEW]) {
                    updated_tasks[TaskStatus::IN_PROGRESS] = developers[person][TaskStatus::NEW];
                    developers[person][TaskStatus::NEW] = 0;
                    task_count -= developers[person][TaskStatus::NEW];
                } else {
                    updated_tasks[TaskStatus::IN_PROGRESS] = task_count;
                    remaining_tasks[TaskStatus::NEW] = developers[person][TaskStatus::NEW] -
                        updated_tasks[TaskStatus::NEW];
                    developers[person][TaskStatus::NEW] -= task_count;
                }
            }
        }

        if(task_count > 0) {
            if (developers[person][TaskStatus::IN_PROGRESS] != 0) {
                if (task_count >= developers[person][TaskStatus::IN_PROGRESS]) {
                    updated_tasks[TaskStatus::TESTING] = developers[person][TaskStatus::IN_PROGRESS];
                    developers[person][TaskStatus::IN_PROGRESS] = 0;
                    task_count -= developers[person][TaskStatus::IN_PROGRESS];
                } else {
                    updated_tasks[TaskStatus::TESTING] = task_count;
                    remaining_tasks[TaskStatus::IN_PROGRESS] = developers[person][TaskStatus::IN_PROGRESS] -
                        updated_tasks[TaskStatus::IN_PROGRESS];
                    developers[person][TaskStatus::IN_PROGRESS] -= task_count;
                }
            }
        }

        if(task_count > 0) {
            if (developers[person][TaskStatus::TESTING] != 0) {
                if (task_count >= developers[person][TaskStatus::TESTING]) {
                    updated_tasks[TaskStatus::DONE] = developers[person][TaskStatus::TESTING];
                    developers[person][TaskStatus::TESTING] = 0;
                    task_count -= developers[person][TaskStatus::TESTING];
                } else {
                    updated_tasks[TaskStatus::DONE] = task_count;

                    remaining_tasks[TaskStatus::TESTING] += developers[person][TaskStatus::TESTING];
                    developers[person][TaskStatus::TESTING] -= task_count;
                }
            }
        }

        if(task_count > 0) {
            if(developers[person][TaskStatus::DONE] != 0){
                if (task_count >= developers[person][TaskStatus::DONE]){
                    task_count -= developers[person][TaskStatus::DONE];
                    developers[person][TaskStatus::DONE] = 0;
                } else {
                    developers[person][TaskStatus::DONE] -= task_count;
                    remaining_tasks[TaskStatus::DONE] += developers[person][TaskStatus::DONE];
                }
            }
        }

        developers[person][TaskStatus::IN_PROGRESS] = updated_tasks[TaskStatus::IN_PROGRESS];
//        updated_tasks.erase(static_cast<TaskStatus>(2));
//        cout << developers[person][TaskStatus::IN_PROGRESS] << endl;


        return make_tuple(updated_tasks, remaining_tasks);
    };

private:
    map<string, TasksInfo> developers;
};

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}


template <typename Collection>
string Join(const Collection& c, const string& d) {
    stringstream ss;
    bool isFirst = true;
    for (const auto& i : c) {
        if(!isFirst) {
            ss << d;
        }
        isFirst = false;
        ss << i;
    }
    return ss.str();
}
template <typename F, typename S>
ostream& operator <<(ostream& out, const pair<F,S>& p) {
    return out << p.first << ": " << p.second;
}
template <typename K, typename V>
ostream& operator <<(ostream& out, const map<K,V>& m){
    return out << '{' << Join(m, ", ") << '}';
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    return out << '['  << Join(v, ", ") << ']';
}

int main() {

    TeamTasks tasks;

    while(cin) {
        string command, person;
        int num;
        cin >> command >> person;
        if (command == "AddNewTasks") {
            cin >> num;
            while (num--)
                tasks.AddNewTask(person);
            cout << "[]" << endl;
        } else if (command == "PerformPersonTasks") {
            cin >> num;
            TasksInfo updated_tasks, untouched_tasks;
            tie(updated_tasks, untouched_tasks) =
                tasks.PerformPersonTasks(person, num);
            cout << vector<TasksInfo>{updated_tasks, untouched_tasks } << endl;
        } else if (command == "GetPersonTasksInfo") {
            cout << tasks.GetPersonTasksInfo(person) << endl;
        } else if (command.size() && command[0] != '#'){
            throw invalid_argument("wrong command: " + command);
        }
    }

    /*tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);*/

    return 0;
}
