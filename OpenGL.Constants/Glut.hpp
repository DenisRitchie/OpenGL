#pragma once
#ifndef _GLUT_HPP_
#define _GLUT_HPP_

// https://www.opengl.org/resources/libraries/glut/spec3/spec3.html
// https://www.opengl.org/resources/libraries/glut/spec3/node15.html

#include "GlutDisplayMode.hpp"

namespace Glut
{
    // glutInitDisplayMode sets the initial display mode.
    // Display mode, normally the bitwise OR-ing of GLUT display mode bit masks. See values below: DisplayMode
    // The initial display mode is used when creating top-level windows, subwindows, and overlays to determine the OpenGL display mode for the to-be-created window or overlay.
    // Note that GLUT_RGBA selects the RGBA color model, but it does not request any bits of alpha(sometimes called an alpha buffer or destination alpha) be allocated.
    // To request alpha, specify GLUT_ALPHA.
    // The same applies to GLUT_LUMINANCE.
    inline void __stdcall InitDisplayMode(const DisplayMode &mode)
    {
        ::glutInitDisplayMode(mode);
    }

    // glutInitWindowPosition and glutInitWindowSize set the initial window position and size respectively.
    // Windows created by glutCreateWindow will be requested to be created with the current initial window position and size.
    // The initial value of the initial window position GLUT state is - 1 and -1. 
    // If either the X or Y component to the initial window position is negative, the actual window position is left to the window system to determine.
    // The initial value of the initial window size GLUT state is 300 by 300. 
    // The initial window size components must be greater than zero.
    // The intent of the initial window position and size values is to provide a suggestion to the window system for a window's initial size and position. 
    // The window system is not obligated to use this information. 
    // Therefore, GLUT programs should not assume the window was created at the specified size or position. 
    // A GLUT program should use the window's reshape callback to determine the true size of the window.
    inline void __stdcall InitWindowPosition(const int x, const int y)
    {
        ::glutInitWindowPosition(x, y);
    }

    // glutInitWindowPosition and glutInitWindowSize set the initial window position and size respectively.
    // Windows created by glutCreateWindow will be requested to be created with the current initial window position and size.
    // The initial value of the initial window position GLUT state is - 1 and -1. 
    // If either the X or Y component to the initial window position is negative, the actual window position is left to the window system to determine.
    // The initial value of the initial window size GLUT state is 300 by 300. 
    // The initial window size components must be greater than zero.
    // The intent of the initial window position and size values is to provide a suggestion to the window system for a window's initial size and position. 
    // The window system is not obligated to use this information. 
    // Therefore, GLUT programs should not assume the window was created at the specified size or position. 
    // A GLUT program should use the window's reshape callback to determine the true size of the window.
    inline void __stdcall InitWindowSize(const int width, const int height)
    {
        ::glutInitWindowSize(width, height);
    }

    // glutCreateWindow creates a top-level window. 
    // The name will be provided to the window system as the window's name. 
    // The intent is that the window system will label the window with the name.
    // Implicitly, the current window is set to the newly created window.
    // Each created window has a unique associated OpenGL context.
    // State changes to a window's associated OpenGL context can be done immediately after the window is created.
    // The display state of a window is initially for the window to be shown.
    // But the window's display state is not actually acted upon until glutMainLoop is entered. 
    // This means until glutMainLoop is called, rendering to a created window is ineffective because the window can not yet be displayed.	
    // The value returned is a unique small integer identifier for the window.
    // The range of allocated identifiers starts at one.
    // This window identifier can be used when calling glutSetWindow.
    // X Implementation Notes:
    // The proper X Inter - Client Communication Conventions Manual(ICCCM) top - level properties are established.
    // The WM_COMMAND property that lists the command line used to invoke the GLUT program is only established for the first window created.
    inline int __stdcall GlutCreateWindow(const char *__restrict title)
    {
        return ::glutCreateWindow(title);
    }

    // glutMainLoop enters the GLUT event processing loop.
    // glutMainLoop enters the GLUT event processing loop. 
    // This routine should be called at most once in a GLUT program. 
    // Once called, this routine will never return. 
    // It will call as necessary any callbacks that have been registered.
    inline void __stdcall MainLoop()
    {
        ::glutMainLoop();
    }

    // glutDisplayFunc sets the display callback for the current window. 
    // When GLUT determines that the normal plane for the window needs to be redisplayed, the display callback for the window is called. 
    // Before the callback, the current window is set to the window needing to be redisplayed and (if no overlay display callback is registered) the layer in use is set to the normal plane. 
    // The display callback is called with no parameters. 
    // The entire normal plane region should be redisplayed in response to the callback (this includes ancillary buffers if your program depends on their state).
    // GLUT determines when the display callback should be triggered based on the window's redisplay state. 
    // The redisplay state for a window can be either set explicitly by calling glutPostRedisplay or implicitly as the result of window damage reported by the window system. 
    // Multiple posted redisplays for a window are coalesced by GLUT to minimize the number of display callbacks called.
    // When an overlay is established for a window, but there is no overlay display callback registered, the display callback is used for redisplaying both the overlay and normal plane(that is, it will be called if either the redisplay state or overlay redisplay state is set).
    // In this case, the layer in use is not implicitly changed on entry to the display callback.
    // See glutOverlayDisplayFunc to understand how distinct callbacks for the overlay and normal plane of a window may be established.
    // When a window is created, no display callback exists for the window.
    // It is the responsibility of the programmer to install a display callback for the window before the window is shown.
    // A display callback must be registered for any window that is shown.
    // If a window becomes displayed without a display callback being registered, a fatal error occurs.
    // Passing NULL to glutDisplayFunc is illegal as of GLUT 3.0; there is no way to ``deregister'' a display callback(though another callback routine can always be registered).
    // Upon return from the display callback, the normal damaged state of the window(returned by calling glutLayerGet(GLUT_NORMAL_DAMAGED) is cleared.
    // If there is no overlay display callback registered the overlay damaged state of the window(returned by calling glutLayerGet(GLUT_OVERLAY_DAMAGED) is also cleared.
    inline void __stdcall DisplayFunc(void(__cdecl *func)(void))
    {
        ::glutDisplayFunc(func);
    }
}

#endif // !_GLUT_HPP_
