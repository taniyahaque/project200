#include <bits/stdc++.h>
using namespace std;

struct Member
{
    int id;

    string st_name;

    string name;

    string address;

    string contact;
};

unsigned long long id_cnt = 1;
vector<Member> members;

void addStaff(string st_name)
{
    getchar();
    string name, address, contact;
    printf("Enter name:");
    getline(cin, name);

    printf("Enter address:");
    getline(cin, address);

    printf("Enter contact:");
    getline(cin, contact);

    Member m = Member();
    m.id = id_cnt++;
    m.name = name;
    m.address = address;
    m.contact = contact;
    m.st_name = st_name;
    members.push_back(m);
}

bool addStaff()
{
    printf("SELECT CATEGORIES\n");
    printf("<1> New Member\n");
    printf("<2> Coach\n");
    printf("<3> Staff\n");
    printf("<4> Cancel\n");
    printf("Enter your choice:\n");

    getchar();
    switch (getchar())
    {

    case '1':
        addStaff("member");
        printf("Member Added\n");
        return 1;

    case '2':
        addStaff("coach");
        printf("Coach Added\n");
        return 1;

    case '3':
        addStaff("stuff");
        printf("Stuff Added\n");
        return 1;

    case '4':
        return 0;

    default:
        printf("Wrong Entry!!Please re-enter correct option.\n");
        addStaff();
    }
    return 0;
}

Member *findStuff(int id)
{
    int sz = members.size();
    for (int i = 0; i < sz; ++i)
    {
        if (members[i].id == id)
            return &members[i];
    }

    return NULL;
}

void deleteStaff(Member *m)
{
    int sz = members.size();
    for (int i = 0; i < sz; ++i)
    {
        if (members[i].id == m->id)
        {
            members.erase(members.begin() + i);
            printf("Removed!\n");
            break;
        }
    }
}

void deleteStaff()
{
    int id;

    printf("Enter id of the member to delete: ");
    scanf("%d", &id);

    Member *m = findStuff(id);

    if (m == NULL)
    {
        printf("No member found!!\n");
    }
    else
    {
        deleteStaff(m);
    }
}

void viewStaff(Member *m)
{
    cout << "Id: " << m->id << endl;
    cout << "Type: " << m->st_name << endl;
    cout << "Name: " << m->name << endl;
    cout << "Address: " << m->address << endl;
    cout << "Contact: " << m->contact << endl;
}

void viewStaff()
{
    int id;

    printf("Enter id of the member to view: ");
    scanf("%d", &id);

    Member *m = findStuff(id);

    if (m == NULL)
    {
        printf("No member found!!\n");
    }
    else
    {
        viewStaff(m);
    }
}

void editStaff(Member *m)
{

    int opt;
    string name, address, contact, type;
    printf("Choose field to edit:\n");
    printf("<1> Name\n");
    printf("<2> Address\n");
    printf("<3> Contact\n");
    printf("<4> Type\n");
    printf("<5> Cancel\n");

    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        printf("Enter name:");
        getline(cin, name);
        m->name = name;
        break;
    case 2:
        printf("Enter address:");
        getline(cin, address);
        m->address = address;
        break;
    case 3:
        printf("Enter contact:");
        getline(cin, contact);
        m->contact = contact;
        break;
    case 4:
        printf("Enter type:");
        getline(cin, type);
        m->st_name = type;
        break;
    case 5:
        break;
    default:
        printf("Wrong Entry!!Please re-enter correct option.\n");
        editStaff(m);
    }

    printf("Edited!");
}

void editStaff()
{
    int id;

    printf("Enter id of the member to edit: ");
    scanf("%d", &id);

    Member *m = findStuff(id);

    if (m == NULL)
    {
        printf("No member found!!\n");
    }
    else
    {
        editStaff(m);
    }
}

vector<Member> search(string name)
{
    vector<Member> list;

    for (int i = 0; i < members.size(); ++i)
    {
        if (members[i].name.find(name) != string::npos)
            list.push_back(members[i]);
    }

    return list;
}

void searchStaff()
{
    string key;

    printf("Enter the name to search member: ");
    cin >> key;

    vector<Member> list = search(key);

    if (list.size() == 0)
    {
        printf("No member found!!\n");
    }
    else
    {
        printf("Found following %d members with this name.\n", (int)list.size());

        for (int i = 0; i < list.size(); ++i)
        {
            viewStaff(&list[i]);
        }
    }
}

void viewAll()
{
    printf("All members:\n\n");

    for (int i = 0; i < members.size(); ++i)
    {
        viewStaff(&members[i]);
        printf("\n");
    }
}

int main()
{
    bool status;
    printf("MAIN MENU \n");
    printf("<1> Add Member\n");
    printf("<2> Remove Member\n");
    printf("<3> View Member\n");
    printf("<4> Edit Member\n");
    printf("<5> Search Members\n");
    printf("<6> View Member's list\n");
    printf("<7> Close Application\n");
    printf("Enter your choice:\n");

    switch (getchar())
    {

    case '1':
        status = addStaff();
        printf("\n------------------------------------\n");
        if (!status && getchar())
            main();
        else
            main();
        break;

    case '2':
        deleteStaff();
        printf("\n------------------------------------\n");
        if (getchar())
            main();
        break;

    case '3':
        viewStaff();
        printf("\n------------------------------------\n");
        if (getchar())
            main();
        break;

    case '4':
        editStaff();
        printf("\n------------------------------------\n");
        if (getchar())
            main();
        break;

    case '5':
        searchStaff();
        printf("\n------------------------------------\n");
        if (getchar())
            main();
        break;

    case '6':
        viewAll();
        printf("\n------------------------------------\n");
        if (getchar())
            main();
        break;

    case '7':
        exit(0);

    default:
        printf("Wrong Entry!!Please re-enter correct option.\n");
        printf("\n");
        if (getchar())
            main();
    }
}
