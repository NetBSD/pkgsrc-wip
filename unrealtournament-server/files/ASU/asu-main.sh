#!/bin/sh
###########################################################
#
# asu.sh
#
# abfackeln's server utilities
# for unreal tournament
#
# Copyright (C) 2001,2002 abfackeln@abfackeln.com
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
# 
# Usage:
# sh asu.sh
#
###########################################################

## asu package installer

Install_Package ()
{
   if [ -f "$PATCH_DIR/$1-patch.tar.gz" ]; then
      pushd $UT_DIR > /dev/null
      tar zxpUf "$PATCH_DIR/$1-patch.tar.gz"
      popd > /dev/null
      if [ -f "$UT_DIR/$1-install.asu" ]; then
         TMP=`head -1 "$UT_DIR/$1-install.asu" | sed -n -e "s/#~asu \([0-9.]*\).*$/\\\\1/" -e "t label" -e "d" -e ": label" -e "p"`
         if [ -f "$LIB_DIR/legacy-asu-script-$TMP.sh" ]; then
            XTMP=`head -1 "$LIB_DIR/legacy-asu-script-$TMP.sh" | sed -n -e "s/#~asu \([0-9.]*\).*$/\\\\1/" -e "t label" -e "d" -e ": label" -e "p"`
            if [ ! "$XTMP" = "$VERSION" ]; then
               Add_Message "WARNING: Legacy script converter for version $TMP scripts may be corrupted!"
            fi
            . "$LIB_DIR/legacy-asu-script-$TMP.sh"
         fi
         . "$UT_DIR/$1-install.asu"
         rm -f "$UT_DIR/$1-install.asu"
      fi
      Add_Message "+++ $1 patch is now installed!"
   else
      Add_Message "!!! Error: can not find patch file: $PATCH_DIR/$1-patch.tar.gz"
   fi
}

## check for map compression

Fix_Totally_Unreal ()
{
   TMP=`ls $UT_DIR/Maps/*.uz 2> /dev/null`
   for XTMP in $TMP; do
      XXTMP=`echo "$XTMP" | sed s/.uz$//`
      if [ ! -f "$XXTMP" ]; then
         echo "decompressing $XTMP ..."
         Add_Message "decompressing $XTMP ..."
         $UT_DIR/ucc decompress $XTMP -nohomedir > /dev/null
         XXTMP=$SYS_DIR/`echo "$XXTMP" | sed s/^.*[/]//`
         mv "$XXTMP" "$UT_DIR/Maps/"
      fi
   done
}

## check that server packages exist

Fix_Server_Packages ()
{
   GetIntValues "MetaClass=Engine.Mutator"
   for GET_VAL in $GET_VAL; do
      INFILE="$GET_VAL"".u"
      if [ ! -f "$SYS_DIR/$INFILE" ]; then
         GetFile $SYS_DIR $INFILE
         if [ -z "$GET_VAL" ]; then
            Add_Message "Can not find the file $INFILE required by one or more .int file(s)"
            ERR=1
         fi
      fi
   done

   GetIntValues "Class=Texture"
   for GET_VAL in $GET_VAL; do
      INFILE="$GET_VAL"".utx"
      if [ ! -f "$UTX_DIR/$INFILE" ]; then
         GetFile $UTX_DIR $INFILE
         if [ -z "$GET_VAL" ]; then
            Add_Message "Can not find the file $INFILE required by one or more .int file(s)"
            ERR=1
         fi
      fi
   done

   GetIntValues "Class=Texture"
   for INFILE in $GET_VAL; do
      IniMatch Engine.GameEngine ServerPackages $INFILE $UT_MAIN_INI
      if [ -z "$INI_VAL" ]; then
         echo
         echo "$INFILE.utx is not being used by the server."
         ReadBool "Use $INFILE.utx"
         if [ "$READ_VAL" = "y" ]; then
            IniAdd Engine.GameEngine ServerPackages $INFILE $UT_MAIN_INI
         else
            echo "Not fixed."
            Add_Message "Not using server package $INFILE."
         fi
      fi
   done

   for INFILE in `ls $SYS_DIR/*.u | sed -e "s/^.*\/\([^\/]*\)\.u$/\\1/"`; do
      TMP=`grep -i "packages=$INFILE" $UT_MAIN_INI`
      if [ -z "$TMP" ]; then
         echo
         echo "$INFILE.u is not being used by the server."
         ReadBool "Use $INFILE.u"
         if [ "$READ_VAL" = "y" ]; then
            IniAdd Engine.GameEngine ServerPackages $INFILE $UT_MAIN_INI
         else
            echo "Not fixed."
            Add_Message "Not using server package $INFILE."
         fi
      fi
   done
}

## check for broken maps

Fix_Corrupted_Maps ()
{
   TMP=`ls -1 -s $UT_DIR/Maps/ | awk '{ if ($1 == 0) { print $2; }}'`
   if [ -n "$TMP" ]; then
      for XTMP in $TMP; do
         Add_Message "Corrupted Map File: $XTMP"
      done
      ERR=1
   fi
}

## bot builder

Generic_Bots ()
{
   BOT_FACE=SGirlSkins.Cathode
   BOT_SKIN=SGirlSkins.fwar
   BOT_CLASS=BotPack.TFemale2Bot
   BOT_VOICE=BotPack.VoiceBoss

   MYFILE=/tmp/sed.tmp.$$
   TMPFILE=/tmp/sed.tmpb.$$

   cat $UT_USER_INI > $MYFILE

   VAR=0
   MAX=32

   while [ $VAR -le $MAX ]; do

      REM=$VAR
      BIN=
      SIG=2

      while [ $SIG -le $MAX ]; do

         if [ $[$REM % $SIG] -gt 0 ]; then
            BIN=1$BIN
            REM=$[ $REM - $[SIG / 2] ]
         else
            BIN=0$BIN
         fi

         SIG=$[ $SIG * 2 ]

      done

      sed s/^BotNames\\[$VAR\\].*/BotNames[$VAR]=$BIN/ $MYFILE > $TMPFILE
      mv $TMPFILE $MYFILE

      VAR=$[ $VAR + 1 ]

   done

   sed "s/^BotFaces\[\([0-9]*\)\].*/BotFaces[\1]=$BOT_FACE/" $MYFILE > $TMPFILE
   sed "s/^BotClasses\[\([0-9]*\)\].*/BotClasses[\1]=$BOT_CLASS/" $TMPFILE > $MYFILE
   sed "s/^BotSkins\[\([0-9]*\)\].*/BotSkins[\1]=$BOT_SKIN/" $MYFILE > $TMPFILE

   ID=0
   while [ $ID -lt 32 ]; do
      echo "VoiceType[$ID]=$BOT_VOICE" >> $TMPFILE
      ID=$(( $ID + 1 ))
   done

   cat $TMPFILE > $UT_USER_INI

   rm -f $MYFILE $TMPFILE
}

### ini file modifying scripts

