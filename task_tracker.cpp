#include <iostream>
#include <tuple>
#include <map>
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


//Отладочный код, чтоб норм вывод смотреть
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
        return developers.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        developers[person][TaskStatus::NEW]++;
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count)
    {
        updated_tasks.clear();
        remaining_tasks.clear();
        auto& person_info = developers[person];

//        Обход тасков и обновление
        for (int i = 0; i < 3; ++i) {
            auto index = static_cast<TaskStatus>(i);
            auto next_index = static_cast<TaskStatus>(i + 1);
            if (person_info.count(index) == 0) {
                continue;
            }
            const auto cur_item_cnt = person_info.at(index);
            if (cur_item_cnt == 0) {
                continue;
            }
            if (cur_item_cnt >= task_count) {

                if (task_count > 0 && i < 3) {
                    updated_tasks[next_index] = task_count;
                }

                if (cur_item_cnt - task_count <= 0) {
                    remaining_tasks.erase(index);
                } else {
                    remaining_tasks[index] = cur_item_cnt - task_count;
                }
                if (person_info[index] != 0
                    && person_info[index] >= task_count) {
                    person_info[index] -= task_count;
                }

                task_count = 0;

            } else {
                updated_tasks[next_index] = cur_item_cnt;
                remaining_tasks[index] = 0;
                person_info.erase(index);
                task_count -= cur_item_cnt;
            }
        }

        remaining_tasks[static_cast<TaskStatus>(3)] = person_info[static_cast<TaskStatus>(3)];

//       Мерж двух мапов в основной
        for (size_t i = 0; i <= 3; ++i) {
            auto index = static_cast<TaskStatus>(i);
            if (updated_tasks[index] == 0
                && remaining_tasks[index] == 0) {
//                person_info[index] = 0;
                if (person_info[index] == 0){
                    person_info.erase(index);
                }
            } else {
                person_info[index] = updated_tasks[index] +
                    remaining_tasks[index];
            }
            if (updated_tasks[index] == 0) {
                updated_tasks.erase(index);
            }
            if (remaining_tasks[index] == 0 || (i == 3 && remaining_tasks.count(index) > 0)) {
                remaining_tasks.erase(index);
            }
        }

        return make_tuple(updated_tasks, remaining_tasks);
    };

private:
    map<string, TasksInfo> developers;
    TasksInfo updated_tasks;
    TasksInfo remaining_tasks;
};



//Отладочный код, чтоб норм вывод смотреть
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

    //Отладочный код, чтоб норм вывод смотреть
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

    return 0;
}
