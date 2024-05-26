% Symptoms of plants
has_symptom(plant1, yellow_leaves).
has_symptom(plant1, wilting).
has_symptom(plant2, brown_spots).
has_symptom(plant2, leaf_drop).
has_symptom(plant3, stunted_growth).
has_symptom(plant3, yellow_leaves).
has_symptom(plant4, white_powder).
has_symptom(plant4, wilting).

% Diagnosis rules
diagnose_plant(Plant, nitrogen_deficiency) :-
    has_symptom(Plant, yellow_leaves),
    has_symptom(Plant, stunted_growth).

diagnose_plant(Plant, fungal_infection) :-
    has_symptom(Plant, brown_spots),
    has_symptom(Plant, leaf_drop).

diagnose_plant(Plant, powdery_mildew) :-
    has_symptom(Plant, white_powder),
    has_symptom(Plant, wilting).

diagnose_plant(Plant, underwatering) :-
    has_symptom(Plant, yellow_leaves),
    has_symptom(Plant, wilting).

diagnose_plant(_, unknown).

% Example queries
% ?- diagnose_plant(plant1, X).
% X = underwatering.

% ?- diagnose_plant(plant2, X).
% X = fungal_infection.

% ?- diagnose_plant(plant3, X).
% X = nitrogen_deficiency.

% ?- diagnose_plant(plant4, X).
% X = powdery_mildew.
