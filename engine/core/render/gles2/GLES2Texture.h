#ifndef gles2texture_h
#define gles2texture_h

#include "GLES2Header.h"
#include "render/TextureRender.h"

class GLES2Texture : public TextureRender{

private:
    GLuint gTexture;
    
    GLenum getGlColorFormat(const int color_format);
    GLuint getTextureObjectId(const GLsizei width, const GLsizei height, const GLenum type, const GLvoid* pixels);

public:
    
    GLES2Texture();

    void loadTexture(int width, int height, int type, void* data);
    void deleteTexture();
    
    void setTexture(GLuint texture);
    GLuint getTexture();


};

#endif /* gles2_texture_h */
