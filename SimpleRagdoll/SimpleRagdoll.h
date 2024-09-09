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
        Head,
        Torso,
        ArmL,
        ArmR,
        LegL,
        LegR
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
        }

        //Offset/dependant from something
        BodyPart(BodyPart dependantLimb, Vector2 limbOffset, PartType limbType, Vector2 limbSize, float limbMass, float limbFriction, float limbAngle, Color col)
        {
            type = limbType;
            size = limbSize;
            offset = limbOffset;
            dependant = dependantLimb.type;
            position = Vector2{ dependantLimb.position.x + offset.x,dependantLimb.position.y + offset.y };
            mass = limbMass;
            friction = limbFriction;
            angle = limbAngle;
            color = col;
        }

        void DrawPart()
        {
            rec = Rectangle{ position.x + offset.x,position.y + offset.y,size.x,size.y };
            DrawRectanglePro(rec, origin, angle, color);
        }

        void Move()
        {
            position.x += totalForce.x * GetFrameTime();
            position.y += totalForce.y * GetFrameTime();
        }
    };

    BodyPart parts[6];
    void CalculateOffset(BodyPart& body, PartType dependant, Vector2 offset);
};

