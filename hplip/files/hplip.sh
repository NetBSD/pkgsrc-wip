#!/bin/sh

# PROVIDE: hplip
# REQUIRE: NETWORKING SERVERS
# BEFORE:  cupsd
# KEYWORD: shutdown

.  /etc/rc.subr

name="hpiod"
rcvar=${name}

# First start hpiod

command="@LOCALBASE@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
portfile="@VARBASE@/run/${name}.port"
hpiod_user=hplip

start_precmd="hpiod_prestart"

load_rc_config $name

: ${hpiod="NO"}

hpiod_prestart()
{
	touch ${pidfile}
	touch ${portfile}
	chown ${hpiod_user} ${pidfile}
	chown ${hpiod_user} ${portfile}
}

run_rc_command $*

# Then start hpssd

name="hpssd"
rcvar=${name}
command="@LOCALBASE@/sbin/hpssd"
command_interpreter="@PYTHON_INTERP@"
pidfile="@VARBASE@/run/${name}.pid"
portfile="@VARBASE@/run/${name}.port"
hpssd_user=nobody
command_args=">/dev/null"

start_precmd="hpssd_prestart"

load_rc_config $name

: ${hpssd="NO"}

hpssd_prestart()
{
	touch ${pidfile}
	touch ${portfile}
	chown ${hpssd_user} ${pidfile}
	chown ${hpssd_user} ${portfile}
}

run_rc_command $*
