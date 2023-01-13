//----------------------------------------------------------------------------
//
// Copyright(C) 2023 by DooM Legacy Team
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//      Support maps with additional information in UMAPINFO format.
//
//----------------------------------------------------------------------------

#ifndef UMAPINFO_H
#define UMAPINFO_H

#include "doomtype.h"


typedef struct
{
    int thing;    // Thing type
    int special;  // Line special type
    int tag;      // Sector tag
} bossaction_t;


// UMAPINFO data for a single map
typedef struct
{
    unsigned int  episode;
    unsigned int  map;

    char         *levelname;
    char         *label;
    char         *intertext;
    char         *intertextsecret;
    char         *levelpic;
    char         *nextmap;
    char         *nextsecret;
    char         *music;
    char         *skytexture;
    char         *endpic;
    char         *exitpic;
    char         *enterpic;
    char         *interbackdrop;
    char         *intermusic;
    bossaction_t *bossactions;
    unsigned int  numbossactions;
    unsigned int  partime;
    boolean       nointermission;
} mapentry_t;


typedef struct
{
  mapentry_t   *map;
  unsigned int  mapnum;
} umapinfo_t;


extern umapinfo_t umapinfo;


void UMI_LoadUMapInfoLump(lumpnum_t lumpnum);


#if 0
extern boolean EpiCustom;
mapentry_t *G_LookupMapinfo(int episode, int map);

boolean UMI_CheckField(char *str);
#endif


#endif  // UMAPINFO_H
