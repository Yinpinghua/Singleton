#ifndef Singleton_h__
#define Singleton_h__
#include <memory>
#include <mutex>
/********************************************/
/***构造函数任意*****************************/
/***线性安全********************************/
/*******************************************/
//实例代码
//class Test : public Singleton<Test> {
//	friend class Singleton<Test>;
// public:
 //	~Test() {
//		cout << "destroy test" << endl;
//	}
//private:
//	Test() {
//		cout << "create test" << endl;
//	}
//
//	Test(int a) {
//		cout << "create test a= " << a << endl;
//	}
//
//	Test(int a, int b) {
//		cout << "create test a= " << a << endl;
//		cout << "create test b= " << b << endl;
//	}
//
//};

class Uncopyable {
protected:
	Uncopyable() = default;
	~Uncopyable() = default;
private:
	Uncopyable(const Uncopyable& )=delete;
	Uncopyable(const Uncopyable&&) = delete;
	Uncopyable& operator=(const Uncopyable&)=delete;
	Uncopyable& operator=(const Uncopyable&&) = delete;
};

template <typename T>
class Singleton  {
public:
	template <typename... ArgTypes>
	static T& getInstance(ArgTypes&&... args) {
		static std::once_flag flag;
		std::call_once(flag, [&]() {
			Singleton::instance_.reset(new T(std::forward<ArgTypes>(args)...)); 
			});

		return *instance_.get();
	}
protected:
	Singleton() = default;
	~Singleton() = default;
private:
	Singleton(const Singleton&) = delete;
	Singleton(const Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(const Singleton&&) = delete;
private:
	static std::unique_ptr<T> instance_;
};

template <class T>
std::unique_ptr<T> Singleton<T>::instance_ = nullptr;


#endif // Singleton_h__
