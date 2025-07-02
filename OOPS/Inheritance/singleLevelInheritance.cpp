
// # DRY --> Don't Repeat Yourself

// convertTo24Hours() --> Timeslider and monthSlider...

Timeslider
{
    function convertTo24Hours()
    {
        //
        //
        //
        //
    }

    TextField{
        sOriginString: convertTo24Hours()
    }
}

MonthSlider
{
    function convertTo24Hours()
    {
        //
        //
        //
        //
    }

    TextField{
        sOriginString: convertTo24Hours()
    }
}

string convertTo24Hours()
{
    // Code memory
    // Code Execution -- NO
    // 
}

class TextField
{
    private:
        string text;
        validator validator;

        onBackButtonClicked()
        {

        }

    signals:
        backButtonClicked();
}


class TextFieldWithCustomKeyBoard : public TextField
{
    private:
        KeyboardSim* sim;
}





// # Single Level Inheritance

class Parent
{
    private:
        int 
};

class Child: public Parent
{

};





























// # Multi Level Inheritance

class Parent
{

};

class Child: public Parent
{

};

class GrandChild: public Child
{

};















// # Multiple Inheritance

class Parent1
{

};

class Parent2
{

};

class Child: public Parent1, public Parent2
{

};



// #Hybrid Inheritance


class Parent
{
};

class Child1: public Parent
{

};

class Child2: public Parent
{

};

class GrandChild: public Child1, public Child2
{

};