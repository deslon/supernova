//
// (c) 2019 Eduardo Doria.
//

#ifndef GLES2SHADERTERRAIN_H
#define GLES2SHADERTERRAIN_H

std::string terrainVertexDec =
        "#ifdef IS_TERRAIN\n"
        "  uniform sampler2D u_heightData;\n"

        "  uniform mat4 u_mMatrix;\n"

        "  uniform vec3 u_EyePos;\n"

        "  uniform float u_terrainSize;\n"
        "  uniform int u_terrainResolution;\n"

        "  uniform vec2 u_terrainNodePos;\n"
        "  uniform float u_terrainNodeSize;\n"
        "  uniform float u_terrainNodeRange;\n"
        "  uniform int u_terrainNodeResolution;\n"

        "  vec2 gridDim;\n"
        "  vec2 terrainTextureCoords;\n"

        "  vec2 morphVertex(vec2 gridPos, vec2 worldPos, float morph) {\n"
        "      vec2 fracPart = fract(gridPos * gridDim.xy * 0.5) * 2.0 / gridDim.xy;\n"
        "      return worldPos - fracPart * u_terrainNodeSize * morph;\n"
        "  }\n"

        "  float getHeight(vec2 p) {\n"
        "      return texture2DLod(u_heightData, p/u_terrainSize, 0.0).r * 100.0;\n"
        "  }\n"

        "#endif\n";

std::string terrainVertexImp =
        "    #ifdef IS_TERRAIN\n"
        "      localPos = u_terrainNodeSize * localPos;\n"
        "      localPos = localPos + vec3(u_terrainNodePos[0], 0.0, u_terrainNodePos[1]);\n"

        "      localPos = vec3(localPos.x, getHeight(localPos.xz + (u_terrainSize/2.0)), localPos.z);\n"

        "      gridDim = vec2(u_terrainNodeResolution, u_terrainNodeResolution);\n"
        "      float morphStart = 0.0;\n"
        "      float morphEnd = 0.25;\n"

        //"      float dist = distance(vec3(629.0, 0.0, -158.0), vec3(u_mMatrix * vec4(localPos, 1.0)));\n"
        "      float dist = distance(u_EyePos, vec3(u_mMatrix * vec4(localPos, 1.0)));\n"

        "      float nextlevel_thresh = ((u_terrainNodeRange-dist)/u_terrainNodeSize*gridDim.x/float(u_terrainResolution));\n"
        "      float rangeDist = 1.0 - smoothstep(morphStart, morphEnd, nextlevel_thresh);\n"

        "      localPos.xz = morphVertex(a_Position.xz, localPos.xz, rangeDist);\n"

        "      localPos = vec3(localPos.x, getHeight(localPos.xz + (u_terrainSize/2.0)), localPos.z);\n"

        "      terrainTextureCoords = (localPos.xz + (u_terrainSize/2.0)) / u_terrainSize;\n"
        "    #endif\n";

#endif //GLES2SHADERTERRAIN_H
