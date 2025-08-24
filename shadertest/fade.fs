#version 330

uniform sampler2D texture0;   // The screen texture
uniform float fadeFactor;     // 0.0 = black, 1.0 = full brightness

in vec2 fragTexCoord;
in vec4 fragColor;

out vec4 finalColor;

void main() {
    vec4 color = texture(texture0, fragTexCoord) * fragColor;
    color.rgb *= fadeFactor; // Darken by factor
    finalColor = color;
}
