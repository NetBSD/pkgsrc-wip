// -----------------------------------------------------------------------------
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
// -----------------------------------------------------------------------------

// [MB] 2023-01-21: Support for Rev 2.2 added
//      Description of UMAPINFO lump format:
//      https://doomwiki.org/wiki/UMAPINFO


#ifdef HAVE_LIBDOOM_UMAPINFO


#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "libdoom-umapinfo-1/doom_umi.h"

#include "dehacked.h"
#include "doomincl.h"
#include "doomstat.h"
#include "p_info.h"
#include "umapinfo.h"
#include "w_wad.h"
#include "z_zone.h"


// Internal representation of UMAPINFO data (merged from PWADs)
umapinfo_t umapinfo = { NULL, NULL, false };


// -----------------------------------------------------------------------------
// Memory management

static void *UMI_Malloc(size_t memsize)
{
    return Z_Malloc(memsize, PU_STATIC, 0);
}


static void UMI_Free(void *ptr)
{
    if (NULL != ptr)
        Z_Free(ptr);
}


// -----------------------------------------------------------------------------
// Constructors and destructors

static void UMI_InitEpisodeMenuEntry(emenu_t *entry)
{
    entry->next  = NULL;

    entry->patch = NULL;
    entry->name  = NULL;
    entry->key   = NULL;
}


static void UMI_DestroyEpisodeMenu(emenu_t *entry)
{
    while (NULL != entry)
    {
        emenu_t *tmp = entry->next;

        UMI_Free((void*) entry->patch);
        UMI_Free((void*) entry->name);
        UMI_Free((void*) entry->key);
        UMI_Free(entry);
        entry = tmp;
    }
}


static void UMI_InitBossActionEntry(bossaction_t *entry)
{
    entry->next    = NULL;

    entry->thing   = 0;
    entry->special = 0;
    entry->tag     = 0;
}


static void UMI_DestroyBossActions(bossaction_t *entry)
{
    while (NULL != entry)
    {
        bossaction_t *tmp = entry->next;

        UMI_Free(entry);
        entry = tmp;
    }
}


static void UMI_InitMapEntry(mapentry_t *entry,
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
    entry->exitpic           = NULL;
    entry->enterpic          = NULL;
    entry->endpic            = NULL;
    entry->bossactions       = NULL;
    entry->endgame           = unchanged;
    entry->episode           = episode;
    entry->map               = map;
    entry->partime           = 0;
    entry->bossactions_clear = false;
    entry->nointermission    = false;
    entry->endbunny          = false;
    entry->endcast           = false;
}


static void UMI_DestroyMaps(mapentry_t *entry)
{
    while (NULL != entry)
    {
        mapentry_t *tmp = entry->next;

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
        UMI_Free((void*) entry->exitpic);
        UMI_Free((void*) entry->enterpic);
        UMI_Free((void*) entry->endpic);
        UMI_DestroyBossActions(entry->bossactions);
        UMI_Free(entry);
        entry = tmp;
    }
}


// -----------------------------------------------------------------------------
// Access functions for key values

// On error, 0 is returned
static unsigned int UMI_GetNumber(doom_umi1_ts_state state)
{
    unsigned int number = 0;
    int          retval = doom_umi1_ts_value_read_number(state, &number);

    if (0 > retval)
    {
        GenPrintf(EMSG_warn, "UMAPINFO: Error while reading value (number)\n");
        number = 0;
    }

    return number;
}


// On error, NULL is returned (and nothing is written via 'len')
// On success a pointer to the string is returned
// A termination with NUL is appended, but not counted for 'len'
// Attention: libdoom-umapinfo supports arbitrary encodings for quoted strings,
// the result must be post-processed!
static char *UMI_GetQString(doom_umi1_ts_state state, size_t *len)
{
    char                *result  = NULL;
    size_t               length  = 0;
    const unsigned char *qstring = NULL;
    int                  retval  = DOOM_UMI1_ERROR_NOTFOUND;

    retval = doom_umi1_ts_value_read_qstring(state, &length, &qstring);
    if (0 > retval || 0 == length + 1u)
        GenPrintf(EMSG_warn, "UMAPINFO: Error while reading value (qstring)\n");
    else
    {
        result = UMI_Malloc(length + 1u);

        if (NULL == result)
            GenPrintf(EMSG_warn, "UMAPINFO: Not enough memory for string\n");
        else
        {
            memcpy(result, qstring, length);
            result[length] = 0;
            *len           = length;
        }
    }

    return result;
}


