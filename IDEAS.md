# Entities
### WHAT:
Base game object, all entities must be created within a Scene derived class

# Scene
### WHAT:
A Scene is an entire level and keeps track of everything related to that level
      Draw calls are made inside the Scene

### WHY:
Easy referencing, loading and unloading of resources

# SceneManager
#### WHAT:
Holds references to every Scene. Provides load/unload functionality, knows which Scene is currently active

### WHY: 

### IMPLEMENTATION:

### FUNCTIONALITY:
- Function to draw the currenly active Scene
- Function to switch active Scene
- Function to get the name of a given Scene
- Function to get the name of the currently active Scene
# SceneGraph

# Rationale