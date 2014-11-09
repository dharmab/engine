#include <stdexcept>
#include <thread>
#include <chrono>
#include <set>
#include <mutex>
#include "IGraphicsManager.h"
#include "IGraphicsManagerView.h"
#include "ManagerCast.h"
#include "Color.h"
#include "Sprite.h"

class GraphicsManager : public Model::IGraphicsManager, public View::IGraphicsManager
{
public:
    GraphicsManager();

    ~GraphicsManager();

    Color GetClearColor();

    void SetClearColor(Color clearColor);

    void SetClearColor(float red, float blue, float green, float alpha);

    void RegisterSprite(std::shared_ptr<Sprite> sprite);

    void UnregisterSprite(std::shared_ptr<Sprite> sprite);

    int GetSpriteCount();

    std::shared_ptr<Camera> GetCamera();

    void PrepareToAddSprites();

    bool AddSpriteToVCIBuffer(float* vertexBuffer, float* colorBuffer, unsigned short* indexBuffer, unsigned short dataStartIndex);

private:
    // Private constructors to disallow access.
    GraphicsManager(GraphicsManager const &other);
    GraphicsManager operator=(GraphicsManager other);

    Color clearColor;
    std::shared_ptr<Camera> camera;
    std::set<std::shared_ptr<Sprite>> registeredSprites;
    std::mutex registeredSpritesMutex;
    std::set<std::shared_ptr<Sprite>>::iterator spriteIterator;
};

GraphicsManager::GraphicsManager() : clearColor(0.0f, 0.0f, 0.0f, 1.0f)
{
    this->camera = std::make_shared<Camera>();
}

GraphicsManager::~GraphicsManager()
{

}

Color GraphicsManager::GetClearColor()
{
    return this->clearColor;
}

void GraphicsManager::SetClearColor(Color clearColor)
{
    this->clearColor = clearColor;
}

void GraphicsManager::SetClearColor(float red, float green, float blue, float alpha)
{
    this->clearColor = Color(red, green, blue, alpha);
}

void GraphicsManager::RegisterSprite(std::shared_ptr<Sprite> sprite)
{
    this->registeredSpritesMutex.lock();
    int registeredCountBeforeAdd = (int)this->registeredSprites.size();
    this->registeredSprites.insert(sprite);
    if ((registeredCountBeforeAdd + 1) != (int)this->registeredSprites.size())
    {
        throw new std::invalid_argument("A sprite was registered that was already registered.");
    }
    this->registeredSpritesMutex.unlock();
}

void GraphicsManager::UnregisterSprite(std::shared_ptr<Sprite> sprite)
{
    this->registeredSpritesMutex.lock();
    int registeredCountBeforeAdd = (int)this->registeredSprites.size();
    this->registeredSprites.erase(sprite);
    if ((registeredCountBeforeAdd - 1) != (int)this->registeredSprites.size())
    {
        throw new std::invalid_argument("A sprite was unregistered that wasn't registered.");
    }
    this->registeredSpritesMutex.unlock();
}

int GraphicsManager::GetSpriteCount()
{
    return (int)this->registeredSprites.size();
}

std::shared_ptr<Camera> GraphicsManager::GetCamera()
{
    return this->camera;
}

void GraphicsManager::PrepareToAddSprites()
{
    this->registeredSpritesMutex.lock();
    this->spriteIterator = this->registeredSprites.begin();
}

bool GraphicsManager::AddSpriteToVCIBuffer(float* vertexBuffer, float* colorBuffer, unsigned short* indexBuffer, unsigned short dataStartIndex)
{
    if (this->spriteIterator == this->registeredSprites.end())
    {
        this->registeredSpritesMutex.unlock();
        return false;
    }
    std::shared_ptr<Sprite> sprite = *(this->spriteIterator);
    sprite->PutGLVertexInfo(vertexBuffer); // 16 = 4 vertices * 4 coordinates
    sprite->PutGLColorInfo(colorBuffer); // 16 = 4 vertices * 4 channels
    sprite->PutGLIndexInfo(indexBuffer, dataStartIndex); // 6 = 2 triangles * 3 coordinates
    this->spriteIterator++;
    return true;
}

// Hidden class pattern methods

std::shared_ptr<Model::IGraphicsManager> Model::CreateIGraphicsManager()
{
    return std::dynamic_pointer_cast<Model::IGraphicsManager, GraphicsManager>(std::make_shared<GraphicsManager>());
}

std::shared_ptr<View::IGraphicsManager> View::CreateIGraphicsManager()
{
    return std::dynamic_pointer_cast<View::IGraphicsManager, GraphicsManager>(std::make_shared<GraphicsManager>());
}

std::shared_ptr<View::IGraphicsManager> ManagerCast::CastGraphicsManagerToGraphicsManagerView(std::shared_ptr<Model::IGraphicsManager> manager)
{
    return std::dynamic_pointer_cast<View::IGraphicsManager, Model::IGraphicsManager>(manager);
}

