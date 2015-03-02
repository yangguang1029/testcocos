varying vec4 v_fragmentColor;	
varying vec2 v_texCoord;
varying float v_alpha;

uniform float fuck;


void main()
{
  
    gl_FragColor = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);
    gl_FragColor.a = abs(v_texCoord.y - fuck);
}