IniAdd()
{
   TMP="/tmp/ut.ini.$$.tmp"
   INI="$4"

   awk 'BEGIN { eval ARGV[1]; eval ARGV[2]; eval ARGV[3]; instate = 0; done = 0; }
/^\[/ { if ((instate >= 1) && (done == 0)) { print item "=" value; done = 1; } if ($1 ~ "\\[" zone "\\]") { instate = 1; } else { instate = 0; } }
{
   if (instate == 2) {
      if (length($1) <= 1) {
         print item "=" value; done = 1;
      } else if ($1 ~ "^" item "=" value "[ \t\f\n\r\v]*$") {
         instate = 0; done = 1;
      }
   } else if (instate == 1) {
      instate = 2;
   }
   print $0;
}
END { if (done == 0) { if (instate >= 1) { print item "=" value; } else { print "[" zone "]"; print item "=" value; print ""; } } }
' "zone=$1" "item=$2" "value=$3" < "$INI" > "$TMP"

   if [ $? -eq 0 ]; then
      mv "$TMP" "$INI"
   fi
}

IniUnAdd()
{
   TMP="/tmp/ut.ini.$$.tmp"
   INI="$4"

   awk 'BEGIN { eval ARGV[1]; eval ARGV[2]; eval ARGV[3]; instate = 0; }
/^\[/ { if ($1 ~ "\\[" zone "\\]") { instate = 1; } else { instate = 0; } }
{
   if (instate == 2) {
      if (length($1) <= 1) {
         print $0;
      } else if ($1 ~ "^" item "=" value "[ \t\f\n\r\v]*$") {
      } else {
         print $0;
      }
   } else if (instate == 1) {
      print $0; instate = 2;
   } else {
      print $0;
   }
}' "zone=$1" "item=$2" "value=$3" < "$INI" > "$TMP"

   if [ $? -eq 0 ]; then
      mv "$TMP" "$INI"
   fi
}

IniSet()
{
   TMP="/tmp/ut.ini.$$.tmp"
   INI="$4"

   awk 'BEGIN { eval ARGV[1]; eval ARGV[2]; eval ARGV[3]; instate = 0; done = 0; }
/^\[/ { if ((instate >= 1) && (done == 0)) { print item "=" value; done = 1; } if ($1 ~ "\\[" zone "\\]") { instate = 1; } else { instate = 0; } }
{
   if (instate == 2) {
      if (length($1) <= 1) {
         print item "=" value; print $0; done = 1;
      } else if ($1 ~ "^" item "=") {
         print item "=" value; instate = 0; done = 1;
      } else {
         print $0;
      }
   } else if (instate == 1) {
      print $0; instate = 2;
   } else {
      print $0;
   }
}
END { if (done == 0) { if (instate >= 1) { print item "=" value; } else { print "[" zone "]"; print item "=" value; print ""; } } }
' "zone=$1" "item=$2" "value=$3" < "$INI" > "$TMP"

   if [ $? -eq 0 ]; then
      mv "$TMP" "$INI"
   fi
}

IniUnSet()
{
   TMP="/tmp/ut.ini.$$.tmp"
   INI="$3"

   awk 'BEGIN { eval ARGV[1]; eval ARGV[2]; eval ARGV[3]; instate = 0; }
/^\[/ { if ($1 ~ "\\[" zone "\\]") { instate = 1; } else { instate = 0; } }
{
   if (instate == 2) {
      if (length($1) <= 1) {
         print $0;
      } else if ($1 ~ "^" item "=") {
      } else {
         print $0;
      }
   } else if (instate == 1) {
      print $0; instate = 2;
   } else {
      print $0;
   }
}' "zone=$1" "item=$2" < "$INI" > "$TMP"

   if [ $? -eq 0 ]; then
      mv "$TMP" "$INI"
   fi
}

IniMatch()
{
   TMP="/tmp/ut.ini.$$.tmp"
   INI="$4"

   awk 'BEGIN { eval ARGV[1]; eval ARGV[2]; eval ARGV[3]; instate = 0; }
/^\[/ { if ($1 ~ "\\[" zone "\\]") { instate = 1; } else { instate = 0; } }
{
   if (instate == 2) {
      if (length($1) <= 1) {
      } else if ($1 ~ "^" item "=" value "[ \t\f\n\r\v]*$") {
         print "match";
      }
   } else if (instate == 1) {
      instate = 2;
   }
}' "zone=$1" "item=$2" "value=$3" < "$INI" > "$TMP"

   INI_VAL=`cat $TMP`
   rm -f $TMP
}

IniRead()
{
   awk 'BEGIN { eval ARGV[1]; eval ARGV[2]; eval ARGV[3]; instate = 0; FS="="; }
/^\[/ { if ($1 ~ "\\[" zone "\\]") { instate = 1; } else { instate = 0; } }
{ if ((instate == 1) && ($1 == item)) { gsub(/^[ \t\f\n\r\v]*/, "", $2); gsub(/[ \t\f\n\r\v]*$/, "", $2); print $2; } }
' "zone=$1" "item=$2" < "$3" > "/tmp/ut.ini.$$.tmp"

   if [ $? -eq 0 ]; then
      INI_VAL=`head -1 /tmp/ut.ini.$$.tmp`
   else
      INI_VAL=""
   fi
   rm -f /tmp/ut.ini.$$.tmp
}

## varied get commands which modify GET_VAL

GetIntValues ()
{
   GET_VAL=`cat $SYS_DIR/*.int | sed -n -e "s/Object=(\(.*\))/\\1/" -e "t label" -e "d" -e ": label" -e "s/^.*Name=\([^,.]*\).*$1.*$/\\1/" -e "t end" -e "d" -e ": end" -e "p" | sort -f`
   XTMP=
   XXTMP=
   for TMP in $GET_VAL; do
      if [ ! "$TMP" = "$XTMP" ]; then
         XTMP="$TMP"
         XXTMP="$XXTMP $TMP"
      fi
   done
   GET_VAL="$XXTMP"
}

GetFullIntValues ()
{
   GET_VAL=`cat $SYS_DIR/*.int | sed -n -e "s/Object=(\(.*\))/\\1/" -e "t label" -e "d" -e ": label" -e "s/^.*Name=\([^,]*\).*$1.*$/\\1/" -e "t end" -e "d" -e ": end" -e "p"`
}

GetFile ()
{
   GET_VAL=`ls $1 | awk 'BEGIN { eval ARGV[1]; } { if (tolower(xname) == tolower($1)) { print $1; } }' "xname=$2"`
}

## std read commands which return READ_VAL

ReadString ()
{
   echo -n "> "
   read READ_VAL
}

ReadNumeric ()
{
   ReadString
   READ_VAL=`echo "$READ_VAL" | sed -e "s/[^0-9]//g"`
}

ReadBool ()
{
   echo -n "$1 (y/n) ? "
   ReadOneChar
}

ReadOneChar ()
{
   read READ_VAL
   READ_VAL=`echo "$READ_VAL" | sed -e "s/\(.\).*/\1/g" -e "y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/"`
}

## menu version of ReadOneChar

Read_Input()
{
   echo
   if [ -n "$MESSAGE" ]; then
      echo "> $MESSAGE"
      echo
      MESSAGE=""
   fi
   echo "Enter a letter from the above menu."
   echo -n "? "
   ReadOneChar
   MENU_SEL=$READ_VAL
}

## generic optimization command

Optimize_Std ()
{
   eval ARG="\$ARG_OPTIM_$1"
   eval PRF="\$PRF_OPTIM_$1"

   echo "New value for $ARG [$PRF]"
   ReadString

   if [ -z "$READ_VAL" ]; then
      READ_VAL="$PRF"
   fi

   MESSAGE="$ARG set to $READ_VAL"
   IniSet $ARG "$READ_VAL" $UT_MAIN_INI
}

## initialization functions

Init_Vars()
{
   IniMatch IpDrv.TcpNetDriver DownloadManagers IpDrv.HTTPDownload $UT_MAIN_INI
   if [ -n "$INI_VAL" ]; then
      IniRead IpDrv.HTTPDownload RedirectToURL $UT_MAIN_INI
      if [ -n "$INI_VAL" ]; then
         MSG_REDIRECT="Disable Download Redirection"
         OPT_REDIRECT=1
      else
         MSG_REDIRECT="Enable Download Redirection"
         OPT_REDIRECT=0
      fi
   else
      MSG_REDIRECT="Enable Download Redirection"
      OPT_REDIRECT=0
   fi

   IniRead Engine.GameInfo bBatchLocal $UT_MAIN_INI
   if [ "$INI_VAL" = "True" ]; then
      MSG_NGLS="Disable NG Local Stats"
      OPT_NGLS=1
   else
      MSG_NGLS="Enable NG Local Stats (requires JDK 1.2)"
      OPT_NGLS=0
   fi

   if [ -f "$UT_USER_INI.old-bots" ]; then
      MSG_BINBOTS="Restore Old Bot Settings"
      OPT_BINBOTS=1
   else
      MSG_BINBOTS="Give Bots Binary Names and Cathode Skins"
      OPT_BINBOTS=0
   fi

   if [ -f "$UT_DIR/Web.graphic/images/1-1.gif" ]; then
      mv -f $UT_DIR/Web.graphic $UT_DIR/Web/graphic
   fi

   if [ -d "$UT_DIR/Web/graphic" ]; then
      OPT_WEBTEXT=1
   else
      OPT_WEBTEXT=0
   fi
}

Init_Optim_Vars ()
{
   eval ARG="\$ARG_OPTIM_$1"
   eval DEF="\$DEF_OPTIM_$1"
   eval PRF="\$PRF_OPTIM_$1"

   IniRead $ARG $UT_MAIN_INI
   CUR=$INI_VAL
   eval MSG_OPTIM_$1=\"\(Def: \$DEF, Opt: \$PRF, Cur: \$CUR\)\"
}

Guess_Paths ()
{
   TMP=`find . -name ASU.ini 2> /dev/null | head -1`
   if [ -z "$TMP" ]; then
      TMP=`find ../System -name ASU.ini 2> /dev/null | head -1`
   fi
   if [ -n "$TMP" ]; then
      UT_ASU_INI="$(pwd)/$TMP"
   else
      TMP=`find . -name System 2> /dev/null | head -1 | sed "s/[/]System$//"`
      if [ -z "$TMP" ]; then
         TMP=`find .. -name System 2> /dev/null | head -1 | sed "s/[/]System$//"`
      fi
      if [ -z "$TMP" ]; then
         echo "$0: Error: Can not find System directory"
         UT_ASU_INI="$(pwd)/ASU.ini"
         UT_DIR="$(pwd)"
      else
         if [ -z "$TMP" ]; then
            UT_DIR="$(pwd)"
         else
            UT_DIR="$(pwd)/$TMP"
         fi
         UT_ASU_INI="$UT_DIR/System/ASU.ini"
      fi
      touch $UT_ASU_INI
      IniSet ASU.settings GameDir "$UT_DIR" $UT_ASU_INI
   fi

   PATCH_DIR="$(pwd)/Patches"
   LIB_DIR="$(pwd)/ASU"

   IniRead ASU.settings GameDir $UT_ASU_INI
   UT_DIR="$INI_VAL"
   SYS_DIR="$UT_DIR/System"

   IniRead ASU.settings GameIni $UT_ASU_INI
   if [ -z "$INI_VAL" ]; then
      UT_MAIN_INI="$SYS_DIR/UnrealTournament.ini"
      IniSet ASU.settings GameIni "$UT_MAIN_INI" $UT_ASU_INI
   else
      UT_MAIN_INI="$INI_VAL"
   fi

   IniRead ASU.settings UserIni $UT_ASU_INI
   if [ -z "$INI_VAL" ]; then
      UT_USER_INI="$SYS_DIR/User.ini"
      IniSet ASU.settings UserIni "$UT_USER_INI" $UT_ASU_INI
   else
      UT_USER_INI="$INI_VAL"
   fi
}

Check_Paths ()
{
   if [ ! -f "$UT_MAIN_INI" ]; then
      echo
      echo "Can not find '$UT_MAIN_INI'"
      echo "Check that your directory name and file names are correct."
      echo
      Menu_Main_D
   else
      if [ ! -f "$UT_USER_INI" ]; then
         echo
         echo "Can not find '$UT_USER_INI'"
         echo "Check that your directory name and file names are correct."
         echo
         Menu_Main_D
      fi
   fi

   UTX_DIR="$UT_DIR/Textures"
}

### this is the "main loop"

Initialization()
{
   VERSION="0.6"
   BETAVER=""

   ### basic init routines

   if [ "$0" = "-bash" ];then
      echo "usage:"
      echo "sh asu.sh"
      echo "sh asu.sh <the ut directory location>"
      exit -2
   fi

   Guess_Paths

   ### the next two lines create the $NL newline var
   NL="
"
   ### do not change the spacing or anything in the above two lines

   # sed awk tar pushd popd head rm mv ls cat eval zcat grep touch unzip

   ### Optimization settings:

   ARG_OPTIM_C="IpDrv.TcpNetDriver MaxClientRate"
   DEF_OPTIM_C="20000"
   PRF_OPTIM_C="5000"

   ARG_OPTIM_I="IpDrv.TcpNetDriver InitialConnectTimeout"
   DEF_OPTIM_I="500.0"
   PRF_OPTIM_I="30.0"
}

## very simple functions

TopDisplay()
{
   echo
   echo
   echo "asu version $VERSION$BETAVER, Copyright (C) 2001,2002 abfackeln@abfackeln.com"
   echo "asu is free software and comes with ABSOLUTELY NO WARRANTY."
   echo "Enter H for help and more copyright information."
   echo
}

Add_Message ()
{
   MESSAGE="$MESSAGE""$NL  $1"
}

### menu functions ###

Menu_Main ()
{
   Initialization
   Check_Paths
   MESSAGE=""
   while [ "$MENU_SEL" != "x" ]; do
      Init_Vars
      TopDisplay

      echo "MAIN MENU"
      echo "---------"
      echo
      echo "B) Bot Menu"
      echo "D) Specify UT Directory and active .ini files"
      echo "   $UT_MAIN_INI"
      echo "H) Help and Copyright Information"
      echo "I) Install Init Script"
      echo "N) $MSG_NGLS"
      echo "O) Optimization Menu"
      echo "P) Patches"
      echo "R) $MSG_REDIRECT"
      echo "S) Server Info, MOTD and Passwords"
      echo "U) Umod Package Menu"
      echo "V) Verify Installation"
      echo "X) Exit"
      Read_Input

      ### now process the menu selection

      case "$MENU_SEL" in
      b)
         Menu_Main_B
         ;;
      d)
         Menu_Main_D
         ;;
      g)
         Menu_Main_G
         ;;
      h)
         Menu_Main_H
         ;;
      i)
         Menu_Main_I
         ;;
      n)
         Menu_Main_N
         ;;
      o)
         Menu_Main_O
         ;;
      p)
         Menu_Main_P
         ;;
      r)
         Menu_Main_R
         ;;
      s)
         Menu_Main_S
         ;;
      u)
         Menu_Main_U
         ;;
      v)
         Menu_Main_V
         ;;
      w)
         Menu_Main_W
         ;;
      "")
         MESSAGE=
         ;;
      *)
         MESSAGE="Unknown Command."
         ;;
      esac
   done
}

