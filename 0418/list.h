class LinkedList{
    private:
        class Node{
            private:
                friend class LinkedList;
                int data;
                Node* next;
                Node* prev;
            public:
                Node(int data):{
                    this->data = data;
                }
                Node():next(nullptr)prev(nullptr){}
                ~Node(){
                    this->next = nullptr; // 댕글링 포인터 방지!
                }
        };
        Node* head;
        Node* tail;

    public:
        // LinkedList():head(nullptr),tail(nullptr){}
        LinkedList(){
            head = new Node();
            tail = head;
        }
        void Append(int data);
        void PrintReverse();
        void Prepend(int data);
        void Print();
        int Length();
};