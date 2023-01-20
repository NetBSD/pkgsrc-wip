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

// [MB] 2023-01-20: Support for Rev 2.2 added
//      Description of UMAPINFO lump format:
//      https://doomwiki.org/wiki/UMAPINFO


#ifdef HAVE_LIBDOOM_UMAPINFO


#include <assert.h>
#include <stddef.h>

#include "libdoom-umapinfo-0/doom_umi.h"

#include "doomincl.h"
#include "umapinfo.h"
#include "w_wad.h"
#include "z_zone.h"


// UMAPINFO data in local format
umapinfo_t umapinfo = { NULL };


static void *UMI_Malloc(size_t memsize)
{
    return Z_Malloc(memsize, PU_STATIC, 0);
}


static void UMI_Free(void *ptr)
{
    Z_Free(ptr);
}


static void UMI_InitMapEntry(umapinfo_t *entry,
                             unsigned int episode, unsigned int map)
{
    entry->next              = NULL;

    entry->author            = NULL;
    entry->label             = NULL;
    entry->levelname         = NULL;
    entry->intertext         = NULL;
    entry->intertextsecret   = NULL;
    entry->interbackdrop     = NULL;
    entry->intermusic        = NULL;
    entry->nextmap           = NULL;
    entry->nextsecret        = NULL;
    entry->music             = NULL;
    entry->skytexture        = NULL;
    entry->levelpic          = NULL;
    entry->endpic            = NULL;
    entry->exitpic           = NULL;
    entry->enterpic          = NULL;
    entry->emenu             = NULL;
    entry->bossactions       = NULL;
    entry->episode           = episode;
    entry->map               = map;
    entry->partime           = 0;
    entry->emenu_clear       = false;
    entry->bossactions_clear = false;
    entry->nointermission    = false;
}


static void UMI_DestroyMapEntry(umapinfo_t *entry)
{
    emenu_t      *e = entry->emenu;
    bossaction_t *b = entry->bossactions;

    UMI_Free((void*) entry->author);
    UMI_Free((void*) entry->label);
    UMI_Free((void*) entry->levelname);
    UMI_Free((void*) entry->intertext);
    UMI_Free((void*) entry->intertextsecret);
    UMI_Free((void*) entry->interbackdrop);
    UMI_Free((void*) entry->intermusic);
    UMI_Free((void*) entry->nextmap);
    UMI_Free((void*) entry->nextsecret);
    UMI_Free((void*) entry->music);
    UMI_Free((void*) entry->skytexture);
    UMI_Free((void*) entry->levelpic);
    UMI_Free((void*) entry->endpic);
    UMI_Free((void*) entry->exitpic);
    UMI_Free((void*) entry->enterpic);
    while (NULL != e)
    {
        emenu_t *tmp = e->next;

        UMI_Free((void*) e->patch);
        UMI_Free((void*) e->name);
        UMI_Free((void*) e->key);
        UMI_Free(e);
        e = tmp;
    }
    while (NULL != b)
    {
        bossaction_t *tmp = b->next;

        UMI_Free(b);
        b = tmp
    }

    UMI_Free(entry);
}


static unsigned int UMI_GetNumber(doom_umi0_ts_state state)
{
    unsigned int number = 0;
    int          retval = doom_umi0_ts_value_read_number(state, &number);

    if (0 > retval)
    {
        GenPrintf(EMSG_warn, "UMAPINFO: Error while reading value (number)\n");
        number = 0;
    }

    return number;
}


// Accepts only printable ASCII characters, others are replaced with '?'
static void UMI_ConvertToASCII(char *t, const unsigned char *s, size_t len)
{
    size_t i = 0;

    for (i = 0; len > i; ++i)
    {
        if (0x20u > s[i] || 0x7Eu < s[i])
            t[i] = '?';
        else
            t[i] = s[i];
    }
}


