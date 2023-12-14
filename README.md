[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/XUCedPox)
# marczaku-214-design-patterns-assignment

You need to help Pikachu collect apples for an undesclosed reason. Use your left right buttons to move em around and catch those red fruits!
But be carefull, you loose if one falls all the way down!

We used a Game loop in spirit of the unity one \(Start, Update, Render) to give all the objects functions that they could implement their own way.
This was simply implemented with a vector of gameobjects that we ran through running the functions in the correct places in the main loop.

Second pattern we used was an object pool for the apples to avoid having to make new ones constantly instead of just moving them to the top of the screen when collected.
