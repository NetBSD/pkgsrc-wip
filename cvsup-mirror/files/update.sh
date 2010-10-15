#!/usr/pkg/bin/bash 

# $FreeBSD$
# $NetBSD: update.sh,v 1.2 2010/10/15 16:57:27 bseklecki Exp $

function usage { 

	echo "Usage: $0 [distroName] [yesNo-validateScanDeltas]";
	return 0
}

if [ "$*" == "" ]; then
	usage;
	echo "Unable determine which BSD prefix to update ...";
	exit 126
else
	DISTRO="$1"
	FULLYESNO="$2" # Take anything, we'll just check for a second argument
fi

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/cvsup/update\.sh\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi


export PREFIX
export CVSUP_ARGS="$2"

export PATH=/bin:/usr/bin:${PREFIX}/bin

lock=/var/spool/lock/cvsup.lock
log=/var/log/cvsup.log

umask 22

# Dont muddle logging
#exec >>${log} 2>&1

# Do the update

date "+$0 update begins at %Y-%m-%d %T"

# The rest of this is executed while holding the lock file, to ensure that
# multiple instances won't collide with one another.

#lockf -t 0 ${lock} /bin/sh << 'E*O*F'

base=${PREFIX}/etc/cvsup
rundir=/var/tmp
cd ${rundir} || exit 120

source ${base}/config.${DISTRO}.conf || exit

colldir=sup-client-scan # Used by all clients to store 'scan' files (delta cache DB) and daemon to read them

startup=${PREFIX}/etc/rc.d/cvsupd
eval chome=~${cuser}
cmd="exec env HOME=${chome} cvsup"

client_options="-1gL 1 -b ${base} -c ${colldir}"

# If they pass us [anything/-s] in $2, tell cvsup client to fun in full scan mode

if [ ! -z ${CVSUP_ARGS} ]; then
	client_options="${client_options} ${CVSUP_ARGS}"
fi


echo "Updating from ${host}"
su -f -m ${cuser} -c "${cmd} ${client_options} -h ${host} ${base}/supfile-${DISTRO}" 

if [ $? -eq 0 ]; then
    echo -n "Re-Starting the CVSUP Daemon with SIGHUP"
    # rc.conf snippet:
     # cvsupd=YES
     # cvsupd_user="cvsup"
     # Also ./rc.d/cvsupd:
	# [ -z "$cvsupd_user" ] && cvsupd_user="cvsupd"
	# [ -z "$cvsupd_basedir" ] && cvsupd_basedir="/usr/pkg/etc/cvsup"
	# [ -z "$cvsupd_maxclients" ] && cvsupd_maxclients="8"
	# [ -z "$cvsupd_syslogfacil" ] && cvsupd_syslogfacil="@local0"
	# [ -z "$cvsupd_collection_dir" ] && cvsupd_collection_dir="sup"               
	# [ -z "$cvsupd_mirrormode_scandir"] && "sup-client-scan" 

    /etc/rc.d/cvsupd restart || exit 119
    touch -m ${base}/last_updated.${DISTRO}
else
	echo "Failed to cvsup update ${DISTRO}"
	exit 99
fi


# If you would like to trigger an SNMP trap or syslog message
#if [ $(($(date +"%s") - $(stat -f "%m" -t %s last_updated.${DISTRO}))) -gt 60 ]; then
#	echo "Its been more than a minute since the script ran successfully";
#else
#	echo "$0  was run successfully less than 60 seconds ago"  | logger -p user0.critical
#fi


date "+CVSup update ends at %Y-%m-%d %T"
