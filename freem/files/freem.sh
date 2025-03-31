#
# FreeM
#
# Shared memory daemon for FreeM
#
# PROVIDE: freem
# REQUIRE: DAEMON
#

if [ -f @SYSCONFBASE@/rc.subr ]; then
    . @SYSCONFBASE@/rc.subr
fi

name="freem"
rcvar=${name}_enable
command="@PREFIX@/bin/${name}"
freem_flags="--daemon --user=freem --group=freem"

load_rc_config $name
run_rc_command "$1"
