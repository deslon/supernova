#include "LightData.h"
#include "Angle.h"


using namespace Supernova;

LightData::LightData(){
    ambientLight = NULL;
}

LightData::~LightData(){
    
}

bool LightData::updateLights(std::vector<Light*>* lights, Vector3* ambientLight){
    
    this->ambientLight = ambientLight;
    
    this->numPointLight = 0;
    this->pointLightPos.clear();
    this->pointLightColor.clear();
    this->pointLightPower.clear();
    this->numSpotLight = 0;
    this->spotLightPos.clear();
    this->spotLightColor.clear();
    this->spotLightTarget.clear();
    this->spotLightPower.clear();
    this->spotLightCutOff.clear();
    this->numDirectionalLight = 0;
    this->directionalLightDir.clear();
    this->directionalLightColor.clear();
    this->directionalLightPower.clear();
    for ( int i = 0; i < (int)lights->size(); i++){
        if (lights->at(i)->getType() == S_POINT_LIGHT){
            this->numPointLight++;
            
            this->pointLightPos.push_back(lights->at(i)->getWorldPosition().x);
            this->pointLightPos.push_back(lights->at(i)->getWorldPosition().y);
            this->pointLightPos.push_back(lights->at(i)->getWorldPosition().z);
            
            this->pointLightColor.push_back(lights->at(i)->getColor().x);
            this->pointLightColor.push_back(lights->at(i)->getColor().y);
            this->pointLightColor.push_back(lights->at(i)->getColor().z);
            
            this->pointLightPower.push_back(lights->at(i)->getPower());
        }
        if (lights->at(i)->getType() == S_SPOT_LIGHT){
            this->numSpotLight++;
            
            this->spotLightPos.push_back(lights->at(i)->getWorldPosition().x);
            this->spotLightPos.push_back(lights->at(i)->getWorldPosition().y);
            this->spotLightPos.push_back(lights->at(i)->getWorldPosition().z);
            
            this->spotLightColor.push_back(lights->at(i)->getColor().x);
            this->spotLightColor.push_back(lights->at(i)->getColor().y);
            this->spotLightColor.push_back(lights->at(i)->getColor().z);
            
            this->spotLightTarget.push_back(lights->at(i)->getWorldTarget().x);
            this->spotLightTarget.push_back(lights->at(i)->getWorldTarget().y);
            this->spotLightTarget.push_back(lights->at(i)->getWorldTarget().z);
            
            this->spotLightPower.push_back(lights->at(i)->getPower());
            
            this->spotLightCutOff.push_back(cos(Angle::defaultToRad(lights->at(i)->getSpotAngle() / 2.0)));
        }
        if (lights->at(i)->getType() == S_DIRECTIONAL_LIGHT){
            this->numDirectionalLight++;
            
            this->directionalLightDir.push_back(lights->at(i)->getDirection().x);
            this->directionalLightDir.push_back(lights->at(i)->getDirection().y);
            this->directionalLightDir.push_back(lights->at(i)->getDirection().z);
            
            this->directionalLightColor.push_back(lights->at(i)->getColor().x);
            this->directionalLightColor.push_back(lights->at(i)->getColor().y);
            this->directionalLightColor.push_back(lights->at(i)->getColor().z);
            
            this->directionalLightPower.push_back(lights->at(i)->getPower());
        }
    }
    
    if ((int)lights->size() > 0){
        return true;
    }
    return false;
}
