# Hotline Miami 2: Wrong Number XP Support Patch

Before Hotline Miami 2 was released, the official system requirements for the game listed Windows XP as being
compatible with the game. Though at the time of release, it turned out that posted requirements in fact came from
the first installment of Hotline Miami. As a result, the game cannot run on XP and users who preordered the came are
not able to play now.

I decided to make some quick research around the issue and it turned out re-adding XP support is not terribly hard.
This unofficial patch aims to make the game playable on XP.

**NOTE: As of 17.03, this patch has been officially endorsed by Abstraction Games!**

### Compiling Requirements

* Visual Studio 2010 or newer

### Known Issues

When the game runs in DirectX 9 mode, it crashes on device lost. To minimize the negative impact of this issue,
the game is now forced to run in borderless windowed mode, so it still appears to be fullscreen, but cannot
be minimized like regular fullscreen applications.
The game will STILL crash when applying changes to any Graphics settings. Don't worry, despite the crash, all the
changes got applied! When you launch the game again, the settings will be changed.