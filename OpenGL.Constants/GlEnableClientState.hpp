#pragma once
#ifndef _GL_ENABLE_CLIENT_STATE_HPP_
#define _GL_ENABLE_CLIENT_STATE_HPP_

// https://docs.microsoft.com/en-us/windows/win32/opengl/glenableclientstate
// https://docs.microsoft.com/en-us/windows/win32/opengl/gldisableclientstate

namespace OpenGL
{
    // The glEnableClientState and glDisableClientState functions enable and disable arrays respectively.
    // The glEnableClientState and glDisableClientState functions enable and disable various individual arrays. 
    // Use glIsEnabled or glGet to determine the current setting of any capability.
    // Calling glEnableClientState and glDisableClientState between calls to glBegin and the corresponding call to glEnd can cause an error.
    // If no error is generated, the behavior is undefined.
    inline void __stdcall EnableClientState(const GLenum array)
    {
        ::glEnableClientState(array);
    }

    // The glEnableClientState and glDisableClientState functions enable and disable arrays respectively.
    // The glEnableClientState and glDisableClientState functions enable and disable various individual arrays. 
    // Use glIsEnabled or glGet to determine the current setting of any capability.
    // Calling glEnableClientState and glDisableClientState between calls to glBegin and the corresponding call to glEnd can cause an error.
    // If no error is generated, the behavior is undefined.
    inline void __stdcall DisableClientState(const GLenum array)
    {
        ::glDisableClientState(array);
    }

    // A symbolic constant for the array you want to enable or disable. 
    // This parameter can assume one of the following values.
    class ClientState
    {
    private:
        GLenum value;

    public:
        inline constexpr ClientState(const GLenum &value = 0) noexcept : value{ value } { }
        inline constexpr operator const GLenum&() const noexcept { return value; }
        using Type = GLenum;

        enum : GLenum
        {
            // If enabled, use color arrays with calls to glArrayElement, glDrawElements, or glDrawArrays.
            // See also glColorPointer.
            ColorArray = GL_COLOR_ARRAY,

            // If enabled, use edge flag arrays with calls to glArrayElement, glDrawElements, or glDrawArrays.
            // See also glEdgeFlagPointer.
            EdgeFlagArray = GL_EDGE_FLAG_ARRAY,

            // If enabled, use index arrays with calls to glArrayElement, glDrawElements, or glDrawArrays.
            // See also glIndexPointer.
            IndexArray = GL_INDEX_ARRAY,

            // If enabled, use normal arrays with calls to glArrayElement, glDrawElements, or glDrawArrays.
            // See also glNormalPointer.
            NormalArray = GL_NORMAL_ARRAY,

            // If enabled, use texture coordinate arrays with calls to glArrayElement, glDrawElements, or glDrawArrays.
            // See also glTexCoordPointer.
            TextureCoordArray = GL_TEXTURE_COORD_ARRAY,

            // If enabled, use vertex arrays with calls to glArrayElement, glDrawElements, or glDrawArrays.
            // See also glVertexPointer.
            VertexArray = GL_VERTEX_ARRAY,
        };
    };
}

#endif // !_GL_ENABLE_CLIENT_STATE_HPP_
