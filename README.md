# Indie Studio

Group members:  
- Axel Dannion 
- Axel Revel
- Matteo Gassend
- Samy Lutz
- Vincent Ferrard
- Arthur Walsh

Repo branches based on git flow

```
master
|
|\    develop
| o<--|--------- hotfix 
|/    |
|     |
|\   /|
|  o<-|--------- release
|  |  |
|   \ |
|     |
|     | \
|     |  o<----- feature
|     | /
|     |
|   /
| /
o {initial commit}
|
```

# Base Classes

```
| Global
|
| LibManag
| EventListener
| Game
| Menu
|

        | Menu
        |
        | draw()
        | EventListener
        |

        | LibManag
        |
        | device
        | scene manager
        | driver
        | gui
        |
        | updateDisplay()
        |

        | EventListener : IEventReceiver
        |
        | onEvent()
        | context
        |

        | Game
        |
        | map
        | player(s)
        | sounds
        | Menu
        | run()
        |

        | Player
        |
        | pos
        | action
        |
```

Repo organisation
```
CMakeLists.txt

.gitignore

inc
  \- *.hpp

src
  \- Class1 {dir}
    \- *.cpp
  \- Class2 {dir}
    \- *.cpp
```
