# Sortie de "jenga info":
```
╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

========================== Jenga Workspace: chapitre2 ==========================

Location: E:\Jenga\chapitre2
Entry file: E:\Jenga\chapitre2\chapitre2.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: Windows, Android
Target Architectures: x86_64, arm64


Projects
------------------------------------------------------------
Name        Kind         Language   Test   External
===================================================
exercice1   ConsoleApp   C++        No     Yes


Available Toolchains
------------------------------------------------------------
Name       Family   Target OS   Arch     Env  
==============================================
host-gcc   gcc      Windows     x86_64   mingw
mingw      gcc      Windows     x86_64   mingw


Daemon
------------------------------------------------------------
Status: Not running
```

# Ce qu'elle m'apprend et que le fichier de projet ne disait pas explicitement:

Elle m'apprend que le workspace s'appelle chapitre2, qu'il utilise le fichier chapitre2.jenga, qu'il possède les configurations Debug et Release, et qu'il cible Windows et Android avec les architectures x86_64 et arm64.

Elle indique également que le projet exercice1 est une application console en C++, sans tests déclarés et considérée comme externe.

Enfin, elle indique les toolchains disponibles (host-gcc et mingw) ainsi que l'état du daemon Jenga, qui n'est pas en fonctionnement.

le fichier .jenga décrit la configuration, alors que jenga info donne une vue d'ensemble de ce que Jenga a réellement compris et détecté dans le workspace.
