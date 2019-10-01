#pragma once

namespace classes {

	class Liste {
	public:
		Liste(float* tal, int length);
		Liste(int length = 2);
		Liste(const Liste& l);
		void setTal(float NYTtal, int sted);
		float getTal(int sted);
		Liste operator+(Liste rhs);
		void operator=(const Liste& rhs);
		~Liste();

	private:
		float* tal;
		int length;
	};

	class Box {
	public:
		Box(Liste l = Liste(2));
		void makeSnake();
		void makeEmpty();
		void makeApple();
		float getX();
		float getY();
		bool getSnakeBool();
		bool getAppleBool();
		void operator=(const Box& rhs);
		~Box();

	private:
		Liste pos;
		int howLongHasBeenSnake;
		bool snakeIsInside;
		bool appleIsInside;
	};

	class Snake {
	public:
		Snake(Liste l);
		void move();
		void calculateNextBox();
		void changeDir(int i);
		~Snake();

	private:
		int dirNum;
		bool hasGrown;
		Box nextBox;
		Liste pos, dir;
	};
}