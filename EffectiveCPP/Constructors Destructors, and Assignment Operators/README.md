These are the topics learned from the book from the second chapter
1. Know what functions C++ silently writes and calls
   
        a. Default constructor
        b. Copy Constructor
        c. Assignement operator

3. Explicitly disallow the use of compiler generated functions you do not want

       class Uncopyable
       {
           protected:
               Uncopyable() {}
               ~Uncopyable() {}
       
           private:
               Uncopyable(const Uncopyable&);
               Uncopyable& operator(const Uncopyable&); // Moving unwanted call to private section
       };


       Now let's make your class as nor copyable and assignable...

       class HomeForSale: private Uncopyable
       {
           
       };

4. Declare destructors virtual in polymorphic Base classes to clean up the memory properly.
   
        a. Polymorphic base classes should declare virtual destructors. If a class has any virtual functions,
           it should have a virtual destructor.
        b. classes not designed to be base classes or not designed to be used polymorphically
           should not declare virtual destructors.
   
6. Prevent exceptions from leaving destructors.
   
           class DBConn
           {
               public:
                   //...
                   DBConn(): db(DBConnection())
                   {
                       db.connect();
                   }
                   ~DbConn()
                   {
                       db.close(); // what if close throws an exception. It's a memory leak and the code after close will                                       // not execute
                       // There are two ways to handle it
                       // 1. Terminate the program
                           try
                           {
                               db.close();
                           }
                           catch(...)
                           {
                               Log Entry
                               std::abort();
                           }
   
                       // 2. Swallow the exception
                           try
                           {
                               db.close();
                           }
                           catch(...)
                           {
                               // Log Entry that call to close failed and continue the programming.(**Not a good practice but                            // but sometimes required)
                           }
                   }
               private:
                   DBConnection db;
           };


           More better approach to handle the situation is by proving close interface to the client. If client didn't closed then close it in destructor.

           class DBConn
           {
               public:
                   void close()
                   {
                        db.close()
                        closed = true;
                   }

                   ~DBConn()
                   {
                       if(!closed)
                       {
                           try
                           {
                               db.close();
                           }
                           catch(...)
                           {
                           }
                       }
                   }
           }
