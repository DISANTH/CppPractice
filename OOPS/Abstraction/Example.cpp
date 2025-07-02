

// Interface providing to client

class APIClient // Interface
{
    public:
        virtual void fetechID() = 0; // Passing Rule
        virtual string fecthAll(vector<string> Ids) = 0;
        virtual future<string> readyIDAsync(string id) = 0;
        virtual ~APIClient()
        {

        }
};

class DatabaseApiClient: public APIClient // SQL
{
    void fetechID()
    {
        // This knows source is database;
    }
    string fecthAll(vector<string> Ids)
    {

    }
    future<string> readyIDAsync(string id)
    {
        
    }
};

class AWSSerrviceCLient: public APIClient
{
    virtual void fetechID()
    {
        // This knows source is database; // https://carrierAwsService.com/fetchId/{ID}
    }
}

//checkdal.cpp;

class FileServiceClient: public APIClient
{
    virtual void fetechID()
    {
        // This knows source is database;
        
        ifstream file("build/mockData/pointData.json");
    }
}



// DAL library (carrier common UI) --> 


They given an interface
 How to acess DAL

  dal.so --> implitation; (Byte code)





 1. fetechID (string ID);
 2. fecthAll (vector<string> IdList);
 3. readyIDAsync();
 4. readAll();







































class Circle: public Shape
{
    public:
        void draw()
        {
            Canvas canvas;
            canvas.drawCircle();
        }
        ~Circle()
        {

        }
};

class Square: public Shape
{
    public:
        void draw()
        {
            Canvas canvas;
            canvas.drawSquare();
        }
        ~Square()
        {

        }
};

