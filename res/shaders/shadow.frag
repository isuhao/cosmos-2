#version 150

uniform sampler2D shadowMap;
uniform sampler2D tex;

varying vec4 ShadowCoord;
varying vec2 vTexCoords;
varying vec3 vNormal;
varying vec3 vLightDir;

void main()
{
  vec4 shadowCoordinateWdivide = ShadowCoord / ShadowCoord.w ;

  // Used to lower moiré pattern and self-shadowing
  shadowCoordinateWdivide.z += 0.001;
  //shadowCoordinateWdivide.z += 0.0005;

  float distanceFromLight = texture2D(shadowMap,shadowCoordinateWdivide.st).z;

  float shadow = 1.0;
  if (ShadowCoord.w > 0.0) {
    shadow = distanceFromLight < shadowCoordinateWdivide.z ? 0.5 : 1.0 ;
  }

  float diffuseIntensity = max(0.0, dot(normalize(vNormal), normalize(vLightDir)));
  vec3 color = diffuseIntensity * (gl_FrontMaterial.diffuse).rgb + (gl_FrontMaterial.ambient).rgb;

  vec4 texel = texture2D(tex, vTexCoords.st); //vec4(1.0, 1.0, 1.0, 1.0);
  gl_FragColor = vec4(texel.rgb * color * shadow, texel.a * gl_FrontMaterial.diffuse.a);
  //gl_FragDepth = gl_FragCoord.z;
  //gl_FragColor = shadow * vec4(color, texel.a * gl_FrontMaterial.diffuse.a);
}
