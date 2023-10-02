#version 450
out vec4 FragColor;
in vec2 UV;

uniform sampler2D _Texture;
uniform sampler2D _Noise;
uniform float _time;

void main(){
	vec4 base = texture(_Texture,UV);
	vec4 noise = texture(_Noise,UV);
	FragColor = mix(base,noise,0.5);
}