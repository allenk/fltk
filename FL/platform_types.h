/*
 * "$Id: platform_types.h 11467 2016-03-29 19:41:14Z manolo $"
 *
  * Copyright 2016 by Bill Spitzak and others.
 *
 * This library is free software. Distribution and use rights are outlined in
 * the file "COPYING" which should have been included with this file.  If this
 * file is missing or damaged, see the license at:
 *
 *     http://www.fltk.org/COPYING.php
 *
 * Please report all bugs and problems on the following page:
 *
 *     http://www.fltk.org/str.php
 */

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/* Platform-dependent types are defined here
 These types must be defined by any platform:
 Fl_Offscreen, Fl_Bitmask, Fl_Region, FL_SOCKET, struct dirent, struct stat
 */

#ifdef __APPLE__
typedef struct CGContext* Fl_Offscreen;
typedef struct CGImage* Fl_Bitmask;
typedef struct flCocoaRegion* Fl_Region;
typedef int FL_SOCKET;
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#elif defined(WIN32)
typedef struct HBITMAP__ *HBITMAP;
typedef HBITMAP Fl_Offscreen;
typedef HBITMAP Fl_Bitmask;
typedef struct HRGN__ *Fl_Region;
# if defined(_WIN64)
typedef  unsigned __int64 FL_SOCKET;
# else
typedef  int FL_SOCKET;
# endif
#include <sys/stat.h>
struct dirent {char d_name[1];};

#elif defined(FL_PORTING)
# pragma message "FL_PORTING: define OS-dependent types"
typedef void* Fl_Offscreen;
typedef void* Fl_Bitmask;
typedef void *Fl_Region;
typedef int FL_SOCKET;
# pragma message "FL_PORTING: define struct dirent and implement scandir() for the platform"
struct dirent {char d_name[1];};
# pragma message "FL_PORTING: define struct stat and implement stat() for the platform"
struct stat { /* the FLTK source code uses part of the stat() API */
  unsigned st_mode;
  off_t st_size;
};
#define        S_IFMT   0170000  /* type of file */
#define        S_IFIFO  0010000  /* named pipe (fifo) */
#define        S_IFCHR  0020000  /* character special */
#define        S_IFDIR  0040000  /* directory */
#define        S_IFBLK  0060000  /* block special */
#define        S_IFREG  0100000  /* regular */
#define        S_IFLNK  0120000  /* symbolic link */

#else
typedef unsigned long Fl_Offscreen;
typedef unsigned long Fl_Bitmask;
typedef struct _XRegion *Fl_Region;
typedef int FL_SOCKET;
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#endif /* __APPLE__ */

#endif /* PLATFORM_TYPES_H */

/*
 * End of "$Id: platform_types.h 11467 2016-03-29 19:41:14Z manolo $".
 */