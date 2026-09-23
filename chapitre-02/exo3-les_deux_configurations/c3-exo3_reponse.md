# - Construction avec Debug:
```
Loading workspace...

Configuration: debug
Target:        Windows x86_64
Toolchain:     mingw

Build Order (1 projects):
  1. exercice1 [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice1                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\exercice1\exercice1.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.97s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.97s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```


# - Construction avec Release:
```
Loading workspace...

Configuration: release
Target:        Windows x86_64
Toolchain:     mingw

Build Order (1 projects):
  1. exercice1 [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: exercice1                                                       Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓   [1/1] Compiled: main.cpp
ℹ Linking...
✓ Built: Build\Bin\release-Windows\exercice1\exercice1.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.56s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           1.56s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

# Comparons:
|    | Debug | Release |
|---|---|---|
|Taille|60.2 Ko|60.2 Ko|
|Temps |0.97s|1.56s|

On constate que release a pris plus de temps que Debug et ils ont la même taille d'exécutables.

