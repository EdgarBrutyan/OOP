#include<iostream>

class Dog {

private:

    std::string breed;
    std::string byname;
    double high;
    double weight;
    int age;
    int energy{100};
    int healph{100};

public:

    Dog() = default;

    Dog(Dog&) = delete; // it should be uncopyable object
   

     explicit Dog(std::string _breed, std::string _byname, int _high, double _weight, int _age, int _energy) 
         //explicit in order to block conversion constructor just in case of assingment to other class

        :breed{ _breed }, byname{ _byname }, high{ _high }, weight{ _weight }, age{_age},  energy{_energy}
         {
             if (high < 10 || weight < 5 || age < 0) { throw("Invalid arguments"); }
         }


    // Settrers

    void setByName(std::string byname)
    {
        this->byname = byname;
    }

    void setBreed(std::string breed)
    {
        this->breed = breed;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setAge(int weight)
    {
        this->weight = weight;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setAge(int high)
    {
        this->high = high;
    }


    // Functions/methods

    void bark()
    {
        std::cout << "Haw haw !!!" << "\n";
        --energy;
    }


    void sleep()
    {
        std::cout << "the dog is sleeping" << "\n";
        energy++;
        high += 0.02;
    }

    void move(std::string direction)
    {
        std::cout << " the dog is moving" << direction;
        energy -= 10;
        weight -= 0.12;
    }


    void run(std::string direction)
    {
        std::cout << "the dog is runnning to" << direction;
        energy -= 30;
        weight -= 1.12;
    }

    void eat()
    {
        energy += 10;
        weight += 0.5;
    }

    void relax()
    {
        energy++;
    }

    ~Dog()
    {

    }

    friend class  Hospital;
};




// Hospital


class  Hospital {


private:
    std::string name;
    std::string hospital_number {"001"}; // by default
    int number_of_stuff{1000};
    int opeartion_rooms{100};
    int hospital_avto{ 20 };
    double budjet;

public:

    Hospital() = default;

    explicit Hospital(const std::string _name, const std::string _hospital_number, int _number_of_stuff, int _operation_rooms, int _hospital_avto, double _budjet)
        :name(_name), hospital_number(_hospital_number), number_of_stuff(_number_of_stuff), opeartion_rooms(_operation_rooms), hospital_avto(_hospital_avto), budjet(_budjet)
    {

    }


    void getting_call(std::string number)
    {
        --hospital_avto;
    }

    void operation(Dog& dog)
    {
        this->number_of_stuff -= 5;
        this->budjet += 500; // dollars
        dog.healph = 100;
    }

    void Remont()
    {
        this->opeartion_rooms += 10;
        budjet -= 10000;
    }

    ~Hospital()
    {

    }


};




// Helicopter


class Helicopter {

private:

    std::string type;
    double accelerate;
    int speed;
    double current_high;
    int energy;
    int count_of_kerosin;

public:

    Helicopter() = default;

    explicit Helicopter(std::string _type, double _accelerate, int _speed, double _current_high, int _energy, int _count_of_kerosin)
        :type(_type), accelerate(_accelerate), speed(_speed), current_high(_current_high), energy(_energy), count_of_kerosin(_count_of_kerosin)
    {

    }


    void rise_from_the_place()
    {
        energy -= 10;
        count_of_kerosin--;
        current_high = 100;
    }

    void move_forward(std::string destination, int lenght_of_path)
    {
        count_of_kerosin = lenght_of_path / 100;
        energy = lenght_of_path / 200;
    }

    void Rise_Speed()
    {
        speed += 10;
        energy--;
        count_of_kerosin--;
    }

};

int main()
{  

    return 0;
}
