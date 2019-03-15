# Dragon Nest Borderless
DLL Created to change Dragon Nest mode to borderless automatically on launch

# How to use
Download the DLLs from (https://github.com/i3dprogrammer/DNBorderless/releases/download/1.0/Borderless.rar)[here] and then extract them in your Dragon Nest directory, and replace files.

# How it works
The game loads `bdvid32.dll` when it starts, so we simply change the original `bdvid32.dll` to `bdvid32_2.dll` and rename our dll to `bdvid32.dll`
this way the game loads our DLL instead of the original one.

The game on launch calls `CreateBandiVideo2` from `bdvid32.dll`, we simply export the function with the same paramters from our modified DLL and change
the current window mode.

# Credits
The idea is from DNModder.
