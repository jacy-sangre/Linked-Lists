class List{
    public:
    virtual void add(int) = 0;
    virtual void print() = 0;
    virtual void addHead(int) = 0;
    virtual void addTail(int) = 0;
    virtual int getPosition(int) = 0;
    virtual void remove(int) = 0;
    virtual void addAt(int, int) = 0;
};