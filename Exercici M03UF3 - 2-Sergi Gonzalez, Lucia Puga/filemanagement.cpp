#include "defines.h"

// Función para guardar las puntuaciones y crear un archivo binario:
void saveScores(std::string name, int points) {

    std::ofstream writeFile;
    writeFile.open("score.bin", std::ios::out | std::ios::binary | std::ios::app);

    size_t longitud = name.size();
    writeFile.write(reinterpret_cast<const char*>(&longitud), sizeof(size_t));
    writeFile.write(name.c_str(), longitud);
    writeFile.write(reinterpret_cast<const char*>(&points), sizeof(int));

    writeFile.close();
}

// Función para leer el archivo binario y mostrar las puntuaciones:
void loadscore() {
    std::ifstream readFile;
    readFile.open("score.bin", std::ios::in | std::ios::binary);

    if (!readFile) {
        std::cerr << "Error with reading the file." << std::endl;
        return;
    }

    while (readFile.peek() != EOF) {
        size_t large;
        readFile.read(reinterpret_cast<char*>(&large), sizeof(size_t));

        if (readFile.eof()) break;

        std::string name;
        name.resize(large);
        readFile.read(&name[0], large);

        int points;
        readFile.read(reinterpret_cast<char*>(&points), sizeof(int));

        std::cout << name << ": " << points << std::endl;
    }

    readFile.close();
}