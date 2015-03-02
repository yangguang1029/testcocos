attribute vec4 a_position;
attribute vec2 a_texCoord;
attribute vec4 a_color;


uniform float delta;
uniform float height;

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
varying float v_alpha;
							
void main()						
{												
    gl_Position = CC_PMatrix * a_position;
    v_fragmentColor = a_color;
    v_texCoord = a_texCoord;
    v_alpha = abs(a_position.y - delta) / height;
}