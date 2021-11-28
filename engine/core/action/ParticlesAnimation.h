//
// (c) 2021 Eduardo Doria.
//

#ifndef PARTICLESANIMATION_H
#define PARTICLESANIMATION_H

#include "Action.h"

namespace Supernova{
    class ParticlesAnimation: public Action{

    public:
        ParticlesAnimation(Scene* scene);

        void setLifeInitializer(float life);
        void setLifeInitializer(float minLife, float maxLife);

        void setPositionInitializer(Vector3 position);
        void setPositionInitializer(Vector3 minPosition, Vector3 maxPosition);
        void setPositionModifier(float fromTime, float toTime, Vector3 fromPosition, Vector3 toPosition);
        void setPositionModifier(float fromTime, float toTime, Vector3 fromPosition, Vector3 toPosition, int functionType);

        void setVelocityInitializer(Vector3 velocity);
        void setVelocityInitializer(Vector3 minVelocity, Vector3 maxVelocity);
        void setVelocityModifier(float fromTime, float toTime, Vector3 fromVelocity, Vector3 toVelocity);
        void setVelocityModifier(float fromTime, float toTime, Vector3 fromVelocity, Vector3 toVelocity, int functionType);

        void setAccelerationInitializer(Vector3 acceleration);
        void setAccelerationInitializer(Vector3 minAcceleration, Vector3 maxAcceleration);
        void setAccelerationModifier(float fromTime, float toTime, Vector3 fromAcceleration, Vector3 toAcceleration);
        void setAccelerationModifier(float fromTime, float toTime, Vector3 fromAcceleration, Vector3 toAcceleration, int functionType);

        void setColorInitializer(Vector3 color);
        void setColorInitializer(Vector3 minColor, Vector3 maxColor);
        void setColorModifier(float fromTime, float toTime, Vector3 fromColor, Vector3 toColor);
        void setColorModifier(float fromTime, float toTime, Vector3 fromColor, Vector3 toColor, int functionType);

        void setAlphaInitializer(float alpha);
        void setAlphaInitializer(float minAlpha, float maxAlpha);
        void setAlphaModifier(float fromTime, float toTime, float fromAlpha, float toAlpha);
        void setAlphaModifier(float fromTime, float toTime, float fromAlpha, float toAlpha, int functionType);

        void setSizeInitializer(float size);
        void setSizeInitializer(float minSize, float maxSize);
        void setSizeModifier(float fromTime, float toTime, float fromSize, float toSize);
        void setSizeModifier(float fromTime, float toTime, float fromSize, float toSize, int functionType);

        void setSpriteIntializer(std::vector<int> frames);
        void setSpriteIntializer(int minFrame, int maxFrame);
        void setSpriteModifier(float fromTime, float toTime, std::vector<int> frames);
        void setSpriteModifier(float fromTime, float toTime, std::vector<int> frames, int functionType);

        void setRotationInitializer(float rotation);
        void setRotationInitializer(float minRotation, float maxRotation);
        void setRotationModifier(float fromTime, float toTime, float fromRotation, float toRotation);
        void setRotationModifier(float fromTime, float toTime, float fromRotation, float toRotation, int functionType);
    };
}

#endif //PARTICLESANIMATION_H