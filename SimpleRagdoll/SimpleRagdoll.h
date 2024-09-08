#pragma once
#include <raylib.h>
#include <vector>
#include <math.h>

class SimpleRagdoll
{
public:
    void Main();

private:
    void Start();
    void Update();
    void Evaluate();
    void Draw();

    const Vector2 screenSize = { 800,500 };
    const Color clearColor = RAYWHITE;

    float gravity = 9.8f;

    Rectangle ground;

    struct BodyPart {
        //=========== Variables
        Rectangle rec;
        Color color;

        Vector2 position = { 0,0 };
        Vector2 totalForce = { 0,0 };
        Vector2 size;
        float mass;
        float friction;
        float angle;

        bool isHead = false;

        //=========== Functions
        BodyPart(Vector2 limbSize, Vector2 limbPos, float limbMass, float limbFriction, float limbAngle, Color col)
        {
            size = limbSize;
            position = limbPos;
            mass = limbMass;
            friction = limbFriction;
            angle = limbAngle;
            color = col;
        }

        void DrawPart()
        {
            rec = Rectangle{ position.x,position.y,size.x,size.y };
            DrawRectanglePro(rec, { 0,0 }, angle, color);
        }

        void Move()
        {
            position.x += totalForce.x * GetFrameTime();
            position.y += totalForce.y * GetFrameTime();
        }
    };
    std::vector<BodyPart> parts;
};

