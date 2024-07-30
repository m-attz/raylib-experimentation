#include "raylib.h"
#include "stdlib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define TARGET_FPS 60

int main(void) {
  /* 
     Initialize window with correct values
     Set target FPS (fps lock)
     Declare array of type Vector3
  */

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "0_0");
  SetTargetFPS(TARGET_FPS);
  Vector3 spherePos = {0.0f, 0.0f, 0.0f};


  /* 
     Store necessary data types (mostly x, y, z vectors) 
     for camera attributes
  */

  Camera3D camera = { 0 };
  camera.position = (Vector3){0.0f, 5.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 0.5f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;
  
  /*
    Loop while the window should NOT close
  */
  while (!WindowShouldClose()) {

    /*
      Increment vector values based on key pressed
    */

    if (IsKeyDown(KEY_UP)) camera.position.y += .5f;
    if (IsKeyDown(KEY_DOWN)) camera.position.y -= .5f;
  

    
    BeginDrawing();
    /* DRAWING BEGINS HERE..*/
    ClearBackground(RAYWHITE);
    BeginMode3D(camera);
    
    DrawGrid(10, 1.0f);
    DrawSphere(spherePos, 1.0f, RED);


    EndMode3D();



    EndDrawing();

  }





  CloseWindow();

  return 0;
}

