3DGameEngineCpp
==
A 3D Game Engine

##Build Dependencies##
- [GLEW](http://glew.sourceforge.net/)
- [SDL2](http://www.libsdl.org/)
- [ASSIMP](http://assimp.sourceforge.net/)

##Using the Engine##
###Entities###
Entities are what you see.

###Components###
Components are how you interact with an entity.

###Scene Graph###
The scene graph allows entities to inherit properties from their parents.

- If a parent entity is rotated, all of its children are also rotated.
- If a child entity of rotated, its parent is not rotated.