//
// (c) 2023 Eduardo Doria.
//

#ifndef BODY3D_H
#define BODY3D_H

#include "EntityHandle.h"
#include "math/Vector2.h"
#include "component/Body3DComponent.h"

namespace JPH{
    class Body;
}

namespace Supernova{

    class Object;

    class Body3D: public EntityHandle{
    public:
        Body3D(Scene* scene, Entity entity);
        virtual ~Body3D();

        Body3D(const Body3D& rhs);
        Body3D& operator=(const Body3D& rhs);

        JPH::Body* getJoltBody() const;

        Object getAttachedObject();

        void createBoxShape(BodyType type, float width, float height, float depth);
        void createSphereShape(BodyType type, float radius);

        void setType(BodyType type);
        BodyType getType() const;

        uint32_t getID() const;

        bool canBeKinematicOrDynamic() const;

        bool isSensor() const;
        void setIsSensor(bool sensor);

        unsigned int getCollisionGroupID() const;
        void setCollisionGroupID(unsigned int group);

        bool isAllowSleeping() const;
        void setAllowSleeping(bool allowSleeping);

        float getFriction() const;
        void setFriction(float friction);

        float getRestitution() const;
        void setRestitution(float restitution);

        Vector3 getLinearVelocity() const;
        void setLinearVelocity(Vector3 linearVelocity);
        void setLinearVelocityClamped(Vector3 linearVelocity);

        Vector3 getAngularVelocity() const;
        void setAngularVelocity(Vector3 angularVelocity);
        void setAngularVelocityClamped(Vector3 angularVelocity);

        // center of mass
        Vector3 getPointVelocityCOM(Vector3 pointRelativeToCOM);
        Vector3 getPointVelocity(Vector3 point);

        void applyForce(const Vector3& force);
        void applyForce(const Vector3& force, const Vector3& point);
        void applyTorque(const Vector3& torque);

    };
}

#endif //BODY3D_H