###  B is the bot menu

Menu_Main_B ()
{
   MESSAGE=""
   while [ "$MENU_SEL" != "x" ]; do
      Init_Vars
      TopDisplay

      echo "BOT MENU"
      echo "--------"
      echo
      echo "G) $MSG_BINBOTS"
      echo "N) Set Minimum Number of Bots"
      echo "X) Exit"
      Read_Input

      ### now process the menu selection

      case "$MENU_SEL" in
      g)
         Menu_Bot_G
         ;;
      n)
         Menu_Bot_N
         ;;
      "")
         MESSAGE=
         ;;
      *)
         MESSAGE="Unknown Command."
         ;;
      esac
   done
   MESSAGE=
   MENU_SEL=
}

###  D is to set the directories

Menu_Main_D ()
{
   READ_VAL=
   while [ -z "$READ_VAL" ]; do
      echo
      echo "Enter the full path of the UT game directory [$UT_DIR]"
      ReadString
      if [ -z "$READ_VAL" ]; then
         READ_VAL=$UT_DIR
      fi
      SYS_DIR="$READ_VAL/System"
      if [ ! -d "$SYS_DIR" ]; then
         echo
         echo "Directory does not exist: $SYS_DIR"
         READ_VAL=
      fi
   done

   UT_DIR=$READ_VAL
   UT_USER_INI="$SYS_DIR/User.ini"
   UT_MAIN_INI="$SYS_DIR/UnrealTournament.ini"

   READ_VAL=
   while [ -z "$READ_VAL" ]; do
      echo
      echo "Main system settings file [$UT_MAIN_INI]"
      ReadString
      if [ -z "$READ_VAL" ]; then
         READ_VAL="$UT_MAIN_INI"
      fi
      TMP=`echo "$READ_VAL" | sed "s/^[\/].*$//"`
      if [ -n "$TMP" ]; then
         READ_VAL="$SYS_DIR/$READ_VAL"
      fi
      if [ ! -f "$READ_VAL" ]; then
         echo
         echo "File does not exist: $READ_VAL"
         TMP="$READ_VAL"
         ReadBool "Do you want to create it"
         if [ "$READ_VAL" = "y" ]; then
            READ_VAL="$TMP"
            #gunzip -c "$LIB_DIR/UnrealTournament.ini.gz" > "$READ_VAL"
            zcat "$LIB_DIR/UnrealTournament.ini.gz" > "$READ_VAL"
         else
            READ_VAL=
         fi
      fi
   done

   UT_MAIN_INI="$READ_VAL"

   READ_VAL=
   while [ -z "$READ_VAL" ]; do
      echo
      echo "User settings file [$UT_USER_INI]"
      ReadString
      if [ -z "$READ_VAL" ]; then
         READ_VAL="$UT_USER_INI"
      fi
      TMP=`echo "$READ_VAL" | sed "s/^[\/].*$//"`
      if [ -n "$TMP" ]; then
         READ_VAL="$SYS_DIR/$READ_VAL"
      fi
      if [ ! -f "$READ_VAL" ]; then
         echo
         echo "File does not exist: $READ_VAL"
         TMP="$READ_VAL"
         ReadBool "Do you want to create it"
         if [ "$READ_VAL" = "y" ]; then
            READ_VAL="$TMP"
            #gunzip -c "$LIB_DIR/User.ini.gz" > "$READ_VAL"
            zcat "$LIB_DIR/User.ini.gz" > "$READ_VAL"
         else
            READ_VAL=
         fi
      fi
   done

   UT_USER_INI="$READ_VAL"

   IniSet ASU.settings GameDir "$UT_DIR" $UT_ASU_INI
   IniSet ASU.settings GameIni "$UT_MAIN_INI" $UT_ASU_INI
   IniSet ASU.settings UserIni "$UT_USER_INI" $UT_ASU_INI

   MESSAGE="Unreal Tournament game directory: $UT_DIR"
   Add_Message "Main .ini file: $UT_MAIN_INI"
   Add_Message "User .ini file: $UT_USER_INI"
   Check_Paths
}

