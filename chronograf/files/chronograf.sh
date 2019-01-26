#!@RCD_SCRIPTS_SHELL@

# PROVIDE: chronograf
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]
then
        . /etc/rc.subr
fi

name="chronograf"
rcvar=$name
chronograf_user="@CHRONOGRAF_USER@"
chronograf_group="@CHRONOGRAF_GROUP@"
chronograf_chdir="@VARBASE@/lib/chronograf"
STDERR="@LOGDIR@/chronograf.log"
command="@PREFIX@/bin/chronograf"
command_args="-r --canned-path=@RESOURCEDIR@/canned --protoboards-path=@RESOURCEDIR@/protoboards 1>/dev/null 2>> $STDERR &"

load_rc_config $name
run_rc_command "$1"
