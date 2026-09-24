# Contenu du fichier de projet de la démonstration XR :

```
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""NKXRDemo — Étage 0 de la mission NKXR (XR_MISSION_IA.md) : une scène
NKRenderer rendue en STÉRÉO SIMULÉE via le module NKXR et son backend
simulateur desktop (souris = tête, ZQSD/WASD, stéréo côte à côte).

Architecture : un renderer compositeur (For2D) qui possède la frame + un
renderer ForGame PAR ŒIL en rendu offscreen partagé (patron NK3DModeler /
NkAnimaEditor) — aucune passe de NKRenderer modifiée. Crochets d'agent :
NK_XR_SIM_POSE (pose figée), NK_XR_SHOT (captures par œil), NK_XR_EXIT.
"""
from Jenga import *
from jengaconfig import *

with project("NKXRDemo"):
    windowedapp()
    language("C++")
    cppdialect("C++17")
    location(".")
    files(["src/**.cpp"])

    # NKGLSlang/NKSPIRVCross explicites : le linker d'un exécutable qui tire
    # NKSL/NKRHI ne les récupère pas transitivement (piège documenté dans
    # NkLocomotionDemo.jenga, 2026-07-23).
    nkentseudependson(
        ["NKXR", "NKRenderer", "NKRHI", "NKSL", "NKGLSlang", "NKSPIRVCross",
         "NKSerialization", "NKReflection", "NKFileSystem", "NKFont", "NKImage", "NKGlad",
         "NKEvent", "NKWindow", "NKMath", "NKTime", "NKLogger", "NKStream",
         "NKContainers", "NKMemory", "NKCore", "NKPlatform", "NKThreading"],
        extra_includes=["src",
                        # NkVulkanDevice.h (liaison OpenXR) tire vulkan.h.
                        "%{wks.location}/Externals/Libs/Vulkan-Headers-1.4.350/include"],
    )

    # NK_RHI_VK_ENABLED est un define LOCAL de NKRHI (non propage) : sans lui,
    # NkVulkanDevice.h montre sa classe STUB et la liaison OpenXR ne compile
    # pas. Les cibles desktop de cette demo ont toujours Vulkan (Externals).
    defines(["NK_RHI_VK_ENABLED"])

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")

    apppublisher("Rihen Universe")
    appversion("0.1.0")
    licensefile("../../LICENSE")

    # ===== Windows ================================================================
    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):
        windowedapp()
        usetoolchain(TC_WINDOWS)
        defines(["WIN32_LEAN_AND_MEAN", "_UNICODE", "UNICODE"])
        # advapi32 : RegGetValueA de la decouverte du runtime OpenXR actif
        # (NkXrOpenXRBackend, etape 2a).
        links(["user32", "gdi32", "opengl32", "dwmapi", "shell32", "advapi32",
               "d3d11", "d3d12", "dxgi", "dxguid", "d3dcompiler", "uuid", "ole32"])

    # ===== Linux XLib (défaut) ===================================================
    with filter("system:Linux && options:linux-backend=xlib || system:Linux && !options:linux-backend && !options:headless"):
        windowedapp()
        usetoolchain("clang-native")
        defines(["NKENTSEU_FORCE_WINDOWING_XLIB_ONLY"])
        links(["pthread", "X11", "Xext", "GL"])

    # ===== macOS ==================================================================
    with filter("system:macOS"):
        windowedapp()
        usetoolchain("clang-native")
        frameworks(["Cocoa", "QuartzCore", "OpenGL"])

    with filter("config:Debug"):
        defines(["_DEBUG", "DEBUG"])
        optimize("Off")
        symbols(True)
    with filter("config:Release"):
        defines(["NDEBUG"])
        optimize("Speed")
        symbols(False)
```

# Analyse du fichier

## 1. Ce que construit le projet

Le fichier construit une application graphique appelée **`NKXRDemo`**. Il s'agit d'une démonstration de réalité étendue (XR) utilisant le module **NKXR** du moteur Nkentseu.

Le projet est une application avec fenêtre (`windowedapp`), écrite en **C++17**. Les fichiers sources sont récupérés dans `src/**.cpp`. La démonstration réalise une stéréo simulée sur ordinateur : la scène est rendue pour les deux yeux et affichée côte à côte. Le commentaire du fichier précise également que la souris sert à simuler la tête et que les commandes ZQSD/WASD servent au déplacement.

Le projet utilise un renderer compositeur avec un rendu `ForGame` séparé pour chaque œil, sans modifier directement les passes de `NKRenderer`.

## 2. Ce dont le projet dépend

La dépendance principale est déclarée avec :

