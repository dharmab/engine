#include "GameStateManager.h"
#include "IGraphicsManager.h"

GameStateManager::GameStateManager()
{
    std::shared_ptr<ControllerPackage> tempControllerPackage = std::make_shared<ControllerPackage>(Model::CreateIGraphicsManager(), std::make_shared<InputManager>(), SoundManager::GetInstance());
    tempControllerPackage->Activate();
}

void GameStateManager::Initialize(GameState* state)
{
    this->PushState(state);
}

void GameStateManager::Update()
{
    gameStates.top()->Update();
}

void GameStateManager::PushState(GameState* state)
{
    if(!gameStates.empty())
    {
        gameStates.top()->Pause();
    }
    gameStates.push(state);
    gameStates.top()->Initialize(this);
}

GameState* GameStateManager::PopState()
{
    GameState* top = gameStates.top();
    top->Pause();
    top->Destroy();
    gameStates.pop();
    if (gameStates.size() != 0)
    {
        gameStates.top()->Resume();
    }
    return top;
}

void GameStateManager::SwapState(GameState* state)
{
    this->PopState();
    this->PushState(state);
}
