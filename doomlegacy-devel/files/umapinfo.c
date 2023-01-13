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
//
// [MB] 2023-01-10: Description of UMAPINFO lump format:
//      https://doomwiki.org/wiki/UMAPINFO


#ifdef HAVE_LIBDOOM_UMAPINFO


#include <assert.h>
#include <stddef.h>

#include "libdoom-umapinfo-0/doom_umi.h"  // libdoom-umapinfo

#include "doomincl.h"
#include "umapinfo.h"
#include "w_wad.h"
#include "z_zone.h"


// UMAPINFO data in local format
umapinfo_t umapinfo = { NULL, 0 };


// Initialize map entry
static void UMI_InitializeMapEntry(umapinfo_t *entry,
                                   unsigned int episode, unsigned int map)
{
    entry->episode         = episode;
    entry->map             = map;

    entry->levelname       = NULL;
    entry->label           = NULL;
    entry->intertext       = NULL;
    entry->intertextsecret = NULL;
    entry->levelpic        = NULL;
    entry->nextmap         = NULL;
    entry->nextsecret      = NULL;
    entry->music           = NULL;
    entry->skytexture      = NULL;
    entry->endpic          = NULL;
    entry->exitpic         = NULL;
    entry->enterpic        = NULL;
    entry->interbackdrop   = NULL;
    entry->intermusic      = NULL;
    entry->bossactions     = NULL;
    entry->numbossactions  = 0;
    entry->partime         = 0;
    entry->nointermission  = false;
}


// Populate map entry
static int UMI_PopulateMapEntry(doom_umi0_ts_state state, size_t index)
{
    unsigned int episode, map;
    int          res = doom_umi0_ts_map_read(state, &episode, &map);

    if (0 == res)
    {
        UMI_InitializeMapEntry(&umapinfo.map[index], episode, map);

        rets = doom_umi0_ts_key_first(state);
        while (0 == retval)
        {
XXX Insert key data
            res = doom_umi0_ts_key_next(state);
        }
    }

    // Only count successfully populated maps
    if (0 == res)
    {
        ++umapinfo.mapnum;
    }
}


// Import UMAPINFO data
static void UMI_ImportUMapInfo(umapinfo *umi, doom_umi0_handle data)
{
    doom_umi0_ts_state state  = NULL;
    int                retval = doom_umi0_ts_state_create(&state, data);

    if (0 > retval)
        GenPrintf(EMSG_warn, "Importing UMAPINFO data failed\n");
    else
    {
        size_t mapnum  = doom_umi0_ts_map_count(state);
        size_t memsize = sizeof(umapinfo_t) * mapnum;
        size_t i       = 0;

        assert(memsize / mapnum == mapnum);
        umapinfo.map    = Z_Malloc(memsize, PU_LEVEL, 0);
        umapinfo.mapnum = 0;

        retval = doom_umi0_ts_map_first(state);
        while (0 == retval && mapnum)
        {
            retval = UMI_PopulateMapEntry(state, i++);
            if (0 == retval)
                retval = doom_umi0_ts_map_first(state);
        }
    }

    doom_umi0_ts_state_destroy(&state);
}


// Load and parse UMAPINFO lump
void UMI_LoadUMapInfoLump(lumpnum_t lumpnum)
{
    doom_umi0_handle  data = NULL; // libdoom-umapinfo UMAPINFO object handle
    int               len  = W_LumpLength(lumpnum);

    assert(0 <= len);

    {
        unsigned char *lump    = Z_Malloc(len, PU_IN_USE, 0);
        size_t         length  = len;
        int            verbose = 0;
        int            retval  = doom_umi0_create(&data, lump, length, verbose);

        W_ReadLump(lumpnum, lump);

        if (0 > retval)
            GenPrintf(EMSG_warn, "Parsing UMAPINFO data failed\n");
        else if (0 < retval)
            GenPrintf(EMSG_warn, "Error in UMAPINFO, data may be incomplete\n");

        Z_Free(lump);

        if (0 <= retval)
            UMI_ImportUMapInfo(&umapinfo, data);

        doom_umi0_destroy(&data);
    }
}


#else  // HAVE_LIBDOOM_UMAPINFO


#include "doomincl.h"


// Stub if libdoom-umapinfo is not available
void UMI_LoadUMapInfoLump(lumpnum_t lumpnum)
{
    GenPrintf(EMSG_warn, "UMAPINFO ignored (libdoom-umapinfo not available)\n");
}


#endif  // HAVE_LIBDOOM_UMAPINFO