```python
nkentseudependson(
    ["NKXR", "NKRenderer", "NKRHI", "NKSL", "NKGLSlang", "NKSPIRVCross",
     "NKSerialization", "NKReflection", "NKFileSystem", "NKFont", "NKImage", "NKGlad",
     "NKEvent", "NKWindow", "NKMath", "NKTime", "NKLogger", "NKStream",
     "NKContainers", "NKMemory", "NKCore", "NKPlatform", "NKThreading"]
)
```

Le projet dépend donc de NKXR et de plusieurs modules graphiques, mathématiques, système et infrastructure du moteur.

Deux dépendances sont particulièrement importantes : **NKGLSlang** et **NKSPIRVCross**. Le commentaire indique qu'elles doivent être déclarées explicitement, car elles ne sont pas automatiquement récupérées de manière transitive lorsqu'un exécutable utilise NKSL/NKRHI.

Le projet ajoute également les headers Vulkan :

```text
Externals/Libs/Vulkan-Headers-1.4.350/include
```

car `NkVulkanDevice.h`, utilisé pour la liaison OpenXR, dépend de `vulkan.h`.

## 3. Ce qui change selon le système

Le fichier adapte la construction à chaque système.

### Windows

Le projet utilise `TC_WINDOWS`, définit des macros Windows et lie plusieurs bibliothèques système, notamment :

```text
user32, gdi32, opengl32, dwmapi, shell32, advapi32,
d3d11, d3d12, dxgi, dxguid, d3dcompiler, uuid, ole32
```

`advapi32` est notamment nécessaire pour `RegGetValueA`, utilisé lors de la découverte du runtime OpenXR actif.

### Linux

Le projet utilise `clang-native` et le backend XLib par défaut. Il définit :

```text
NKENTSEU_FORCE_WINDOWING_XLIB_ONLY
```

et lie :

```text
pthread, X11, Xext, GL
```

### macOS

Le projet utilise également `clang-native` et dépend des frameworks :

```text
Cocoa, QuartzCore, OpenGL
```

Ainsi, le projet conserve la même application mais adapte les outils, définitions et bibliothèques nécessaires à chaque système.

## 4. Les trois pièges documentés

### Piège 1 — Les dépendances transitives de NKSL/NKRHI

Le fichier précise que `NKGLSlang` et `NKSPIRVCross` doivent être déclarées explicitement.

**Ligne concernée :**

```python
["NKXR", "NKRenderer", "NKRHI", "NKSL", "NKGLSlang", "NKSPIRVCross", ...]
```

**Sans cette ligne :**

Jenga pourrait construire les dépendances directes, mais l'édition de liens de l'exécutable pourrait échouer avec des symboles manquants provenant de `NKGLSlang` ou `NKSPIRVCross`.

C'est donc un piège qui se manifeste au niveau du **linker**, et non nécessairement pendant la compilation.

### Piège 2 — Le define `NK_RHI_VK_ENABLED`

Le fichier contient :

```python
defines(["NK_RHI_VK_ENABLED"])
```

Le commentaire explique que ce define est local à NKRHI et n'est pas propagé automatiquement.

**Sans cette ligne :**

`NkVulkanDevice.h` présenterait sa version **STUB** au lieu de la vraie classe Vulkan. La liaison avec OpenXR ne pourrait alors pas être compilée correctement.

Ce piège montre qu'un même fichier d'en-tête peut présenter une interface différente selon les `#define` utilisés lors de la compilation.

### Piège 3 — Les bibliothèques système propres à chaque plateforme

Sous Windows, le projet déclare notamment :

```python
links(["user32", "gdi32", "opengl32", "dwmapi", "shell32", "advapi32",
       "d3d11", "d3d12", "dxgi", "dxguid", "d3dcompiler", "uuid", "ole32"])
```

**Sans ces bibliothèques :**

Le programme pourrait compiler ses fichiers C++, mais l'édition de liens pourrait échouer parce que les fonctions Windows utilisées par le programme ne trouveraient pas leur implémentation.

Le même principe apparaît sous Linux avec `pthread`, `X11`, `Xext` et `GL`, et sous macOS avec les frameworks `Cocoa`, `QuartzCore` et `OpenGL`.

## Conclusion

`NKXRDemo` est donc une application C++17 graphique qui démontre le fonctionnement de `NKXR` avec une XR simulée sur ordinateur. Son fichier Jenga organise les nombreuses dépendances du moteur, ajoute les headers Vulkan nécessaires et adapte les bibliothèques et toolchains selon Windows, Linux ou macOS.

Les trois pièges principaux documentés sont : **les dépendances transitives non récupérées automatiquement, le define Vulkan local à NKRHI et les bibliothèques système nécessaires à l'édition de liens**. Leur suppression peut provoquer respectivement des symboles manquants au linker, un problème de compilation lié à la version STUB de la classe Vulkan, ou des erreurs d'édition de liens propres au système.
