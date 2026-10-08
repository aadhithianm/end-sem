#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Customer
{
public:
    int id;
    string name;

    void getCustomer(int customerId)
    {
        id = customerId;
        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, name);
    }

    void displayCustomer()
    {
        cout << "Customer ID   : " << id << endl;
        cout << "Customer Name : " << name << endl;
    }
};

int main()
{
    queue<Customer> q;

    int choice;
    int id = 1;

    do
    {
        cout << "\n========== TAXI QUEUE SYSTEM ==========\n";
        cout << "1. Add Customer\n";
        cout << "2. Assign Taxi\n";
        cout << "3. List Customers\n";
        cout << "4. Queue Status\n";
        cout << "5. Exit\n";
        cout << "========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                Customer obj;
                obj.getCustomer(id);
                q.push(obj);
                cout << "\nCustomer added successfully!\n";
                id++;
                break;
            }

            case 2:
            {
                if (q.empty())
                {
                    cout << "\nQueue is empty.\n";
                    cout << "No customer is waiting for a taxi.\n";
                }
                else
                {
                    Customer obj = q.front();
                    cout << "\nTaxi assigned to:\n";
                    obj.displayCustomer();
                    q.pop();
                    cout << "Customer removed from queue.\n";
                }
                break;
            }

            case 3:
            {
                if (q.empty())
                {
                    cout << "\nNo customers are waiting.\n";
                }
                else
                {
                    queue<Customer> temp = q;

                    cout << "\n------ Waiting Customers ------\n";

                    while (!temp.empty())
                    {
                        Customer obj = temp.front();

                        obj.displayCustomer();

                        cout << "-------------------------------\n";

                        temp.pop();
                    }
                }

                break;
            }

            case 4:
            {
                if (q.empty())
                {
                    cout << "\nQueue is EMPTY.\n";
                }
                else
                {
                    cout << "\nNumber of waiting customers: "
                         << q.size() << endl;
                }

                break;
            }

            case 5:
            {
                cout << "\nExiting Taxi Queue System...\n";
                break;
            }

            default:
            {
                cout << "\nInvalid choice! Please try again.\n";
            }
        }

    } while (choice != 5);

    return 0;
}
