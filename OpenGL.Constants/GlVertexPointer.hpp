#pragma once
#ifndef _GL_VERTEX_POINTER_HPP_
#define _GL_VERTEX_POINTER_HPP_

// https://docs.microsoft.com/en-us/windows/win32/opengl/glvertexpointer

namespace OpenGL
{
    // The number of coordinates per vertex. 
    // The value of size must be 2, 3, or 4.
    class VertexSize
    {
    private:
        GLint value;

    public:
        inline constexpr VertexSize(const GLint &value = Two) noexcept : value{ value } { }
        inline constexpr operator const GLint&() const noexcept { return value; }
        using Type = GLint;

        // glVertex*[d, f, i, s][v] function
        enum : GLint
        {
            // glVertex2[d, f, i, s][v] function    
            Two = 2,

            // glVertex3[d, f, i, s][v] function
            Three = 3,

            // glVertex4[d, f, i, s][v] function
            Four = 4,
        };
    };

    // The data type of each coordinate in the array using the following symbolic constants: GL_SHORT, GL_INT, GL_FLOAT, and GL_DOUBLE.
    class VertexDataType
    {
    private:
        GLenum value;

    public:
        inline constexpr VertexDataType(const GLenum &value = Double) noexcept : value{ value } { }
        inline constexpr operator const GLenum&() const noexcept { return value; }
        using Type = GLenum;

        // glVertex*[d, f, i, s][v] function
        enum : GLenum
        {
            // glVertex*s[v] function
            Short = GL_SHORT,

            // glVertex*i[v] function
            Int = GL_INT,

            // glVertex*f[v] function
            Float = GL_FLOAT,

            // glVertex*d[v] function
            Double = GL_DOUBLE,
        };
    };

    // The glVertexPointer function defines an array of vertex data.
    //
    // The glVertexPointer function specifies the location and data of an array of vertex coordinates to use when rendering. 
    // The size parameter specifies the number of coordinates per vertex. 
    // The type parameter specifies the data type of each vertex coordinate. 
    // The stride parameter determines the byte offset from one vertex to the next, enabling the packing of vertices and attributes in a single array or storage in separate arrays. 
    // In some implementations, storing the vertices and attributes in a single array can be more efficient than using separate arrays (see glInterleavedArrays).
    // 
    // A vertex array is enabled when you specify the GL_VERTEX_ARRAY constant with glEnableClientState.When enabled, glDrawArrays, glDrawElements, and glArrayElement use the vertex array.
    // By default, the vertex array is disabled.
    //
    // You cannot include glVertexPointer in display lists.
    //
    // When you specify a vertex array using glVertexPointer, the values of all the function's vertex array parameters are saved in a client-side state, and static array elements can be cached. 
    // Because the vertex array parameters are client-side state, their values are not saved or restored by glPushAttrib and glPopAttrib.
    // 
    // Although no error is generated if you call glVertexPointer within glBegin and glEnd pairs, the results are undefined.
    // 
    // number_of_coordinate: The number of coordinates per vertex. The value of size must be 2, 3, or 4.
    // data_type: The data type of each coordinate in the array using the following symbolic constants: GL_SHORT, GL_INT, GL_FLOAT, and GL_DOUBLE.
    // byte_offset: The byte offset between consecutive vertices. When stride is zero, the vertices are tightly packed in the array.
    // coordinate_of_the_first_vertex: A pointer to the first coordinate of the first vertex in the array.
    inline void __stdcall VertexPointer(const VertexSize::Type number_of_coordinate, const VertexDataType::Type data_type, const GLsizei byte_offset, const GLvoid *__restrict coordinate_of_the_first_vertex)
    {
        ::glVertexPointer(number_of_coordinate, data_type, byte_offset, coordinate_of_the_first_vertex);
    }

    // The glVertexPointer function defines an array of vertex data.
    //
    // The glVertexPointer function specifies the location and data of an array of vertex coordinates to use when rendering. 
    // The size parameter specifies the number of coordinates per vertex. 
    // The type parameter specifies the data type of each vertex coordinate. 
    // The stride parameter determines the byte offset from one vertex to the next, enabling the packing of vertices and attributes in a single array or storage in separate arrays. 
    // In some implementations, storing the vertices and attributes in a single array can be more efficient than using separate arrays (see glInterleavedArrays).
    // 
    // A vertex array is enabled when you specify the GL_VERTEX_ARRAY constant with glEnableClientState.When enabled, glDrawArrays, glDrawElements, and glArrayElement use the vertex array.
    // By default, the vertex array is disabled.
    //
    // You cannot include glVertexPointer in display lists.
    //
    // When you specify a vertex array using glVertexPointer, the values of all the function's vertex array parameters are saved in a client-side state, and static array elements can be cached. 
    // Because the vertex array parameters are client-side state, their values are not saved or restored by glPushAttrib and glPopAttrib.
    // 
    // Although no error is generated if you call glVertexPointer within glBegin and glEnd pairs, the results are undefined.
    // 
    // number_of_coordinate: The number of coordinates per vertex. The value of size must be 2, 3, or 4.
    // data_type: The data type of each coordinate in the array using the following symbolic constants: GL_SHORT, GL_INT, GL_FLOAT, and GL_DOUBLE.
    // vertices: A pointer to the first coordinate of the first vertex in the array.
    inline void __stdcall VertexPointer(const VertexSize::Type number_of_coordinate, const VertexDataType::Type data_type, const GLvoid *__restrict vertices)
    {
        ::glVertexPointer(number_of_coordinate, data_type, 0, vertices);
    }
}

#endif // !_GL_VERTEX_POINTER_HPP_
