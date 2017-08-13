
#include "Image.h"
#include "PrimitiveMode.h"
#include <string>
#include "image/TextureLoader.h"
#include "platform/Log.h"

using namespace Supernova;

Image::Image(): Mesh2D() {
    primitiveMode = S_TRIANGLES;
    texWidth = 0;
    texHeight = 0;
    useTextureRect = false;
}

Image::Image(int width, int height): Image() {
    setSize(width, height);
}

Image::Image(std::string image_path): Image() {
    setTexture(image_path);
}

Image::~Image() {
}

void Image::setTectureRect(float x, float y, float width, float height){
    setTectureRect(Rect(x, y, width, height));
}

void Image::setTectureRect(Rect textureRect){
    this->textureRect = textureRect;
    
    if (loaded && !useTextureRect){
        useTextureRect = true;
        reload();
    }else{
        useTextureRect = true;
        normalizeTextureRect();
    }
}

void Image::normalizeTextureRect(){
    
    if (useTextureRect){
        if (textureRect.isNormalized()){
            
            submeshes[0]->getMaterial()->setTextureRect(textureRect.getX(),
                                                        textureRect.getY(),
                                                        textureRect.getWidth(),
                                                        textureRect.getHeight());
            
        }else {
            
            if (this->texWidth != 0 && this->texHeight != 0) {
                submeshes[0]->getMaterial()->setTextureRect(textureRect.getX() / (float) texWidth,
                                                            textureRect.getY() / (float) texHeight,
                                                            textureRect.getWidth() / (float) texWidth,
                                                            textureRect.getHeight() / (float) texHeight);
            }
        }
    }
}

void Image::setSize(int width, int height){
    Mesh2D::setSize(width, height);
    if (loaded) {
        createVertices();
        updateVertices();
    }
}

void Image::setInvertTexture(bool invertTexture){
    Mesh2D::setInvertTexture(invertTexture);
    if (loaded) {
        createVertices();
        updateVertices();
    }
}

void Image::createVertices(){
    vertices.clear();
    vertices.push_back(Vector3(0, 0, 0));
    vertices.push_back(Vector3(width, 0, 0));
    vertices.push_back(Vector3(width,  height, 0));
    vertices.push_back(Vector3(0,  height, 0));

    texcoords.clear();
    texcoords.push_back(Vector2(0.0f, 0.0f));
    texcoords.push_back(Vector2(1.0f, 0.0f));
    texcoords.push_back(Vector2(1.0f, 1.0f));
    texcoords.push_back(Vector2(0.0f, 1.0f));

    if (invertTexture){
        for (int i = 0; i < texcoords.size(); i++){
            texcoords[i].y = 1 - texcoords[i].y;
        }
    }

    static const unsigned int indices_array[] = {
        0,  1,  2,
        0,  2,  3
    };

    std::vector<unsigned int> indices;
    indices.assign(indices_array, std::end(indices_array));
    submeshes[0]->setIndices(indices);

    normals.clear();
    normals.push_back(Vector3(0.0f, 0.0f, 1.0f));
    normals.push_back(Vector3(0.0f, 0.0f, 1.0f));
    normals.push_back(Vector3(0.0f, 0.0f, 1.0f));
    normals.push_back(Vector3(0.0f, 0.0f, 1.0f));
}

bool Image::load(){
    
    if (submeshes[0]->getMaterial()->getTexture()) {
        submeshes[0]->getMaterial()->getTexture()->load();
        texWidth = submeshes[0]->getMaterial()->getTexture()->getWidth();
        texHeight = submeshes[0]->getMaterial()->getTexture()->getHeight();
        
        normalizeTextureRect();
        
        if (this->width == 0 && this->height == 0) {
            if (submeshes[0]->getMaterial()->getTextureRect()){
                this->width = texWidth * submeshes[0]->getMaterial()->getTextureRect()->getWidth();
                this->height = texHeight * submeshes[0]->getMaterial()->getTextureRect()->getHeight();
            }else{
                this->width = texWidth;
                this->height = texHeight;
            }
        }
    }
    
    setInvertTexture(isIn3DScene());
    createVertices();
    
    return Mesh2D::load();
}