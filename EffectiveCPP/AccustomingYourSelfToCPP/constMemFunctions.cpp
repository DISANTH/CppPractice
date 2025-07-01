#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class TextBlock
{
    public:

        TextBlock(const char* textData)
        {
            mSize = strlen(textData);
            text = new char[mSize+1];
            strcpy(text,textData);
            text[mSize] = '\0';
        }

        const char& operator[](std::size_t position) const
        {
            //cout << "const [] called" << endl;
            assert(position < mSize);
            return text[position];
        }

        /*

        char& operator[](std::size_t position)
        {
            //
            //    We are duplicating the same code multiple time, due to provide non const char reference here...
            //    See the new code below for the better approach...
            //
            cout << "non-const [] called" << endl;
            assert(position < mSize);
            return text[position];
        }
        */

        char& operator[](std::size_t position)
        {
            return const_cast<char&>( static_cast<const TextBlock&>(*this)[position]); // this is the better way to avoid code duplication...
        }

        std::size_t size() const
        {
            return this->mSize;
        }

    private:
        char* text;
        std::size_t mSize;
};

void printData(const TextBlock& textBlock)
{
    cout << endl;
    for(int i = 0; i < textBlock.size(); i++)
    {
        cout << textBlock[i];
    }
    cout << endl;
}

int main()
{
    TextBlock tblk("Disanth Kumar");
    tblk[10] = 'N';
    cout << "tblk[10] :: " << tblk[10] << endl;

    printData(tblk);

    return 0;
}