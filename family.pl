% Define family relationships
parent(john, mary).
parent(john, jim).
parent(mary, ann).
parent(mary, peter).
parent(peter, susan).

% Define rules for relationships
ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).