###  H is help

Menu_Main_H ()
{
   TopDisplay
   zcat $LIB_DIR/help.txt.gz | more
   echo
   echo -n "Press enter to continue or enter L for legal and copyright information: "
   ReadOneChar
   if [ "$READ_VAL" = "l" ]; then
      zcat $LIB_DIR/legal.txt.gz | more
      echo
      echo -n "Press enter to continue or enter C for copyright information: "
      ReadOneChar
      if [ "$READ_VAL" = "c" ]; then
         zcat $LIB_DIR/gpl.txt.gz | more
         echo -n "Press enter to continue: "
         ReadOneChar
      fi
   fi
}

###  I is the init script

Menu_Main_I ()
{
   echo
   echo "if you intend to run this program as a user other than root, then enter"
   echo "the username here .. if you run as root then it will suid to this user"
   echo

   ## read user id

   USERID=
   while [ -z "$USERID" ]; do
      echo "Enter the userid that the ucc program should run as [nobody]"
      ReadString
      USERID=$READ_VAL
      if [ -z "$USERID" ]; then
         USERID="nobody"
      fi
      if [ "$USERID" = "root" ]; then
         echo "invalid user id; should not run as root, pick someone else"
         USERID=
      fi
      TMP=`grep ^$USERID: /etc/passwd`
      if [ "$TMP" = "" ]; then
         echo "invalid user id"
         USERID=
      fi
   done

   ## allow multihome

   echo
   echo "If you have more than one IP, enter one with access to the internet (optional)"
   READ_VAL=X
   while [ "$READ_VAL" = "X" ]; do
      ReadString
      if [ -n "$READ_VAL" ]; then
         READ_VAL=`echo "$READ_VAL" | sed -n -e "s/^[^0-9]*\([0-9]\{1,3\}[.][0-9]\{1,3\}[.][0-9]\{1,3\}[.][0-9]\{1,3\}\)[^0-9]*$/\\1/" -e "t label" -e "d" -e ": label" -e "p"`
         if [ -z "$READ_VAL" ]; then
            echo "The value which you entered contains invalid characters."
            echo
            echo "If you have more than one IP, enter one with access to the internet (optional)"
            READ_VAL=X
         fi
      fi
   done
   MYIP=$READ_VAL

#   ## read game port
#
#   IniRead URL Port $UT_MAIN_INI
#   echo
#   echo "Enter the port where the ucc program should run [$INI_VAL]"
#   ReadNumeric
#   if [ -z "$READ_VAL" ]; then
#      MYPORT=$INI_VAL
#   else
#      MYPORT=$READ_VAL
#   fi
#
   ### read game type

#   CAPTION=`cat $SYS_DIR/*.int | grep "Parent=.Game[ ]*Types" | sed -e 's/^.*Caption=["]\([^"]*\).*$/\1/' -e 's/ /_/g'`
#   COUNT=0
#   for TMP in $CAPTION; do
#      COUNT=$(($COUNT + 1))
#      eval "CAPTION$COUNT=$TMP"
#      echo "$COUNT) $TMP"
#   done
#
#   GAMETYPE=`cat $SYS_DIR/*.int | grep "Parent=.Game[ ]*Types" | sed -e 's/^.*Class=\([^,]*\).*$/\1/' -e 's/^.* //g'`
#   COUNT=0
#   for TMP in $GAMETYPE; do
#      COUNT=$(($COUNT + 1))
#      eval "GAMETYPE$COUNT=$TMP"
#      echo "$COUNT) $TMP"
#   done

   MAPTYPE="1=DM, 2=CTF, 3=DOM, 4=AS, 5=LMS, 6=TDM"
   MAP_DIR="$UT_DIR/Maps"

   TMP=`cat $SYS_DIR/*.int | grep s_SWAT.s_SWATGame`
   if [ -n "$TMP" ]; then
      MAPTYPE="$MAPTYPE, 7=TO-1.6, 8=TO-200"
   fi

   echo
   echo $MAPTYPE
   echo
   echo "Enter the game type [1]"
   ReadNumeric
   case "$READ_VAL" in
   8)
      MAPTYPE="TO"
      MAP_DIR="$UT_DIR/TacticalOps/Maps"
      MYGAME="s_SWAT.s_SWATGame"
      ;;
   7)
      MAPTYPE="SW"
      MYGAME="s_SWAT.s_SWATGame"
      ;;
   6)
      MAPTYPE="DM"
      MYGAME="Botpack.TeamGamePlus"
      ;;
   5)
      MAPTYPE="DM"
      MYGAME="Botpack.LastManStanding"
      ;;
   4)
      MAPTYPE="AS"
      MYGAME="Botpack.Assault"
      ;;
   3)
      MAPTYPE="DOM"
      MYGAME="Botpack.Domination"
      ;;
   2)
      MAPTYPE="CTF"
      MYGAME="Botpack.CTFGame"
      ;;
   *)
      MAPTYPE="DM"
      MYGAME="Botpack.DeathMatchPlus"
      ;;
   esac

   ## find a map based on game type

   echo
   ls $MAP_DIR/$MAPTYPE-*.unr | sed -e "s/^.*Maps\/$MAPTYPE-\(.*\)\.unr/\1/g" | awk '{ printf ("%s, ", $0); }'
   TMP=`ls $MAP_DIR/$MAPTYPE-*.unr | sed -e "s/^.*Maps\/$MAPTYPE-\(.*\)\.unr/\1/g" | awk '{ printf ("%s\n", $0); }' | head -1`
   echo
   MAPNAME=
   while [ -z "$MAPNAME" ]; do
      echo
      echo "Select a map to start the game with [$TMP]"
      ReadString
      if [ -z "$READ_VAL" ]; then
         READ_VAL=$TMP
      fi
      MAPNAME=`ls $MAP_DIR/$MAPTYPE-*.unr | sed -e "s/^.*Maps\/$MAPTYPE-\(.*\)\.unr/\1/g" | awk 'BEGIN { eval ARGV[1]; } { if (tolower($0) == tolower(mygt)) { printf("%s", $0); } }' mygt=$READ_VAL`
   done
   MYMAP="$MAPTYPE-$MAPNAME"

   ## search and add mutators

   GetFullIntValues "MetaClass=Engine.Mutator"
   MYMODS=
   READ_VAL=y
   while [ -n "$READ_VAL" ]; do
      echo
      echo $GET_VAL
      echo
      echo "Select a mutator (enter nothing to continue)"
      ReadString
      if [ -n "$READ_VAL" ]; then
         TMP=
         for XTMP in $GET_VAL; do
            XXTMP=`echo "$XTMP" | sed -n -e "/^$READ_VAL/p"`
            if [ -n "$XXTMP" ]; then
               for XXXTMP in $MYMODS; do
                  if [ "$XXTMP" = "$XXXTMP" ]; then
                     XXTMP=
                  fi
               done
            fi
            if [ -n "$XXTMP" ]; then
               if [ -z "$MYMODS" ]; then
                  MYMODS="$XXTMP"
               else
                  MYMODS="$MYMODS,$XXTMP"
               fi
               TMP=1
            fi
         done
         if [ -z "$TMP" ]; then
            echo
            echo "Unrecognized mutator.  Try again."
         fi
         if [ -n "$MYMODS" ]; then
            echo
            echo "Currently selected: $MYMODS"
         fi
      fi
   done
   MYMODS=`echo "$MYMODS" | sed -e "s/ /,/g"`

   ###

   MYNAME="ucc.init"
   while [ -f "$UT_DIR/$MYNAME" ]; do
      echo
      echo "File exists: $UT_DIR/$MYNAME"
      ReadBool "Do you want to overwrite it"
      if [ "$READ_VAL" = "y" ]; then
         rm -f "$UT_DIR/$MYNAME"
      else
         echo
         echo "Enter a new name for the server init script"
         ReadString
         MYNAME=`echo "$READ_VAL" | sed -e "s/[^0-9a-zA-Z._-]//g"`
         if [ -z "$MYNAME" ]; then
            MYNAME="ucc.init"
         fi
      fi
   done

   ###

   TMPA="/tmp/uccinita.$$"
   TMPB="/tmp/uccinitb.$$"
   TMPC="$UT_DIR/$MYNAME"

   zcat $LIB_DIR/ucc.init.gz > $TMPA

   sed "s|^MYNAME=.*|MYNAME=$MYNAME|" $TMPA > $TMPB
   sed "s|^MYDIR=.*|MYDIR=$UT_DIR|" $TMPB > $TMPA
   sed "s|^MYGAME=.*|MYGAME=$MYGAME|" $TMPA > $TMPB
   sed "s|^MYMAP=.*|MYMAP=$MYMAP|" $TMPB > $TMPA
   #sed "s|^MYPORT=.*|MYPORT=$MYPORT|" $TMPA > $TMPB
   sed "s|^MYPORT=.*||" $TMPA > $TMPB
   sed "s|^MYMODS=.*|MYMODS=$MYMODS|" $TMPB > $TMPA
   sed "s|^MYUSERID=.*|MYUSERID=$USERID|" $TMPA > $TMPB
   sed "s|^MYIP=.*|MYIP=$MYIP|" $TMPB > $TMPA
   sed "s|^MYINI=.*|MYINI=$UT_MAIN_INI|" $TMPA > $TMPC

   rm -f $TMPA $TMPB
   chmod +x $TMPC

   MESSAGE="Created $TMPC"
   Add_Message
   Add_Message "to start the server, use the linux command:"
   Add_Message "$TMPC start"
   Add_Message
   Add_Message "to stop the server, use the linux command:"
   Add_Message "$TMPC stop"
   Add_Message
   Add_Message "to restart the server, use the linux command:"
   Add_Message "$TMPC restart"
   Add_Message
   Add_Message "If you execute the above 'start' or 'restart' commands as root,"
   Add_Message "the server will run as the user below but at a higher task priority."
   Add_Message
   Add_Message "Server will run as user: $USERID"
   if [ -n "$MYIP" ]; then
      Add_Message "Multihome IP: $MYIP"
   fi
   #Add_Message "Game port: $MYPORT"
   Add_Message "Default map: $MAPTYPE-$MAPNAME"
   Add_Message "Mutators: $MYMODS"
}