// Accept only printable ASCII characters. Others are replaced with '?'
// If parameter 'multiline' is true, LF control characters are accepted too
static void UMI_ConvertToASCII(char *str, size_t length, boolean multiline)
{
    size_t i = 0;

    for (i = 0; length > i; ++i)
    {
       if (multiline && 0x0A == str[i])
           continue;

       if (0x20 > str[i] || 0x7E < str[i])
            str[i] = '?';
    }
}


// Control characters (e.g. line breaks) are not allowed
static void UMI_ReplaceString(doom_umi1_ts_state state, const char** str)
{
    size_t  length = 0;
    char   *string = UMI_GetQString(state, &length);

    if (NULL != string)
    {
        UMI_ConvertToASCII(string, length, false);
        UMI_Free((void*) *str);
        *str = string;
    }
}


// Like UMI_ReplaceString(), but ignores strings with more than 8 characters
static void UMI_ReplaceStringMax8(doom_umi1_ts_state state, const char** str)
{
    size_t  length = 0;
    char   *string = UMI_GetQString(state, &length);

    if (NULL != string)
    {
        if (8u < length)
            UMI_Free(string);
        else
        {
            UMI_ConvertToASCII(string, length, false);
            UMI_Free((void*) *str);
            *str = string;
        }
    }
}


static const char* UMI_CreateEmptyString()
{
    char *string = UMI_Malloc(1);

    if (NULL == string)
        GenPrintf(EMSG_warn, "UMAPINFO: Not enough memory for empty string\n");
    else
        string[0] = 0;

    return string;
}


// Same as UMI_ReplaceString(), but 'clear' identifier gives empty string
static void UMI_ReplaceStringClear(doom_umi1_ts_state state, const char** str)
{
    int type   = DOOM_UMI1_TYPE_INVALID;
    int retval = doom_umi1_ts_value_type(state, &type);

    if (0 <= retval && DOOM_UMI1_TYPE_CLEAR == type)
    {
        const char *string = UMI_CreateEmptyString();

        if (NULL != string)
            *str = string;
    }
    else
        UMI_ReplaceString(state, str);
}


// It is allowed that multiple lines are contained in one value
static void UMI_ReplaceMultiString(doom_umi1_ts_state state,
                                   const char** str, size_t valcount)
{
    char   *multi        = NULL;
    size_t  multi_length = 0;
    size_t  val          = 0;

    for (val = 0; valcount > val; ++val)
    {
        size_t  length = 0;
        char   *string = UMI_GetQString(state, &length);
        int     retval = DOOM_UMI1_ERROR_NOTFOUND;

        if (NULL == string)
            break;

        if (NULL == multi)
        {
            multi        = string;
            multi_length = length;
        }
        else if (0 != length)  // Append
        {
            char   *tmp        = NULL;
            size_t  tmp_length = multi_length + length;

            tmp_length += 2u;  // For LF and NUL-termination
            if (multi_length > tmp_length)
                break;
            tmp = UMI_Malloc(tmp_length);
            if (NULL == tmp)
                break;
            memcpy(tmp, multi, multi_length);
            tmp[multi_length] = 0x0A;  // LF
            memcpy(&tmp[multi_length + 1u], string, length + 1u);
            UMI_Free(multi);
            multi        = tmp;
            multi_length = tmp_length - 1u;  // Without NUL-termination
        }

        if (valcount - 1u != val)
        {
            retval = doom_umi1_ts_value_next(state);
            if (0 > retval)
                break;
        }
    }

    if (0 == valcount || valcount != val)
        GenPrintf(EMSG_warn, "UMAPINFO: Incomplete multi-line string\n");

    if (NULL != multi)
    {
        UMI_ConvertToASCII(multi, multi_length, true);
        UMI_Free((void*) *str);
        *str = multi;
    }
}


// Same as UMI_ReplaceMultiString(), but 'clear' identifier gives empty string
static void UMI_ReplaceMultiStringClear(doom_umi1_ts_state state,
                                        const char** str, size_t valcount)
{
    int type   = DOOM_UMI1_TYPE_INVALID;
    int retval = doom_umi1_ts_value_type(state, &type);

    if (0 <= retval && DOOM_UMI1_TYPE_CLEAR == type)
    {
        const char *string = UMI_CreateEmptyString();

        if (NULL != string)
            *str = string;
    }
    else
        UMI_ReplaceMultiString(state, str, valcount);
}


