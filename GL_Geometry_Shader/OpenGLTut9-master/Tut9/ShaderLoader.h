#ifndef SHADERLOADER_H
#define SHADERLOADER_H

GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path, const char * geometry_file_path);

#endif