###  N is the ngLocalStats

Menu_Main_N ()
{
   if [ $OPT_NGLS -eq 0 ]; then
      IniSet Engine.GameInfo bBatchLocal True $UT_MAIN_INI
      MESSAGE="Enabling ngLocalStats (requires JDK 1.2)"
   else
      IniSet Engine.GameInfo bBatchLocal False $UT_MAIN_INI
      MESSAGE="Disabling ngLocalStats"
   fi
}

###  O is the optimization menu

Menu_Main_O ()
{
   MESSAGE=""
   while [ "$MENU_SEL" != "x" ]; do
      Init_Optim_Vars C
      Init_Optim_Vars I
      TopDisplay

      echo "OPTIMIZATION MENU"
      echo "-----------------"
      echo
      echo "C) $ARG_OPTIM_C $MSG_OPTIM_C"
      echo "I) $ARG_OPTIM_I $MSG_OPTIM_I"
      echo "X) Exit to Main Menu"
      Read_Input

      ### now process the menu selection

      case "$MENU_SEL" in
      c)
         Optimize_Std C
         ;;
      i)
         Optimize_Std I
         ;;
      *)
         MESSAGE="Unknown Command."
         ;;
      esac
   done
   MESSAGE=
   MENU_SEL=
}

### P is the patches

