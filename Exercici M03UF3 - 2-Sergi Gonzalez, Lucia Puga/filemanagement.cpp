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
    std::ifstream readFile("score.bin", std::ios::binary);

    if (!readFile) {
        std::cerr << "Error with reading the file." << std::endl;
        return;
    }

    size_t large;
    while (readFile.read(reinterpret_cast<char*>(&large), sizeof(size_t))) {  
        std::string name(large, '\0');  
        readFile.read(&name[0], large); 

        int points;
        readFile.read(reinterpret_cast<char*>(&points), sizeof(int));  

        std::cout << name << ": " << points << std::endl;
    }

    readFile.close();
}