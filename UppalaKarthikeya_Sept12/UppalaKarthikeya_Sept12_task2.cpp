#include <iostream>
#include <string>
using namespace std;

class Command {
public:
    string name; int duration;
    Command(string n,int d){ name=n; duration=d; }
};

class Node {
public:
    Command* cmd;
    Node* next;
    Node(Command* c){ cmd=c; next=NULL; }
};

class Executor {
public:
    void run(Command& c){ cout<<"Executing "<<c.name<<" for "<<c.duration<<"ms\n"; }
};

void advance(Node*& cur){ if(cur) cur=cur->next; }
void printQueue(Node* head){
    cout<<"Queue: ";
    for(Node* t=head; t; t=t->next) cout<<t->cmd->name<<" -> ";
    cout<<"NULL\n";
}

class CommandQueue {
    Node* head;
public:
    CommandQueue(){ head=NULL; }
    ~CommandQueue(){ clear(); }

    void enqueue(Command* c){
        Node* n=new Node(c);
        if(!head) head=n;
        else{ Node* t=head; while(t->next) t=t->next; t->next=n; }
    }

    void executeAll(Executor& ex){
        Node* cur=head;
        while(cur){ ex.run(*cur->cmd); advance(cur); }
    }

    void clear(){
        while(head){ Node* tmp=head; head=head->next; delete tmp->cmd; delete tmp; }
    }

    Node* getHead(){ return head; }
};

int main(){
    CommandQueue q; Executor ex;

    q.enqueue(new Command("Start Motor",100));
    q.enqueue(new Command("Open Valve",50));
    q.enqueue(new Command("Close Valve",60));
    q.enqueue(new Command("Stop Motor",80));
    q.enqueue(new Command("Shutdown",40));

    printQueue(q.getHead());
    q.executeAll(ex);
}
