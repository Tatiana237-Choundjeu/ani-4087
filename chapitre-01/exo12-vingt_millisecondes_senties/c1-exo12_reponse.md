Mon Code:


import pygame
import time

pygame.init()

fenetre = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Test de latence")

retard_ms = 10
en_cours = True

while en_cours:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            en_cours = False

        # j'augmente le retard avec la flèche droite
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                retard_ms = min(200, retard_ms + 10)

            # Je diminue le retard avec la flèche gauche
            if event.key == pygame.K_LEFT:
                retard_ms = max(0, retard_ms - 10)

    # Position actuelle de la souris
    position = pygame.mouse.get_pos()

    # J'attends le retard choisi
    time.sleep(retard_ms / 1000)

    # Dessin
    fenetre.fill((30, 30, 30))
    pygame.draw.circle(fenetre, (255, 255, 255), position, 20)
    pygame.display.flip()

pygame.quit()



J'ai utilisé un programme qui fait suivre à un objet affiché à l'écran les mouvements de la souris, avec un retard réglable de 0 à 200 ms.

J'ai fait essayer le programme à cinq personnes et j'ai noté le retard à partir duquel chacune a déclaré ressentir un décalage.

Personne   | Seuil ressenti |
| ---------- | -------------: |
| Personne 1 |      10 ms |
| Personne 2 |      10 ms |
| Personne 3 |      20 ms |
| Personne 4 |      20 ms |
| Personne 5 |      10 ms |

Les seuils observés sont donc de **10, 10, 20, 20 et 10 ms**. La majorité des personnes ont détecté le retard dès **10 ms**.

Le budget fixé est de 20 ms. Les résultats montrent que le retard peut être perceptible avant d'atteindre ce budget, puisque trois personnes sur cinq ont ressenti un décalage dès 10 ms.

Dans un casque VR, le seuil doit être encore plus bas, car l'image doit suivre très rapidement les mouvements réels de la tête. Un retard entre le mouvement de la tête et l'image affichée crée un conflit entre la vision et les informations de l'oreille interne, ce qui peut provoquer de l'inconfort ou le mal des transports.
