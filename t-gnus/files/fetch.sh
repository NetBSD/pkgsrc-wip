#! /bin/ksh

export CVSROOT=:pserver:anonymous@cvs.m17n.org:/cvs/root
export MODULE=gnus
export TARBALL_PREFIX=t-gnus

umask 022

FILE=$(echo $1 | sed 's,^.*/\([^/]*\),\1,')
SUBDIR=$(basename $FILE .tar.gz)

#DATE=$(echo $FILE | sed -e "s/^${TARBALL_PREFIX}//" -e 's/^-//' -e 's/\.tar\.gz$//')
DATE=20040906
# a T-Gnus tag is something like: t-gnus-6_17_2-00
TAG=$(echo $SUBDIR | sed -e 's,\([0-9][0-9]*\)\.\([0-9][0-9]*\)\.\([0-9][0-9]*\)\.\([0-9][0-9]*\),\1_\2_\3-\4,' )

mkdir -p $SUBDIR
cd $SUBDIR && {
#	cvs checkout -P -D${DATE}-UTC ${MODULE}
	cvs checkout -P -r${TAG} ${MODULE}
	find . | TZ=:UTC xargs touch -t ${DATE}0000
	( 
	  echo . type=dir uid=0 gid=0
	  find ./${MODULE} -type d | sed 's/$/ type=dir uid=0 gid=0/'
	  find ./${MODULE} -type f | sed 's/$/ type=file uid=0 gid=0/'
	) | pax -wM > ../${SUBDIR}.tar
	cd .. && rm -rf $SUBDIR
	TZ=:UTC touch -t ${DATE}0000 ${SUBDIR}.tar
	gzip ${SUBDIR}.tar
}
