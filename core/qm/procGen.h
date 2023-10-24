#pragma once
#include "..ew/mesh.h"
#include "..ew/ewMath.h"

namespace qm 
{
	struct Vertex {
		ew::Vec3 pos;
		ew::Vec3 normal;
		ew::Vec2 uv;
	};

	struct MeshData {
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
	};

	ew::MeshData createSphere(float radius, int numSegments)
	{
	}

	ew::MeshData createCylinder(float height, float radius, int numSegments)
	{
	}

	ew::MeshData createPlane(float size, int subdivisions)
	{
		MeshData data;
		Vertex v;

		for (float row = 0; row <= subdivisions; row++)
		{
			for (float col = 0; col <= subdivisions; col++)
			{
				v.pos.x = size * (col / subdivisions);
				v.pos.y = 1;
				v.pos.z = size * (row / subdivisions);

				v.normal = ew::Vec3(0, 1, 0);
				v.uv = (row/subdivisions, col/subdivisions);
				data.vertices.push_back(v);
			}
		}

		int columns = subdivisions + 1;
		for (int row = 0; row < subdivisions; row++)
		{
			for (int col = 0; col < subdivisions; col++)
			{
				int start = row * columns + col;
				data.indices.push_back(start);
				data.indices.push_back(start + 1);
				data.indices.push_back(start + columns + 1);

				data.indices.push_back(start);
				data.indices.push_back(start + columns);
				data.indices.push_back(start + columns + 1);
			}
		}



		return data;
	}
}
