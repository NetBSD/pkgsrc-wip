#!@RCD_SCRIPTS_SHELL@
# $NetBSD: n2n_edge.sh,v 1.4 2014/03/28 18:44:00 phonohawk Exp $

# PROVIDE: n2n_edge
# REQUIRE: DAEMON

. /etc/rc.subr

N2N_USER="@N2N_USER@"
N2N_GROUP="@N2N_GROUP@"
N2N_CONFIG_FILE="@PKG_SYSCONFDIR@/edge.conf"

name="n2n_edge"
rcvar=$name
command="@PREFIX@/sbin/edge"
required_files="$N2N_CONFIG_FILE"
start_precmd="edge_prestart"

n2n_config_var() {
    eval '(
        . "$N2N_CONFIG_FILE" >/dev/null
        echo "$'$1'"
    )'
}

quotemeta() {
    echo "$1" | sed 's/[^0-9a-zA-Z]/\\&/g'
}

edge_prestart() {
    local device="$(n2n_config_var device)"
    if [ -n "$device" ]; then
        rc_flags="$rc_flags -d $device"
    fi

    local address="$(n2n_config_var address)"
    if [ -n "$address" ]; then
        rc_flags="$rc_flags -a $address"
    else
        err 1 "$N2N_CONFIG_FILE: address is not set."
    fi

    local netmask="$(n2n_config_var netmask)"
    if [ -n "$netmask" ]; then
        rc_flags="$rc_flags -s $netmask"
    fi

    local macaddr="$(n2n_config_var macaddr)"
    if [ -n "$macaddr" ]; then
        rc_flags="$rc_flags -m $macaddr"
    fi

    local mtu="$(n2n_config_var mtu)"
    if [ -n "$mtu" ]; then
        rc_flags="$rc_flags -M $mtu"
    fi

    local port="$(n2n_config_var port)"
    if [ -n "$port" ]; then
        rc_flags="$rc_flags -p $port"
    fi

    local community="$(n2n_config_var community)"
    if [ -n "$community" ]; then
        rc_flags="$rc_flags -c $(quotemeta "$community")"
    else
        err 1 "$N2N_CONFIG_FILE: community is not set."
    fi

    local key="$(n2n_config_var key)"
    if [ -n "$key" ]; then
        export N2N_KEY="$key"
    fi

    local interval="$(n2n_config_var interval)"
    if [ -n "$interval" ]; then
        rc_flags="$rc_flags -i $interval"
    fi

    local localaddr="$(n2n_config_var localaddr)"
    if [ -n "$localaddr" ]; then
        rc_flags="$rc_flags -L $localaddr"
    fi

    local reresolve="$(n2n_config_var reresolve)"
    if [ -n "$reresolve" ]; then
        if checkyesno reresolve; then
            rc_flags="$rc_flags -b"
        fi
    fi

    local routing="$(n2n_config_var routing)"
    if [ -n "$routing" ]; then
        if checkyesno routing; then
            rc_flags="$rc_flags -r"
        fi
    fi

    local multicast="$(n2n_config_var multicast)"
    if [ -n "$multicast" ]; then
        if checkyesno multicast; then
            rc_flags="$rc_flags -E"
        fi
    fi

    local verbose="$(n2n_config_var verbose)"
    if [ -n "$verbose" ]; then
        if checkyesno verbose; then
            rc_flags="$rc_flags -v"
        fi
    fi

    local supernodes="$(n2n_config_var supernodes)"
    set -- $supernodes
    if [ $# -gt 0 ]; then
        while [ $# -gt 0 ]; do
            case "$1" in
                *:*)
                    rc_flags="$rc_flags -l $1";;
                *)
                    rc_flags="$rc_flags -l $1:7654"
            esac
            shift
        done
    else
        err 1 "$N2N_CONFIG_FILE: supernodes is not set."
    fi

    rc_flags="$rc_flags -u $(id -u "$N2N_USER")"
    rc_flags="$rc_flags -g $(id -g "$N2N_GROUP")"
}

load_rc_config $name
run_rc_command "$1"
