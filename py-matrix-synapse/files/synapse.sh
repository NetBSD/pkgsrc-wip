#!/bin/sh
#
# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$
#

# PROVIDE: synapse
# REQUIRE: LOGIN postgresql
# KEYWORD: shutdown

#
# Add the following line to /etc/rc.conf to enable `synapse':
#
# synapse_enable="YES"

. /etc/rc.subr
name=synapse

rcvar=$name
load_rc_config ${name}
synapse_user="@SYNAPSE_SYNAPSE_USERS@"
synapse_conf="@PREFIX@/etc/homeserver.yaml"
synapse_dbdir="@SYNAPSE_DATADIR@"
synapse_logdir="@SYNAPSE_LOGDIR@"
synapse_pidfile="@SYNAPSE_PIDDIR@/homeserver.pid"

pidfile="${synapse_pidfile}"
procname="@PYTHONBIN@"
command="@PYTHONBIN@"
command_args="-m synapse.app.homeserver --daemonize -c ${synapse_conf}"
start_precmd=start_precmd

start_precmd()
{
	if [ ! -d ${synapse_pidfile%/*} ] ; then
		install -d -o @SYNAPSE_USERS@ -g wheel ${synapse_pidfile%/*};
	fi

	if [ ! -d ${synapse_dbdir} ] ; then
		install -d -o @SYNAPSE_USERS@ -g wheel ${synapse_dbdir};
	fi

	if [ ! -d ${synapse_logdir} ] ; then
		install -d -o @SYNAPSE_USERS@ -g wheel ${synapse_logdir};
	fi

	if $(grep -q CHANGEME ${synapse_conf}) ; then
		echo "Error: Default secret values in config."
		echo "Please replace the CHANGEME values in ${synapse_conf}"
		exit 1
	fi
}

run_rc_command "$1"
