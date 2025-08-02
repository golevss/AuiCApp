//
// Created by GolevSS on 03.08.2025.
//

#ifndef TASK_H
#define TASK_H
#include <string>

class Task {
public:
    std::string getTaskName();
    bool setTaskName(std::string name);

    bool getCheckBox();
    bool setCheckBox(bool checked);

private:
    std::string taskName = "";
    bool checkBox = false;
};

#endif //TASK_H
