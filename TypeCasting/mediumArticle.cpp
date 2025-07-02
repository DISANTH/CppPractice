#include<iostream>

using namespace std;

class Entity {
public:
    virtual void Print() {} // Makes Entity a polymorphic class
};

class Player : public Entity {
    const char* m_Name = "Player";
public:
    void PrintPlayer() { std::cout << "Player: " << m_Name << "\n"; }
};

class Enemy : public Entity {
    std::string m_Name = "Enemy";
public:
    void PrintEnemy() { std::cout << "Enemy: " << m_Name << "\n"; }
};

int main() {
    Player* player = new Player();
    Entity* entity = new Enemy();

    // Dynamic Casting
    Player* p0 = dynamic_cast<Player*>(entity);
    if (p0) {
        std::cout << "dynamic_cast succeeded\n";
    } else {
        std::cout << "dynamic_cast failed!\n";
    }

    // Static Casting
    Player* p1 = static_cast<Player*>(entity);
    if (p1) {
        std::cout << "static_cast succeeded\n";
    } else {
        std::cout << "static_cast failed!\n";
    }

    // Accessing the object
    p1->PrintPlayer(); // Undefined behavior

    delete player;
    delete entity;
    return 0;
}