#version 120

attribute vec3 position;

void main()
{
	gl_Position = vec4(position * 0.5,1.0);
}