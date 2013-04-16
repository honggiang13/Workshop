precision mediump float;
uniform sampler2D u_texColor1;
uniform vec4 u_step;
varying vec2 v_uv;
void main()
{
	vec4 color1 = texture2D(u_texColor1, v_uv);
	vec4 color2 = texture2D(u_texColor1, v_uv + vec2(u_step.x,0.0));
	vec4 color3 = texture2D(u_texColor1, v_uv + vec2(u_step.z, u_step.w));
	vec4 color4 = texture2D(u_texColor1, v_uv + vec2(0.0, u_step.y));
	vec4 color5 = texture2D(u_texColor1, v_uv + vec2(-u_step.z, u_step.w));
	vec4 color6 = texture2D(u_texColor1, v_uv + vec2(-u_step.x, 0.0));
	vec4 color7 = texture2D(u_texColor1, v_uv + vec2(-u_step.z, -u_step.w));
	vec4 color8 = texture2D(u_texColor1, v_uv + vec2(0.0, -u_step.y));
	vec4 color9 = texture2D(u_texColor1, v_uv + vec2(u_step.z, -u_step.w));
	gl_FragColor = (2.0 * color1 + color2 + color3 + color4 + color5 + color6 + color7 + color8 + color9) * 0.1;

}
