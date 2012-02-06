#! /bin/sh
#
# $Id: import-package.sh,v 1.5 2012/02/06 12:48:43 fhajny Exp $
#
# Script designed to make initial imports into wip easier.
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

if echo ${CVSROOT} | grep -i pkgsrc-wip > /dev/null; then
  TAGS="${USER_UPPER} ${USER_UPPER}_$(date +%Y%m%d)"
  ROOTDIR=
else
  TAGS="TNF pkgsrc-base"
  ROOTDIR=pkgsrc/
fi

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
find . | sed "s|^.|CVS: will import: ${ROOTDIR}${PKGPATH}|" >> ${MSG}

${EDITOR} ${MSG}

echo "Edited message follows:"
echo ${DASH70}
grep -v '^CVS:.*$' < ${MSG}
echo ${DASH70}
echo 	"CVSROOT:	${CVSROOT}"
echo 	"ROOTDIR:	${ROOTDIR}"
echo 	"PKGPATH:	${PKGPATH}"
echo 	"TAGS:		${TAGS}"
echo ""
printf "y, enter to import, ctrl-c to abort> "
read ANS

if [ "${ANS}" = "y" ]; then
  CVS_RSH=ssh cvs -d ${CVSROOT} import -m "$(cat ${MSG} | grep -v '^CVS:.*$')" ${ROOTDIR}${PKGPATH} ${TAGS}
fi

echo ${DASH70}
echo "If the import went OK, move away the ${PKGPATH} directory"
echo "and run \"cvs update -dPA ${PACKAGE}\" in ${CATEGORY} to complete"
echo "the import. If you got conflict errors, just cvs add the"
echo "conflicting files and cvs commit them."
echo ""
echo "Don't forget to add the package to ${CATEGORY}/Makefile and remove"
echo "it from the TODO list."
echo ""
