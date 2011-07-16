#ifndef COSMOS_PARTICLEEMITTER_H_
#define COSMOS_PARTICLEEMITTER_H_

#include <boost/shared_ptr.hpp>
#include <iostream>
#include <math.h>
//#include <vector>
//#include <string>

//#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "Camera.hpp"
#include "Matrix4f.hpp"
#include "Particle.hpp"
#include "Quaternion.hpp"
#include "Renderable.hpp"
#include "util.hpp"
#include "Vector3f.hpp"

/*
 * An emitter of fancy hats
 */
class ParticleEmitter {
 public:
	typedef boost::shared_ptr<ParticleEmitter> ShPtr;

	ParticleEmitter(Renderable::ShPtr renderable, Vector3f position, Vector3f normal, Vector3f up, float speed, float lifetime, float radius, float generation_rate/*, int count*/)
   : renderable_(renderable), pos_(position), norm_(normal), up_(up), speed_(speed), lifetime_(lifetime), radius_(radius),
     part_count_((generation_rate*lifetime)+1), generation_rate_(1/generation_rate), generation_remainder_(1/generation_rate), next_part_(0) {
    init();
  }

  void update(float delta);
  void render(Transform::ShPtr cam);
  void rotate(const Vector3f& axis, float angle);

 private:
  Renderable::ShPtr renderable_; // Should not use these - designed for objects
  float speed_;
  Vector3f pos_;
  Vector3f norm_;
  Vector3f up_;
  std::vector<Particle::ShPtr> parts_;
  int part_count_;
  float radius_;
  float generation_rate_;
  float generation_remainder_;
  int next_part_;
  float lifetime_;
  
  void init();
  
  DISALLOW_COPY_AND_ASSIGN(ParticleEmitter);
};

#endif
