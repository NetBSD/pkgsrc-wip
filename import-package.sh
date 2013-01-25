#! /bin/sh
#
# $Id: import-package.sh,v 1.12 2013/01/25 22:51:45 roelants Exp $
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

cleanup() {
	if [ -n "${CLEANUP}" ]; then
		rm -f ${CLEANUP}
	fi
}
trap cleanup 0

if [ -z "${MAKE}" ]; then
	if type bmake >/dev/null 2>&1; then
		MAKE=bmake
	else
		MAKE=make
	fi
fi

PACKAGE=$(basename $(pwd))

for cvsdir in $(find . -type d -name CVS); do
	cvsdir=$(echo ${cvsdir} | cut -c 3-)
	if [ -r "${cvsdir}/Repository" ]; then
		read repo < "${cvsdir}/Repository"
		if [ "${repo}" != "$(dirname wip/${PACKAGE}/${cvsdir})" ]; then
			echo "Mismatched CVS directory found: ${cvsdir}" >&2
			echo 'Please remove CVS directories from other' \
				'packages, or change to the correct' \
				'directory path.' >&2
			exit 1
		fi
	fi
	if grep '[^D]' "${cvsdir}/Entries"; then
		echo "It seems $(dirname ${cvsdir}) is already checked in." >&2
		exit 1
	fi
done

CATEGORY=$(basename $(dirname $(pwd)))
PKGPATH=${CATEGORY}/${PACKAGE}
CVSROOT=$(cat ../CVS/Root)
USER=$(echo ${CVSROOT} | sed -e 's/@.*$//' -e 's/^.*://')
USER_UPPER="$(echo ${USER} | tr '[a-z]' '[A-Z]')"
MSG="$(${MKTEMP} -t import-package.XXXXXXXX)"
CLEANUP="${MSG}"
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

ADDLIST="$(${MKTEMP} -t import-package-files.XXXXXXXX)"
CLEANUP="${CLEANUP} ${ADDLIST}"
(
	cd ..
	find ${PACKAGE} \( -name CVS -prune \) -o -type d -print |
		while read dir; do
			[ -e "${dir}/CVS" ] && continue
			echo ${dir}/
		done
	find ${PACKAGE} \( -name CVS -prune \) -o -type f ! -name '*orig' \
	    ! -name '.#*' -print
) | sort > ${ADDLIST}
sed "s|^|CVS: will add: ${CATEGORY}/|" ${ADDLIST} >> ${MSG}

${EDITOR} ${MSG}

echo "Edited message follows:"
echo ${DASH70}
grep -v '^CVS:.*$' < ${MSG}
echo ${DASH70}
echo 	"CVSROOT:	${CVSROOT}"
echo 	"PKGPATH:	${PKGPATH}"
echo ""
printf "y + enter to import, any other text + enter to abort> "
read ANS

if [ "${ANS}" = "y" ]; then
	(
		export CVS_RSH=ssh
		cd ..
		[ -e "${PACKAGE}/CVS" ] || cvs add ${PACKAGE} || exit 1
		grep '/$' ${ADDLIST} | fgrep -vx ${PACKAGE}/ |
			xargs -L 100 cvs add
		grep -v '/$' ${ADDLIST} | xargs -L 100 cvs add
		cvs commit -m "$(grep -v '^CVS:.*$' ${MSG})" ${PACKAGE}
	)

	echo ${DASH70}
	echo "Don't forget to add the package to ${CATEGORY}/Makefile."
	echo "When imported to pkgsrc itself, please update the CHANGES-*"
	echo "file and possibly remove the package from the TODO list."
	echo ""
fi
