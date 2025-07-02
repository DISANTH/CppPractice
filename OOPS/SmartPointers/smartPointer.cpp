/*
    When we use smart pointers....

    RAII  --> Resource acquisition is initialization.

*/

/**
   1. "Febin Melit"
   2. "Eggs For Egg"

        "Eggs" : 2
        "For" : 1

   3. 1 --> 2 --> 3 --> 4
   

 */

 
 class shared_ptr
 {
    
 }

class FileHandler {
public:
    FileHandler(const std::string& filename) : file(filename) {
        if (!file.is_open()) { // Acquired
            throw std::runtime_error("Could not open file");
        }
        std::cout << "File Opened" << std::endl;
    }

    ~FileHandler() {
        file.close();// released
        std::cout << "File Closed" << std::endl;
    }
    
    void write_to_file(const std::string& text){
        file << text << std::endl;
    }

private:
    std::ofstream file;
};

int main()
{
    FileHandler pointDatahandler("../mockData/pointData.json");
    return 0;
}