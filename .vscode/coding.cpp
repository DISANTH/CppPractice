
#include <iostream>
#include <stack>
using namespace std;
// class IComponent
// {
// public:
//     virtual void setInterface(Network *network) = 0;
// };

// class IPrintable : public IComponent
// {
//     Network network;

// public:
//     virtual void print() = 0;
// };

class IScannable
{
};

class IFaxable
{
};

// class ModernFax : public IFaxable
// {
// };

// class Network
// {
// };

class Iprinter
{
    public:
    virtual void print() = 0;
};

class Printer : public Iprinter
{
private:
public:
    void print() override
    {
        std::cout << "Traditional Printer" << std::endl;
    }
};

class JupiterPrinter : public Iprinter
{
public:
    void print() override
    {
        cout << "JupiterPrinter Printer" << endl;
    }
};

int bracketType(char &ch)
{
    bool isOpen = false;

    if(ch == '[')
    {
        isOpen = true;
    }
    else if(ch == '{')
    {
        isOpen = true;
    }
    else if(ch == '(')
    {
        isOpen = true;
    }
    if(isOpen)
    {
        return 0;
    } 
    else{
        return 1;
    }
}

int matchBrackets(string str)
{
    char* ptr1;
    char* ptr2;

    
    return 0;

}

char getOppositeOpening(char ch)
{
    if(ch == ']')
    {
        return '[';
    }
    else if(ch == '}')
    {
        return '{';
    }
    else
    {
        return '(';
    }
}

int matchBracketsWithStack(string str)
{
    stack<char> _stack;
    for(char &ch: str)
    {
        if(bracketType(ch) == 0)
        {
            _stack.push(ch);
        }
        else{
            if(_stack.empty())
            {
                return false;
            }
            char& data = _stack.top();
            _stack.pop();
            if(getOppositeOpening(ch) != data)
            {
                return false;
            }
        }
    }
    if(_stack.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    cout << matchBracketsWithStack("][()()]{") << endl;
    return 0;
}


/**
 * 
 * [()()]{}
 */