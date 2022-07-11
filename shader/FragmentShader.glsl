#version 330 core
in vec3 vertexColor;
in vec2 vertexTexCoord;

out vec4 FragColor;

uniform sampler2D mTexture1;
uniform sampler2D mTexture2;
uniform float delta;

void main()
{
	vec2 texCoord1 = vertexTexCoord;
	vec2 texCoord2 = vec2(-vertexTexCoord.x, vertexTexCoord.y);
	FragColor = mix(texture(mTexture1, texCoord1), texture(mTexture2, texCoord2), delta);
}
