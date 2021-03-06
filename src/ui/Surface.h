#ifndef UI_SURFACE_H
#define UI_SURFACE_H

#include <memory>

#include <math/Rect.h>
#include <ui/SDL.h>
#include <ui/SDL_opengl.h>
#include <util/Asset.h>
#include <util/Log.h>


/**
 * Surface class, represents a SDL_Surface, and provides
 * helper functions to interact with OpenGL
 *
 * @author SwarmingLogic (Roald Fernandez)
 */
class Surface
{
public:
  Surface();
  Surface(const AssetImage& imagefile);

  /**
   * Create based on SDL_Surface.
   * @note Takes ownership!
   */
  Surface(SDL_Surface* surface);

  virtual ~Surface();

  /**
   * @param filename Just the filename, it prepends image directory.
   */
  void loadImage(const AssetImage& imagefile);

  /**
   * Fill using a SDL_Surface.
   * @note Takes ownership!
   */
  void setSurface(SDL_Surface& surface);
  SDL_Surface* getSurface();

  void setGlTextureId(GLuint textureId, Size size);

  GLuint glBind() const;
  void prepareForGl();

  GLuint getTextureId() const;

  unsigned int getWidth() const;
  unsigned int getHeight() const;
  Size getSize() const;

  /**
   * Only use if image dimensions are not a power of two.
   *
   * If a clip is set, it assumes texcoord are passed to withing this clip.
   * I.e 0.0 correspond to the clip start. 1.0 to the clip end.
   *
   * The surface will extend to powers of two regardless, and then the texture
   * coordinates need to be adjusted. This function calculates that new
   * coordinate.
   */
  float glTexCoordX(float texcoord) const;
  float glTexCoordY(float texcoord) const;


  /**
   * If set true, it enables linear mipmapping and anisotropic filtering.
   * If set false, sets nearest filter, with clamp to edge wrapping.
   */
  void setIsMaxFiltering(bool isMaxFiltering);
  bool isMaxFiltering() const;


  /**
   * Sets texture repeat factor hint. Defaults to 1.0f
   */
  float getRepeatFactorHint() const;
  void setRepeatFactorHint(float repeatFactor);

private:
  void releaseResources();

  Log log_;
  SdlSurfacePtr surface_;
  GLuint textureId_;
  Rect imageRect_;
  bool isMaxFiltering_;
  float repeatFactor_;

  // NonCopyable
  Surface(const Surface& c);
  Surface& operator=(const Surface& c);
};


typedef std::shared_ptr<Surface> SurfaceShPtr;

#endif
