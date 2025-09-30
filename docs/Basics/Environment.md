[go back](../../README.md)

# Coding Environment

If you are on windows or mac, I recommend to use a virtual Linux system via docker together with Visual Studio Code and `Dev Container Extension`. On Linux you can freely choose an IDE.

Contents
- <a href="#ide_">Using an IDE</a>
- <a href="#vs_">IDE and Compiler in one (Visual Studio)</a>

<br><br>


---
<h3><a href='top' name='ide_'>Using an IDE</a></h3>

There are many IDEs for C++ out there. I recommend VSCode or for a few more features Eclipse.<br>
VSCode can be used right away with maybe a C/C++ extension.

When using VSCode you can download the IDE from the [official website](https://code.visualstudio.com/download). Then I recommend following packages:
- `C/C++`
- `C/C++ Extension`
- `CMake`
- `c-testmate`
- `Remote - SSH`
- `Container Tools`
- `Dev Containers`
- `Docker`
- `Project Manager` (Alessandro Fragnani)

If you want to use VSCode on Windows and Mac and want to compile your C++ Code on linux, you can start a virtual linux system as a docker container and can connect your VSCode with that container. [This recommended environment setup is described in detail here](VSCode_Linux_Container.md).


<br><br>

For eclipse see this:


For installation on Windows:
1. Go to https://www.eclipse.org/downloads/
2. Download the windows installer for Eclipse desktop
3. Follow the instructions of the installer and make sure to choose C/C++ Developement.



For installation on Linux:
```terminal
sudo apt update
sudo apt install eclipse-cdt
```


If you want to use git and github, make sure to go to developer settings and to personal access tokens. There you can create a new token with a name and a password/token. This is needed from Eclipse to authentificate with your account and only so you can use eclipse with git/github. Your normal user name and password will not work.

Install CMake addon: On 'Help \> Eclipse Marketplace' search for 'CMake' and install the CMake Editor.

Next another important step is to add MinGW32 to Eclipse. For that open *Window* \> *Preferences* \> *C/C++* \> *Core Build*. There you can add MinGW -> add the path to the gcc.exe in the bin folder. 

For adding a C++ Project you can go to 'File \> Import' and select 'General \> File from Folder' or from 'Git \> Project from Git'.

You can detect nested projects by right clicking on your top project folder in the Project Explorer. Then choose *Configure* and *Configure and Detect nested Projects*. Now your subproject should be detected as C++ Project and you should be able to run it (it should use your CMakeLists.txt file). You may have to click on the ⚙️ icon on your build name on the right of the run button and there you can change the compiler to mingw32 if you already add it (like described previously). Now you should be able to run your program in Eclipse! Else you can use your terminal (CMD)/bat file.


<br><br>

---
<h3><a href='top' name='vs_'>IDE and Compiler in one</a></h3>

If you does not want to compile your code on a low level by "yourself" with mingw, cmake and a bat file and want to use an IDE for more than only a texteditor, then **Visual Studio** is an option and a common way on Windows to create C++ Code!<br>
To be clear: the low level way is great to do and works fine but the integration in an IDE (like Eclipse) often seems to not fully work and it is more recommended to do so once and to seeing the compiling process, but then offers no comfort and therefore switching to an IDE with an integrated C++ compiler is a good idea.

> I do not recommend you to use Visual Studio due to the not standard compiler and the sometimes strange handlings from this IDE. I recommend (as said on top) to use docker to have a virtual linux which can be connected with VSCode.

**Installation**<br>
Installation is easy:
1. Go to the [Visual Studio website](https://visualstudio.microsoft.com/de/downloads/) and download the installer
2. Follow the installer and choose something like 'Desktop Developement with C++' all other add-ons are most likely not needed (but choose as you wish)
3. Set your installation path (most likely: D:/ or C:/ Visual Studio/2022/Community, Visual Studio/Packages, Visual Studio/Shared)

And you are finish.

Now you can create new C++ projects with Visual Studio.

**Creating new C++ Projects**<br>
Create a new empty C++ project with Visual Studio and name the project likeyou want + make sure to check the box to include the projectmap file and the project itself to one folder. Now ther should be following files and folder (the name can vary but you should be able to found them):
```text
Project_Name
----| External Libs
----| Header Files
----| Source Files
----| Ressource Files
```
The structure should be self explainable and well structured. Most likely first you want to make a *main.cpp* in the Source folder and yeah that its.

**Importing External Libs**<br>
It is recommend to create one folder on your PC with all external C++ libs. Like on *D:/cpplibs* or something like that.

*Additional Include Directories*<br>Right click on your project name in the explorer of visual studio: *Properties* \> *C/C++* \> *General* \> *Additional Including Paths* and add there the path to the including folder (to the folder where the header files are). <br>Example:

``````
D:\CPPlibs\GLFW\include
D:\CPPlibs\GLM
D:\CPPlibs\VulkanSDK\1.4.304.1\Include
``````

or relative if you copied the lib in a libs folder in your project:

``````
$(SolutionDir)/libs/GLFW/include
$(SolutionDir)/libs/GLM
$(SolutionDir)/libs/VulkanSDK/1.4.304.1/Include
``````



> Important note: You should make sure to hit 'Configurations' on the top left corner to 'all' 



*Additional Library Directories*<br>Staying in the project properties go to *Properties* \> *Linker* \> *Input* \> *Additional External Libraries Paths* and there the path to the folder where the .lib, .dll, .a files are stored.<br>Example:

```
D:\CPPlibs\VulkanSDK\1.4.304.1\Lib
D:\CPPlibs\GLFW\lib-vc2022
```

or relative if you copied the lib in a libs folder in your project:

```
$(SolutionDir)/libs/VulkanSDK/1.4.304.1/Lib
$(SolutionDir)/libs/GLFW/lib-vc2022
```





*Additional Dependencies*<br>Lastly click on *Properties* \> *Linker* \> *General* \> *Additional Dependencies* and add just the name of the lib files.<br>Example:

```
vulkan-1.lib
glfw3.lib
```


The specific names can vary due to language or updates, but the meaning stays the same.

Now the import of the external libs should be working!


**Importing External Projects**<br>
Importing  your own custom C++ project and transform it into an Visual Studio Project is quite weird, but there is a simple way. 
1. Just copy all your project files into an new folder and delte the olds and also the top folder. 
2. Create a new empty C++ project with Visual Studio and name the project like your top folder name was + make sure to check the box to include the projectmap file and the project itself to one folder. 
3. You have to create every source file and header file new in Visual Studio and then copy and paste the code in the new file. Drag and drop the files will only link the path to these files! BE careful and make it the longer but more secure way as described.
4. Add now your external libraries as describes in the section before.

Now you should be fine!









