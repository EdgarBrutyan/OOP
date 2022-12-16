#include<iostream>

class Grass{

private:

	int count; // count of grass in area


public:

	Grass()
	{
		count = 10; // предположим всегда имеем столько
	}


	void set_count_of_grass(int& count)
	{
		this->count = count;
	}

	friend class Frog;

};  

class Sun {
private:

	bool glow;
	int X; // условно пердставим что начиная с 6 утра до 19 вечера оно сияет 
	int Y; 

public:

	void glow_or_not(int hours)
	{

		if (hours >= 6 && hours <= 19)
		{
			this->glow = 1;
		}

		else
		{
			this->glow = 0;
		}
	}


	bool get_glow()
	{
		return glow;
	}

	friend class Frog;
	friend class Tree;

};

class Frog {

private:

	void breathe()
	{
	      // by default he breath
	}

public:

	void Eat_Grass(Grass& a)
	{
		--a.count;
		breathe(); // breathe even during eating
	}

	void move()
	{
		std::cout << "Frog is moving";
		breathe();
	}

	void sleep()
	{
		
			std::cout << "The frog sleeps";
			breathe();
		  
	}

	
};

class Tree {

public:

	void photosynthesis(int hours)
	{
		if (hours >= 6 && hours <= 19)
		{
			std::cout << "The tree is doing photosynthesis";
		}
	}

	void stop_photosynthesis(int hours)
	{
		if (hours < 6 && hours >= 0 && hours > 19 && hours <= 24)
		{
			std::cout << "THe tree stop doing photosynthesis";
		}
	}


};

class World {

public:
	Sun sun;
	Frog frog;
	Grass grass;
	Tree tree;
};

int main()
{
	World world;
	
	std::cout << "Enter the current time";
	int time = 0;
	std::cin >> time;
	world.sun.glow_or_not(time);
	bool _glow = world.sun.get_glow();

	while (_glow)
	{
		world.frog.move();
		world.tree.photosynthesis(time);
	}

	world.frog.sleep();
	world.tree.stop_photosynthesis(time);

	std::cout << "Time for sleep, the sun does not glow";
}


