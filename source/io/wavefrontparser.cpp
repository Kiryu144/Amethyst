#include "wavefrontparser.h"

void readObj(std::string filePath, AM::WavefrontData& data);

void AM::WavefrontParser::readObj(std::string filePath, WavefrontData& data) {
    std::vector<glm::vec3> tempVertices;
    std::vector<glm::vec2> tempUVs;
    std::vector<glm::vec3> tempNormals;

    std::string fileContents;
    AM::readFile(filePath, fileContents);

    data.vertexData.clear();
    data.uvData.clear();
    data.normalData.clear();

    for(std::string& line : AM::splitString(fileContents, '\n')){ //Iterate lines
        std::vector<std::string> args = AM::splitString(line, ' ');
        if(args.size() == 0){ //Skip empty lines
            continue;
        }

        if(args.at(0) == "v" && args.size() >= 4){
            glm::vec3 vertice;
            for(int i = 0; i < 3; i++){
                vertice[i] = std::stof(args[i+1]);
            }
            tempVertices.push_back(vertice);
        }else if(args.at(0) == "vt" && args.size() >= 3){
            glm::vec2 uv;
            for(int i = 0; i < 2; i++){
                uv[i] = std::stof(args[i+1]);
            }
            tempUVs.push_back(uv);
        }else if(args.at(0) == "vn" && args.size() >= 4){
            glm::vec3 normal;
            for(int i = 0; i < 3; i++){
                normal[i] = std::stof(args[i+1]);
            }
            tempNormals.push_back(normal);
        }else if(args.at(0) == "f" && args.size() == 4){
            for(int i = 1; i <= 3; i++) {
                std::vector<std::string> face = AM::splitString(args.at(i), '/');
                if(face.size() == 1){ //Only vertex data present
                    data.vertexData.add(tempVertices.at(std::stoi(face.at(0))-1));
                }else if(face.size() == 2){ //Vertex data & UV data
                    data.vertexData.add(tempVertices.at(std::stoi(face.at(0))-1));
                    data.uvData.add(tempUVs.at(std::stoi(face.at(1))-1));
                }else if(face.size() == 3){
                    data.vertexData.add(tempVertices.at(std::stoi(face.at(0))-1));
                    if(face.at(1).size() > 0){
                        data.uvData.add(tempUVs.at(std::stoi(face.at(1))-1));
                    }
                    if(face.at(2).size() > 0){
                        data.normalData.add(tempNormals.at(std::stoi(face.at(2))-1));
                    }
                }
            }
        }
    }

}





























