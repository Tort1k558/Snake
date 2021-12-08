#version 330 core

out vec4 frag_color;
in vec2 texCoords;
uniform sampler2D texture1;
void main()
{
	frag_color = texture(texture1,texCoords);
	if(frag_color.rgb == vec3(1.0))
	{
		discard;
	}
}