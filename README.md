# WeatherStation-Qt6
Une interface de monitoring météo haute performance développée en **C++20** et **Qt 6 (QML)**.
Conçue pour être légère, moderne et facilement portable sur des systèmes embarqués.

## Preview

![Preview of the App V1](/assets/Interface_V1.png)

## Fonctionnalités
* **Affichage Temps Réel** : Visualisation de la température, humidité et pression.
* **Architecture Découplée** : Backend C++ gérant les données et Frontend QML pour une UI fluide.
* **Modern C++** : Utilisation des fonctionnalités C++20 (Concepts, Span, String Literals).
* **Interface Réactive** : S'adapte à différentes tailles d'écran (Desktop & Tablettes).

## Architecture
Le projet suit un modèle de communication **Signal/Slot** entre le cœur métier et la vue :
* **Backend (C++)** : Gère la logique, les calculs et (bientôt) la réception des capteurs.
* **Frontend (QML/Qt Quick)** : Interface utilisateur déclarative utilisant le matériel accéléré.
* **Data Binding** : Les propriétés C++ sont exposées au QML via `Q_PROPERTY`.

## Installation (WSL / Linux / Windows / Android)

### Prérequis
* **Compilateur** : GCC 11+ (support C++20)
* **Build System** : CMake 3.16+
* **Framework** : Qt 6.x

### Dépendances Ubuntu 24.04
```bash
sudo apt update
sudo apt install qt6-base-dev qml6-module-qtquick-controls qml6-module-qtquick-layouts

mkdir build && cd build
cmake ..
cmake --build .
```

## Distribution & Portabilité
Ce projet est conçu pour être portable. Pour générer un exécutable autonome (AppImage) capable de s'exécuter sur n'importe quelle distribution Linux sans installer Qt6 manuellement :

**Consultez mon outil de packaging : [DockerQt6](https://github.com/Senkyano/DockerQt6)**

Cet outil utilise un environnement Docker/chroot pour garantir que toutes les dépendances Qt6 sont embarquées, résolvant ainsi les problèmes de compatibilité entre différentes versions d'OS.

## Roadmap
- [X] Design de l'interface V1.
- [ ] Squelette de l'interface QML.
- [ ] Liaison C++/QML (Data Binding).
- [ ] Intégration de données réelles via API ou Capteurs.
- [ ] Historisation des données dans une base SQLite.
- [ ] Déploiement via Yocto Project sur Raspberry Pi.