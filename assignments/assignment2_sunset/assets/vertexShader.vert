#version 450
	layout(location = 0) in vec3 vPos;
	layout(location = 1) in vec2 uvCoord;                 // shader playback time (in seconds)

	out vec2 FragCoord;
	void main(){
		FragCoord = uvCoord;
		gl_Position = vec4(vPos,1.0);
	}