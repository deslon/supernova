
#ifndef POINTS_H
#define POINTS_H

#define S_POINTSIZE_PIXEL 0
#define S_POINTSIZE_WIDTH 1
#define S_POINTSIZE_HEIGHT 2

#include "ConcreteObject.h"
#include "render/ObjectRender.h"
#include <unordered_map>

namespace Supernova {

    class Points: public ConcreteObject {

    private:
        void updateNormalizedRectsData();
        void updatePointScale();
        void fillScaledSizeVector();
        void normalizeTextureRects();
        
        std::vector<float> pointSizesScaled;
        std::vector<float> rectsData;
        
        int texWidth;
        int texHeight;

        float pointScale;

        int pointSizeReference;
        
        bool useTextureRects;

    protected:
        ObjectRender* render;

        std::vector<Vector3> positions;
        std::vector<Vector3> normals;
        std::vector<Rect*> textureRects;
        std::vector<float> pointSizes;
        std::vector<Vector4> colors;

        bool sizeAttenuation;
        float pointScaleFactor;
        float minPointSize;
        float maxPointSize;
        
        std::unordered_map <std::string, Rect> framesRect;
        
        void updatePositions();
        void updateNormals();
        void updatePointColors();
        void updatePointSizes();
        void updateTextureRects();

    public:
        Points();
        virtual ~Points();

        void setSizeAttenuation(bool sizeAttenuation);
        void setPointScaleFactor(float pointScaleFactor);
        void setPointSizeReference(int pointSizeReference);
        void setMinPointSize(float minPointSize);
        void setMaxPointSize(float maxPointSize);

        void addPoint();
        void addPoint(Vector3 position);

        void setPointPosition(int point, Vector3 position);
        void setPointPosition(int point, float x, float y, float z);
        void setPointSize(int point, float size);
        void setPointColor(int point, Vector4 color);
        void setPointColor(int point, float red, float green, float blue, float alpha);
        void setPointSprite(int point, std::string id);
        void setPointSprite(int point, int id);
        
        void addSpriteFrame(std::string id, float x, float y, float width, float height);
        void removeSpriteFrame(std::string id);
        
        std::vector<Vector3>* getPositions();
        std::vector<Vector3>* getNormals();
        std::vector<Rect*>* getTextureRects();
        std::vector<float>* getPointSizes();
        std::vector<Vector4>* getColors();
        
        virtual void updateVPMatrix(Matrix4* viewMatrix, Matrix4* projectionMatrix, Matrix4* viewProjectionMatrix, Vector3* cameraPosition);
        virtual void updateMatrix();
        
        virtual bool renderDraw();
        
        virtual bool load();
        virtual void destroy();
    };
    
}


#endif