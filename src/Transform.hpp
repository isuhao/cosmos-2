#ifndef COSMOS_TRANSFORM_H_
#define COSMOS_TRANSFORM_H_

#include <boost/shared_ptr.hpp>
#include <iostream>
#include <string>

#include "SDL/SDL_opengl.h"

#include "Material.hpp"
#include "Matrix4f.hpp"
#include "Mesh.hpp"
#include "Quaternion.hpp"
#include "util.hpp"
#include "Vector3f.hpp"

/*
 * A class for representing the space transform of an object
 */
class Transform {
 public:
	typedef boost::shared_ptr<Transform> ShPtr;

  Transform(unsigned int id): id_(id), scale_(Vector3f(1.0f, 1.0f, 1.0f)) {}
  const unsigned int id() const { return id_; }
  
  void apply();
  void apply_inverse();
  void apply_rotation();
  void set_direction(const Vector3f& dir);
  void load();
  
  // S Q T
  Transform& set_scale(const Vector3f& scale) { scale_ = scale; return *this; }
  Transform& set_quat(const Quaternion& quat) { quat_ = quat; return *this; }
  Transform& set_translate(const Vector3f& trans) { translate_ = trans; return *this; }
  
  Vector3f get_scale() { return scale_; }
  Quaternion get_rotation() { return quat_; }
  Vector3f get_position() { return translate_; }
  
  //Transform& rotate(const Quaternion& q);
  Transform& rotate(const Vector3f& axis, float angle);
  Transform& rotate_relative(const Vector3f& axis, float angle);
  
  /*Transform& rotateX(float angle);
  Transform& rotateY(float angle);
  Transform& rotateZ(float angle);
  Transform& scale(const Vector3f& scale);
  Transform& translate(const Vector3f& translation);
  void print() const { std::cout << trans_ << std::endl; };*/

 private:
  //static const float M_PI = 3.14159265358979323846;
  const unsigned int id_;

  Vector3f scale_;
  Quaternion quat_;
  Vector3f translate_; 
  
  DISALLOW_COPY_AND_ASSIGN(Transform);
};

#endif
