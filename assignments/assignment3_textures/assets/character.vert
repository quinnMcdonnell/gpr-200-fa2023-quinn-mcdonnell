#version 450
layout(location = 0) in vec3 vPos;
layout(location = 1) in vec2 vUV;
out vec2 UV;

uniform float _time;

void main(){
	UV = vUV;

	vec3 Position = vPos;

	Position.x += sin(_time)*0.5;

	gl_Position = vec4(Position*0.5,1);
}