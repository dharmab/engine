#ifndef Core_ManagerCasts_h
#define Core_ManagerCasts_h

#include <memory>
#include "IInputManagerView.h"
#include "IInputManager.h"
#include "IGraphicsManagerView.h"
#include "IGraphicsManager.h"

namespace ManagerCast
{
    std::shared_ptr<View::IInputManager> CastInputManagerToInputManagerView(std::shared_ptr<Model::IInputManager> manager);

    std::shared_ptr<View::IGraphicsManager> CastGraphicsManagerToGraphicsManagerView(std::shared_ptr<Model::IGraphicsManager> manager);
}

#endif
