# Sortie de la configuration Debug :
```
Resultat : 1.23995e+07
Temps de calcul : 164.207 ms
```

# Sortie de la configuration Release :
```
Resultat : 1.23995e+07
Temps de calcul : 171.846 ms
```

# Rapport de Mesure des performances en Debug et Release


## 1. Expérience

Le programme effectue plusieurs millions d'opérations mathématiques, notamment avec les fonctions `sin()` et `sqrt()`. Le temps d'exécution est mesuré avec `std::chrono`.

Le même programme a été compilé dans les deux configurations.

## 2. Résultats

| Configuration | Temps d'exécution |
| ------------- | ----------------: |
| Debug         |        164,207 ms |
| Release       |        171,846 ms |

Les deux exécutables produisent le même résultat numérique :

```text
1.23995e+07
```

Cela permet de vérifier que le calcul effectué est le même dans les deux configurations.

## 3. Comparaison avec le budget de 11 ms

Une image de casque dure environ 11 ms.

En Debug :

```text
164,207 ms > 11 ms
```

Le calcul dépasse donc le budget de :

```text
164,207 - 11 = 153,207 ms
```

En Release :

```text
171,846 ms > 11 ms
```

Le calcul dépasse donc le budget de :

```text
171,846 - 11 = 160,846 ms
```

Les deux configurations dépassent largement le budget de 11 ms.

## 4. Quelle mesure aurait conduit à une mauvaise décision ?

Dans cette expérience, aucune des deux mesures n'aurait conduit à une mauvaise décision concernant le budget de 11 ms, car les deux mesures montrent que le calcul dépasse ce budget.

La mesure Debug est de 164,207 ms et la mesure Release de 171,846 ms. Elles conduisent donc toutes les deux à la même conclusion : le calcul est trop long pour tenir dans une image de 11 ms.

## 5. Conclusion

Le calcul testé ne respecte pas le budget de 11 ms dans les deux configurations. La version Release mesurée ici est légèrement plus lente que la version Debug, ce qui montre qu'une différence de performance ne doit pas être supposée sans effectuer une mesure réelle.


