#include "OBJObject.h"

OBJObject::OBJObject(const char *filepath) 
{
	toWorld = glm::mat4(1.0f);
	this->angle = 0.0f;
	parse(filepath);
}

void OBJObject::parse(const char *filepath) 
{
	FILE* fp;     // file pointer

	int c1, c2;    // characters read from file

	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec3 > temp_normals;
	std::vector< glm::vec3 > temp_colors;
	std::vector< unsigned int > vertexIndices, colorIndices, normalIndices;



	fp = fopen(filepath, "rb");  // make the file name configurable so you can load other files
	if (fp == NULL) { cerr << "error loading file" << endl; exit(-1); }  // just in case the file can't be found or is corrupt
	while (1) {
		c1 = fgetc(fp);
		c2 = fgetc(fp);
		if (c1 == EOF)
			break;
		if (c1 == 'v' && c2 == ' ')
		{
			glm::vec3 vertex;
			
			fscanf(fp, "%f %f %f", &vertex.x, &vertex.y, &vertex.z);
			vertices.push_back(vertex);
	
		}

		else if (c1 == 'v' && c2 == 'n')
		{
			glm::vec3 normal;
			fscanf(fp, "%f %f %f", &normal.x, &normal.y, &normal.z);
			normals.push_back(normal);
		}
	
	}


	// read normal data accordingly

	fclose(fp);   // make sure you don't forget to close the file when done


	//TODO parse the OBJ file
	// Populate the face indices, vertices, and normals vectors with the OBJ Object data

}

void OBJObject::draw() 
{
	glMatrixMode(GL_MODELVIEW);

	// Push a save state onto the matrix stack, and multiply in the toWorld matrix
	glPushMatrix();
	glMultMatrixf(&(toWorld[0][0]));

	glBegin(GL_POINTS);
	// Loop through all the vertices of this OBJ Object and render them
	for (unsigned int i = 0; i < vertices.size(); ++i) 
	{
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);

		if (i < normals.size()) {
			glm::vec3 rgb_normal = normals[i] * 0.5f + 0.5f;
			glColor3f(rgb_normal.x, rgb_normal.y, rgb_normal.z);
		}
		
	}

	glEnd();

	// Pop the save state off the matrix stack
	// This will undo the multiply we did earlier
	glPopMatrix();
}

void OBJObject::update()
{
	spin(1.0f);
}

void OBJObject::spin(float deg)
{
	this->angle += deg;
	if (this->angle > 360.0f || this->angle < -360.0f) this->angle = 0.0f;
	// This creates the matrix to rotate the cube
	this->toWorld = glm::rotate(glm::mat4(1.0f), this->angle / 180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f));
}