static void UMI_ReplaceString(doom_umi0_ts_state state, const char** str)
{
    size_t               length  = 0;
    const unsigned char *qstring = NULL;
    int                  retval  = DOOM_UMI0_ERROR_NOTFOUND;

    retval = doom_umi0_ts_value_read_qstring(state, &length, &qstring);
    if (0 > retval || length + 1u)
        GenPrintf(EMSG_warn, "UMAPINFO: Error while reading value (qstring)\n");
    else
    {
        char *s = UMI_Malloc(length + 1u);

        if (NULL == s)
            GenPrintf(EMSG_warn, "UMAPINFO: Not enough memory for string\n");
        else
        {
            // libdoom-umapinfo supports arbitrary encoding for quoted strings
            UMI_ConvertToASCII(s, qstring, length);
            s[length] = 0;

            UMI_Free((void*) *str);
            *str = s;
        }
    }
}


static void UMI_ReplaceMultiString(doom_umi0_ts_state state,
                                   const char** str, size_t valcount)
{
    /* TBD */
}


static void UMI_AppendMenuEntry(doom_umi0_ts_state state,
                                emenu_t** em, size_t valcount)
{
    /* TBD */
}


static void UMI_MergeBossAction(doom_umi0_ts_state state,
                                bossaction_t** ba, size_t valcount)
{
    /* TBD */
}


static void UMI_StoreKeyData(doom_umi0_ts_state state, mapentry_t *entry)
{
    size_t key      = 0;
    int    retval   = doom_umi0_ts_key_read(state, NULL, &key);
    size_t valcount = 0;

    if (0 > retval)
    {
        GenPrintf(EMSG_warn, "UMAPINFO: Error while reading key\n");
        return;
    }

    retval = doom_umi0_ts_value_count(state, &valcount);
    if (0 > retval || 0 == valcount)
    {
        GenPrintf(EMSG_warn, "UMAPINFO: Error while reading value\n");
        return;
    }

    switch (key)
    {
        case DOOM_UMI0_KEY_AUTHOR:
            UMI_ReplaceString(state, &entry->author);
            break;
        case DOOM_UMI0_KEY_LABEL:
            UMI_ReplaceString(state, &entry->label);
            break;
        case DOOM_UMI0_KEY_LEVELNAME:
            UMI_ReplaceString(state, &entry->levelname);
            break;
        case DOOM_UMI0_KEY_INTERTEXT:
            UMI_ReplaceMultiString(state, &entry->intertext, valcount);
            break;
        case DOOM_UMI0_KEY_INTERTEXTSECRET:
            UMI_ReplaceMultiString(state, &entry->intertextsecret, valcount);
            break;
        case DOOM_UMI0_KEY_INTERBACKDROP:
            UMI_ReplaceString(state, &entry->interbackdrop);
            break;
        case DOOM_UMI0_KEY_INTERMUSIC:
            UMI_ReplaceString(state, &entry->intermusic);
            break;
        case DOOM_UMI0_KEY_NEXTMAP:
            UMI_ReplaceString(state, &entry->nextmap);
            break;
        case DOOM_UMI0_KEY_NEXTSECRET:
            UMI_ReplaceString(state, &entry->nextsecret);
            break;
        case DOOM_UMI0_KEY_MUSIC:
            UMI_ReplaceString(state, &entry->music);
            break;
        case DOOM_UMI0_KEY_SKYTEXTURE:
            UMI_ReplaceString(state, &entry->skytexture);
            break;
        case DOOM_UMI0_KEY_LEVELPIC:
            UMI_ReplaceString(state, &entry->levelpic);
            break;
        case DOOM_UMI0_KEY_ENDPIC:
            UMI_ReplaceString(state, &entry->endpic);
            break;
        case DOOM_UMI0_KEY_EXITPIC:
            UMI_ReplaceString(state, &entry->exitpic);
            break;
        case DOOM_UMI0_KEY_ENTERPIC:
            UMI_ReplaceString(state, &entry->enterpic);
            break;
        case DOOM_UMI0_KEY_EPISODE:
            UMI_AppendMenuEntry(state, &entry->emenu, valcount);
            entry->emenu_clear = false;
            break;
        case DOOM_UMI0_KEY_BOSSACTION:
            UMI_MergeBossAction(&entry->bossactions, valcount);
            entry->bossactions_clear = false;
            break;
        case DOOM_UMI0_KEY_PARTIME:
            entry->partime = UMI_GetNumber(state);
            break;
        case DOOM_UMI0_KEY_NOINTERMISSION:
            entry->nointermission = UMI_GetNumber(state) ? true : false;
            break;
        default:
            GenPrintf(EMSG_warn, "UMAPINFO: Unknown key ignored\n");
            break;
    }
}


