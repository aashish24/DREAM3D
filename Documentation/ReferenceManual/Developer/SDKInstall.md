Installing the DREAM.3D SDK {#sdk_install}
========
<a name="prerequisites">
## Prerequisites ##
</a>

These prerequisites need to be completed before installing the DREAM.3D SDK.

If you have already fulfilled all of these prerequisites, skip to the [Install the DREAM.3D SDK](#install_sdk) section.

<a name="compiler_suite">
### Install a Compiler Suite ###
</a>

A compatible compiler needs to be installed on your system to be able to build DREAM.3D.

For more information, please visit [Installing a Compiler Suite](@ref compiler_suite).

<a name="downloading_dream3d">
### Download the Source Code for DREAM.3D ###
</a>

The source code for DREAM.3D must be downloaded using Git.

For more information, please visit [Downloading the Source Code for DREAM.3D](@ref source_download).

<a name="install_sdk">
## Install the DREAM.3D SDK ##
</a>

It is **strongly recommended** that developers of DREAM.3D use the Superbuild build system to install the DREAM.3D SDK.

Otherwise, developers can download and install each dependency manually.

### Using the Superbuild build system ###

This is a CMake based build system that uses CMake to drive the creation of the SDK. The Superbuild can run on Windows, OS X and Linux systems.

**Note**: All of DREAM.3D's dependent libraries, including a prebuilt version of Qt 5.6.x, will be automatically downloaded and compiled during this process and may take a while to complete.

Please visit the [DREAM.3D Superbuild](http://www.github.com/bluequartzsoftware/DREAM3DSuperBuild) Github page to download the Superbuild build system.

After downloading, open the Help documentation inside the Superbuild's directory for more information on how to build a DREAM.3D SDK using the Superbuild.  There are separate help documents for Windows, OS X, and Linux.

### Alternate Installation Method - Downloading and Installing External Dependencies Manually ###

**This section is only used if compiling an SDK from scratch instead of using the Superbuild method above!  BlueQuartz Software does not officially support this method of SDK installation.**

DREAM.3D depends on several 3rd party libraries to be installed and ready to link against. This section will detail the needed libraries and utilities and where to obtain them or how to compile them.  This is the recommended order of installation.

|  Package   | Minimum Version | Download Location |
|  ------	| ------	| ------	|
| Git | 2.8.x | [http://www.git-scm.com](http://www.git-scm.com) |
| CMake | 3.5.1 | [http://www.cmake.org/cmake/resources/software.html](http://www.cmake.org/cmake/resources/software.html) |
| Doxygen | 1.8.11 | [http://www.stack.nl/~dimitri/doxygen/download.html](http://www.stack.nl/~dimitri/doxygen/download.html) |
| HDF5 | 1.8.16 | [http://www.hdfgroup.org/HDF5/release/obtain5.html](http://www.hdfgroup.org/HDF5/release/obtain5.html) |
| Boost | 1.60.0 | [http://www.boost.org](http://www.boost.org) |
| Eigen | 3.2.8 | [Eigen Home Page](http://eigen.tuxfamily.org/index.php?title=Main_Page) |
| Intel Threading Building Blocks | tbb44\_20151115oss | [http://threadingbuildingblocks.org/download](http://threadingbuildingblocks.org/download) |
| Qt | 5.6.2 (Qt 4.x will NOT work) |  The developer should obtain a precompiled package from [http://www.qt.io](http://www.qt.io) and install that version rather than trying to compile Qt itself. Visual Studio uses should get Qt 5.6.2 at the minimum.  |
| Qwt | 6.1.2 | Obtain from [https://sourceforge.net/projects/qwt/files](https://sourceforge.net/projects/qwt/files) |
| ITK | 4.9.1 | [ITK.org](http://www.itk.org) 4.9.1 is the earliest version compatible with HDF5 1.8.16 |

---
**Next Page (Windows)**: [Configuring and Building DREAM.3D on Windows](@ref windows_configure_and_build_dream3d).

**Next Page (OS X)**: [Configuring and Building DREAM.3D on Mac OS X](@ref osx_configure_and_build_dream3d).

**Next Page (Linux)**: [Configuring and Building DREAM.3D on Linux](@ref linux_configure_and_build_dream3d).

**Previous Page**: [Downloading the Source Code for DREAM.3D](@ref source_download).

