#version 330

uniform sampler2D texture0;
uniform vec3 tintColor;   // e.g. pink {1.0, 0.4, 0.7}
uniform float strength;   // 0.0 = none, 1.0 = full tint

in vec2 fragTexCoord;
in vec4 fragColor;

out vec4 finalColor;

void main() {
    vec4 color = texture(texture0, fragTexCoord) * fragColor;
    color.rgb = mix(color.rgb, tintColor, strength);
    finalColor = color;
}
