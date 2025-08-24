#version 330
uniform sampler2D texture0;
in vec2 fragTexCoord;
in vec4 fragColor;
out vec4 finalColor;
void main() {
    vec4 color = texture(texture0, fragTexCoord) * fragColor;
    color.rgb = 1.0 - color.rgb; // invert colors
    finalColor = color;
}
