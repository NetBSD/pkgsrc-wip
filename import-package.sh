#! /bin/sh
#
# $Id: import-package.sh,v 1.6 2012/07/02 13:41:35 thomasklausner Exp $
#
# Script designed to make add packages into wip easier.
#
# Just cd to the package directory and run ../import-package.sh
#
# It will automatically create a nice import message based on DESCR
# and PKGNAME, set up the CVS tags correctly and autodetect what CVSROOT
# to use. It also shows you what files will be imported, reminds you
# to run pkglint(1) and asks for confirmation before doing anything.

[ -n "${MKTEMP}" ] || MKTEMP=mktemp
[ -n "${EDITOR}" ] || EDITOR=vi

if [ -z "${MAKE}" ]; then
  if [ -n "$(which bmake)" ]; then
    MAKE=bmake
  else
    MAKE=make
  fi
fi

CATEGORY=$(basename $(dirname $(pwd)))
PACKAGE=$(basename $(pwd))
PKGPATH=${CATEGORY}/${PACKAGE}
CVSROOT=$(cat ../CVS/Root)
USER=$(echo ${CVSROOT} | sed -e 's/@.*$//' -e 's/^.*://')
USER_UPPER="$(echo ${USER} | tr '[a-z]' '[A-Z]')"
MSG="$(${MKTEMP} -t import-package.XXXXXXXX)"
echo "Please wait while determining PKGNAME and DESCR_SRC."
PKGNAME="$(${MAKE} show-var VARNAME=PKGNAME)"
DESCR_SRC="$(${MAKE} show-var VARNAME=DESCR_SRC) /dev/null"

DASH70=----------------------------------------------------------------------

echo "Import ${PKGNAME} as ${CATEGORY}/${PACKAGE}." > ${MSG}
echo "" >> ${MSG}
cat ${DESCR_SRC} >> ${MSG}
echo ${DASH70} | sed 's/^/CVS: /' >> ${MSG}
echo "CVS: Please edit the above message to give a brief description" >> ${MSG}
echo "CVS: of the package for those who read the *-changes@ list." >> ${MSG}
echo "CVS: Did you remember to run pkglint(1) before importing?" >> ${MSG}
echo "CVS:" >> ${MSG}
echo "CVS: Lines starting with CVS: will be automatically removed." >> ${MSG}
echo "CVS:" >> ${MSG}
find . | grep -v -e CVS -e orig$ | sed "s|^.|CVS: will add: ${PKGPATH}|" >> ${MSG}

${EDITOR} ${MSG}

echo "Edited message follows:"
echo ${DASH70}
grep -v '^CVS:.*$' < ${MSG}
echo ${DASH70}
echo 	"CVSROOT:	${CVSROOT}"
echo 	"PKGPATH:	${PKGPATH}"
echo ""
printf "y, enter to import, ctrl-c to abort> "
read ANS

if [ "${ANS}" = "y" ]; then
    (CVS_RSH=ssh cd .. && cvs add ${PACKAGE}) || exit 1
    find . -type d | grep -v -e CVS -e '^\.$' | while read d
    do
        CVS_RSH=ssh cvs add "$d"
    done
    find . -type f | grep -v -e CVS -e orig$ | while read f
    do
        CVS_RSH=ssh cvs add "$f"
    done
    CVS_RSH=ssh cvs commit -m "$(grep -v '^CVS:.*$' ${MSG})"
fi

echo ${DASH70}
echo "Don't forget to add the package to ${CATEGORY}/Makefile."
echo "When imported to pkgsrc itself, please update the CHANGES-*"
echo "file and possibly remove the package from the TODO list."
echo ""
