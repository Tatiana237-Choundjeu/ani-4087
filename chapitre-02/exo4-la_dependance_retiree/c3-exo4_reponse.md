# contenu de exercice1.jenga :
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
    dependson(["moduleA"])


```
# contenu de moduleA.jenga avant :
```
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# moduleA - Jenga Project (inclus dans le workspace via include())

from Jenga import *

with project("moduleA"):
    staticlib()
    language("C++")
    location(".")
    files(["src/**.cpp", "include/**.hpp"])
    dependson([("moduleB")])

```

# Contenu de moduleA.jenga après avoir retiré le moduleB

```
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# moduleA - Jenga Project (inclus dans le workspace via include())

from Jenga import *

with project("moduleA"):
    staticlib()
    language("C++")
    location(".")
    files(["src/**.cpp", "include/**.hpp"])
```

# Contenu de modueB.jenge :

```
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# moduleB - Jenga Project (inclus dans le workspace via include())

from Jenga import *

with project("moduleB"):
    staticlib()
    language("C++")
    location(".")
    files(["src/**.cpp", "include/**.hpp"])

```

# Message d'erreur :
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
  1. moduleA [STATIC_LIB] → 
  2. moduleB [STATIC_LIB] → 
  3. exercice1 [CONSOLE_APP] (depends: moduleA)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: moduleA                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

No source files found for project moduleA

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: moduleB                                                          Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

No source files found for project moduleB

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice1                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date
ℹ Linking...
╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║                                Compilation Error: Link Failed                                ║
╠══════════════════════════════════════════════════════════════════════════════════════════════╣
║ g++.exe: error: E:\Jenga\chapitre2\Build\Lib\Debug-Windows\moduleA\moduleA.lib: No such file ║
║ or directory                                                                                 ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝
✗ Link failed: Build\Bin\Debug-Windows\exercice1\exercice1.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✗ Build Failed                                                                 Time: 0.11s  │
│ Errors: 1  | Failed files: 1                                                                 │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                  BUILD FAILED                                  
════════════════════════════════════════════════════════════════════════════════
Projects Built:  2/3
Failed:         1
Errors:         1
Time:           0.12s
Status:         ✗ FAILURE
════════════════════════════════════════════════════════════════════════════════

Echecs (1) — a corriger :
  ✗ exercice1
```

# L'erreur apparaît à la dernière étape de la chaîne de construction : l'édition de liens
