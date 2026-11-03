#!/bin/sh

PATH=/bin:/usr/bin:/usr/pkg/bin
BASEDIR=$PWD
PATCHCONF="${BASEDIR}/electron/patches/config.json"

for _dirs in $(sed -n 's|.*patch_dir": "src\(.*\)", "repo": "src\(.*\)".*|.\1:.\2|p' < ${PATCHCONF}); do
	_patchdir=$(echo "$_dirs" | cut -d: -f1)
	_srcdir=$(echo "$_dirs" | cut -d: -f2)
	cd "$BASEDIR/$_srcdir"
	while read -r _patch; do
		git apply --reject --directory="$(git rev-parse --show-prefix)" "${BASEDIR}/${_patchdir}/${_patch}"
	done < "${BASEDIR}/${_patchdir}/.patches"
done
