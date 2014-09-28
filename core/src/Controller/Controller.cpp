#include "Controller.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "IGraphicsManagerView.h"
#include "IGraphicsManager.h"
#include "ManagerConverters.h"

Controller::Controller()
{
    this->shouldExit = false;
}

void Controller::Start()
{
    // Start the main game loop on a different thread.
    std::thread gameThread(&Controller::gameLoop, this);
    this->viewLoop();
    gameThread.join();
}

void Controller::gameLoop()
{
    GameStateManager manager;
    manager.Initialize(new InitialState());

    int i = 0;
    while(!this->shouldExit)
    {
        i++;
        double startTime = glfwGetTime();

        manager.Update();
        
        while((glfwGetTime() - startTime) <= Controller::UPDATE_RATE)
        { }
    }
}

void Controller::viewLoop()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(window);

    GraphicsView graphicsView(window);
    graphicsView.Initialize();
    graphicsView.OnWindowClose = [this] () { this->shouldExit = true; };
    InputView inputView(window);
    inputView.Initialize();
    SoundView soundView;
    soundView.Initialize();
    ResourceView resourceView;
    resourceView.Initialize();

    while(!this->shouldExit)
    {
        double startTime = glfwGetTime();

        glfwPollEvents();

        graphicsView.Update(ControllerPackage::GetActiveControllerPackage()->GetGraphicsManager());
        inputView.Update(ControllerPackage::GetActiveControllerPackage()->GetInputManager());
        soundView.Update(ControllerPackage::GetActiveControllerPackage()->GetSoundManager());
        resourceView.Update(ControllerPackage::GetActiveControllerPackage()->GetResourceManager());

        while((glfwGetTime() - startTime) <= Controller::FRAMERATE)
        { }
    }

void Controller::updateViews(GraphicsView* graphicsView, InputView* inputView, std::shared_ptr<SoundView>* soundView)
{
    std::weak_ptr<ControllerPackage> weakControllerPackage = ControllerPackage::GetActiveControllerPackage();
    std::shared_ptr<ControllerPackage> controllerPackage = weakControllerPackage.lock();
    
    if (weakControllerPackage.expired()) 
    {
        return;
    }

    graphicsView->Update(Rawr::ConvertGraphicsManagerForView(controllerPackage->GetGraphicsManager()));
    inputView->Update(controllerPackage->GetInputManager());
    (*soundView)->Update(controllerPackage->GetSoundManager());
}

void Controller::handleEvents(std::shared_ptr<sf::RenderWindow> window, InputView* inputView) {
    sf::Event event;
    while (window->pollEvent(event))
    {
        // Close program on Closed event
        if (event.type == sf::Event::Closed)
        {
            this->shouldExit = true;
            window->close();
        }

        // TODO: handle LostFocus, GainedFocus and Resized events

        // InputView handles other window events
        inputView->OnSfmlEvent(event);
    }
}