// -----------------------------------------------------------------------------
// Episode menu

// Returns true on success
static boolean UMI_PopulateEpisodeMenuEntry(doom_umi1_ts_state state,
                                            emenu_t *entry)
{
    boolean  result = false;
    size_t   length = 0;
    int      retval = DOOM_UMI1_ERROR_NOTFOUND;
    char    *tmp    = NULL;

    tmp = UMI_GetQString(state, &length);
    if (NULL != tmp)
    {
        UMI_ConvertToASCII(tmp, length, false);
        entry->patch = tmp;
        retval = doom_umi1_ts_value_next(state);
    }

    if (0 <= retval)
    {
        tmp = UMI_GetQString(state, &length);
        if (NULL != tmp)
        {
            UMI_ConvertToASCII(tmp, length, false);
            entry->name = tmp;
            retval = doom_umi1_ts_value_next(state);
        }
    }

    if (0 <= retval)
    {
        tmp = UMI_GetQString(state, &length);
        if (NULL != tmp)
        {
            UMI_ConvertToASCII(tmp, length, false);
            entry->key = tmp;
            result = true;
        }
    }

    return result;
}


// Returns true if identifier 'clear' was detected
static boolean UMI_AppendEpisodeMenuEntry(doom_umi1_ts_state state,
                                          emenu_t** em, size_t valcount)
{
    boolean  result = false;
    int      type   = DOOM_UMI1_TYPE_INVALID;
    int      retval = doom_umi1_ts_value_type(state, &type);

    if (0 <= retval && DOOM_UMI1_TYPE_CLEAR == type)
    {
        UMI_DestroyEpisodeMenu(*em);
        *em    = NULL;
        result = true;
    }
    else
    {
        emenu_t *entry = UMI_Malloc(sizeof(emenu_t));

        if (NULL != entry)
        {
            UMI_InitEpisodeMenuEntry(entry);
            if (false == UMI_PopulateEpisodeMenuEntry(state, entry))
            {
                GenPrintf(EMSG_warn,
                          "UMAPINFO: Error while reading episode menu entry\n");
                UMI_DestroyEpisodeMenu(entry);
            }
            else
            {
                // Append episode menu entry to list
                if (NULL == *em)
                    *em = entry;
                else
                {
                    emenu_t *tmp = *em;

                    while (NULL != tmp->next)
                        tmp = tmp->next;
                    tmp->next = entry;
                }
            }
        }
    }

    return result;
}


// -----------------------------------------------------------------------------
// Boss actions

// Returns true on success
static boolean UMI_PopulateBossActionEntry(doom_umi1_ts_state state,
                                           bossaction_t *entry)
{
    boolean result      = false;
    size_t  thing_index = 0;
    int     retval      = DOOM_UMI1_ERROR_NOTFOUND;

    retval = doom_umi1_ts_value_read_thing(state, NULL, &thing_index);
    if (0 <= retval && (size_t) INT_MAX >= thing_index)
    {
        entry->thing = thing_index;
        retval = doom_umi1_ts_value_next(state);
        if (0 <= retval)
            retval = doom_umi1_ts_value_read_number(state, &entry->special);
        if (0 <= retval)
            retval = doom_umi1_ts_value_next(state);
        if (0 <= retval)
            retval = doom_umi1_ts_value_read_number(state, &entry->tag);
        if (0 <= retval)
            result = true;
    }

    return result;
}


// Returns true if identifier 'clear' was detected
static boolean UMI_MergeBossAction(doom_umi1_ts_state state,
                                   bossaction_t** ba, size_t valcount)
{
    boolean  result = false;
    int      type   = DOOM_UMI1_TYPE_INVALID;
    int      retval = doom_umi1_ts_value_type(state, &type);

    if (0 <= retval && DOOM_UMI1_TYPE_CLEAR == type)
    {
        UMI_DestroyBossActions(*ba);
        *ba    = NULL;
        result = true;
    }
    else if (DOOM_UMI1_TYPE_THING == type)
    {
        bossaction_t *entry = UMI_Malloc(sizeof(bossaction_t));

        if (NULL != entry)
        {
            UMI_InitBossActionEntry(entry);
            if (false == UMI_PopulateBossActionEntry(state, entry))
            {
                GenPrintf(EMSG_warn,
                          "UMAPINFO: Error while reading boss action\n");
                UMI_DestroyBossActions(entry);
            }
            else
            {
                if (NULL == *ba)
                    *ba = entry;
                else
                {
                    bossaction_t *tmp = *ba;

                    while (NULL != tmp->next)
                        tmp = tmp->next;
                    tmp->next = entry;
                }
            }
        }
    }

    return result;
}


