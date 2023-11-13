#version 450
out vec4 FragColor;

in Surface{
	vec2 UV;
	vec3 WorldPosition;
	vec3 WorldNormal;
}fs_in;

struct Light
{
	vec3 position;
	vec3 color;
};

struct Material 
{
	float ambientK; //Ambient coefficient (0-1)
	float diffuseK; //Diffuse coefficient (0-1)
	float specular; //Specular coefficient (0-1)
	float shininess; //Shininess
};

#define MAX_LIGHTS 4
uniform Light _Lights[MAX_LIGHTS];

uniform Material _Material;
uniform vec3 _CameraPosition;
uniform sampler2D _Texture;

void main(){
	
	vec4 newTex = texture(_Texture,fs_in.UV);

	vec3 normal = normalize(fs_in.WorldNormal);
	vec3 position = fs_in.WorldPosition;

	for(int i = 0; i < MAX_LIGHTS; i++)
	{
	vec3 LightPosition = _Lights[i].position;
	vec3 omega = normalize(LightPosition - position); //Omega Vector
	vec3 h = normalize(omega + _CameraPosition);

	vec3 Amb = _Lights[i].color * _Material.ambientK;
	vec3 Dif = _Lights[i].color * _Material.diffuseK * max(dot(omega, normal),0);
	vec3 Spec = _Lights[i].color * _Material.specular * pow(max(dot(h,normal),0),_Material.shininess);

	vec3 I = Amb + Dif + Spec;
	newTex.rgb = newTex.rgb * I;
	}

	

	FragColor = newTex;
}