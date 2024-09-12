#include "SimpleRagdoll.h"

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
    parts[Head] = BodyPart(Head, Vector2{ 100,50 }, Vector2{ (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 }, 50, 0, 0, BLACK);
    parts[Bone] = BodyPart(parts[Head], Vector2{ 100,0 }, Bone, Vector2{100,50}, 10, 0, 0, RED);
}

void SimpleRagdoll::Update()
{
    Evaluate();
    Draw();
}

void SimpleRagdoll::Evaluate()
{
    parts[Head].angle++;
    parts[Bone].RotateOriginDependantly(0.1f);
}

void SimpleRagdoll::CalculateOffset(BodyPart& body, PartType dependant, Vector2 offset)
{
    body.position.x = parts[dependant].position.x + offset.x;
    body.position.y = parts[dependant].position.y + offset.y;
}

void SimpleRagdoll::Draw()
{
    parts[Head].DrawPart();
    parts[Bone].DrawPart();   
    //parts[ArmL].DrawPart();   
}

