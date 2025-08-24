#version 330

uniform sampler2D texture0;   // main texture
uniform vec3 tintColor;       // color multiplier (R,G,B)

in vec2 fragTexCoord;
in vec4 fragColor;

out vec4 finalColor;

void main() {
    vec4 color = texture(texture0, fragTexCoord) * fragColor;
    color.rgb *= tintColor;   // Apply tint
    color.rgb /= max(dot(tintColor, vec3(0.333)), 0.001);
    finalColor = color;
}
