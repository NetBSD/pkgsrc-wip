#!@RCD_SCRIPTS_SHELL@
# $NetBSD: n2n_supernode.sh,v 1.2 2014/03/28 18:44:00 phonohawk Exp $

# PROVIDE: n2n_supernode
# REQUIRE: DAEMON

. /etc/rc.subr

N2N_USER="@N2N_USER@"
N2N_GROUP="@N2N_GROUP@"
N2N_CONFIG_FILE="@PKG_SYSCONFDIR@/supernode.conf"

name="n2n_supernode"
rcvar=$name
command="@PREFIX@/sbin/supernode"
n2n_supernode_user="$N2N_USER"
n2n_supernode_group="$N2N_GROUP"
required_files="$N2N_CONFIG_FILE"
start_precmd="supernode_prestart"

n2n_config_var() {
    eval '(
        . "$N2N_CONFIG_FILE" >/dev/null
        echo "$'$1'"
    )'
}

supernode_prestart() {
    local port="$(n2n_config_var port)"
    if [ -n "$port" ]; then
        rc_flags="$rc_flags -l $port"
    fi

    local verbose="$(n2n_config_var verbose)"
    if [ -n "$verbose" ]; then
        if checkyesno verbose; then
            rc_flags="$rc_flags -v"
        fi
    fi
}

load_rc_config $name
run_rc_command "$1"