Menu_Main_P ()
{
   touch $UT_MAIN_INI.asu
   MESSAGE="Summary of patches:"

   TMP=`echo "$PATCH_DIR" | sed -e 's|/|\\\/|g'`
   for TMP in `ls $PATCH_DIR/*-*-patch.tar.gz | sed -e "s/^$TMP\/\(.*\)-\(.*\)-patch\.tar\.gz$/PACKAGE=\\1;VERS=\\2/"`; do
      eval $TMP
      IniRead ASU.patches $PACKAGE $UT_MAIN_INI.asu
      INST="$PACKAGE-$VERS-patch.tar.gz"
      echo
      if [ "$VERS" = "$INI_VAL" ]; then
         echo "The patch $PACKAGE version $INI_VAL has already been applied."
         ReadBool "Do you want to re-patch the same version anyway"
         if [ "$READ_VAL" = "y" ]; then
#            READ_VAL=`echo $VERS | sed -e "s/-.*$//"`
#            if [ -n "$READ_VAL" ]; then
#               VERS="$READ_VAL"
#            fi
            IniSet ASU.patches $PACKAGE $VERS $UT_MAIN_INI.asu
            Install_Package "$PACKAGE-$VERS"
         else
            Add_Message "--- $PACKAGE-$VERS was already installed."
         fi
      else
         if [ "$INI_VAL" = "0" ]; then
            Add_Message "--- $PACKAGE-$VERS is incompatible with another package."
         else
            if [ -n "$INI_VAL" ]; then
               echo "You currently have $PACKAGE version $INI_VAL installed"
               echo "-- You will not be able to undo the following patch  --"
            fi

            ReadBool "Do you want to patch $PACKAGE to version $VERS"
            if [ "$READ_VAL" = "y" ]; then
#               READ_VAL=`echo $VERS | sed -e "s/-.*$//"`
#               if [ -n "$READ_VAL" ]; then
#                  VERS="$READ_VAL"
#               fi
               IniSet ASU.patches $PACKAGE $VERS $UT_MAIN_INI.asu
               Install_Package "$PACKAGE-$VERS"
            else
               Add_Message "--- $PACKAGE-$VERS patch NOT installed."
            fi
         fi
      fi
   done
}

###  R is the redirect

Menu_Main_R ()
{
   if [ $OPT_REDIRECT -eq 0 ]; then
      MESSAGE="Enabling Download Redirect"

      # Allow an interface to change the RedirectToURL

      IniRead ASU.settings RedirectToURL $UT_ASU_INI
      if [ -z "$INI_VAL" ]; then
         IniSet ASU.settings RedirectToURL "http://ucc.sobservers.com/" $UT_ASU_INI
         IniRead ASU.settings RedirectToURL $UT_ASU_INI
         if [ -z "$INI_VAL" ]; then
            echo "ERROR: Can not read/write .ini file: $UT_ASU_INI"
            exit -3
         fi
      fi

      echo
      echo "Enter the URL of the Redirect server [$INI_VAL]"
      ReadString
      if [ -n "$READ_VAL" ]; then
         MESSAGE="RedirectToURL: $READ_VAL"
         IniSet ASU.settings RedirectToURL "$READ_VAL" $UT_ASU_INI
      else
         MESSAGE="RedirectToURL: $INI_VAL"
      fi

      IniSet IpDrv.HTTPDownload RedirectToURL $INI_VAL $UT_MAIN_INI

      # next, MaxDownloadSize

      IniRead ASU.settings MaxDownloadSize $UT_ASU_INI
      if [ -z "$INI_VAL" ]; then
         IniSet ASU.settings MaxDownloadSize 150000 $UT_ASU_INI
         IniRead ASU.settings MaxDownloadSize $UT_ASU_INI
      fi
      echo
      echo "About MaxDownloadSize:"
      echo "Files which are larger (in bytes) than the MaxDownloadSize will be"
      echo "loaded from the redirect server and NOT from your UT server."
      echo "Be sure that files that are not on the redirect server are smaller than"
      echo "the MaxDownloadSize! -- Note: CSHP should NOT be redirected; so the"
      echo "MaxDownloadSize should be greater than the size of the CSHP .u file"
      echo
      echo "Enter the Maximum Filesize to Download From the UT Server [$INI_VAL]"
      ReadNumeric
      if [ -n "$READ_VAL" ]; then
         Add_Message "MaxDownloadSize : $READ_VAL"
         IniSet ASU.settings MaxDownloadSize "$READ_VAL" $UT_ASU_INI
      else
         Add_Message "MaxDownloadSize : $INI_VAL"
      fi
 
      IniSet IpDrv.TcpNetDriver MaxDownloadSize $INI_VAL $UT_MAIN_INI

      # now set the standard vals

      IniSet IpDrv.HTTPDownload UseCompression True $UT_MAIN_INI
      IniSet IpDrv.HTTPDownload ProxyServerPort 3128 $UT_MAIN_INI
      IniSet IpDrv.HTTPDownload ProxyServerPort "" $UT_MAIN_INI
      IniSet IpDrv.TcpNetDriver AllowDownloads True $UT_MAIN_INI
      IniUnSet IpDrv.TcpNetDriver DownloadManagers $UT_MAIN_INI
      IniAdd IpDrv.TcpNetDriver DownloadManagers IpDrv.HTTPDownload $UT_MAIN_INI
      IniAdd IpDrv.TcpNetDriver DownloadManagers Engine.ChannelDownload $UT_MAIN_INI
   else
      MESSAGE="Disabling Download Redirect"
      IniUnAdd IpDrv.TcpNetDriver DownloadManagers IpDrv.HTTPDownload $UT_MAIN_INI
   fi

   ## this should be an option:
   # IniSet IpServer.UdpServerQuery MinNetVer 413 $UT_MAIN_INI
}

