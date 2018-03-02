///////////////////////////////////////////////////////////////////////////
// FILE:                        window.h                                 //
///////////////////////////////////////////////////////////////////////////
//                      BAHAMUT GRAPHICS LIBRARY                         //
//                        Author: Corbin Stark                           //
///////////////////////////////////////////////////////////////////////////
//                                                                       //
// Permission is hereby granted, free of charge, to any person obtaining //
// a copy of this software and associated documentation files (the       //
// "Software"), to deal in the Software without restriction, including   //
// without limitation the rights to use, copy, modify, merge, publish,   //
// distribute, sublicense, and/or sell copies of the Software, and to    //
// permit persons to whom the Software is furnished to do so, subject to //
// the following conditions:                                             //
//                                                                       //
// The above copyright notice and this permission notice shall be        //
// included in all copies or substantial portions of the Software.       //
//                                                                       //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       //
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    //
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.//
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  //
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  //
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     //
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                //
///////////////////////////////////////////////////////////////////////////

#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include <stdlib.h>
#include <vector>
#include "maths.h"

#define MAX_KEYS	1024
#define MAX_BUTTONS	32

void initWindow(int width, int height, const char* title, bool fullscreen, bool resizable, bool primary_monitor);

void setWindowPos(int x, int y);
void setWindowSize(int width, int height);
void beginDrawing();
void endDrawing();
bool isWindowClosed();

void setClearColor(float r, float g, float b, float a);
void setClearColor(vec4f& color);
void setWindowResizeCallback(void(*resizecallback)(int width, int height));

bool isKeyPressed(unsigned int keycode);
bool isKeyReleased(unsigned int keycode);
bool isButtonPressed(unsigned int button);
bool isButtonReleased(unsigned int button);
bool isKeyDown(unsigned int keycode);
bool isButtonDown(unsigned int button);
bool isKeyUp(unsigned int keycode);
bool isButtonUp(unsigned int button);

double getElapsedTime();

void getMousePos(double* mousex, double* mousey);
vec2f getMousePos();
void disposeWindow();

void setFPSCap(double FPS);

void setMouseLocked(bool locked);
void setMouseHidden(bool hidden);
void setVSync(bool vsync);

int getWindowWidth();
int getWindowHeight();

#endif