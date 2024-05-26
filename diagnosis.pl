% Define the symptoms for each condition
symptom(cold, sneezing).
symptom(cold, runny_nose).
symptom(cold, cough).
symptom(flu, fever).
symptom(flu, chills).
symptom(flu, fatigue).
symptom(allergies, itchy_eyes).
symptom(allergies, sneezing).
symptom(allergies, runny_nose).

% Define rules for diagnosing the conditions based on symptoms
diagnose(X, cold) :- 
    symptom(X, sneezing),
    symptom(X, runny_nose),
    symptom(X, cough).

diagnose(X, flu) :- 
    symptom(X, fever),
    symptom(X, chills),
    symptom(X, fatigue).

diagnose(X, allergies) :- 
    symptom(X, itchy_eyes),
    symptom(X, sneezing),
    symptom(X, runny_nose).

% Query to diagnose a condition based on symptoms
diagnose_condition(Symptoms, Condition) :-
    findall(X, (member(Symptom, Symptoms), diagnose(Symptom, X)), Conditions),
    list_to_set(Conditions, UniqueConditions),
    length(UniqueConditions, NumConditions),
    NumConditions = 1,
    nth0(0, UniqueConditions, Condition).

% Example usage:
% diagnose_condition([fever, chills, fatigue], Condition).
