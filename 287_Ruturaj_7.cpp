#include<iostream>
#include <stack>
using namespace std;

struct page{
    string address;
    page* next;

    page(string addr) : address(addr), next(nullptr){}
};

class WebBrowser{
    public:
    stack<page*> backstack;
    stack<page*> forwardstack;
    page* currentpage;

    WebBrowser() : currentpage(nullptr){}

    void visit(string address) {
        if (currentpage != nullptr) {
            backstack.push(currentpage);
        }
        currentpage = new page(address);
        while(!forwardstack.empty()) {
            forwardstack.pop();
        }
        cout << "Visited : " << currentpage->address <<endl;
    }

    void goback() {
        if (!backstack.empty()) {
            forwardstack.push(currentpage);
            currentpage = backstack.top();
            backstack.pop();
            cout << "Navigate back to : " <<currentpage->address <<endl;
        } else {
            cout << "No more pages in the history to go back. " << endl;
        }
    }
    
    void goforward(){
        if (!forwardstack.empty()) {
            backstack.push(currentpage);
            currentpage = forwardstack.top();
            forwardstack.pop();
            cout << "Navigate to forward to : " <<currentpage->address <<endl;
        } else {
            cout << "No more pages in the forward history. " << endl;
        }
    }

    void viewcurrentpage(){
        if(currentpage != nullptr) {
            cout<<"Current page : "<<currentpage->address<<endl;
        }else {
            cout<<"No page is currently opened : "<<endl;
        }
    }

    bool ishistoryempty() {
        return backstack.empty();
    }
};

int main() {
    WebBrowser W1;

    W1.visit("www.googele.com");
    W1.visit("www.youtube.com");
    W1.visit("www.linkedin.com");
    W1.visit("www.amazon.com");
    W1.visit("www.pccoe.com");
    W1.goback();
    W1.goback();
    W1.goforward();
    W1.viewcurrentpage();
    
    
return 0;
}
