#version 330 core

layout(points) in;
//layout(points, max_vertices = 10) out;				//to draw points
//layout(line_strip, max_vertices = 2) out;			//to draw lines
layout(triangle_strip, max_vertices = 7) out;		//to draw rectangles
//layout(line_strip, max_vertices = 11) out;		//to draw 10-sided polygon
//layout(line_strip, max_vertices = 64) out;			//to draw polygons with different number of sides

//layout(triangle_fan, max_vertices = 5) out;


in float vSides[];

in vec4 vertexColor[];								// Output from vertex shader for each vertex
out vec4 fColor;									// Output to fragment shader

const float PI = 3.1415926;


//					(0,0,1)
//				   *
//			      /|\
//	  (-1,1,0)  /  |  \  (1,1,0)
//			   * - | - * 
//			  /    |0  /
// (-1,-1,0) *--------* (1,-1,0)		
//	 

void arrowPyramid4(vec4 position)
{    
    gl_Position = position + vec4(0.1, 0.1, 0.0, 0.0);
	fColor = vertexColor[0]; 
    EmitVertex();   
	gl_Position = position + vec4(0.1, -0.1, 0.0, 0.0); 
	fColor = vertexColor[0]; 
    EmitVertex();
    gl_Position = position + vec4(0.0, 0.0, 0.1, 0.0);
	fColor = vec4(1,1,1,1);
	EmitVertex();
    gl_Position = position + vec4(-0.1, -0.1, 0.0, 0.0);
	fColor = vertexColor[0]; 
    EmitVertex();

	gl_Position = position + vec4(0.0, 0.0, 0.1, 0.0);
	fColor = vec4(1,1,1,1);
	EmitVertex();
    gl_Position = position + vec4(-0.1, 0.1, 0.0, 0.0);
	fColor = vertexColor[0]; 
    EmitVertex();
	gl_Position = position + vec4(0.1, 0.1, 0.0, 0.0);
	fColor = vertexColor[0]; 
    EmitVertex();
    EndPrimitive();
}

vec3 testVector = vec3(1, 0, 0);
void arrowPyramid4Dir(vec4 position) //, vec4 direction)
{    
	//direction
	vec3 transform_y = cross(vec3(0.0, 0.0, 1.0), testVector);
	vec3 transform_z = testVector;
	vec3 transform_x = cross(transform_z, transform_y);

	mat4 transform = mat4(1);
	transform[0][0] = transform_x[0];
	transform[1][0] = transform_y[0];
	transform[2][0] = transform_z[0];

	transform[0][1] = transform_x[1];
	transform[1][1] = transform_y[1];
	transform[2][1] = transform_z[1];

	transform[0][2] = transform_x[2];	
	transform[1][2] = transform_y[2];	
	transform[2][2] = transform_z[2];

	transform[0][3] = 0;
	transform[1][3] = 0;
	transform[2][3] = 0;
	transform[3][3] = 1;


    gl_Position = position + transform*vec4(0.1, 0.1, 0.0, 0.0);
	fColor = vertexColor[0]; 
    EmitVertex();   
	gl_Position = position + transform*vec4(0.1, -0.1, 0.0, 0.0); 
	fColor = vertexColor[0]; 
    EmitVertex();
    gl_Position = position + transform*vec4(0.0, 0.0, 0.1, 0.0);
	fColor = vec4(1,1,1,1);
	EmitVertex();
    gl_Position = position + transform*vec4(-0.1, -0.1, 0.0, 0.0);
	fColor = vertexColor[0]; 
    EmitVertex();

	gl_Position = position + transform*vec4(0.0, 0.0, 0.1, 0.0);
	fColor = vec4(1,1,1,1);
	EmitVertex();
    gl_Position = position + transform*vec4(-0.1, 0.1, 0.0, 0.0);
	fColor = vertexColor[0]; 
    EmitVertex();
	gl_Position = position + transform*vec4(0.1, 0.1, 0.0, 0.0);
	fColor = vertexColor[0]; 
    EmitVertex();
    EndPrimitive();
}

void test(vec4 position) {

//direction
	vec3 transform_y = cross(vec3(0.0, 0.0, 1.0), testVector);
	vec3 transform_z = testVector;
	vec3 transform_x = cross(transform_z, transform_y);

	mat4 transform = mat4(1);
	transform[0][0] = transform_x[0];
	transform[1][0] = transform_x[1];
	transform[2][0] = transform_x[2];

	transform[0][1] = transform_y[0];
	transform[1][1] = transform_y[1];
	transform[2][1] = transform_y[2];

	transform[0][2] = transform_z[0];	
	transform[1][2] = transform_z[1];	
	transform[2][2] = transform_z[2];

	transform[0][3] = 1;
	transform[1][3] = 1;
	transform[2][3] = 1;
	transform[3][3] = 1;


	gl_Position = transform*(position + vec4(0.1, 0.1, 0.0, 0.0));
	fColor = vertexColor[0]; 
    EmitVertex();   
	gl_Position = transform*(position + vec4(0.1, -0.1, 0.0, 0.0)); 
	fColor = vertexColor[0]; 
    EmitVertex();
    gl_Position = transform*(position + vec4(0.0, 0.0, 0.1, 0.0));
	fColor = vec4(1,1,1,1);
	EmitVertex();
    gl_Position = transform*(position + vec4(-0.1, -0.1, 0.0, 0.0));
	fColor = vertexColor[0]; 
    EmitVertex();

	gl_Position = transform*(position + vec4(0.0, 0.0, 0.1, 0.0));
	fColor = vec4(1,1,1,1);
	EmitVertex();
    gl_Position = transform*(position + vec4(-0.1, 0.1, 0.0, 0.0));
	fColor = vertexColor[0]; 
    EmitVertex();
	gl_Position = transform*(position + vec4(0.1, 0.1, 0.0, 0.0));
	fColor = vertexColor[0]; 
    EmitVertex();
    EndPrimitive();

}

void main() {
	fColor = vertexColor[0]; // Point has only one vertex
	
	//arrowPyramid4(gl_in[0].gl_Position);
	arrowPyramid4Dir(gl_in[0].gl_Position);

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
	//for (int i = 0; i <= vSides[0]; i++) {
	//	// Angle between each side in radians
	//	float ang = PI * 2.0 / vSides[0] * i;
	//
	//	// Offset from center of point (0.3 to accomodate for aspect ratio)
	//	vec4 offset = vec4(cos(ang) * 0.3, -sin(ang) * 0.4, 0.0, 0.0);
	//	gl_Position = gl_in[0].gl_Position + offset;
	//
	//	EmitVertex();
	//}

	EndPrimitive();
}