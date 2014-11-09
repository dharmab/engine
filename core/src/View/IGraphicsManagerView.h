#ifndef Core_IGraphicsManagerView_h
#define Core_IGraphicsManagerView_h

#include <memory>
#include "Color.h"
#include "Camera.h"

namespace View
{
    class IGraphicsManager
    {
    public:
        virtual Color GetClearColor() = 0;

        virtual int GetSpriteCount() = 0;

        virtual std::shared_ptr<Camera> GetCamera() = 0;

        /**
         * Prepares to add all sprites with the AddSpriteToVCIBuffer method
         */
        virtual void PrepareToAddSprites() = 0;

        /**
         * Adds the next sprite's vertex, color, and index information to the
         * given vertex buffer.
         * DO NOT CALL THIS METHOD IF THERE IS NOT SPACE FOR 16 values for
         * each sprite (16 * GetSpriteCount()).
         *
         * @return true if the sprite's data was successfully added; false if
         * there are no more sprites to be added or PrepareToAddSprites hasn't
         * been called.
         *
         */
        virtual bool AddSpriteToVCIBuffer(float* vertexBuffer, float* colorbuffer, unsigned short* indexBuffer, unsigned short dataStartIndex) = 0;

        virtual ~IGraphicsManager() {};
    };

    std::shared_ptr<View::IGraphicsManager> CreateIGraphicsManager();
}

#endif