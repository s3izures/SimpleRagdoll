#pragma once
#include <raylib.h>

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
    const Color clearColor = { 250, 250, 250, 255 };
};

