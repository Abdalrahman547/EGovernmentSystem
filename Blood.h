
#include <iostream>
using namespace std;

class Blood
{
private:
    string Type;
    int CountOfBloodBag;

public:
    Blood()
    {
        Type = "XXXX";
        CountOfBloodBag = 0;
    }

    Blood(string s, int c)
    {
        Type = s;
        CountOfBloodBag = c;
    }

    string getType()
    {
        return Type;
    }

    int getCountOfBloodBag()
    {
        return CountOfBloodBag;
    }

    void setType(string t)
    {
        Type = t;
    }

    void setCountOfBloodBag(int c)
    {
        CountOfBloodBag = c;
    }
};