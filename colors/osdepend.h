/******************************************************************************
* @file 
* @author Simon
*
* @brief Conditional compiling for project.
*
* @section DESCRIPTION
*
* This determines the current OS that the project is being compiled so that
* dependencies which conflict on different OSs are taken care of here.
* For example printing in color is a problem when writing code in Linux,
* or in windows.
******************************************************************************/


// ----==== OS Dependent Compilation... ====----
#ifdef WINDOWS
	#include "wcolors.h"    // personal header with function to implement color in a windows cmd prompt
#elif defined(WIN32)
	#include "wcolors.h"    // personal header with function to implement colir in a windows cmd prompt
#elif defined(linux)
	#include "lcolors.h"    // personal header with function to implement color in a linux terminal
#else
	#include "lcolors.h"		// don't know what the name of mac is. Therefore I'm just doing an else
#endif
