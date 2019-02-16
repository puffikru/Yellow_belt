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
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count)
    {
        updated_tasks.clear();
        remaining_tasks.clear();
        auto& person_info = developers[person];

//        Обход тасков и обновление
        for (size_t i = 0; i < person_info.size(); ++i) {
            auto index = static_cast<TaskStatus>(i);
            auto next_index = static_cast<TaskStatus>(i + 1);
            if (person_info.count(index) == 0) {
                continue;
            }
            const auto cur_item_cnt = person_info.at(index);
            if (cur_item_cnt >= task_count) {
                updated_tasks[next_index] = task_count;
                remaining_tasks[index] = cur_item_cnt - task_count;
                if (person_info[index] != 0
                    && person_info[index] >= task_count) {
                    person_info[index] -= task_count;
                }

            } else {
                updated_tasks[next_index] = cur_item_cnt;
                remaining_tasks[index] = 0;
                person_info[index] = 0;
                task_count -= cur_item_cnt;
            }
        }

//       Мерж двух мапов в основной
        for (size_t i = 0; i < person_info.size(); ++i) {
            auto index = static_cast<TaskStatus>(i);
            if (updated_tasks[index] == 0
                && remaining_tasks[index] == 0) {
                person_info[index] = 0;
            } else {
                person_info[index] = updated_tasks[index] +
                    remaining_tasks[index];
            }
        }

        return make_tuple(updated_tasks, remaining_tasks);
    };

private:
    map<string, TasksInfo> developers;
//    Вынес сюда свойства, так как нужно, чтоб параметры сохранялись после выхода из метода
    TasksInfo updated_tasks;
    TasksInfo remaining_tasks;
};

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {

    TeamTasks tasks;

    tasks.AddNewTask("Ilia");
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
    PrintTasksInfo(untouched_tasks);

    return 0;
}
