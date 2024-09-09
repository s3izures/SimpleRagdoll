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
    parts[Torso] = BodyPart(Torso, Vector2{ 100,150 }, Vector2{ (float)GetScreenWidth() / 2,(float)GetScreenHeight() / 2 }, 50, 0, 0, BLACK);
    parts[Torso].origin = Vector2{ parts[Torso].size.x / 2 ,parts[Torso].size.y / 2 };

    parts[Head] = BodyPart(parts[Torso], Vector2{ 0,-50}, Head, Vector2{50,50}, 10, 0, 0, RED);
    //parts[Head].origin = Vector2{ parts[Head].size.x / 2,parts[Head].size.y + parts[Torso].size.y / 2};
    parts[Head].origin = Vector2{ parts[Head].size.x / 2,parts[Head].size.y};

    parts[ArmL] = BodyPart(parts[Torso], Vector2{ 0,0 }, ArmL, Vector2{ 50,100 }, 20, 0, 0, RED);
    parts[ArmL].origin = Vector2{ parts[ArmL].size.x / 2 + parts[Torso].size.x, parts[ArmL].size.y / 2 };
}

void SimpleRagdoll::Update()
{
    Evaluate();
    Draw();
}

void SimpleRagdoll::Evaluate()
{
    parts[Torso].angle;
    //parts[Head].angle++;
    //parts[Head].Move();
    /*parts[Head].angle = parts[Torso].angle;
    parts[ArmL].angle = parts[Torso].angle;*/
}

void SimpleRagdoll::CalculateOffset(BodyPart& body, PartType dependant, Vector2 offset)
{
    body.position.x = parts[dependant].position.x + offset.x;
    body.position.y = parts[dependant].position.y + offset.y;
}

void SimpleRagdoll::Draw()
{
    parts[Torso].DrawPart();
    parts[Head].DrawPart();   
    parts[ArmL].DrawPart();   
}

