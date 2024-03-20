//task1
#include <string>
#include <map>
#include <iostream>
#include <vector>
// f
struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads; 
    using Workload = std::map<std::string, int>::value_type;

    Task(std::string _text, std::string _date, std::map<std::string, int> _workloads)
        : text(_text), date(_date), workloads(_workloads) {}


    int getTotalLoad() const {
        int totalLoad = 0;
        for(const auto& workload : workloads) {
            totalLoad += workload.second; 
        }
        return totalLoad; 
    }
};

struct Worker {
    std::string name;
    std::string login;
    int maxLoad; 

    
    Worker(std::string _name, std::string _login, int _maxLoad)
        : name(_name), login(_login), maxLoad(_maxLoad) {}
};
//task2
#include <string>
#include <map>
#include <iostream>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads; 
    using Workload = std::map<std::string, int>::value_type;

    Task(std::string _text, std::string _date, std::map<std::string, int> _workloads)
        : text(_text), date(_date), workloads(_workloads) {}


    int getTotalLoad() const {
        int totalLoad = 0;
        for(const auto& workload : workloads) {
            totalLoad += workload.second; 
        }
        return totalLoad; 
    }
};

struct Worker {
    std::string name;
    std::string login;
    int maxLoad; 

    
    Worker(std::string _name, std::string _login, int _maxLoad)
        : name(_name), login(_login), maxLoad(_maxLoad) {}
};
//task3
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);
    int getTotalLoad() const;
};

Task::Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads)
{
    this->text = text;
    this->date = date;
    this->workloads = workloads;
}


struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    bool isOverworked(const std::vector<Task>& tasks) const;
};

Worker::Worker(const std::string& name, const std::string& login, int maxLoad)
{
    this->name = name;
    this->login = login;
    this->maxLoad = maxLoad;

}


int Task::getTotalLoad() const
{
    int totalLoad = 0;
    for (const auto& pair : workloads)
    {
        totalLoad += pair.second;
    }
    return totalLoad;
}

void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
        if (t1.getTotalLoad() != t2.getTotalLoad()) {
            return t1.getTotalLoad() < t2.getTotalLoad();
        } else if (t1.date != t2.date) {
            return t1.date < t2.date;
        } else {
            return t1.text < t2.text;
        }
    });


}
//task4
#include <string>
#include <vector>
#include <map>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(std::string _text, std::string _date, std::map<std::string, int> _workloads)
        : text(_text), date(_date), workloads(_workloads) {}
};

struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(std::string _name, std::string _login, int _maxLoad)
        : name(_name), login(_login), maxLoad(_maxLoad) {}
};

int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker) {
    int totalLoad = 0;
    for (const Task& task : allTasks) {
        auto it = task.workloads.find(worker.login);
        if (it != task.workloads.end()) {
            totalLoad += it->second;
        }
    }
    return totalLoad;
}
//task5
#include <vector>
#include <map>
#include <stdexcept>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(std::string _text, std::string _date, std::map<std::string, int> _workloads)
        : text(_text), date(_date), workloads(_workloads) {}
};

struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(std::string _name, std::string _login, int _maxLoad)
        : name(_name), login(_login), maxLoad(_maxLoad) {}
};

int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker);

void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers) {
    std::vector<Task> tempTasks = tasks;
    tempTasks.push_back(newTask); 

    for (const Worker& worker : workers) {
        int totalLoad = getWorkerLoad(tempTasks, worker);
        if (totalLoad > worker.maxLoad) {
            throw std::runtime_error("Overworked");
        }
    }

    tasks.push_back(newTask);
}

int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker) {
    int totalLoad = 0;
    for (const Task& task : allTasks) {
        auto it = task.workloads.find(worker.login);
        if (it != task.workloads.end()) {
            totalLoad += it->second;
        }
    }
    return totalLoad;
}
//task6
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
// d
struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);
    int getTotalLoad() const;
};

Task::Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads)
{
    this->text = text;
    this->date = date;
    this->workloads = workloads;
}


struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    bool isOverworked(const std::vector<Task>& tasks) const;
};

Worker::Worker(const std::string& name, const std::string& login, int maxLoad)
{
    this->name = name;
    this->login = login;
    this->maxLoad = maxLoad;

}


int Task::getTotalLoad() const
{
    int totalLoad = 0;
    for (const auto& pair : workloads)
    {
        totalLoad += pair.second;
    }
    return totalLoad;
}

void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
        if (t1.getTotalLoad() != t2.getTotalLoad()) {
            return t1.getTotalLoad() < t2.getTotalLoad();
        } else if (t1.date != t2.date) {
            return t1.date < t2.date;
        } else {
            return t1.text < t2.text;
        }
    });


}
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
    int totalLoad = 0;
    for (const Task& task : allTasks) {
        auto it = task.workloads.find(worker.login);
        if (it != task.workloads.end()) {
            totalLoad += it->second;
        }
    }
    return totalLoad;
}

void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    tasks.push_back(newTask);
    std::vector<Worker> overworkedWorkers;
    for (const auto& worker : workers) {
        int totalLoad = getWorkerLoad(tasks, worker);
        if (totalLoad > worker.maxLoad) {
            overworkedWorkers.push_back(worker);
        }
    }

    if (!overworkedWorkers.empty()) {
        std::sort(overworkedWorkers.begin(), overworkedWorkers.end(), [](const Worker& w1, const Worker& w2) {
            return w1.login < w2.login;
        });

        std::string errorMessage = "Overworked: ";
        for (size_t i = 0; i < overworkedWorkers.size(); ++i) {
            const Worker& worker = overworkedWorkers[i];
            int currentLoad = getWorkerLoad(tasks, worker);
            int difference =  currentLoad-worker.maxLoad;
            errorMessage += worker.login + " by " + std::to_string(difference);
            if (i < overworkedWorkers.size() - 1) {
                errorMessage += ", ";
            }
        }

        throw std::runtime_error(errorMessage);
    }
}
//////////////////////////////////////////////