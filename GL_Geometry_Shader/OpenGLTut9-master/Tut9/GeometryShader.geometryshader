#version 330 core

layout(points) in;
//layout(points, max_vertices = 1) out;				//to draw points
//layout(line_strip, max_vertices = 2) out;			//to draw lines
//layout(triangle_strip, max_vertices = 5) out;		//to draw rectangles
//layout(line_strip, max_vertices = 11) out;		//to draw 10-sided polygon
layout(line_strip, max_vertices = 64) out;			//to draw polygons with different number of sides

in float vSides[];

in vec4 vertexColor[];								// Output from vertex shader for each vertex
out vec4 fColor;									// Output to fragment shader

const float PI = 3.1415926;

void main() {
	fColor = vertexColor[0]; // Point has only one vertex
	
	/////TO DRAW POINTS/////
	//gl_Position = gl_in[0].gl_Position;
	//EmitVertex();
	
	/////TO DRAW LINES/////
	//gl_Position = gl_in[0].gl_Position + vec4(-0.1, 0.0, 0.0, 0.0);
    //EmitVertex();

    //gl_Position = gl_in[0].gl_Position + vec4(0.1, 0.0, 0.0, 0.0);
    //EmitVertex();

	/////TO DRAW RECTANGLES/////
	//gl_Position = gl_in[0].gl_Position + vec4(-0.1, 0.1, 0.0, 0.0);
	//EmitVertex();

	//gl_Position = gl_in[0].gl_Position + vec4(0.1, 0.1, 0.0, 0.0);
	//EmitVertex();

	//gl_Position = gl_in[0].gl_Position + vec4(0.1, -0.1, 0.0, 0.0);
	//EmitVertex();

	//gl_Position = gl_in[0].gl_Position + vec4(-0.1, -0.1, 0.0, 0.0);
	//EmitVertex();

	//gl_Position = gl_in[0].gl_Position + vec4(-0.1, 0.1, 0.0, 0.0);
	//EmitVertex();
	
	/////TO DRAW 10-SIDED POLYGON/////
	//for (int i = 0; i <= 10; i++) {
    //    // Angle between each side in radians
    //    float ang = PI * 2.0 / 10.0 * i;
	//
    //    // Offset from center of point (0.3 to accomodate for aspect ratio)
    //    vec4 offset = vec4(cos(ang) * 0.3, -sin(ang) * 0.4, 0.0, 0.0);
    //    gl_Position = gl_in[0].gl_Position + offset;
	//
    //    EmitVertex();
    //}
	
	/////TO DRAW POLYGONS WITH DIFFERENT NUMBER OF SIDES/////
	for (int i = 0; i <= vSides[0]; i++) {
		// Angle between each side in radians
		float ang = PI * 2.0 / vSides[0] * i;

		// Offset from center of point (0.3 to accomodate for aspect ratio)
		vec4 offset = vec4(cos(ang) * 0.3, -sin(ang) * 0.4, 0.0, 0.0);
		gl_Position = gl_in[0].gl_Position + offset;

		EmitVertex();
	}

	EndPrimitive();
}