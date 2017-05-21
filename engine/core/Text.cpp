#include "Text.h"

#include "PrimitiveMode.h"
#include <string>
#include "image/TextureLoader.h"
#include "render/TextureManager.h"
#include "platform/Log.h"
#include "image/ColorType.h"
#include "FileData.h"
#include "stb_truetype.h"
#include <codecvt>

Text::Text(): Mesh2D() {
    primitiveMode = S_TRIANGLES;
    dynamic = true;
}

Text::Text(std::string font): Mesh2D() {
    primitiveMode = S_TRIANGLES;
    setFont(font);
}

Text::~Text() {
}

void Text::setFont(std::string font){
    this->font = font;
    setTexture(font);
}


bool Text::load(){

    unsigned int size = 60;
    unsigned int atlasWidth = 512;
    unsigned int atlasHeight = 512;

    const unsigned int atlasLimit = 32768;
    const unsigned int oversampleX = 2;
    const unsigned int oversampleY = 2;
    const unsigned int firstChar = 32;
    const unsigned int lastChar = 255;
    const unsigned int charCount = lastChar - firstChar;

    //if (!loaded && this->width == 0 && this->height == 0){
        //TextureManager::loadTexture(submeshes[0]->getTextures()[0]);
        //this->width = atlasWidth;
        //this->height = atlasHeight;
    //}

    FileData* fontData = new FileData();
    fontData->open(font.c_str());

    bool fitBitmap = false;

    unsigned char *atlasData = NULL;
    stbtt_packedchar *charInfo = new stbtt_packedchar[charCount];

    stbtt_pack_context context;
    while (!fitBitmap && atlasWidth <= atlasLimit) {
        if (atlasData) delete[] atlasData;
        atlasData = new unsigned char[atlasWidth * atlasHeight];

        if (!stbtt_PackBegin(&context, atlasData, atlasWidth, atlasHeight, 0, 1, nullptr))
            Log::Error(LOG_TAG, "Failed to initialize font");

        stbtt_PackSetOversampling(&context, oversampleX, oversampleY);
        if (!stbtt_PackFontRange(&context, fontData->getMemPtr(), 0, size, firstChar, charCount, charInfo)){
            atlasWidth = atlasWidth * 2;
            atlasHeight = atlasHeight * 2;
        }else{
            fitBitmap = true;
        }
    }
    if (atlasWidth > atlasLimit){
        Log::Error(LOG_TAG, "Failed to pack font");
    }
    stbtt_PackEnd(&context);

    unsigned int textureSize = atlasWidth * atlasHeight * sizeof(unsigned char);
    TextureFile* textureFile  = new TextureFile(atlasWidth, atlasHeight, textureSize, S_COLOR_ALPHA, 8, (void*)atlasData);
    textureFile->flipVertical();
    TextureManager::loadTexture(textureFile, font);

    delete[] atlasData;

    delete fontData;

    std::string text = "Eduardo Dória Lima";

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
    std::wstring utf16String = convert.from_bytes( text );

    float offsetX = 0;
    float offsetY = 0;

    vertices.clear();
    texcoords.clear();
    std::vector<unsigned int> indices;
    int ind = 0;

    for(auto c : utf16String) {
        int intchar = uint_least32_t(c);
        if (intchar >= firstChar && intchar <= lastChar) {
            stbtt_aligned_quad quad;
            stbtt_GetPackedQuad(charInfo, atlasWidth, atlasHeight, intchar - firstChar, &offsetX, &offsetY, &quad, 1);
            float auxt0 = quad.t0;
            quad.t0 = 1 - quad.t1;
            quad.t1 = 1 - auxt0;

            float auxy0 = quad.y0;
            quad.y0 = -quad.y1;
            quad.y1 = -auxy0;

            vertices.push_back(Vector3(quad.x0, quad.y0, 0));
            vertices.push_back(Vector3(quad.x1, quad.y0, 0));
            vertices.push_back(Vector3(quad.x1, quad.y1, 0));
            vertices.push_back(Vector3(quad.x0, quad.y1, 0));

            texcoords.push_back(Vector2(quad.s0, quad.t0));
            texcoords.push_back(Vector2(quad.s1, quad.t0));
            texcoords.push_back(Vector2(quad.s1, quad.t1));
            texcoords.push_back(Vector2(quad.s0, quad.t1));

            normals.push_back(Vector3(0.0f, 0.0f, 1.0f));
            normals.push_back(Vector3(0.0f, 0.0f, 1.0f));
            normals.push_back(Vector3(0.0f, 0.0f, 1.0f));
            normals.push_back(Vector3(0.0f, 0.0f, 1.0f));

            indices.push_back(ind);
            indices.push_back(ind+1);
            indices.push_back(ind+2);
            indices.push_back(ind);
            indices.push_back(ind+2);
            indices.push_back(ind+3);
            ind = ind + 4;
        }
    }
    
    submeshes[0]->setIndices(indices);
    

    return Mesh2D::load();
}
