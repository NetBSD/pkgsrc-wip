#!@RCD_SCRIPTS_SHELL@

# PROVIDE: downtimed
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
        . /etc/rc.subr
fi

name=downtimed
rcvar=downtimed
command="@PREFIX@/sbin/downtimed"
load_rc_config downtimed
run_rc_command "$1"
