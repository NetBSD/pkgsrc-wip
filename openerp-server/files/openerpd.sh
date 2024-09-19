#!/bin/sh
#
# PROVIDE: openerpd
# REQUIRE: postgresql LOGIN
#
# Add the following lines to /etc/rc.conf to enable openerp-server
#
#
# openerpd (bool):        Set to "NO" by default,
#                         Set it to "YES" to enable openerp-server
#
# openerpd_config (str):  The path to the openerp-server configuration file
#                         (defaults to @PREFIX@/etc/openerp-server.conf)
#
# openerpd_flags (str):   Extra arguments to be used when invoking
#                         the openerp-server daemon.
#
# Patch submitted by (c) Franck Porcher, Ph.D, to fix some issues regarding
# pidfile, log files, and discrepencies with the main configuration file.

#  getval varname file [default_value] [separator_char]
#  - Discard comment lines (any text leading with blanks then #)
#  - Retain only the last value set


. /etc/rc.subr

name=openerpd
command=@PREFIX@/bin/openerp-server
rcvar=openerpd

load_rc_config $name

openerpd="${openerpd-"NO"}"
openerpd_config="${openerpd_config-"@PREFIX@/etc/openerp-server.conf"}"
openerpd_user="${openerpd_user-"openerpd"}"
openerpd_pidfile="${openerpd_pidfile:-"$(grep pidfile @PREFIX@/etc/openerp-server.conf | awk -F "=" ' { print $2 } ' |sed 's/[ ]//g' )"}"
openerpd_logdir="${openerpd_logdir:-"$(dirname `grep logfile @PREFIX@/etc/openerp-server.conf | awk -F "=" ' { print $2 } ' `)"}"
openerpd_flags="${openerpd_flags:-"--config=${openerpd_config}"}"

# /etc/rc.subr use $pidfile (not ${name}_pidfile)
pidfile="${openerpd_pidfile}"

required_files="${openerpd_config}"

start_precmd="${name}_prestart"
stop_cmd="${name}_stop"
status_cmd="${name}_status"
getval_cmd="${name}_getval"

export PYTHON_EGG_DIR=/tmp

openerpd_prestart()
{
    local d
    
    d="$(dirname "${openerpd_pidfile}")"
    if [ ! -d "${d}" ]
    then
        mkdir -p "${d}"
    fi
    chown "${openerpd_user}" "${d}"

    d="$openerpd_logdir"
    if [ ! -d "${d}" ]
    then
        mkdir -p "${d}"
    fi
    chown "${openerpd_user}" "${d}"
}

openerpd_stop()
{
    # Try its best to stop the service
    if [ -f "${openerpd_pidfile}" ]
    then
        echo "Stopping ${name}."
        kill -15 "$(cat "${openerpd_pidfile}")"
    else
        # echo "Looking for (openerp-server.py ${openerpd_flags})"
        openerpd_pid=$(pgrep -f "openerp-server.py ${openerpd_flags}")
        if [ -n "${openerpd_pid}" ]
        then
            echo "Stopping ${name}."
            kill -15 "${openerpd_pid}"
        else
            echo "${name} not running? (pidfile not found)"
        fi
    fi
}

openerpd_status()
{
    # Try its best to find the service's status
    if [ -f "${openerpd_pidfile}" ]
    then
        openerpd_pid="$(cat "${openerpd_pidfile}")"
    fi

    if [ -z "${openerpd_pid}" ]
    then 
	openerpd_pid=$(pgrep -f "openerp-server.py ${openerpd_flags}")
	[ -n "${openerpd_pid}" ] && echo "${openerpd_pid}" > "${openerpd_pidfile}"
    fi

    if [ -n "${openerpd_pid}" ]
    then
        echo "${name} running with pid: $openerpd_pid"
    else
        echo "${name} not running? (pid not found)"
    fi
}


command_args=" >/dev/null 2>&1 &"

load_rc_config $name
run_rc_command "$1"
