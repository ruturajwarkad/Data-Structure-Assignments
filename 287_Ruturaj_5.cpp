#include<iostream>
using namespace std;

struct Route {
    int id;
    Route* next;
};

class NavigationSystem {
private:
    Route* head; 

public:
    NavigationSystem() {
        head = nullptr;  
    }

    // Display all routes
    void DisplayRoutes() {
        if (head == nullptr) {
            cout << "No routes available.\n";
            return;
        }

        Route* temp = head;
        do {
            cout << "Route ID: " << temp->id << endl;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Add route at beginning
    void AddRouteBeginning(int routeId) {
        Route* newRoute = new Route;
        newRoute->id = routeId;

        if (head == nullptr) {
            head = newRoute;
            newRoute->next = head;
        } else {
            Route* temp = head;
            while (temp->next != head) temp = temp->next; 
            temp->next = newRoute;
            newRoute->next = head;
            head = newRoute;
        }
        DisplayRoutes();
    }

    // Add route at end
    void AddRouteEnd(int routeId) {
        Route* newRoute = new Route;
        newRoute->id = routeId;

        if (head == nullptr) {
            head = newRoute;
            newRoute->next = head;
        } else {
            Route* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newRoute;
            newRoute->next = head;
        }
        DisplayRoutes();
    }

    // Add route at index
    void AddRouteAtIndex(int routeId, int index = 0) {
        if (index == 0) {
            AddRouteBeginning(routeId);
            return;
        }

        Route* newRoute = new Route;
        newRoute->id = routeId;
        Route* temp = head;
        for (int i = 0; temp->next != head && i < index - 1; ++i) temp = temp->next;

        newRoute->next = temp->next;
        temp->next = newRoute;

        DisplayRoutes();
    }

    // Remove all routes
    void RemoveAllRoutes() {
        if (!head) return;

        Route* current = head;
        Route* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
        cout << "All routes removed.\n";
        DisplayRoutes();
    }

    // Remove last route
    void RemoveLastRoute() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Route* temp = head;
            while (temp->next->next != head) temp = temp->next;
            delete temp->next;
            temp->next = head;
        }
        DisplayRoutes();
    }

    // Remove route at index
    void RemoveRouteAtIndex(int index) {
        if (!head) return;

        if (index == 0) {
            RemoveFirstRoute();
            return;
        }

        Route* temp = head;
        for (int i = 0; temp->next != head && i < index - 1; ++i) temp = temp->next;

        Route* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        DisplayRoutes();
    }

    // Remove first route
    void RemoveFirstRoute() {
        if (!head) return;

        Route* temp = head;
        while (temp->next != head) temp = temp->next;

        Route* toDelete = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            temp->next = head->next;
            head = head->next;
        }
        delete toDelete;

        DisplayRoutes();
    }

    // Remove route by searching 
    void RemoveRouteById(int routeId) {
        if (!head) return;

        Route* temp = head;
        Route* prev = nullptr;
        do {
            if (temp->id == routeId) {
                if (prev == nullptr) RemoveFirstRoute();
                else prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        DisplayRoutes();
    }

    // Search for route by ID
    void SearchRoute(int routeId) {
        if (!head) {
            cout << "Route not found.\n";
            return;
        }

        Route* temp = head;
        do {
            if (temp->id == routeId) {
                cout << "Route found: Route ID " << routeId << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Route not found.\n";
    }

    // Modify route's ID
    void ModifyRoute(int oldId, int newId) {
        if (!head) return;

        Route* temp = head;
        do {
            if (temp->id == oldId) {
                temp->id = newId;
                cout << "Route ID " << oldId << " modified to " << newId << ".\n";
                DisplayRoutes();
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Route not found.\n";
    }
};

int main() {
    NavigationSystem navSys;

    // adding routes
    navSys.AddRouteEnd(101);
    navSys.AddRouteEnd(102);
    navSys.AddRouteBeginning(100);
    navSys.AddRouteAtIndex(103, 2);

    // modifying route
    navSys.ModifyRoute(102, 105);

    // searching route
    navSys.SearchRoute(105);

    // removing routes
    navSys.RemoveFirstRoute();
    navSys.RemoveLastRoute();
    navSys.RemoveRouteById(103);

    // removing all routes
    navSys.RemoveAllRoutes();

    return 0;
}
