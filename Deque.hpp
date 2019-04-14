struct Elem {
    Elem *prev;
    int current;
    Elem *next;
};


class Deque {
    size_t size;
    Elem* firstElem = nullptr;
    Elem* lastElem = nullptr;
public:
    Deque(int s);
    void push_back(int);
    void push_front(int);
    bool pop_back();
    bool pop_front();
    int get_size() {
        return size;
    }
    int operator[] (int);
    void sort();
    void print_deque();
    ~Deque();
};
