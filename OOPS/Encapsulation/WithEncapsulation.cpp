class Car{
    private:
        string brand;
        int year;
    public:
        void setBrand(const std::string& carBrand)
        {
            brand = carBrand;
        }

        string getBrand() const
        {
            return brand;
        }

        void setYear(const int carYear)
        {
            year = carYear;
        }

        int getYear() const
        {
            return year;
        }
}

int main()
{
    Car myCar;
    myCar.setBrand("Benz");
    myCar.setYear(2018);

    cout << "Brand :: " << myCar.brand << " , Year: " << myCar.year << std::endl;
    return 0;
}