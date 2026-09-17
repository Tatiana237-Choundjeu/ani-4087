Mon code:


import pygame
import time

pygame.init()
fenetre = pygame.display.set_mode((800, 600))

durees = []

for i in range(1000):
    debut = time.perf_counter()

    fenetre.fill((0, 0, 0))
    pygame.display.flip()

    fin = time.perf_counter()

    durees.append((fin - debut) * 1000)

print("Plus longue image :", max(durees), "ms")
print("Images > 11 ms :", sum(d > 11 for d in durees))

pygame.quit()



Temps de la plus longe image: 46.18ms

Nombre d'images de plus de 11 secondes : 2 images

Conclusion: Mon code ne peux pas tenir dans un casque de VR car il y'a déjà deux images de plus de 11ms et sa pire image fait 46.18ms, ce qui dépasse largement l'écheance.
