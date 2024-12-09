#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Human {
protected:
    std::string name;
    int age;
public:
    Human(std::string name, int age) : name(name), age(age) {}
    virtual void display() const {
        std::cout << "Имя: " << name << ", Возраст: " << age << std::endl;
    }
};

class Preschooler : public Human {
public:
    Preschooler(std::string name, int age) : Human(name, age) {}
    void display() const override {
        std::cout << "Дошкольник - ";
        Human::display();
    }
};

class Schoolchild : public Human {
public:
    Schoolchild(std::string name, int age) : Human(name, age) {}
    void display() const override {
        std::cout << "Школьник - ";
        Human::display();
    }
};

class Student : public Human {
public:
    Student(std::string name, int age) : Human(name, age) {}
    void display() const override {
        std::cout << "Студент - ";
        Human::display();
    }
};

class Worker : public Human {
public:
    Worker(std::string name, int age) : Human(name, age) {}
    void display() const override {
        std::cout << "Работающий - ";
        Human::display();
    }
};

template <typename T>
class ArrayContainer {
private:
    std::vector<std::shared_ptr<T>> elements;
public:
    void add(std::shared_ptr<T> element) {
        elements.push_back(element);
    }

    std::shared_ptr<T>& operator[](size_t index) {
        return elements.at(index);
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    auto preschooler = std::make_shared<Preschooler>("Дениска", 5);
    auto schoolchild = std::make_shared<Schoolchild>("Юля", 10);
    auto student = std::make_shared<Student>("Максим", 20);
    auto worker = std::make_shared<Worker>("Vfrcbv", 30);

    ArrayContainer<Human> humans;
    humans.add(preschooler);
    humans.add(schoolchild);
    humans.add(student);
    humans.add(worker);

    for (size_t i = 0; i < humans.size(); ++i) {
        humans[i]->display();
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Component {
protected:
    Component() {}
public:
    virtual ~Component() {}

    virtual void info() const = 0;
};

class Part : public Component {
protected:
    Part() : name("Безымянная деталь") {}
    Part(const std::string& name) : name(name) {}
    std::string name;
public:
    virtual ~Part() {}

    void info() const override {
        std::cout << "Деталь: " << name << std::endl;
    }

    template<typename T, typename... Args>
    friend std::shared_ptr<T> createComponent(Args&&... args);
};

class Assembly : public Component {
protected:
    Assembly() : name("Безымянная сборка") {}
    Assembly(const std::string& name) : name(name) {}
    std::string name;
public:
    virtual ~Assembly() {}

    void info() const override {
        std::cout << "Сборка: " << name << std::endl;
    }

    template<typename T, typename... Args>
    friend std::shared_ptr<T> createComponent(Args&&... args);
};

template<typename T, typename... Args>
std::shared_ptr<T> createComponent(Args&&... args) {
    static_assert(std::is_base_of<Component, T>::value, "T must be a Component");
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<std::shared_ptr<Component>> components;

    components.push_back(createComponent<Part>("Деталь двигателя"));
    components.push_back(createComponent<Assembly>("Сборка двигателя"));
    components.push_back(createComponent<Part>("Деталь колеса"));
    components.push_back(createComponent<Assembly>("Сборка шасси"));

    for (const auto& component : components) {
        component->info();
    }

    return 0;
}
