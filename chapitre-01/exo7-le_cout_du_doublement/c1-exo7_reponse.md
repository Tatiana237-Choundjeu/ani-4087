Temps moyen du rendu : 1.3ms

Estimation du rendu deux fois : 1.3 * 2 = 2.6ms

Temps restant sur 11 ms : 11 - 2.6 = 8.4ms

Conclusion: Le rendu seul est relativement rapide puisqu'il prend environ 1,3 ms. Même effectué deux fois, il prend environ 2,6 ms, ce qui laisse 8,4 ms pour le reste du programme. Je pense qu'il faut donc surtout surveiller et réduire les traitements qui consomment beaucoup de temps dans le reste de la boucle (la logique, les calculs et les opérations effectuées à chaque image) afin de conserver une marge suffisante pour respecter le budget de 11 ms par image.