static mapentry_t *UMI_GetMapEntry(unsigned int episode, unsigned int map)
{
    mapentry_t *entry      = umapinfo.entry;
    mapentry_t *entry_last = NULL;

    while (NULL != entry)
    {
        entry_last = entry;
        if (episode == entry->episode && map == entry->map)
            break;

        entry = entry->next;
    }

    if (NULL == entry)
    {
        // Not found, create new entry
        entry = UMI_Malloc(sizeof(mapentry_t));
        if (NULL != entry)
        {
            UMI_InitMapEntry(entry, episode, map);
            if (NULL == umapinfo.entry)
                umapinfo.entry = entry;
            else
                entry_last->next = entry;
        }
    }

    return entry;
}


static void UMI_MergeMapEntry(doom_umi0_ts_state state)
{
    mapentry_t   *entry   = NULL
    unsigned int  episode = 0;
    unsigned int  map     = 0;
    int           retval  = doom_umi0_ts_map_read(state, &episode, &map);

    if (0 <= retval)
        entry = UMI_GetMapEntry(episode, map);

    if (NULL == entry)
        retval = DOOM_UMI0_ERROR_NOTFOUND;
    else
    {
        size_t keycount = 0;

        retval = doom_umi0_ts_key_count(state, &keycount);
        while (0 <= retval && keycount)
        {
            UMI_StoreKeyData(state, entry);

            if (--keycount)
                retval = doom_umi0_ts_key_next(state);
        }
    }

    if (0 > retval)
        GenPrintf(EMSG_warn, "UMAPINFO: Error while importing keys\n");
}


static void UMI_ImportUMapInfo(umapinfo *umi, doom_umi0_handle data)
{
    doom_umi0_ts_state state    = NULL;
    size_t             mapcount = 0;  // Number of toplevel map entries
    int                retval   = doom_umi0_ts_state_create(&state, data);

    if (0 <= retval)
        retval = doom_umi0_ts_map_count(state, &mapcount);

    while (0 <= retval && mapcount)
    {
        UMI_MergeMapEntry(state);

        if (--mapcount)
            retval = doom_umi0_ts_map_next(state);
    }

    doom_umi0_ts_state_destroy(&state);

    if (0 > retval)
        GenPrintf(EMSG_warn, "UMAPINFO: Error while importing map entry\n");
}


void UMI_LoadUMapInfoLump(lumpnum_t lumpnum)
{
    doom_umi0_handle  data = NULL; // libdoom-umapinfo UMAPINFO object handle
    int               len  = W_LumpLength(lumpnum);

    assert(0 <= len);

    {
        int            retval  = DOOM_UMI0_ERROR_MEMORY;
        unsigned char *lump    = UMI_Malloc(len);
        size_t         length  = len;
        int            verbose = 0;

        if (NULL != lump)
        {
            W_ReadLump(lumpnum, lump);
            retval = doom_umi0_create(&data, lump, length, verbose);
            UMI_Free(lump);
        }
        if (0 > retval)
            GenPrintf(EMSG_warn, "UMAPINFO: Parsing data failed\n");
        else if (0 < retval)
            GenPrintf(EMSG_warn, "UMAPINFO: Warning: Data may be incomplete\n");

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
    GenPrintf(EMSG_warn, "UMAPINFO: Ignored (libdoom-umapinfo is required)\n");
}


#endif  // HAVE_LIBDOOM_UMAPINFO