###  S is the server settings

Menu_Main_S ()
{
   IniRead Engine.GameReplicationInfo ServerName $UT_MAIN_INI
   echo
   echo "Enter a name for your server [$INI_VAL]"
   ReadString
   if [ -n "$READ_VAL" ]; then
      MESSAGE="ServerName: $READ_VAL"
      IniSet Engine.GameReplicationInfo ServerName "$READ_VAL" $UT_MAIN_INI
   else
      MESSAGE="ServerName: $INI_VAL"
   fi

   IniRead URL Port $UT_MAIN_INI
   if [ -z "$INI_VAL" ]; then
      INI_VAL=7777
   fi
   echo
   echo "Enter the Game Port [$INI_VAL]"
   ReadNumeric
   if [ -n "$READ_VAL" ]; then
      Add_Message "Game Port : $READ_VAL"
      IniSet URL Port "$READ_VAL" $UT_MAIN_INI
   else
      Add_Message "Game Port : $INI_VAL"
   fi
 
   IniRead Engine.GameReplicationInfo AdminName $UT_MAIN_INI
   echo
   echo "Enter the name of the server administrator [$INI_VAL]"
   ReadString
   if [ -n "$READ_VAL" ]; then
      Add_Message "AdminName : $READ_VAL"
      IniSet Engine.GameReplicationInfo AdminName "$READ_VAL" $UT_MAIN_INI
   else
      Add_Message "AdminName : $INI_VAL"
   fi

   IniRead Engine.GameReplicationInfo AdminEmail $UT_MAIN_INI
   echo
   echo "Enter an administrator email address [$INI_VAL]"
   ReadString
   if [ -n "$READ_VAL" ]; then
      Add_Message "AdminEmail: $READ_VAL"
      IniSet Engine.GameReplicationInfo AdminEmail "$READ_VAL" $UT_MAIN_INI
   else
      Add_Message "AdminEmail: $INI_VAL"
   fi

   echo
   echo "Enter 4 lines for a MOTD:"

   for TMP in 1 2 3 4; do
      IniRead Engine.GameReplicationInfo MOTDLine$TMP $UT_MAIN_INI
      echo
      echo "Line $TMP [$INI_VAL]"
      ReadString
      if [ -n "$READ_VAL" ]; then
         Add_Message "MOTDLine$TMP : $READ_VAL"
         IniSet Engine.GameReplicationInfo MOTDLine$TMP "$READ_VAL" $UT_MAIN_INI
      else
         Add_Message "MOTDLine$TMP : $INI_VAL"
      fi
   done

   IniRead UWeb.WebServer bEnabled $UT_MAIN_INI
   if [ "$INI_VAL" = "False" ]; then
      INI_VAL=0
   else
      IniRead UWeb.WebServer ListenPort $UT_MAIN_INI
   fi
   echo
   echo "Enter port number for the Web Admin (* to disable) [$INI_VAL]"
   ReadNumeric
   if [ -z "$READ_VAL" ]; then
      READ_VAL=$INI_VAL
   fi
   if [ "$READ_VAL" = "*" ]; then
      IniSet UWeb.WebServer bEnabled False $UT_MAIN_INI
      Add_Message "Web admin DISABLED"
   else
      IniSet UWeb.WebServer ListenPort "$READ_VAL" $UT_MAIN_INI
      IniSet UWeb.WebServer bEnabled True $UT_MAIN_INI
      Add_Message "Web admin enabled"
      Add_Message "UWeb.WebServer.ListenPort: $READ_VAL"

      IniRead UTServerAdmin.UTServerAdmin AdminUsername $UT_MAIN_INI
      echo
      echo "Enter a username to enter the Web Admin [$INI_VAL]"
      ReadString
      if [ -n "$READ_VAL" ]; then
         IniSet UTServerAdmin.UTServerAdmin AdminUsername "$READ_VAL" $UT_MAIN_INI
         Add_Message "UTServerAdmin.UTServerAdmin.AdminUsername: $READ_VAL"
      else
         Add_Message "UTServerAdmin.UTServerAdmin.AdminUsername: $INI_VAL"
      fi

      IniRead UTServerAdmin.UTServerAdmin AdminPassword $UT_MAIN_INI
      echo
      echo "Enter a password to enter the Web Admin [$INI_VAL]"
      ReadString
      if [ -n "$READ_VAL" ]; then
         IniSet UTServerAdmin.UTServerAdmin AdminPassword "$READ_VAL" $UT_MAIN_INI
         Add_Message "UTServerAdmin.UTServerAdmin.AdminPassword: $READ_VAL"
      else
         Add_Message "UTServerAdmin.UTServerAdmin.AdminPassword: $INI_VAL"
      fi

      if [ "$OPT_WEBTEXT" = "1" ]; then
         XTMP="t"
      else
         XTMP="g"
      fi
      echo
      echo "Text-based or full-graphics web admin (t/g) [$XTMP]"
      echo -n "> "
      ReadOneChar
      if [ "$READ_VAL" = "t" ]; then
         XTMP="t"
      fi
      if [ "$READ_VAL" = "g" ]; then
         XTMP="g"
      fi
      TMP="$UT_DIR/xxxx"
      if [ "$XTMP" = "g" ]; then
         if [ "$OPT_WEBTEXT" = "1" ]; then
            mv "$UT_DIR/Web/" "$TMP/"
            mv "$TMP/graphic/" "$UT_DIR/Web/"
            mv "$TMP/" "$UT_DIR/Web/plaintext/"
         fi
         Add_Message "Web-admin display mode: Full-graphics"
      else
         if [ "$OPT_WEBTEXT" = "0" ]; then
            mv "$UT_DIR/Web/" "$TMP/"
            mv "$TMP/plaintext/" "$UT_DIR/Web/"
            mv "$TMP/" "$UT_DIR/Web/graphic/"
         fi
         Add_Message "Web-admin display mode: Text-only"
      fi
   fi

   IniRead Engine.GameInfo AdminPassword $UT_MAIN_INI
   if [ -z "$INI_VAL" ]; then
      INI_VAL="*"
   fi
   echo
   echo "Server Console Admin password (* to disable) [$INI_VAL]"
   ReadString
   if [ -z "$READ_VAL" ]; then
      READ_VAL=$INI_VAL
   fi
   if [ "$READ_VAL" = "*" ]; then
      IniSet Engine.GameInfo AdminPassword "" $UT_MAIN_INI
      Add_Message "Private Admin Password DISABLED"
   else
      IniSet Engine.GameInfo AdminPassword "$READ_VAL" $UT_MAIN_INI
      Add_Message "Engine.GameInfo.AdminPassword: $READ_VAL"
   fi

   IniRead Engine.GameInfo GamePassword $UT_MAIN_INI
   if [ -z "$INI_VAL" ]; then
      INI_VAL="*"
   fi
   echo
   echo "Private Game Password (* to disable) [$INI_VAL]"
   ReadString
   if [ -z "$READ_VAL" ]; then
      READ_VAL=$INI_VAL
   fi
   if [ "$READ_VAL" = "*" ]; then
      IniSet Engine.GameInfo GamePassword "" $UT_MAIN_INI
      Add_Message "Private Game Password DISABLED"
   else
      IniSet Engine.GameInfo GamePassword "$READ_VAL" $UT_MAIN_INI
      Add_Message "Engine.GameInfo.GamePassword: $READ_VAL"
   fi
}