// -----------------------------------------------------------------------------
// Import data

// Check whether map entry object for episode/map already exists
// If not, create an empty map entry object
static mapentry_t *UMI_GetMapEntry(unsigned int episode, unsigned int map)
{
    mapentry_t *entry      = umapinfo.entry_first;
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
            if (NULL == umapinfo.entry_first)
                umapinfo.entry_first = entry;
            else
                entry_last->next = entry;
        }
    }

    return entry;
}


static void UMI_StoreKeyData(doom_umi1_ts_state state, mapentry_t *entry)
{
    size_t  key      = 0;
    int     retval   = doom_umi1_ts_key_read(state, NULL, &key);
    size_t  valcount = 0;
    boolean emc      = false;  // Episode menu clear request

    if (0 > retval)
    {
        GenPrintf(EMSG_warn, "UMAPINFO: Error while reading key\n");
        return;
    }

    retval = doom_umi1_ts_value_count(state, &valcount);
    if (0 > retval || 0 == valcount)
    {
        GenPrintf(EMSG_warn, "UMAPINFO: Error while reading value\n");
        return;
    }

    switch (key)
    {
        case DOOM_UMI1_KEY_AUTHOR:
            UMI_ReplaceString(state, &entry->author);
            break;
        case DOOM_UMI1_KEY_LABEL:
            UMI_ReplaceStringClear(state, &entry->label);
            break;
        case DOOM_UMI1_KEY_LEVELNAME:
            UMI_ReplaceString(state, &entry->levelname);
            break;
        case DOOM_UMI1_KEY_INTERTEXT:
            UMI_ReplaceMultiStringClear(state, &entry->intertext, valcount);
            break;
        case DOOM_UMI1_KEY_INTERTEXTSECRET:
            UMI_ReplaceMultiStringClear(state,
                                        &entry->intertextsecret, valcount);
            break;
        case DOOM_UMI1_KEY_INTERBACKDROP:
            UMI_ReplaceStringMax8(state, &entry->interbackdrop);
            break;
        case DOOM_UMI1_KEY_INTERMUSIC:
            UMI_ReplaceStringMax8(state, &entry->intermusic);
            break;
        case DOOM_UMI1_KEY_NEXT:
            UMI_ReplaceStringMax8(state, &entry->nextmap);
            break;
        case DOOM_UMI1_KEY_NEXTSECRET:
            UMI_ReplaceStringMax8(state, &entry->nextsecret);
            break;
        case DOOM_UMI1_KEY_MUSIC:
            UMI_ReplaceStringMax8(state, &entry->music);
            break;
        case DOOM_UMI1_KEY_SKYTEXTURE:
            UMI_ReplaceStringMax8(state, &entry->skytexture);
            break;
        case DOOM_UMI1_KEY_LEVELPIC:
            UMI_ReplaceStringMax8(state, &entry->levelpic);
            break;
        case DOOM_UMI1_KEY_EXITPIC:
            UMI_ReplaceStringMax8(state, &entry->exitpic);
            break;
        case DOOM_UMI1_KEY_ENTERPIC:
            UMI_ReplaceStringMax8(state, &entry->enterpic);
            break;
        case DOOM_UMI1_KEY_ENDPIC:
            UMI_ReplaceStringMax8(state, &entry->endpic);
            break;
        case DOOM_UMI1_KEY_EPISODE:
            // Associated with global episode list (not the map entry object)
            emc = UMI_AppendEpisodeMenuEntry(state, &umapinfo.emenu, valcount);
            break;
        case DOOM_UMI1_KEY_BOSSACTION:
            if (UMI_MergeBossAction(state, &entry->bossactions, valcount))
                entry->bossactions_clear = true;
            break;
        case DOOM_UMI1_KEY_ENDGAME:
            entry->endgame = UMI_GetNumber(state) ? enabled : disabled;
            break;
        case DOOM_UMI1_KEY_PARTIME:
            entry->partime = UMI_GetNumber(state);
            break;
        case DOOM_UMI1_KEY_NOINTERMISSION:
            entry->nointermission = UMI_GetNumber(state) ? true : false;
            break;
        case DOOM_UMI1_KEY_ENDBUNNY:
            entry->endbunny = UMI_GetNumber(state) ? true : false;
            break;
        case DOOM_UMI1_KEY_ENDCAST:
            entry->endcast = UMI_GetNumber(state) ? true : false;
            break;
        default:
            GenPrintf(EMSG_warn, "UMAPINFO: Unknown key ignored\n");
            break;
    }

    // Store flag that default episode menu must be cleared
    if (emc)
       umapinfo.emenu_clear = true;
}


