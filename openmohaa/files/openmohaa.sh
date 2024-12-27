#!/bin/sh

cd @PREFIX@/lib/openmohaa/

if [ $# -gt 1 ]; then
 echo Usage: >&2
 echo "  $0" >&2
 echo "  $0 [base|breakthrough|spearhead]" >&2
 exit 1
fi

if [ $# -eq 0 ]; then
 LAUNCH=base
fi

if [ $# -eq 1 ]; then
 LAUNCH=$1
fi

exec ./launch_openmohaa_${LAUNCH}.@MACHINE_GNU_ARCH@
