% Facts
american(robert).
is_enemy(countryA).
has_missiles(countryA).
sold_to(robert, countryA).

% Rules
has_weapons(X) :- has_missiles(X).

criminal(X) :- american(X),
               sold_to(X, Y), 
               is_enemy(Y),
               has_weapons(Y).
