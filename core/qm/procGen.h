#pragma once
#include <ew/mesh.h>
#include <ew/ewMath/ewMath.h>

namespace qm 
{
	//qm::MeshData createSphere(float radius, int numSegments){}

	ew::MeshData createCylinder(float height, float radius, int numSegments)
	{
		ew::MeshData data;
		ew::Vertex v;

		float topY = height / 2;
		float bottomY = -topY;

		v.pos = ew::Vec3(0, topY, 0);
		v.normal = ew::Vec3(0, 1, 0);
		v.uv = ew::Vec2(0.5f, 0.5f);

		data.vertices.push_back(v);

		float thetaStep = 6.28 / numSegments; //see how to get pi
		
		for (int dupe = 0; dupe < 2; dupe++) {
			for (int i = 0; i < numSegments; i++)
			{
				float theta = i * thetaStep;
				v.pos.x = cos(theta) * radius;
				v.pos.z = sin(theta) * radius;
				v.pos.y = topY;

				if (dupe == 0)
				{
					v.normal = ew::Vec3(0, 1, 0);
					v.uv = ew::Vec2((float)(v.pos.x), (float)(v.pos.z)) + ew::Vec2(0.5f, 0.5f);
				}
				else if (dupe == 1)
				{
					v.normal = ew::Vec3(0,topY,0) + v.pos;
					v.uv = ew::Vec2(v.pos.x,1);
				}

				data.vertices.push_back(v);
			}
		}
		for (int dupe = 0; dupe < 2; dupe++)
		{
			for (int i = 0; i < numSegments; i++)
			{
				float theta = i * thetaStep;
				v.pos.x = cos(theta) * radius;
				v.pos.z = sin(theta) * radius;
				v.pos.y = bottomY;

				if (dupe == 0)
				{
					v.normal = ew::Vec3(0, bottomY, 0) + v.pos;
					v.uv = ew::Vec2(v.pos.x, 0);
				}
				else if (dupe == 1)
				{
					v.normal = ew::Vec3(0, -1, 0);
					v.uv = ew::Vec2((float)(v.pos.x), (float)(v.pos.z)) + ew::Vec2(0.5f, 0.5f);
				}

				data.vertices.push_back(v);
			}
		}
		
		v.pos = ew::Vec3(0, bottomY, 0);
		v.normal = ew::Vec3(0, -1, 0);
		v.uv = ew::Vec2(0.5f, 0.5f);
		data.vertices.push_back(v);


		//Indices are done here
		int start = 1;
		int center = 0;

		for (int i = 0; i < numSegments; i++)
		{
			data.indices.push_back(start + i);
			data.indices.push_back(center);
			data.indices.push_back(start + i + 1);
		}

		start = (2 * numSegments) + 1;
		center = data.vertices.size() - 1;

		for (int i = 0; i < numSegments; i++)
		{
			data.indices.push_back(start + i + 1);
			data.indices.push_back(center);
			data.indices.push_back(start + i);
		}
		
		int sideStart = 1;
		int columns = numSegments + 1;

		for (int i = 0; i < numSegments; i++)
		{
			int start = sideStart + 1;
			data.indices.push_back(start);
			data.indices.push_back(start + 1);
			data.indices.push_back(start + columns);

			data.indices.push_back(start + columns + 1);
			data.indices.push_back(start + columns);
			data.indices.push_back(start + 1);

		}

		return data;
	}

	ew::MeshData createPlane(float size, int subdivisions)
	{
		ew::MeshData data;
		ew::Vertex v;

		for (float row = 0; row <= subdivisions; row++)
		{
			for (float col = 0; col <= subdivisions; col++)
			{
				v.pos.x = size * (col / subdivisions);
				v.pos.y = 0;
				v.pos.z = -size * (row / subdivisions);

				v.normal = ew::Vec3(0, 1, 0);
				v.uv = ew::Vec2(row/subdivisions, col/subdivisions);
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
				data.indices.push_back(start + columns + 1);
				data.indices.push_back(start + columns);
			}
		}

		return data;
	}
}
