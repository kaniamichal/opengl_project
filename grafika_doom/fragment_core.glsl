#version 460

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	sampler2D diffuseTex;
	sampler2D specularTex;
};


in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcord;
in vec3 vs_normal;

out vec4 fs_color;

//uniforms
uniform Material material;
uniform vec3 lightPos0;
uniform vec3 cameraPosition; 

//functions
vec3 calculateAmbient(Material material)
{
		return material.ambient;
}

vec3 calculateDiffuse(Material material, vec3 vs_position, vec3 vs_normal, vec3 lightPos0)
{
	vec3 posToLightDirectionVector = normalize(lightPos0 - vs_position);
	float diffuse = clamp(dot(posToLightDirectionVector, vs_normal), 0, 1); 
	vec3 diffuseFinal = material.diffuse * diffuse;

	return diffuseFinal;
}

vec3 calculateSpecular(Material material, vec3 vs_position, vec3 vs_normal, vec3 lightPos0, vec3 cameraPosition)
{
	vec3 lightToPosDirVec = normalize(vs_position - lightPos0);
	vec3 reflectDirVec = normalize(reflect(lightToPosDirVec, normalize(vs_normal)));
	vec3 posToViewDirVec = normalize(cameraPosition - vs_position);
	float specularConstant = pow(max(dot(posToViewDirVec, reflectDirVec), 0), 10);
	vec3 specularFinal = material.specular * specularConstant;

	return specularFinal; 
}

void main()
{
	//fs_color = vec4(vs_color, 1.f);
	//fs_color = texture(texture0, vs_texcord);// + texture(texture1, vs_texcord); //* vec4(vs_color, 1.f);

	//ambient light
	vec3 ambientFinal = calculateAmbient(material);
	
	//diffuse light
	vec3 diffuseFinal = calculateDiffuse(material, vs_position, vs_normal, lightPos0);

	//specular light
	vec3 specularFinal = calculateSpecular(material, vs_position, vs_normal, lightPos0, cameraPosition);

	//atenuations


	//final light
	fs_color = texture(material.diffuseTex, vs_texcord) * vec4(vs_color, 1.0f) * (vec4(ambientFinal, 1.0f) + vec4(diffuseFinal, 1.0f) + vec4(specularFinal, 1.0f));
}