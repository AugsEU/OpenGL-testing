#include "WavefrontModel.h"
#define _CRT_SECURE_NO_WARNINGS

WavefrontModel::WavefrontModel() : mVB(new VertexBuffer({}, 0)), mIB(new IndexBuffer({},0))
{

}

WavefrontModel::~WavefrontModel()
{

}

void WavefrontModel::LoadOBJ(const std::string& OBJPath)
{
    std::vector<float> Verts;
    std::vector<unsigned int> Idx;

    FILE* file = fopen(OBJPath.c_str(), "r");
    if (file == NULL) 
    {
        std::cout << "File error." << std::endl;
        return;
    }
    while (1) 
    {
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        if (strcmp(lineHeader, "v") == 0)
        {
            float vertex[3];
            fscanf(file, "%f %f %f\n", &vertex[0], &vertex[1], &vertex[2]);
            Verts.push_back(vertex[0]);
            Verts.push_back(vertex[1]);
            Verts.push_back(vertex[2]);
        }
        else if (strcmp(lineHeader, "f") == 0)
        {
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
            if (matches != 9) {
                std::cout << "File can't be read by our simple parserTry exporting with other options\n" << std::endl;
                return;
            }
            Idx.push_back(vertexIndex[0]-1);
            Idx.push_back(vertexIndex[1]-1);
            Idx.push_back(vertexIndex[2]-1);
        }
    }

    mVB = std::make_unique<VertexBuffer>(&Verts[0], (unsigned int)(Verts.size() * 3 * sizeof(float)));
    mIB = std::make_unique<IndexBuffer>(&Idx[0], (unsigned int)Idx.size());
}