static void UMI_MergeMapEntry(doom_umi1_ts_state state)
{
    mapentry_t   *entry   = NULL;
    unsigned int  episode = 0;
    unsigned int  map     = 0;
    int           retval  = doom_umi1_ts_map_read(state, &episode, &map);

    if (0 <= retval)
        entry = UMI_GetMapEntry(episode, map);

    if (NULL == entry)
        retval = DOOM_UMI1_ERROR_NOTFOUND;
    else
    {
        size_t keycount = 0;

        retval = doom_umi1_ts_key_count(state, &keycount);
        while (0 <= retval && keycount)
        {
            UMI_StoreKeyData(state, entry);

            if (--keycount)
                retval = doom_umi1_ts_key_next(state);
        }
    }

    if (0 > retval)
        GenPrintf(EMSG_warn, "UMAPINFO: Error while importing keys\n");
}


static void UMI_ImportUMapInfo(umapinfo_t *umi, doom_umi1_handle data)
{
    doom_umi1_ts_state state    = NULL;
    size_t             mapcount = 0;  // Number of toplevel map entries
    int                retval   = doom_umi1_ts_state_create(&state, data);

    if (0 <= retval)
        retval = doom_umi1_ts_map_count(state, &mapcount);

    while (0 <= retval && mapcount)
    {
        UMI_MergeMapEntry(state);

        if (--mapcount)
            retval = doom_umi1_ts_map_next(state);
    }

    doom_umi1_ts_state_destroy(&state);

    if (0 > retval)
        GenPrintf(EMSG_warn, "UMAPINFO: Error while importing map entry\n");
}


// -----------------------------------------------------------------------------
// API

// Import and merge UMAPINFO lump into current data
// If parts of the new data are already present, they overwrite the current data
void UMI_LoadUMapInfoLump(lumpnum_t lumpnum)
{
    doom_umi1_handle  data = NULL; // libdoom-umapinfo UMAPINFO object handle
    int               len  = W_LumpLength(lumpnum);

    assert(0 <= len);

    {
        int            retval  = DOOM_UMI1_ERROR_MEMORY;
        unsigned char *lump    = UMI_Malloc(len);
        size_t         length  = len;
        int            verbose = 0;

        if (NULL != lump)
        {
            W_ReadLump(lumpnum, lump);
            retval = doom_umi1_create(&data, lump, length, verbose);
            UMI_Free(lump);
        }
        if (0 > retval)
            GenPrintf(EMSG_warn, "UMAPINFO: Parsing data failed\n");
        else if (0 < retval)
            GenPrintf(EMSG_warn, "UMAPINFO: Warning: Data may be incomplete\n");

        if (0 <= retval)
            UMI_ImportUMapInfo(&umapinfo, data);

        doom_umi1_destroy(&data);
    }
}


void UMI_DestroyUMapInfo(void)
{
    UMI_DestroyEpisodeMenu(umapinfo.emenu);
    umapinfo.emenu       = NULL;
    umapinfo.emenu_clear = false;

    UMI_DestroyMaps(umapinfo.entry_first);
    umapinfo.entry_first = NULL;
}


// Extract episode and map numbers from map name
// For Doom 2 map names zero is returned for episode
// Returns true on success (numbers are valid)
boolean UMI_ParseMapName(const char *name, byte *episode, byte *map)
{
    boolean      result = false;
    int          retval = 0;
    unsigned int e      = 0;
    unsigned int m      = 0;

    retval = sscanf(name, "%*[Mm]%*[Aa]%*[Pp]%u", &m);
    if (1 == retval && 255u >= m)
        result = true;

    if (false == result)
    {
        retval = sscanf(name, "%*[Ee]%u%*[Mm]%u", &e, &m);
        if (2 == retval && 0 < e && 255u >= e && 0 < m && 255u >= m)
            result = true;
    }

    if (true == result)
    {
        *episode = e;
        *map     = m;
    }

    return result;
}


