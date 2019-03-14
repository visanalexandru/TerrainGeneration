#version 330 core
out vec4 FragColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
uniform sampler2D ourTexture;
float get_gradient(float height)
{
    return height/100;
}
vec3 get_color()
{
    float ypos=FragPos.y+50;
    float gradient=get_gradient(ypos);
    vec3 ret;
    if(ypos<40)
    {
        ret=vec3(0.55,0.25,0.55);
    }
    else if(ypos<60)
    {
        ret=vec3(1,0.8,1)*gradient;
    }
    else
    {
        float posy=ypos-60;
        posy=min(posy,10);
        ret=vec3(1,0.8,1)*get_gradient(60)+vec3(2,0.1,2)*get_gradient(posy)*2;
    }
    return ret;
}
void main()
{
    vec3 lightColor=vec3(1,1,1);
    vec3 norm = normalize(Normal);
    vec3 lightDir =vec3(0,1,0);
    float diff = max(dot(norm, lightDir), 0.0)*1.5;
    vec3 diffuse = diff * lightColor;
    vec4 texcolor = texture(ourTexture,TexCoord)*vec4(get_color(),1);
    vec3 result = diffuse * vec3(texcolor);
    FragColor=vec4(result,1.f);
}
