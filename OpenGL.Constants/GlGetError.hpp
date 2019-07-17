#pragma once
#ifndef _GL_ERROR_HPP_
#define _GL_ERROR_HPP_

// https://docs.microsoft.com/en-us/windows/win32/opengl/glgeterror

namespace OpenGL
{
    // The glGetError function returns error information.
    auto GetError = ::glGetError;

    // The glGetError function returns one of the following error codes.
    // Note that glGetError returns GL_INVALID_OPERATION if it is called between a call to glBegin and its corresponding call to glEnd.
    class ErrorCode
    {
    private:
        GLenum value;

    public:
        inline constexpr ErrorCode(const GLenum &value = NoError) noexcept : value{ value } { }
        inline constexpr operator const GLenum&() const noexcept { return value; }
        using Type = GLenum;

        enum : GLenum
        {
            // No error has been recorded. 
            // The value of this symbolic constant is guaranteed to be zero.
            NoError = GL_NO_ERROR,

            // An unacceptable value is specified for an enumerated argument. 
            // The offending function is ignored, having no side effect other than to set the error flag.
            InvalidEnum = GL_INVALID_ENUM,

            // A numeric argument is out of range. 
            // The offending function is ignored, having no side effect other than to set the error flag.
            InvalidValue = GL_INVALID_VALUE,

            // The specified operation is not allowed in the current state. 
            // The offending function is ignored, having no side effect other than to set the error flag.
            InvalidOperation = GL_INVALID_OPERATION,

            // This function would cause a stack overflow. 
            // The offending function is ignored, having no side effect other than to set the error flag.
            StackOverflow = GL_STACK_OVERFLOW,

            // This function would cause a stack underflow. 
            // The offending function is ignored, having no side effect other than to set the error flag.
            StackUnderflow = GL_STACK_UNDERFLOW,

            // There is not enough memory left to execute the function. 
            // The state of OpenGL is undefined, except for the state of the error flags, after this error is recorded.
            OutOfMemory = GL_OUT_OF_MEMORY,
        };
    };
}


#endif // !_GL_ERROR_HPP_
