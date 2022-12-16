#include<iostream>


struct Grass{
	int count; 
};  

// end of strcut Grass and inplementation of functions

void constrcutor_grass(Grass* a)
{
    a->count = 1000;
}
void set_grass_count(Grass* a, int& _count )
{
    a->count =  _count;
}
void destructor(Grass* a)
{
    std::cout << " Dessruction of Grass";
}





// struct

struct Sun {
	bool glow;
};


 // Functions for sun
void constructor_for_sun(Sun* sun)
    {
        std::cout << "Enter the current time(hours)" << "\n"; 
        int hours = 0;
        std::cin >> hours;
        
        std::cout << "minutes" << "\n";
        int minutes = 0;
        std::cin >> minutes;

		if (hours >= 6 && hours <= 19)
		{
			sun->glow = 1;
		}

		else
		{
			sun->glow = 0;
		}
	}
    void destructor_for_sun (Sun* sun)
    {
        
    }
	bool sun_get_glow(Sun* a)
	{
		return a->glow;
	}
	
	
	
//struct  Frog

struct Frog {};

// functions for frog

void constructor_Frog(Frog* a)
    {
        std::cout << "Costructor for Frog";
    }
    
    void destuctor (Frog* a)
    {
        std::cout << "Destructor for Frog";
    }

    void Frog_breathe(Frog* frog)
	{
	      // by default he breath
	}

	void  Frog_Eat_Grass(Frog* frog, Grass* a)
	{
		--a->count;
		Frog_breathe(frog); // breathe even during eating
	}

	void  Frog_move(Frog* frog, Sun* a)
	{
	    if(a->glow == true)
	    {
	        std::cout << "Frog is moving";
	    }
	    
	    Frog_breathe(frog);
		
	}

	void  Frog_sleep(Frog* frog, Sun* a)
	{
	    if(a->glow == false)
	    {
	        std::cout << "The frog sleeps";
	    }
		Frog_breathe(frog);
		  
	}

// fucntions for Tree



struct Tree {};

	void photosynthesis(Tree* a, int hours)
	{
		if (hours >= 6 && hours <= 19)
		{
			std::cout << "The tree is doing photosynthesis";
		}
	}

	void stop_photosynthesis(Tree* a, int hours)
	{
		if (hours < 6 && hours >= 0 && hours > 19 && hours <= 24)
		{
			std::cout << "THe tree stop doing photosynthesis";
		}
	}


int main()
{
	Sun a;
	constructor_for_sun(&a);
	
	


}