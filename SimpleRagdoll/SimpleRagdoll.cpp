#include "SimpleRagdoll.h"
#include <iostream>

void SimpleRagdoll::Main()
{
    InitWindow(screenSize.x, screenSize.y, "Simple Ragdoll");
    SetTargetFPS(60);

    Start();

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(clearColor);
            Update();
        EndDrawing();
    }

    CloseWindow();
}

void SimpleRagdoll::Start()
{
    //ground
    ground = Rectangle{ 0.0f, (float)GetScreenHeight(), (float)GetScreenWidth(), 20.0f };

    //Head
    BodyPart head = BodyPart({ 50,50 }, { 200,200 }, 10, 0, 0, BLACK);
    head.isHead = true;
    parts.push_back(head);

    //Body, bottom of head
    BodyPart body = BodyPart({ 50,100 }, { head.position.x + head.size.x / 2, head.position.y + head.size.y }, 20, 0, 0, DARKGRAY);
    parts.push_back(body);
}

void SimpleRagdoll::Update()
{
    Evaluate();
    Draw();
}

void SimpleRagdoll::Evaluate()
{
    for (BodyPart& bp : parts)
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            parts[0].position = GetMousePosition();
        }
        else if (bp.isHead)
        {
            if (CheckCollisionRecs(ground, bp.rec))
            {
                bp.totalForce = { 0.0f,0.0f };
            }
            else
            {
                //Calculate Gravity
                bp.totalForce = Vector2{ 0, bp.mass * gravity };
                bp.Move();
            }
        }

        if (!bp.isHead)
        {
            bp.position.x = parts[0].position.x - bp.size.x;
            bp.position.y = parts[0].position.y - bp.size.y;
        }
    }
}

void SimpleRagdoll::Draw()
{
    for (BodyPart& bp : parts)
    {
        bp.DrawPart();
    }
}

