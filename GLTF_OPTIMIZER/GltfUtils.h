#pragma once
#include "tiny_gltf.h"
#pragma once

static void GetNodeMeshIdx(tinygltf::Model* model, tinygltf::Node* node, std::vector<int>& meshIdxs)
{
	if (node->children.size() > 0)
	{
		for (int i = 0; i < node->children.size(); ++i)
		{
			GetNodeMeshIdx(model, &(model->nodes[node->children[i]]), meshIdxs);
		}
	}
	if (node->mesh != -1)
	{
		meshIdxs.push_back(node->mesh);
	}
}

