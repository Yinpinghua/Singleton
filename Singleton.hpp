#ifndef Singleton_h__
#define Singleton_h__
/********************************************/
/***构造函数任意*****************************/
/***线性安全********************************/
/*******************************************/
//实例代码
//class Test : public Singleton<Test> {
//	friend class Singleton<Test>;
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
//	~Test() {
//		cout << "destroy test" << endl;
//	}
//};

template<typename type>
class Singleton {
public:
	template<class...Args>
	static type& GetInstance(Args &&... args) {
		static type instance(std::forward<Args>(args)...);
		return instance;
	}

protected:
	Singleton() = default;
	~Singleton() = default;
private:
	Singleton(const Singleton&) = delete;
	Singleton(const Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(const Singleton&&) = delete;
};

#endif // Singleton_h__