###  U is the umod menu

Menu_Main_U ()
{
   MESSAGE=""
   while [ "$MENU_SEL" != "x" ]; do
      TopDisplay

      echo "UMOD PACKAGE MENU"
      echo "-----------------"
      echo
      echo "I) Install a Umod package"
      echo "L) List Currently Installed Umods"
      echo "U) Uninstall Umod"
      echo "X) Exit to Main Menu"
      Read_Input

      ### now process the menu selection

      case "$MENU_SEL" in
      i)
         Menu_Mod_I
         ;;
      l)
         Menu_Mod_L
         ;;
      u)
         Menu_Mod_U
         ;;
      *)
         MESSAGE="Unknown Command."
         ;;
      esac
   done
   MESSAGE=
   MENU_SEL=
}

###  V is the verify installation

Menu_Main_V ()
{
   ERR=0
   MESSAGE="Verifying installation ..."

   ## simple fixes

   if [ -f "$SYS_DIR/core" ]; then
      Add_Message "Removed bad file: $SYS_DIR/core"
      rm -f "$SYS_DIR/core"
   fi

   ## fix functions

   Fix_Totally_Unreal
   #Fix_Server_Packages
   Fix_Corrupted_Maps

   ## print result

   if [ $ERR -eq 0 ]; then
      Add_Message "Everything looks fine."
   else
      Add_Message "At least one error was found that was not fixed."
   fi
}

###  Bot Menu

###  G is the generic bots

Menu_Bot_G ()
{
   TMP="$UT_USER_INI.old-bots"
   if [ $OPT_BINBOTS -ne 0 ]; then
      mv -f "$TMP" "$UT_USER_INI"
      MESSAGE="Restored Old Bot Settings."
   else
      cp -f "$UT_USER_INI" "$TMP"
      echo "Generating Binary Bots ..."
      Generic_Bots
      MESSAGE="Created Binary Bot Settings."
   fi
}

###  N is to set the number of bots

Menu_Bot_N ()
{
   IniRead Botpack.DeathMatchPlus MinPlayers $UT_MAIN_INI
   if [ -z "$INI_VAL" ]; then
      INI_VAL=0
   fi
   echo
   echo "Enter the minimum number of players (including bots) you want on your server [$INI_VAL]"
   ReadNumeric
   if [ -z $READ_VAL ]; then
      READ_VAL=$INI_VAL
   fi
   IniSet Botpack.DeathMatchPlus MinPlayers "$READ_VAL" $UT_MAIN_INI
   IniSet Botpack.CTFGame MinPlayers "$READ_VAL" $UT_MAIN_INI
   IniSet Botpack.Domination MinPlayers "$READ_VAL" $UT_MAIN_INI
   IniSet Botpack.Assault MinPlayers "$READ_VAL" $UT_MAIN_INI
   IniSet Botpack.TeamGamePlus MinPlayers "$READ_VAL" $UT_MAIN_INI
   MESSAGE="MinPlayers: $READ_VAL"
}

###  Mod Menu

Menu_Mod_I ()
{
   echo
   echo "Zip and Umod files in the Patches directory:"
   echo
   pushd $PATCH_DIR > /dev/null
   ls *.[zZ][iI][pP] *.[uU][mM][oO][dD] 2> /dev/null
   popd > /dev/null
   echo
   echo "Enter the name of the file from the above list"
   echo "or enter the full file name if it is located elsewhere."
   ReadString
   MESSAGE="Installing $READ_VAL ..."
   TMPDIR=
   if [ ! -f "$READ_VAL" ]; then
      ## try to find it
      if [ -f "$UT_DIR/$READ_VAL" ]; then
         READ_VAL="$UT_DIR/$READ_VAL"
      else
         if [ -f "$PATCH_DIR/$READ_VAL" ]; then
            READ_VAL="$PATCH_DIR/$READ_VAL"
         fi
      fi
   fi
   if [ -f "$READ_VAL" ]; then
      SUFFIX=`echo "$READ_VAL" | sed -e "s/^.*[.]\([^.]*\)/\\1/"`
      if [ "$SUFFIX" = "zip" ]; then
         PROCESSED="0"
         TMPDIR=/tmp/asu.$$
         mkdir $TMPDIR
         echo "Attempting to unzip the umod file ..."
         XXTMP=`echo $TMPDIR | sed -e "s/[/]/\[\/\]/g"`
         XTMP=`unzip -o -d $TMPDIR -C $READ_VAL | sed -n -e "s/^.*$XXTMP[/]\([^/; ]*\).*$/\\1/" -e "t label" -e "d" -e ": label" -e "p"`
         for XXTMP in $XTMP; do
            TMP=`echo "$XXTMP" | sed -e "s/^.*[.]\([^.]*\)/\\1/"`
            if [ "$TMP" = "umod" ]; then
               echo "Installing $XXTMP"
               perl $LIB_DIR/umod.pl -b $UT_DIR -i "$TMPDIR/$XXTMP"
               PROCESSED="1"
            fi
         done
         rm -rf "$TMPDIR"
         if [ -d "$TMPDIR" ]; then
            rm -rf "$TMPDIR"
         fi
         TMPDIR="$READ_VAL"
         if [ "1" = "$PROCESSED" ]; then
            Menu_Mod_L
         else
            Add_Message "Failed: No .umod's contained in .zip file"
         fi
      elif [ "$SUFFIX" = "umod" ]; then
         perl $LIB_DIR/umod.pl -b $UT_DIR -i $READ_VAL
         Menu_Mod_L
      else
         Add_Message "Failed: Must be a .umod or .zip file (which contains a .umod of the same name)"
      fi
   else
      MESSAGE="Unable to find file: $READ_VAL"
   fi
	
   if [ -d "$TMPDIR" ]; then
      rm -rf "$TMPDIR"
   fi
}

Menu_Mod_L ()
{
   MESSAGE="Installed Umods:$NL"`perl $LIB_DIR/umod.pl --modvers -b $UT_DIR | awk '{ print "  " $0; }'`
}

Menu_Mod_U ()
{
   MESSAGE=
   echo
   echo "Installed Umods:"
   perl $LIB_DIR/umod.pl -b $UT_DIR | awk '{ print "  " $0; }'
   echo
   echo "Enter the name of the umod package"
   ReadString
   if [ -n "$READ_VAL" ]; then
      TMP=`perl $LIB_DIR/umod.pl -b $UT_DIR -u "$READ_VAL" 2> /dev/stdout | head -1 | sed -e "s/^.*: \(product not installed\).*$/\\1/"`
      if [ "$TMP" = "product not installed" ]; then
         MESSAGE="Umod NOT FOUND: $READ_VAL"
         Add_Message "Use the L command to list the umods."
         Add_Message "Enter the full name exactly as it appears except without"
         Add_Message "the three digit version number at the end."
      else
         MESSAGE="Umod uninstalled: $READ_VAL"
      fi
   fi
}

# EOF
