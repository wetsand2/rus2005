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

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

class Base {
public:
	virtual ~Base() {}

	virtual void display() const {
		std::cout << "Объект типа Base\n";
	}
};

class Derived : public Base {
public:
	void display() const override {
		std::cout << "Объект типа Derived\n";
	}
};

void add(std::vector<std::shared_ptr<Base>>& storage, const std::shared_ptr<Base>& obj) {
	storage.push_back(obj);
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::vector<std::shared_ptr<Base>> storage;

	for (int i = 0; i < 10; ++i) {
		if (std::rand() % 2 == 0) {
			auto baseObj = std::make_shared<Base>();
			add(storage, baseObj);
		}
		else {
			auto derivedObj = std::make_shared<Derived>();
			add(storage, derivedObj);
		}
	}

	std::cout << "Содержимое хранилища:\n";
	for (const auto& obj : storage) {
		obj->display();
	}

	return 0;
}

