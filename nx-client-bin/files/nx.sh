#!@SH@

PATH="${PATH}:@PREFIX@/lib/@NX@/bin"
export PATH
LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/@NX@"
export LD_LIBRARY_PATH

if [ $# -gt 0 ]
then
	exec /usr/pkg/lib/nx/bin/$*
else
	exec /usr/pkg/lib/nx/bin/nxclient
fi
