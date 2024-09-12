#pragma once
#include <raylib.h>
#include <raymath.h>
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

    const Vector2 screenSize = { 1900,600 };
    const Color clearColor = RAYWHITE;

    float gravity = 9.8f;

    Rectangle ground;

    enum PartType
    {
        None,
        Bone,
        Head,
    };

    struct BodyPart {
        //=========== Variables ===========

        PartType type;
        Rectangle rec;
        Color color;

        Vector2 position = { 0,0 };
        Vector2 totalForce = { 10,20 };
        Vector2 size;

        float mass;
        float friction;
        float angle;

        PartType dependant = None;
        Vector2 offset = { 0,0 };
        Vector2 origin = { size.x / 2,size.y / 2 }; //defaults to center

        //=========== Functions ===========

        BodyPart() {}

        //No offset from anything
        BodyPart(PartType limbType, Vector2 limbSize, Vector2 limbPos, float limbMass, float limbFriction, float limbAngle, Color col)
        {
            type = limbType;
            size = limbSize;
            position = limbPos;
            mass = limbMass;
            friction = limbFriction;
            angle = limbAngle;
            color = col;
            origin = Vector2{ 0,size.y/2 };
        }

        //Offset/dependant from something
        BodyPart(BodyPart dependantLimb, Vector2 limbOffset, PartType limbType, Vector2 limbSize, float limbMass, float limbFriction, float limbAngle, Color col)
        {
            type = limbType;
            size = limbSize;
            offset = limbOffset;
            dependant = dependantLimb.type;
            position = Vector2{ dependantLimb.position.x + limbOffset.x, dependantLimb.position.y + limbOffset.y };
            origin = Vector2{ 0,size.y/2 };
            mass = limbMass;
            friction = limbFriction;
            angle = limbAngle;
            color = col;
        }

        void DrawPart()
        {
            rec = Rectangle{ position.x,position.y,size.x,size.y };
            DrawRectanglePro(rec, origin, angle, color);
            //DrawCircle(position.x * size.x / origin.x, position.y * size.y / origin.y, 3, RED);
        }

        void Move()
        {
            position.x += totalForce.x * GetFrameTime();
            position.y += totalForce.y * GetFrameTime();
        }

        void RotateOriginDependantly(float rad)
        {
            Vector2 p = position;

            float s = sinf(rad);
            float c = cosf(rad);

            p.x -= offset.x;
            p.y -= offset.y;

            float xnew = p.x * c - p.y * s;
            float ynew = p.x * s + p.y * c;

            p.x = xnew + offset.x;
            p.y = ynew + offset.y;

            position = p;
        }
    };

    BodyPart parts[4];
    void CalculateOffset(BodyPart& body, PartType dependant, Vector2 offset);
};

