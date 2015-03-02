#ifdef GL_ES
precision lowp float;
#endif

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

vec4 colors[7];
uniform float width;

void main()
{
//    colors[0] = vec4(1,0,0,1);
//    colors[1] = vec4(0,1,0,1);
//    colors[2] = vec4(0,0,1,1);
//    colors[3] = vec4(0,1,1,1);
//    colors[4] = vec4(1,0,1,1);
//    colors[5] = vec4(1,1,0,1);
//    colors[6] = vec4(1,1,1,1);
//    int y = int( mod(gl_FragCoord.y / 3.0, 7.0 ) );
//    gl_FragColor = colors[y] * texture2D(CC_Texture0, v_texCoord);
    gl_FragColor = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);
//    gl_FragColor[1] = 1.;
    gl_FragColor[3] = 0.;
}
