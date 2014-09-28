#include "ControllerPackage.h"

ControllerPackage* ControllerPackage::activeControllerPackage = nullptr;


ControllerPackage::ControllerPackage(std::shared_ptr<Model::IGraphicsManager> graphicsManager, std::shared_ptr<InputManager> inputManager, std::shared_ptr<SoundManager> soundManager)
: graphicsManager(graphicsManager),
inputManager(inputManager),
soundManager(soundManager),
resourceManager(resourceManager)
{
	
}

ControllerPackage::~ControllerPackage()
{
	delete this->graphicsManager;
	delete this->inputManager;
	delete this->soundManager;
}

GraphicsManager* const ControllerPackage::GetGraphicsManager()
{
	return this->graphicsManager;
}


InputManager* const ControllerPackage::GetInputManager()
{
	return this->inputManager;
}

SoundManager* const ControllerPackage::GetSoundManager()
{
	return this->soundManager;
}

ResourceManager* const ControllerPackage::GetResourceManager()
{
    return this->resourceManager;
}

void ControllerPackage::Activate()
{
    ControllerPackage::activeControllerPackage = this;
}

ControllerPackage* ControllerPackage::GetActiveControllerPackage()
{
    return ControllerPackage::activeControllerPackage;
}
