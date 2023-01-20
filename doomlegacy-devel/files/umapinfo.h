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
//      Support for additional map information in UMAPINFO format.
//
//----------------------------------------------------------------------------

#ifndef UMAPINFO_H
#define UMAPINFO_H

#include "doomtype.h"


// Entry for episode menu
typedef struct
{
    emenu_t    *next;

    const char *patch;  // Used only if valid for all menu entries
    const char *name;   // Episode name (used with HUD font without patch)
    const char *key;    // Keyboard key
} emenu_t;


// Usable only for monsters that call A_BossDeath
typedef struct
{
    bossaction_t *next;

    int           thing;    // Thing type
    int           special;  // Line special type
    int           tag;      // Sector tag
} bossaction_t;


typedef struct
{
    mapentry_t   *next;

    const char   *author;
    const char   *label;              // NULL: default, Empty: clear
    const char   *levelname;
    const char   *intertext;          // NULL: default, Empty: clear
    const char   *intertextsecret;    // NULL: default, Empty: clear
    const char   *interbackdrop;
    const char   *intermusic;
    const char   *nextmap;
    const char   *nextsecret;
    const char   *music;
    const char   *skytexture;
    const char   *levelpic;
    const char   *endpic;
    const char   *exitpic;
    const char   *enterpic;
    emenu_t      *emenu;              // Linked list
    bossaction_t *bossactions;        // Linked list
    unsigned int  episode;
    unsigned int  map;
    unsigned int  partime;
    boolean       emenu_clear;        // Clear all default episode menu entries
    boolean       bossactions_clear;  // Clear all default boss actions
    boolean       nointermission;     // Skip the 'level finished' screen
} mapentry_t;


typedef struct
{
    mapentry_t *entry;  // Linked list
} umapinfo_t;


// Current UMAPINFO data
extern umapinfo_t umapinfo;


// Import UMAPINFO lump
// If some keys are already present in current data, they are overwritten
void UMI_LoadUMapInfoLump(lumpnum_t lumpnum);


#endif  // UMAPINFO_H
