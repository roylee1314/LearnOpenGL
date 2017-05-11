#version 330 core

#version 330 core
struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};



in vec3 Normal;
in vec3 FragPos;
in vec3 LightPos;

out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 viewPos;
uniform Material material;


void main()
{	
	float ambientStrength = 0.1f;
	// ambient
	vec3 ambient = ambientStrength * lightColor;
	// diffuse
	vec3 norm = normalize(Normal);

	vec3 lightDir = normalize(LightPos  - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;
	// specular
	float specularStrength = 0.5f;
	vec3 viewDir = normalize(- FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir),0.0), 128);
	vec3 specular = specularStrength * spec * lightColor;
	vec3 result = (ambient + diffuse + specular) * objectColor;
	color = vec4(result, 1.0f);

}


