#include <cpr/cpr.h>
#include <string>
#include <iostream>

const std::string BASE_URL = "http://127.0.0.1:8000";

// Add Entry
cpr::Response addEntry(const std::string &date, const std::string &value)
{
    cpr::Response r = cpr::Post(
        cpr::Url{BASE_URL + "/add-entry"},
        cpr::Header{{"Content-Type", "application/json"}},
        cpr::Body{"{\"date\": \"" + date + "\", \"value\": \"" + value + "\"}"});
    return r;
}

// Delete Entry
cpr::Response deleteEntry(const std::string &date)
{
    cpr::Response r = cpr::Delete(
        cpr::Url{BASE_URL + "/delete-entry/" + date});
    return r;
}

// Update Entry
cpr::Response updateEntry(const std::string &date, const std::string &new_value)
{
    cpr::Response r = cpr::Put(
        cpr::Url{BASE_URL + "/update-entry"},
        cpr::Header{{"Content-Type", "application/json"}},
        cpr::Body{"{\"date\": \"" + date + "\", \"new_value\": \"" + new_value + "\"}"});
    return r;
}

// Get Entry
cpr::Response getEntry(const std::string &date)
{
    cpr::Response r = cpr::Get(
        cpr::Url{BASE_URL + "/get-entry/" + date});
    return r;
}

// Get All Data
cpr::Response getAllData()
{
    cpr::Response r = cpr::Get(
        cpr::Url{BASE_URL + "/all-data"});
    return r;
}

bool ContinueLoop()
{
    std::string a;
    std::cout << "Wanna operate more? 'yes' or 'no': ";
    std::cin >> a;
    std::cout << "\n";
    return a == "yes";
}

void Operations(const std::string &a)
{
    if (a == "delete")
    {
        std::string date;
        std::cout << "Enter date of deletion: ";
        std::cin >> date;
        std::cout << "\n";
        cpr::Response delRes = deleteEntry(date);
        std::cout << "Delete Entry Response: " << delRes.text << std::endl;
    }
    else if (a == "update")
    {
        std::string date, new_value;
        std::cout << "Enter date to update: ";
        std::cin >> date;
        std::cout << "Enter new value: ";
        std::cin >> new_value;
        auto updRes = updateEntry(date, new_value);
        std::cout << "Update Entry Response: " << updRes.text << std::endl;
    }
    else if (a == "fetchall")
    {
        auto allRes = getAllData();
        std::cout << "All Data Response: " << allRes.text << std::endl;
    }
    else if (a == "get")
    {
        std::string date;
        std::cout << "Enter date to fetch: ";
        std::cin >> date;
        auto getRes = getEntry(date);
        std::cout << "Get Entry Response: " << getRes.text << std::endl;
    }
    else if (a == "add")
    {
        std::string date, value;
        std::cout << "Enter date to add: ";
        std::cin >> date;
        std::cout << "Enter value: ";
        std::cin >> value;
        auto res = addEntry(date, value);
        std::cout << "Add Entry Response: " << res.text << std::endl;
    }
    else
    {
        std::cout << "Invalid operation. Skipping...\n";
    }
}

int main()
{
    std::string str;
    while (true)
    {
        if (ContinueLoop())
        {
            std::cout << "You can use the following operations by inserting their names in small form:\n";
            std::cout << "delete\nadd\nget\nfetchall\nupdate\nskip\n";
            std::cout << "What will you choose? : ";
            std::cin >> str;
            std::cout << "\n";
            if (str == "skip")
            {
                continue;
            }
            Operations(str);
        }
        else
        {
            std::cout << "Exiting... Thank you! 🎉\n";
            return 0;
        }
    }
}
