

#include <iostream>
#include <vector>
using namespace std;

// class A{
// int a;
// int b;
// public:
//     A(int i, int j): a(i), b(j) {}
//     A(const A &obj)
//     {
//         a = obj.a;
//         b = obj.b;
//         cout<<"Copy Cntr\n";
//     }
//     A& operator =(A obj)
//     {
//         a = obj.a;
//         b = obj.b;
//         cout<<"Copy assignment operator\n";
//         return *this;
//     }
// };
// int main()
// {
//     A obj1(10, 20);
//     A obj2(1, 2);
//     obj2 = obj1; // object2.operator=(obj1);
//     A obj3 = obj2;
 
//     return 0;
// }

// // Copy Cntr
// // Copy assignment operator
// // Copy Cntr



// void test(char* &str)
// {
//     str = new char[10]; // 500
//     strcpy(*str, "test");
// }
 
// // int main()
// // {
// //     char* str = NULL; // NULL
// //     test(str);
// //     cout << str;
// //     return 0;
// // }


// // void Thing::process()
// // {
// //    {
// //      lock_guard<mutex> locking(lock);
// // 	.
// // 	.
// // 	.
// //    }
// //     inner();
// // 	cout << "print" << endl;
// // }
 
// // void Thing::inner()
// // {
// //     lock_guard<mutex> locking(lock);
// // 	.
// // 	.
// // 	.
// // }

// binary_semaphore oddSemaphore{1},evenSemaphore{0};
// void printOddNumbers(int limit)
// {
    
//     for(int i = 1; i <= limit; i += 2)
//     {
//         oddSemaphore.acquire();
//         cout << i << " ";
//         evenSemaphore.release();
//     }
// }

// void printEvenNumbers(int limit)
// {
//      for(int i = 2; i <= limit; i += 2)
//     {
//         evenSemaphore.acquire();
//         cout << i << " ";
//         oddSemaphore.release();
//     }
// }

void print(const vector<int> &numbers)
{
    for(const int &data: numbers)
    {
        cout << " " << data;
    }
    cout << endl;
}

int main()
{
    // thread evenThread(printOddNumbers,100);
    // thread oddThread(printOddNumbers,100);

    // evenThread.join();
    // oddThread.join();

    // int i = 59;
    // int *ptr = &i;
    // cout << "*ptr :: " << *ptr << endl;
    // free(ptr);

    vector<int> vec {1,2,3,4};
    int* ptr = &vec[1];

    vec.push_back(11);
    vec.push_back(6);
    vec.push_back(100);

    cout<< *ptr;

    cout << endl;

    print(vec);

    return 0;
}


// N [] 0 --> end;


//input --> { 2,0,1,0,4,0,9} - i - NooFZero's
// {2,1,0,0,4,0,9}



// [2,1,4,9,0,0,0]

// {2,1,0,0,4,0,9};


// void moveZeroesToEnd(vector<int> &numbers)
// {
//     for(int i = 0; i < numbers.size(); i++)
//     {
//         if(numbers[i] == 0)
//         {
//             for(int j = i+1; j < numbers.size();j++)
//             {
//                 if(numbers[j] != 0)
//                 {
//                     swap(numbers[i],numbers[j]);
//                 }         
//             }
//         }
//     }
// }