#version 330

uniform sampler2D texture0;
uniform vec3 tintColor;   // e.g. pink {1.0, 0.4, 0.7}
uniform float strength;   // 0.0 = none, 1.0 = full tint

in vec2 fragTexCoord;
in vec4 fragColor;

out vec4 finalColor;

void main() {
	if (strength >= 1)
		finalColor = vec4(tintColor, 1.0);
	else
	{
		vec4 color = texture(texture0, fragTexCoord) * fragColor;
		vec3 tinted = mix(color.rgb, tintColor, strength);
		finalColor = vec4(tinted, color.a);
	}
}
