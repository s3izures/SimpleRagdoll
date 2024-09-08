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

}

void SimpleRagdoll::Update()
{

}

void SimpleRagdoll::Evaluate()
{

}

void SimpleRagdoll::Draw()
{

}
