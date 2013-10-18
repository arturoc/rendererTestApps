attribute vec4 position;       
attribute vec2 texcoord;       

uniform mat4 modelViewMatrix;  
uniform mat4 projectionMatrix;

varying vec2 texcoord0;

void main()
{
 vec4 pos = projectionMatrix * modelViewMatrix * position;
 gl_Position = pos;
 texcoord0 = texcoord;
}