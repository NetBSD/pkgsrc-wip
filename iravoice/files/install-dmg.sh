#!/bin/sh

set -eu

distfile=$1
destination=$2
workdir=$3
mountpoint="${workdir}/IraVoice.dmg.mnt"
device=

cleanup()
{
	if [ -n "${device}" ]; then
		/usr/bin/hdiutil detach "${device}" >/dev/null 2>&1 ||
			/usr/bin/hdiutil detach -force "${device}" >/dev/null 2>&1 ||
			true
	fi
	rmdir "${mountpoint}" >/dev/null 2>&1 || true
}

trap cleanup EXIT HUP INT TERM

mkdir -p "${mountpoint}"
device=$(/usr/bin/hdiutil attach -nobrowse -readonly \
	-mountpoint "${mountpoint}" "${distfile}" |
	awk -v mp="${mountpoint}" '$NF == mp { print $1; exit }')
test -n "${device}"

cd "${mountpoint}"
pax -rw -pp -pm IraVoice.app "${destination}"
