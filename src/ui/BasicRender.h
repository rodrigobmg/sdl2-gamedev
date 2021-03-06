#ifndef UI_BASICRENDER_H
#define UI_BASICRENDER_H

#include <math/Rect.h>
#include <ui/GlState.h>
#include <ui/SDL_opengl.h>
#include <util/SDL_Event_fwd.h>



/**
 * BasicRender class.
 *
 * @author SwarmingLogic (Roald Fernandez)
 */
class BasicRender
{
public:
  BasicRender(){}
  virtual ~BasicRender(){}

  virtual void initialize() {};
  virtual void render(float currentTime) const = 0;
  virtual void refresh() = 0;
  virtual void finalize() {};

  virtual bool handleEvent(const SDL_Event&) { return false; }
  virtual void handleResize(int width, int height) {
    GlState::viewport(Rect(0, 0, width, height));
  }

  virtual bool prefersMouseGrab() const { return false; }


private:
  // NonCopyable
  BasicRender(const BasicRender& c);
  BasicRender& operator=(const BasicRender& c);
};

#endif
