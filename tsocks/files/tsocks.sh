#!@SH@

if [ $# -eq 0 ]; then
	echo "usage: `basename $0` command" 1>&2
	exit 1
fi

export LD_PRELOAD=@PREFIX@/lib/libtsocks.so
exec $*
