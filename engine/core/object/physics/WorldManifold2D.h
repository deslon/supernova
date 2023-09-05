//
// (c) 2023 Eduardo Doria.
//

#ifndef WORLDMANIFOLD2D_H
#define WORLDMANIFOLD2D_H

#include "Scene.h"

class b2WorldManifold;

namespace Supernova{

    class WorldManifold2D{
        private:
            Scene* scene;
            b2WorldManifold* worldmanifold;

        public:
            WorldManifold2D(Scene* scene, b2WorldManifold* worldmanifold);
            virtual ~WorldManifold2D();

            WorldManifold2D(const WorldManifold2D& rhs);
            WorldManifold2D& operator=(const WorldManifold2D& rhs);

            b2WorldManifold* getBox2DWorldManifold();

            Vector2 getNormal() const;
            Vector2 getPoint() const;
            float getSeparations() const;
    };
}

#endif //WORLDMANIFOLD2D_H