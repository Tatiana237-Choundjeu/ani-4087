# Contenu de Exercice1.jenga
```
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# exercice1 - Jenga Project (inclus dans le workspace via include())

from Jenga import *

with project("exercice1"):
    consoleapp()
    language("C++")
    cppdialect("C++17")
    location(".")
    files(["src/**.cpp", "include/**.hpp"])
    defines(["MON_DEFINE"])
```

# Premier message (avec define) :
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

Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     mingw

Build Order (3 projects):
  1. exercice1 [CONSOLE_APP] → 
  2. moduleA [STATIC_LIB] → 
  3. moduleB [STATIC_LIB]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice1                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exercice1\exercice1.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.80s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: moduleA                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

No source files found for project moduleA

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: moduleB                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

No source files found for project moduleB

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  3/3
Time:           0.81s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

# Deuxième message (sans define) :
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

Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     mingw

Build Order (3 projects):
  1. exercice1 [CONSOLE_APP] → 
  2. moduleA [STATIC_LIB] → 
  3. moduleB [STATIC_LIB]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice1                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ E:\Jenga\chapitre2\Build\Obj\Debug-Windows\exercice1\src_main.obj: In function `main':       ║
║ E:/Jenga/chapitre2/exercice1/src/main.cpp:7: undefined reference to `MonModule::afficher()'  ║
║ collect2.exe: error: ld returned 1 exit status                                               ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build\Bin\Debug-Windows\exercice1\exercice1.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 0.76s  │
│ Errors: 2  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  0/3
Failed:         1
Not reached:    2  (arret au premier echec — voir --keep-going)
Errors:         2
Time:           0.76s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ exercice1

```

# Conclusion
J'aurais su diagnostiquer la première erreur sans cet exercice, car le compilateur indique clairement qu'aucune fonction `afficher()` ne correspond à l'appel effectué et précise qu'un argument est attendu.

En revanche, l'erreur `undefined reference to 'MonModule::afficher()'` est une erreur d'édition de liens. Je l'aurais eu plus de difficulté à diagnostiquer sans cet exercice, car le fichier se compile correctement mais le symbole recherché n'est pas trouvé lors de l'édition de liens.

L'exercice m'a donc permis de comprendre qu'une erreur peut apparaître après la compilation, au moment du linking.

