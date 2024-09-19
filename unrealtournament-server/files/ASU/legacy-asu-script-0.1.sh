#~asu 0.6
#~legacy 0.1 ## compatability functions for version 0.1 scripts

AddIni () { IniAdd "$1" "$2" "$3" "$4"; }
UnAddIni () { IniUnAdd "$1" "$2" "$3" "$4"; }
SetIni () { IniSet "$1" "$2" "$3" "$4"; }
UnSetIni () { IniUnSet "$1" "$2" "$3"; }
MatchIni () { IniMatch "$1" "$2" "$3" "$4"; }
ReadIni () { IniRead "$1" "$2" "$3"; }

