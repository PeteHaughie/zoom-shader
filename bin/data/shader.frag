OF_GLSL_SHADER_HEADER

uniform sampler2D u_texture;
uniform float u_zoom;
uniform vec2 u_offset;
uniform vec2 u_resolution;

void main() {
    // Calculate normalized UV coordinates from resolution
    vec2 uv = gl_FragCoord.xy / u_resolution;

    // Adjust UV coordinates based on zoom and offset
    vec2 zoomedCoord = (uv - 0.5) / u_zoom + 0.5 + u_offset;

    // Sample the texture with adjusted coordinates
    vec4 color = texture2D(u_texture, zoomedCoord);

    gl_FragColor = color;
}