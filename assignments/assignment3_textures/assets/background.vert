#version 450
layout(location = 0) in vec3 vPos;
layout(location = 1) in vec2 vUV;
out vec2 UV;

uniform float _time;

void main(){
	UV = vUV;

	vec3 position = vPos;
	position.y += sin(_time + position.x)*0.5;

	gl_Position = vec4(position*2,1.0);
}