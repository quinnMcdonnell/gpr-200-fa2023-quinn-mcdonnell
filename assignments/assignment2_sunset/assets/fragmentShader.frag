#version 450
uniform vec2 iResolution;           // viewport resolution (in pixels)
uniform float iTime;                 // shader playback time (in seconds)
out vec4 FragColor;
in vec2 FragCoord;
void main(){
	vec2 uv = FragCoord;
    float aspectRatio = iResolution.x/iResolution.y;
    float t = 0.75f*sin(iTime)+0.5f;
    
    //Colors
    vec3 Night = vec3(0.0,0.0,0.3);
    vec3 Day = vec3(1,0,0.0);
    vec3 Sun = vec3(1,1,0.0);
    vec2 circle = vec2(aspectRatio*0.5,t-0.5);
    
    //Graident Animation
    vec3 Gradient = vec3(cos(t) * uv.y, 0, cos(t) * uv.y);
    
    //Background
    vec3 Background = smoothstep(Day, Night, Gradient);
    float sunDistance = step(length(uv - circle),0.1f);
    float hills = 1.0 - step(cos(uv.x*5.0) * 0.2 + 0.4,uv.y);
    
    //Blend dark grey hills
    vec3 color = Background;
    color = mix(color, mix(Sun*sunDistance,Sun*sunDistance,t),sunDistance);
    color = mix(color,vec3(0.05),hills);

    FragColor = vec4(color,1.0);

}

