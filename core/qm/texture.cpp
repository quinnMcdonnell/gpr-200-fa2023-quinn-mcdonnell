#include "texture.h"
#include "../ew/external/stb_image.h"
#include "..ew/external/glad.h"


namespace qm
{
	unsigned int loadTexture(const char* filePath) {

		stbi_set_flip_vertically_on_load(true);

		int width, height, numComponents;
		unsigned char* data = stbi_load(filePath, &width, &height, &numComponents, 0)
			if (data == NULL) {
				printf("Failed to load image %s", filePath);
				stbi_image_free(data);
				return 0;
			}
	}

}

