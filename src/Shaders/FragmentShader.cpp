#include "FragmentShader.hpp"

const std::string FragmentShader::get_name() const {
	return name_;
}

const bool FragmentShader::is_name(const std::string& rhs) const {
	return name_.compare(rhs) == 0;
}
