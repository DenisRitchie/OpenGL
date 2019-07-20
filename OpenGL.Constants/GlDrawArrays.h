#pragma once
#ifndef _GL_DRAW_ARRAYS_HPP_
#define _GL_DRAW_ARRAYS_HPP_

// https://docs.microsoft.com/en-us/windows/win32/opengl/gldrawarrays

namespace OpenGL
{
    // With glDrawArrays, you can specify multiple geometric primitives to render. 
    // Instead of calling separate OpenGL functions to pass each individual vertex, normal, or color, you can specify separate arrays of vertices, normals, and colors to define a sequence of primitives (all the same kind) with a single call to glDrawArrays.
    //
    // When you call glDrawArrays, count sequential elements from each enabled array are used to construct a sequence of geometric primitives, beginning with the first element.
    // The mode parameter specifies what kind of primitive to construct and how to use the array elements to construct the primitives.
    //
    // After glDrawArrays returns, the values of vertex attributes that are modified by glDrawArrays are undefined.
    // For example, if GL_COLOR_ARRAY is enabled, the value of the current color is undefined after glDrawArrays returns.Attributes not modified by glDrawArrays remain defined.When GL_VERTEX_ARRAY is not enabled, no geometric primitives are generated but the attributes corresponding to enabled arrays are modified.
    //
    // You can include glDrawArrays in display lists.When you include glDrawArrays in a display list, the necessary array data, determined by the array pointers and the enables, are generated and entered in the display list.
    // The values of array pointers and enables are determined during the creation of display lists.
    //
    // You can read static array data at any time.
    // If any static array elements are modified and the array is not specified again, the results of any subsequent calls to glDrawArrays are undefined.
    //
    // Although no error is generated when you specify an array more than once within glBegin and glend pairs, the results are undefined.
    //
    // primitive_to_render: The kind of primitives to render.
    // The following constants specify acceptable types of primitives : GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES, GL_QUAD_STRIP, GL_QUADS, and GL_POLYGON.
    // first_index: The starting index in the enabled arrays.
    // number_of_indexes: The number of indexes to render.
    inline void __stdcall DrawArrays(const BeginMode::Type &primitive_to_render, const GLint &first_index, const GLsizei &number_of_indexes)
    {
        ::glDrawArrays(primitive_to_render, first_index, number_of_indexes);
    }
}

#endif // !_GL_DRAW_ARRAYS_HPP_
