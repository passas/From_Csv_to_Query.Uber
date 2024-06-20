## From CSV to Query - Uber

```
> Erase technical debt;
  - csv.c:94
    - invalid column format -> empty string -> struct empty field -> seg.fault or fault behaviour;
    + raise flag from each invalid field (token) -> handle as intended.
```
