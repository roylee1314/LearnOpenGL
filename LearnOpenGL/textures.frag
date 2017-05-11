#version 330 core
in vec3 ourColor;
in vec2 TexCoord;
uniform sampler2D dayTexture;
uniform sampler2D nightTexture;
uniform float tm;
out vec4 color;

void main()
{
	color = mix(texture(dayTexture, TexCoord), texture(nightTexture, TexCoord), sin(tm) / 2.0 + 0.5);
	//color = texture(dayTexture, TexCoord) * vec4(ourColor, 1.0f);
}