// Search for UMAPINFO map entry that matches episode and map parameters
// NULL is returned if nothing was found
mapentry_t *UMI_LookupUMapInfo(byte episode, byte map)
{
    mapentry_t   *entry = umapinfo.entry_first;
    unsigned int  e     = episode;
    unsigned int  m     = map;

    // libdoom-umapinfo uses episode 0 for Doom 2
    if (doom2_commercial == gamemode)
        e = 0;

    while (NULL != entry)
    {
        // Entries with numbers beyond the range of 'byte' will never match
        if (entry->episode == e && entry->map == m)
            break;
        entry = entry->next;
    }

    if (NULL != entry)
        GenPrintf(EMSG_info,
                  "UMAPINFO: Map entry found for Episode %u, Map %u\n", e, m);

    return entry;
}


// Load UMAPINFO data for current gameepisode/gamemap
void UMI_Load_LevelInfo(void)
{
    gamemapinfo = UMI_LookupUMapInfo(gameepisode, gamemap);

    // SMMU level info is replaced with UMAPINFO data, where possible
    if (gamemapinfo)
    {
        // Key author is handled by WI_Draw_LF() and WI_Draw_EL()
        // Also mapped to info_creator for COM_MapInfo_f()
        if (gamemapinfo->author)
            info_creator = gamemapinfo->author;

        // Keys label and levelname are handled by P_LevelName()

        // Keys intertext and intertextsecret are handled by F_StartFinale()

        // Key interbackdrop is handled by F_StartFinale()

        // Key intermusic is handled by WI_Ticker()

        // Keys nextmap and nextsecret are handled by G_DoUMapInfo()

        // Key music is mapped to info_music
        if (gamemapinfo->music)
            info_music = UMI_GetMusicLumpName(gamemapinfo->music);

        // Key skytexture is mapped to info_skyname
        if (gamemapinfo->skytexture)
            info_skyname = gamemapinfo->skytexture;

        // Key levelpic is handled by WI_Draw_LF() and WI_Draw_EL()

        // Key exitpic is mapped to info_interpic
        if (gamemapinfo->exitpic)
            info_interpic = gamemapinfo->exitpic;

        // Key enterpic is handled by WI_Draw_ShowNextLoc()

        // Key endpic is handled by F_Drawer()

        // Key bossactions is handled by A_Bosstype_Death()

        // Key endgame is handled by G_NextLevel()

        // Key partime is mapped to info_partime
        if (gamemapinfo->partime)
        {
            if ((unsigned int) INT_MAX < gamemapinfo->partime)
                info_partime = INT_MAX;
            else
                info_partime = gamemapinfo->partime;
            pars_valid_bex = true;  // Abuse this flag for activation with PWAD
        }
    }
}


// Strip "d_" prefix from lump name, if present
// (because the function S_AddMusic() adds a "d_" prefix)
// Returns a pointer into name
const char* UMI_GetMusicLumpName(const char* name)
{
    if (('d' == name[0] || 'D' == name[0]) && '_' == name[1])
        return &name[2];
    else
        return name;
}


#else  // HAVE_LIBDOOM_UMAPINFO


#include "doomincl.h"


// -----------------------------------------------------------------------------
// API stubs (if libdoom-umapinfo is not available)

void UMI_LoadUMapInfoLump(lumpnum_t lumpnum)
{
    GenPrintf(EMSG_warn, "UMAPINFO: Ignored (libdoom-umapinfo is required)\n");
}


void UMI_DestroyUMapInfo(void)
{
    return;
}


boolean UMI_ParseMapName(const char *mapname, byte *episode, byte * map)
{
    return false;
}


mapentry_t *UMI_LookupUMapinfo(byte episode, byte map)
{
    return NULL;
}


void UMI_Load_LevelInfo(void)
{
    return;
}


const char* UMI_GetMusicLumpName(const char* name)
{
    return name;
}

#endif  // HAVE_LIBDOOM_UMAPINFO
