class Singleton {
  public:
  static Singleton& GetInstance() {
    static Singleton singleton;
    return singleton;
  }
  
  private:
  Singleton() {};
  ~Singleton() {};

  Singleton(const Singleton&) = delete;
  Singleton operator=(Singleton&) = delete;
};
