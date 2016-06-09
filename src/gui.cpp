// Include standard headers
#include <cstdio>
#include <cstdlib>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#include "shader.hpp"


#include "gui.h"

Gui::Gui(){
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window_ and create its OpenGL context
	window_ = glfwCreateWindow(1024, 768, "Tutorial 02 - Red triangle", NULL,
														NULL);
	if( window_ == NULL ){
		fprintf(stderr, "Failed to open GLFW window_. If you have an Intel GPU,"
			"they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window_);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window_, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glGenVertexArrays(1, &VertexArrayID_);
	glBindVertexArray(VertexArrayID_);

	// Create and compile our GLSL program from the shaders
	programID_ = LoadShaders("SimpleVertexShader.vertexshader",
																 "SimpleFragmentShader.fragmentshader");
}
Gui::~Gui(){
	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID_);
	glDeleteProgram(programID_);

	// Close OpenGL window_ and terminate GLFW
	glfwTerminate();	
}

void Gui::DrawRectangle(Rectangle rect, size_t depth, Color color){
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
							 g_vertex_buffer_data, GL_STATIC_DRAW);

	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data),
							 g_color_buffer_data, GL_STATIC_DRAW);

	// Clear the screen
	glClear( GL_COLOR_BUFFER_BIT );	
	// Use our shader
	glUseProgram(programID_);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, 
												// but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glVertexAttribPointer(
	    1,                // attribute. No particular reason for 1,
	    									// but must match the layout in the shader.
	    3,                // size
	    GL_FLOAT,         // type
	    GL_FALSE,         // normalized?
	    0,                // stride
	    (void*)0          // array buffer offset
	);		

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

}

void Gui::UpdateImage(){
	glfwSwapBuffers(window_);
	glfwPollEvents();
}

