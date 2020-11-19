// MSNeoPoc.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define DEFAULT_PORT 1863


#include "SocketServer.h"
#include "SocketServerException.h"
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")
int main()
{
    std::cout << "Starting main MSNPServer\n";
    try {
        SocketServer serv(DEFAULT_PORT);
        serv.listenAsync();
        char test[20];
        std::cin.getline(test, 20);
    }catch (SocketServerException& e) {
        std::cout << "Unable to create server on port " << DEFAULT_PORT << " : " << e.what() << "\n";
    }

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
